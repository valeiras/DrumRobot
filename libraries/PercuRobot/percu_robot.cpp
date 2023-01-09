#include "percu_robot.h"

template <int NB_HIT_JOINTS, int NB_POS_JOINTS>
PercuRobot<NB_HIT_JOINTS, NB_POS_JOINTS>::PercuRobot() {
}

template <int NB_HIT_JOINTS, int NB_POS_JOINTS>
void PercuRobot<NB_HIT_JOINTS, NB_POS_JOINTS>::hit(byte limb, byte pos, byte velocity, bool printOutput) {
  if (printOutput) {
    Serial.print("Hitting limb: ");
    Serial.print(limb);
    Serial.print(", with angle: ");
    Serial.println(getHitAngle(limb, pos, velocity));
  }

  if (limb < NB_HIT_JOINTS) {
    hitServos_[limb].write(getHitAngle(limb, pos, velocity));
  }
}

template <int NB_HIT_JOINTS, int NB_POS_JOINTS>
void PercuRobot<NB_HIT_JOINTS, NB_POS_JOINTS>::rest(byte limb, byte pos, bool printOutput) {
  if (limb < NB_HIT_JOINTS) {
    hitServos_[limb].write(getRestAngle(limb, pos));
  }
  if (printOutput) {
    Serial.print("Limb ");
    Serial.print(limb);
    Serial.print(" going to rest angle: ");
    Serial.println(getRestAngle(limb, pos));
    Serial.print("pos = ");
    Serial.println(pos);
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
void PercuRobot<NB_HIT_JOINTS, NB_POS_JOINTS>::attachServos(byte hitPins[NB_HIT_JOINTS], byte posPins[NB_POS_JOINTS]) {
  for (unsigned int ii = 0; ii < NB_HIT_JOINTS; ii++) {
    hitServos_[ii].attach(hitPins[ii]);
  }
  for (unsigned int ii = 0; ii < NB_POS_JOINTS; ii++) {
    posServos_[ii].attach(posPins[ii]);
  }
}

// Drum Robot
template class PercuRobot<3, 2>;

// Glocken Robot:
template class PercuRobot<2, 2>;