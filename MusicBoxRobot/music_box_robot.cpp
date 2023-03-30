#include "music_box_robot.h"
#include "music_box_config.h"

MusicBoxRobot::MusicBoxRobot() {
}

MusicBoxRobot::MusicBoxRobot(int servoPin, int sensorPin) {
  servo_.attach(servoPin);

  sensorPin_ = sensorPin;
  pinMode(sensorPin_, INPUT);
}

void MusicBoxRobot::goToPos(uint16_t pos, uint8_t vel) {
  setVelOrder(vel);
  // First, if we are below the desired value, we loop until we start the new loop
  int valueRead;
  do {
    valueRead = getSensorRead();
  } while (valueRead < pos);
  do {
    valueRead = getSensorRead();
  } while (valueRead > pos);
}

uint16_t MusicBoxRobot::getPos() {
  //uint16_t analogValue = analogRead(sensorPin_);
  //return map(analogValue, MIN_ANALOG_READ, MAX_ANALOG_READ, MIN_POS, MAX_POS);
  return 0;
}

uint16_t MusicBoxRobot::getSensorRead() {
  return analogRead(sensorPin_);
}

void MusicBoxRobot::setVelOrder(uint8_t velOrder) {
  servo_.write(velOrder);
}

void MusicBoxRobot::stop(){
  servo_.write(STOP);
}

void MusicBoxRobot::goToInitialPos() {
  goToPos(START_POSITION, V_MAX);
}