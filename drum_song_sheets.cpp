#include "drum_song_sheets.h"

// -------------------------------------------- SIMPLEST DRUM SONG -----------------------------------------------------
SimplestDrumSong::SimplestDrumSong(): DrumSong() {
  nbPatterns_ = 1;
  nbBeats_ = 1;
}


void SimplestDrumSong::createPatterns(bool printOutput) {
  initializeBlankPatterns(nbPatterns_, nbBeats_);

  byte patternId = 0;

  setHitPattern(RIGHT_LEG, patternId, 0b1000000010000000, printOutput);
  setHitPattern(LEFT_ARM,  patternId, 0b1010101010101010, printOutput);
  setHitPattern(RIGHT_ARM, patternId, 0b0010000000100000, printOutput);

  setPosPattern(LEFT_ARM, patternId, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, printOutput);
  setPosPattern(RIGHT_ARM, patternId, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, printOutput);

  byte pattSeq[nbBeats_] = {0};
  setPatternSequence(pattSeq);
}


// -------------------------------------------- SIMPLEST DRUM SONG -----------------------------------------------------
BasicDrumSong::BasicDrumSong(): DrumSong() {
  nbPatterns_ = 3;
  nbBeats_ = 10;
}

void BasicDrumSong::createPatterns(bool printOutput) {
  initializeBlankPatterns(nbPatterns_, nbBeats_);

  byte patternId0 = 0;
  byte patternId1 = 1;
  byte patternId2 = 2;

  // Right leg
  setHitPattern(RIGHT_LEG, patternId0, 0b0000000000000000, printOutput);
  setHitPattern(RIGHT_LEG, patternId1, 0b1000000010100000, printOutput);
  setHitPattern(RIGHT_LEG, patternId2, 0b1000000010100000, printOutput);

  // Left arm
  setHitPattern(LEFT_ARM, patternId0,  0b1000100010001000, printOutput);
  setHitPattern(LEFT_ARM, patternId1,  0b1010101010101010, printOutput);
  setHitPattern(LEFT_ARM, patternId2,  0b1010101010100101, printOutput);

  setPosPattern(LEFT_ARM, patternId0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, printOutput);
  setPosPattern(LEFT_ARM, patternId1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, printOutput);
  setPosPattern(LEFT_ARM, patternId2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, printOutput);

  // Right arm
  setHitPattern(RIGHT_ARM, patternId0, 0b1000100010001000, printOutput);
  setHitPattern(RIGHT_ARM, patternId1, 0b1000100100001000, printOutput);
  setHitPattern(RIGHT_ARM, patternId2, 0b0000100100001010, printOutput);

  setPosPattern(RIGHT_ARM, patternId0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, printOutput);
  setPosPattern(RIGHT_ARM, patternId1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, printOutput);
  setPosPattern(RIGHT_ARM, patternId2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, printOutput);

  byte pattSeq[nbBeats_] = {0, 1, 2, 1, 2, 1, 2, 1, 2, 1};

  setPatternSequence(pattSeq);
}
