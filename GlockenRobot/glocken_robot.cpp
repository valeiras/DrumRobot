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
  byte posAnglesLeft[NB_POS_LA_GL] = { _posAngleC00L, _posAngleCS0L, _posAngleD00L, _posAngleDS0L,
                                       _posAngleE00L, _posAngleF00L, _posAngleFS0L, _posAngleG00L };

  byte posAnglesRight[NB_POS_RA_GL] = { _posAngleG00R, _posAngleGS0R, _posAngleA00R, _posAngleAS0R,
                                        _posAngleB00R, _posAngleC01R, _posAngleCS1R, _posAngleD01R };

  byte posAnglesHead[NB_POS_HD_GL] = { _posAngleHdL, _posAngleHdC, _posAngleHdR };

  String posNamesLeft[NB_POS_LA_GL] = { "C00", "CS0", "D00", "DS0", "E00", "F00", "FS0", "G00" };
  String posNamesRight[NB_POS_RA_GL] = { "G00", "GS0", "AS0", "B00", "C01", "CS1", "D01", "DS1" };
  String posNamesHead[NB_POS_RA_GL] = { "Left", "Center", "Right" };

  setLimbParams(_dirLAGl, _dirRAGl, _dirHdGl,
                _hitAngleLAGl, _hitAngleRAGl, _hitAngleHdGl,
                _restAngleLAGl, _restAngleRAGl, _restAngleHdGl, posAnglesLeft, posAnglesRight, posAnglesHead,
                posNamesLeft, posNamesRight, posNamesHead);
}

void GlockenRobot::setLimbParams(signed char directionLeft, signed char directionRight, signed char directionHead,
                                 byte hitAngleLeft, byte hitAngleRight, byte hitAngleHead,
                                 byte restAngleLeft, byte restAngleRight, byte restAngleHead,
                                 byte posAnglesLeft[NB_POS_LA_GL], byte posAnglesRight[NB_POS_RA_GL], byte posAnglesHead[NB_POS_HD_GL],
                                 String posNamesLeft[NB_POS_LA_GL], String posNamesRight[NB_POS_RA_GL], String posNamesHead[NB_POS_HD_GL]) {

  hitDirection_[LEFT_ARM_GL] = directionLeft;
  hitDirection_[RIGHT_ARM_GL] = directionRight;
  hitDirection_[HEAD_GL] = directionHead;

  hitAngles_[LEFT_ARM_GL] = hitAngleLeft;
  hitAngles_[RIGHT_ARM_GL] = hitAngleRight;
  hitAngles_[HEAD_GL] = hitAngleHead;

  restAngles_[LEFT_ARM_GL] = restAngleLeft;
  restAngles_[RIGHT_ARM_GL] = restAngleRight;
  restAngles_[HEAD_GL] = restAngleHead;

  for (unsigned int ii = 0; ii < NB_POS_LA_GL; ii++) {
    posAnglesLeft_[ii] = posAnglesLeft[ii];
    posNamesLeft_[ii] = posNamesLeft[ii];
  }

  for (unsigned int ii = 0; ii < NB_POS_RA_GL; ii++) {
    posAnglesRight_[ii] = posAnglesRight[ii];
    posNamesRight_[ii] = posNamesRight[ii];
  }

  for (unsigned int ii = 0; ii < NB_POS_HD_GL; ii++) {
    posAnglesHead_[ii] = posAnglesHead[ii];
    posNamesHead_[ii] = posNamesHead[ii];
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

unsigned int GlockenRobot::getHitTime(byte limb, byte pos, byte velocity, bool printOutput) {
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
