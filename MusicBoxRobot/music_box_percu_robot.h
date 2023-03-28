#ifndef Music_box_percu_robot_h
#define Music_box_percu_robot_h

#include <percu_robot.h>
#include "music_box_config.h"

class MusicBoxPercuRobot : public PercuRobot<NB_HIT_JOINTS_MB, NB_POS_JOINTS_MB>{
public:
  MusicBoxPercuRobot(byte hitPins[NB_HIT_JOINTS_MB]);

  byte getHitAngle(byte limb, byte pos, byte velocity);
  byte getRestAngle(byte limb, byte pos);
  byte getPosAngle(byte limb, byte pos);
  String getPosName(byte limb, byte pos);

  unsigned int getHitTime(byte limb, byte pos, byte velocity, bool printOutput = 0);

  void setLimbParams(signed char directionFoot, signed char directionHead,
                     byte hitAngleFoot, byte hitAngleHead,
                     byte restAngleFoot, byte restAngleHead);

private:
  void setLimbParams();

  byte hitAngles_[NB_HIT_JOINTS_MB], restAngles_[NB_HIT_JOINTS_MB];
};

#endif
