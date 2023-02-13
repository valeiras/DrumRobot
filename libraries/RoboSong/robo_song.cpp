#include "robo_song.h"

template <int NB_LIMBS, int BITS_FOR_POS>
RoboSong<NB_LIMBS, BITS_FOR_POS>::RoboSong() {
  for (unsigned int ii = 0; ii < NB_LIMBS; ii++) {
    semiquaversToNextHit_[ii] = 0;
    currSemiquaver_[ii] = -1;
    currSequenceIdx_[ii] = 0;
  }

  posMask_ = 0;
  velMask_ = 0;

  for (unsigned int ii = BITS_FOR_HIT; ii < BITS_FOR_HIT + BITS_FOR_POS; ii++) {
    bitSet(posMask_, ii);
  }

  for (unsigned int ii = BITS_FOR_HIT + BITS_FOR_POS; ii < BITS_PER_BYTE; ii++) {
    bitSet(velMask_, ii);
  }

  unsigned int bitsForVel = BITS_PER_BYTE - (BITS_FOR_HIT + BITS_FOR_POS);
  maxVel_ = pow(2, bitsForVel) - 1;
}

template <int NB_LIMBS, int BITS_FOR_POS>
void RoboSong<NB_LIMBS, BITS_FOR_POS>::initializeBlankPatterns(unsigned int nbPatterns, unsigned int nbBeats) {
  nbPatterns_ = nbPatterns;
  nbBeats_ = nbBeats;

  for (int limb = 0; limb < NB_LIMBS; limb++) {
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

template <int NB_LIMBS, int BITS_FOR_POS>
byte RoboSong<NB_LIMBS, BITS_FOR_POS>::getPosNextHit(byte limb) {
  return nextPos_[limb];
}

template <int NB_LIMBS, int BITS_FOR_POS>
byte RoboSong<NB_LIMBS, BITS_FOR_POS>::getVelNextHit(byte limb) {
  return nextVel_[limb];
}

template <int NB_LIMBS, int BITS_FOR_POS>
byte RoboSong<NB_LIMBS, BITS_FOR_POS>::getSemiquaversToNextHit(byte limb) {
  return semiquaversToNextHit_[limb];
}

template <int NB_LIMBS, int BITS_FOR_POS>
void RoboSong<NB_LIMBS, BITS_FOR_POS>::goToNextSemiquaver(bool printOutput) {
  for (unsigned int limb = 0; limb < NB_LIMBS; limb++) {
    if (printOutput) {
      Serial.print("Limb ");
      Serial.print(limb);
      Serial.print(" : ");
      Serial.print(semiquaversToNextHit_[limb] - 1);
      Serial.println(" semiquavers to next hit");
    }
    if (--semiquaversToNextHit_[limb] < 0) {
      Serial.println("This should not be happening!");
    }
  }
}

template <int NB_LIMBS, int BITS_FOR_POS>
void RoboSong<NB_LIMBS, BITS_FOR_POS>::goToFirstSemiquaver(bool printOutput) {
  if (printOutput) {
    Serial.print("Going to first semiquaver. Nb of limbs: ");
    Serial.println(NB_LIMBS);
  }

  for (unsigned int ii = 0; ii < NB_LIMBS; ii++) {
   if(printOutput){
      Serial.print("initalizing limb ");
      Serial.println(ii);
   }
    semiquaversToNextHit_[ii] = 0;
    currSemiquaver_[ii] = -1;
    currSequenceIdx_[ii] = 0;
  }

  for (unsigned int limb = 0; limb < NB_LIMBS; limb++) {
    computeNextHit(limb, printOutput);
    // We substract one, to compensate for the fact that we started from -1
    semiquaversToNextHit_[limb]--;
    if (printOutput) {
      Serial.print("Limb: ");
      Serial.print(limb);
      Serial.print(", semiquavers to next hit = ");
      Serial.println(semiquaversToNextHit_[limb]);
    }
  }
}

template <int NB_LIMBS, int BITS_FOR_POS>
void RoboSong<NB_LIMBS, BITS_FOR_POS>::computeNextHit(byte limb, bool printOutput = false) {
  signed char semiquaver = currSemiquaver_[limb];
  unsigned char sequenceIdx = currSequenceIdx_[limb];
  if(printOutput){
    Serial.print("Limb: ");
    Serial.print(limb);
    Serial.print(", Initial semiquaver: ");
    Serial.print(currSemiquaver_[limb]);
    Serial.print("Initial sequence index: ");
    Serial.println(sequenceIdx);
  }

  // We get the current pattern
  byte patternId = patternSequence_[sequenceIdx];
  byte* currPattern = patternArrays_[limb][patternId];

  do {
    // We iterate the pattern. When we get to the end we start again
    if (++semiquaver >= SEMIQUAVERS_PER_BEAT) {
      semiquaver = 0;
      sequenceIdx = (sequenceIdx + 1) % nbBeats_;
      patternId = patternSequence_[sequenceIdx];
      currPattern = patternArrays_[limb][patternId];
    }
    semiquaversToNextHit_[limb]++;

  } while (!bitRead(currPattern[semiquaver], 0));

  nextPos_[limb] = getPosFromNoteData(currPattern[semiquaver]);
  nextVel_[limb] = getVelFromNoteData(currPattern[semiquaver]);

  currSemiquaver_[limb] = semiquaver;
  currSequenceIdx_[limb] = sequenceIdx;

  if (printOutput) {
    Serial.print("Next hit for limb ");
    Serial.print(limb);
    Serial.print(" occurs at pattern ");
    Serial.print(sequenceIdx);
    Serial.print(" and semiquaver ");
    Serial.println(semiquaver);
    Serial.print("The corresponding position is: ");
    Serial.println(nextPos_[limb]);
  }
}

template <int NB_LIMBS, int BITS_FOR_POS>
void RoboSong<NB_LIMBS, BITS_FOR_POS>::setQuarterHit(byte limb, byte pos, byte velocity, byte patternId, byte noteIndex, bool printOutput) {
  byte semiquaversPerQuarter = 4;
  setHit(limb, pos, velocity, patternId, noteIndex, semiquaversPerQuarter, printOutput);
}

template <int NB_LIMBS, int BITS_FOR_POS>
void RoboSong<NB_LIMBS, BITS_FOR_POS>::setQuaverHit(byte limb, byte pos, byte velocity, byte patternId, byte noteIndex, bool printOutput) {
  byte semiquaversPerQuaver = 2;
  setHit(limb, pos, velocity, patternId, noteIndex, semiquaversPerQuaver, printOutput);
}

template <int NB_LIMBS, int BITS_FOR_POS>
void RoboSong<NB_LIMBS, BITS_FOR_POS>::setSemiquaverHit(byte limb, byte pos, byte velocity, byte patternId, byte noteIndex, bool printOutput) {
  byte semiquaversPerSemiquaver = 1;
  setHit(limb, pos, velocity, patternId, noteIndex, semiquaversPerSemiquaver, printOutput);
}

template <int NB_LIMBS, int BITS_FOR_POS>
void RoboSong<NB_LIMBS, BITS_FOR_POS>::setHit(byte limb, byte pos, byte vel, byte patternId, byte noteIndex, byte semiquaversPerNote, bool printOutput) {
  if (noteIndex > 0 && semiquaversPerNote * (noteIndex - 1) < SEMIQUAVERS_PER_BEAT && pos < nbOfPositions_[limb]) {
    // We get the current pattern
    byte* currPattern = patternArrays_[limb][patternId];
    byte* currElement = &currPattern[semiquaversPerNote * (noteIndex - 1)];

    // We initialize the element
    *currElement = 0;

    // We set the first bit -> hit
    bitSet(*currElement, 0);

    // We set the position bits
    *currElement = *currElement | (pos << BITS_FOR_HIT);

    // We set the velocity bits
    *currElement = *currElement | (min(vel, maxVel_) << BITS_FOR_HIT + BITS_FOR_POS);
  } else {
    Serial.println("Index out of bounds");
  }
}

template <int NB_LIMBS, int BITS_FOR_POS>
void RoboSong<NB_LIMBS, BITS_FOR_POS>::setQuarterRest(byte limb, byte patternId, byte noteIndex) {
  byte semiquaversPerQuarter = 4;
  setRest(limb, patternId, noteIndex, semiquaversPerQuarter);
}

template <int NB_LIMBS, int BITS_FOR_POS>
void RoboSong<NB_LIMBS, BITS_FOR_POS>::setQuaverRest(byte limb, byte patternId, byte noteIndex) {
  byte semiquaversPerQuaver = 2;
  setRest(limb, patternId, noteIndex, semiquaversPerQuaver);
}

template <int NB_LIMBS, int BITS_FOR_POS>
void RoboSong<NB_LIMBS, BITS_FOR_POS>::setSemiquaverRest(byte limb, byte patternId, byte noteIndex) {
  byte semiquaversPerSemiquaver = 1;
  setRest(limb, patternId, noteIndex, semiquaversPerSemiquaver);
}

template <int NB_LIMBS, int BITS_FOR_POS>
void RoboSong<NB_LIMBS, BITS_FOR_POS>::setRest(byte limb, byte patternId, byte noteIndex, byte semiquaversPerNote) {
  if (noteIndex > 0 && semiquaversPerNote * (noteIndex - 1) < SEMIQUAVERS_PER_BEAT) {
    byte* currPattern = patternArrays_[limb][patternId];
    currPattern[semiquaversPerNote * (noteIndex - 1)] = 0;
  }
}

template <int NB_LIMBS, int BITS_FOR_POS>
void RoboSong<NB_LIMBS, BITS_FOR_POS>::setHitPattern(byte limb, byte patternId, byte p1, byte p2, byte p3, byte p4, byte p5, byte p6, byte p7,
                                                     byte p8, byte p9, byte p10, byte p11, byte p12, byte p13, byte p14, byte p15, byte p16, bool printOutput = false) {
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
    // We reinitialize the element:
    currPattern[ii] = 0;

    if (inputPattern[ii] != REST && inputPattern[ii] <= nbPos) {
      bitSet(currPattern[ii], 0);

      // We substract 1 to the position, because we reserve 0 for the rest => we add one to make it different
      currPattern[ii] = currPattern[ii] | (inputPattern[ii] << BITS_FOR_HIT);
    }
    if (printOutput) {
      Serial.print(inputPattern[ii]);
      Serial.print(" ");
    }
  }
}

template <int NB_LIMBS, int BITS_FOR_POS>
void RoboSong<NB_LIMBS, BITS_FOR_POS>::setVelPattern(byte limb, byte patternId, byte v1, byte v2, byte v3, byte v4, byte v5, byte v6, byte v7, byte v8, byte v9, byte v10, byte v11, byte v12, byte v13, byte v14, byte v15, byte v16, bool printOutput = false) {
  unsigned int nbPos = nbOfPositions_[limb];
  byte* currPattern = patternArrays_[limb][patternId];
  byte inputPattern[SEMIQUAVERS_PER_BEAT] = {v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16};

  if (printOutput) {
    Serial.println("");
    Serial.print("Setting velocity pattern ");
    Serial.print(patternId);
    Serial.print(" for limb ");
    Serial.println(limb);
  }

  for (int ii = 0; ii < SEMIQUAVERS_PER_BEAT; ii++) {
    currPattern[ii] = currPattern[ii] | (min(inputPattern[ii], maxVel_) << BITS_FOR_HIT + BITS_FOR_POS);

    if (printOutput) {
      Serial.print(inputPattern[ii]);
      Serial.print(" ");
    }
  }
}

template <int NB_LIMBS, int BITS_FOR_POS>
void RoboSong<NB_LIMBS, BITS_FOR_POS>::setPatternSequence(byte pattSeq[]) {
  for (int ii = 0; ii < nbBeats_; ii++) {
    if (pattSeq[ii] < nbPatterns_) {
      patternSequence_.push_back(pattSeq[ii]);
    } else {
      patternSequence_.push_back(0);
    }
  }
}

template <int NB_LIMBS, int BITS_FOR_POS>
void RoboSong<NB_LIMBS, BITS_FOR_POS>::printPatterns() {
  for (unsigned int ii = 0; ii < NB_LIMBS; ii++) {
    printPatterns(ii);
  }
}

template <int NB_LIMBS, int BITS_FOR_POS>
void RoboSong<NB_LIMBS, BITS_FOR_POS>::printPatterns(byte limb) {
  for (unsigned int ii = 0; ii < nbPatterns_; ii++) {
    printHitPattern(limb, ii);
    printPosPattern(limb, ii);
    printVelPattern(limb, ii);
  }
}

template <int NB_LIMBS, int BITS_FOR_POS>
void RoboSong<NB_LIMBS, BITS_FOR_POS>::printHitPattern(byte limb, byte patternId) {
  if (limb < NB_LIMBS && patternId < nbPatterns_) {
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

template <int NB_LIMBS, int BITS_FOR_POS>
void RoboSong<NB_LIMBS, BITS_FOR_POS>::printPosPattern(byte limb, byte patternId) {
  if (limb < NB_LIMBS && patternId < nbPatterns_) {
    Serial.println("");
    Serial.print("Position pattern ");
    Serial.print(patternId);
    Serial.print(" for limb ");
    Serial.println(limb);

    byte* currPattern = patternArrays_[limb][patternId];
    for (unsigned int ii = 0; ii < SEMIQUAVERS_PER_BEAT; ii++) {
      Serial.print((currPattern[ii] & posMask_) >> BITS_FOR_HIT);
      Serial.print(" ");
    }
    Serial.println("");
  }
}

template <int NB_LIMBS, int BITS_FOR_POS>
void RoboSong<NB_LIMBS, BITS_FOR_POS>::printVelPattern(byte limb, byte patternId) {
  if (limb < NB_LIMBS && patternId < nbPatterns_) {
    Serial.println("");
    Serial.print("Velocity pattern ");
    Serial.print(patternId);
    Serial.print(" for limb ");
    Serial.println(limb);

    byte* currPattern = patternArrays_[limb][patternId];
    for (unsigned int ii = 0; ii < SEMIQUAVERS_PER_BEAT; ii++) {
      Serial.print((currPattern[ii] & velMask_) >> BITS_FOR_HIT + BITS_FOR_POS);
      Serial.print(" ");
    }
    Serial.println("");
  }
}
template <int NB_LIMBS, int BITS_FOR_POS>
byte RoboSong<NB_LIMBS, BITS_FOR_POS>::getPosFromNoteData(byte noteData) {
  return ((noteData & posMask_) >> BITS_FOR_HIT);
}

template <int NB_LIMBS, int BITS_FOR_POS>
byte RoboSong<NB_LIMBS, BITS_FOR_POS>::getVelFromNoteData(byte noteData) {
  return ((noteData & velMask_) >> BITS_FOR_HIT + BITS_FOR_POS);
}

// We need to tell the compiler to compile the required templates. This can also be achieved by
// putting all the implementation on the header file, but we have decided to allow only tested versions
// of the RoboSong<NB_LIMBS, BITS_FOR_HIT, BITS_FOR_POS>

// DrumSong:
template class RoboSong<4, 3>;

// GlockenSong:
template class RoboSong<2, 4>;

template class RoboSong<3, 5>;