#ifndef Drum_robot_gr_h
#define Drum_robot_gr_h

#include <percu_robot.h>
#include "drum_robot_config_gr.h"

#define ANGLES_PER_POSITION 3

struct posParamsDrum {
  byte hitAngle, restAngle, posAngle;
  String posName;  // Name of the position, for debugging purposes
};

class DrumRobotGR : public PercuRobot<NB_HIT_JOINTS_DR, NB_POS_JOINTS_DR>{
public:
  DrumRobotGR(byte hitPins[NB_HIT_JOINTS_DR], byte posPins[NB_POS_JOINTS_DR]);

  byte getHitAngle(byte limb, byte pos, byte velocity);
  byte getRestAngle(byte limb, byte pos);
  byte getPosAngle(byte limb, byte pos);

  unsigned int getHitTime(byte limb, byte pos, byte velocity, bool printOutput = 0);
  String getPosName(byte limb, byte pos);

  void setLimbParams(signed char directions[NB_HIT_JOINTS_DR],
                     byte anglesLeftArm[NB_POS_LA_DR][ANGLES_PER_POSITION], String namesLeftArm[NB_POS_LA_DR],
                     byte anglesRightArm[NB_POS_RA_DR][ANGLES_PER_POSITION], String namesRightArm[NB_POS_RA_DR],
                     byte anglesRightLeg[NB_POS_RL_DR][ANGLES_PER_POSITION], String namesRightLeg[NB_POS_RL_DR],
                     byte inactiveAngles[NB_HIT_JOINTS_DR]);

private:
  void setLimbParams();

  struct posParamsDrum paramsLeftArm_[NB_POS_LA_DR], paramsRightArm_[NB_POS_RA_DR], paramsRightLeg_[NB_POS_RL_DR];
  posParamsDrum *posParameters_[NB_HIT_JOINTS_DR] = { paramsLeftArm_, paramsRightArm_, paramsRightLeg_ };
};

#endif
