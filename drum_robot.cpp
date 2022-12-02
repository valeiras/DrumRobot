#include "drum_robot.h"

DrumRobot::DrumRobot() {
  // We initialize the default parameters
  setupLimbParams();
}

void DrumRobot::hit(byte limb, byte pos) {
  switch (limb) {
    case RIGHT_LEG:
      hitServoRightLeg_.write(getHitAngle(RIGHT_LEG, pos));
      break;
    case LEFT_ARM:
      hitServoLeftArm_.write(getHitAngle(LEFT_ARM, pos));
      break;
    case RIGHT_ARM:
      hitServoRightArm_.write(getHitAngle(RIGHT_ARM, pos));
      break;
  }
}

void DrumRobot::rest(byte limb, byte pos) {
  switch (limb) {
    case RIGHT_LEG:
      hitServoRightLeg_.write(getRestAngle(RIGHT_LEG, pos));
      break;
    case LEFT_ARM:
      hitServoLeftArm_.write(getRestAngle(LEFT_ARM, pos));
      break;
    case RIGHT_ARM:
      hitServoRightArm_.write(getRestAngle(RIGHT_ARM, pos));
      break;
  }
}

void DrumRobot::goToPos(byte limb, byte pos) {
  switch (limb) {
    case LEFT_ARM:
      posServoLeftArm_.write(getPosAngle(LEFT_ARM, pos));
      break;
    case RIGHT_ARM:
      posServoRightArm_.write(getPosAngle(RIGHT_ARM, pos));
      break;
  }
}

void DrumRobot::goToPosAngle(byte limb, byte posAngle) {
  switch (limb) {
    case LEFT_ARM:
      posServoLeftArm_.write(posAngle);
      break;
    case RIGHT_ARM:
      posServoRightArm_.write(posAngle);
      break;
  }
}

void DrumRobot::goToHitAngle(byte limb, byte hitAngle) {
  switch (limb) {
    case RIGHT_LEG:
      hitServoRightLeg_.write(hitAngle);
      break;
    case LEFT_ARM:
      hitServoLeftArm_.write(hitAngle);
      break;
    case RIGHT_ARM:
      hitServoRightArm_.write(hitAngle);
      break;
  }
}

void DrumRobot::attachServos(byte bdHitPin, byte rightHitPin, byte leftHitPin, byte rightPosPin, byte leftPosPin) {
  hitServoRightLeg_.attach(bdHitPin);
  hitServoLeftArm_.attach(leftHitPin);
  hitServoRightArm_.attach(rightHitPin);
  posServoLeftArm_.attach(leftPosPin);
  posServoRightArm_.attach(rightPosPin);
}

// We use the default values defined in robot_config.h
void DrumRobot::setupLimbParams() {
  setupLimbParams(_wServo, _hitAngle_BD, _restAngle_BD, _posAngle_BD,
                  _hitAngleSticksLeft, _restAngleSticksLeft, _posAngleSticksLeft,
                  _hitAngleHH, _restAngleHH, _posAngleHH,
                  _hitAngleSnLeft, _restAngleSnLeft, _posAngleSnLeft,
                  _hitAngleSticksRight, _restAngleSticksRight, _posAngleSticksRight,
                  _hitAngleSnRight, _restAngleSnRight, _posAngleSnRight,
                  _hitAngleCrash, _restAngleCrash, _posAngleCrash);

}

void DrumRobot::setupLimbParams(float wServo, byte hitAngleBD, byte restAngleBD, byte posAngleBD,
                                byte hitAngleSticksLeft, byte restAngleSticksLeft, byte posAngleSticksLeft,
                                byte hitAngleHH, byte restAngleHH, byte posAngleHH,
                                byte hitAngleSNLeft, byte restAngleSNLeft, byte posAngleSNLeft,
                                byte hitAngleSticksRight, byte restAngleSticksRight, byte posAngleSticksRight,
                                byte hitAngleSNRight, byte restAngleSNRight, byte posAngleSNRight,
                                byte hitAngleCrash, byte restAngleCrash, byte posAngleCrash) {

  wServo_ = wServo;

  unsigned int hitTimeBD = abs(hitAngleBD - restAngleBD) / wServo_;
  paramsRightLeg_[0] = {hitAngleBD, restAngleBD, posAngleBD, hitTimeBD, "BD"};

  unsigned int hitTimeSticksLeft = abs(hitAngleSticksLeft - restAngleSticksLeft) / wServo;
  paramsLeftArm_[0] = {hitAngleSticksLeft, restAngleSticksLeft, posAngleSticksLeft, hitTimeSticksLeft, "Sticks Left"};

  unsigned int hitTimeHH = abs(hitAngleHH - restAngleHH) / wServo_;
  paramsLeftArm_[1] = {hitAngleHH, restAngleHH, posAngleHH, hitTimeHH, "HH"};

  unsigned int hitTimeSNLeft = abs(hitAngleSNLeft - restAngleSNLeft) / wServo_;
  paramsLeftArm_[2] = {hitAngleSNLeft, restAngleSNLeft, posAngleSNLeft, hitTimeSNLeft, "SN Left"};

  unsigned int hitTimeSticksRight = abs(hitAngleSticksRight - restAngleSticksRight) / wServo_;
  paramsRightArm_[0] = {hitAngleSticksRight, restAngleSticksRight, posAngleSticksRight, hitTimeSticksRight, "Sticks Right"};

  unsigned int hitTimeSNRight = abs(hitAngleSNRight - restAngleSNRight) / wServo_;
  paramsRightArm_[1] = {hitAngleSNRight, restAngleSNRight, posAngleSNRight, hitTimeSNRight, "SN Right"};

  unsigned int hitTimeCrash = abs(hitAngleCrash - restAngleCrash) / wServo_;
  paramsRightArm_[2] = {hitAngleCrash, restAngleCrash, posAngleCrash, hitTimeCrash, "Crash"};

}

