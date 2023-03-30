#ifndef Drum_song_h
#define Drum_song_h

#include <percu_song.h>
#include <Arduino.h>

#include "drum_robot_config.h"

#define BITS_FOR_POS_DR 3

#define SIMPLEST_RYTHM 0
#define BASIC_RYTHM 1
#define CRESCENDO 2
#define QUARTER_NOTES 3

class DrumSong : public PercuSong<NB_HIT_JOINTS_DR, BITS_FOR_POS_DR> {
public:
  DrumSong();

  // Default patterns for the different songs. Empty method in the base class
  void createPredefinedPatterns(byte rythmName, bool printOutput = false);
};

#endif
