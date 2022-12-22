#include "robo_song.h"

template <int NB_LIMBS, int BITS_FOR_POS>
RoboSong<NB_LIMBS, BITS_FOR_POS>::RoboSong(){

      for (unsigned int ii = 0; ii < NB_LIMBS; ii++) {
        hitIndexes_[ii] = -1;
        sequenceIndexes_[ii] = 0;
        timeNextHit_[ii] = 0;
      }

      posMask_ = 0;
      velMask_ = 0;

      for (unsigned int ii = BITS_FOR_HIT; ii < BITS_FOR_HIT + BITS_FOR_POS; ii++) {
        bitSet(posMask_, ii);
      }

      for (unsigned int ii = BITS_FOR_HIT + BITS_FOR_POS; ii < BITS_PER_BYTE; ii++) {
        bitSet(velMask_, ii);
      }

      unsigned int bits_for_vel = BITS_PER_BYTE - (BITS_FOR_HIT + BITS_FOR_POS);
      maxVel_ = pow(2, bits_for_vel) - 1;
}

template <int NB_LIMBS, int BITS_FOR_POS>
void RoboSong<NB_LIMBS, BITS_FOR_POS>::initializeBlankPatterns(unsigned int nbPatterns, unsigned int nbBeats) {
  nbPatterns_ = nbPatterns;
  nbBeats_ = nbBeats;

  for (int limb = 0; limb < NB_LIMBS; limb++) {
    for (int patternId = 0; patternId < nbPatterns_; patternId++) {
      byte* currPattern = patternArrays_[limb][patternId];
      for (int noteIndex = 0; noteIndex < SEMIQUAVERS_PER_BEAT; noteIndex++) {
        currPattern[noteIndex] = 0;
      }
    }

    for (int ii = 0; ii < nbBeats_; ii++) {
      patternSequence_[ii] = 0;
    }
  }
}

template <int NB_LIMBS, int BITS_FOR_POS>
void RoboSong<NB_LIMBS, BITS_FOR_POS>::computeNextHit(byte limb, bool printOutput = false) {
  signed char* hitIndex = &hitIndexes_[limb];
  byte* sequenceIndex = &sequenceIndexes_[limb];

  // We get the current pattern
  byte patternId = patternSequence_[*sequenceIndex];
  byte* currPattern = patternArrays_[limb][patternId];

  do {
    // We iterate the pattern. When we get to the end we start again
    if (++(*hitIndex) >= SEMIQUAVERS_PER_BEAT) {
      *hitIndex = 0;
      *sequenceIndex = (*sequenceIndex + 1) % nbBeats_;
      patternId = patternSequence_[*sequenceIndex];
      currPattern = patternArrays_[limb][patternId];
    }
    timeNextHit_[limb] += timeSemiquaver_;

  } while (!bitRead(currPattern[*hitIndex], 0));
}

template <int NB_LIMBS, int BITS_FOR_POS>
unsigned long RoboSong<NB_LIMBS, BITS_FOR_POS>::getTimeNextHit(byte limb) {
  return timeNextHit_[limb];
}

template <int NB_LIMBS, int BITS_FOR_POS>
byte RoboSong<NB_LIMBS, BITS_FOR_POS>::getPosNextHit(byte limb) {
  byte sequenceIndex = sequenceIndexes_[limb];
  byte patternId = patternSequence_[sequenceIndex];
  byte* currPattern = patternArrays_[limb][patternId];
  unsigned char hitIndex = hitIndexes_[limb];

  return ((currPattern[hitIndex] & posMask_) >> BITS_FOR_HIT);
}

template <int NB_LIMBS, int BITS_FOR_POS>
byte RoboSong<NB_LIMBS, BITS_FOR_POS>::getVelNextHit(byte limb) {
  byte sequenceIndex = sequenceIndexes_[limb];
  byte patternId = patternSequence_[sequenceIndex];
  byte* currPattern = patternArrays_[limb][patternId];
  unsigned char hitIndex = hitIndexes_[limb];

  return ((currPattern[hitIndex] & velMask_) >> BITS_FOR_HIT + BITS_FOR_POS);
}

template <int NB_LIMBS, int BITS_FOR_POS>
void RoboSong<NB_LIMBS, BITS_FOR_POS>::setBpm(unsigned short bpm) {
  bpm_ = bpm;
  unsigned long timeQuarter = int(60000.0 / bpm_);  // us per quarter note
  timeSemiquaver_ = int(timeQuarter / 4.0);      // us per semiquaver note
}

template <int NB_LIMBS, int BITS_FOR_POS>
void RoboSong<NB_LIMBS, BITS_FOR_POS>::setInitialTime(unsigned long initialTime) {
  for (unsigned int ii = 0; ii < NB_LIMBS; ii++) {
    timeNextHit_[ii] = initialTime;
  }
}

template <int NB_LIMBS, int BITS_FOR_POS>
void RoboSong<NB_LIMBS, BITS_FOR_POS>::setQuarterHit(byte limb, byte pos, byte velocity, byte patternId, byte noteIndex, bool printOutput) {
  byte semiquaversPerQuarter = 4;
  setHit(limb, pos, velocity, patternId, noteIndex, semiquaversPerQuarter, printOutput);
}

