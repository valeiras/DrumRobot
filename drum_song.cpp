#include "drum_song.h"

DrumSong::DrumSong() {
  for (unsigned int ii = 0; ii < _nbLimbs; ii++) {
    hitIndexes_[ii] = -1;
    sequenceIndexes_[ii] = 0;
  }

  posMask_ = B00000111;
  nbOfPositions_[0] = _nbPosRightLeg;
  nbOfPositions_[1] = _nbPosLeftArm;
  nbOfPositions_[2] = _nbPosRightArm;
}

void DrumSong::createPatterns(bool printOutput) {

}

void DrumSong::createPredefinedPatterns(byte rythmName, bool printOutput = false) {
  switch (rythmName) {
    // -------------------------------------------- SIMPLEST RYTHM -----------------------------------------------------
    case SIMPLEST_RYTHM:
    default:
      {
        if (printOutput) {
          Serial.println("simplest rythm");
        }
        nbPatterns_ = 1;
        nbBeats_ = 1;
        initializeBlankPatterns(nbPatterns_, nbBeats_);

        byte patternId = 0;

        setHitPattern(RIGHT_LEG, patternId, 0b1000000010000000, printOutput);
        setHitPattern(LEFT_ARM,  patternId, 0b1010101010101010, printOutput);
        setHitPattern(RIGHT_ARM, patternId, 0b0010000000100000, printOutput);

        setPosPattern(LEFT_ARM, patternId, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, printOutput);
        setPosPattern(RIGHT_ARM, patternId, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, printOutput);

        byte simplestPattSeq[nbBeats_] = {0};
        setPatternSequence(simplestPattSeq);

        break;
      }
    case BASIC_RYTHM:
      {
        // -------------------------------------------- BASIC RYTHM -----------------------------------------------------
        if (printOutput) {
          Serial.println("Basic rythm");
        }
        nbPatterns_ = 3;
        nbBeats_ = 10;

        byte patternId0 = 0;
        byte patternId1 = 1;
        byte patternId2 = 2;

        // Right leg
        setHitPattern(RIGHT_LEG, patternId0, 0b0000000000000000, printOutput);
        setHitPattern(RIGHT_LEG, patternId1, 0b1000000010100000, printOutput);
        setHitPattern(RIGHT_LEG, patternId2, 0b1000000010100000, printOutput);

        // Left arm
        setHitPattern(LEFT_ARM, patternId0,  0b1000100010001000, printOutput);
        setHitPattern(LEFT_ARM, patternId1,  0b1010101010101010, printOutput);
        setHitPattern(LEFT_ARM, patternId2,  0b1010101010100101, printOutput);

        if (printOutput) {
          Serial.println("Setting pos pattern from basic rythm");
        }
        setPosPattern(LEFT_ARM, patternId0, STICK, 0, 0, 0, STICK, 0, 0, 0, STICK, 0, 0, 0, STICK, 0, 0, 0, printOutput);
        setPosPattern(LEFT_ARM, patternId1, HH, 0, HH, 0, HH, 0, HH, 0, HH, 0, HH, 0, HH, 0, HH, 0, printOutput);
        setPosPattern(LEFT_ARM, patternId2, HH, 0, HH, 0, HH, 0, HH, 0, HH, 0, HH, 0, 0, SN_LEFT, 0, SN_LEFT, printOutput);

        // Right arm
        setHitPattern(RIGHT_ARM, patternId0, 0b1000100010001000, printOutput);
        setHitPattern(RIGHT_ARM, patternId1, 0b1000100100001000, printOutput);
        setHitPattern(RIGHT_ARM, patternId2, 0b0000100100001010, printOutput);

        setPosPattern(RIGHT_ARM, patternId0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, printOutput);
        setPosPattern(RIGHT_ARM, patternId1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, printOutput);
        setPosPattern(RIGHT_ARM, patternId2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, printOutput);

        byte basicPattSeq[nbBeats_] = {0, 1, 2, 1, 2, 1, 2, 1, 2, 1};

        setPatternSequence(basicPattSeq);
        break;
      }
  }
}

void DrumSong::initializeBlankPatterns(unsigned int nbPatterns, unsigned int nbBeats) {
  nbPatterns_ = nbPatterns;
  nbBeats_ = nbBeats;

  for (int limb = 0; limb < _nbLimbs; limb++) {
    for (int patternId = 0; patternId < nbPatterns_; patternId++) {
      byte* currPattern = patternArrays_[limb][patternId];
      for (int noteIndex = 0; noteIndex < SEMIQUAVERS_PER_BEAT; noteIndex++) {
        currPattern[noteIndex] = 0;
      }
    }

    for (int ii = 0; ii < nbBeats_; ii++) {
      patternSequence_[ii] = 0;
    }
  }
}

