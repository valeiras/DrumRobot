#include <musician_robot.h>

#ifndef Glocken_robot_h
#define Glocken_robot_h

#include "glocken_robot_config.h"

class GlockenRobot : public MusicianRobot<NB_HIT_JOINTS_GLOCK, NB_POS_JOINTS_GLOCK> {
public:
  GlockenRobot();

  byte getHitAngle(byte limb, byte pos, byte velocity);
  byte getRestAngle(byte limb, byte pos);
  byte getPosAngle(byte limb, byte pos);
  unsigned int getHitTime(byte limb, byte pos, byte velocity);
  String getPosName(byte limb, byte pos);

  void setLimbParams(signed char directions[NB_HIT_JOINTS_GLOCK]);

  void setWServo(float wServo);

private:
  void setLimbParams();

  byte hitAngles_[NB_HIT_JOINTS_GLOCK], restAngles_[NB_HIT_JOINTS_GLOCK];
  
  byte posAnglesLeft_[NB_POS_LAG], posAnglesRight_[NB_POS_LAG];
  byte* posAngles_[NB_POS_JOINTS_GLOCK] = {posAnglesLeft_, posAnglesRight_};
  
  String posNamesLeft_[NB_POS_LAG], posNamesRight_[NB_POS_RAG];
  String* posNames_[NB_POS_JOINTS_GLOCK] = {posNamesLeft_, posNamesRight_};
};

#endif
