#include "drum_song.h"

DrumSong::DrumSong() {
  nbLimbs_ = 3;
  for (unsigned int ii = 0; ii < nbLimbs_; ii++) {
    hitIndexes_[ii] = -1;
    sequenceIndexes_[ii] = 0;
    timeNextHit_[ii] = 0;
  }

  posMask_ = 0;
  velMask_ = 0;

  for (unsigned int ii = BITS_FOR_HIT; ii < BITS_FOR_HIT + BITS_FOR_POS; ii++) {
    bitSet(posMask_, ii);
  }

  for (unsigned int ii = BITS_FOR_HIT + BITS_FOR_POS; ii < 8; ii++) {
    bitSet(velMask_, ii);
  }

  maxVel_ = pow(2, 8 - (BITS_FOR_HIT + BITS_FOR_POS)) - 1;

  nbOfPositions_[RIGHT_ARM] = NB_POS_RIGHT_ARM;
  nbOfPositions_[LEFT_ARM] = NB_POS_LEFT_ARM;
  nbOfPositions_[RIGHT_LEG] = NB_POS_RIGHT_LEG;
}

void DrumSong::createPatterns(bool printOutput) {
}

void DrumSong::createPredefinedPatterns(byte rythmName, bool printOutput = false) {
  switch (rythmName) {
    // -------------------------------------------- SIMPLEST RYTHM -----------------------------------------------------
    case SIMPLEST_RYTHM:
    default:
      {
        if (printOutput) {
          Serial.println("Simplest rythm");
        }
        nbPatterns_ = 1;
        nbBeats_ = 1;
        initializeBlankPatterns(nbPatterns_, nbBeats_);

        byte patternId = 0;

        setQuarterHit(RIGHT_LEG, BDRU, V012, patternId, 1, printOutput);
        setQuarterHit(RIGHT_LEG, BDRU, V008, patternId, 3, printOutput);
        setQuaverHit(RIGHT_LEG, BDRU, V014, patternId, 6, printOutput);

        setQuaverHit(LEFT_ARM, HHAT, V014, patternId, 1, printOutput);
        setQuaverHit(LEFT_ARM, HHAT, V007, patternId, 2, printOutput);
        setQuaverHit(LEFT_ARM, HHAT, V012, patternId, 3, printOutput);
        setQuaverHit(LEFT_ARM, HHAT, V008, patternId, 4, printOutput);
        setQuaverHit(LEFT_ARM, HHAT, V010, patternId, 5, printOutput);
        setQuaverHit(LEFT_ARM, HHAT, V006, patternId, 6, printOutput);
        setQuaverHit(LEFT_ARM, HHAT, V012, patternId, 7, printOutput);
        setQuaverHit(LEFT_ARM, SNLT, V009, patternId, 8, printOutput);

        setQuarterHit(RIGHT_ARM, SNRG, V014, patternId, 1, printOutput);
        setQuarterHit(RIGHT_ARM, SNRG, V014, patternId, 2, printOutput);
        setQuarterHit(RIGHT_ARM, CRSH, V010, patternId, 4, printOutput);

        byte simplestPattSeq[nbBeats_] = { 0 };
        setPatternSequence(simplestPattSeq);

        break;
      }
    case BASIC_RYTHM:
      {
        // -------------------------------------------- BASIC RYTHM -----------------------------------------------------
        if (printOutput) {
          Serial.println("Basic rythm");
        }
        nbPatterns_ = 3;
        nbBeats_ = 10;
        initializeBlankPatterns(nbPatterns_, nbBeats_);

        byte patternId0 = 0;
        byte patternId1 = 1;
        byte patternId2 = 2;

        // Right leg
        // ----------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_LEG, patternId0, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, printOutput);
        setVelPattern(RIGHT_LEG, patternId0, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, printOutput);

        setHitPattern(RIGHT_LEG, patternId1, BDRU, REST, REST, REST, REST, REST, REST, REST, BDRU, REST, BDRU, REST, REST, REST, REST, REST, printOutput);
        setVelPattern(RIGHT_LEG, patternId1, V012, V000, V000, V000, V000, V000, V000, V000, V008, V000, VMAX, V000, V000, V000, V000, V000, printOutput);

        setHitPattern(RIGHT_LEG, patternId2, BDRU, REST, REST, REST, REST, REST, REST, REST, BDRU, REST, BDRU, REST, REST, REST, REST, REST, printOutput);
        setVelPattern(RIGHT_LEG, patternId2, V012, V000, V000, V000, V000, V000, V000, V000, V008, V000, VMAX, V000, V000, V000, V000, V000, printOutput);


        // Left arm
        // ---------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(LEFT_ARM, patternId0, STCK, REST, REST, REST, STCK, REST, REST, REST, STCK, REST, REST, REST, STCK, REST, REST, REST, printOutput);
        setVelPattern(LEFT_ARM, patternId0, V012, V000, V000, V000, V010, V000, V000, V000, V012, V000, V000, V000, V010, V000, V000, V000, printOutput);

        setHitPattern(LEFT_ARM, patternId1, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, printOutput);
        setVelPattern(LEFT_ARM, patternId1, V012, V000, V008, V000, V012, V000, V007, V000, V014, V000, V007, V000, V012, V000, V007, V000, printOutput);

        setHitPattern(LEFT_ARM, patternId2, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, REST, SNLT, REST, SNLT, printOutput);
        setVelPattern(LEFT_ARM, patternId2, V012, V000, V008, V000, V012, V000, V007, V000, V014, V000, V007, V000, V000, V006, V000, V005, printOutput);

        // Right arm
        // ----------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_ARM, patternId0, STCK, REST, REST, REST, STCK, REST, REST, REST, STCK, REST, REST, REST, STCK, REST, REST, REST, printOutput);
        setVelPattern(RIGHT_ARM, patternId0, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, printOutput);

        setHitPattern(RIGHT_ARM, patternId1, CRSH, REST, REST, REST, SNRG, REST, REST, SNRG, REST, REST, REST, REST, SNRG, REST, REST, REST, printOutput);
        setVelPattern(RIGHT_ARM, patternId1, V014, V000, V000, V000, V012, V000, V000, V008, V000, V000, V000, V000, V012, V000, V000, V000, printOutput);

        setHitPattern(RIGHT_ARM, patternId2, REST, REST, REST, REST, SNRG, REST, REST, SNRG, REST, REST, REST, REST, SNRG, REST, SNRG, REST, printOutput);
        setVelPattern(RIGHT_ARM, patternId2, V000, V000, V000, V000, V012, V000, V000, V008, V000, V000, V000, V000, V014, V000, V012, V000, printOutput);

        // Right leg
        // ----------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_LEG, patternId0, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, printOutput);
        setVelPattern(RIGHT_LEG, patternId0, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, printOutput);

        setHitPattern(RIGHT_LEG, patternId1, BDRU, REST, REST, REST, REST, REST, REST, REST, BDRU, REST, BDRU, REST, REST, REST, REST, REST, printOutput);
        setVelPattern(RIGHT_LEG, patternId1, V012, V000, V000, V000, V000, V000, V000, V000, V008, V000, VMAX, V000, V000, V000, V000, V000, printOutput);

        setHitPattern(RIGHT_LEG, patternId2, BDRU, REST, REST, REST, REST, REST, REST, REST, BDRU, REST, BDRU, REST, REST, REST, REST, REST, printOutput);
        setVelPattern(RIGHT_LEG, patternId2, V012, V000, V000, V000, V000, V000, V000, V000, V008, V000, VMAX, V000, V000, V000, V000, V000, printOutput);


        // Left arm
        // ---------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(LEFT_ARM, patternId0, STCK, REST, REST, REST, STCK, REST, REST, REST, STCK, REST, REST, REST, STCK, REST, REST, REST, printOutput);
        setVelPattern(LEFT_ARM, patternId0, V012, V000, V000, V000, V010, V000, V000, V000, V012, V000, V000, V000, V010, V000, V000, V000, printOutput);

        setHitPattern(LEFT_ARM, patternId1, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, printOutput);
        setVelPattern(LEFT_ARM, patternId1, V012, V000, V008, V000, V012, V000, V007, V000, V014, V000, V007, V000, V012, V000, V007, V000, printOutput);

        setHitPattern(LEFT_ARM, patternId2, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, REST, SNLT, REST, SNLT, printOutput);
        setVelPattern(LEFT_ARM, patternId2, V012, V000, V008, V000, V012, V000, V007, V000, V014, V000, V007, V000, V000, V006, V000, V005, printOutput);

        // Right arm
        // ----------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_ARM, patternId0, STCK, REST, REST, REST, STCK, REST, REST, REST, STCK, REST, REST, REST, STCK, REST, REST, REST, printOutput);
        setVelPattern(RIGHT_ARM, patternId0, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, printOutput);

        setHitPattern(RIGHT_ARM, patternId1, CRSH, REST, REST, REST, SNRG, REST, REST, SNRG, REST, REST, REST, REST, SNRG, REST, REST, REST, printOutput);
        setVelPattern(RIGHT_ARM, patternId1, V014, V000, V000, V000, V012, V000, V000, V008, V000, V000, V000, V000, V012, V000, V000, V000, printOutput);

        setHitPattern(RIGHT_ARM, patternId2, REST, REST, REST, REST, SNRG, REST, REST, SNRG, REST, REST, REST, REST, SNRG, REST, SNRG, REST, printOutput);
        setVelPattern(RIGHT_ARM, patternId2, V000, V000, V000, V000, V012, V000, V000, V008, V000, V000, V000, V000, V014, V000, V012, V000, printOutput);
        byte basicPattSeq[nbBeats_] = { 0, 1, 2, 1, 2, 1, 2, 1, 2, 1 };

        setPatternSequence(basicPattSeq);
        break;
      }
    case BASIC_RYTHM_WO_ACC:
      {
        // -------------------------------------------- BASIC RYTHM WITHOUT ACCENTS -----------------------------------------------------
        if (printOutput) {
          Serial.println("Basic rythm without accents");
        }
        nbPatterns_ = 3;
        nbBeats_ = 10;
        initializeBlankPatterns(nbPatterns_, nbBeats_);

        byte patternId0 = 0;
        byte patternId1 = 1;
        byte patternId2 = 2;

        // Right leg
        // ----------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_LEG, patternId0, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, printOutput);
        setVelPattern(RIGHT_LEG, patternId0, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, printOutput);

        setHitPattern(RIGHT_LEG, patternId1, BDRU, REST, REST, REST, REST, REST, REST, REST, BDRU, REST, BDRU, REST, REST, REST, REST, REST, printOutput);
        setVelPattern(RIGHT_LEG, patternId1, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, printOutput);

        setHitPattern(RIGHT_LEG, patternId2, BDRU, REST, REST, REST, REST, REST, REST, REST, BDRU, REST, BDRU, REST, REST, REST, REST, REST, printOutput);
        setVelPattern(RIGHT_LEG, patternId2, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, printOutput);


        // Left arm
        // ---------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(LEFT_ARM, patternId0, STCK, REST, REST, REST, STCK, REST, REST, REST, STCK, REST, REST, REST, STCK, REST, REST, REST, printOutput);
        setVelPattern(LEFT_ARM, patternId0, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, printOutput);

        setHitPattern(LEFT_ARM, patternId1, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, printOutput);
        setVelPattern(LEFT_ARM, patternId1, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, printOutput);

        setHitPattern(LEFT_ARM, patternId2, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, REST, SNLT, REST, SNLT, printOutput);
        setVelPattern(LEFT_ARM, patternId2, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, printOutput);

        // Right arm
        // ----------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_ARM, patternId0, STCK, REST, REST, REST, STCK, REST, REST, REST, STCK, REST, REST, REST, STCK, REST, REST, REST, printOutput);
        setVelPattern(RIGHT_ARM, patternId0, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, printOutput);

        setHitPattern(RIGHT_ARM, patternId1, CRSH, REST, REST, REST, SNRG, REST, REST, SNRG, REST, REST, REST, REST, SNRG, REST, REST, REST, printOutput);
        setVelPattern(RIGHT_ARM, patternId1, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, printOutput);

        setHitPattern(RIGHT_ARM, patternId2, REST, REST, REST, REST, SNRG, REST, REST, SNRG, REST, REST, REST, REST, SNRG, REST, SNRG, REST, printOutput);
        setVelPattern(RIGHT_ARM, patternId2, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, printOutput);

        // Right leg
        // ----------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_LEG, patternId0, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, printOutput);
        setVelPattern(RIGHT_LEG, patternId0, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, printOutput);

        setHitPattern(RIGHT_LEG, patternId1, BDRU, REST, REST, REST, REST, REST, REST, REST, BDRU, REST, BDRU, REST, REST, REST, REST, REST, printOutput);
        setVelPattern(RIGHT_LEG, patternId1, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, printOutput);

        setHitPattern(RIGHT_LEG, patternId2, BDRU, REST, REST, REST, REST, REST, REST, REST, BDRU, REST, BDRU, REST, REST, REST, REST, REST, printOutput);
        setVelPattern(RIGHT_LEG, patternId2, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, printOutput);


        // Left arm
        // ---------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(LEFT_ARM, patternId0, STCK, REST, REST, REST, STCK, REST, REST, REST, STCK, REST, REST, REST, STCK, REST, REST, REST, printOutput);
        setVelPattern(LEFT_ARM, patternId0, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, printOutput);

        setHitPattern(LEFT_ARM, patternId1, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, printOutput);
        setVelPattern(LEFT_ARM, patternId1, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, printOutput);

        setHitPattern(LEFT_ARM, patternId2, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, REST, SNLT, REST, SNLT, printOutput);
        setVelPattern(LEFT_ARM, patternId2, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, printOutput);

        // Right arm
        // ----------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_ARM, patternId0, STCK, REST, REST, REST, STCK, REST, REST, REST, STCK, REST, REST, REST, STCK, REST, REST, REST, printOutput);
        setVelPattern(RIGHT_ARM, patternId0, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, printOutput);

        setHitPattern(RIGHT_ARM, patternId1, CRSH, REST, REST, REST, SNRG, REST, REST, SNRG, REST, REST, REST, REST, SNRG, REST, REST, REST, printOutput);
        setVelPattern(RIGHT_ARM, patternId1, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, printOutput);

        setHitPattern(RIGHT_ARM, patternId2, REST, REST, REST, REST, SNRG, REST, REST, SNRG, REST, REST, REST, REST, SNRG, REST, SNRG, REST, printOutput);
        setVelPattern(RIGHT_ARM, patternId2, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, printOutput);
        byte basicPattSeq[nbBeats_] = { 0, 1, 2, 1, 2, 1, 2, 1, 2, 1 };

        setPatternSequence(basicPattSeq);
        break;
      }
    case CRESCENDO:
      {
        if (printOutput) {
          Serial.println("Crescendo");
        }
        nbPatterns_ = 1;
        nbBeats_ = 1;
        initializeBlankPatterns(nbPatterns_, nbBeats_);

        byte patternId = 0;

        setQuaverHit(RIGHT_LEG, BDRU, V001, patternId, 1, printOutput);
        setQuaverHit(RIGHT_LEG, BDRU, V003, patternId, 2, printOutput);
        setQuaverHit(RIGHT_LEG, BDRU, V005, patternId, 3, printOutput);
        setQuaverHit(RIGHT_LEG, BDRU, V007, patternId, 4, printOutput);
        setQuaverHit(RIGHT_LEG, BDRU, V009, patternId, 5, printOutput);
        setQuaverHit(RIGHT_LEG, BDRU, V011, patternId, 6, printOutput);
        setQuaverHit(RIGHT_LEG, BDRU, V013, patternId, 7, printOutput);
        setQuaverHit(RIGHT_LEG, BDRU, VMAX, patternId, 8, printOutput);

        setQuaverHit(LEFT_ARM, SNLT, V001, patternId, 1, printOutput);
        setQuaverHit(LEFT_ARM, SNLT, V003, patternId, 2, printOutput);
        setQuaverHit(LEFT_ARM, SNLT, V005, patternId, 3, printOutput);
        setQuaverHit(LEFT_ARM, SNLT, V007, patternId, 4, printOutput);
        setQuaverHit(LEFT_ARM, SNLT, V009, patternId, 5, printOutput);
        setQuaverHit(LEFT_ARM, SNLT, V011, patternId, 6, printOutput);
        setQuaverHit(LEFT_ARM, SNLT, V013, patternId, 7, printOutput);
        setQuaverHit(LEFT_ARM, SNLT, VMAX, patternId, 8, printOutput);

        setQuaverHit(RIGHT_ARM, SNRG, V001, patternId, 1, printOutput);
        setQuaverHit(RIGHT_ARM, SNRG, V003, patternId, 2, printOutput);
        setQuaverHit(RIGHT_ARM, SNRG, V005, patternId, 3, printOutput);
        setQuaverHit(RIGHT_ARM, SNRG, V007, patternId, 4, printOutput);
        setQuaverHit(RIGHT_ARM, SNRG, V009, patternId, 5, printOutput);
        setQuaverHit(RIGHT_ARM, SNRG, V011, patternId, 6, printOutput);
        setQuaverHit(RIGHT_ARM, SNRG, V013, patternId, 7, printOutput);
        setQuaverHit(RIGHT_ARM, CRSH, VMAX, patternId, 8, printOutput);

        byte simplestPattSeq[nbBeats_] = { 0 };
        setPatternSequence(simplestPattSeq);

        break;
      }
  }
}

