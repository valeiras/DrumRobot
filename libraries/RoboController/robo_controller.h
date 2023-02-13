#ifndef Robo_controller_h
#define Robo_controller_h

#include <Array.h>
#include <percu_robot.h>
#include <robo_song.h>

#include "Arduino.h"

#define POS_SECURITY_FACTOR 0.5

template <byte NB_HIT_JOINTS, byte NB_POS_JOINTS, byte BITS_FOR_POS>
class RoboController {
 public:
  RoboController(PercuRobot<NB_HIT_JOINTS, NB_POS_JOINTS> *robot, RoboSong<NB_HIT_JOINTS, BITS_FOR_POS> *song,
                 unsigned short bpm, bool simulation, bool printOutput);

  // This method should be called once all the parameters of the robot and the song have been set
  void initializeRobot();

  void setInitialTime(unsigned long currTime);
  void goToTime(unsigned long currTime, bool printOutput = 0);

  void manageHitInstruction(byte limb, unsigned long currTime);
  void managePosInstruction(byte limb);

  bool isTimeToChangePos(byte limb, unsigned long ellapsedTime);

  void setBpm(unsigned short bpm);

 private:
  PercuRobot<NB_HIT_JOINTS, NB_POS_JOINTS> *robot_;
  RoboSong<NB_HIT_JOINTS, BITS_FOR_POS> *song_;

  unsigned long timeNextHitInstruction_[NB_HIT_JOINTS], timeNextPosInstruction_[NB_POS_JOINTS];
  byte nextInstruction_[NB_HIT_JOINTS];
  bool moveLimb_[NB_POS_JOINTS];
  byte nextPos_[NB_POS_JOINTS];

  unsigned short bpm_;
  unsigned int timePerSemiquaver_;
  unsigned long timeNextSemiquaver_;

  bool simulation_, printOutput_;
};

template <byte NB_HIT_JOINTS, byte NB_POS_JOINTS, byte BITS_FOR_POS>
RoboController<NB_HIT_JOINTS, NB_POS_JOINTS, BITS_FOR_POS>::RoboController(PercuRobot<NB_HIT_JOINTS, NB_POS_JOINTS> *robot,
                                                                           RoboSong<NB_HIT_JOINTS, BITS_FOR_POS> *song,
                                                                           unsigned short bpm, bool simulation, bool printOutput) {
  robot_ = robot;
  song_ = song;

  setBpm(bpm);

  simulation_ = simulation;
  printOutput_ = printOutput;
}

template <byte NB_HIT_JOINTS, byte NB_POS_JOINTS, byte BITS_FOR_POS>
void RoboController<NB_HIT_JOINTS, NB_POS_JOINTS, BITS_FOR_POS>::initializeRobot() {
  for (unsigned int limb = 0; limb < NB_POS_JOINTS; limb++) {
    timeNextPosInstruction_[limb] = 0;
    moveLimb_[limb] = false;
  }

  song_->goToFirstSemiquaver(printOutput_);
  for (unsigned int limb = 0; limb < NB_HIT_JOINTS; limb++) {
    nextInstruction_[limb] = HIT;

    if (limb < NB_POS_JOINTS) {
      nextPos_[limb] = song_->getPosNextHit(limb);
      timeNextHitInstruction_[limb] = timeNextSemiquaver_ + song_->getSemiquaversToNextHit(limb) * timePerSemiquaver_ - robot_->getHitTime(limb, nextPos_[limb], song_->getVelNextHit(limb));
      if (printOutput_) {
        Serial.print("Computing time for next hit for limb ");
        Serial.println(limb);
        Serial.print("Semiquavers to next hit: ");
        Serial.print(song_->getSemiquaversToNextHit(limb));
        Serial.print(", hit time: ");
        Serial.print(robot_->getHitTime(limb, nextPos_[limb], song_->getVelNextHit(limb)));
        Serial.print(", result: ");
        Serial.println(timeNextHitInstruction_[limb]);
      }
      robot_->rest(limb, nextPos_[limb]);
      robot_->goToPos(limb, nextPos_[limb]);
    } else {
      timeNextHitInstruction_[limb] = timeNextSemiquaver_ + song_->getSemiquaversToNextHit(limb) * timePerSemiquaver_ - robot_->getHitTime(limb, 0, song_->getVelNextHit(limb));
      robot_->rest(limb, 0, true);
    }
  }
}

template <byte NB_HIT_JOINTS, byte NB_POS_JOINTS, byte BITS_FOR_POS>
void RoboController<NB_HIT_JOINTS, NB_POS_JOINTS, BITS_FOR_POS>::setInitialTime(unsigned long initialTime) {
  timeNextSemiquaver_ = initialTime;
}

