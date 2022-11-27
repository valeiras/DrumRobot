#include "drum_song.h"

DrumSong::DrumSong() {
  hitIndexRightLeg_ = -1;
  hitIndexLeftArm_ = -1;
  hitIndexRightArm_ = -1;

  patternIndexRightLeg_ = 0;
  patternIndexLeftArm_ = 0;
  patternIndexRightArm_ = 0;
}


unsigned long DrumSong::getTimeToNextHit(byte limb) {
  unsigned int pattern = getHitPattern(limb);
  short* hitIndex = getHitIndexPointer(limb);
  byte* patternIndex = getPatternIndexPointer(limb);

  unsigned long timeToNextInstruction = 0;

  do {
    // We iterate the pattern. When we get to the end we start again
    if (++(*hitIndex) >= SEMIQUAVERS_PER_BEAT) {
      *hitIndex = 0;
      *patternIndex = (*patternIndex + 1) % nbBeats_;
      pattern = getHitPattern(limb);
    }
    timeToNextInstruction += timeSemiquaver_;
  } while (!bitRead(pattern, *hitIndex));

  return timeToNextInstruction;
}

byte DrumSong::getPosNextHit(byte limb) {
  byte patternId;

  switch (limb) {
    case LEFT_ARM:
      patternId = patternSequence_[patternIndexLeftArm_];
      return posPatternsLeftArm_[patternId][hitIndexLeftArm_];
    case RIGHT_ARM:
      patternId = patternSequence_[patternIndexRightArm_];
      return posPatternsRightArm_[patternId][hitIndexRightArm_];
    default:
      return 255;
  }
}

void DrumSong::setBpm(unsigned short bpm) {
  bpm_ = bpm;
  timeQuarter_ = int(60000.0 / bpm_);       // us per quarter note
  timeQuaver_ = int(timeQuarter_ / 2.0);    // us per quaver note
  timeSemiquaver_ = int(timeQuaver_ / 2.0); // us per semiquaver note
}

unsigned int DrumSong::getNumberOfPositions(byte limb) {
  switch (limb) {
    case LEFT_ARM:
      return nbPosLeftArm;
    case RIGHT_ARM:
      return nbPosRightArm;
    default:
      return 0;
  }
}

byte* DrumSong::getPosPattern(byte limb, byte patternId) {
  if (patternId < nbPatterns_) {
    switch (limb) {
      case LEFT_ARM:
        return posPatternsLeftArm_[patternId];
      case RIGHT_ARM:
        return posPatternsRightArm_[patternId];
    }
  }
  else {
    return errPosPattern_;
  }
}

Array<byte[16], MAX_NB_PATTERNS>* DrumSong::getPosPatternsPointer(byte limb) {
  switch (limb) {
    case LEFT_ARM:
      return &posPatternsLeftArm_;
    case RIGHT_ARM:
      return &posPatternsRightArm_;
  }
}

unsigned int DrumSong::getHitPattern(byte limb, byte patternId) {
  if (patternId < nbPatterns_) {
    switch (limb) {
      case RIGHT_LEG:
        return hitPatternsRightLeg_[patternId];
      case LEFT_ARM:
        return hitPatternsLeftArm_[patternId];
      case RIGHT_ARM:
        return hitPatternsRightArm_[patternId];
    }
  }
  else {
    return 0;
  }
}

unsigned int DrumSong::getHitPattern(byte limb) {
  byte patternId;

  switch (limb) {
    case RIGHT_LEG:
      patternId = patternSequence_[patternIndexRightLeg_];
      return hitPatternsRightLeg_[patternId];
    case LEFT_ARM:
      patternId = patternSequence_[patternIndexLeftArm_];
      return hitPatternsLeftArm_[patternId];
    case RIGHT_ARM:
      patternId = patternSequence_[patternIndexRightArm_];
      return hitPatternsRightArm_[patternId];
  }
}

unsigned int* DrumSong::getHitPatternPointer(byte limb, byte patternId) {
  if (patternId < nbPatterns_) {
    switch (limb) {
      case RIGHT_LEG:
        return &hitPatternsRightLeg_[patternId];
      case LEFT_ARM:
        return &hitPatternsLeftArm_[patternId];
      case RIGHT_ARM:
        return &hitPatternsRightArm_[patternId];
    }
  }
  else {
    return new unsigned int;
  }
}

short* DrumSong::getHitIndexPointer(byte limb) {
  switch (limb) {
    case RIGHT_LEG:
      return &hitIndexRightLeg_;
    case LEFT_ARM:
      return &hitIndexLeftArm_;
    case RIGHT_ARM:
      return &hitIndexRightArm_;
  }
}

byte* DrumSong::getPatternIndexPointer(byte limb) {
  switch (limb) {
    case RIGHT_LEG:
      return &patternIndexRightLeg_;
    case LEFT_ARM:
      return &patternIndexLeftArm_;
    case RIGHT_ARM:
      return &patternIndexRightArm_;
  }
}

void DrumSong::setHitPattern(byte limb, byte hitPatternIndex, unsigned int inputPattern) {
  if (hitPatternIndex < nbPatterns_) {
    unsigned int *pattern = getHitPatternPointer(limb, hitPatternIndex);
    *pattern = 0;
    for (unsigned int ii = 0; ii < SEMIQUAVERS_PER_BEAT; ii++) {
      if (bitRead(inputPattern, ii)) {
        // We write the pattern from right to left
        bitSet(*pattern, SEMIQUAVERS_PER_BEAT - ii - 1);
      }
    }
  }
}

void DrumSong::setPosPattern(byte limb, byte inputPattern[][SEMIQUAVERS_PER_BEAT]) {
  Array<byte[16], MAX_NB_PATTERNS> *pattern = getPosPatternsPointer(limb);
  
  unsigned int nbPos = getNumberOfPositions(limb);
  for (int ii = 0; ii < nbPatterns_; ii++) {
    for (int jj = 0; jj < SEMIQUAVERS_PER_BEAT; jj++) {
      if (inputPattern[ii][jj] < nbPos) {
        (*pattern)[ii][jj] = inputPattern[ii][jj];
      }
      else {
        (*pattern)[ii][jj] = 0;
      }
    }
  }
}

void DrumSong::setPatternSequence(byte pattSeq[]) {
  for (int ii = 0; ii < nbBeats_; ii++) {
    if (pattSeq[ii] < nbPatterns_) {
      patternSequence_.push_back(pattSeq[ii]);
    }
    else {
      patternSequence_.push_back(0);
    }
  }
}
