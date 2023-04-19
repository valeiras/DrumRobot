#include "lighting_robot.h"

LightingRobot::LightingRobot(int matrixWidth, int matrixHeight, int nbMatricesHor, int nbMatricesVert,
                             FastLED_NeoMatrix *fastLedMatrix, int spotlightPins[NB_SPOTLIGHTS], int meterPins[NB_METERS], int brightness, int address)
  : RoboReceptor(address) {

  // MATRIX DECLARATION:
  // Parameter 1 = width of NeoPixel matrix
  // Parameter 2 = height of matrix
  // Parameter 3 = pin number (most are valid)
  // Parameter 4 = matrix layout flags, add together as needed:
  //   NEO_MATRIX_TOP, NEO_MATRIX_BOTTOM, NEO_MATRIX_LEFT, NEO_MATRIX_RIGHT:
  //     Position of the isFirst LED in the matrix; pick two, e.g.
  //     NEO_MATRIX_TOP + NEO_MATRIX_LEFT for the top-left corner.
  //   NEO_MATRIX_ROWS, NEO_MATRIX_COLUMNS: LEDs are arranged in horizontal
  //     rows or in vertical columns, respectively; pick one or the other.
  //   NEO_MATRIX_PROGRESSIVE, NEO_MATRIX_ZIGZAG: all rows/columns proceed
  //     in the same order, or alternate lines reverse direction; pick one.
  //   See example below for these values in action.
  // Parameter 5 = pixel type flags, add together as needed:
  //   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
  //   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
  //   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
  //   NEO_GRBW    Pixels are wired for GRBW bitstream (RGB+W NeoPixel products)
  //   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
  w_ = matrixWidth;
  h_ = matrixHeight;

  fastLedMatrix_ = fastLedMatrix;

  unsigned int minDimension = min(w_, h_);
  halfSize_ = ceil(minDimension / 2.0);

  nbMtxHor_ = nbMatricesHor;

  fastLedMatrix_->begin();
  fastLedMatrix_->setTextWrap(false);
  fastLedMatrix_->setBrightness(brightness);

  // We set the primary colors
  primaryColors_[0] = fastLedMatrix_->Color(255, 0, 0);
  primaryColors_[1] = fastLedMatrix_->Color(0, 255, 0);
  primaryColors_[2] = fastLedMatrix_->Color(0, 0, 255);

  // We set the palette colors:
  paletteColors_[0] = fastLedMatrix_->Color(43, 53, 103);
  paletteColors_[1] = fastLedMatrix_->Color(186, 215, 233);
  paletteColors_[2] = fastLedMatrix_->Color(252, 255, 231);
  paletteColors_[3] = fastLedMatrix_->Color(235, 69, 95);

  fastLedMatrix_->setTextColor(paletteColors_[0]);
  fastLedMatrix_->setTextSize(2);

  x_ = -fastLedMatrix_->width();
  currColorIndex_ = 0;
  mtxOrderCount_ = 0;

  isSplBlinkOn_ = false;
  isSplSeqOn_ = false;
  isSplTopOn_ = false;
  isSplBottomOn_ = false;

  hasStarted_ = false;
  isFirstAfterStart_ = true;
  isFirstAfterStop_ = false;
  isFirstAfterMatrixModeChange_ = false;
  isFirstAfterSpotlightModeChange_ = false;
  isFirstAfterMatrixBlinkChange_ = false;
  isFirstAfterSpotlightBlinkChange_ = false;

  isMatrixOn_ = false;
  areSpotlightsOn_ = false;

  for (unsigned int ii = 0; ii < NB_BLINKING_INTERVALS; ii++) {
    hasIntervalChanged_[ii] = false;
  }

  currMtxBlinkInterval_ = QUARTER_INTERVAL;
  currSplBlinkInterval_ = QUARTER_INTERVAL;

  currBitmap_ = 0;

  matrixMode_ = MTX_OFF_MODE;
  setBpm(bpmValues[DEFAULT_BPM_IDX]);

  lastSemiquaverChange_ = 0;
  lastQuarterNoteChange_ = 0;

  for (unsigned int ii = 0; ii < NB_SPOTLIGHTS; ii++) {
    spotlightPins_[ii] = spotlightPins[ii];
    pinMode(spotlightPins_[ii], OUTPUT);
  }
  currSpotlight_ = 0;

  for (unsigned int ii = 0; ii < NB_METERS; ii++) {
    meterPins_[ii] = meterPins[ii];
    pinMode(meterPins_[ii], OUTPUT);
  }

  isMatrixPending_ = true;
  clearAllLights();
}

