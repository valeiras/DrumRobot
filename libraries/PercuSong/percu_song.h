#ifndef Percu_song_h
#define Percu_song_h

#include <Array.h>

#include "Arduino.h"

#define MAX_NB_PATTERNS 5
#define MAX_NB_MEASURES 50

#define BITS_FOR_HIT 1
#define BITS_PER_BYTE 8

#define HIT 1
#define REST 255

#define SEMIQUAVERS_PER_MEASURE 16

#define V000 0
#define V001 1
#define V002 2
#define V003 3
#define V004 4
#define V005 5
#define V006 6
#define V007 7
#define V008 8
#define V009 9
#define V010 10
#define V011 11
#define V012 12
#define V013 13
#define V014 14
#define V015 15

template <int NB_LIMBS, int BITS_FOR_POS>
class PercuSong {
 public:
  PercuSong();

  // Default patterns for the different songs. Empty method in the base class
  virtual void createPredefinedPatterns(byte rythmName, bool hasOutput = false) = 0;
  void initializeBlankPatterns(unsigned int nbPatterns, unsigned int nbMeasures);

  byte getPosNextHit(byte limb);
  byte getVelNextHit(byte limb);
  byte getSemiquaversToNextHit(byte limb);

  void goToNextSemiquaver(bool hasOutput = 0);
  void goToFirstSemiquaver(bool hasOutput = 0);
  void computeNextHit(byte limb, bool hasOutput = false);

  void setQuarterHit(byte limb, byte pos, byte velocity, byte patternIndex, byte noteIndex, bool hasOutput = false);
  void setQuaverHit(byte limb, byte pos, byte velocity, byte patternIndex, byte noteIndex, bool hasOutput = false);
  void setSemiquaverHit(byte limb, byte pos, byte velocity, byte patternIndex, byte noteIndex, bool hasOutput = false);
  void setHit(byte limb, byte pos, byte velocity, byte patternId, byte noteIndex, byte semiquaversPerNote, bool hasOutput = false);

  void setQuarterRest(byte limb, byte patternIndex, byte noteIndex);
  void setQuaverRest(byte limb, byte patternIndex, byte noteIndex);
  void setSemiquaverRest(byte limb, byte patternIndex, byte noteIndex);
  void setRest(byte limb, byte patternId, byte noteIndex, byte semiquaversPerNote);

  void setHitPattern(byte limb, byte patternId, byte p1, byte p2, byte p3, byte p4, byte p5, byte p6, byte p7, byte p8, byte p9, byte p10, byte p11, byte p12, byte p13, byte p14, byte p15, byte p16, bool hasOutput = false);
  void setVelPattern(byte limb, byte patternId, byte v1, byte v2, byte v3, byte v4, byte v5, byte v6, byte v7, byte v8, byte v9, byte v10, byte v11, byte v12, byte v13, byte v14, byte v15, byte v16, bool hasOutput = false);
  void setPatternSequence(byte pattSeq[]);

  void printPatterns();
  void printPatterns(byte limb);
  void printPosPattern(byte limb, byte patternIndex);
  void printHitPattern(byte limb, byte patternIndex);
  void printVelPattern(byte limb, byte patternIndex);

 protected:
  byte nbOfPositions_[NB_LIMBS];
  byte nbPatterns_;
  byte nbMeasures_;

 private:
  byte getPosFromNoteData(byte noteData);
  byte getVelFromNoteData(byte noteData);

  unsigned short bpm_;
  unsigned int timeSemiquaver_;

  signed char currSemiquaver_[NB_LIMBS];
  unsigned char currSequenceIdx_[NB_LIMBS];
  byte semiquaversToNextHit_[NB_LIMBS], nextPos_[NB_LIMBS], nextVel_[NB_LIMBS];

  signed char hitDirection_[NB_LIMBS];

  Array<byte, MAX_NB_MEASURES> patternSequence_;

  Array<Array<byte[16], MAX_NB_PATTERNS>, NB_LIMBS> patternArrays_;

  uint8_t posMask_, velMask_;
  byte maxVel_;
};

