#include "drum_song.h"

DrumSong::DrumSong() : RoboSong<NB_LIMBS_DRUM, BITS_FOR_POS_DRUM>::RoboSong() {
  nbOfPositions_[RIGHT_ARM] = NB_POS_RIGHT_ARM;
  nbOfPositions_[LEFT_ARM] = NB_POS_LEFT_ARM;
  nbOfPositions_[RIGHT_LEG] = NB_POS_RIGHT_LEG;
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
        setVelPattern(RIGHT_LEG, patternId1, V012, V000, V000, V000, V000, V000, V000, V000, V008, V000, V016, V000, V000, V000, V000, V000, printOutput);

        setHitPattern(RIGHT_LEG, patternId2, BDRU, REST, REST, REST, REST, REST, REST, REST, BDRU, REST, BDRU, REST, REST, REST, REST, REST, printOutput);
        setVelPattern(RIGHT_LEG, patternId2, V012, V000, V000, V000, V000, V000, V000, V000, V008, V000, V016, V000, V000, V000, V000, V000, printOutput);


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
        setVelPattern(RIGHT_LEG, patternId1, V012, V000, V000, V000, V000, V000, V000, V000, V008, V000, V016, V000, V000, V000, V000, V000, printOutput);

        setHitPattern(RIGHT_LEG, patternId2, BDRU, REST, REST, REST, REST, REST, REST, REST, BDRU, REST, BDRU, REST, REST, REST, REST, REST, printOutput);
        setVelPattern(RIGHT_LEG, patternId2, V012, V000, V000, V000, V000, V000, V000, V000, V008, V000, V016, V000, V000, V000, V000, V000, printOutput);


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
        setQuaverHit(RIGHT_LEG, BDRU, V016, patternId, 8, printOutput);

        setQuaverHit(LEFT_ARM, SNLT, V001, patternId, 1, printOutput);
        setQuaverHit(LEFT_ARM, SNLT, V003, patternId, 2, printOutput);
        setQuaverHit(LEFT_ARM, SNLT, V005, patternId, 3, printOutput);
        setQuaverHit(LEFT_ARM, SNLT, V007, patternId, 4, printOutput);
        setQuaverHit(LEFT_ARM, SNLT, V009, patternId, 5, printOutput);
        setQuaverHit(LEFT_ARM, SNLT, V011, patternId, 6, printOutput);
        setQuaverHit(LEFT_ARM, SNLT, V013, patternId, 7, printOutput);
        setQuaverHit(LEFT_ARM, SNLT, V016, patternId, 8, printOutput);

        setQuaverHit(RIGHT_ARM, SNRG, V001, patternId, 1, printOutput);
        setQuaverHit(RIGHT_ARM, SNRG, V003, patternId, 2, printOutput);
        setQuaverHit(RIGHT_ARM, SNRG, V005, patternId, 3, printOutput);
        setQuaverHit(RIGHT_ARM, SNRG, V007, patternId, 4, printOutput);
        setQuaverHit(RIGHT_ARM, SNRG, V009, patternId, 5, printOutput);
        setQuaverHit(RIGHT_ARM, SNRG, V011, patternId, 6, printOutput);
        setQuaverHit(RIGHT_ARM, SNRG, V013, patternId, 7, printOutput);
        setQuaverHit(RIGHT_ARM, CRSH, V016, patternId, 8, printOutput);

        byte simplestPattSeq[nbBeats_] = { 0 };
        setPatternSequence(simplestPattSeq);

        break;
      }
  }
}