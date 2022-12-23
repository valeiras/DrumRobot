#include "glocken_robot.h"

GlockenRobot::GlockenRobot() {
  // We initialize the default parameters
  setLimbParams();

  nbPos_[LEFT_ARM_GL] = NB_POS_LA_GL;
  nbPos_[RIGHT_ARM_GL] = NB_POS_RA_GL;

  setServoSpeed(_wServoGl);
}

// We use the default values defined in robot_config.h
void GlockenRobot::setLimbParams() {
  byte posAnglesLeft[NB_POS_LA_GL] = { _posAngleC00, _posAngleCS0, _posAngleD00, _posAngleDS0, _posAngleE00,
                                       _posAngleF00, _posAngleFS0, _posAngleG00, _posAngleGS0 };

  byte posAnglesRight[NB_POS_RA_GL] = { _posAngleA00, _posAngleAS0, _posAngleB00, _posAngleC01, _posAngleCS1,
                                        _posAngleD01, _posAngleDS1, _posAngleE01, _posAngleF01 };

  String posNamesLeft[NB_POS_LA_GL] = { "C00", "CS0", "D00", "DS0", "E00", "F00", "FS0", "G00", "GS0" };
  String posNamesRight[NB_POS_RA_GL] = { "A00", "AS0", "B00", "C01", "CS1", "D01", "DS1", "E01", "F01" };

  setLimbParams(_dirLAGl, _dirRAGl, _hitAngleLAGl, _hitAngleRAGl,
                _restAngleLAGl, _restAngleRAGl, posAnglesLeft, posAnglesRight,
                posNamesLeft, posNamesRight);
}

void GlockenRobot::setLimbParams(signed char directionLeft, signed char directionRight,
                                 byte hitAngleLeft, byte hitAngleRight,
                                 byte restAngleLeft, byte restAngleRight,
                                 byte posAnglesLeft[NB_POS_LA_GL], byte posAnglesRight[NB_POS_RA_GL],
                                 String posNamesLeft[NB_POS_LA_GL], String posNamesRight[NB_POS_RA_GL]) {

  hitDirection_[LEFT_ARM_GL] = directionLeft;
  hitDirection_[RIGHT_ARM_GL] = directionRight;

  hitAngles_[LEFT_ARM_GL] = hitAngleLeft;
  hitAngles_[RIGHT_ARM_GL] = hitAngleRight;
  restAngles_[LEFT_ARM_GL] = restAngleLeft;
  restAngles_[RIGHT_ARM_GL] = restAngleRight;

  for (unsigned int ii = 0; ii < NB_POS_LA_GL; ii++) {
    posAnglesLeft_[ii] = posAnglesLeft[ii];
    posNamesLeft_[ii] = posNamesLeft[ii];
  }

  for (unsigned int ii = 0; ii < NB_POS_RA_GL; ii++) {
    posAnglesRight_[ii] = posAnglesRight[ii];
    posNamesRight_[ii] = posNamesRight[ii];
  }
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
