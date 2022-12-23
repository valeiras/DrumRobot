#include <robo_song.h>

#ifndef Glocken_song_h
#define Glocken_song_h

#include "Arduino.h"
#include "robo_song.h"
#include "glocken_robot_config.h"

#define BITS_FOR_POS_GLOCK 4
#define NB_LIMBS_GLOCK 2

class GlockenSong : public RoboSong<NB_LIMBS_GLOCK, BITS_FOR_POS_GLOCK> {
public:
  GlockenSong();

  // Default patterns for the different songs. Empty method in the base class
  void createPredefinedPatterns(byte rythmName, bool printOutput = false);
};

#endif
