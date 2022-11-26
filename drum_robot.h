#ifndef Drum_robot_h
#define Drum_robot_h

#include "Arduino.h"
#include <Servo.h>
#include "robot_config.h"

#define NB_POS_RIGHT_LEG 1
#define NB_POS_LEFT_ARM 3
#define NB_POS_RIGHT_ARM 3

#define RIGHT_LEG 0
#define LEFT_ARM 1
#define RIGHT_ARM 2

struct limbParams{
  byte hitAngle, restAngle, posAngle;
  unsigned int hitTime;
  String posName;  // Name of the position, for debugging purposes
};
  
class DrumRobot{
  public:
    DrumRobot();
    DrumRobot(byte bdHitPin, byte rightHitPin, byte leftHitPin, byte rightPosPin, byte leftPosPin);

    void hit(byte limb, byte pos);
    void rest(byte limb, byte pos);
    void goToPos(byte limb, byte pos);

    void goToPosAngle(byte limb, byte posAngle);
    void goToHitAngle(byte limb, byte hitAngle);
    
    byte getHitAngle(byte limb, byte pos);
    byte getRestAngle(byte limb, byte pos);
    byte getPosAngle(byte limb, byte pos);
    unsigned int getHitTime(byte limb, byte pos);
    float getServoSpeed();
    
    String getPosName(byte limb, byte pos);
  
    void setupLimbParams(float wServo, byte hutAngleBD, byte restAngleBD, byte posAngleBD, 
                         byte hitAngleSticksLeft, byte restAngleSticksLeft, byte posAngleSticksLeft, 
                         byte hitAngleHH, byte restAngleHH, byte posAngleHH,
                         byte hitAngleSNLeft, byte restAngleSNLeft, byte posAngleSNLeft, 
                         byte hitAngleSticksRight, byte restAngleSticksRight, byte posAngleSticksRight, 
                         byte hitAngleSNRight, byte restAngleSNRight, byte posAngleSNRight, 
                         byte hitAngleCrash, byte restAngleCrash, byte posAngleCrash);
                         
  private:
    void setupLimbParams();

    Servo hitServoRightLeg_, hitServoLeftArm_, posServoLeftArm_, hitServoRightArm_, posServoRightArm_;
    
    // rotational speed degrees per ms, from the data sheet of the servo
    float wServo_;
    struct limbParams paramsRightLeg_[NB_POS_RIGHT_LEG], paramsLeftArm_[NB_POS_LEFT_ARM], paramsRightArm_[NB_POS_RIGHT_ARM];
};

#endif
