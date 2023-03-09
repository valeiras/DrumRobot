#include "lighting_robot.h"

LightingRobot::LightingRobot() {}

LightingRobot::LightingRobot(int matrixWidth, int matrixHeight, int matrixPin, int spotlightPins[NB_SPOTLIGHTS], int brightness, int address, int bpm)
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
  // ledMatrix_ = new Adafruit_NeoMatrix(matrixWidth, matrixHeight, nbMatricesHor, nbMatricesVert, matrixPin,
  //                                     NEO_MATRIX_TOP + NEO_MATRIX_LEFT + NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
  //                                     NEO_GRB + NEO_KHZ800);

  w_ = matrixWidth;
  h_ = matrixHeight;
  ledMatrix_ = new Adafruit_NeoMatrix(w_, h_, matrixPin,
                                      NEO_MATRIX_TOP + NEO_MATRIX_RIGHT + NEO_MATRIX_ROWS + NEO_MATRIX_ZIGZAG,
                                      NEO_GRB + NEO_KHZ800);

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
  setBpm(bpm);

  lastMatrixBlinkingTime_ = 0;
  lastSpotlightBlinkingTime_ = 0;
  matrixOn_ = false;
  spotlightOn_ = false;

  for (unsigned int ii = 0; ii < NB_SPOTLIGHTS; ii++) {
    spotlightPins_[ii] = spotlightPins[ii];
    pinMode(spotlightPins_[ii], OUTPUT);
  }
  currSpotlight_ = 2;

  clearAllLights();
}

void LightingRobot::setBpm(uint8_t bpm) {
  bpm_ = bpm;
  blinkingInterval_ = MS_PER_MIN / (bpm_*4);
}

void LightingRobot::doLighting(unsigned long currTime) {
  if (hasStarted_) {
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
        break;
      case SPOTLIGHT_BLINKING_MODE:
        doSpotlightBlinking(currTime);
        break;
      case SPOTLIGHT_SEQUENCE_MODE:
        doSpotlightSequence(currTime);
        break;
      case SPOTLIGHT_CONSTANT_MODE:
        doSpotlightConstant(currTime);
        break;
    }
  }
  lastLightingTime_ = currTime;
}

void LightingRobot::doMatrixName(unsigned long ellapsedTime) {
  if (ellapsedTime - lastMatrixBlinkingTime_ >= blinkingInterval_) {
    lastMatrixBlinkingTime_ += blinkingInterval_;
    x_++;
    ledMatrix_->fillScreen(0);
    ledMatrix_->setCursor(x_, 5);
    ledMatrix_->print(F("MEKANIKA"));
    if (x_ > 36) {
      x_ = -ledMatrix_->width();
      if (++currColorIndex_ >= NB_PALETTE_COLORS) currColorIndex_ = 0;
      ledMatrix_->setTextColor(paletteColors_[currColorIndex_]);
    }
    ledMatrix_->show();
  }
}

void LightingRobot::doMatrixBlinking(unsigned long ellapsedTime) {
  if (ellapsedTime - lastMatrixBlinkingTime_ >= blinkingInterval_) {
    matrixOn_ = !matrixOn_;
    lastMatrixBlinkingTime_ += blinkingInterval_;
    if (matrixOn_) {
      currColorIndex_ = ++currColorIndex_ % NB_PALETTE_COLORS;
      ledMatrix_->fillScreen(paletteColors_[currColorIndex_]);
      ledMatrix_->show();
    } else {
      ledMatrix_->fillScreen(0);
      ledMatrix_->show();
    }
  }
}

void LightingRobot::doMatrixLogo(unsigned long ellapsedTime) {
  if (!matrixOn_) {
    ledMatrix_->clear();
    ledMatrix_->drawRGBBitmap(0, 0, image_data_gear[currBitmap_], w_, h_);
    ledMatrix_->show();
    matrixOn_ = true;
  }
  if (ellapsedTime - lastMatrixBlinkingTime_ >= blinkingInterval_) {
    currBitmap_ = ++currBitmap_ % NB_POSITIONS;
    ledMatrix_->clear();
    lastMatrixBlinkingTime_ += blinkingInterval_;
    ledMatrix_->drawRGBBitmap(0, 0, image_data_gear[currBitmap_], w_, h_);
    ledMatrix_->show();
  }
}

