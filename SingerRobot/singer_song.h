#ifndef Singer_song__h
#define Singer_song__h

#include <percu_song.h>
#include <robo_communication.h>
#include <Arduino.h>

#include "singer_robot_config.h"

#define BITS_FOR_POS_SG 1

#define POS_SG 0
#define SING 1

class SingerSong : public PercuSong<NB_SINGERS, BITS_FOR_POS_SG> {
public:
  SingerSong();

  // Default patterns for the different songs. Empty method in the base class
  void createPredefinedPatterns(Songs songName, bool hasOutput = false);

private:
};

#endif
