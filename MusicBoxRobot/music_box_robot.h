#ifndef Music_box_robot_h
#define Music_box_robot_h

#include <Servo.h>
#include <Arduino.h>

#define MIN_POS 0
#define MAX_POS 360
#define MIN_ANALOG_READ 0
#define MAX_ANALOG_READ 1023

class MusicBoxRobot {
public:
  MusicBoxRobot();
  MusicBoxRobot(int servoPin, int sensorPin);

  void goToPos(int vel);
  int getPos();
  
  void setVel(int vel);
private:
  Servo servo_;
  int sensorPin_;
};

#endif