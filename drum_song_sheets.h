#ifndef Drum_song_sheets_h
#define Drum_song_sheets_h

#include "drum_song.h"

class SimplestDrumSong: public DrumSong{
  public:

    SimplestDrumSong();
    void createPatterns(bool printOutput);

  private:
    
};

class BasicDrumSong: public DrumSong{
  public:

    BasicDrumSong();
    BasicDrumSong(unsigned short bpm);
    void createPatterns(bool printOutput);

  private:
    
};

#endif
