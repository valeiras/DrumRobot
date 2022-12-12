#include "drum_robot.h"

DrumRobot::DrumRobot() {
  // We initialize the default parameters
  setupLimbParams();
}

void DrumRobot::hit(byte limb, byte pos, byte velocity, bool printOutput) {
  hitServos_[limb].write(getHitAngle(limb, pos, velocity));
}

void DrumRobot::rest(byte limb, byte pos) {
  hitServos_[limb].write(getRestAngle(limb, pos));
}

void DrumRobot::goToPos(byte limb, byte pos) {
  posServos_[limb].write(getPosAngle(limb, pos));
}

void DrumRobot::goToPosAngle(byte limb, byte posAngle) {
  posServos_[limb].write(posAngle);
}

void DrumRobot::goToHitAngle(byte limb, byte hitAngle) {
  hitServos_[limb].write(hitAngle);
}

void DrumRobot::attachServos(byte bdHitPin, byte rightHitPin, byte leftHitPin, byte rightPosPin, byte leftPosPin) {
  hitServos_[LEFT_ARM].attach(leftHitPin);
  hitServos_[RIGHT_ARM].attach(rightHitPin);
  hitServos_[RIGHT_LEG].attach(bdHitPin);

  posServos_[LEFT_ARM].attach(leftPosPin);
  posServos_[RIGHT_ARM].attach(rightPosPin);
}

// We use the default values defined in robot_config.h
void DrumRobot::setupLimbParams() {
  setupLimbParams(_wServo, _dirRightLeg, _dirLeftArm, _dirRightArm,
                  _hitAngle_BD, _restAngle_BD, _posAngle_BD,
                  _hitAngleSticksLeft, _restAngleSticksLeft, _posAngleSticksLeft,
                  _hitAngleHH, _restAngleHH, _posAngleHH,
                  _hitAngleSnLeft, _restAngleSnLeft, _posAngleSnLeft,
                  _hitAngleSticksRight, _restAngleSticksRight, _posAngleSticksRight,
                  _hitAngleSnRight, _restAngleSnRight, _posAngleSnRight,
                  _hitAngleCrash, _restAngleCrash, _posAngleCrash);

}

void DrumRobot::setupLimbParams(float wServo, signed char dirRightLeg, signed char dirLeftArm, signed char dirRightArm,
                                byte hitAngleBD, byte restAngleBD, byte posAngleBD,
                                byte hitAngleSticksLeft, byte restAngleSticksLeft, byte posAngleSticksLeft,
                                byte hitAngleHH, byte restAngleHH, byte posAngleHH,
                                byte hitAngleSNLeft, byte restAngleSNLeft, byte posAngleSNLeft,
                                byte hitAngleSticksRight, byte restAngleSticksRight, byte posAngleSticksRight,
                                byte hitAngleSNRight, byte restAngleSNRight, byte posAngleSNRight,
                                byte hitAngleCrash, byte restAngleCrash, byte posAngleCrash) {

  wServo_ = wServo;

  hitDirection_[RIGHT_LEG] = dirRightLeg;
  hitDirection_[LEFT_ARM] = dirLeftArm;
  hitDirection_[RIGHT_ARM] = dirRightArm;

  posParameters_[RIGHT_LEG][BDRU] = {hitAngleBD, restAngleBD, posAngleBD, "BD"};

  posParameters_[LEFT_ARM][STCK] = {hitAngleSticksLeft, restAngleSticksLeft, posAngleSticksLeft, "Sticks Left"};
  posParameters_[LEFT_ARM][HHAT] = {hitAngleHH, restAngleHH, posAngleHH, "HH"};
  posParameters_[LEFT_ARM][SNLT] = {hitAngleSNLeft, restAngleSNLeft, posAngleSNLeft, "SN Left"};

  posParameters_[RIGHT_ARM][STCK] = {hitAngleSticksRight, restAngleSticksRight, posAngleSticksRight, "Sticks Right"};
  posParameters_[RIGHT_ARM][SNRG] = {hitAngleSNRight, restAngleSNRight, posAngleSNRight, "SN Right"};
  posParameters_[RIGHT_ARM][CRSH] = {hitAngleCrash, restAngleCrash, posAngleCrash, "Crash"};

  nbPos_[RIGHT_LEG] = _nbPosRightLeg;
  nbPos_[LEFT_ARM] = _nbPosLeftArm;
  nbPos_[RIGHT_ARM] = _nbPosRightArm;
}


byte DrumRobot::getHitAngle(byte limb, byte pos, byte velocity) {
  if (pos < nbPos_[limb]) {
    return posParameters_[limb][pos].hitAngle + hitDirection_[limb] * velocity * VEL_MULTIPLIER;
  }
  else {
    return 255;
  }
}

byte DrumRobot::getRestAngle(byte limb, byte pos) {
  if (pos < nbPos_[limb]) {
    return posParameters_[limb][pos].restAngle;
  }
  else {
    return 255;
  }
}

byte DrumRobot::getPosAngle(byte limb, byte pos) {
  if (pos < nbPos_[limb]) {
    return posParameters_[limb][pos].posAngle;
  }
  else {
    return 255;
  }
}


unsigned int DrumRobot::getHitTime(byte limb, byte pos, byte velocity, bool printOutput) {
  if (pos < nbPos_[limb]) {
    float result = abs(posParameters_[limb][pos].hitAngle + hitDirection_[limb] * velocity * VEL_MULTIPLIER - posParameters_[limb][pos].restAngle) / wServo_;
    return round(result);
  }
  else {
    return 0;
  }
}

float DrumRobot::getServoSpeed() {
  return wServo_;
}

String DrumRobot::getPosName(byte limb, byte pos) {
  if (pos < nbPos_[limb]) {
    return posParameters_[limb][pos].posName;
  }
  else {
    return "Error";
  }
}
