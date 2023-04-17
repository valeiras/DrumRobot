#ifndef Drum_song_gr_h
#define Drum_song_gr_h

#include <percu_song.h>
#include <Arduino.h>

#include "drum_robot_config_gr.h"

#define BITS_FOR_POS_DR 3
#define NB_LIMBS_DR 3

#define SIMPLEST_RYTHM 0
#define BASIC_RYTHM 1
#define BASIC_RYTHM_WO_ACC 2
#define CRESCENDO 3
#define QUARTER_NOTES 4

class DrumSongGR : public PercuSong<NB_LIMBS_DR, BITS_FOR_POS_DR> {
public:
  DrumSongGR();

  // Default patterns for the different songs. Empty method in the base class
  void createPredefinedPatterns(byte rythmName, bool printOutput = false);
};

#endif