template <int NB_LIMBS, int BITS_FOR_POS>
void RoboSong<NB_LIMBS, BITS_FOR_POS>::setQuaverHit(byte limb, byte pos, byte velocity, byte patternId, byte noteIndex, bool printOutput) {
  byte semiquaversPerQuaver = 2;
  setHit(limb, pos, velocity, patternId, noteIndex, semiquaversPerQuaver, printOutput);
}

template <int NB_LIMBS, int BITS_FOR_POS>
void RoboSong<NB_LIMBS, BITS_FOR_POS>::setSemiquaverHit(byte limb, byte pos, byte velocity, byte patternId, byte noteIndex, bool printOutput) {
  byte semiquaversPerSemiquaver = 1;
  setHit(limb, pos, velocity, patternId, noteIndex, semiquaversPerSemiquaver, printOutput);
}

template <int NB_LIMBS, int BITS_FOR_POS>
void RoboSong<NB_LIMBS, BITS_FOR_POS>::setHit(byte limb, byte pos, byte vel, byte patternId, byte noteIndex, byte semiquaversPerNote, bool printOutput) {
  if (noteIndex > 0 && semiquaversPerNote * (noteIndex - 1) < SEMIQUAVERS_PER_BEAT && pos < nbOfPositions_[limb]) {
    // We get the current pattern
    byte* currPattern = patternArrays_[limb][patternId];
    byte* currElement = &currPattern[semiquaversPerNote * (noteIndex - 1)];

    // We initialize the element
    *currElement = 0;

    // We set the first bit -> hit
    bitSet(*currElement, 0);

    // We set the position bits
    *currElement = *currElement | (pos << BITS_FOR_HIT);

    // We set the velocity bits
    *currElement = *currElement | (min(vel, maxVel_) << BITS_FOR_HIT + BITS_FOR_POS);
  } else {
    Serial.println("Index out of bounds");
  }
}

template <int NB_LIMBS, int BITS_FOR_POS>
void RoboSong<NB_LIMBS, BITS_FOR_POS>::setQuarterRest(byte limb, byte patternId, byte noteIndex) {
  byte semiquaversPerQuarter = 4;
  setRest(limb, patternId, noteIndex, semiquaversPerQuarter);
}

template <int NB_LIMBS, int BITS_FOR_POS>
void RoboSong<NB_LIMBS, BITS_FOR_POS>::setQuaverRest(byte limb, byte patternId, byte noteIndex) {
  byte semiquaversPerQuaver = 2;
  setRest(limb, patternId, noteIndex, semiquaversPerQuaver);
}

template <int NB_LIMBS, int BITS_FOR_POS>
void RoboSong<NB_LIMBS, BITS_FOR_POS>::setSemiquaverRest(byte limb, byte patternId, byte noteIndex) {
  byte semiquaversPerSemiquaver = 1;
  setRest(limb, patternId, noteIndex, semiquaversPerSemiquaver);
}

template <int NB_LIMBS, int BITS_FOR_POS>
void RoboSong<NB_LIMBS, BITS_FOR_POS>::setRest(byte limb, byte patternId, byte noteIndex, byte semiquaversPerNote) {
  if (noteIndex > 0 && semiquaversPerNote * (noteIndex - 1) < SEMIQUAVERS_PER_BEAT) {
    byte* currPattern = patternArrays_[limb][patternId];
    currPattern[semiquaversPerNote * (noteIndex - 1)] = 0;
  }
}

template <int NB_LIMBS, int BITS_FOR_POS>
void RoboSong<NB_LIMBS, BITS_FOR_POS>::setHitPattern(byte limb, byte patternId, byte p1, byte p2, byte p3, byte p4, byte p5, byte p6, byte p7,
                             byte p8, byte p9, byte p10, byte p11, byte p12, byte p13, byte p14, byte p15, byte p16, bool printOutput = false) {

  unsigned int nbPos = nbOfPositions_[limb];
  byte* currPattern = patternArrays_[limb][patternId];
  byte inputPattern[SEMIQUAVERS_PER_BEAT] = { p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16 };

  if (printOutput) {
    Serial.println("");
    Serial.print("Setting pos pattern ");
    Serial.print(patternId);
    Serial.print(" for limb ");
    Serial.println(limb);
  }

  for (int ii = 0; ii < SEMIQUAVERS_PER_BEAT; ii++) {
    // We reinitialize the element:
    currPattern[ii] = 0;

    if (inputPattern[ii] != REST && inputPattern[ii] <= nbPos) {
      bitSet(currPattern[ii], 0);

      // We substract 1 to the position, because we reserve 0 for the rest => we add one to make it different
      currPattern[ii] = currPattern[ii] | (inputPattern[ii] << BITS_FOR_HIT);
    }
    if (printOutput) {
      Serial.print(inputPattern[ii]);
      Serial.print(" ");
    }
  }
}

