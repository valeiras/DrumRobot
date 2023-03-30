#ifndef Music_box_robot_h
#define Music_box_robot_h

#include <Servo.h>
#include <Arduino.h>

#define V_MIN 87
#define V_MAX 59
#define STOP 90

class MusicBoxRobot {
public:
  MusicBoxRobot();
  MusicBoxRobot(int servoPin, int sensorPin);

  void goToPos(uint16_t pos, uint8_t vel);
  void goToInitialPos();

  uint16_t getSensorRead();
  uint16_t getPos();

  void setVelOrder(uint8_t velOrder);
  void stop();

private:
  Servo servo_;
  int sensorPin_;
};

#endif