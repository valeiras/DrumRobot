#include "singer_robot.h"

SingerRobot::SingerRobot() {
  setVibratoParams(DEFAULT_CLOSED_POS, DEFAULT_OPEN_POS, DEFAULT_VIBRATO_AMP);
}

void SingerRobot::noteOn(byte singerIdx, unsigned long currTime, bool printOutput) {
  vibratoDirection_[singerIdx] = 1;
  vibrato_[singerIdx] = true;
  vibratoServos_[singerIdx].write(openPosition_ + vibratoAmplitude_);

  nextVibratoInstructionTime_[singerIdx] = currTime + abs((openPosition_ + vibratoAmplitude_ - closedPosition_) / wServo_);

  if (printOutput) {
    Serial.print("Writing ");
    Serial.print(openPosition_ + vibratoAmplitude_);
    Serial.print(" to servo ");
    Serial.print(singerIdx);
  }
}

void SingerRobot::noteOff(byte singerIdx) {
  vibratoServos_[singerIdx].write(closedPosition_);
  vibrato_[singerIdx] = false;
}

void SingerRobot::checkVibrato(unsigned long currTime, bool printOutput) {
  if (printOutput) {
    Serial.print("Current time: ");
    Serial.println(currTime);
  }
  for (unsigned int ii = 0; ii < NB_SINGERS; ii++) {
    if (printOutput) {
      Serial.print("Limb ");
      Serial.print(ii);
      Serial.print(", next vibrato time: ");
      Serial.println(nextVibratoInstructionTime_[ii]);
    }

    if (vibrato_[ii] && currTime > nextVibratoInstructionTime_[ii]) {
      goToNextVibratoPosition(ii);
    }
  }
}

void SingerRobot::goToNextVibratoPosition(byte singerIdx) {
  vibratoDirection_[singerIdx] = -vibratoDirection_[singerIdx];
  vibratoServos_[singerIdx].write(openPosition_ + vibratoDirection_[singerIdx] * vibratoAmplitude_);
  nextVibratoInstructionTime_[singerIdx] += 2 * vibratoAmplitude_ / wServo_;
}

void SingerRobot::setServoSpeed(float wServo) {
  wServo_ = wServo;
}

float SingerRobot::getServoSpeed() {
  return wServo_;
}

void SingerRobot::attachServos(byte vibratoPins[NB_SINGERS]) {
  for (unsigned int ii = 0; ii < NB_SINGERS; ii++) {
    vibratoServos_[ii].attach(vibratoPins[ii]);
    vibratoServos_[ii].write(closedPosition_);
  }
}

void SingerRobot::setVibratoParams(byte closedPos, byte openPos, byte vibratoAmp) {
  closedPosition_ = closedPos;
  openPosition_ = openPos;
  vibratoAmplitude_ = vibratoAmp;
}