#ifndef Basic_drum_song_h
#define Basic_rum_song_h

#include "drum_song.h"

class BasicDrumSong: public DrumSong{
  public:

    BasicDrumSong();
    BasicDrumSong(unsigned short bpm);
    void createPatterns();

  private:
    
};

#endif
