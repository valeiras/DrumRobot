#include "lighting_robot.h"

LightingRobot::LightingRobot() {}

LightingRobot::LightingRobot(int matrixWidth, int matrixHeight, int matrixPin, int brightness, int address)
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
}

void LightingRobot::setMode(uint8_t mode) {
  mode_ = mode;
}

void LightingRobot::doLighting() {
  if (hasStarted_) {
    switch (mode_) {
      case NAME_MODE:
        matrix_->fillScreen(0);
        matrix_->setCursor(x_, 5);
        matrix_->print(F("MEKANIKA"));
        if (--x_ < -36) {
          x_ = matrix_->width();
          if (++pass_ >= 3) pass_ = 0;
          matrix_->setTextColor(primaryColors_[pass_]);
        }
        matrix_->show();
        break;
      case BLINKING_MODE:
        if (blink_) {
          matrix_->fillScreen(matrix_->Color(0, 0, 0));
        } else {
          matrix_->fillScreen(matrix_->Color(0, 20, 0));
        }
        blink_ = !blink_;
        break;
      case LOGO_MODE:
        if (blink_) {
          matrix_->fillScreen(matrix_->Color(0, 0, 0));
        } else {
          matrix_->fillScreen(matrix_->Color(100, 0, 0));
        }
        blink_ = !blink_;
        break;
    }
  }
}

void LightingRobot::treatStartMsg() {
  hasStarted_ = true;
}

void LightingRobot::treatResyncMsg() {
}

void LightingRobot::treatBpmChangeMsg(uint8_t messageContent) {
}

void LightingRobot::treatModeChangeMsg(uint8_t messageContent) {
  mode_ = messageContent;
}

void LightingRobot::treatSetResyncTimeMsg(uint16_t messageContent) {
}