unsigned long DrumSong::getTimeToNextHit(byte limb, bool printOutput) {
  signed char* hitIndex = &hitIndexes_[limb];
  byte * sequenceIndex = &sequenceIndexes_[limb];

  // We get the current pattern
  byte patternId = patternSequence_[*sequenceIndex];
  byte* currPattern = patternArrays_[limb][patternId];

  unsigned long timeToNextInstruction = 0;

  do {
    // We iterate the pattern. When we get to the end we start again
    if (++(*hitIndex) >= SEMIQUAVERS_PER_BEAT) {
      *hitIndex = 0;
      *sequenceIndex = (*sequenceIndex + 1) % nbBeats_;
      patternId = patternSequence_[*sequenceIndex];
      currPattern = patternArrays_[limb][patternId];
    }
    timeToNextInstruction += timeSemiquaver_;
  } while (!bitRead(currPattern[*hitIndex], 0));

  return timeToNextInstruction;
}

byte DrumSong::getPosNextHit(byte limb, bool printOutput) {
  byte sequenceIndex = sequenceIndexes_[limb];
  byte patternId = patternSequence_[sequenceIndex];
  byte* currPattern = patternArrays_[limb][patternId];

  unsigned char hitIndex =  hitIndexes_[limb];
  return (currPattern[hitIndex] >> BITS_FOR_HIT);
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
  if (noteIndex > 0 && semiquaversPerNote * (noteIndex - 1) < SEMIQUAVERS_PER_BEAT && pos < nbOfPositions_[limb] ) {
    // We get the current pattern
    byte* currPattern = patternArrays_[limb][patternId];
    byte* currElement = &currPattern[semiquaversPerNote * (noteIndex - 1)];

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
    byte* currPattern = patternArrays_[limb][patternId];
    currPattern[semiquaversPerNote * (noteIndex - 1)] = 0;
  }
}

void DrumSong::setHitPattern(byte limb, byte patternId, unsigned int inputPattern, bool printOutput) {
  byte* currPattern = patternArrays_[limb][patternId];

  if (patternId < nbPatterns_) {
    for (unsigned int ii = 0; ii < SEMIQUAVERS_PER_BEAT; ii++) {
      if (bitRead(inputPattern, ii)) {
        // We write the pattern from right to left
        bitSet(currPattern[SEMIQUAVERS_PER_BEAT - 1 - ii], 0);
      }
    }
  }

  if (printOutput) {
    Serial.print("Hit pattern: ");
    for (unsigned int ii = 0; ii < SEMIQUAVERS_PER_BEAT; ii++) {
      Serial.print(bitRead(currPattern[ii], 0));
    }
    Serial.println("");
    Serial.println("");
  }
}

void DrumSong::setPosPattern(byte limb, byte patternId, byte p1, byte p2, byte p3, byte p4, byte p5, byte p6, byte p7, byte p8, byte p9, byte p10, byte p11, byte p12, byte p13, byte p14, byte p15, byte p16, bool printOutput) {
  unsigned int nbPos = nbOfPositions_[limb];
  byte* currPattern = patternArrays_[limb][patternId];
  byte inputPattern[SEMIQUAVERS_PER_BEAT] = {p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16};

  if (printOutput) {
    Serial.println("");
    Serial.print("Setting pos pattern ");
    Serial.print(patternId);
    Serial.print(" for limb ");
    Serial.println(limb);
  }

  for (int ii = 0; ii < SEMIQUAVERS_PER_BEAT; ii++) {
    if (inputPattern[ii] < nbPos) {
      currPattern[ii] = currPattern[ii] | (inputPattern[ii] << BITS_FOR_HIT);

      if (printOutput) {
        Serial.print(inputPattern[ii]);
        Serial.print(" ");
      }
    }
    else {
      if (printOutput) {
        Serial.println("");
        Serial.println("Position out of bounds. Seeting 0");
        Serial.println("");
      }
      currPattern[ii] = 0;
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
  if (limb < _nbLimbs && patternId < nbPatterns_) {
    Serial.println("");
    Serial.print("Position pattern ");
    Serial.print(patternId);
    Serial.print(" for limb ");
    Serial.println(limb);
    byte* currPattern = patternArrays_[limb][patternId];
    for (unsigned int ii = 0; ii < SEMIQUAVERS_PER_BEAT; ii++) {
      Serial.print((currPattern[ii] >> BITS_FOR_HIT) & posMask_);
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
    byte* currPattern = patternArrays_[limb][patternId];
    for (unsigned int ii = 0; ii < SEMIQUAVERS_PER_BEAT; ii++) {
      Serial.print(bitRead(currPattern[ii], 0));
      Serial.print(" ");
    }
    Serial.println("");
  }
}
