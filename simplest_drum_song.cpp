#include "simplest_drum_song.h"

SimplestDrumSong::SimplestDrumSong(){
}

SimplestDrumSong::SimplestDrumSong(unsigned short bpm): DrumSong(bpm){
  nbPatterns_ = 1;
  nbBeats_ = 1;
  createPatterns();
}

void SimplestDrumSong::createPatterns(){
  hitPatternsRightLeg_[0] = B00110001;
   
  hitPatternsLeftArm_[0] = B11111111; 
  
  hitPatternsRightArm_[0] = B01000100;
  
  byte ppLa[nbPatterns_][8] = {
    {2, 2, 2, 2, 2, 2, 2, 2}
  };
  byte ppRa[nbPatterns_][8] = {
    {1, 1, 1, 1, 2, 2, 2, 2}
  };

  for(int ii=0; ii<nbPatterns_; ii++){
    for(int jj=0; jj<8; jj++){
      posPatternsLeftArm_[ii][jj] = ppLa[ii][jj];
      posPatternsRightArm_[ii][jj] = ppRa[ii][jj];
    }
  }
}
