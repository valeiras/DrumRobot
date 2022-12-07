#ifndef Drum_song_h
#define Drum_song_h

#include "Arduino.h"
#include "drum_robot.h"
#include <Array.h>

#define MAX_NB_PATTERNS 5
#define MAX_NB_BEATS 100
#define SEMIQUAVERS_PER_BEAT 16

#define BITS_FOR_HIT 1
#define BITS_FOR_POS 3

#define SIMPLEST_RYTHM 0
#define BASIC_RYTHM 1

class DrumSong {
  public:
    DrumSong();

    // Default patterns for the different songs. Empty method in the base class
    virtual void createPatterns(bool printOutput=false);

    void createPredefinedPatterns(byte rythmName, bool printOutput=false);
    void initializeBlankPatterns(unsigned int nbPatterns, unsigned int nbBeats);
    
    unsigned long getTimeToNextHit(byte limb, bool printOutput=false);
    byte getPosNextHit(byte limb, bool printOutput=false);

    void setBpm(unsigned short bpm);

    void setQuarterHit(byte limb, byte pos, byte patternIndex, byte noteIndex);
    void setQuaverHit(byte limb, byte pos, byte patternIndex, byte noteIndex);
    void setSemiquaverHit(byte limb, byte pos, byte patternIndex, byte noteIndex);
    void setHit(byte limb, byte pos, byte patternId, byte noteIndex, byte semiquaversPerNote);
    
    void setQuarterRest(byte limb, byte patternIndex, byte noteIndex);
    void setQuaverRest(byte limb, byte patternIndex, byte noteIndex);
    void setSemiquaverRest(byte limb, byte patternIndex, byte noteIndex);
    void setRest(byte limb, byte patternId, byte noteIndex, byte semiquaversPerNote);
    
    void setHitPattern(byte limb, byte hitPattenIndex, unsigned int pattern, bool printOutput);
    void setPosPattern(byte limb, byte patternId, byte p1, byte p2, byte p3, byte p4, byte p5, byte p6, byte p7, byte p8, byte p9, byte p10, byte p11, byte p12, byte p13, byte p14, byte p15, byte p16, bool printOutput=false);
    void setPatternSequence(byte pattSeq[]);
    
    void printPosPattern(byte limb, byte patternIndex);
    void printHitPattern(byte limb, byte patternIndex);
  
  protected:
    unsigned short bpm_;
    unsigned int timeQuarter_, timeQuaver_, timeSemiquaver_;

    byte nbOfPositions_[_nbLimbs];
    signed char hitIndexes_[_nbLimbs];                                       // Index of the current instruction in the pattern
    byte sequenceIndexes_[_nbLimbs];                                         // Index of the current pattern in the pattern sequence

    byte nbPatterns_;
    byte nbBeats_;

    byte errPosPattern_[16] = {255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255};

    Array<byte, MAX_NB_BEATS> patternSequence_;

    // Position patterns are stored as byte arrays, where each elements represents the position of the servo
    Array<Array<byte[16], MAX_NB_PATTERNS>, _nbLimbs> patternArrays_;
    
    unsigned int posMask_;
};

#endif
