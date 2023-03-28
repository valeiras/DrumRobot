#ifndef Music_box_percu_song_h
#define Music_box_percu_song_h

#include <percu_song.h>
#include "music_box_config.h"

#define SIMPLEST_RYTHM 0

class MusicBoxPercuSong : public PercuSong<NB_HIT_JOINTS_MB, BITS_FOR_POS_MB> {
public:
  MusicBoxPercuSong();

  // Default patterns for the different songs. Empty method in the base class
  void createPredefinedPatterns(byte rythmName, bool printOutput = false);
};

#endif
