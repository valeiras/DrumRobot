#include <musician_robot.h>

#ifndef Drum_robot_h
#define Drum_robot_h

#include "drum_robot_config.h"

struct posParamsDrum {
  byte hitAngle, restAngle, posAngle;
  String posName;  // Name of the position, for debugging purposes
};

class DrumRobot : public MusicianRobot<NB_HIT_JOINTS_DRUM, NB_POS_JOINTS_DRUM> {
public:
  DrumRobot();

  byte getHitAngle(byte limb, byte pos, byte velocity);
  byte getRestAngle(byte limb, byte pos);
  byte getPosAngle(byte limb, byte pos);
  unsigned int getHitTime(byte limb, byte pos, byte velocity);
  String getPosName(byte limb, byte pos);

  void setLimbParams(signed char directions[NB_HIT_JOINTS_DRUM],
                     byte anglesLeftArm[NB_POS_LEFT_ARM][3], String namesLeftArm[NB_POS_LEFT_ARM],
                     byte anglesRightArm[NB_POS_RIGHT_ARM][3], String namesRightArm[NB_POS_RIGHT_ARM],
                     byte anglesRightLeg[NB_POS_RIGHT_LEG][3], String namesRightLeg[NB_POS_RIGHT_LEG]);

  void setWServo(float wServo);

private:
  void setLimbParams();

  struct posParamsDrum paramsLeftArm_[NB_POS_LEFT_ARM], paramsRightArm_[NB_POS_RIGHT_ARM], paramsRightLeg_[NB_POS_RIGHT_LEG];
  posParamsDrum *posParameters_[NB_HIT_JOINTS_DRUM] = { paramsLeftArm_, paramsRightArm_, paramsRightLeg_ };
};

#endif
