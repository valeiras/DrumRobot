#include "music_box_controller.h"

MusicBoxController::MusicBoxController()
  : RoboReceptor() {
}

MusicBoxController::MusicBoxController(int address, MusicBoxRobot* robot, MusicBoxSong* song)
  : RoboReceptor(address) {
    robot_ = robot;
    song_ = song;
    
    robot_->initializeRobot();
}

void MusicBoxController::treatStartMsg() {
  hasStarted_ = true;
}

void MusicBoxController::treatResyncMsg() {
}

void MusicBoxController::treatBpmChangeMsg(uint8_t messageContent) {
  setBpm(messageContent);
}

void MusicBoxController::treatModeChangeMsg(uint8_t messageContent) {
}

void MusicBoxController::treatSetResyncTimeMsg(uint16_t messageContent) {
}

void MusicBoxController::setBpm(int bpm){
  bpm_ = bpm;
  unsigned long timeQuarter = int(60000.0 / bpm_);  // us per quarter note
  timePerSemiquaver_ = int(timeQuarter / 4.0);      // us per semiquaver note
}