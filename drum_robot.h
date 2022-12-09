#ifndef Drum_robot_h
#define Drum_robot_h

#include "Arduino.h"
#include <Servo.h>
#include "robot_config.h"

#define VEL_MULTIPLIER 1

struct posParams {
  byte hitAngle, restAngle, posAngle;
  String posName;  // Name of the position, for debugging purposes
};

class DrumRobot {
  public:
    DrumRobot();

    void hit(byte limb, byte pos, byte velocity, bool printOutput);
    void rest(byte limb, byte pos);
    void goToPos(byte limb, byte pos);

    void goToPosAngle(byte limb, byte posAngle);
    void goToHitAngle(byte limb, byte hitAngle);

    byte getHitAngle(byte limb, byte pos, byte velocity);
    byte getRestAngle(byte limb, byte pos);
    byte getPosAngle(byte limb, byte pos);
    unsigned int getHitTime(byte limb, byte pos, byte velocity, bool printOutput);
    float getServoSpeed();

    String getPosName(byte limb, byte pos);

    void attachServos(byte bdHitPin, byte rightHitPin, byte leftHitPin, byte rightPosPin, byte leftPosPin);

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

    Servo hitServoRightLeg_, hitServoLeftArm_, posServoLeftArm_, hitServoRightArm_, posServoRightArm_;
    signed char dirRightLeg_, dirLeftArm_, dirRightArm_;

    // rotational speed degrees per ms, from the data sheet of the servo
    float wServo_;
    struct posParams paramsRightLeg_[_nbPosRightLeg], paramsLeftArm_[_nbPosLeftArm], paramsRightArm_[_nbPosRightArm];
};

#endif
