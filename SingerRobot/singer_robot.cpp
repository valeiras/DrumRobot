#include "singer_robot.h"

SingerRobot::SingerRobot(byte vibratoPins[NB_SINGERS])
  : PercuRobot(vibratoPins) {

  // We initialize the default parameters
  setVibratoParams(DEFAULT_CLOSED_POS, DEFAULT_OPEN_POS, DEFAULT_VIBRATO_AMP);

  setServoSpeed(_wServoSg);
  hasVibrato_ = false;
  stop();

  for (unsigned int ii = 0; ii < NB_SINGERS; ii++) {
    noteOn_[ii] = 0;
    noteOnPending_[ii] = false;
    noteOffPending_[ii] = false;
    currNoteIdx_[ii] = 0;
  }

  setFrequencies();
}

unsigned int SingerRobot::getFrequency(byte singerIdx) {
  if (singerIdx < NB_SINGERS) {
    return frequencies_[currNoteIdx_[singerIdx]];
  } else {
    return 0;
  }
}

String SingerRobot::getNoteName(byte singerIdx) {
  if (singerIdx < NB_SINGERS) {
    return noteNames_[currNoteIdx_[singerIdx]];
  } else {
    return "";
  }
}

void SingerRobot::hit(byte singerIdx, byte pos, byte noteIdx, bool hasOutput = 0) {
  if (noteIdx == 0) {
    makeNoteOff(singerIdx);
  } else if (noteIdx < NB_NOTES_SG) {
    makeNoteOn(singerIdx, noteIdx, hasOutput);
  } else {
    makeNoteOn(singerIdx, NB_NOTES_SG - 1, hasOutput);
  }
}

void SingerRobot::rest(byte singerIdx, byte pos = 0, bool hasOutput = 0) {
}

void SingerRobot::stop() {
  for (unsigned int ii = 0; ii < NB_SINGERS; ii++) {
    hitServos_[ii].write(closedPosition_);
    makeNoteOff(ii);
  }
}

void SingerRobot::makeNoteOn(byte singerIdx, byte noteIdx, bool hasOutput = 0) {
  noteOnPending_[singerIdx] = true;
  noteOn_[singerIdx] = true;
  currNoteIdx_[singerIdx] = noteIdx;
}

void SingerRobot::makeNoteOff(byte singerIdx) {
  noteOffPending_[singerIdx] = true;
  noteOn_[singerIdx] = false;
}

bool SingerRobot::isNoteOn(byte singerIdx) {
  return noteOn_[singerIdx];
}

bool SingerRobot::isNoteOnPending(byte singerIdx) {
  return noteOnPending_[singerIdx];
}

bool SingerRobot::isNoteOffPending(byte singerIdx) {
  return noteOffPending_[singerIdx];
}

bool SingerRobot::unsetNoteOnPending(byte singerIdx) {
  noteOnPending_[singerIdx] = false;
}

bool SingerRobot::unsetNoteOffPending(byte singerIdx) {
  noteOffPending_[singerIdx] = false;
}

void SingerRobot::startVibrato(byte singerIdx, unsigned long currTime, bool hasOutput = 0) {
  vibratoDirection_[singerIdx] = 1;
  hitServos_[singerIdx].write(openPosition_ + vibratoAmplitude_);
  nextVibratoInstructionTime_[singerIdx] = currTime + abs((openPosition_ + vibratoAmplitude_ - closedPosition_) / wServo_);
}

void SingerRobot::stopVibrato(byte singerIdx, bool hasOutput = 0) {
  hitServos_[singerIdx].write(closedPosition_);
}

void SingerRobot::checkVibrato(byte singerIdx, unsigned long currTime, bool hasOutput = 0) {
  if (hasVibrato_) {
    if (noteOn_[singerIdx] && currTime > nextVibratoInstructionTime_[singerIdx]) {
      goToNextVibratoPosition(singerIdx);
    }
  }
}

void SingerRobot::setVibrato(bool hasVibrato) {
  hasVibrato_ = hasVibrato;
}

void SingerRobot::goToNextVibratoPosition(byte singerIdx) {
  vibratoDirection_[singerIdx] = -vibratoDirection_[singerIdx];
  hitServos_[singerIdx].write(openPosition_ + vibratoDirection_[singerIdx] * vibratoAmplitude_);
  nextVibratoInstructionTime_[singerIdx] += 2 * vibratoAmplitude_ / wServo_;
}

void SingerRobot::setVibratoParams(byte closedPos, byte openPos, byte vibratoAmp) {
  closedPosition_ = closedPos;
  openPosition_ = openPos;
  vibratoAmplitude_ = vibratoAmp;
}

void SingerRobot::setLimbParams() {
}

void SingerRobot::setFrequencies() {
  frequencies_.push_back(NOTE_OFF);
  frequencies_.push_back(FREQ_C03);
  frequencies_.push_back(FREQ_CS3);
  frequencies_.push_back(FREQ_D03);
  frequencies_.push_back(FREQ_DS3);
  frequencies_.push_back(FREQ_E03);
  frequencies_.push_back(FREQ_F03);
  frequencies_.push_back(FREQ_FS3);
  frequencies_.push_back(FREQ_G03);
  frequencies_.push_back(FREQ_GS3);
  frequencies_.push_back(FREQ_A03);
  frequencies_.push_back(FREQ_AS3);
  frequencies_.push_back(FREQ_B03);
  frequencies_.push_back(FREQ_C04);
  frequencies_.push_back(FREQ_CS4);
  frequencies_.push_back(FREQ_D04);
  frequencies_.push_back(FREQ_DS4);
  frequencies_.push_back(FREQ_E04);
  frequencies_.push_back(FREQ_F04);
  frequencies_.push_back(FREQ_FS4);
  frequencies_.push_back(FREQ_G04);
  frequencies_.push_back(FREQ_GS4);
  frequencies_.push_back(FREQ_A04);
  frequencies_.push_back(FREQ_AS4);
  frequencies_.push_back(FREQ_B04);

  noteNames_.push_back("OFF");
  noteNames_.push_back("C03");
  noteNames_.push_back("CS3");
  noteNames_.push_back("D03");
  noteNames_.push_back("DS3");
  noteNames_.push_back("E03");
  noteNames_.push_back("F03");
  noteNames_.push_back("FS3");
  noteNames_.push_back("G03");
  noteNames_.push_back("GS3");
  noteNames_.push_back("A03");
  noteNames_.push_back("AS3");
  noteNames_.push_back("B03");
  noteNames_.push_back("C04");
  noteNames_.push_back("CS4");
  noteNames_.push_back("D04");
  noteNames_.push_back("DS4");
  noteNames_.push_back("E04");
  noteNames_.push_back("F04");
  noteNames_.push_back("FS4");
  noteNames_.push_back("G04");
  noteNames_.push_back("GS4");
  noteNames_.push_back("A04");
  noteNames_.push_back("AS4");
  noteNames_.push_back("B04");
}