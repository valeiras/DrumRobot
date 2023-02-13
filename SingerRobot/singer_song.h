#ifndef Singer_song_h
#define Singer_song_h

#include <robo_song.h>

#include "Arduino.h"
#include "robo_song.h"
#include "singer_robot_config.h"

#define BITS_FOR_POS_SG 5
#define NB_LIMBS_SG 3

#define C_SCALE 0

class SingerSong : public RoboSong<NB_LIMBS_SG, BITS_FOR_POS_SG> {
public:
  SingerSong();

  // Default patterns for the different songs. Empty method in the base class
  void createPredefinedPatterns(byte rythmName, bool printOutput = false);

  String getNoteName(byte note);
  int getFreqNextHit(byte singerIdx);

private:
  void setFrequencies();

  int frequencies_[NB_NOTES_SG];
  String noteNames_[NB_NOTES_SG];
};

#endif
