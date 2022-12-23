#ifndef Robo_controller_h
#define Robo_controller_h

#include <Array.h>
#include <percu_robot.h>
#include <robo_song.h>

#include "Arduino.h"

template <byte NB_HIT_JOINTS, byte NB_POS_JOINTS, byte BITS_FOR_POS>
class RoboController {
 public:
  RoboController(PercuRobot<NB_HIT_JOINTS, NB_POS_JOINTS> *robot, RoboSong<NB_HIT_JOINTS, BITS_FOR_POS> *song,
                 bool simulation, bool printOutput);

  // This method should be called once all the parameters of the robot and the song have been set
  void initializeRobot();

  void manageHitInstruction(byte limb, unsigned long currTime);
  void managePosInstruction(byte limb);

  unsigned long getTimeNextHitInstruction(byte limb);
  bool isTimeToChangePos(byte limb, unsigned long ellapsedTime);

 private:
  PercuRobot<NB_HIT_JOINTS, NB_POS_JOINTS> *robot_;
  RoboSong<NB_HIT_JOINTS, BITS_FOR_POS> *song_;

  unsigned long timeNextHitInstruction_[NB_HIT_JOINTS], timeNextPosInstruction_[NB_POS_JOINTS];
  byte nextInstruction_[NB_HIT_JOINTS];
  bool moveLimb_[NB_POS_JOINTS];
  byte nextPos_[NB_POS_JOINTS];

  bool simulation_, printOutput_;
};

template <byte NB_HIT_JOINTS, byte NB_POS_JOINTS, byte BITS_FOR_POS>
RoboController<NB_HIT_JOINTS, NB_POS_JOINTS, BITS_FOR_POS>::RoboController(PercuRobot<NB_HIT_JOINTS, NB_POS_JOINTS> *robot,
                                                                           RoboSong<NB_HIT_JOINTS, BITS_FOR_POS> *song,
                                                                           bool simulation, bool printOutput) {
  robot_ = robot;
  song_ = song;

  simulation_ = simulation;
  printOutput_ = printOutput;
}

template <byte NB_HIT_JOINTS, byte NB_POS_JOINTS, byte BITS_FOR_POS>
void RoboController<NB_HIT_JOINTS, NB_POS_JOINTS, BITS_FOR_POS>::initializeRobot() {
  for (unsigned int limb = 0; limb < NB_POS_JOINTS; limb++) {
    timeNextPosInstruction_[limb] = 0;
    moveLimb_[limb] = false;
  }

  for (unsigned int limb = 0; limb < NB_HIT_JOINTS; limb++) {
    song_->computeNextHit(limb, printOutput_);
    nextInstruction_[limb] = HIT;

    if (limb < NB_POS_JOINTS) {
      nextPos_[limb] = song_->getPosNextHit(limb);
      timeNextHitInstruction_[limb] = song_->getTimeNextHit(limb) - robot_->getHitTime(limb, nextPos_[limb], song_->getVelNextHit(limb));
      robot_->rest(limb, nextPos_[limb]);
      robot_->goToPos(limb, nextPos_[limb]);
    } else {
      timeNextHitInstruction_[limb] = song_->getTimeNextHit(limb) - robot_->getHitTime(limb, 0, song_->getVelNextHit(limb));
      robot_->rest(limb);
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
      Serial.println(timeNextHitInstruction_[limb]);
    }
    robot_->hit(limb, currentPosition, song_->getVelNextHit(limb), printOutput_);

    if (printOutput_) {
      Serial.print("Hit time: ");
      Serial.println(robot_->getHitTime(limb, currentPosition, song_->getVelNextHit(limb)));
    }

    timeNextHitInstruction_[limb] += robot_->getHitTime(limb, currentPosition, song_->getVelNextHit(limb));
    nextInstruction_[limb] = REST;
  } else if (nextInstruction_[limb] == REST) {
    song_->computeNextHit(limb, printOutput_);

    if (limb < NB_POS_JOINTS) {
      // We check if we need to move
      nextPos_[limb] = song_->getPosNextHit(limb);

      if (currentPosition != nextPos_[limb]) {
        moveLimb_[limb] = true;
        timeNextPosInstruction_[limb] = currTime + abs(robot_->getHitAngle(limb, currentPosition, song_->getVelNextHit(limb)) - robot_->getRestAngle(limb, nextPos_[limb])) / (robot_->getServoSpeed());
        currentPosition = nextPos_[limb];
      }
    }

    timeNextHitInstruction_[limb] = song_->getTimeNextHit(limb) - robot_->getHitTime(limb, currentPosition, song_->getVelNextHit(limb));
    nextInstruction_[limb] = HIT;
    // We inmmediately go the the rest state of the next posiion
    robot_->rest(limb, nextPos_[limb]);
  }
}

template <byte NB_HIT_JOINTS, byte NB_POS_JOINTS, byte BITS_FOR_POS>
void RoboController<NB_HIT_JOINTS, NB_POS_JOINTS, BITS_FOR_POS>::managePosInstruction(byte limb) {
  robot_->goToPos(limb, nextPos_[limb]);
  moveLimb_[limb] = false;
}

template <byte NB_HIT_JOINTS, byte NB_POS_JOINTS, byte BITS_FOR_POS>
unsigned long RoboController<NB_HIT_JOINTS, NB_POS_JOINTS, BITS_FOR_POS>::getTimeNextHitInstruction(byte limb) {
  return timeNextHitInstruction_[limb];
}

template <byte NB_HIT_JOINTS, byte NB_POS_JOINTS, byte BITS_FOR_POS>
bool RoboController<NB_HIT_JOINTS, NB_POS_JOINTS, BITS_FOR_POS>::isTimeToChangePos(byte limb, unsigned long ellapsedTime) {
  return (limb < NB_POS_JOINTS && moveLimb_[limb] && ellapsedTime >= timeNextPosInstruction_[limb]);
}

#endif
