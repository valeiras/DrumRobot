#ifndef Drum_song_h
#define Drum_song_h

#include "Arduino.h"
#include "drum_robot.h"
#include <Array.h>

#define MAX_NB_PATTERNS 5
#define MAX_NB_BEATS 100

class DrumSong{
  public:
    DrumSong();
    DrumSong(unsigned short bpm);
    
    virtual void createPatterns() = 0;
    unsigned long getTimeToNextHit(byte limb);
    byte getPosNextHit(byte limb);

    void setBpm(unsigned short bpm);
           
  protected:
    byte* getPosPattern(byte limb, byte patternId);
    byte* getPosPattern(byte limb);
    byte getHitPattern(byte limb, byte patternId);
    byte getHitPattern(byte limb);
    short* getHitIndexPointer(byte limb);
    byte* getPatternIndexPointer(byte limb);
    void setPosPatternLeftArm(byte posPatt[][8]);
    void setPosPatternRightArm(byte posPatt[][8]);
    void setPatternSequence(byte pattSeq[]);
    
    unsigned short bpm_;
    unsigned int timeQuarter_, timeQuaver_;
    
    short hitIndexRightLeg_, hitIndexLeftArm_, hitIndexRightArm_;                  // Index of the current instruction in the pattern
    byte patternIndexRightLeg_, patternIndexLeftArm_, patternIndexRightArm_;        // Index of the current pattern in the pattern sequence
    
    byte nbPatterns_;
    byte nbBeats_;

    byte errPosPattern_[8] = {255, 255, 255, 255, 255, 255, 255, 255};

    Array<byte, MAX_NB_BEATS> patternSequence_;

    // Hit patterns are stored as bytes, where each bit represents hit or rest in each quaver
    Array<byte, MAX_NB_PATTERNS> hitPatternsRightLeg_, hitPatternsLeftArm_, hitPatternsRightArm_;
    
    // Position patterns are stored as byte arrays, where each elements represents the position of the servo
    Array<byte[8], MAX_NB_PATTERNS> posPatternsLeftArm_, posPatternsRightArm_;
    
};

#endif
