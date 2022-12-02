#include "drum_song.h"

DrumSong::DrumSong() {
  hitIndexRL_ = -1;
  hitIndexLA_ = -1;
  hitIndexRA_ = -1;

  patternSequenceIndexRL_ = 0;
  patternSequenceIndexLA_ = 0;
  patternSequenceIndexRA_ = 0;

  posMask_ = B00000111;
}

void DrumSong::createPatterns(bool printOutput) {

}

void DrumSong::initializeBlankPatterns(unsigned int nbPatterns, unsigned int nbBeats) {
  nbPatterns_ = nbPatterns;
  nbBeats_ = nbBeats;

  for (int ii = 0; ii < nbPatterns_; ii++) {
    hitPatternsRL_[ii] = 0;
    hitPatternsLA_[ii] = 0;
    hitPatternsRA_[ii] = 0;

    for (int jj = 0; jj < SEMIQUAVERS_PER_BEAT; jj++) {
      posPatternsLA_[ii][jj] = 0;
      posPatternsRA_[ii][jj] = 0;
      hitAndPosPatternsRL_[ii][jj] = 0;
      hitAndPosPatternsRA_[ii][jj] = 0;
      hitAndPosPatternsLA_[ii][jj] = 0;
    }
  }

  for (int ii = 0; ii < nbBeats_; ii++) {
    patternSequence_[ii] = 0;
  }
}

unsigned long DrumSong::getTimeToNextHit(byte limb) {
  unsigned int pattern = getHitPattern(limb);
  signed char* hitIndex = getHitIndexPointer(limb);
  byte* patternSequenceIndex = getPatternSequenceIndexPointer(limb);

  signed char copyHitIndex = *hitIndex;
  byte copyPatternSequenceIndex = *patternSequenceIndex;
  byte patternId = patternSequence_[copyPatternSequenceIndex];

  unsigned long timeToNextInstruction = 0;

  do {
    // We iterate the pattern. When we get to the end we start again
    if (++(*hitIndex) >= SEMIQUAVERS_PER_BEAT) {
      *hitIndex = 0;
      *patternSequenceIndex = (*patternSequenceIndex + 1) % nbBeats_;
      pattern = getHitPattern(limb);
    }

    timeToNextInstruction += timeSemiquaver_;
  } while (!bitRead(pattern, *hitIndex));

  // We repeat the same process with the new array

  byte* hitAndPosPattern = getHitAndPosPattern(limb, patternId);
  unsigned long newTimeToNextInstruction = 0;

  do {
    // We iterate the pattern. When we get to the end we start again
    if (++(copyHitIndex) >= SEMIQUAVERS_PER_BEAT) {
      copyHitIndex = 0;
      copyPatternSequenceIndex = (copyPatternSequenceIndex + 1) % nbBeats_;
      patternId = patternSequence_[copyPatternSequenceIndex];
      hitAndPosPattern = getHitAndPosPattern(limb, patternId);
    }
    newTimeToNextInstruction += timeSemiquaver_;
  } while (!bitRead(hitAndPosPattern[copyHitIndex], 0));

  if (copyHitIndex != *hitIndex || copyPatternSequenceIndex != *patternSequenceIndex || newTimeToNextInstruction != timeToNextInstruction) {
    Serial.print("Error in the time to next hit -> Limb: ");
    ////Serial.println(limb);
    ////Serial.print("Bit : ");
    ////Serial.println(bitRead(pattern, *hitIndex));
    ////Serial.print("Pattern : ");
    ////Serial.println(pattern, BIN);
    ////Serial.print("New bit: ");
    ////Serial.println(bitRead(hitAndPosPattern[copyHitIndex], 0));
    ////Serial.print("New pattern : ");
    ////Serial.println("");
    //Serial.print("Hit index ");
    //Serial.print(*hitIndex);
    //Serial.print(" - copy hit index ");
    //Serial.print(copyHitIndex);
    //Serial.print(" - pattern index ");
    //Serial.print(*patternSequenceIndex);
    //Serial.print(" - copy pattern index ");
    //Serial.print(copyPatternSequenceIndex);
    //Serial.print(" - time to next instruction ");
    //Serial.print(timeToNextInstruction);
    //Serial.print(" - new time to next instruction ");
    //Serial.println(newTimeToNextInstruction);

  }

  return newTimeToNextInstruction;
}