byte DrumRobot::getHitAngle(byte limb, byte pos) {
  switch (limb) {
    case RIGHT_LEG:
      if (pos < _nbPosRightLeg) {
        return paramsRightLeg_[pos].hitAngle;
      }
      else {
        return 255;
      }
    case LEFT_ARM:
      if (pos < _nbPosLeftArm) {
        return paramsLeftArm_[pos].hitAngle;
      }
      else {
        return 255;
      }
    case RIGHT_ARM:
      if (pos < _nbPosRightArm) {
        return paramsRightArm_[pos].hitAngle;
      }
      else {
        return 255;
      }
  }
}

byte DrumRobot::getRestAngle(byte limb, byte pos) {
  switch (limb) {
    case RIGHT_LEG:
      if (pos < _nbPosRightLeg) {
        return paramsRightLeg_[pos].restAngle;
      }
      else {
        return 255;
      }
    case LEFT_ARM:
      if (pos < _nbPosLeftArm) {
        return paramsLeftArm_[pos].restAngle;
      }
      else {
        return 255;
      }
    case RIGHT_ARM:
      if (pos < _nbPosRightArm) {
        return paramsRightArm_[pos].restAngle;
      }
      else {
        return 255;
      }
  }
}

byte DrumRobot::getPosAngle(byte limb, byte pos) {
  switch (limb) {
    case RIGHT_LEG:
      if (pos < _nbPosRightLeg) {
        return paramsRightLeg_[pos].posAngle;
      }
      else {
        return 255;
      }
    case LEFT_ARM:
      if (pos < _nbPosLeftArm) {
        return paramsLeftArm_[pos].posAngle;
      }
      else {
        return 255;
      }
    case RIGHT_ARM:
      if (pos < _nbPosRightArm) {
        return paramsRightArm_[pos].posAngle;
      }
      else {
        return 255;
      }
  }
}


unsigned int DrumRobot::getHitTime(byte limb, byte pos) {
  switch (limb) {
    case RIGHT_LEG:
      if (pos < _nbPosRightLeg) {
        return paramsRightLeg_[pos].hitTime;
      }
      else {
        return 0;
      }
    case LEFT_ARM:
      if (pos < _nbPosLeftArm) {
        return paramsLeftArm_[pos].hitTime;
      }
      else {
        return 0;
      }
    case RIGHT_ARM:
      if (pos < _nbPosRightArm) {
        return paramsRightArm_[pos].hitTime;
      }
      else {
        return 0;
      }
  }
}

float DrumRobot::getServoSpeed() {
  return wServo_;
}

String DrumRobot::getPosName(byte limb, byte pos) {
//  Serial.print("Getting pos name. Limb: ");
//  Serial.print(limb);
//  Serial.print(", pos: ");
//  Serial.println(pos);
  switch (limb) {
    case RIGHT_LEG:
      if (pos < _nbPosRightLeg) {
//        Serial.print("Returning: ");
//        Serial.println(paramsRightLeg_[pos].posName);
        return paramsRightLeg_[pos].posName;
      }
      else {
        return "Error";
      }
    case LEFT_ARM:
      if (pos < _nbPosLeftArm) {
//        Serial.print("Returning: ");
//        Serial.println(paramsLeftArm_[pos].posName);
        return paramsLeftArm_[pos].posName;
      }
      else {
        return "Error";
      }
    case RIGHT_ARM:
      if (pos < _nbPosRightArm) {
//        Serial.print("Returning: ");
//        Serial.println(paramsRightArm_[pos].posName);
        return paramsRightArm_[pos].posName;
      }
      else {
        return "Error";
      }
  }
}