void LightingRobot::setBpm(uint8_t bpm) {
  setBpm(float(bpm));
}

void LightingRobot::setBpm(float bpm) {
  bpm_ = bpm;
  semiquaverInterval_ = MS_PER_MIN / (bpm_ * SEMIQUAVERS_PER_BEAT);
  quarterNoteInterval_ = 4 * semiquaverInterval_;
}

void LightingRobot::doLighting(unsigned long currTime) {
  if (isBrightnessChangePending_) {
    fastLedMatrix_->setBrightness(pendingBrightness_);
    isBrightnessChangePending_ = false;
  }

  if (isMatrixPending_) {
    fastLedMatrix_->show();
    isMatrixPending_ = false;
  }

  if (isBpmChangePending_) {
    setBpm(pendingBpm_);
    isBpmChangePending_ = false;
  }

  if (isFirstAfterStart_) {
    lastSemiquaverChange_ = currTime;
    isFirstAfterStart_ = false;
    turnOnMatrix();
  }

  if (isFirstAfterSpotlightModeChange_) {
    initializeSpotlightMode();
    isFirstAfterSpotlightModeChange_ = false;
  }

  if (isFirstAfterMatrixModeChange_) {
    initializeMatrixMode();
    isFirstAfterMatrixModeChange_ = false;
  }

  checkNoteChanges(currTime);

  if (isSplSeqOn_) {
    doSpotlightSequence();
  } else if (isSplBlinkOn_) {
    doSpotlightBlinking();
  }

  if (hasStarted_) {
    switch (matrixMode_) {
      case MTX_OFF_MODE:
      case MTX_CONSTANT_MODE:
        break;
      case MTX_BLINK_MODE:
        doMatrixBlinking();
        break;
      case MTX_NAME_MODE:
        doMatrixName();
        break;
      case MTX_LOGO_MODE:
        doMatrixLogo();
        break;
      case MTX_RCT_MODE:
        doMatrixRectangles();
        break;
      case MTX_BARS_MODE:
        doMatrixBars();
        break;
    }
    doMeterMovement(currTime);
  } else {
    if (isFirstAfterStop_) {
      clearAllLights();
      clearMeters();
      isFirstAfterStop_ = false;
    }
  }
}

void LightingRobot::doMatrixName() {
  if (hasIntervalChanged_[currMtxBlinkInterval_]) {
    if (++x_ > 32) {
      x_ = -fastLedMatrix_->width();
      currColorIndex_ = ++currColorIndex_ % NB_PALETTE_COLORS;
      fastLedMatrix_->setTextColor(paletteColors_[currColorIndex_]);
    }
    printMatrixName();
  }
}

void LightingRobot::doMatrixBlinking() {
  if (hasIntervalChanged_[currMtxBlinkInterval_]) {
    isMatrixOn_ = !isMatrixOn_;
    if (isMatrixOn_) {
      currColorIndex_ = ++currColorIndex_ % NB_PALETTE_COLORS;
      for (unsigned int ii = 0; ii < nbMtxHor_; ii++) {
        unsigned int colorIdx = (currColorIndex_ + ii) % NB_PALETTE_COLORS;
        fastLedMatrix_->fillRect(ii * w_, 0, w_, h_, paletteColors_[colorIdx]);
      }
      fastLedMatrix_->show();
    } else {
      fastLedMatrix_->clear();
      fastLedMatrix_->show();
    }
  }
}

void LightingRobot::doMatrixLogo() {
  if (hasIntervalChanged_[currMtxBlinkInterval_]) {
    currBitmap_ = ++currBitmap_ % NB_POSITIONS;
    printMatrixLogo();
  }
}

void LightingRobot::doMatrixRectangles() {
  if (hasIntervalChanged_[currMtxBlinkInterval_]) {
    currColorIndex_ = ++currColorIndex_ % NB_PALETTE_COLORS;
    printMatrixRectangles();
  }
}

void LightingRobot::doMatrixBars() {
  if (hasIntervalChanged_[currMtxBlinkInterval_]) {
    currColorIndex_ = ++currColorIndex_ % NB_PALETTE_COLORS;
    printMatrixBars();
  }
}

