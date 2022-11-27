#include "drum_song_sheets.h"

// -------------------------------------------- SIMPLEST DRUM SONG -----------------------------------------------------
SimplestDrumSong::SimplestDrumSong(): DrumSong() {
  nbPatterns_ = 1;
  nbBeats_ = 1;
}


void SimplestDrumSong::createPatterns() { 
  setHitPattern(RIGHT_LEG, 0, 0b1000000010000000);
  setHitPattern(LEFT_ARM,  0, 0b1010101010101010);
  setHitPattern(RIGHT_ARM, 0, 0b0010000000100000);

  byte posPattLeftArm[nbPatterns_][SEMIQUAVERS_PER_BEAT] = {
    {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}
  };

  byte posPattRightArm[nbPatterns_][SEMIQUAVERS_PER_BEAT] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2}
  };

  byte pattSeq[nbBeats_] = {0};

  setPosPattern(LEFT_ARM, posPattLeftArm);
  setPosPattern(RIGHT_ARM, posPattRightArm);
  setPatternSequence(pattSeq);
}


// -------------------------------------------- SIMPLEST DRUM SONG -----------------------------------------------------
BasicDrumSong::BasicDrumSong():DrumSong() {
  nbPatterns_ = 3;
  nbBeats_ = 10;
}

void BasicDrumSong::createPatterns() {    
  setHitPattern(RIGHT_LEG, 0, 0b0000000000000000);
  setHitPattern(RIGHT_LEG, 1, 0b1000000010100000);
  setHitPattern(RIGHT_LEG, 2, 0b1000000010100000);

  setHitPattern(LEFT_ARM, 0,  0b0100010001000100);
  setHitPattern(LEFT_ARM, 1,  0b1010101010101010);
  setHitPattern(LEFT_ARM, 2,  0b1010101010101010);

  setHitPattern(RIGHT_ARM, 0, 0b0000000000000000);
  setHitPattern(RIGHT_ARM, 1, 0b1000100100001010);
  setHitPattern(RIGHT_ARM, 2, 0b1000100100000101);

  byte posPattLeftArm[nbPatterns_][SEMIQUAVERS_PER_BEAT] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2}
  };

  byte posPattRightArm[nbPatterns_][SEMIQUAVERS_PER_BEAT] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
  };

  byte pattSeq[nbBeats_] = {1, 2, 1, 2, 1, 2, 1, 2, 1, 2};

  setPosPattern(LEFT_ARM, posPattLeftArm);
  setPosPattern(RIGHT_ARM, posPattRightArm);
  setPatternSequence(pattSeq);

}
