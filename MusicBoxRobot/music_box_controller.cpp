#include "music_box_controller.h"

MusicBoxController::MusicBoxController(MusicBoxRobot* mbRobot, MusicBoxSong* mbSong,
                                       MusicBoxPercuRobot* prcRobot, PercuSong<NB_HIT_JOINTS_MB, BITS_FOR_POS_MB>* prcSong,
                                       int address, bool isSimulation, bool hasOutput)
  : PercuController<NB_HIT_JOINTS_MB, NB_POS_JOINTS_MB, BITS_FOR_POS_MB>(prcRobot, prcSong,
                                                                         address, isSimulation, hasOutput) {
  mbSong_ = mbSong;
  mbRobot_ = mbRobot;

  currVelOrder_ = bpmOrders[DEFAULT_BPM_IDX];
  currInstructionIsOn_ = mbSong_->getNextInstruction(nbSemiquaversNextInstruction_);
  firstMbAfterStart_ = false;
  semiquaverCount_ = 0;
}

void MusicBoxController::treatStartMsg() {
  if (!hasStarted_) {
    mbSong_->restartSong();
    currInstructionIsOn_ = mbSong_->getNextInstruction(nbSemiquaversNextInstruction_);
    semiquaverCount_ = 0;
    firstMbAfterStart_ = true;
  }
  PercuController::treatStartMsg();
}

void MusicBoxController::treatStopMsg() {
  mbRobot_->stop();
  PercuController::treatStopMsg();
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
  if (hasStarted_ && firstMbAfterStart_) {
    lastOrderTime_ = currTime;
    firstMbAfterStart_ = false;

    if (currInstructionIsOn_) {
      mbRobot_->setVelOrder(currVelOrder_);
    }
  }

  int semiquaversEllapsed = PercuController::goToTime(currTime);

  semiquaverCount_ += semiquaversEllapsed;
  if (semiquaverCount_ >= nbSemiquaversNextInstruction_) {
    semiquaverCount_ = semiquaverCount_ - nbSemiquaversNextInstruction_;
    currInstructionIsOn_ = mbSong_->getNextInstruction(nbSemiquaversNextInstruction_);
    if (currInstructionIsOn_) {
      mbRobot_->setVelOrder(currVelOrder_);
    } else {
      mbRobot_->stop();
    }
    unsigned long ellapsedTime = currTime - lastOrderTime_;
    Serial.print("Ellapsed time = ");
    Serial.println(ellapsedTime);
    Serial.print("Sensor read: ");
    Serial.println(mbRobot_->getSensorRead());
    lastOrderTime_ = currTime;
  }
}