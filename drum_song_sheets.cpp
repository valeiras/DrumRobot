#include "drum_song_sheets.h"

// -------------------------------------------- SIMPLEST DRUM SONG -----------------------------------------------------
SimplestDrumSong::SimplestDrumSong(){
}

SimplestDrumSong::SimplestDrumSong(unsigned short bpm): DrumSong(bpm){
  nbPatterns_ = 1;
  nbBeats_ = 1;
  createPatterns();
}

void SimplestDrumSong::createPatterns(){
  hitPatternsRightLeg_[0] = 0b0011000100001111;
   
  hitPatternsLeftArm_[0] = 0b1111111100001111; 
  
  hitPatternsRightArm_[0] = 0b0100010000001111;
  
  byte posPattLeftArm[nbPatterns_][SEMIQUAVERS_PER_BEAT] = {
    {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}
  };
  
  byte posPattRightArm[nbPatterns_][SEMIQUAVERS_PER_BEAT] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2}
  };

  byte pattSeq[nbBeats_] = {0};

  setPosPatternLeftArm(posPattLeftArm);
  setPosPatternRightArm(posPattRightArm);
  setPatternSequence(pattSeq);

}


// -------------------------------------------- SIMPLEST DRUM SONG -----------------------------------------------------
BasicDrumSong::BasicDrumSong(){
}

BasicDrumSong::BasicDrumSong(unsigned short bpm): DrumSong(bpm){
  nbPatterns_ = 3;
  nbBeats_ = 10;
  createPatterns();
}

void BasicDrumSong::createPatterns(){
  hitPatternsRightLeg_[0] = 0b0000000000000000;
  hitPatternsRightLeg_[1] = 0b0000010100000001;
  hitPatternsRightLeg_[2] = 0b0000010100000001;
   
  hitPatternsLeftArm_[0] =  0b0010001000100010;
  hitPatternsLeftArm_[1] =  0b0101010101010101;
  hitPatternsLeftArm_[2] =  0b0101010101010101;   
  
  hitPatternsRightArm_[0] = 0b0000000000000000;
  hitPatternsRightArm_[1] = 0b0101000010010001;
  hitPatternsRightArm_[2] = 0b1010000010010001; 
  
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

  setPosPatternLeftArm(posPattLeftArm);
  setPosPatternRightArm(posPattRightArm);
  setPatternSequence(pattSeq);

}
