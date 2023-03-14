#include <percu_robot.h>

#ifndef Glocken_robot_h
#define Glocken_robot_h

#include "glocken_robot_config.h"

class GlockenRobot : public PercuRobot<NB_HIT_JOINTS_GL, NB_POS_JOINTS_GL> {
public:
  GlockenRobot(byte hitPins[NB_HIT_JOINTS_GL], byte posPins[NB_POS_JOINTS_GL]);

  byte getHitAngle(byte limb, byte pos, byte velocity);
  byte getRestAngle(byte limb, byte pos);
  byte getPosAngle(byte limb, byte pos);
  unsigned int getHitTime(byte limb, byte pos, byte velocity, bool printOutput = 0);
  String getPosName(byte limb, byte pos);

  void setLimbParams(signed char directionLeft, signed char directionRight,
                     byte hitAngleLeft, byte hitAngleRight,
                     byte restAngleLeft, byte restAngleRight,
                     byte posAnglesLeft[NB_POS_LA_GL], byte posAnglesRight[NB_POS_RA_GL],
                     String posNamesLeft[NB_POS_LA_GL], String posNamesRight[NB_POS_RA_GL]);

private:
  void setLimbParams();

  byte hitAngles_[NB_HIT_JOINTS_GL], restAngles_[NB_HIT_JOINTS_GL];

  byte posAnglesLeft_[NB_POS_LA_GL], posAnglesRight_[NB_POS_LA_GL];
  byte* posAngles_[NB_POS_JOINTS_GL] = { posAnglesLeft_, posAnglesRight_ };

  String posNamesLeft_[NB_POS_LA_GL], posNamesRight_[NB_POS_RA_GL];
  String* posNames_[NB_POS_JOINTS_GL] = { posNamesLeft_, posNamesRight_ };
};

#endif
