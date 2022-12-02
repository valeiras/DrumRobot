#include "drum_song.h"

DrumSong::DrumSong() {
  hitIndexRL_ = -1;
  hitIndexLA_ = -1;
  hitIndexRA_ = -1;

  sequenceIndexRL_ = 0;
  sequenceIndexLA_ = 0;
  sequenceIndexRA_ = 0;

  posMask_ = B00000111;
}

void DrumSong::createPatterns(bool printOutput) {

}

void DrumSong::initializeBlankPatterns(unsigned int nbPatterns, unsigned int nbBeats) {
  nbPatterns_ = nbPatterns;
  nbBeats_ = nbBeats;

  for (int ii = 0; ii < nbPatterns_; ii++) {
    for (int jj = 0; jj < SEMIQUAVERS_PER_BEAT; jj++) {
      patternsRL_[ii][jj] = 0;
      patternsRA_[ii][jj] = 0;
      patternsLA_[ii][jj] = 0;
    }
  }

  for (int ii = 0; ii < nbBeats_; ii++) {
    patternSequence_[ii] = 0;
  }
}

unsigned long DrumSong::getTimeToNextHit(byte limb) {
  signed char* hitIndex = getHitIndexPointer(limb);
  byte* sequenceIndex = getSequenceIndexPointer(limb);

  // We get the current pattern
  byte patternId = patternSequence_[*sequenceIndex];
  byte* pattern = getPatternPointer(limb, patternId);

  unsigned long timeToNextInstruction = 0;

  do {
    // We iterate the pattern. When we get to the end we start again
    if (++(*hitIndex) >= SEMIQUAVERS_PER_BEAT) {
      *hitIndex = 0;
      *sequenceIndex = (*sequenceIndex + 1) % nbBeats_;
      patternId = patternSequence_[*sequenceIndex];
      pattern = getPatternPointer(limb, patternId);
    }
    timeToNextInstruction += timeSemiquaver_;
  } while (!bitRead(pattern[*hitIndex], 0));

  return timeToNextInstruction;
}

