#ifndef Lighting_robot_h
#define Lighting_robot_h

#include <robo_receptor.h>
#include <robo_communication.h>

#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

#define MS_PER_MIN 60000
#define NB_OF_SPOTLIGHTS 6

class LightingRobot : public RoboReceptor {
public:
  LightingRobot();
  LightingRobot(int matrixWidth, int matrixHeight, int matrixPin, int spotlightPin[NB_OF_SPOTLIGHTS], int brightness, int address, int bpm);

  void setMode(uint8_t mode);
  void setBpm(uint8_t bpm);

  void doLighting(unsigned long currTime);
  void doNameLighting(unsigned long ellapsedTime);
  void doBlinkLighting();
  void doLogoLighting();

  void treatStartMsg();
  void treatResyncMsg();
  void treatBpmChangeMsg(uint8_t messageContent);
  void treatModeChangeMsg(uint8_t messageContent);
  void treatSetResyncTimeMsg(uint16_t messageContent);

private:
  uint8_t mode_, bpm_;
  Adafruit_NeoMatrix *ledMatrix_;
  int spotlightPins_[NB_OF_SPOTLIGHTS];
  int currSpotlightOn_;

  uint16_t primaryColors_[3];
  int x_, pass_;
  bool hasStarted_, blink_;
  unsigned long initTime_, lastBlink_, blinkingTime_;
};

#endif