void LightingRobot::doSpotlightBlinking() {
  if (hasIntervalChanged_[currSplBlinkInterval_]) {
    areSpotlightsOn_ = !areSpotlightsOn_;
    if (isSplBottomOn_) {
      switchSpotlightsBottom(areSpotlightsOn_);
      if (isSplTopOn_) {
        // If both top and bottom buttons are pressed, we alternate both
        switchSpotlightsTop(!areSpotlightsOn_);
      }
    } else if (isSplTopOn_) {
      switchSpotlightsTop(areSpotlightsOn_);
    } else {
      switchSpotlights(areSpotlightsOn_);
    }
  }
}

void LightingRobot::doSpotlightSequence() {
  if (hasIntervalChanged_[currSplBlinkInterval_]) {
    // We always do a sequence, but depending on the combination of button we change the order
    digitalWrite(spotlightPins_[currSpotlight_], LOW);
    if (isSplBottomOn_) {
      if (isSplTopOn_) {
        // We add the extra spotlight on top
        digitalWrite(spotlightPins_[currSpotlight_ + NB_BOTTOM_SPOTLIGHTS], LOW);
      }
      // If the blinking button is pressed, we reverse the order of the sequence, relying on integer overflow
      if (isSplBlinkOn_) {
        // We iterate 2, 1, 0
        currSpotlight_ = min(uint8_t(currSpotlight_ - 1), NB_BOTTOM_SPOTLIGHTS - 1);
      } else {
        // We iterate 0, 1, 2
        currSpotlight_ = ++currSpotlight_ % NB_BOTTOM_SPOTLIGHTS;
      }
      if (isSplTopOn_) {
        digitalWrite(spotlightPins_[currSpotlight_ + NB_BOTTOM_SPOTLIGHTS], HIGH);
      }
    } else if (isSplTopOn_) {
      if (isSplBlinkOn_) {
        // We iterate 5, 4, 3
        if (--currSpotlight_ < NB_BOTTOM_SPOTLIGHTS) {
          currSpotlight_ = NB_SPOTLIGHTS - 1;
        }
      } else {
        // We iterate 3, 4, 5
        if (++currSpotlight_ == NB_SPOTLIGHTS) {
          currSpotlight_ = NB_BOTTOM_SPOTLIGHTS;
        }
      }
    } else {
      if (isSplBlinkOn_) {
        // We iterate 5, 4, 3, 2, 1, 0
        currSpotlight_ = min(uint8_t(currSpotlight_ - 1), NB_SPOTLIGHTS - 1);
      } else {
        // We iterate 0, 1, 2, 3, 4, 5
        currSpotlight_ = ++currSpotlight_ % NB_SPOTLIGHTS;
      }
    }
    digitalWrite(spotlightPins_[currSpotlight_], HIGH);
  }
}

void LightingRobot::doMeterMovement(unsigned long currTime) {
  int output = max(0, MAX_METER_OUTPUT * (1 - float(currTime - lastQuarterNoteChange_) / quarterNoteInterval_));
  for (unsigned int ii = 0; ii < NB_METERS; ii++) {
    analogWrite(meterPins_[ii], hasStarted_ * output);
  }
}

void LightingRobot::treatStartMsg() {
  if (!hasStarted_) {
    hasStarted_ = true;
    isFirstAfterStart_ = true;
  }
}

void LightingRobot::treatStopMsg() {
  if (hasStarted_) {
    hasStarted_ = false;
    isFirstAfterStop_ = true;
  }
}

void LightingRobot::treatResyncMsg() {
}

void LightingRobot::treatBpmChangeMsg(uint8_t messageContent) {
  isBpmChangePending_ = true;
  pendingBpm_ = messageContent;
}

void LightingRobot::treatBpmIdxChangeMsg(uint8_t messageContent) {
  isBpmChangePending_ = true;
  pendingBpm_ = bpmValues[messageContent];
}

void LightingRobot::treatMtxModeChangeMsg(uint8_t messageContent) {
  matrixMode_ = messageContent;
  isFirstAfterMatrixModeChange_ = true;
}

void LightingRobot::treatSplModeChangeMsg(uint8_t messageContent) {
  switch (messageContent) {
    case SPL_TOP_ON:
      isSplTopOn_ = true;
      break;
    case SPL_TOP_OFF:
      isSplTopOn_ = false;
      break;
    case SPL_BOTTOM_ON:
      isSplBottomOn_ = true;
      break;
    case SPL_BOTTOM_OFF:
      isSplBottomOn_ = false;
      break;
    case SPL_BLINK_ON:
      Serial.println("Blink on");
      isSplBlinkOn_ = true;
      break;
    case SPL_BLINK_OFF:
      Serial.println("Blink off");
      isSplBlinkOn_ = false;
      break;
    case SPL_SEQ_ON:
      Serial.println("Sequence on");
      isSplSeqOn_ = true;
      break;
    case SPL_SEQ_OFF:
      Serial.println("Sequence off");
      isSplSeqOn_ = false;
      break;
  }
  isFirstAfterSpotlightModeChange_ = true;
}

