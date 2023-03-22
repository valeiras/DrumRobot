#include "lighting_robot.h"

LightingRobot::LightingRobot() {}

LightingRobot::LightingRobot(int matrixWidth, int matrixHeight, int nbMatricesHor, int nbMatricesVert,
                             int matrixPin, int spotlightPins[NB_SPOTLIGHTS], int brightness, int address)
  : RoboReceptor(address) {

  // MATRIX DECLARATION:
  // Parameter 1 = width of NeoPixel matrix
  // Parameter 2 = height of matrix
  // Parameter 3 = pin number (most are valid)
  // Parameter 4 = matrix layout flags, add together as needed:
  //   NEO_MATRIX_TOP, NEO_MATRIX_BOTTOM, NEO_MATRIX_LEFT, NEO_MATRIX_RIGHT:
  //     Position of the FIRST LED in the matrix; pick two, e.g.
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

  ledMatrix_ = new Adafruit_NeoMatrix(matrixWidth, matrixHeight, nbMatricesHor, nbMatricesVert, matrixPin,
                                      NEO_MATRIX_TOP + NEO_MATRIX_LEFT + NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
                                      NEO_GRB + NEO_KHZ800);


  unsigned int minDimension = min(w_, h_);
  halfSize_ = ceil(minDimension / 2.0);

  nbMtxHor_ = nbMatricesHor;

  ledMatrix_->begin();
  ledMatrix_->setTextWrap(false);
  ledMatrix_->setBrightness(brightness);

  // We set the primary colors
  primaryColors_[0] = ledMatrix_->Color(255, 0, 0);
  primaryColors_[1] = ledMatrix_->Color(0, 255, 0);
  primaryColors_[2] = ledMatrix_->Color(0, 0, 255);

  // We set the palette colors:
  paletteColors_[0] = ledMatrix_->Color(43, 53, 103);
  paletteColors_[1] = ledMatrix_->Color(186, 215, 233);
  paletteColors_[2] = ledMatrix_->Color(252, 255, 231);
  paletteColors_[3] = ledMatrix_->Color(235, 69, 95);

  ledMatrix_->setTextColor(paletteColors_[0]);

  x_ = -ledMatrix_->width();
  currColorIndex_ = 0;
  hasStarted_ = false;
  currBitmap_ = 0;

  matrixMode_ = MATRIX_OFF_MODE;
  spotlightMode_ = SPOTLIGHT_OFF_MODE;
  setBpm(DEFAULT_BPM);

  wholeNoteChange_ = false;
  halfNoteChange_ = false;
  quarterNoteChange_ = false;
  quaverChange_ = false;
  semiquaverChange_ = false;

  lastSemiquaverChange_ = 0;

  for (unsigned int ii = 0; ii < NB_SPOTLIGHTS; ii++) {
    spotlightPins_[ii] = spotlightPins[ii];
    pinMode(spotlightPins_[ii], OUTPUT);
  }
  currSpotlight_ = 0;

  clearAllLights();
}

void LightingRobot::setBpm(uint8_t bpm) {
  bpm_ = bpm;

  semiquaverInterval_ = MS_PER_MIN / (bpm_ * SEMIQUAVERS_PER_BEAT);
}

void LightingRobot::doLighting(unsigned long currTime) {
  if (hasStarted_) {
    checkNoteChanges(currTime);

    switch (matrixMode_) {
      case MATRIX_OFF_MODE:
        break;
      case MATRIX_BLINKING_MODE:
        doMatrixBlinking(currTime);
        break;
      case MATRIX_NAME_MODE:
        doMatrixName(currTime);
        break;
      case MATRIX_LOGO_MODE:
        doMatrixLogo(currTime);
        break;
      case MATRIX_RECTANGLES_MODE:
        doMatrixRectangles(currTime);
        break;
      case MATRIX_BARS_MODE:
        doMatrixBars(currTime);
        break;
    }
    switch (spotlightMode_) {
      case SPOTLIGHT_OFF_MODE:
      case SPOTLIGHT_CONSTANT_MODE:
        break;
      case SPOTLIGHT_BLINKING_MODE:
        doSpotlightBlinking(currTime);
        break;
      case SPOTLIGHT_SEQUENCE_MODE:
        doSpotlightSequence(currTime);
        break;
    }
  } else {
    lastSemiquaverChange_ = currTime;
  }
}

