#include "glocken_robot_gr.h"

GlockenRobotGR::GlockenRobotGR(byte hitPins[NB_HIT_JOINTS_GL], byte posPins[NB_POS_JOINTS_GL])
  : PercuRobot(hitPins, posPins) {
  nbPos_[LEFT_ARM_GL] = NB_POS_LA_GL;
  nbPos_[RIGHT_ARM_GL] = NB_POS_RA_GL;

  // We initialize the default parameters
  setLimbParams();

  setServoSpeed(_wServoGl);
}

// We use the default values defined in robot_config.h
void GlockenRobotGR::setLimbParams() {
  byte posAngleLeft[NB_POS_LA_GL] = { _posAngleC00, _posAngleCS0, _posAngleD00, _posAngleDS0, _posAngleE00,
                                      _posAngleF00, _posAngleFS0, _posAngleG00, _posAngleGS0, _posAngleA00 };

  byte posAngleRight[NB_POS_RA_GL] = { _posAngleAS0, _posAngleB00, _posAngleC01, _posAngleCS1,
                                       _posAngleD01, _posAngleDS1, _posAngleE01, _posAngleF01 };

  String posNamesLeft[NB_POS_LA_GL] = { "C00", "CS0", "D00", "DS0", "E00", "F00", "FS0", "G00", "GS0", "A00" };
  String posNamesRight[NB_POS_RA_GL] = { "AS0", "B00", "C01", "CS1", "D01", "DS1", "E01", "F01" };

  setLimbParams(_dirLAGl, _dirRAGl, _hitAngleLAGl, _hitAngleRAGl,
                _restAngleLAGl, _restAngleRAGl, posAngleLeft, posAngleRight,
                posNamesLeft, posNamesRight,
                _inactiveAngleLAGL, _inactiveAngleRAGL);
}

void GlockenRobotGR::setLimbParams(signed char directionLeft, signed char directionRight,
                                 byte hitAngleLeft, byte hitAngleRight,
                                 byte restAngleLeft, byte restAngleRight,
                                 byte posAngleLeft[NB_POS_LA_GL], byte posAngleRight[NB_POS_RA_GL],
                                 String posNamesLeft[NB_POS_LA_GL], String posNamesRight[NB_POS_RA_GL],
                                 byte inactiveAngleLA, byte inactiveAngleRA) {

  hitDirection_[LEFT_ARM_GL] = directionLeft;
  hitDirection_[RIGHT_ARM_GL] = directionRight;

  hitAngle_[LEFT_ARM_GL] = hitAngleLeft;
  hitAngle_[RIGHT_ARM_GL] = hitAngleRight;

  restAngle_[LEFT_ARM_GL] = restAngleLeft;
  restAngle_[RIGHT_ARM_GL] = restAngleRight;
  
  inactiveAngle_[LEFT_ARM_GL] = inactiveAngleLA;
  inactiveAngle_[RIGHT_ARM_GL] = inactiveAngleRA;

  for (unsigned int ii = 0; ii < NB_POS_LA_GL; ii++) {
    posAngleLeft_[ii] = posAngleLeft[ii];
    posNamesLeft_[ii] = posNamesLeft[ii];
  }

  for (unsigned int ii = 0; ii < NB_POS_RA_GL; ii++) {
    posAngleRight_[ii] = posAngleRight[ii];
    posNamesRight_[ii] = posNamesRight[ii];
  }
}

byte GlockenRobotGR::getHitAngle(byte limb, byte pos, byte velocity) {
  return hitAngle_[limb] + hitDirection_[limb] * velocity * VEL_MULTIPLIER;
}

byte GlockenRobotGR::getRestAngle(byte limb, byte pos) {
  return restAngle_[limb];
}

byte GlockenRobotGR::getPosAngle(byte limb, byte pos) {
  if (pos < nbPos_[limb]) {
    return posAngle_[limb][pos];
  } else {
    return 255;
  }
}

unsigned int GlockenRobotGR::getHitTime(byte limb, byte pos, byte velocity, bool printOutput) {
  float result = abs(hitAngle_[limb] + hitDirection_[limb] * velocity * VEL_MULTIPLIER - restAngle_[limb]) / wServo_;
  return round(result);
}

String GlockenRobotGR::getPosName(byte limb, byte pos) {
  if (pos < nbPos_[limb]) {
    return posNames_[limb][pos];
  } else {
    return "Error";
  }
}
