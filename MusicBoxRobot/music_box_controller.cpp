#include "music_box_controller.h"

MusicBoxController::MusicBoxController(MusicBoxRobot* mbRobot, MusicBoxSong* mbSong,
                                       MusicBoxPercuRobot* prcRobot, PercuSong<NB_HIT_JOINTS_MB, BITS_FOR_POS_MB>* prcSong,
                                       int address, bool simulation, bool printOutput)
  : PercuController<NB_HIT_JOINTS_MB, NB_POS_JOINTS_MB, BITS_FOR_POS_MB>(prcRobot, prcSong,
                                                                         address, simulation, printOutput) {
  mbSong_ = mbSong;
  mbRobot_ = mbRobot;
  mbSong_->printInstructions();

  currVelOrder_ = bpmOrders[DEFAULT_BPM_IDX];
  currInstructionIsOn_ = mbSong_->getNextInstruction(nbSemiquaversNextInstruction_);

  Serial.print("Constructor: Current instruction: ");
  Serial.println(currInstructionIsOn_);
  semiquaverCount_ = 0;
}

void MusicBoxController::treatStartMsg() {
  PercuController::treatStartMsg();

  if (hasStarted_ && currInstructionIsOn_) {
    mbRobot_->setVelOrder(currVelOrder_);
  } else {
    mbRobot_->stop();
  }
}

void MusicBoxController::treatResyncMsg() {
  PercuController::treatResyncMsg();
}

void MusicBoxController::treatBpmChangeMsg(uint8_t messageContent) {
  PercuController::treatBpmChangeMsg(messageContent);
}

void MusicBoxController::treatBpmIdxChangeMsg(uint8_t messageContent) {
  PercuController::treatBpmIdxChangeMsg(messageContent);

  currVelOrder_ = bpmOrders[messageContent];
  if (hasStarted_ && currInstructionIsOn_) {
    mbRobot_->setVelOrder(currVelOrder_);
  }
}

void MusicBoxController::treatModeChangeMsg(uint8_t messageContent) {
PercuController:
  treatModeChangeMsg(messageContent);
}

void MusicBoxController::treatSetResyncTimeMsg(uint16_t messageContent) {
PercuController:
  treatSetResyncTimeMsg(messageContent);
}

void MusicBoxController::goToTime(unsigned long currTime) {
  int semiquaversEllapsed = PercuController::goToTime(currTime);
  if(semiquaversEllapsed != 0){
    Serial.println(semiquaversEllapsed);
  }

  semiquaverCount_ += semiquaversEllapsed;
  if (semiquaverCount_ > nbSemiquaversNextInstruction_) {
    semiquaverCount_ = semiquaverCount_ - (nbSemiquaversNextInstruction_-1);
    currInstructionIsOn_ = mbSong_->getNextInstruction(nbSemiquaversNextInstruction_);
    if (currInstructionIsOn_) {
      mbRobot_->setVelOrder(currVelOrder_);
    } else {
      mbRobot_->stop();
    }
  }
}