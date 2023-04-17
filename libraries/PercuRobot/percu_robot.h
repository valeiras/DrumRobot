#ifndef Percu_robot_h
#define Percu_robot_h

#include "Arduino.h"
#include "Servo.h"

#define VEL_MULTIPLIER 1

template <int NB_HIT_JOINTS, int NB_POS_JOINTS>
class PercuRobot {
 public:
  PercuRobot(byte hitPins[NB_HIT_JOINTS], byte posPins[NB_POS_JOINTS]);

  virtual void hit(byte limb, byte pos, byte velocity, bool printOutput = 0);
  virtual void rest(byte limb, byte pos = 0, bool printOutput = 0);
  virtual void goToPos(byte limb, byte pos);

  void goToPosAngle(byte limb, byte posAngle);
  void goToHitAngle(byte limb, byte hitAngle);

  virtual byte getHitAngle(byte limb, byte pos, byte velocity) = 0;
  virtual byte getRestAngle(byte limb, byte pos) = 0;
  virtual byte getPosAngle(byte limb, byte pos) = 0;
  virtual byte getInactiveAngle(byte limb);
  virtual unsigned int getHitTime(byte limb, byte pos, byte velocity, bool printOutput = 0) = 0;
  virtual String getPosName(byte limb, byte pos) = 0;

  void setServoSpeed(float wServo);
  float getServoSpeed();

  void activateLimb(byte limb);
  void deactivateLimb(byte limb);

 protected:
  virtual void setLimbParams() = 0;
  void attachServos(byte hitPins[NB_HIT_JOINTS], byte posPins[NB_POS_JOINTS], bool printOutput = 0);

  signed char hitDirection_[NB_HIT_JOINTS];
  byte nbPos_[NB_HIT_JOINTS];
  Servo posServos_[NB_POS_JOINTS];
  bool isLimbActive_[NB_HIT_JOINTS];
  byte inactiveAngle_[NB_HIT_JOINTS];

  // rotational speed degrees per ms
  float wServo_;

 private:
  Servo hitServos_[NB_HIT_JOINTS];
};

template <int NB_HIT_JOINTS, int NB_POS_JOINTS>
PercuRobot<NB_HIT_JOINTS, NB_POS_JOINTS>::PercuRobot(byte hitPins[NB_HIT_JOINTS], byte posPins[NB_POS_JOINTS]) {
  attachServos(hitPins, posPins);
  for (unsigned int ii = 0; ii < NB_HIT_JOINTS; ii++) {
    isLimbActive_[ii] = true;
  }
}

template <int NB_HIT_JOINTS, int NB_POS_JOINTS>
void PercuRobot<NB_HIT_JOINTS, NB_POS_JOINTS>::hit(byte limb, byte pos, byte velocity, bool printOutput) {
  if (limb < NB_HIT_JOINTS && isLimbActive_[limb]) {
    hitServos_[limb].write(getHitAngle(limb, pos, velocity));
  }
}

template <int NB_HIT_JOINTS, int NB_POS_JOINTS>
void PercuRobot<NB_HIT_JOINTS, NB_POS_JOINTS>::rest(byte limb, byte pos, bool printOutput) {
  if (limb < NB_HIT_JOINTS && isLimbActive_[limb]) {
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
  if (limb < NB_HIT_JOINTS && isLimbActive_[limb]) {
    hitServos_[limb].write(hitAngle);
  }
}

template <int NB_HIT_JOINTS, int NB_POS_JOINTS>
byte PercuRobot<NB_HIT_JOINTS, NB_POS_JOINTS>::getInactiveAngle(byte limb) {
  if (limb < NB_HIT_JOINTS) {
    return inactiveAngle_[limb];
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

template <int NB_HIT_JOINTS, int NB_POS_JOINTS>
void PercuRobot<NB_HIT_JOINTS, NB_POS_JOINTS>::activateLimb(byte limb) {
  if (limb < NB_HIT_JOINTS) {
    isLimbActive_[limb] = true;
  }
}

template <int NB_HIT_JOINTS, int NB_POS_JOINTS>
void PercuRobot<NB_HIT_JOINTS, NB_POS_JOINTS>::deactivateLimb(byte limb) {
  if (limb < NB_HIT_JOINTS) {
    isLimbActive_[limb] = false;
    hitServos_[limb].write(getInactiveAngle(limb));
  }
}

#endif