void LightingRobot::doMatrixName(unsigned long ellapsedTime) {
  if (quarterNoteChange_) {
    if (++x_ > 36) {
      x_ = -ledMatrix_->width();
      currColorIndex_ = ++currColorIndex_ % NB_PALETTE_COLORS;
      ledMatrix_->setTextColor(paletteColors_[currColorIndex_]);
    }
    printMatrixName();
  }
}

void LightingRobot::doMatrixBlinking(unsigned long ellapsedTime) {
  if (quaverChange_) {
    matrixOn_ = !matrixOn_;
    if (matrixOn_) {
      currColorIndex_ = ++currColorIndex_ % NB_PALETTE_COLORS;
      for (unsigned int ii = 0; ii < nbMtxHor_; ii++) {
        unsigned int colorIdx = (currColorIndex_ + ii) % NB_PALETTE_COLORS;
        ledMatrix_->fillRect(ii * w_, 0, w_, h_, paletteColors_[colorIdx]);
      }
      ledMatrix_->show();
    } else {
      ledMatrix_->clear();
      ledMatrix_->show();
    }
  }
}

void LightingRobot::doMatrixLogo(unsigned long ellapsedTime) {
  if (quarterNoteChange_) {
    currBitmap_ = ++currBitmap_ % NB_POSITIONS;
    printMatrixLogo();
  }
}

void LightingRobot::doMatrixRectangles(unsigned long ellapsedTime) {
  if (quaverChange_) {
    currColorIndex_ = ++currColorIndex_ % NB_PALETTE_COLORS;
    printMatrixRectangles();
  }
}

void LightingRobot::doMatrixBars(unsigned long ellapsedTime) {
  if (quarterNoteChange_) {
    currColorIndex_ = ++currColorIndex_ % NB_PALETTE_COLORS;
    printMatrixBars();
  }
}

void LightingRobot::doSpotlightBlinking(unsigned long ellapsedTime) {
  if (quaverChange_) {
    if (spotlightsOn_) {
      turnOffSpotlights();
    } else {
      turnOnSpotlights();
    }
  }
}

void LightingRobot::doSpotlightSequence(unsigned long ellapsedTime) {
  if (semiquaverChange_) {
    digitalWrite(spotlightPins_[currSpotlight_], LOW);
    currSpotlight_ = ++currSpotlight_ % NB_SPOTLIGHTS;
    digitalWrite(spotlightPins_[currSpotlight_], HIGH);
  }
}

void LightingRobot::treatStartMsg() {
  hasStarted_ = true;
  turnOnSpotlights();
}

void LightingRobot::treatResyncMsg() {
}

void LightingRobot::treatBpmChangeMsg(uint8_t messageContent) {
  setBpm(messageContent);
}

void LightingRobot::treatModeChangeMsg(uint8_t messageContent) {
  uint8_t element = messageContent & MASK_ELEMENT_IDENTIFIER;
  uint8_t mode = (messageContent & MASK_LIGHTING_MODE) >> BITS_PER_ELEMENT_IDENTIFIER;
  switch (element) {
    case MATRIX:
      matrixMode_ = mode;
      initializeMatrixMode();
      break;
    case SPOTLIGHT:
      spotlightMode_ = mode;
      initializeSpotlightMode();
      break;
  }
}

void LightingRobot::treatSetResyncTimeMsg(uint16_t messageContent) {
}

void LightingRobot::clearAllLights() {
  clearMatrix();
  turnOffSpotlights();
}

void LightingRobot::clearMatrix() {
  ledMatrix_->clear();
  ledMatrix_->show();
  matrixOn_ = false;
}

void LightingRobot::turnOffSpotlights() {
  for (unsigned int ii = 0; ii < NB_SPOTLIGHTS; ii++) {
    digitalWrite(spotlightPins_[ii], LOW);
  }
  spotlightsOn_ = false;
}

void LightingRobot::turnOnSpotlights() {
  for (unsigned int ii = 0; ii < NB_SPOTLIGHTS; ii++) {
    digitalWrite(spotlightPins_[ii], HIGH);
  }
  spotlightsOn_ = true;
}

