#include "glocken_robot_ld.h"

GlockenRobotLD::GlockenRobotLD(byte hitPins[NB_HIT_JOINTS_GL], byte posPins[NB_POS_JOINTS_GL])
  : PercuRobot(hitPins, posPins) {
  nbPos_[LEFT_ARM_GL] = NB_POS_LA_GL;
  nbPos_[RIGHT_ARM_GL] = NB_POS_RA_GL;

  // We initialize the default parameters
  setLimbParams();

  setServoSpeed(_wServoGl);
}

// We use the default values defined in robot_config.h
void GlockenRobotLD::setLimbParams() {
  byte posAngleLeft[NB_POS_LA_GL] = { _posAngleC00L, _posAngleCS0L, _posAngleD00L, _posAngleDS0L,
                                       _posAngleE00L, _posAngleF00L, _posAngleFS0L, _posAngleG00L };

  byte posAngleRight[NB_POS_RA_GL] = { _posAngleG00R, _posAngleGS0R, _posAngleA00R, _posAngleAS0R,
                                        _posAngleB00R, _posAngleC01R };

  byte posAngleHead[NB_POS_HD_GL] = { _posAngleHdL, _posAngleHdC, _posAngleHdR };

  String posNamesLeft[NB_POS_LA_GL] = { "C00", "CS0", "D00", "DS0", "E00", "F00", "FS0", "G00" };
  String posNamesRight[NB_POS_RA_GL] = { "G00", "GS0", "A00", "AS0", "B00", "C01"};
  String posNamesHead[NB_POS_RA_GL] = { "Left", "Center", "Right" };

  setLimbParams(_dirLAGl, _dirRAGl, _dirHdGl,
                _hitAngleLAGl, _hitAngleRAGl, _hitAngleHdGl,
                _restAngleLAGl, _restAngleRAGl, _restAngleHdGl, posAngleLeft, posAngleRight, posAngleHead,
                posNamesLeft, posNamesRight, posNamesHead,
                _inactiveAngleLAGL, _inactiveAngleRAGL, _inactiveAngleHdGL);
}

void GlockenRobotLD::setLimbParams(signed char directionLeft, signed char directionRight, signed char directionHead,
                                 byte hitAngleLeft, byte hitAngleRight, byte hitAngleHead,
                                 byte restAngleLeft, byte restAngleRight, byte restAngleHead,
                                 byte posAngleLeft[NB_POS_LA_GL], byte posAngleRight[NB_POS_RA_GL], byte posAngleHead[NB_POS_HD_GL],
                                 String posNamesLeft[NB_POS_LA_GL], String posNamesRight[NB_POS_RA_GL], String posNamesHead[NB_POS_HD_GL],
                                 byte inactiveAngleLA, byte inactiveAngleRA, byte inactiveAngleHd) {

  hitDirection_[LEFT_ARM_GL] = directionLeft;
  hitDirection_[RIGHT_ARM_GL] = directionRight;
  hitDirection_[HEAD_GL] = directionHead;

  hitAngle_[LEFT_ARM_GL] = hitAngleLeft;
  hitAngle_[RIGHT_ARM_GL] = hitAngleRight;
  hitAngle_[HEAD_GL] = hitAngleHead;

  restAngle_[LEFT_ARM_GL] = restAngleLeft;
  restAngle_[RIGHT_ARM_GL] = restAngleRight;
  restAngle_[HEAD_GL] = restAngleHead;

  inactiveAngle_[LEFT_ARM_GL] = inactiveAngleLA;
  inactiveAngle_[RIGHT_ARM_GL] = inactiveAngleRA;
  inactiveAngle_[HEAD_GL] = inactiveAngleHd;

  for (unsigned int ii = 0; ii < NB_POS_LA_GL; ii++) {
    posAngleLeft_[ii] = posAngleLeft[ii];
    posNamesLeft_[ii] = posNamesLeft[ii];
  }

  for (unsigned int ii = 0; ii < NB_POS_RA_GL; ii++) {
    posAngleRight_[ii] = posAngleRight[ii];
    posNamesRight_[ii] = posNamesRight[ii];
  }

  for (unsigned int ii = 0; ii < NB_POS_HD_GL; ii++) {
    posAngleHead_[ii] = posAngleHead[ii];
    posNamesHead_[ii] = posNamesHead[ii];
  }
}

byte GlockenRobotLD::getHitAngle(byte limb, byte pos, byte velocity) {
  return hitAngle_[limb] + hitDirection_[limb] * velocity * VEL_MULTIPLIER;
}

byte GlockenRobotLD::getRestAngle(byte limb, byte pos) {
  return restAngle_[limb];
}

byte GlockenRobotLD::getPosAngle(byte limb, byte pos) {
  if (pos < nbPos_[limb]) {
    return posAngle_[limb][pos];
  } else {
    return 255;
  }
}

unsigned int GlockenRobotLD::getHitTime(byte limb, byte pos, byte velocity, bool hasOutput) {
  float result = abs(hitAngle_[limb] + hitDirection_[limb] * velocity * VEL_MULTIPLIER - restAngle_[limb]) / wServo_;
  return round(result);
}

String GlockenRobotLD::getPosName(byte limb, byte pos) {
  if (pos < nbPos_[limb]) {
    return posNames_[limb][pos];
  } else {
    return "Error";
  }
}
