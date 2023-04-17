#ifndef Glocken_robot_ld_h
#define Glocken_robot_ld_h

#include <percu_robot.h>

#include "glocken_robot_config_ld.h"

class GlockenRobotLD : public PercuRobot<NB_HIT_JOINTS_GL, NB_POS_JOINTS_GL> {
public:
  GlockenRobotLD(byte hitPins[NB_HIT_JOINTS_GL], byte posPins[NB_POS_JOINTS_GL]);

  byte getHitAngle(byte limb, byte pos, byte velocity);
  byte getRestAngle(byte limb, byte pos);
  byte getPosAngle(byte limb, byte pos);

  unsigned int getHitTime(byte limb, byte pos, byte velocity, bool printOutput = 0);
  String getPosName(byte limb, byte pos);

  void setLimbParams(signed char directionLeft, signed char directionRight, signed char directionHead,
                     byte hitAngleLeft, byte hitAngleRight, byte hitAngleHead,
                     byte restAngleLeft, byte restAngleRight, byte restAngleHead,
                     byte posAngleLeft[NB_POS_LA_GL], byte posAngleRight[NB_POS_RA_GL], byte posAngleHead[NB_POS_HD_GL],
                     String posNamesLeft[NB_POS_LA_GL], String posNamesRight[NB_POS_RA_GL], String posNamesHead[NB_POS_HD_GL],
                     byte inactiveAngleLA, byte inactiveAngleRA, byte inactiveAngleHd);

private:
  void setLimbParams();

  byte hitAngle_[NB_HIT_JOINTS_GL], restAngle_[NB_HIT_JOINTS_GL];

  byte posAngleLeft_[NB_POS_LA_GL], posAngleRight_[NB_POS_LA_GL], posAngleHead_[NB_POS_HD_GL];
  byte* posAngle_[NB_POS_JOINTS_GL] = { posAngleLeft_, posAngleRight_, posAngleHead_ };

  String posNamesLeft_[NB_POS_LA_GL], posNamesRight_[NB_POS_RA_GL], posNamesHead_[NB_POS_HD_GL];
  String* posNames_[NB_POS_JOINTS_GL] = { posNamesLeft_, posNamesRight_, posNamesHead_ };
};

#endif