template <int NB_LIMBS, int BITS_FOR_POS>
void RoboSong<NB_LIMBS, BITS_FOR_POS>::setVelPattern(byte limb, byte patternId, byte v1, byte v2, byte v3, byte v4, byte v5, byte v6, byte v7, byte v8, byte v9, byte v10, byte v11, byte v12, byte v13, byte v14, byte v15, byte v16, bool printOutput = false) {
  unsigned int nbPos = nbOfPositions_[limb];
  byte* currPattern = patternArrays_[limb][patternId];
  byte inputPattern[SEMIQUAVERS_PER_BEAT] = { v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16 };

  if (printOutput) {
    Serial.println("");
    Serial.print("Setting velocity pattern ");
    Serial.print(patternId);
    Serial.print(" for limb ");
    Serial.println(limb);
  }

  for (int ii = 0; ii < SEMIQUAVERS_PER_BEAT; ii++) {
    currPattern[ii] = currPattern[ii] | (min(inputPattern[ii], maxVel_) << BITS_FOR_HIT + BITS_FOR_POS);

    if (printOutput) {
      Serial.print(inputPattern[ii]);
      Serial.print(" ");
    }
  }
}

template <int NB_LIMBS, int BITS_FOR_POS>
void RoboSong<NB_LIMBS, BITS_FOR_POS>::setPatternSequence(byte pattSeq[]) {
  for (int ii = 0; ii < nbBeats_; ii++) {
    if (pattSeq[ii] < nbPatterns_) {
      patternSequence_.push_back(pattSeq[ii]);
    } else {
      patternSequence_.push_back(0);
    }
  }
}

template <int NB_LIMBS, int BITS_FOR_POS>
void RoboSong<NB_LIMBS, BITS_FOR_POS>::printPatterns() {
  for (unsigned int ii = 0; ii < NB_LIMBS; ii++) {
    printPatterns(ii);
  }
}

template <int NB_LIMBS, int BITS_FOR_POS>
void RoboSong<NB_LIMBS, BITS_FOR_POS>::printPatterns(byte limb) {
  for (unsigned int ii = 0; ii < nbPatterns_; ii++) {
    printHitPattern(limb, ii);
    printPosPattern(limb, ii);
    printVelPattern(limb, ii);
  }
}

template <int NB_LIMBS, int BITS_FOR_POS>
void RoboSong<NB_LIMBS, BITS_FOR_POS>::printHitPattern(byte limb, byte patternId) {
  if (limb < NB_LIMBS && patternId < nbPatterns_) {
    Serial.println("");
    Serial.print("Hit pattern ");
    Serial.print(patternId);
    Serial.print(" for limb ");
    Serial.println(limb);

    byte* currPattern = patternArrays_[limb][patternId];
    for (unsigned int ii = 0; ii < SEMIQUAVERS_PER_BEAT; ii++) {
      Serial.print(bitRead(currPattern[ii], 0));
      Serial.print(" ");
    }
    Serial.println("");
  }
}

template <int NB_LIMBS, int BITS_FOR_POS>
void RoboSong<NB_LIMBS, BITS_FOR_POS>::printPosPattern(byte limb, byte patternId) {
  if (limb < NB_LIMBS && patternId < nbPatterns_) {
    Serial.println("");
    Serial.print("Position pattern ");
    Serial.print(patternId);
    Serial.print(" for limb ");
    Serial.println(limb);

    byte* currPattern = patternArrays_[limb][patternId];
    for (unsigned int ii = 0; ii < SEMIQUAVERS_PER_BEAT; ii++) {
      Serial.print((currPattern[ii] & posMask_) >> BITS_FOR_HIT);
      Serial.print(" ");
    }
    Serial.println("");
  }
}

template <int NB_LIMBS, int BITS_FOR_POS>
void RoboSong<NB_LIMBS, BITS_FOR_POS>::printVelPattern(byte limb, byte patternId) {
  if (limb < NB_LIMBS && patternId < nbPatterns_) {
    Serial.println("");
    Serial.print("Velocity pattern ");
    Serial.print(patternId);
    Serial.print(" for limb ");
    Serial.println(limb);

    byte* currPattern = patternArrays_[limb][patternId];
    for (unsigned int ii = 0; ii < SEMIQUAVERS_PER_BEAT; ii++) {
      Serial.print((currPattern[ii] & velMask_) >> BITS_FOR_HIT + BITS_FOR_POS);
      Serial.print(" ");
    }
    Serial.println("");
  }
}

template <int NB_LIMBS, int BITS_FOR_POS>
unsigned long RoboSong<NB_LIMBS, BITS_FOR_POS>::getMaxTimeToNextHit(){
  unsigned long maxTime = 0;
  for(unsigned int ii=0; ii<NB_LIMBS; ii++){
    if(timeNextHit_[ii] > maxTime){
      maxTime = timeNextHit_[ii];
    }
  }

  return maxTime;
}

// We need to tell the compiler to compile the required templates. This can also be achieved by 
// putting all the implementation on the header file, but we have decided to allow only tested versions
// of the RoboSong<NB_LIMBS, BITS_FOR_HIT, BITS_FOR_POS>

// DrumSong:
template class RoboSong<3, 3>;