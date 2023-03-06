#include "music_box_robot.h"

MusicBoxRobot::MusicBoxRobot() {
}

MusicBoxRobot::MusicBoxRobot(int servoPin, int sensorPin) {
  servo_.attach(servoPin);

  sensorPin_ = sensorPin;
  pinMode(sensorPin_, OUTPUT);
}

void MusicBoxRobot::goToPos(int vel) {
}

int MusicBoxRobot::getPos() {
  int analogValue = analogRead(sensorPin_);
  return map(analogValue, MIN_ANALOG_READ, MAX_ANALOG_READ, MIN_POS, MAX_POS);
}

void MusicBoxRobot::setVel(int vel) {
  servo_.write(vel);
}