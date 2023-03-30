#include "music_box_percu_robot.h"

MusicBoxPercuRobot::MusicBoxPercuRobot(byte hitPins[NB_HIT_JOINTS_MB])
  : PercuRobot(hitPins, NULL) {

  // We initialize the default parameters
  setLimbParams();

  setServoSpeed(_wServoMB);
}

// We use the default values defined in robot_config.h
void MusicBoxPercuRobot::setLimbParams() {
  setLimbParams(_dirFootMB, _dirHeadMB,
                _hitAngleFootMB, _hitAngleHeadMB,
                _restAngleHeadMB, _restAngleHeadMB);
}

void MusicBoxPercuRobot::setLimbParams(signed char directionFoot, signed char directionHead,
                                       byte hitAngleFoot, byte hitAngleHead,
                                       byte restAngleFoot, byte restAngleHead) {

  hitDirection_[FOOT_MB] = directionFoot;
  hitDirection_[HEAD_MB] = directionHead;

  hitAngles_[FOOT_MB] = hitAngleFoot;
  hitAngles_[HEAD_MB] = hitAngleHead;
  restAngles_[FOOT_MB] = restAngleFoot;
  restAngles_[HEAD_MB] = restAngleHead;
}

byte MusicBoxPercuRobot::getHitAngle(byte limb, byte pos, byte velocity) {
  return hitAngles_[limb] + hitDirection_[limb] * velocity * VEL_MULTIPLIER;
}

byte MusicBoxPercuRobot::getRestAngle(byte limb, byte pos) {
  return restAngles_[limb];
}

byte MusicBoxPercuRobot::getPosAngle(byte limb, byte pos) {
  return 0;
}

unsigned int MusicBoxPercuRobot::getHitTime(byte limb, byte pos, byte velocity, bool printOutput) {
  float result = abs(hitAngles_[limb] + hitDirection_[limb] * velocity * VEL_MULTIPLIER - restAngles_[limb]) / wServo_;
  return round(result);
}

String MusicBoxPercuRobot::getPosName(byte limb, byte pos){
  return "";
}