void LightingRobot::treatMtxBlinkChangeMsg(uint8_t messageContent) {
  currMtxBlinkInterval_ = messageContent;
}

void LightingRobot::treatSplBlinkChangeMsg(uint8_t messageContent) {
  currSplBlinkInterval_ = messageContent;
}

void LightingRobot::treatBrightnessChangeMsg(uint8_t messageContent) {
  isBrightnessChangePending_ = true;
  pendingBrightness_ = messageContent;
  isMatrixPending_ = true;
}

void LightingRobot::treatSetResyncTimeMsg(uint16_t messageContent) {
}

void LightingRobot::clearAllLights() {
  clearMatrix();
  switchSpotlights(LOW);
}

void LightingRobot::clearMeters() {
  for (unsigned int ii = 0; ii < NB_METERS; ii++) {
    analogWrite(meterPins_[ii], 0);
  }
}

void LightingRobot::clearMatrix() {
  fastLedMatrix_->clear();
  fastLedMatrix_->show();
  isMatrixOn_ = false;
}

void LightingRobot::switchSpotlights(byte onOrOff) {
  for (unsigned int ii = 0; ii < NB_SPOTLIGHTS; ii++) {
    digitalWrite(spotlightPins_[ii], onOrOff);
  }
}

void LightingRobot::switchSpotlightsTop(byte onOrOff) {
  for (unsigned int ii = NB_BOTTOM_SPOTLIGHTS; ii < NB_SPOTLIGHTS; ii++) {
    digitalWrite(spotlightPins_[ii], onOrOff);
  }
}

void LightingRobot::switchSpotlightsBottom(byte onOrOff) {
  for (unsigned int ii = 0; ii < NB_BOTTOM_SPOTLIGHTS; ii++) {
    digitalWrite(spotlightPins_[ii], onOrOff);
  }
}

void LightingRobot::turnOnMatrix() {
  for (unsigned int ii = 0; ii < nbMtxHor_; ii++) {
    unsigned int colorIdx = (currColorIndex_ + ii) % NB_PALETTE_COLORS;
    fastLedMatrix_->fillRect(ii * w_, 0, w_, h_, paletteColors_[colorIdx]);
  }
  fastLedMatrix_->show();
  isMatrixOn_ = true;
}

void LightingRobot::initializeMatrixMode() {
  switch (matrixMode_) {
    case MTX_OFF_MODE:
      clearMatrix();
      break;
    case MTX_BLINK_MODE:
      mtxOrderCount_++;
      clearMatrix();
      break;
    case MTX_NAME_MODE:
      mtxOrderCount_++;
      printMatrixName();
      break;
    case MTX_LOGO_MODE:
      mtxOrderCount_++;
      printMatrixLogo();
      break;
    case MTX_RCT_MODE:
      mtxOrderCount_++;
      printMatrixRectangles();
      break;
    case MTX_BARS_MODE:
      mtxOrderCount_++;
      printMatrixBars();
      break;
    case MTX_CONSTANT_MODE:
      if (--mtxOrderCount_ == 0) {
        turnOnMatrix();
      }
      break;
  }
}

void LightingRobot::initializeSpotlightMode() {
  switchSpotlights(LOW);

  if (isSplSeqOn_) {
    initializeSpotlightSequence();
  } else if (isSplBlinkOn_) {
    initializeSpotlightBlinking();
  } else {
    if (isSplTopOn_) { switchSpotlightsTop(HIGH); }
    if (isSplBottomOn_) { switchSpotlightsBottom(HIGH); }
  }
}

void LightingRobot::initializeSpotlightSequence() {
  if (isSplBottomOn_) {
    if (isSplTopOn_) {
      digitalWrite(spotlightPins_[currSpotlight_ + NB_BOTTOM_SPOTLIGHTS], HIGH);
    } else if (currSpotlight_ >= NB_BOTTOM_SPOTLIGHTS) {
      currSpotlight_ = isSplBlinkOn_ ? NB_BOTTOM_SPOTLIGHTS - 1 : 0;
    }
  } else if (isSplTopOn_ && currSpotlight_ < NB_BOTTOM_SPOTLIGHTS) {
    currSpotlight_ = isSplBlinkOn_ ? NB_SPOTLIGHTS - 1 : NB_BOTTOM_SPOTLIGHTS;
  }
  digitalWrite(spotlightPins_[currSpotlight_], HIGH);
}

