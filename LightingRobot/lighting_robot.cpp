#include "lighting_robot.h"

LightingRobot::LightingRobot() {}

LightingRobot::LightingRobot(int matrixWidth, int matrixHeight, int matrixPin, int lightPin, int brightness, int address, int bpm)
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
  matrix_ = new Adafruit_NeoMatrix(matrixWidth, matrixHeight, matrixPin,
                                   NEO_MATRIX_TOP + NEO_MATRIX_LEFT + NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
                                   NEO_GRB + NEO_KHZ800);

  matrix_->begin();
  matrix_->setTextWrap(false);
  matrix_->setBrightness(brightness);

  // We set the primary colors
  primaryColors_[0] = matrix_->Color(255, 0, 0);
  primaryColors_[1] = matrix_->Color(0, 255, 0);
  primaryColors_[2] = matrix_->Color(0, 0, 255);

  matrix_->setTextColor(primaryColors_[0]);

  x_ = matrix_->width();
  pass_ = 0;
  hasStarted_ = false;

  mode_ = NAME_MODE;
  setBpm(bpm);

  initTime_ = 0;
  lastBlink_ = 0;
  blink_ = true;

  lightPin_ = lightPin;
  pinMode(lightPin_, OUTPUT);
}

void LightingRobot::setMode(uint8_t mode) {
  mode_ = mode;
}

void LightingRobot::setBpm(uint8_t bpm) {
  bpm_ = bpm;
  blinkingTime_ = MS_PER_MIN / (16 * bpm_);
  // Serial.print("[Lighting robot] Setting bpm: ");
  // Serial.println(bpm);
}

void LightingRobot::doLighting(unsigned long currTime) {
  if (hasStarted_) {
    unsigned long ellapsedTime = currTime - initTime_;
    // Serial.print("[LightingRobot] Curr time: ");
    // Serial.println(currTime);
    // Serial.print("[LightingRobot] Ellapsed time: ");
    // Serial.println(ellapsedTime);
    // Serial.print("[LightingRobot] Blinking time: ");
    // Serial.println(blinkingTime_);
    if (ellapsedTime - lastBlink_ > blinkingTime_) {
      //Serial.println("[LightingRobot] Change blinking state!");
      blink_ = !blink_;
      //lastBlink_ += blinkingTime_;
      lastBlink_ = ellapsedTime;
      x_--;
    }
    switch (mode_) {
      case NAME_MODE:
        doNameLighting(ellapsedTime);
        break;
      case BLINKING_MODE:
        doBlinkLighting();
        break;
      case LOGO_MODE:
        doLogoLighting();
        break;
    }
  } else {
    initTime_ = currTime;
  }
}

void LightingRobot::doNameLighting(unsigned long ellapsedTime) {
  matrix_->fillScreen(0);
  matrix_->setCursor(x_, 5);
  matrix_->print(F("MEKANIKA  "));
  if (x_ < -36) {
    x_ = matrix_->width();
    if (++pass_ >= 3) pass_ = 0;
    matrix_->setTextColor(primaryColors_[pass_]);
  }
  matrix_->show();
  digitalWrite(lightPin_, HIGH);
}

void LightingRobot::doBlinkLighting() {
  if (blink_) {
    matrix_->fillScreen(matrix_->Color(0, 0, 0));
    matrix_->show();
    digitalWrite(lightPin_, HIGH);
  } else {
    matrix_->fillScreen(matrix_->Color(0, 50, 0));
    matrix_->show();
    digitalWrite(lightPin_, LOW);
  }
}

void LightingRobot::doLogoLighting() {
  if (blink_) {
    matrix_->fillScreen(matrix_->Color(0, 0, 0));
    matrix_->show();
    digitalWrite(lightPin_, HIGH);
  } else {
    matrix_->fillScreen(matrix_->Color(50, 0, 0));
    matrix_->show();
    digitalWrite(lightPin_, LOW);
  }
}

void LightingRobot::treatStartMsg() {
  hasStarted_ = true;
  lastBlink_ = initTime_;
}

void LightingRobot::treatResyncMsg() {
}

void LightingRobot::treatBpmChangeMsg(uint8_t messageContent) {
  setBpm(messageContent);
}

void LightingRobot::treatModeChangeMsg(uint8_t messageContent) {
  mode_ = messageContent;
}

void LightingRobot::treatSetResyncTimeMsg(uint16_t messageContent) {
}