byte DrumSong::getPosNextHit(byte limb) {
  byte patternId;
  switch (limb) {
    case LEFT_ARM:
      patternId = patternSequence_[sequenceIndexLA_];
      return (patternsLA_[patternId][hitIndexLA_] >> BITS_FOR_HIT);
    case RIGHT_ARM:
      patternId = patternSequence_[sequenceIndexRA_];
      return (patternsRA_[patternId][hitIndexRA_] >> BITS_FOR_HIT);
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
  byte semiquaversPerNote = 4;
  setHit(limb, pos, patternId, noteIndex, semiquaversPerNote);
}

void DrumSong::setQuaverHit(byte limb, byte pos, byte patternId, byte noteIndex) {
  byte semiquaversPerNote = 4;
  setHit(limb, pos, patternId, noteIndex, semiquaversPerNote);
}

void DrumSong::setSemiquaverHit(byte limb, byte pos, byte patternId, byte noteIndex) {
  byte semiquaversPerNote = 4;
  setHit(limb, pos, patternId, noteIndex, semiquaversPerNote);
}

void DrumSong::setHit(byte limb, byte pos, byte patternId, byte noteIndex, byte semiquaversPerNote) {
  if (noteIndex > 0 && semiquaversPerNote * (noteIndex - 1) < SEMIQUAVERS_PER_BEAT && pos < getNumberOfPositions(limb) ) {
    byte* pattern = getPatternPointer(limb, patternId);
    byte* currElement = &pattern[semiquaversPerNote * (noteIndex - 1)];

    // We initialize the element
    *currElement = 0;

    // We set the first bit -> hit
    bitSet(*currElement, 0);

    // We set the position bits
    *currElement = *currElement | (pos << BITS_FOR_HIT);
  }
}

void DrumSong::setQuarterRest(byte limb, byte patternId, byte noteIndex) {
  byte semiquaversPerNote = 4;
  setRest(limb, patternId, noteIndex, semiquaversPerNote);
}

void DrumSong::setQuaverRest(byte limb, byte patternId, byte noteIndex) {
  byte semiquaversPerNote = 2;
  setRest(limb, patternId, noteIndex, semiquaversPerNote);
}

void DrumSong::setSemiquaverRest(byte limb, byte patternId, byte noteIndex) {
  byte semiquaversPerNote = 1;
  setRest(limb, patternId, noteIndex, semiquaversPerNote);
}

void DrumSong::setRest(byte limb, byte patternId, byte noteIndex, byte semiquaversPerNote) {
  if (noteIndex > 0 && semiquaversPerNote * (noteIndex - 1) < SEMIQUAVERS_PER_BEAT) {
    byte* pattern = getPatternPointer(limb, patternId);
    pattern[semiquaversPerNote * (noteIndex - 1)] = 0;
  }
}

void DrumSong::setHitPattern(byte limb, byte patternId, unsigned int inputPattern, bool printOutput) {
  byte* pattern = getPatternPointer(limb, patternId);

  if (patternId < nbPatterns_) {
    for (unsigned int ii = 0; ii < SEMIQUAVERS_PER_BEAT; ii++) {
      if (bitRead(inputPattern, ii)) {
        // We write the pattern from right to left
        bitSet(pattern[SEMIQUAVERS_PER_BEAT - 1 - ii], 0);
      }
    }
  }

  if (printOutput) {
    Serial.print("Hit pattern: ");
    for (unsigned int ii = 0; ii < SEMIQUAVERS_PER_BEAT; ii++) {
      Serial.print(bitRead(pattern[ii], 0));
    }
    Serial.println("");
    Serial.println("");
  }
}

void DrumSong::setPosPattern(byte limb, byte inputPattern[][SEMIQUAVERS_PER_BEAT], bool printOutput) {
  unsigned int nbPos = getNumberOfPositions(limb);

  Array<byte[16], MAX_NB_PATTERNS>* patternArray = getPatternArrayPointer(limb);

  if (printOutput) {
    Serial.println("");
    Serial.print("Setting pos pattern for limb :");
    Serial.println(limb);
  }

  for (int ii = 0; ii < nbPatterns_; ii++) {
    if (printOutput) {
      Serial.println("");
      Serial.print("Setting pos pattern ");
      Serial.println(ii);
    }

    for (int jj = 0; jj < SEMIQUAVERS_PER_BEAT; jj++) {
      if (inputPattern[ii][jj] < nbPos) {
        (*patternArray)[ii][jj] = (*patternArray)[ii][jj] | (inputPattern[ii][jj] << BITS_FOR_HIT);

        if (printOutput) {
          Serial.print(inputPattern[ii][jj]);
          Serial.print(" ");
        }
      }
      else {
        if (printOutput) {
          Serial.println("");
          Serial.println("Position out of bounds. Seeting 0");
          Serial.println("");
        }
        (*patternArray)[ii][jj] = 0;
      }
    }
    if (printOutput) {
      Serial.println("");
      Serial.print("Position pattern ");
      Serial.print(ii);
      Serial.print(" for limb ");
      Serial.print(limb);
      Serial.print(" right after: ");
      printPosPattern(limb, ii);
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
  if (limb != RIGHT_LEG && limb < _nbLimbs && patternId < nbPatterns_) {
    Serial.println("");
    Serial.print("Position pattern ");
    Serial.print(patternId);
    Serial.print(" for limb ");
    Serial.println(limb);
    byte* pattern = getPatternPointer(limb, patternId);
    for (unsigned int ii = 0; ii < SEMIQUAVERS_PER_BEAT; ii++) {
      Serial.print((pattern[ii] >> BITS_FOR_HIT) & posMask_);
      Serial.print(" ");
    }
    Serial.println("");
  }
}

void DrumSong::printHitPattern(byte limb, byte patternId) {
  if (limb < _nbLimbs && patternId < nbPatterns_) {
    Serial.println("");
    Serial.print("Hit pattern ");
    Serial.print(patternId);
    Serial.print(" for limb ");
    Serial.println(limb);
    byte* pattern = getPatternPointer(limb, patternId);
    for (unsigned int ii = 0; ii < SEMIQUAVERS_PER_BEAT; ii++) {
      Serial.print(bitRead(pattern[ii], 0));
      Serial.print(" ");
    }
    Serial.println("");
  }
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

byte* DrumSong::getPatternPointer(byte limb, byte patternId) {
  if (patternId < nbPatterns_) {
    switch (limb) {
      case RIGHT_LEG:
        return patternsRL_[patternId];
      case LEFT_ARM:
        return patternsLA_[patternId];
      case RIGHT_ARM:
        return patternsRA_[patternId];
    }
  }
  else {
    return errPosPattern_;
  }
}

Array<byte[16], MAX_NB_PATTERNS>* DrumSong::getPatternArrayPointer(byte limb) {
  switch (limb) {
    case RIGHT_LEG:
      return &patternsRL_;
    case LEFT_ARM:
      return &patternsLA_;
    case RIGHT_ARM:
      return &patternsRA_;
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

byte* DrumSong::getSequenceIndexPointer(byte limb) {
  switch (limb) {
    case RIGHT_LEG:
      return &sequenceIndexRL_;
    case LEFT_ARM:
      return &sequenceIndexLA_;
    case RIGHT_ARM:
      return &sequenceIndexRA_;
  }
}
