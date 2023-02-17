#include <robo_song.h>

#ifndef Glocken_song_h
#define Glocken_song_h

#include "Arduino.h"
#include "robo_song.h"
#include "glocken_robot_config.h"

#define BITS_FOR_POS_GL 4

#define FRERE_JACQUES 0

class GlockenSong : public RoboSong<NB_HIT_JOINTS_GL, BITS_FOR_POS_GL> {
public:
  GlockenSong();

  // Default patterns for the different songs. Empty method in the base class
  void createPredefinedPatterns(byte songName, bool printOutput = false);
};

#endif
