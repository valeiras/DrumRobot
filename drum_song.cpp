#include "drum_song.h"

DrumSong::DrumSong(){
}

DrumSong::DrumSong(unsigned short bpm){
  setBpm(bpm);

  hitIndexRightLeg_ = -1;
  hitIndexLeftArm_ = -1;
  hitIndexRightArm_ = -1;

  patternIndexRightLeg_= 0;
  patternIndexLeftArm_ = 0;
  patternIndexRightArm_ = 0;
}

unsigned long DrumSong::getTimeToNextHit(byte limb){
  byte pattern = getHitPattern(limb);
  short* hitIndex = getHitIndexPointer(limb);
  byte* patternIndex = getPatternIndexPointer(limb);
  
  unsigned long timeToNextInstruction = 0;
  
  do{
    // We iterate the pattern. When we get to the end we start again
    if(++(*hitIndex)>=8){
      *hitIndex = 0;
      *patternIndex = (*patternIndex+1)%nbBeats_;
      pattern = getHitPattern(limb);
    }
    timeToNextInstruction+=timeQuaver_;
  } while(!bitRead(pattern, *hitIndex));

  return timeToNextInstruction;
}

byte DrumSong::getPosNextHit(byte limb){
  byte patternId;
  
  switch(limb){
  case LEFT_ARM:
    patternId = patternSequence_[patternIndexLeftArm_];
    return posPatternsLeftArm_[patternId][hitIndexLeftArm_];
  case RIGHT_ARM:
    patternId = patternSequence_[patternIndexRightArm_];
    return posPatternsRightArm_[patternId][hitIndexRightArm_];
  default:
    return 255;
  }
}

void DrumSong::setBpm(unsigned short bpm){
  bpm_ = bpm;
  timeQuarter_ = int(60000.0/bpm_);     // us per quarter note
  timeQuaver_ = int(timeQuarter_/2.0);  // us per quaver note
}

byte* DrumSong::getPosPattern(byte limb, byte patternId){
  if(patternId < nbPatterns_){
    switch(limb){
    case LEFT_ARM:
      return posPatternsLeftArm_[patternId];
    case RIGHT_ARM:
      return posPatternsRightArm_[patternId];
    }
  }
  else{ 
    return errPosPattern_;
  }
}
    
byte DrumSong::getHitPattern(byte limb, byte patternId){
  if(patternId < nbPatterns_){
    switch(limb){
    case RIGHT_LEG:
      return hitPatternsRightLeg_[patternId];
    case LEFT_ARM:
      return hitPatternsLeftArm_[patternId];
    case RIGHT_ARM:
      return hitPatternsRightArm_[patternId];
    } 
  }
  else{
    return 0;
  }
}

byte DrumSong::getHitPattern(byte limb){  
  byte patternId;
  
  switch(limb){
  case RIGHT_LEG:
    patternId = patternSequence_[patternIndexRightLeg_];
    return hitPatternsRightLeg_[patternId];
  case LEFT_ARM:
    patternId = patternSequence_[patternIndexLeftArm_];
    return hitPatternsLeftArm_[patternId];
  case RIGHT_ARM:
    patternId = patternSequence_[patternIndexRightArm_];
    return hitPatternsRightArm_[patternId];  
  }
}

short* DrumSong::getHitIndexPointer(byte limb){
  switch(limb){
  case RIGHT_LEG:
    return &hitIndexRightLeg_;
  case LEFT_ARM:
    return &hitIndexLeftArm_;
  case RIGHT_ARM:
    return &hitIndexRightArm_;
  } 
}

byte* DrumSong::getPatternIndexPointer(byte limb){
  switch(limb){
  case RIGHT_LEG:
    return &patternIndexRightLeg_;
  case LEFT_ARM:
    return &patternIndexLeftArm_;
  case RIGHT_ARM:
    return &patternIndexRightArm_;
  }   
}

void DrumSong::setPosPatternLeftArm(byte posPatt[][8]){
  for(int ii=0; ii<nbPatterns_; ii++){
    for(int jj=0; jj<8; jj++){
      if(posPatt[ii][jj] < NB_POS_LEFT_ARM){
        posPatternsLeftArm_[ii][jj] = posPatt[ii][jj];
      }
      else{
        posPatternsLeftArm_[ii][jj] = 0;
      }
    }
  }  
}

void DrumSong::setPosPatternRightArm(byte posPatt[][8]){
  for(int ii=0; ii<nbPatterns_; ii++){
    for(int jj=0; jj<8; jj++){
      if(posPatt[ii][jj] < NB_POS_RIGHT_ARM){
        posPatternsRightArm_[ii][jj] = posPatt[ii][jj];
      }
      else{
        posPatternsRightArm_[ii][jj] = 0;
      }
    }
  }   
}
  
void DrumSong::setPatternSequence(byte pattSeq[]){
  for(int ii=0; ii<nbBeats_; ii++){
    if(pattSeq[ii]<nbPatterns_){
      patternSequence_.push_back(pattSeq[ii]);
    }
    else{
      patternSequence_.push_back(0);
    }
  }
}
