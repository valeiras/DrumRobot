#ifndef Drum_song_gr_h
#define Drum_song_gr_h

#include <percu_song.h>
#include <robo_communication.h>
#include <Arduino.h>

#include "drum_robot_config_gr.h"

#define BITS_FOR_POS_DR 3
#define NB_LIMBS_DR 3

class DrumSongGR : public PercuSong<NB_LIMBS_DR, BITS_FOR_POS_DR> {
public:
  DrumSongGR();

  // Default patterns for the different songs. Empty method in the base class
  void createPredefinedPatterns(Songs songName, bool hasOutput = false);

  private:
};

#endif
