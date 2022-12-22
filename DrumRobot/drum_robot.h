#include <musician_robot.h>

#ifndef Drum_robot_h
#define Drum_robot_h

#include "drum_robot_config.h"

struct posParamsDrum {
  byte hitAngle, restAngle, posAngle;
  String posName;  // Name of the position, for debugging purposes
};

class DrumRobot : public MusicianRobot<NB_HIT_JOINTS_DRUM, NB_POS_JOINTS_DRUM>{
  public:
    DrumRobot();

    byte getHitAngle(byte limb, byte pos, byte velocity);
    byte getRestAngle(byte limb, byte pos);
    byte getPosAngle(byte limb, byte pos);
    unsigned int getHitTime(byte limb, byte pos, byte velocity);
    String getPosName(byte limb, byte pos);

    void setupLimbParams(float wServo, signed char dirRightLeg, signed char dirLeftArm, signed char dirRightArm,
                         byte hitAngleBD, byte restAngleBD, byte posAngleBD,
                         byte hitAngleSticksLeft, byte restAngleSticksLeft, byte posAngleSticksLeft,
                         byte hitAngleHH, byte restAngleHH, byte posAngleHH,
                         byte hitAngleSNLeft, byte restAngleSNLeft, byte posAngleSNLeft,
                         byte hitAngleSticksRight, byte restAngleSticksRight, byte posAngleSticksRight,
                         byte hitAngleSNRight, byte restAngleSNRight, byte posAngleSNRight,
                         byte hitAngleCrash, byte restAngleCrash, byte posAngleCrash);

  private:
    void setupLimbParams();

    struct posParamsDrum paramsLeftArm_[NB_POS_LEFT_ARM], paramsRightArm_[NB_POS_RIGHT_ARM], paramsRightLeg_[NB_POS_RIGHT_LEG];
    posParamsDrum *posParameters_[NB_HIT_JOINTS_DRUM] = {paramsLeftArm_, paramsRightArm_, paramsRightLeg_};
};

#endif
