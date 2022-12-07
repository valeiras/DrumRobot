#include "drum_song_sheets.h"

// -------------------------------------------- SIMPLEST DRUM SONG -----------------------------------------------------
SimplestDrumSong::SimplestDrumSong(): DrumSong() {
  nbPatterns_ = 1;
  nbBeats_ = 1;
}


void SimplestDrumSong::createPatterns(bool printOutput) {
  initializeBlankPatterns(nbPatterns_, nbBeats_);

  setHitPattern(RIGHT_LEG, 0, 0b1000000010000000, printOutput);
  setHitPattern(LEFT_ARM,  0, 0b1010101010101010, printOutput);
  setHitPattern(RIGHT_ARM, 0, 0b0010000000100000, printOutput);

  byte posPattLeftArm[nbPatterns_][SEMIQUAVERS_PER_BEAT] = {
    {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}
  };

  byte posPattRightArm[nbPatterns_][SEMIQUAVERS_PER_BEAT] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2}
  };

  byte pattSeq[nbBeats_] = {0};

  setPosPattern(LEFT_ARM, posPattLeftArm, printOutput);
  setPosPattern(RIGHT_ARM, posPattRightArm, printOutput);
  setPatternSequence(pattSeq);
}


// -------------------------------------------- SIMPLEST DRUM SONG -----------------------------------------------------
BasicDrumSong::BasicDrumSong(): DrumSong() {
  nbPatterns_ = 3;
  nbBeats_ = 10;
}

void BasicDrumSong::createPatterns(bool printOutput) {
  initializeBlankPatterns(nbPatterns_, nbBeats_);

  setHitPattern(RIGHT_LEG, 0, 0b0000000000000000, printOutput);
  setHitPattern(RIGHT_LEG, 1, 0b1000000010100000, printOutput);
  setHitPattern(RIGHT_LEG, 2, 0b1000000010100000, printOutput);

  setHitPattern(LEFT_ARM, 0,  0b1000100010001000, printOutput);
  setHitPattern(LEFT_ARM, 1,  0b1010101010101010, printOutput);
  setHitPattern(LEFT_ARM, 2,  0b1010101010100101, printOutput);

  setHitPattern(RIGHT_ARM, 0, 0b1000100010001000, printOutput);
  setHitPattern(RIGHT_ARM, 1, 0b1000100100001000, printOutput);
  setHitPattern(RIGHT_ARM, 2, 0b0000100100001010, printOutput);

  byte posPattLeftArm[nbPatterns_][SEMIQUAVERS_PER_BEAT] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2}
  };

  byte posPattRightArm[nbPatterns_][SEMIQUAVERS_PER_BEAT] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
  };

  byte pattSeq[nbBeats_] = {0, 1, 2, 1, 2, 1, 2, 1, 2, 1};
  
  setPosPattern(LEFT_ARM, posPattLeftArm, printOutput);
  setPosPattern(RIGHT_ARM, posPattRightArm, printOutput);

  setPatternSequence(pattSeq);
}
