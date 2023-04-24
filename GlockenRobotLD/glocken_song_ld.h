#ifndef Glocken_song_ld_h
#define Glocken_song_ld_h

#include <percu_song.h>
#include <Arduino.h>

#include "glocken_robot_config_ld.h"

#define BITS_FOR_POS_GL 4

#define FRERE_JACQUES 0

class GlockenSongLD : public PercuSong<NB_HIT_JOINTS_GL, BITS_FOR_POS_GL> {
public:
  GlockenSongLD();

  // Default patterns for the different songs. Empty method in the base class
  void createPredefinedPatterns(byte songName, bool hasOutput = false);
};

#endif