template <int NB_LIMBS, int BITS_FOR_POS>
PercuSong<NB_LIMBS, BITS_FOR_POS>::PercuSong() {
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
void PercuSong<NB_LIMBS, BITS_FOR_POS>::initializeBlankPatterns(unsigned int nbPatterns, unsigned int nbMeasures) {
  nbPatterns_ = nbPatterns;
  nbMeasures_ = nbMeasures;

  for (int limb = 0; limb < NB_LIMBS; limb++) {
    for (int patternId = 0; patternId < nbPatterns_; patternId++) {
      byte* currPattern = patternArrays_[limb][patternId];
      for (int noteIndex = 0; noteIndex < SEMIQUAVERS_PER_MEASURE; noteIndex++) {
        currPattern[noteIndex] = 0;
      }
    }

    for (int ii = 0; ii < nbMeasures_; ii++) {
      patternSequence_[ii] = 0;
    }
  }
}

template <int NB_LIMBS, int BITS_FOR_POS>
byte PercuSong<NB_LIMBS, BITS_FOR_POS>::getPosNextHit(byte limb) {
  return nextPos_[limb];
}

template <int NB_LIMBS, int BITS_FOR_POS>
byte PercuSong<NB_LIMBS, BITS_FOR_POS>::getVelNextHit(byte limb) {
  return nextVel_[limb];
}

template <int NB_LIMBS, int BITS_FOR_POS>
byte PercuSong<NB_LIMBS, BITS_FOR_POS>::getSemiquaversToNextHit(byte limb) {
  return semiquaversToNextHit_[limb];
}

template <int NB_LIMBS, int BITS_FOR_POS>
void PercuSong<NB_LIMBS, BITS_FOR_POS>::goToNextSemiquaver(bool hasOutput) {
  for (unsigned int limb = 0; limb < NB_LIMBS; limb++) {
    if (--semiquaversToNextHit_[limb] < 0) {
      Serial.println("This should not be happening!");
    }
  }
}

template <int NB_LIMBS, int BITS_FOR_POS>
void PercuSong<NB_LIMBS, BITS_FOR_POS>::goToFirstSemiquaver(bool hasOutput) {
  for (unsigned int ii = 0; ii < NB_LIMBS; ii++) {
    semiquaversToNextHit_[ii] = 0;
    currSemiquaver_[ii] = -1;
    currSequenceIdx_[ii] = 0;
  }

  for (unsigned int limb = 0; limb < NB_LIMBS; limb++) {
    computeNextHit(limb, hasOutput);
    // We substract one, to compensate for the fact that we started from -1
    semiquaversToNextHit_[limb]--;
  }
}

template <int NB_LIMBS, int BITS_FOR_POS>
void PercuSong<NB_LIMBS, BITS_FOR_POS>::computeNextHit(byte limb, bool hasOutput = false) {
  signed char semiquaver = currSemiquaver_[limb];
  unsigned char sequenceIdx = currSequenceIdx_[limb];

  // We get the current pattern
  byte patternId = patternSequence_[sequenceIdx];
  byte* currPattern = patternArrays_[limb][patternId];

  do {
    // We iterate the pattern. When we get to the end we start again
    if (++semiquaver >= SEMIQUAVERS_PER_MEASURE) {
      semiquaver = 0;
      sequenceIdx = (sequenceIdx + 1) % nbMeasures_;
      patternId = patternSequence_[sequenceIdx];
      currPattern = patternArrays_[limb][patternId];
    }
    semiquaversToNextHit_[limb]++;

  } while (!bitRead(currPattern[semiquaver], 0));

  nextPos_[limb] = getPosFromNoteData(currPattern[semiquaver]);
  nextVel_[limb] = getVelFromNoteData(currPattern[semiquaver]);

  currSemiquaver_[limb] = semiquaver;
  currSequenceIdx_[limb] = sequenceIdx;
}

template <int NB_LIMBS, int BITS_FOR_POS>
void PercuSong<NB_LIMBS, BITS_FOR_POS>::setQuarterHit(byte limb, byte pos, byte velocity, byte patternId, byte noteIndex, bool hasOutput) {
  byte semiquaversPerQuarter = 4;
  setHit(limb, pos, velocity, patternId, noteIndex, semiquaversPerQuarter, hasOutput);
}

template <int NB_LIMBS, int BITS_FOR_POS>
void PercuSong<NB_LIMBS, BITS_FOR_POS>::setQuaverHit(byte limb, byte pos, byte velocity, byte patternId, byte noteIndex, bool hasOutput) {
  byte semiquaversPerQuaver = 2;
  setHit(limb, pos, velocity, patternId, noteIndex, semiquaversPerQuaver, hasOutput);
}

template <int NB_LIMBS, int BITS_FOR_POS>
void PercuSong<NB_LIMBS, BITS_FOR_POS>::setSemiquaverHit(byte limb, byte pos, byte velocity, byte patternId, byte noteIndex, bool hasOutput) {
  byte semiquaversPerSemiquaver = 1;
  setHit(limb, pos, velocity, patternId, noteIndex, semiquaversPerSemiquaver, hasOutput);
}

template <int NB_LIMBS, int BITS_FOR_POS>
void PercuSong<NB_LIMBS, BITS_FOR_POS>::setHit(byte limb, byte pos, byte vel, byte patternId, byte noteIndex, byte semiquaversPerNote, bool hasOutput) {
  if (noteIndex > 0 && semiquaversPerNote * (noteIndex - 1) < SEMIQUAVERS_PER_MEASURE && pos < nbOfPositions_[limb]) {
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
void PercuSong<NB_LIMBS, BITS_FOR_POS>::setQuarterRest(byte limb, byte patternId, byte noteIndex) {
  byte semiquaversPerQuarter = 4;
  setRest(limb, patternId, noteIndex, semiquaversPerQuarter);
}

template <int NB_LIMBS, int BITS_FOR_POS>
void PercuSong<NB_LIMBS, BITS_FOR_POS>::setQuaverRest(byte limb, byte patternId, byte noteIndex) {
  byte semiquaversPerQuaver = 2;
  setRest(limb, patternId, noteIndex, semiquaversPerQuaver);
}

template <int NB_LIMBS, int BITS_FOR_POS>
void PercuSong<NB_LIMBS, BITS_FOR_POS>::setSemiquaverRest(byte limb, byte patternId, byte noteIndex) {
  byte semiquaversPerSemiquaver = 1;
  setRest(limb, patternId, noteIndex, semiquaversPerSemiquaver);
}

template <int NB_LIMBS, int BITS_FOR_POS>
void PercuSong<NB_LIMBS, BITS_FOR_POS>::setRest(byte limb, byte patternId, byte noteIndex, byte semiquaversPerNote) {
  if (noteIndex > 0 && semiquaversPerNote * (noteIndex - 1) < SEMIQUAVERS_PER_MEASURE) {
    byte* currPattern = patternArrays_[limb][patternId];
    currPattern[semiquaversPerNote * (noteIndex - 1)] = 0;
  }
}

template <int NB_LIMBS, int BITS_FOR_POS>
void PercuSong<NB_LIMBS, BITS_FOR_POS>::setHitPattern(byte limb, byte patternId, byte p1, byte p2, byte p3, byte p4, byte p5, byte p6, byte p7,
                                                      byte p8, byte p9, byte p10, byte p11, byte p12, byte p13, byte p14, byte p15, byte p16, bool hasOutput = false) {
  unsigned int nbPos = nbOfPositions_[limb];
  byte* currPattern = patternArrays_[limb][patternId];
  byte inputPattern[SEMIQUAVERS_PER_MEASURE] = {p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16};

  for (int ii = 0; ii < SEMIQUAVERS_PER_MEASURE; ii++) {
    // We reinitialize the element:
    currPattern[ii] = 0;

    if (inputPattern[ii] != REST && inputPattern[ii] <= nbPos) {
      bitSet(currPattern[ii], 0);

      // We substract 1 to the position, because we reserve 0 for the rest => we add one to make it different
      currPattern[ii] = currPattern[ii] | (inputPattern[ii] << BITS_FOR_HIT);
    }
  }
}

template <int NB_LIMBS, int BITS_FOR_POS>
void PercuSong<NB_LIMBS, BITS_FOR_POS>::setVelPattern(byte limb, byte patternId, byte v1, byte v2, byte v3, byte v4, byte v5, byte v6, byte v7, byte v8, byte v9, byte v10, byte v11, byte v12, byte v13, byte v14, byte v15, byte v16, bool hasOutput = false) {
  unsigned int nbPos = nbOfPositions_[limb];
  byte* currPattern = patternArrays_[limb][patternId];
  byte inputPattern[SEMIQUAVERS_PER_MEASURE] = {v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16};

  for (int ii = 0; ii < SEMIQUAVERS_PER_MEASURE; ii++) {
    currPattern[ii] = currPattern[ii] | (min(inputPattern[ii], maxVel_) << BITS_FOR_HIT + BITS_FOR_POS);
  }
}

template <int NB_LIMBS, int BITS_FOR_POS>
void PercuSong<NB_LIMBS, BITS_FOR_POS>::setPatternSequence(byte pattSeq[]) {
  for (int ii = 0; ii < nbMeasures_; ii++) {
    if (pattSeq[ii] < nbPatterns_) {
      patternSequence_.push_back(pattSeq[ii]);
    } else {
      patternSequence_.push_back(0);
    }
  }
}

template <int NB_LIMBS, int BITS_FOR_POS>
void PercuSong<NB_LIMBS, BITS_FOR_POS>::printPatterns() {
  for (unsigned int ii = 0; ii < NB_LIMBS; ii++) {
    printPatterns(ii);
  }
}

template <int NB_LIMBS, int BITS_FOR_POS>
void PercuSong<NB_LIMBS, BITS_FOR_POS>::printPatterns(byte limb) {
  for (unsigned int ii = 0; ii < nbPatterns_; ii++) {
    printHitPattern(limb, ii);
    printPosPattern(limb, ii);
    printVelPattern(limb, ii);
  }
}

template <int NB_LIMBS, int BITS_FOR_POS>
void PercuSong<NB_LIMBS, BITS_FOR_POS>::printHitPattern(byte limb, byte patternId) {
  if (limb < NB_LIMBS && patternId < nbPatterns_) {
    Serial.println("");
    Serial.print("Hit pattern ");
    Serial.print(patternId);
    Serial.print(" for limb ");
    Serial.println(limb);

    byte* currPattern = patternArrays_[limb][patternId];
    for (unsigned int ii = 0; ii < SEMIQUAVERS_PER_MEASURE; ii++) {
      Serial.print(bitRead(currPattern[ii], 0));
      Serial.print(" ");
    }
    Serial.println("");
  }
}

template <int NB_LIMBS, int BITS_FOR_POS>
void PercuSong<NB_LIMBS, BITS_FOR_POS>::printPosPattern(byte limb, byte patternId) {
  if (limb < NB_LIMBS && patternId < nbPatterns_) {
    Serial.println("");
    Serial.print("Position pattern ");
    Serial.print(patternId);
    Serial.print(" for limb ");
    Serial.println(limb);

    byte* currPattern = patternArrays_[limb][patternId];
    for (unsigned int ii = 0; ii < SEMIQUAVERS_PER_MEASURE; ii++) {
      Serial.print((currPattern[ii] & posMask_) >> BITS_FOR_HIT);
      Serial.print(" ");
    }
    Serial.println("");
  }
}

template <int NB_LIMBS, int BITS_FOR_POS>
void PercuSong<NB_LIMBS, BITS_FOR_POS>::printVelPattern(byte limb, byte patternId) {
  if (limb < NB_LIMBS && patternId < nbPatterns_) {
    Serial.println("");
    Serial.print("Velocity pattern ");
    Serial.print(patternId);
    Serial.print(" for limb ");
    Serial.println(limb);

    byte* currPattern = patternArrays_[limb][patternId];
    for (unsigned int ii = 0; ii < SEMIQUAVERS_PER_MEASURE; ii++) {
      Serial.print((currPattern[ii] & velMask_) >> BITS_FOR_HIT + BITS_FOR_POS);
      Serial.print(" ");
    }
    Serial.println("");
  }
}
template <int NB_LIMBS, int BITS_FOR_POS>
byte PercuSong<NB_LIMBS, BITS_FOR_POS>::getPosFromNoteData(byte noteData) {
  return ((noteData & posMask_) >> BITS_FOR_HIT);
}

template <int NB_LIMBS, int BITS_FOR_POS>
byte PercuSong<NB_LIMBS, BITS_FOR_POS>::getVelFromNoteData(byte noteData) {
  return ((noteData & velMask_) >> BITS_FOR_HIT + BITS_FOR_POS);
}

#endif