#include "drum_robot.h"

DrumRobot::DrumRobot() {
  // We initialize the default parameters
  setLimbParams();

  nbPos_[LEFT_ARM] = NB_POS_LEFT_ARM;
  nbPos_[RIGHT_ARM] = NB_POS_RIGHT_ARM;
  nbPos_[RIGHT_LEG] = NB_POS_RIGHT_LEG;

  setWServo(_wServo);
}

// We use the default values defined in robot_config.h
void DrumRobot::setLimbParams() {
  signed char directions[NB_HIT_JOINTS_DRUM] = { _dirRightLeg, _dirLeftArm, _dirRightArm };

  byte anglesLeftArm[NB_POS_LEFT_ARM][3] = { { _hitAngleSticksLeft, _restAngleSticksLeft, _posAngleSticksLeft },
                                             { _hitAngleHH, _restAngleHH, _posAngleHH },
                                             { _hitAngleSnLeft, _restAngleSnLeft, _posAngleSnLeft } };
  String namesLeftArm[NB_POS_LEFT_ARM] = { "Sticks Left", "HH", "SN Left" };

  byte anglesRightArm[NB_POS_RIGHT_ARM][3] = { { _hitAngleSticksRight, _restAngleSticksRight, _posAngleSticksRight },
                                               { _hitAngleSnRight, _restAngleSnRight, _posAngleSnRight },
                                               { _hitAngleCrash, _restAngleCrash, _posAngleCrash } };
  String namesRightArm[NB_POS_RIGHT_ARM] = { "Sticks Right", "SN Right", "Crash" };

  byte anglesRightLeg[NB_POS_RIGHT_LEG][3] = { { _hitAngleBD, _restAngleBD, _posAngleBD } };
  String namesRightLeg[NB_POS_RIGHT_LEG] = { "BD" };


  setLimbParams(directions,
                anglesLeftArm, namesLeftArm,
                anglesRightArm, namesRightArm,
                anglesRightLeg, namesRightLeg);
}

void DrumRobot::setLimbParams(signed char directions[NB_HIT_JOINTS_DRUM],
                                byte anglesLeftArm[NB_POS_LEFT_ARM][3], String namesLeftArm[NB_POS_LEFT_ARM],
                                byte anglesRightArm[NB_POS_RIGHT_ARM][3], String namesRightArm[NB_POS_RIGHT_ARM],
                                byte anglesRightLeg[NB_POS_RIGHT_LEG][3], String namesRightLeg[NB_POS_RIGHT_LEG]) {

  for (unsigned int ii = 0; ii < NB_HIT_JOINTS_DRUM; ii++) {
    hitDirection_[ii] = directions[ii];
  }

  for (unsigned int ii = 0; ii < NB_POS_LEFT_ARM; ii++) {
    posParameters_[LEFT_ARM][ii] = { anglesLeftArm[ii][0], anglesLeftArm[ii][1], anglesLeftArm[ii][2], namesLeftArm[ii] };
  }

  for (unsigned int ii = 0; ii < NB_POS_RIGHT_ARM; ii++) {
    posParameters_[RIGHT_ARM][ii] = { anglesRightArm[ii][0], anglesRightArm[ii][1], anglesRightArm[ii][2], namesRightArm[ii] };
  }

  for (unsigned int ii = 0; ii < NB_POS_RIGHT_LEG; ii++) {
    posParameters_[RIGHT_LEG][ii] = { anglesRightLeg[ii][0], anglesRightLeg[ii][1], anglesRightLeg[ii][2], namesRightLeg[ii] };
  }
}

void DrumRobot::setWServo(float wServo){
  wServo_ = wServo;
}

byte DrumRobot::getHitAngle(byte limb, byte pos, byte velocity) {
  if (pos < nbPos_[limb]) {
    return posParameters_[limb][pos].hitAngle + hitDirection_[limb] * velocity * VEL_MULTIPLIER;
  } else {
    return 255;
  }
}

byte DrumRobot::getRestAngle(byte limb, byte pos) {
  if (pos < nbPos_[limb]) {
    return posParameters_[limb][pos].restAngle;
  } else {
    return 255;
  }
}

byte DrumRobot::getPosAngle(byte limb, byte pos) {
  if (pos < nbPos_[limb]) {
    return posParameters_[limb][pos].posAngle;
  } else {
    return 255;
  }
}

unsigned int DrumRobot::getHitTime(byte limb, byte pos, byte velocity) {
  if (pos < nbPos_[limb]) {
    float result = abs(posParameters_[limb][pos].hitAngle + hitDirection_[limb] * velocity * VEL_MULTIPLIER - posParameters_[limb][pos].restAngle) / wServo_;
    return round(result);
  } else {
    return 0;
  }
}

String DrumRobot::getPosName(byte limb, byte pos) {
  if (pos < nbPos_[limb]) {
    return posParameters_[limb][pos].posName;
  } else {
    return "Error";
  }
}
