#ifndef Robo_song_h
#define Robo_song_h

#include <Array.h>

#include "Arduino.h"

#define MAX_NB_PATTERNS 5
#define MAX_NB_BEATS 100

#define BITS_FOR_HIT 1
#define BITS_PER_BYTE 8

#define HIT 1
#define REST 255

#define SEMIQUAVERS_PER_BEAT 16

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
#define V016 15


template <int NB_LIMBS, int BITS_FOR_POS>
class RoboSong {
 public:
  RoboSong();

  // Default patterns for the different songs. Empty method in the base class
  virtual void createPredefinedPatterns(byte rythmName, bool printOutput = false) = 0;
  void initializeBlankPatterns(unsigned int nbPatterns, unsigned int nbBeats);

  byte getPosNextHit(byte limb);
  byte getVelNextHit(byte limb);
  byte getSemiquaversToNextHit(byte limb);
  
  void goToNextSemiquaver(bool printOutput = 0);
  void goToFirstSemiquaver();
  void computeNextHit(byte limb, bool printOutput = false);

  void setQuarterHit(byte limb, byte pos, byte velocity, byte patternIndex, byte noteIndex, bool printOutput = false);
  void setQuaverHit(byte limb, byte pos, byte velocity, byte patternIndex, byte noteIndex, bool printOutput = false);
  void setSemiquaverHit(byte limb, byte pos, byte velocity, byte patternIndex, byte noteIndex, bool printOutput = false);
  void setHit(byte limb, byte pos, byte velocity, byte patternId, byte noteIndex, byte semiquaversPerNote, bool printOutput = false);

  void setQuarterRest(byte limb, byte patternIndex, byte noteIndex);
  void setQuaverRest(byte limb, byte patternIndex, byte noteIndex);
  void setSemiquaverRest(byte limb, byte patternIndex, byte noteIndex);
  void setRest(byte limb, byte patternId, byte noteIndex, byte semiquaversPerNote);

  void setHitPattern(byte limb, byte patternId, byte p1, byte p2, byte p3, byte p4, byte p5, byte p6, byte p7, byte p8, byte p9, byte p10, byte p11, byte p12, byte p13, byte p14, byte p15, byte p16, bool printOutput = false);
  void setVelPattern(byte limb, byte patternId, byte v1, byte v2, byte v3, byte v4, byte v5, byte v6, byte v7, byte v8, byte v9, byte v10, byte v11, byte v12, byte v13, byte v14, byte v15, byte v16, bool printOutput = false);
  void setPatternSequence(byte pattSeq[]);

  void printPatterns();
  void printPatterns(byte limb);
  void printPosPattern(byte limb, byte patternIndex);
  void printHitPattern(byte limb, byte patternIndex);
  void printVelPattern(byte limb, byte patternIndex);

 protected:
  byte nbOfPositions_[NB_LIMBS];
  byte nbPatterns_;
  byte nbBeats_;

 private:
  byte getPosFromNoteData(byte noteData);
  byte getVelFromNoteData(byte noteData);

  unsigned short bpm_;
  unsigned int timeSemiquaver_;

  signed char currSemiquaver_;
  unsigned char currSequenceIdx_;
  byte semiquaversToNextHit_[NB_LIMBS], nextPos_[NB_LIMBS], nextVel_[NB_LIMBS];

  signed char hitDirection_[NB_LIMBS];

  Array<byte, MAX_NB_BEATS> patternSequence_;

  Array<Array<byte[16], MAX_NB_PATTERNS>, NB_LIMBS> patternArrays_;

  uint8_t posMask_, velMask_;
  byte maxVel_;
};

#endif