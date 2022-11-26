#ifndef Simplest_drum_song_h
#define Simplest_rum_song_h

#include "drum_song.h"

class SimplestDrumSong: public DrumSong{
  public:

    SimplestDrumSong();
    SimplestDrumSong(unsigned short bpm);
    void createPatterns();

  private:
    
};

#endif
