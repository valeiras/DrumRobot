#include "drum_song_gr.h"

DrumSongGR::DrumSongGR()
  : PercuSong<NB_LIMBS_DR, BITS_FOR_POS_DR>::PercuSong() {
  nbOfPositions_[RIGHT_ARM_DR] = NB_POS_RA_DR;
  nbOfPositions_[LEFT_ARM_DR] = NB_POS_LA_DR;
  nbOfPositions_[RIGHT_LEG_DR] = NB_POS_RL_DR;
}

void DrumSongGR::createPredefinedPatterns(byte rythmName, bool printOutput = false) {
  switch (rythmName) {
    // -------------------------------------------- SIMPLEST RYTHM -----------------------------------------------------
    case SIMPLEST_RYTHM:
    default:
      {
        nbPatterns_ = 1;
        nbMeasures_ = 1;
        initializeBlankPatterns(nbPatterns_, nbMeasures_);

        byte patternId = 0;

        setQuarterHit(RIGHT_LEG_DR, BDRU, V012, patternId, 1, printOutput);
        setQuarterHit(RIGHT_LEG_DR, BDRU, V008, patternId, 3, printOutput);
        setQuaverHit(RIGHT_LEG_DR, BDRU, V014, patternId, 6, printOutput);

        setQuaverHit(LEFT_ARM_DR, HHAT, V014, patternId, 1, printOutput);
        setQuaverHit(LEFT_ARM_DR, HHAT, V007, patternId, 2, printOutput);
        setQuaverHit(LEFT_ARM_DR, HHAT, V012, patternId, 3, printOutput);
        setQuaverHit(LEFT_ARM_DR, HHAT, V008, patternId, 4, printOutput);
        setQuaverHit(LEFT_ARM_DR, HHAT, V010, patternId, 5, printOutput);
        setQuaverHit(LEFT_ARM_DR, HHAT, V006, patternId, 6, printOutput);
        setQuaverHit(LEFT_ARM_DR, HHAT, V012, patternId, 7, printOutput);
        setQuaverHit(LEFT_ARM_DR, SNLT, V009, patternId, 8, printOutput);

        setQuarterHit(RIGHT_ARM_DR, SNRG, V014, patternId, 1, printOutput);
        setQuarterHit(RIGHT_ARM_DR, SNRG, V014, patternId, 2, printOutput);
        setQuarterHit(RIGHT_ARM_DR, CRSH, V010, patternId, 4, printOutput);

        byte simplestPattSeq[nbMeasures_] = { 0 };
        setPatternSequence(simplestPattSeq);

        break;
      }
    case BASIC_RYTHM:
      {
        // -------------------------------------------- BASIC RYTHM -----------------------------------------------------
        nbPatterns_ = 3;
        nbMeasures_ = 10;
        initializeBlankPatterns(nbPatterns_, nbMeasures_);

        byte patternId0 = 0;
        byte patternId1 = 1;
        byte patternId2 = 2;

        // Right leg
        // ----------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_LEG_DR, patternId0, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, printOutput);
        setVelPattern(RIGHT_LEG_DR, patternId0, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, printOutput);

        setHitPattern(RIGHT_LEG_DR, patternId1, BDRU, REST, REST, REST, REST, REST, REST, REST, BDRU, REST, BDRU, REST, REST, REST, REST, REST, printOutput);
        setVelPattern(RIGHT_LEG_DR, patternId1, V012, V000, V000, V000, V000, V000, V000, V000, V008, V000, V015, V000, V000, V000, V000, V000, printOutput);

        setHitPattern(RIGHT_LEG_DR, patternId2, BDRU, REST, REST, REST, REST, REST, REST, REST, BDRU, REST, BDRU, REST, REST, REST, REST, REST, printOutput);
        setVelPattern(RIGHT_LEG_DR, patternId2, V012, V000, V000, V000, V000, V000, V000, V000, V008, V000, V015, V000, V000, V000, V000, V000, printOutput);


        // Left arm
        // ---------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(LEFT_ARM_DR, patternId0, STCK, REST, REST, REST, STCK, REST, REST, REST, STCK, REST, REST, REST, STCK, REST, REST, REST, printOutput);
        setVelPattern(LEFT_ARM_DR, patternId0, V012, V000, V000, V000, V010, V000, V000, V000, V012, V000, V000, V000, V010, V000, V000, V000, printOutput);

        setHitPattern(LEFT_ARM_DR, patternId1, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, printOutput);
        setVelPattern(LEFT_ARM_DR, patternId1, V012, V000, V008, V000, V012, V000, V007, V000, V014, V000, V007, V000, V012, V000, V007, V000, printOutput);

        setHitPattern(LEFT_ARM_DR, patternId2, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, REST, SNLT, REST, SNLT, printOutput);
        setVelPattern(LEFT_ARM_DR, patternId2, V012, V000, V008, V000, V012, V000, V007, V000, V014, V000, V007, V000, V000, V006, V000, V005, printOutput);

        // Right arm
        // ----------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_ARM_DR, patternId0, STCK, REST, REST, REST, STCK, REST, REST, REST, STCK, REST, REST, REST, STCK, REST, REST, REST, printOutput);
        setVelPattern(RIGHT_ARM_DR, patternId0, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, printOutput);

        setHitPattern(RIGHT_ARM_DR, patternId1, CRSH, REST, REST, REST, SNRG, REST, REST, SNRG, REST, REST, REST, REST, SNRG, REST, REST, REST, printOutput);
        setVelPattern(RIGHT_ARM_DR, patternId1, V014, V000, V000, V000, V012, V000, V000, V008, V000, V000, V000, V000, V012, V000, V000, V000, printOutput);

        setHitPattern(RIGHT_ARM_DR, patternId2, REST, REST, REST, REST, SNRG, REST, REST, SNRG, REST, REST, REST, REST, SNRG, REST, SNRG, REST, printOutput);
        setVelPattern(RIGHT_ARM_DR, patternId2, V000, V000, V000, V000, V012, V000, V000, V008, V000, V000, V000, V000, V014, V000, V012, V000, printOutput);

        // Right leg
        // ----------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_LEG_DR, patternId0, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, printOutput);
        setVelPattern(RIGHT_LEG_DR, patternId0, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, printOutput);

        setHitPattern(RIGHT_LEG_DR, patternId1, BDRU, REST, REST, REST, REST, REST, REST, REST, BDRU, REST, BDRU, REST, REST, REST, REST, REST, printOutput);
        setVelPattern(RIGHT_LEG_DR, patternId1, V012, V000, V000, V000, V000, V000, V000, V000, V008, V000, V015, V000, V000, V000, V000, V000, printOutput);

        setHitPattern(RIGHT_LEG_DR, patternId2, BDRU, REST, REST, REST, REST, REST, REST, REST, BDRU, REST, BDRU, REST, REST, REST, REST, REST, printOutput);
        setVelPattern(RIGHT_LEG_DR, patternId2, V012, V000, V000, V000, V000, V000, V000, V000, V008, V000, V015, V000, V000, V000, V000, V000, printOutput);


        // Left arm
        // ---------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(LEFT_ARM_DR, patternId0, STCK, REST, REST, REST, STCK, REST, REST, REST, STCK, REST, REST, REST, STCK, REST, REST, REST, printOutput);
        setVelPattern(LEFT_ARM_DR, patternId0, V012, V000, V000, V000, V010, V000, V000, V000, V012, V000, V000, V000, V010, V000, V000, V000, printOutput);

        setHitPattern(LEFT_ARM_DR, patternId1, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, printOutput);
        setVelPattern(LEFT_ARM_DR, patternId1, V012, V000, V008, V000, V012, V000, V007, V000, V014, V000, V007, V000, V012, V000, V007, V000, printOutput);

        setHitPattern(LEFT_ARM_DR, patternId2, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, REST, SNLT, REST, SNLT, printOutput);
        setVelPattern(LEFT_ARM_DR, patternId2, V012, V000, V008, V000, V012, V000, V007, V000, V014, V000, V007, V000, V000, V006, V000, V005, printOutput);

        // Right arm
        // ----------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_ARM_DR, patternId0, STCK, REST, REST, REST, STCK, REST, REST, REST, STCK, REST, REST, REST, STCK, REST, REST, REST, printOutput);
        setVelPattern(RIGHT_ARM_DR, patternId0, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, printOutput);

        setHitPattern(RIGHT_ARM_DR, patternId1, CRSH, REST, REST, REST, SNRG, REST, REST, SNRG, REST, REST, REST, REST, SNRG, REST, REST, REST, printOutput);
        setVelPattern(RIGHT_ARM_DR, patternId1, V014, V000, V000, V000, V012, V000, V000, V008, V000, V000, V000, V000, V012, V000, V000, V000, printOutput);

        setHitPattern(RIGHT_ARM_DR, patternId2, REST, REST, REST, REST, SNRG, REST, REST, SNRG, REST, REST, REST, REST, SNRG, REST, SNRG, REST, printOutput);
        setVelPattern(RIGHT_ARM_DR, patternId2, V000, V000, V000, V000, V012, V000, V000, V008, V000, V000, V000, V000, V014, V000, V012, V000, printOutput);
        byte basicPattSeq[nbMeasures_] = { 0, 1, 2, 1, 2, 1, 2, 1, 2, 1 };

        setPatternSequence(basicPattSeq);
        break;
      }
    case BASIC_RYTHM_WO_ACC:
      {
        // -------------------------------------------- BASIC RYTHM WITHOUT ACCENTS -----------------------------------------------------
        nbPatterns_ = 3;
        nbMeasures_ = 10;
        initializeBlankPatterns(nbPatterns_, nbMeasures_);

        byte patternId0 = 0;
        byte patternId1 = 1;
        byte patternId2 = 2;

        // Right leg
        // ----------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_LEG_DR, patternId0, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, printOutput);
        setVelPattern(RIGHT_LEG_DR, patternId0, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, printOutput);

        setHitPattern(RIGHT_LEG_DR, patternId1, BDRU, REST, REST, REST, REST, REST, REST, REST, BDRU, REST, BDRU, REST, REST, REST, REST, REST, printOutput);
        setVelPattern(RIGHT_LEG_DR, patternId1, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, printOutput);

        setHitPattern(RIGHT_LEG_DR, patternId2, BDRU, REST, REST, REST, REST, REST, REST, REST, BDRU, REST, BDRU, REST, REST, REST, REST, REST, printOutput);
        setVelPattern(RIGHT_LEG_DR, patternId2, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, printOutput);


        // Left arm
        // ---------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(LEFT_ARM_DR, patternId0, STCK, REST, REST, REST, STCK, REST, REST, REST, STCK, REST, REST, REST, STCK, REST, REST, REST, printOutput);
        setVelPattern(LEFT_ARM_DR, patternId0, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, printOutput);

        setHitPattern(LEFT_ARM_DR, patternId1, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, printOutput);
        setVelPattern(LEFT_ARM_DR, patternId1, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, printOutput);

        setHitPattern(LEFT_ARM_DR, patternId2, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, REST, SNLT, REST, SNLT, printOutput);
        setVelPattern(LEFT_ARM_DR, patternId2, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, printOutput);

        // Right arm
        // ----------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_ARM_DR, patternId0, STCK, REST, REST, REST, STCK, REST, REST, REST, STCK, REST, REST, REST, STCK, REST, REST, REST, printOutput);
        setVelPattern(RIGHT_ARM_DR, patternId0, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, printOutput);

        setHitPattern(RIGHT_ARM_DR, patternId1, CRSH, REST, REST, REST, SNRG, REST, REST, SNRG, REST, REST, REST, REST, SNRG, REST, REST, REST, printOutput);
        setVelPattern(RIGHT_ARM_DR, patternId1, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, printOutput);

        setHitPattern(RIGHT_ARM_DR, patternId2, REST, REST, REST, REST, SNRG, REST, REST, SNRG, REST, REST, REST, REST, SNRG, REST, SNRG, REST, printOutput);
        setVelPattern(RIGHT_ARM_DR, patternId2, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, printOutput);

        // Right leg
        // ----------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_LEG_DR, patternId0, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, printOutput);
        setVelPattern(RIGHT_LEG_DR, patternId0, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, printOutput);

        setHitPattern(RIGHT_LEG_DR, patternId1, BDRU, REST, REST, REST, REST, REST, REST, REST, BDRU, REST, BDRU, REST, REST, REST, REST, REST, printOutput);
        setVelPattern(RIGHT_LEG_DR, patternId1, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, printOutput);

        setHitPattern(RIGHT_LEG_DR, patternId2, BDRU, REST, REST, REST, REST, REST, REST, REST, BDRU, REST, BDRU, REST, REST, REST, REST, REST, printOutput);
        setVelPattern(RIGHT_LEG_DR, patternId2, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, printOutput);


        // Left arm
        // ---------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(LEFT_ARM_DR, patternId0, STCK, REST, REST, REST, STCK, REST, REST, REST, STCK, REST, REST, REST, STCK, REST, REST, REST, printOutput);
        setVelPattern(LEFT_ARM_DR, patternId0, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, printOutput);

        setHitPattern(LEFT_ARM_DR, patternId1, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, printOutput);
        setVelPattern(LEFT_ARM_DR, patternId1, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, printOutput);

        setHitPattern(LEFT_ARM_DR, patternId2, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, REST, SNLT, REST, SNLT, printOutput);
        setVelPattern(LEFT_ARM_DR, patternId2, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, printOutput);

        // Right arm
        // ----------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_ARM_DR, patternId0, STCK, REST, REST, REST, STCK, REST, REST, REST, STCK, REST, REST, REST, STCK, REST, REST, REST, printOutput);
        setVelPattern(RIGHT_ARM_DR, patternId0, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, printOutput);

        setHitPattern(RIGHT_ARM_DR, patternId1, CRSH, REST, REST, REST, SNRG, REST, REST, SNRG, REST, REST, REST, REST, SNRG, REST, REST, REST, printOutput);
        setVelPattern(RIGHT_ARM_DR, patternId1, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, printOutput);

        setHitPattern(RIGHT_ARM_DR, patternId2, REST, REST, REST, REST, SNRG, REST, REST, SNRG, REST, REST, REST, REST, SNRG, REST, SNRG, REST, printOutput);
        setVelPattern(RIGHT_ARM_DR, patternId2, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, printOutput);
        byte basicPattSeq[nbMeasures_] = { 0, 1, 2, 1, 2, 1, 2, 1, 2, 1 };

        setPatternSequence(basicPattSeq);
        break;
      }
    case CRESCENDO:
      {
        nbPatterns_ = 1;
        nbMeasures_ = 1;
        initializeBlankPatterns(nbPatterns_, nbMeasures_);

        byte patternId = 0;

        setQuaverHit(RIGHT_LEG_DR, BDRU, V001, patternId, 1, printOutput);
        setQuaverHit(RIGHT_LEG_DR, BDRU, V003, patternId, 2, printOutput);
        setQuaverHit(RIGHT_LEG_DR, BDRU, V005, patternId, 3, printOutput);
        setQuaverHit(RIGHT_LEG_DR, BDRU, V007, patternId, 4, printOutput);
        setQuaverHit(RIGHT_LEG_DR, BDRU, V009, patternId, 5, printOutput);
        setQuaverHit(RIGHT_LEG_DR, BDRU, V011, patternId, 6, printOutput);
        setQuaverHit(RIGHT_LEG_DR, BDRU, V013, patternId, 7, printOutput);
        setQuaverHit(RIGHT_LEG_DR, BDRU, V015, patternId, 8, printOutput);

        setQuaverHit(LEFT_ARM_DR, SNLT, V001, patternId, 1, printOutput);
        setQuaverHit(LEFT_ARM_DR, SNLT, V003, patternId, 2, printOutput);
        setQuaverHit(LEFT_ARM_DR, SNLT, V005, patternId, 3, printOutput);
        setQuaverHit(LEFT_ARM_DR, SNLT, V007, patternId, 4, printOutput);
        setQuaverHit(LEFT_ARM_DR, SNLT, V009, patternId, 5, printOutput);
        setQuaverHit(LEFT_ARM_DR, SNLT, V011, patternId, 6, printOutput);
        setQuaverHit(LEFT_ARM_DR, SNLT, V013, patternId, 7, printOutput);
        setQuaverHit(LEFT_ARM_DR, SNLT, V015, patternId, 8, printOutput);

        setQuaverHit(RIGHT_ARM_DR, SNRG, V001, patternId, 1, printOutput);
        setQuaverHit(RIGHT_ARM_DR, SNRG, V003, patternId, 2, printOutput);
        setQuaverHit(RIGHT_ARM_DR, SNRG, V005, patternId, 3, printOutput);
        setQuaverHit(RIGHT_ARM_DR, SNRG, V007, patternId, 4, printOutput);
        setQuaverHit(RIGHT_ARM_DR, SNRG, V009, patternId, 5, printOutput);
        setQuaverHit(RIGHT_ARM_DR, SNRG, V011, patternId, 6, printOutput);
        setQuaverHit(RIGHT_ARM_DR, SNRG, V013, patternId, 7, printOutput);
        setQuaverHit(RIGHT_ARM_DR, CRSH, V015, patternId, 8, printOutput);

        byte simplestPattSeq[nbMeasures_] = { 0 };
        setPatternSequence(simplestPattSeq);

        break;
      }
    case QUARTER_NOTES:
      {
        nbPatterns_ = 1;
        nbMeasures_ = 1;
        initializeBlankPatterns(nbPatterns_, nbMeasures_);

        byte patternId = 0;

        setQuarterHit(RIGHT_LEG_DR, BDRU, V015, patternId, 1, printOutput);
        setQuarterHit(RIGHT_LEG_DR, BDRU, V015, patternId, 2, printOutput);
        setQuarterHit(RIGHT_LEG_DR, BDRU, V015, patternId, 3, printOutput);
        setQuarterHit(RIGHT_LEG_DR, BDRU, V015, patternId, 4, printOutput);

        setQuarterHit(LEFT_ARM_DR, SNLT, V015, patternId, 1, printOutput);
        setQuarterHit(LEFT_ARM_DR, SNLT, V015, patternId, 2, printOutput);
        setQuarterHit(LEFT_ARM_DR, SNLT, V015, patternId, 3, printOutput);
        setQuarterHit(LEFT_ARM_DR, SNLT, V015, patternId, 4, printOutput);

        setQuarterHit(RIGHT_ARM_DR, SNRG, V015, patternId, 1, printOutput);
        setQuarterHit(RIGHT_ARM_DR, SNRG, V015, patternId, 2, printOutput);
        setQuarterHit(RIGHT_ARM_DR, SNRG, V015, patternId, 3, printOutput);
        setQuarterHit(RIGHT_ARM_DR, SNRG, V015, patternId, 4, printOutput);

        byte simplestPattSeq[nbMeasures_] = { 0 };
        setPatternSequence(simplestPattSeq);

        break;
      }
  }
}