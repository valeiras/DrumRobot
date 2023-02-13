#ifndef Singer_robot_h
#define Singer_robot_h

#include <Arduino.h>
#include <Servo.h>
#include "singer_robot_config.h"

class SingerRobot {
public:
  SingerRobot();

  void noteOn(byte singerIdx, unsigned long currTime, bool printOutput = 0);
  void noteOff(byte singerIdx);

  void checkVibrato(unsigned long currTime, bool printOutput = 0);
  void goToNextVibratoPosition(byte singerIdx);

  void setServoSpeed(float wServo);
  float getServoSpeed();

  void setVibratoParams(byte closedPos, byte openPos, byte vibratoAmp);

  String getNoteName(byte note);

  void attachServos(byte vibratoPins[NB_SINGERS]);

private:
  float wServo_;

  Servo vibratoServos_[NB_SINGERS];
  byte buzzPins_[NB_SINGERS];

  bool vibrato_[NB_SINGERS];
  signed char vibratoDirection_[NB_SINGERS];
  unsigned long nextVibratoInstructionTime_[NB_SINGERS];
  byte closedPosition_, openPosition_, vibratoAmplitude_;
};

#endif
