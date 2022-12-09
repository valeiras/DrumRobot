#include "drum_robot.h"

DrumRobot::DrumRobot() {
  // We initialize the default parameters
  setupLimbParams();
}

void DrumRobot::hit(byte limb, byte pos, byte velocity, bool printOutput) {
  switch (limb) {
    case RIGHT_LEG:
      hitServoRightLeg_.write(getHitAngle(RIGHT_LEG, pos, velocity));
      break;
    case LEFT_ARM:
      hitServoLeftArm_.write(getHitAngle(LEFT_ARM, pos, velocity));
      break;
    case RIGHT_ARM:
      hitServoRightArm_.write(getHitAngle(RIGHT_ARM, pos, velocity));
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

  dirRightLeg_ = dirRightLeg;
  dirLeftArm_ = dirLeftArm;
  dirRightArm_ = dirRightArm;

  paramsRightLeg_[0] = {hitAngleBD, restAngleBD, posAngleBD, "BD"};

  paramsLeftArm_[0] = {hitAngleSticksLeft, restAngleSticksLeft, posAngleSticksLeft, "Sticks Left"};
  paramsLeftArm_[1] = {hitAngleHH, restAngleHH, posAngleHH, "HH"};
  paramsLeftArm_[2] = {hitAngleSNLeft, restAngleSNLeft, posAngleSNLeft, "SN Left"};

  paramsRightArm_[0] = {hitAngleSticksRight, restAngleSticksRight, posAngleSticksRight, "Sticks Right"};
  paramsRightArm_[1] = {hitAngleSNRight, restAngleSNRight, posAngleSNRight, "SN Right"};
  paramsRightArm_[2] = {hitAngleCrash, restAngleCrash, posAngleCrash, "Crash"};
}


byte DrumRobot::getHitAngle(byte limb, byte pos, byte velocity) {
  switch (limb) {
    case RIGHT_LEG:
      if (pos < _nbPosRightLeg) {
        //return paramsRightLeg_[pos].hitAngle;
        return paramsRightLeg_[pos].hitAngle + dirRightLeg_ * velocity * VEL_MULTIPLIER;
      }
      else {
        return 255;
      }
    case LEFT_ARM:
      if (pos < _nbPosLeftArm) {
        //return paramsLeftArm_[pos].hitAngle;
        return paramsLeftArm_[pos].hitAngle + dirLeftArm_ * velocity * VEL_MULTIPLIER;
      }
      else {
        return 255;
      }
    case RIGHT_ARM:
      if (pos < _nbPosRightArm) {
        //return paramsRightArm_[pos].hitAngle;
        return paramsRightArm_[pos].hitAngle + dirRightArm_ * velocity * VEL_MULTIPLIER;
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


unsigned int DrumRobot::getHitTime(byte limb, byte pos, byte velocity, bool printOutput) {
  switch (limb) {
    case RIGHT_LEG:
      if (pos < _nbPosRightLeg) {
        float result =   abs(paramsRightLeg_[pos].hitAngle + dirRightLeg_ * velocity * VEL_MULTIPLIER - paramsRightLeg_[pos].restAngle) / wServo_;
          return round(result);
        }
        else {
          return 0;
        }
      case LEFT_ARM:
        if (pos < _nbPosLeftArm) {
          float result = abs(paramsLeftArm_[pos].hitAngle + dirLeftArm_ * velocity * VEL_MULTIPLIER - paramsLeftArm_[pos].restAngle) / wServo_;
          return round(result);
        }
        else {
          return 0;
        }
      case RIGHT_ARM:
        if (pos < _nbPosRightArm) {
          float result = abs(paramsRightArm_[pos].hitAngle + dirRightArm_ * velocity * VEL_MULTIPLIER - paramsRightArm_[pos].restAngle) / wServo_;
          return round(result);
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
    switch (limb) {
      case RIGHT_LEG:
        if (pos < _nbPosRightLeg) {
          return paramsRightLeg_[pos].posName;
        }
        else {
          return "Error";
        }
      case LEFT_ARM:
        if (pos < _nbPosLeftArm) {
          return paramsLeftArm_[pos].posName;
        }
        else {
          return "Error";
        }
      case RIGHT_ARM:
        if (pos < _nbPosRightArm) {
          return paramsRightArm_[pos].posName;
        }
        else {
          return "Error";
        }
    }
  }
