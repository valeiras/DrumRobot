#ifndef Glocken_song_gr_h
#define Glocken_song_gr_h

#include <percu_song.h>
#include <robo_communication.h>
#include <Arduino.h>

#include "glocken_robot_config_gr.h"

#define BITS_FOR_POS_GL 4
#define NB_LIMBS_GL 2


class GlockenSongGR : public PercuSong<NB_LIMBS_GL, BITS_FOR_POS_GL> {
public:
  GlockenSongGR();

  // Default patterns for the different songs. Empty method in the base class
  void createPredefinedPatterns(Songs songName, bool hasOutput = false);
};

#endif