void LightingRobot::initializeMatrixMode() {
  switch (matrixMode_) {
    case MATRIX_OFF_MODE:
    case MATRIX_BLINKING_MODE:
      clearMatrix();
      break;
    case MATRIX_NAME_MODE:
      printMatrixName();
      break;
    case MATRIX_LOGO_MODE:
      printMatrixLogo();
      break;
    case MATRIX_RECTANGLES_MODE:
      printMatrixRectangles();
      break;
    case MATRIX_BARS_MODE:
      printMatrixBars();
      break;
  }
}

void LightingRobot::initializeSpotlightMode() {
  switch (spotlightMode_) {
    case SPOTLIGHT_OFF_MODE:
    case SPOTLIGHT_BLINKING_MODE:
      turnOffSpotlights();
      break;
    case SPOTLIGHT_SEQUENCE_MODE:
      turnOffSpotlights();
      digitalWrite(spotlightPins_[currSpotlight_], HIGH);
      break;
    case SPOTLIGHT_CONSTANT_MODE:
      turnOnSpotlights();
      break;
  }
}

void LightingRobot::printMatrixName() {
  ledMatrix_->clear();
  ledMatrix_->setCursor(x_, 5);
  ledMatrix_->print(F("MEKANIKA"));
  ledMatrix_->show();
}

void LightingRobot::printMatrixLogo() {
  ledMatrix_->clear();
  for (unsigned int ii = 0; ii < nbMtxHor_; ii++) {
    unsigned int bitmapIdx = (currBitmap_ + ii) % NB_POSITIONS;
    ledMatrix_->drawRGBBitmap(ii * w_, 0, image_data_gear[bitmapIdx], w_, h_);
  }
  ledMatrix_->show();
}

void LightingRobot::printMatrixRectangles() {
  ledMatrix_->clear();

  unsigned int colorIdx = currColorIndex_;
  for (unsigned int ii = 0; ii < halfSize_; ii++) {
    for (unsigned int jj = 0; jj < nbMtxHor_; jj++) {
      ledMatrix_->drawRect(ii + jj * w_, ii, w_ - 2 * ii, h_ - 2 * ii, paletteColors_[colorIdx]);
    }
    colorIdx = ++colorIdx % NB_PALETTE_COLORS;
  }

  ledMatrix_->show();
}

void LightingRobot::printMatrixBars() {
  ledMatrix_->clear();

  unsigned int colorIdx = currColorIndex_;
  for (unsigned int ii = 0; ii < w_ * nbMtxHor_; ii += BAR_WIDTH) {
    ledMatrix_->drawLine(ii, 0, ii + BAR_WIDTH, h_ - 1, paletteColors_[colorIdx]);
    colorIdx = ++colorIdx % NB_PALETTE_COLORS;
  }

  ledMatrix_->show();
}

void LightingRobot::checkNoteChanges(unsigned long currTime) {
  semiquaverChange_ = false;
  quaverChange_ = false;
  quarterNoteChange_ = false;
  halfNoteChange_ = false;
  wholeNoteChange_ = false;


  if (lastSemiquaverChange_ - currTime >= semiquaverInterval_) {
    semiquaverChange_ = true;
    lastSemiquaverChange_ += semiquaverInterval_;
    semiquaverCount_++;

    if (semiquaverCount_ % SEMIQUAVERS_PER_WHOLE_NOTE == 0) {
      semiquaverCount_ = 0;

      wholeNoteChange_ = true;
      halfNoteChange_ = true;
      quarterNoteChange_ = true;
      quaverChange_ = true;
    } else if (semiquaverCount_ % SEMIQUAVERS_PER_HALF_NOTE == 0) {
      halfNoteChange_ = true;
      quarterNoteChange_ = true;
      quaverChange_ = true;
    } else if (semiquaverCount_ % SEMIQUAVERS_PER_QUARTER_NOTE == 0) {
      quarterNoteChange_ = true;
      quaverChange_ = true;
    } else if (semiquaverCount_ % SEMIQUAVERS_PER_QUAVER == 0) {
      quaverChange_ = true;
    }
  }
}