void LightingRobot::doMatrixRectangles(unsigned long ellapsedTime) {
  Serial.println("Rectangles");
  if (ellapsedTime - lastMatrixBlinkingTime_ >= blinkingInterval_) {
    Serial.println("Changing");
    ledMatrix_->clear();
    lastMatrixBlinkingTime_ += blinkingInterval_;

    unsigned int minDimension = min(w_, h_);
    unsigned int halfSize = ceil(minDimension / 2.0);

    unsigned int colorIdx = currColorIndex_;
    for (unsigned int ii = 0; ii < halfSize; ii++) {
      ledMatrix_->drawRect(ii, ii, w_ - 2 * ii, h_ - 2 * ii, paletteColors_[colorIdx]);
      colorIdx = ++colorIdx % NB_PALETTE_COLORS;
    }
    ledMatrix_->show();
    currColorIndex_ = ++currColorIndex_ % NB_PALETTE_COLORS;
  }
}

void LightingRobot::doMatrixBars(unsigned long ellapsedTime) {
  if (ellapsedTime - lastMatrixBlinkingTime_ >= blinkingInterval_) {
    ledMatrix_->clear();
    lastMatrixBlinkingTime_ += blinkingInterval_;

    unsigned int colorIdx = currColorIndex_;
    for (unsigned int ii = 0; ii < w_; ii += BAR_WIDTH) {
      ledMatrix_->drawLine(ii, 0, ii + BAR_WIDTH, h_ - 1, paletteColors_[colorIdx]);
      colorIdx = ++colorIdx % NB_PALETTE_COLORS;
    }
    ledMatrix_->show();
    currColorIndex_ = ++currColorIndex_ % NB_PALETTE_COLORS;
  }
}

void LightingRobot::doSpotlightBlinking(unsigned long ellapsedTime) {
  if (ellapsedTime - lastSpotlightBlinkingTime_ >= blinkingInterval_) {
    spotlightOn_ = !spotlightOn_;
    lastSpotlightBlinkingTime_ += blinkingInterval_;
    if (spotlightOn_) {
      turnOnSpotlights();
    } else {
      turnOffSpotlights();
    }
  }
}

void LightingRobot::doSpotlightSequence(unsigned long ellapsedTime) {
  if (ellapsedTime - lastSpotlightBlinkingTime_ >= blinkingInterval_) {
    digitalWrite(spotlightPins_[currSpotlight_], LOW);
    currSpotlight_ = ++currSpotlight_ % NB_SPOTLIGHTS;
    digitalWrite(spotlightPins_[currSpotlight_], HIGH);
    lastSpotlightBlinkingTime_ += blinkingInterval_;
  }
}

void LightingRobot::doSpotlightConstant(unsigned long ellapsedTime) {
  if (!spotlightOn_) {
    turnOnSpotlights();
    spotlightOn_ = true;
  }
}

void LightingRobot::treatStartMsg() {
  hasStarted_ = true;
  lastSpotlightBlinkingTime_ = lastLightingTime_;
  lastMatrixBlinkingTime_ = lastLightingTime_;
}

void LightingRobot::treatResyncMsg() {
}

void LightingRobot::treatBpmChangeMsg(uint8_t messageContent) {
  setBpm(messageContent);
}

void LightingRobot::treatModeChangeMsg(uint8_t messageContent) {
  uint8_t element = messageContent & MASK_ELEMENT_IDENTIFIER;
  uint8_t mode = (messageContent & MASK_LIGHTING_MODE) >> BITS_PER_ELEMENT_IDENTIFIER;
  Serial.print("Element: ");
  Serial.println(element);
  switch (element) {
    case MATRIX:
      Serial.print("[LightingRobot] Matrix mode: ");
      Serial.println(mode);
      matrixMode_ = mode;
      clearMatrix();
      lastMatrixBlinkingTime_ = lastLightingTime_;
      break;
    case SPOTLIGHT:
      spotlightMode_ = mode;
      turnOffSpotlights();
      lastSpotlightBlinkingTime_ = lastLightingTime_;
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
  spotlightOn_ = false;
}

void LightingRobot::turnOnSpotlights() {
  for (unsigned int ii = 0; ii < NB_SPOTLIGHTS; ii++) {
    digitalWrite(spotlightPins_[ii], HIGH);
  }
}