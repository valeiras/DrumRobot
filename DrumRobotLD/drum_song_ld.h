#ifndef Drum_song_ld_h
#define Drum_song_ld_h

#include <percu_song.h>
#include <Arduino.h>

#include "drum_robot_config_ld.h"

#define BITS_FOR_POS_DR 3

class DrumSongLD : public PercuSong<NB_HIT_JOINTS_DR, BITS_FOR_POS_DR> {
public:
  DrumSongLD();

  // Default patterns for the different songs. Empty method in the base class
  void createPredefinedPatterns(Songs songName, bool hasOutput = false);
};

#endif
