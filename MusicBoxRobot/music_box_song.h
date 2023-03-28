#ifndef Music_box_song_h
#define Music_box_song_h

#include <Arduino.h>
#include <Array.h>

#define BITS_FOR_ON_OFF 1
#define SEMIQUAVERS_MASK B11111110

#define BARS_PER_LOOP 8  // Number of bars in a music box cylinder
#define SEMIQUAVERS_PER_BAR 16
#define SEMIQUAVERS_PER_LOOP 128  // 8*16=128 -> Number of semiquavers in a complete loop of the music box. This value can be stored in 7 bits

#define MAX_NB_INSTRUCTIONS 64

#define OFF 0
#define ON 1

class MusicBoxSong {
public:
  MusicBoxSong();

  void setOnInstruction(uint8_t nbSemiquavers);
  void setOffInstruction(uint8_t nbSemiquavers);

  bool getNextInstruction(uint8_t &nbSemiquavers);

  void printInstructions();

private:
  void setInstruction(uint8_t nbSemiquavers, bool onOrOff);

  uint8_t instructions_[MAX_NB_INSTRUCTIONS];
  uint8_t nbInstructions_;
  
  int8_t currInstructionIndex_;
};

#endif