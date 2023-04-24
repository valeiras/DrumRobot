#ifndef Percu_robot_h
#define Percu_robot_h

#include "Arduino.h"
#include "Servo.h"

#define VEL_MULTIPLIER 1

template <int NB_HIT_JOINTS, int NB_POS_JOINTS>
class PercuRobot {
 public:
  PercuRobot();
  PercuRobot(byte hitPins[NB_HIT_JOINTS]);
  PercuRobot(byte hitPins[NB_HIT_JOINTS], byte posPins[NB_POS_JOINTS]);

  virtual void hit(byte limb, byte pos, byte velocity, bool hasOutput = 0);
  virtual void rest(byte limb, byte pos = 0, bool hasOutput = 0);
  virtual void goToPos(byte limb, byte pos);

  void goToPosAngle(byte limb, byte posAngle);
  void goToHitAngle(byte limb, byte hitAngle);

  virtual void processNoteOnMessage(byte noteIdx);
  virtual void processNoteOffMessage(byte noteIdx);
  virtual void processVibratoAmpChangeMessage(byte vibratoAmp);

  virtual void stop();

  virtual byte getHitAngle(byte limb, byte pos, byte velocity);
  virtual byte getRestAngle(byte limb, byte pos);
  virtual byte getPosAngle(byte limb, byte pos);
  virtual unsigned int getHitTime(byte limb, byte pos, byte velocity, bool hasOutput = 0);
  virtual String getPosName(byte limb, byte pos);
  virtual byte getInactiveAngle(byte limb);

  void setServoSpeed(float wServo);
  float getServoSpeed();

  void activateLimb(byte limb);
  void deactivateLimb(byte limb);

 protected:
  virtual void setLimbParams() = 0;
  void attachServos(byte hitPins[NB_HIT_JOINTS], bool hasOutput = 0);
  void attachServos(byte hitPins[NB_HIT_JOINTS], byte posPins[NB_POS_JOINTS], bool hasOutput = 0);

  signed char hitDirection_[NB_HIT_JOINTS];
  byte nbPos_[NB_HIT_JOINTS];
  Servo hitServos_[NB_HIT_JOINTS], posServos_[NB_POS_JOINTS];
  bool isLimbActive_[NB_HIT_JOINTS];
  byte inactiveAngle_[NB_HIT_JOINTS];

  // rotational speed degrees per ms
  float wServo_;

 private:
};

template <int NB_HIT_JOINTS, int NB_POS_JOINTS>
PercuRobot<NB_HIT_JOINTS, NB_POS_JOINTS>::PercuRobot() {
}

template <int NB_HIT_JOINTS, int NB_POS_JOINTS>
PercuRobot<NB_HIT_JOINTS, NB_POS_JOINTS>::PercuRobot(byte hitPins[NB_HIT_JOINTS]) {
  attachServos(hitPins);
}

template <int NB_HIT_JOINTS, int NB_POS_JOINTS>
PercuRobot<NB_HIT_JOINTS, NB_POS_JOINTS>::PercuRobot(byte hitPins[NB_HIT_JOINTS], byte posPins[NB_POS_JOINTS]) {
  attachServos(hitPins, posPins);
}

template <int NB_HIT_JOINTS, int NB_POS_JOINTS>
void PercuRobot<NB_HIT_JOINTS, NB_POS_JOINTS>::hit(byte limb, byte pos, byte velocity, bool hasOutput) {
  if (limb < NB_HIT_JOINTS && isLimbActive_[limb]) {
    hitServos_[limb].write(getHitAngle(limb, pos, velocity));
  }
}

template <int NB_HIT_JOINTS, int NB_POS_JOINTS>
void PercuRobot<NB_HIT_JOINTS, NB_POS_JOINTS>::rest(byte limb, byte pos, bool hasOutput) {
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
void PercuRobot<NB_HIT_JOINTS, NB_POS_JOINTS>::processNoteOnMessage(byte noteIdx) {
}

template <int NB_HIT_JOINTS, int NB_POS_JOINTS>
void PercuRobot<NB_HIT_JOINTS, NB_POS_JOINTS>::processNoteOffMessage(byte noteIdx) {
}

template <int NB_HIT_JOINTS, int NB_POS_JOINTS>
void PercuRobot<NB_HIT_JOINTS, NB_POS_JOINTS>::processVibratoAmpChangeMessage(byte vibratoAmp) {
}

template <int NB_HIT_JOINTS, int NB_POS_JOINTS>
void PercuRobot<NB_HIT_JOINTS, NB_POS_JOINTS>::stop() {
  for (unsigned int limb = 0; limb < NB_HIT_JOINTS; limb++) {
    rest(limb);
  }
}

template <int NB_HIT_JOINTS, int NB_POS_JOINTS>
byte PercuRobot<NB_HIT_JOINTS, NB_POS_JOINTS>::getHitAngle(byte limb, byte pos, byte velocity) {
  return 0;
}

template <int NB_HIT_JOINTS, int NB_POS_JOINTS>
byte PercuRobot<NB_HIT_JOINTS, NB_POS_JOINTS>::getRestAngle(byte limb, byte pos) {
  return 0;
}
template <int NB_HIT_JOINTS, int NB_POS_JOINTS>
byte PercuRobot<NB_HIT_JOINTS, NB_POS_JOINTS>::getPosAngle(byte limb, byte pos) {
  return 0;
}

template <int NB_HIT_JOINTS, int NB_POS_JOINTS>
unsigned int PercuRobot<NB_HIT_JOINTS, NB_POS_JOINTS>::getHitTime(byte limb, byte pos, byte velocity, bool hasOutput = 0) {
  return 0;
}

template <int NB_HIT_JOINTS, int NB_POS_JOINTS>
String PercuRobot<NB_HIT_JOINTS, NB_POS_JOINTS>::getPosName(byte limb, byte pos) {
  return "";
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
void PercuRobot<NB_HIT_JOINTS, NB_POS_JOINTS>::attachServos(byte hitPins[NB_HIT_JOINTS], bool hasOutput) {
  for (unsigned int ii = 0; ii < NB_HIT_JOINTS; ii++) {
    hitServos_[ii].attach(hitPins[ii]);
    isLimbActive_[ii] = true;
  }
}

template <int NB_HIT_JOINTS, int NB_POS_JOINTS>
void PercuRobot<NB_HIT_JOINTS, NB_POS_JOINTS>::attachServos(byte hitPins[NB_HIT_JOINTS], byte posPins[NB_POS_JOINTS], bool hasOutput) {
  attachServos(hitPins);
  for (unsigned int ii = 0; ii < NB_POS_JOINTS; ii++) {
    posServos_[ii].attach(posPins[ii]);
  }
}

template <int NB_HIT_JOINTS, int NB_POS_JOINTS>
void PercuRobot<NB_HIT_JOINTS, NB_POS_JOINTS>::activateLimb(byte limb) {
  if (limb < NB_HIT_JOINTS) {
    isLimbActive_[limb] = true;
    rest(limb);
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
