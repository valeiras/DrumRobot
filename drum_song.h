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

class DrumSong {
  public:
    DrumSong();

    // Default patterns for the different songs. Empty method in the base class
    virtual void createPatterns(bool printOutput);
    
    void initializeBlankPatterns(unsigned int nbPatterns, unsigned int nbBeats);
    
    unsigned long getTimeToNextHit(byte limb);
    byte getPosNextHit(byte limb);

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
    void setPosPattern(byte limb, byte posPatt[][SEMIQUAVERS_PER_BEAT], bool printOutput);
    void setPatternSequence(byte pattSeq[]);
    
    void printPosPattern(byte limb, byte patternIndex);
    void printHitPattern(byte limb, byte patternIndex);
  
  protected:
    unsigned int getNumberOfPositions(byte limb);
    byte* getPatternPointer(byte limb, byte patternId);
    Array<byte[16], MAX_NB_PATTERNS>* getPatternArrayPointer(byte limb);
    
    signed char* getHitIndexPointer(byte limb);
    byte* getSequenceIndexPointer(byte limb);

    unsigned short bpm_;
    unsigned int timeQuarter_, timeQuaver_, timeSemiquaver_;

    signed char hitIndexRL_, hitIndexLA_, hitIndexRA_;                // Index of the current instruction in the pattern
    byte sequenceIndexRL_, sequenceIndexLA_, sequenceIndexRA_;        // Index of the current pattern in the pattern sequence

    byte nbPatterns_;
    byte nbBeats_;

    byte errPosPattern_[16] = {255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255};

    Array<byte, MAX_NB_BEATS> patternSequence_;

    // Position patterns are stored as byte arrays, where each elements represents the position of the servo
    Array<byte[16], MAX_NB_PATTERNS> patternsRL_, patternsLA_, patternsRA_;
    
    unsigned int posMask_;
};

#endif