byte DrumSong::getPosNextHit(byte limb) {
  byte patternId;
  switch (limb) {
    case LEFT_ARM:
      patternId = patternSequence_[patternSequenceIndexLA_];
      if ((hitAndPosPatternsLA_[patternId][hitIndexLA_] >> BITS_FOR_HIT) != posPatternsLA_[patternId][hitIndexLA_]) {
        Serial.println("Error in the pos!!!");
      }
      return posPatternsLA_[patternId][hitIndexLA_];
    case RIGHT_ARM:
      patternId = patternSequence_[patternSequenceIndexRA_];
      if ((hitAndPosPatternsRA_[patternId][hitIndexRA_] >> BITS_FOR_HIT) != posPatternsRA_[patternId][hitIndexRA_]) {
        Serial.println("Error in the pos!!!");
      }
      return (hitAndPosPatternsRA_[patternId][hitIndexRA_] >> BITS_FOR_HIT);
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

void DrumSong::setQuarterHit(byte limb, byte pos, byte patternId, byte noteIndex) {
  if (noteIndex > 0 && 4 * (noteIndex - 1) < SEMIQUAVERS_PER_BEAT && pos < getNumberOfPositions(limb) ) {
    unsigned int* pattern = getHitPatternPointer(limb, patternId);
    bitSet(*pattern, 4 * (noteIndex - 1));

    if (limb != RIGHT_LEG) {
      byte* posPattern = getPosPattern(limb, patternId);
      posPattern[4 * (noteIndex - 1)] = pos;
    }

    byte* hitAndPosPattern = getHitAndPosPattern(limb, patternId);
    byte* hitAndPosCurrElement = &hitAndPosPattern[4 * (noteIndex - 1)];

    *hitAndPosCurrElement = 0;
    bitSet(*hitAndPosCurrElement, 0);
    *hitAndPosCurrElement = *hitAndPosCurrElement | (pos << BITS_FOR_HIT);
  }
}

void DrumSong::setQuaverHit(byte limb, byte pos, byte patternId, byte noteIndex) {
  if (noteIndex > 0 && 2 * (noteIndex - 1) < SEMIQUAVERS_PER_BEAT && pos < getNumberOfPositions(limb) ) {
    unsigned int* pattern = getHitPatternPointer(limb, patternId);
    bitSet(*pattern, 2 * (noteIndex - 1));

    byte* posPattern = getPosPattern(limb, patternId);
    posPattern[2 * (noteIndex - 1)] = pos;

    byte* hitAndPosPattern = getHitAndPosPattern(limb, patternId);
    byte* hitAndPosCurrElement = &hitAndPosPattern[2 * (noteIndex - 1)];

    *hitAndPosCurrElement = 0;
    bitSet(*hitAndPosCurrElement, 0);
    *hitAndPosCurrElement = *hitAndPosCurrElement | (pos << BITS_FOR_HIT);
  }
}

void DrumSong::setSemiquaverHit(byte limb, byte pos, byte patternId, byte noteIndex) {
  if (noteIndex > 0 && (noteIndex - 1) < SEMIQUAVERS_PER_BEAT && pos < getNumberOfPositions(limb) ) {
    unsigned int* pattern = getHitPatternPointer(limb, patternId);
    bitSet(*pattern, noteIndex - 1);

    byte* posPattern = getPosPattern(limb, patternId);
    posPattern[(noteIndex - 1)] = pos;

    byte* hitAndPosPattern = getHitAndPosPattern(limb, patternId);
    byte* hitAndPosCurrElement = &hitAndPosPattern[(noteIndex - 1)];

    *hitAndPosCurrElement = 0;
    bitSet(*hitAndPosCurrElement, 0);
    *hitAndPosCurrElement = *hitAndPosCurrElement | (pos << BITS_FOR_HIT);
  }
}

void DrumSong::setQuarterRest(byte limb, byte patternId, byte noteIndex) {
  if (noteIndex > 0 && 4 * (noteIndex - 1) < SEMIQUAVERS_PER_BEAT) {
    unsigned int* pattern = getHitPatternPointer(limb, patternId);
    bitClear(*pattern, 4 * (noteIndex - 1));

    byte* hitAndPosPattern = getHitAndPosPattern(limb, patternId);
    byte* hitAndPosCurrElement = &hitAndPosPattern[4 * (noteIndex - 1)];

    *hitAndPosCurrElement = 0;
  }
}

void DrumSong::setQuaverRest(byte limb, byte patternId, byte noteIndex) {
  if (noteIndex > 0 && 2 * (noteIndex - 1) < SEMIQUAVERS_PER_BEAT) {
    unsigned int* pattern = getHitPatternPointer(limb, patternId);
    bitClear(*pattern, 2 * (noteIndex - 1));

    byte* hitAndPosPattern = getHitAndPosPattern(limb, patternId);
    byte* hitAndPosCurrElement = &hitAndPosPattern[2 * (noteIndex - 1)];

    *hitAndPosCurrElement = 0;
  }
}

void DrumSong::setSemiquaverRest(byte limb, byte patternId, byte noteIndex) {
  if (noteIndex > 0 && (noteIndex - 1) < SEMIQUAVERS_PER_BEAT) {
    unsigned int* pattern = getHitPatternPointer(limb, patternId);
    bitClear(*pattern, noteIndex - 1);

    byte* hitAndPosPattern = getHitAndPosPattern(limb, patternId);
    byte* hitAndPosCurrElement = &hitAndPosPattern[(noteIndex - 1)];

    *hitAndPosCurrElement = 0;
  }
}


void DrumSong::setHitPattern(byte limb, byte patternId, unsigned int inputPattern, bool printOutput) {
  if (printOutput) {
    Serial.print("pattern to set: ");
    Serial.println(inputPattern, BIN);
  }

  if (patternId < nbPatterns_) {
    unsigned int *pattern = getHitPatternPointer(limb, patternId);
    *pattern = 0;
    for (unsigned int ii = 0; ii < SEMIQUAVERS_PER_BEAT; ii++) {
      if (bitRead(inputPattern, ii)) {
        // We write the pattern from right to left
        bitSet(*pattern, SEMIQUAVERS_PER_BEAT - ii - 1);
      }
    }

    if (printOutput) {
      Serial.print("pattern old style ");
      for (unsigned int ii = 0; ii < SEMIQUAVERS_PER_BEAT; ii++) {
        Serial.print(bitRead(*pattern, ii));
      }
      Serial.println("");
    }
  }


  byte* hitAndPosPattern = getHitAndPosPattern(limb, patternId);

  if (patternId < nbPatterns_) {
    for (unsigned int ii = 0; ii < SEMIQUAVERS_PER_BEAT; ii++) {
      if (bitRead(inputPattern, ii)) {
        // We write the pattern from right to left
        bitSet(hitAndPosPattern[SEMIQUAVERS_PER_BEAT - 1 - ii], 0);
      }
    }
  }

  if (printOutput) {
    Serial.print("pattern new style ");
    for (unsigned int ii = 0; ii < SEMIQUAVERS_PER_BEAT; ii++) {
      Serial.print(bitRead(hitAndPosPattern[ii], 0));
    }
    Serial.println("");
    Serial.println("");
  }
}

void DrumSong::setPosPattern(byte limb, byte inputPattern[][SEMIQUAVERS_PER_BEAT]) {
  Array<byte[16], MAX_NB_PATTERNS> *pattern = getArrayPosPatterns(limb);

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

  Array<byte[16], MAX_NB_PATTERNS> *hitAndPosPattern = getArrayHitAndPosPatterns(limb);

  for (int ii = 0; ii < nbPatterns_; ii++) {
    for (int jj = 0; jj < SEMIQUAVERS_PER_BEAT; jj++) {
      if (inputPattern[ii][jj] < nbPos) {
        (*hitAndPosPattern)[ii][jj] = (*hitAndPosPattern)[ii][jj] | (inputPattern[ii][jj] << BITS_FOR_HIT);
      }
      else {
        (*hitAndPosPattern)[ii][jj] = 0;
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

void DrumSong::printPosPattern(byte limb, byte patternId) {
  if (limb != RIGHT_LEG) {
    Serial.println("");
    Serial.println("Printing pos pattern:");

    Serial.println("With the old method: ");
    byte* posPattern = getPosPattern(limb, patternId);
    for (unsigned int ii = 0; ii < SEMIQUAVERS_PER_BEAT; ii++) {
      Serial.print(posPattern[ii]);
      Serial.print(" ");
    }
    Serial.println("");

    Serial.println("With the new method: ");
    byte* hitAndPosPattern = getHitAndPosPattern(limb, patternId);
    for (unsigned int ii = 0; ii < SEMIQUAVERS_PER_BEAT; ii++) {
      Serial.print((hitAndPosPattern[ii] >> BITS_FOR_HIT) & posMask_);
      Serial.print(" ");
    }
    Serial.println("");
  }
}

void DrumSong::printHitPattern(byte limb, byte patternId) {
  Serial.println("");
  Serial.print("Printing hit pattern number ");
  Serial.println(patternId);

  Serial.println("With the old method: ");
  unsigned int hitPattern = getHitPattern(limb, patternId);
  for (unsigned int ii = 0; ii < SEMIQUAVERS_PER_BEAT; ii++) {
    Serial.print(bitRead(hitPattern, ii));
    Serial.print(" ");
  }
  Serial.println("");

  Serial.println("With the new method: ");
  byte* hitAndPosPattern = getHitAndPosPattern(limb, patternId);
  for (unsigned int ii = 0; ii < SEMIQUAVERS_PER_BEAT; ii++) {
    Serial.print(bitRead(hitAndPosPattern[ii], 0));
    Serial.print(" ");
  }
  Serial.println("");
}

unsigned int DrumSong::getNumberOfPositions(byte limb) {
  switch (limb) {
    case RIGHT_LEG:
      return _nbPosRightLeg;
    case LEFT_ARM:
      return _nbPosLeftArm;
    case RIGHT_ARM:
      return _nbPosRightArm;
    default:
      return 0;
  }
}

byte* DrumSong::getPosPattern(byte limb, byte patternId) {
  if (patternId < nbPatterns_) {
    switch (limb) {
      case RIGHT_LEG:
        return errPosPattern_;
      case LEFT_ARM:
        return posPatternsLA_[patternId];
      case RIGHT_ARM:
        return posPatternsRA_[patternId];
    }
  }
  else {
    return errPosPattern_;
  }
}

byte* DrumSong::getHitAndPosPattern(byte limb, byte patternId) {
  if (patternId < nbPatterns_) {
    switch (limb) {
      case RIGHT_LEG:
        return hitAndPosPatternsRL_[patternId];
      case LEFT_ARM:
        return hitAndPosPatternsLA_[patternId];
      case RIGHT_ARM:
        return hitAndPosPatternsRA_[patternId];
    }
  }
  else {
    return errPosPattern_;
  }
}

Array<byte[16], MAX_NB_PATTERNS>* DrumSong::getArrayPosPatterns(byte limb) {
  switch (limb) {
    case LEFT_ARM:
      return &posPatternsLA_;
    case RIGHT_ARM:
      return &posPatternsRA_;
  }
}

Array<byte[16], MAX_NB_PATTERNS>* DrumSong::getArrayHitAndPosPatterns(byte limb) {
  switch (limb) {
    case RIGHT_LEG:
      return &hitAndPosPatternsRL_;
    case LEFT_ARM:
      return &hitAndPosPatternsLA_;
    case RIGHT_ARM:
      return &hitAndPosPatternsRA_;
  }
}

unsigned int DrumSong::getHitPattern(byte limb, byte patternId) {
  if (patternId < nbPatterns_) {
    switch (limb) {
      case RIGHT_LEG:
        return hitPatternsRL_[patternId];
      case LEFT_ARM:
        return hitPatternsLA_[patternId];
      case RIGHT_ARM:
        return hitPatternsRA_[patternId];
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
      patternId = patternSequence_[patternSequenceIndexRL_];
      return hitPatternsRL_[patternId];
    case LEFT_ARM:
      patternId = patternSequence_[patternSequenceIndexLA_];
      return hitPatternsLA_[patternId];
    case RIGHT_ARM:
      patternId = patternSequence_[patternSequenceIndexRA_];
      return hitPatternsRA_[patternId];
  }
}

unsigned int* DrumSong::getHitPatternPointer(byte limb, byte patternId) {
  if (patternId < nbPatterns_) {
    switch (limb) {
      case RIGHT_LEG:
        return &hitPatternsRL_[patternId];
      case LEFT_ARM:
        return &hitPatternsLA_[patternId];
      case RIGHT_ARM:
        return &hitPatternsRA_[patternId];
    }
  }
  else {
    return new unsigned int;
  }
}

signed char* DrumSong::getHitIndexPointer(byte limb) {
  switch (limb) {
    case RIGHT_LEG:
      return &hitIndexRL_;
    case LEFT_ARM:
      return &hitIndexLA_;
    case RIGHT_ARM:
      return &hitIndexRA_;
  }
}

byte* DrumSong::getPatternSequenceIndexPointer(byte limb) {
  switch (limb) {
    case RIGHT_LEG:
      return &patternSequenceIndexRL_;
    case LEFT_ARM:
      return &patternSequenceIndexLA_;
    case RIGHT_ARM:
      return &patternSequenceIndexRA_;
  }
}