template <byte NB_HIT_JOINTS, byte NB_POS_JOINTS, byte BITS_FOR_POS>
void RoboController<NB_HIT_JOINTS, NB_POS_JOINTS, BITS_FOR_POS>::goToTime(unsigned long currTime, bool printOutput) {
  for (unsigned int limb = 0; limb < NB_HIT_JOINTS; limb++) {
    if (currTime >= timeNextHitInstruction_[limb]) {
      manageHitInstruction(limb, currTime);
    }
    if (isTimeToChangePos(limb, currTime)) {
      managePosInstruction(limb);
    }
  }

  while (currTime > timeNextSemiquaver_) {
    timeNextSemiquaver_ += timePerSemiquaver_;
    song_->goToNextSemiquaver();
    if (printOutput_) {
      Serial.print("Going to next semiquaver at time: ");
      Serial.print(currTime);
      Serial.println(". Semiquavers to next hit: ");
      for (unsigned int limb = 0; limb < NB_HIT_JOINTS; limb++) {
        Serial.print("limb ");
        Serial.print(limb);
        Serial.print(": ");
        Serial.print(song_->getSemiquaversToNextHit(limb));
        Serial.print(". Time next instruction: ");
        Serial.println(timeNextHitInstruction_[limb]);
      }
    }
  }
}

template <byte NB_HIT_JOINTS, byte NB_POS_JOINTS, byte BITS_FOR_POS>
void RoboController<NB_HIT_JOINTS, NB_POS_JOINTS, BITS_FOR_POS>::manageHitInstruction(byte limb, unsigned long currTime) {
  byte currentPosition = limb < NB_POS_JOINTS ? nextPos_[limb] : 0;

  if (nextInstruction_[limb] == HIT) {
    if (simulation_) {
      Serial.println("");
      Serial.print(robot_->getPosName(limb, currentPosition));
      Serial.print(" at time ");
      Serial.print(timeNextHitInstruction_[limb]);
      Serial.print(", pos: ");
      Serial.print(currentPosition);
      Serial.print(", hit angle: ");
      Serial.println(robot_->getHitAngle(limb, currentPosition, song_->getVelNextHit(limb)));
      Serial.println("");
    }
    robot_->hit(limb, currentPosition, song_->getVelNextHit(limb), simulation_);

    timeNextHitInstruction_[limb] += robot_->getHitTime(limb, currentPosition, song_->getVelNextHit(limb));
    nextInstruction_[limb] = REST;
    song_->computeNextHit(limb, printOutput_);
    if (printOutput_) {
      Serial.print("Computed next hit. Semiquavers to next hit: ");
      Serial.println(song_->getSemiquaversToNextHit(limb));
    }
  } else if (nextInstruction_[limb] == REST) {
    if (limb < NB_POS_JOINTS) {
      // We check if we need to move
      nextPos_[limb] = song_->getPosNextHit(limb);

      if (currentPosition != nextPos_[limb]) {
        moveLimb_[limb] = true;
        timeNextPosInstruction_[limb] = currTime + abs(robot_->getHitAngle(limb, currentPosition, song_->getVelNextHit(limb)) - robot_->getRestAngle(limb, nextPos_[limb])) / (POS_SECURITY_FACTOR*robot_->getServoSpeed());
        currentPosition = nextPos_[limb];
      }
      robot_->rest(limb, nextPos_[limb]);
    }
    else{
      robot_->rest(limb);
    }

    timeNextHitInstruction_[limb] = timeNextSemiquaver_ + song_->getSemiquaversToNextHit(limb) * timePerSemiquaver_ - robot_->getHitTime(limb, currentPosition, song_->getVelNextHit(limb));
    nextInstruction_[limb] = HIT;
    // We inmmediately go the the rest state of the next posiion
    
  }
}

template <byte NB_HIT_JOINTS, byte NB_POS_JOINTS, byte BITS_FOR_POS>
void RoboController<NB_HIT_JOINTS, NB_POS_JOINTS, BITS_FOR_POS>::managePosInstruction(byte limb) {
  robot_->goToPos(limb, nextPos_[limb]);
  moveLimb_[limb] = false;
}

template <byte NB_HIT_JOINTS, byte NB_POS_JOINTS, byte BITS_FOR_POS>
bool RoboController<NB_HIT_JOINTS, NB_POS_JOINTS, BITS_FOR_POS>::isTimeToChangePos(byte limb, unsigned long ellapsedTime) {
  return (limb < NB_POS_JOINTS && moveLimb_[limb] && ellapsedTime >= timeNextPosInstruction_[limb]);
}

template <byte NB_HIT_JOINTS, byte NB_POS_JOINTS, byte BITS_FOR_POS>
void RoboController<NB_HIT_JOINTS, NB_POS_JOINTS, BITS_FOR_POS>::setBpm(unsigned short bpm) {
  bpm_ = bpm;
  unsigned long timeQuarter = int(60000.0 / bpm_);  // us per quarter note
  timePerSemiquaver_ = int(timeQuarter / 4.0);      // us per semiquaver note

  // We update the hit instructions
  for (unsigned int limb = 0; limb < NB_HIT_JOINTS; limb++) {
    if (nextInstruction_[limb] == HIT) {
      timeNextHitInstruction_[limb] = timeNextSemiquaver_ + song_->getSemiquaversToNextHit(limb) * timePerSemiquaver_ - robot_->getHitTime(limb, nextPos_[limb], song_->getVelNextHit(limb));
    }
  }
}

#endif
