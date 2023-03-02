#ifndef Percu_robot_h
#define Percu_robot_h

#include "Servo.h"
#include "Arduino.h"

#define VEL_MULTIPLIER 1

template <int NB_HIT_JOINTS, int NB_POS_JOINTS>
class PercuRobot {
 public:
  PercuRobot();

  virtual void hit(byte limb, byte pos, byte velocity, bool printOutput = 0);
  virtual void rest(byte limb, byte pos = 0, bool printOutput = 0);
  virtual void goToPos(byte limb, byte pos);

  void goToPosAngle(byte limb, byte posAngle);
  void goToHitAngle(byte limb, byte hitAngle);

  virtual byte getHitAngle(byte limb, byte pos, byte velocity) = 0;
  virtual byte getRestAngle(byte limb, byte pos) = 0;
  virtual byte getPosAngle(byte limb, byte pos) = 0;
  virtual unsigned int getHitTime(byte limb, byte pos, byte velocity, bool printOutput = 0) = 0;
  virtual String getPosName(byte limb, byte pos) = 0;

  void setServoSpeed(float wServo);
  float getServoSpeed();

  void attachServos(byte hitPins[NB_HIT_JOINTS], byte posPins[NB_POS_JOINTS], bool printOutput = 0);

 protected:
  signed char hitDirection_[NB_HIT_JOINTS];
  byte nbPos_[NB_HIT_JOINTS];
  // rotational speed degrees per ms
  float wServo_;

 private:
  Servo hitServos_[NB_HIT_JOINTS];
  Servo posServos_[NB_POS_JOINTS];
};

template <int NB_HIT_JOINTS, int NB_POS_JOINTS>
PercuRobot<NB_HIT_JOINTS, NB_POS_JOINTS>::PercuRobot() {
}

template <int NB_HIT_JOINTS, int NB_POS_JOINTS>
void PercuRobot<NB_HIT_JOINTS, NB_POS_JOINTS>::hit(byte limb, byte pos, byte velocity, bool printOutput) {
  if (limb < NB_HIT_JOINTS) {
    hitServos_[limb].write(getHitAngle(limb, pos, velocity));
  }
}

template <int NB_HIT_JOINTS, int NB_POS_JOINTS>
void PercuRobot<NB_HIT_JOINTS, NB_POS_JOINTS>::rest(byte limb, byte pos, bool printOutput) {
  if (limb < NB_HIT_JOINTS) {
    hitServos_[limb].write(getRestAngle(limb, pos));
  }
}

template <int NB_HIT_JOINTS, int NB_POS_JOINTS>
void PercuRobot<NB_HIT_JOINTS, NB_POS_JOINTS>::goToPos(byte limb, byte pos) {
  if (limb < NB_POS_JOINTS) {
    posServos_[limb].write(getPosAngle(limb, pos));
  }
}

template <int NB_HIT_JOINTS, int NB_POS_JOINTS>
void PercuRobot<NB_HIT_JOINTS, NB_POS_JOINTS>::goToPosAngle(byte limb, byte posAngle) {
  if (limb < NB_POS_JOINTS) {
    posServos_[limb].write(posAngle);
  }
}

template <int NB_HIT_JOINTS, int NB_POS_JOINTS>
void PercuRobot<NB_HIT_JOINTS, NB_POS_JOINTS>::goToHitAngle(byte limb, byte hitAngle) {
  if (limb < NB_HIT_JOINTS) {
    hitServos_[limb].write(hitAngle);
  }
}

template <int NB_HIT_JOINTS, int NB_POS_JOINTS>
void PercuRobot<NB_HIT_JOINTS, NB_POS_JOINTS>::setServoSpeed(float wServo) {
  wServo_ = wServo;
}

template <int NB_HIT_JOINTS, int NB_POS_JOINTS>
float PercuRobot<NB_HIT_JOINTS, NB_POS_JOINTS>::getServoSpeed() {
  return wServo_;
}

template <int NB_HIT_JOINTS, int NB_POS_JOINTS>
void PercuRobot<NB_HIT_JOINTS, NB_POS_JOINTS>::attachServos(byte hitPins[NB_HIT_JOINTS], byte posPins[NB_POS_JOINTS], bool printOutput) {
  for (unsigned int ii = 0; ii < NB_HIT_JOINTS; ii++) {
    hitServos_[ii].attach(hitPins[ii]);
  }
  for (unsigned int ii = 0; ii < NB_POS_JOINTS; ii++) {
    posServos_[ii].attach(posPins[ii]);
  }
}

#endif
