#ifndef Lighting_robot_h
#define Lighting_robot_h

#include <robo_receptor.h>
#include <robo_communication.h>

#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

#ifndef PSTR
#define PSTR  // Make Arduino Due happy
#endif

class LightingRobot : public RoboReceptor {
public:
  LightingRobot();
  LightingRobot(int matrixWidth, int matrixHeight, int matrixPin, int brightness, int address);

  void setMode(uint8_t mode);
  void doLighting();

  void treatStartMsg();
  void treatResyncMsg();
  void treatBpmChangeMsg(uint8_t messageContent);
  void treatModeChangeMsg(uint8_t messageContent);
  void treatSetResyncTimeMsg(uint16_t messageContent);

private:
  uint8_t mode_;
  Adafruit_NeoMatrix *matrix_;

  uint16_t primaryColors_[3];
  int x_, pass_;
  bool hasStarted_, blink_;
};

#endif