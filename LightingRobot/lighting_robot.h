#ifndef Lighting_robot_h
#define Lighting_robot_h

#include "gear.h"

#include <robo_receptor.h>
#include <robo_communication.h>

#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

#include <math.h>

#define MS_PER_MIN 60000
#define NB_SPOTLIGHTS 6

#define NB_PRIMARY_COLORS 3
#define NB_PALETTE_COLORS 4

#define BAR_WIDTH 2

class LightingRobot : public RoboReceptor {
public:
  LightingRobot();
  LightingRobot(int matrixWidth, int matrixHeight, int matrixPin, int spotlightPin[NB_SPOTLIGHTS], int brightness, int address, int bpm);

  void setBpm(uint8_t bpm);

  void doLighting(unsigned long currTime);
  
  void treatStartMsg();
  void treatResyncMsg();
  void treatBpmChangeMsg(uint8_t messageContent);
  void treatModeChangeMsg(uint8_t messageContent);
  void treatSetResyncTimeMsg(uint16_t messageContent);

private:
  void doMatrixName(unsigned long ellapsedTime);
  void doMatrixBlinking(unsigned long ellapsedTime);
  void doMatrixLogo(unsigned long ellapsedTime);
  void doMatrixRectangles(unsigned long ellapsedTime);
  void doMatrixBars(unsigned long ellapsedTime);
  
  void doSpotlightBlinking(unsigned long ellapsedTime);
  void doSpotlightSequence(unsigned long ellapsedTime);
  void doSpotlightConstant(unsigned long ellapsedTime);

  void clearAllLights();
  void clearMatrix();
  void turnOffSpotlights();
  void turnOnSpotlights();

  uint8_t matrixMode_, spotlightMode_, bpm_;
  int w_, h_;
  Adafruit_NeoMatrix *ledMatrix_;
  int spotlightPins_[NB_SPOTLIGHTS];
  int currSpotlight_;

  uint16_t primaryColors_[NB_PRIMARY_COLORS], paletteColors_[NB_PALETTE_COLORS];
  int x_, currColorIndex_, currBitmap_;
  bool hasStarted_, matrixOn_, spotlightOn_;
  unsigned long lastLightingTime_, lastMatrixBlinkingTime_, lastSpotlightBlinkingTime_, blinkingInterval_;
};

#endif