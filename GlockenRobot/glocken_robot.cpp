#include "glocken_robot.h"

GlockenRobot::GlockenRobot() {
  // We initialize the default parameters
  setLimbParams();

  nbPos_[LEFT_ARM_GL] = NB_POS_LA_GL;
  nbPos_[RIGHT_ARM_GL] = NB_POS_RA_GL;

  setWServo(_wServo);
}

// We use the default values defined in robot_config.h
void GlockenRobot::setLimbParams() {
  signed char directions[NB_HIT_JOINTS_GL] = { _dirLA_GL, _dirRA_GL };
}

void GlockenRobot::setLimbParams(signed char directions[NB_HIT_JOINTS_GL]) {
}

void GlockenRobot::setWServo(float wServo) {
  wServo_ = wServo;
}

byte GlockenRobot::getHitAngle(byte limb, byte pos, byte velocity) {
  return hitAngles_[limb] + hitDirection_[limb] * velocity * VEL_MULTIPLIER;
}

byte GlockenRobot::getRestAngle(byte limb, byte pos) {
  return restAngles_[limb];
}

byte GlockenRobot::getPosAngle(byte limb, byte pos) {
  if (pos < nbPos_[limb]) {
    return posAngles_[limb][pos];
  } else {
    return 255;
  }
}

unsigned int GlockenRobot::getHitTime(byte limb, byte pos, byte velocity) {
  float result = abs(hitAngles_[limb] + hitDirection_[limb] * velocity * VEL_MULTIPLIER - restAngles_[limb]) / wServo_;
  return round(result);
}

String GlockenRobot::getPosName(byte limb, byte pos) {
  if (pos < nbPos_[limb]) {
    return posNames_[limb][pos];
  } else {
    return "Error";
  }
}
