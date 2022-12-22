#include <robo_song.h>

#ifndef Drum_song_h
#define Drum_song_h

#include "Arduino.h"
#include "robo_song.h"
#include "drum_robot_config.h"

#define BITS_FOR_POS_DRUM 3
#define NB_LIMBS_DRUM 3

#define SIMPLEST_RYTHM 0
#define BASIC_RYTHM 1
#define BASIC_RYTHM_WO_ACC 2
#define CRESCENDO 3

class DrumSong : public RoboSong<NB_LIMBS_DRUM, BITS_FOR_POS_DRUM> {
public:
  DrumSong();

  // Default patterns for the different songs. Empty method in the base class
  void createPredefinedPatterns(byte rythmName, bool printOutput = false);
};

#endif
