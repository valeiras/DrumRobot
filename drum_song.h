#ifndef Drum_song_h
#define Drum_song_h

#include "Arduino.h"
#include "drum_robot.h"
#include <Array.h>

#define MAX_NB_PATTERNS 5
#define MAX_NB_BEATS 100
#define SEMIQUAVERS_PER_BEAT 16

class DrumSong {
  public:
    DrumSong();

    // Default patterns for the different songs. Empty method in the base class
    virtual void createPatterns();
    
    void initializeBlankPatterns(unsigned int nbPatterns, unsigned int nbBeats);
    
    unsigned long getTimeToNextHit(byte limb);
    byte getPosNextHit(byte limb);

    void setBpm(unsigned short bpm);

    void setQuarterHit(byte limb, byte pos, byte patternIndex, byte noteIndex);
    void setQuaverHit(byte limb, byte pos, byte patternIndex, byte noteIndex);
    void setSemiquaverHit(byte limb, byte pos, byte patternIndex, byte noteIndex);
    
    void setQuarterRest(byte limb, byte patternIndex, byte noteIndex);
    void setQuaverRest(byte limb, byte patternIndex, byte noteIndex);
    void setSemiquaverRest(byte limb, byte patternIndex, byte noteIndex);
    
    void setHitPattern(byte limb, byte hitPattenIndex, unsigned int pattern);
    void setPosPattern(byte limb, byte posPatt[][SEMIQUAVERS_PER_BEAT]);
    void setPatternSequence(byte pattSeq[]);
    
    void printPosPattern(byte limb, byte patternIndex);
    void printHitPattern(byte limb, byte patternIndex);
  
  protected:
    unsigned int getNumberOfPositions(byte limb);
    byte* getPosPattern(byte limb, byte patternId);
    Array<byte[16], MAX_NB_PATTERNS>* getPosPatternsPointer(byte limb);
    unsigned int getHitPattern(byte limb, byte patternId);
    unsigned int getHitPattern(byte limb);
    unsigned int* getHitPatternPointer(byte limb, byte patternId);
    short* getHitIndexPointer(byte limb);
    byte* getPatternIndexPointer(byte limb);

    unsigned short bpm_;
    unsigned int timeQuarter_, timeQuaver_, timeSemiquaver_;

    short hitIndexRightLeg_, hitIndexLeftArm_, hitIndexRightArm_;                   // Index of the current instruction in the pattern
    byte patternIndexRightLeg_, patternIndexLeftArm_, patternIndexRightArm_;        // Index of the current pattern in the pattern sequence

    byte nbPatterns_;
    byte nbBeats_;

    byte errPosPattern_[8] = {255, 255, 255, 255, 255, 255, 255, 255};

    Array<byte, MAX_NB_BEATS> patternSequence_;

    // Hit patterns are stored as unsigned ints (2 bytes), where each bit represents hit or rest in each semiquaver
    Array<unsigned int, MAX_NB_PATTERNS> hitPatternsRightLeg_, hitPatternsLeftArm_, hitPatternsRightArm_;

    // Position patterns are stored as byte arrays, where each elements represents the position of the servo
    Array<byte[16], MAX_NB_PATTERNS> posPatternsLeftArm_, posPatternsRightArm_;

};

#endif