void LightingRobot::printMatrixName() {
  fastLedMatrix_->clear();
  fastLedMatrix_->setCursor(x_, 1);
  fastLedMatrix_->print(F("MEKANIKA"));
  fastLedMatrix_->show();
}

void LightingRobot::initializeSpotlightBlinking() {
  areSpotlightsOn_ = true;
  if (isSplBottomOn_) {
    switchSpotlightsBottom(areSpotlightsOn_);
    if (isSplTopOn_) {
      // If both top and bottom buttons are pressed, we alternate both
      switchSpotlightsTop(!areSpotlightsOn_);
    }
  } else if (isSplTopOn_) {
    switchSpotlightsTop(areSpotlightsOn_);
  } else {
    switchSpotlights(areSpotlightsOn_);
  }
}

void LightingRobot::printMatrixLogo() {
  fastLedMatrix_->clear();
  for (unsigned int ii = 0; ii < nbMtxHor_; ii++) {
    unsigned int bitmapIdx = (currBitmap_ + ii) % NB_POSITIONS;
    fastLedMatrix_->drawRGBBitmap(ii * w_, 0, image_data_gear[bitmapIdx], w_, h_);
  }
  fastLedMatrix_->show();
}

void LightingRobot::printMatrixRectangles() {
  fastLedMatrix_->clear();

  unsigned int colorIdx = currColorIndex_;
  for (unsigned int ii = 0; ii < halfSize_; ii++) {
    for (unsigned int jj = 0; jj < nbMtxHor_; jj++) {
      fastLedMatrix_->drawRect(ii + jj * w_, ii, w_ - 2 * ii, h_ - 2 * ii, paletteColors_[colorIdx]);
    }
    colorIdx = ++colorIdx % NB_PALETTE_COLORS;
  }

  fastLedMatrix_->show();
}

void LightingRobot::printMatrixBars() {
  fastLedMatrix_->clear();

  unsigned int colorIdx = currColorIndex_;
  for (unsigned int ii = 0; ii < w_ * nbMtxHor_; ii += BAR_WIDTH) {
    fastLedMatrix_->drawLine(ii, 0, ii + BAR_WIDTH, h_ - 1, paletteColors_[colorIdx]);
    colorIdx = ++colorIdx % NB_PALETTE_COLORS;
  }

  fastLedMatrix_->show();
}

void LightingRobot::checkNoteChanges(unsigned long currTime) {
  for (unsigned int ii = 0; ii < NB_BLINKING_INTERVALS; ii++) {
    hasIntervalChanged_[ii] = false;
  }

  if (currTime - lastSemiquaverChange_ >= semiquaverInterval_) {
    hasIntervalChanged_[SEMIQUAVER_INTERVAL] = true;
    lastSemiquaverChange_ += semiquaverInterval_;

    semiquaverCount_++;

    if (semiquaverCount_ % SEMIQUAVERS_PER_WHOLE_NOTE == 0) {
      semiquaverCount_ = 0;

      hasIntervalChanged_[WHOLE_INTERVAL] = true;
      hasIntervalChanged_[HALF_INTERVAL] = true;
      hasIntervalChanged_[QUARTER_INTERVAL] = true;
      hasIntervalChanged_[QUAVER_INTERVAL] = true;

      lastQuarterNoteChange_ = currTime;
    } else if (semiquaverCount_ % SEMIQUAVERS_PER_HALF_NOTE == 0) {
      hasIntervalChanged_[HALF_INTERVAL] = true;
      hasIntervalChanged_[QUARTER_INTERVAL] = true;
      hasIntervalChanged_[QUAVER_INTERVAL] = true;

      lastQuarterNoteChange_ = currTime;
    } else if (semiquaverCount_ % SEMIQUAVERS_PER_QUARTER_NOTE == 0) {
      hasIntervalChanged_[QUARTER_INTERVAL] = true;
      hasIntervalChanged_[QUAVER_INTERVAL] = true;

      lastQuarterNoteChange_ = currTime;
    } else if (semiquaverCount_ % SEMIQUAVERS_PER_QUAVER == 0) {
      hasIntervalChanged_[QUAVER_INTERVAL] = true;
    }
  }
}