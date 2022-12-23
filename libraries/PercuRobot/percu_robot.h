#ifndef Percu_robot_h
#define Percu_robot_h

#include <Servo.h>

#include "Arduino.h"

#define VEL_MULTIPLIER 1

template <int NB_HIT_JOINTS, int NB_POS_JOINTS>
class PercuRobot {
 public:
  PercuRobot();

  virtual void hit(byte limb, byte pos, byte velocity, bool printOutput = 0);
  virtual void rest(byte limb, byte pos = 0);
  virtual void goToPos(byte limb, byte pos);

  void goToPosAngle(byte limb, byte posAngle);
  void goToHitAngle(byte limb, byte hitAngle);

  virtual byte getHitAngle(byte limb, byte pos, byte velocity) = 0;
  virtual byte getRestAngle(byte limb, byte pos) = 0;
  virtual byte getPosAngle(byte limb, byte pos) = 0;
  virtual unsigned int getHitTime(byte limb, byte pos, byte velocity) = 0;
  virtual String getPosName(byte limb, byte pos) = 0;

  void setServoSpeed(float wServo);
  float getServoSpeed();

  void attachServos(byte hitPins[NB_HIT_JOINTS], byte posPins[NB_POS_JOINTS]);

 protected:
  signed char hitDirection_[NB_HIT_JOINTS];
  byte nbPos_[NB_HIT_JOINTS];
  // rotational speed degrees per ms
  float wServo_;

 private:
  Servo hitServos_[NB_HIT_JOINTS];
  Servo posServos_[NB_POS_JOINTS];
};

#endif