void DrumSong::initializeBlankPatterns(unsigned int nbPatterns, unsigned int nbBeats) {
  nbPatterns_ = nbPatterns;
  nbBeats_ = nbBeats;

  for (int limb = 0; limb < nbLimbs_; limb++) {
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

void DrumSong::computeNextHit(byte limb, bool printOutput = false) {
  signed char* hitIndex = &hitIndexes_[limb];
  byte* sequenceIndex = &sequenceIndexes_[limb];

  // We get the current pattern
  byte patternId = patternSequence_[*sequenceIndex];
  byte* currPattern = patternArrays_[limb][patternId];

  unsigned long timeToNextHit = 0;

  do {
    // We iterate the pattern. When we get to the end we start again
    if (++(*hitIndex) >= SEMIQUAVERS_PER_BEAT) {
      *hitIndex = 0;
      *sequenceIndex = (*sequenceIndex + 1) % nbBeats_;
      patternId = patternSequence_[*sequenceIndex];
      currPattern = patternArrays_[limb][patternId];
    }
    timeToNextHit += timeSemiquaver_;
  } while (!bitRead(currPattern[*hitIndex], 0));

  timeNextHit_[limb] += timeToNextHit;
}

unsigned long DrumSong::getTimeNextHit(byte limb) {
  return timeNextHit_[limb];
}

byte DrumSong::getPosNextHit(byte limb) {
  byte sequenceIndex = sequenceIndexes_[limb];
  byte patternId = patternSequence_[sequenceIndex];
  byte* currPattern = patternArrays_[limb][patternId];
  unsigned char hitIndex = hitIndexes_[limb];

  return ((currPattern[hitIndex] & posMask_) >> BITS_FOR_HIT);
}

byte DrumSong::getVelNextHit(byte limb) {
  byte sequenceIndex = sequenceIndexes_[limb];
  byte patternId = patternSequence_[sequenceIndex];
  byte* currPattern = patternArrays_[limb][patternId];
  unsigned char hitIndex = hitIndexes_[limb];

  return ((currPattern[hitIndex] & velMask_) >> BITS_FOR_HIT + BITS_FOR_POS);
}

void DrumSong::setBpm(unsigned short bpm) {
  bpm_ = bpm;
  timeQuarter_ = int(60000.0 / bpm_);        // us per quarter note
  timeQuaver_ = int(timeQuarter_ / 2.0);     // us per quaver note
  timeSemiquaver_ = int(timeQuaver_ / 2.0);  // us per semiquaver note
}

void DrumSong::setInitialTime(unsigned long initialTime) {
  for (unsigned int ii = 0; ii < nbLimbs_; ii++) {
    timeNextHit_[ii] = initialTime;
  }
}

void DrumSong::setQuarterHit(byte limb, byte pos, byte velocity, byte patternId, byte noteIndex, bool printOutput) {
  byte semiquaversPerNote = 4;
  setHit(limb, pos, velocity, patternId, noteIndex, semiquaversPerNote, printOutput);
}

void DrumSong::setQuaverHit(byte limb, byte pos, byte velocity, byte patternId, byte noteIndex, bool printOutput) {
  byte semiquaversPerNote = 2;
  setHit(limb, pos, velocity, patternId, noteIndex, semiquaversPerNote, printOutput);
}

void DrumSong::setSemiquaverHit(byte limb, byte pos, byte velocity, byte patternId, byte noteIndex, bool printOutput) {
  byte semiquaversPerNote = 1;
  setHit(limb, pos, velocity, patternId, noteIndex, semiquaversPerNote, printOutput);
}

void DrumSong::setHit(byte limb, byte pos, byte vel, byte patternId, byte noteIndex, byte semiquaversPerNote, bool printOutput) {
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

void DrumSong::setQuarterRest(byte limb, byte patternId, byte noteIndex) {
  byte semiquaversPerNote = 4;
  setRest(limb, patternId, noteIndex, semiquaversPerNote);
}

void DrumSong::setQuaverRest(byte limb, byte patternId, byte noteIndex) {
  byte semiquaversPerNote = 2;
  setRest(limb, patternId, noteIndex, semiquaversPerNote);
}

void DrumSong::setSemiquaverRest(byte limb, byte patternId, byte noteIndex) {
  byte semiquaversPerNote = 1;
  setRest(limb, patternId, noteIndex, semiquaversPerNote);
}

void DrumSong::setRest(byte limb, byte patternId, byte noteIndex, byte semiquaversPerNote) {
  if (noteIndex > 0 && semiquaversPerNote * (noteIndex - 1) < SEMIQUAVERS_PER_BEAT) {
    byte* currPattern = patternArrays_[limb][patternId];
    currPattern[semiquaversPerNote * (noteIndex - 1)] = 0;
  }
}

void DrumSong::setHitPattern(byte limb, byte patternId, byte p1, byte p2, byte p3, byte p4, byte p5, byte p6, byte p7,
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

void DrumSong::setVelPattern(byte limb, byte patternId, byte v1, byte v2, byte v3, byte v4, byte v5, byte v6, byte v7, byte v8, byte v9, byte v10, byte v11, byte v12, byte v13, byte v14, byte v15, byte v16, bool printOutput = false) {
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

void DrumSong::setPatternSequence(byte pattSeq[]) {
  for (int ii = 0; ii < nbBeats_; ii++) {
    if (pattSeq[ii] < nbPatterns_) {
      patternSequence_.push_back(pattSeq[ii]);
    } else {
      patternSequence_.push_back(0);
    }
  }
}

void DrumSong::printPatterns() {
  for (unsigned int ii = 0; ii < nbLimbs_; ii++) {
    printPatterns(ii);
  }
}

void DrumSong::printPatterns(byte limb) {
  for (unsigned int ii = 0; ii < nbPatterns_; ii++) {
    printHitPattern(limb, ii);
    printPosPattern(limb, ii);
    printVelPattern(limb, ii);
  }
}

void DrumSong::printHitPattern(byte limb, byte patternId) {
  if (limb < nbLimbs_ && patternId < nbPatterns_) {
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

void DrumSong::printPosPattern(byte limb, byte patternId) {
  if (limb < nbLimbs_ && patternId < nbPatterns_) {
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

void DrumSong::printVelPattern(byte limb, byte patternId) {
  if (limb < nbLimbs_ && patternId < nbPatterns_) {
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
