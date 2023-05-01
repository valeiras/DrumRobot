#include "drum_song_ld.h"

DrumSongLD::DrumSongLD()
  : PercuSong<NB_HIT_JOINTS_DR, BITS_FOR_POS_DR>::PercuSong() {
  nbOfPositions_[RIGHT_ARM_DR] = NB_POS_RA_DR;
  nbOfPositions_[LEFT_ARM_DR] = NB_POS_LA_DR;
  nbOfPositions_[RIGHT_LEG_DR] = NB_POS_RL_DR;
  nbOfPositions_[HEAD_DR] = NB_POS_HD_DR;
}

void DrumSongLD::createPredefinedPatterns(Songs songName, bool hasOutput = false) {
  switch (songName) {
    case FRERE_JACQUES:
      {
        // -------------------------------------------- BASIC RYTHM -----------------------------------------------------
        nbPatterns_ = 2;
        nbMeasures_ = 8;
        initializeBlankPatterns(nbPatterns_, nbMeasures_);

        byte patternId0 = 0;
        byte patternId1 = 1;


        // Head
        // ----------------------------------------0001----------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(HEAD_DR, patternId0, HEAD, REST, REST, REST, HEAD, REST, REST, REST, HEAD, REST, REST, REST, HEAD, REST, REST, REST, hasOutput);
        setVelPattern(HEAD_DR, patternId0, V012, V000, V000, V000, V000, V000, V000, V000, V008, V000, V015, V000, V000, V000, V000, V000, hasOutput);

        setHitPattern(HEAD_DR, patternId1, HEAD, REST, REST, REST, HEAD, REST, REST, REST, HEAD, REST, HEAD, REST, HEAD, REST, REST, REST, hasOutput);
        setVelPattern(HEAD_DR, patternId1, V012, V000, V000, V000, V000, V000, V000, V000, V008, V000, V015, V000, V000, V000, V000, V000, hasOutput);

        // Right leg
        // ----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_LEG_DR, patternId0, BDRU, REST, REST, REST, REST, REST, REST, REST, BDRU, REST, REST, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_LEG_DR, patternId0, V012, V000, V000, V000, V000, V000, V000, V000, V008, V000, V015, V000, V000, V000, V000, V000, hasOutput);

        setHitPattern(RIGHT_LEG_DR, patternId1, BDRU, REST, REST, REST, REST, REST, REST, REST, BDRU, REST, BDRU, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_LEG_DR, patternId1, V012, V000, V000, V000, V000, V000, V000, V000, V008, V000, V015, V000, V000, V000, V000, V000, hasOutput);


        // Left arm
        // ---------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(LEFT_ARM_DR, patternId0, REST, REST, HHSN, REST, HHSN, REST, HHSN, REST, HHSN, REST, HHSN, REST, HHSN, REST, HHSN, REST, hasOutput);
        setVelPattern(LEFT_ARM_DR, patternId0, V000, V000, V008, V000, V012, V000, V007, V000, V014, V000, V007, V000, V012, V000, V007, V000, hasOutput);

        setHitPattern(LEFT_ARM_DR, patternId1, HHSN, REST, HHSN, REST, HHSN, REST, HHSN, REST, HHSN, REST, REST, REST, REST, SNSN, REST, SNCR, hasOutput);
        setVelPattern(LEFT_ARM_DR, patternId1, V012, V000, V008, V000, V012, V000, V007, V000, V014, V000, V007, V000, V000, V006, V000, V005, hasOutput);

        // Right arm
        // ---------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_ARM_DR, patternId0, SNCR, REST, REST, REST, HHSN, REST, REST, REST, REST, REST, REST, REST, HHSN, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_ARM_DR, patternId0, V014, V000, V000, V000, V012, V000, V000, V008, V000, V000, V000, V000, V012, V000, V000, V000, hasOutput);

        setHitPattern(RIGHT_ARM_DR, patternId1, REST, REST, REST, REST, HHSN, REST, REST, HHSN, REST, REST, REST, REST, SNSN, REST, SNSN, REST, hasOutput);
        setVelPattern(RIGHT_ARM_DR, patternId1, V000, V000, V000, V000, V012, V000, V000, V008, V000, V000, V000, V000, V014, V000, V012, V000, hasOutput);

        byte frereJacquesPattSeq[nbMeasures_] = { 0, 1, 0, 1, 0, 1, 0, 1 };

        setPatternSequence(frereJacquesPattSeq);
        break;
      }
    case HOUND_DOG:
      {
        // -------------------------------------------- HOUND DOG -----------------------------------------------------
        nbPatterns_ = 3;
        nbMeasures_ = 6;
        initializeBlankPatterns(nbPatterns_, nbMeasures_);

        byte patternId0 = 0;
        byte patternId1 = 1;
        byte patternId2 = 2;

        // Head
        // ----------------------------------------0001----------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(HEAD_DR, patternId0, HEAD, REST, REST, REST, HEAD, REST, REST, REST, HEAD, REST, REST, REST, HEAD, REST, REST, REST, hasOutput);
        setVelPattern(HEAD_DR, patternId0, V012, V000, V000, V000, V000, V000, V000, V000, V008, V000, V015, V000, V000, V000, V000, V000, hasOutput);

        setHitPattern(HEAD_DR, patternId1, HEAD, REST, REST, REST, HEAD, REST, REST, REST, HEAD, REST, REST, REST, HEAD, REST, REST, REST, hasOutput);
        setVelPattern(HEAD_DR, patternId1, V012, V000, V000, V000, V000, V000, V000, V000, V008, V000, V015, V000, V000, V000, V000, V000, hasOutput);

        setHitPattern(HEAD_DR, patternId2, HEAD, REST, REST, REST, HEAD, REST, REST, REST, HEAD, REST, HEAD, REST, HEAD, REST, REST, REST, hasOutput);
        setVelPattern(HEAD_DR, patternId2, V012, V000, V000, V000, V000, V000, V000, V000, V008, V000, V015, V000, V000, V000, V000, V000, hasOutput);

        // Right leg
        // ----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_LEG_DR, patternId0, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_LEG_DR, patternId0, V012, V000, V000, V000, V012, V000, V000, V000, V008, V000, V015, V000, V000, V000, V000, V000, hasOutput);

        setHitPattern(RIGHT_LEG_DR, patternId1, BDRU, REST, REST, REST, REST, REST, REST, REST, BDRU, REST, REST, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_LEG_DR, patternId1, V012, V000, V000, V000, V000, V000, V000, V000, V008, V000, V015, V000, V000, V000, V000, V000, hasOutput);

        setHitPattern(RIGHT_LEG_DR, patternId2, BDRU, REST, REST, REST, REST, REST, REST, REST, BDRU, REST, BDRU, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_LEG_DR, patternId2, V012, V000, V000, V000, V000, V000, V000, V000, V008, V000, V015, V000, V000, V000, V000, V000, hasOutput);


        // Left arm
        // ---------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(LEFT_ARM_DR, patternId0, SNCR, REST, REST, REST, SNCR, REST, REST, REST, SNCR, REST, REST, REST, SNCR, REST, REST, REST, hasOutput);
        setVelPattern(LEFT_ARM_DR, patternId0, V006, V008, V000, V009, V008, V000, V007, V000, V010, V000, V007, V000, V012, V000, V007, V000, hasOutput);

        setHitPattern(LEFT_ARM_DR, patternId1, REST, REST, HHSN, REST, HHSN, REST, HHSN, REST, HHSN, REST, HHSN, REST, HHSN, REST, HHSN, REST, hasOutput);
        setVelPattern(LEFT_ARM_DR, patternId1, V000, V000, V008, V000, V012, V000, V007, V000, V014, V000, V007, V000, V012, V000, V007, V000, hasOutput);

        setHitPattern(LEFT_ARM_DR, patternId2, HHSN, REST, HHSN, REST, HHSN, REST, HHSN, REST, HHSN, REST, REST, REST, REST, SNSN, REST, SNCR, hasOutput);
        setVelPattern(LEFT_ARM_DR, patternId2, V012, V000, V008, V000, V012, V000, V007, V000, V014, V000, V007, V000, V000, V006, V000, V005, hasOutput);

        // Right arm
        // ---------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_ARM_DR, patternId0, SNSN, REST, SNSN, REST, SNSN, REST, SNCR, REST, SNCR, REST, REST, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_ARM_DR, patternId0, V014, V000, V012, V000, V012, V000, V009, V008, V014, V000, V000, V000, V000, V000, V000, V000, hasOutput);

        setHitPattern(RIGHT_ARM_DR, patternId1, SNCR, REST, REST, REST, HHSN, REST, REST, REST, REST, REST, REST, REST, HHSN, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_ARM_DR, patternId1, V014, V000, V000, V000, V012, V000, V000, V008, V000, V000, V000, V000, V012, V000, V000, V000, hasOutput);

        setHitPattern(RIGHT_ARM_DR, patternId1, REST, REST, REST, REST, HHSN, REST, REST, HHSN, REST, REST, REST, REST, SNSN, REST, SNSN, REST, hasOutput);
        setVelPattern(RIGHT_ARM_DR, patternId1, V000, V000, V000, V000, V012, V000, V000, V008, V000, V000, V000, V000, V014, V000, V012, V000, hasOutput);

        byte houndDogPattSeq[nbMeasures_] = { 0, 1, 2, 1, 2, 1 };

        setPatternSequence(houndDogPattSeq);
        break;
      }
    case RUDY:
      {
        // -------------------------------------------- RUDY -----------------------------------------------------
        nbPatterns_ = 3;
        nbMeasures_ = 10;
        initializeBlankPatterns(nbPatterns_, nbMeasures_);

        byte patternId0 = 0;
        byte patternId1 = 1;
        byte patternId2 = 2;

        // --------------------------------------------- Pattern 0--------------------------------------------------------------
        setQuarterHit(HEAD_DR, BDRU, V008, patternId0, 1, hasOutput);
        setQuarterHit(HEAD_DR, BDRU, V008, patternId0, 2, hasOutput);
        setQuarterHit(HEAD_DR, BDRU, V008, patternId0, 3, hasOutput);
        setQuarterHit(HEAD_DR, BDRU, V008, patternId0, 4, hasOutput);

        setQuarterHit(RIGHT_LEG_DR, BDRU, V008, patternId0, 4, hasOutput);

        setQuarterHit(LEFT_ARM_DR, SNCR, V013, patternId0, 1, hasOutput);
        setQuarterHit(LEFT_ARM_DR, SNCR, V012, patternId0, 2, hasOutput);
        setQuarterHit(LEFT_ARM_DR, SNCR, V015, patternId0, 3, hasOutput);
        setQuarterHit(LEFT_ARM_DR, SNCR, V015, patternId0, 4, hasOutput);

        setQuarterHit(RIGHT_ARM_DR, SNCR, V013, patternId0, 1, hasOutput);
        setQuarterHit(RIGHT_ARM_DR, SNCR, V012, patternId0, 2, hasOutput);
        setQuarterHit(RIGHT_ARM_DR, SNCR, V015, patternId0, 3, hasOutput);
        setQuarterHit(RIGHT_ARM_DR, SNCR, V015, patternId0, 4, hasOutput);

        // --------------------------------------------- Pattern 1--------------------------------------------------------------
        setQuarterHit(HEAD_DR, BDRU, V008, patternId1, 1, hasOutput);
        setQuarterHit(HEAD_DR, BDRU, V008, patternId1, 2, hasOutput);
        setQuarterHit(HEAD_DR, BDRU, V008, patternId1, 3, hasOutput);
        setQuarterHit(HEAD_DR, BDRU, V008, patternId1, 4, hasOutput);

        setQuarterHit(RIGHT_LEG_DR, BDRU, V012, patternId1, 1, hasOutput);
        setQuarterHit(RIGHT_LEG_DR, BDRU, V008, patternId1, 3, hasOutput);

        setQuaverHit(LEFT_ARM_DR, HHSN, V007, patternId1, 1, hasOutput);
        setQuaverHit(LEFT_ARM_DR, HHSN, V007, patternId1, 2, hasOutput);
        setQuaverHit(LEFT_ARM_DR, HHSN, V012, patternId1, 3, hasOutput);
        setQuaverHit(LEFT_ARM_DR, HHSN, V008, patternId1, 4, hasOutput);
        setQuaverHit(LEFT_ARM_DR, HHSN, V010, patternId1, 5, hasOutput);
        setQuaverHit(LEFT_ARM_DR, HHSN, V006, patternId1, 6, hasOutput);
        setQuaverHit(LEFT_ARM_DR, HHSN, V012, patternId1, 7, hasOutput);
        setQuaverHit(LEFT_ARM_DR, HHSN, V009, patternId1, 8, hasOutput);

        setQuarterHit(RIGHT_ARM_DR, HHSN, V014, patternId1, 2, hasOutput);
        setQuarterHit(RIGHT_ARM_DR, HHSN, V014, patternId1, 4, hasOutput);

        // --------------------------------------------- Pattern 2--------------------------------------------------------------
        setQuarterHit(HEAD_DR, BDRU, V008, patternId2, 1, hasOutput);
        setQuarterHit(HEAD_DR, BDRU, V008, patternId2, 2, hasOutput);
        setQuarterHit(HEAD_DR, BDRU, V008, patternId2, 3, hasOutput);
        setQuarterHit(HEAD_DR, BDRU, V008, patternId2, 4, hasOutput);

        setQuarterHit(RIGHT_LEG_DR, BDRU, V012, patternId2, 1, hasOutput);
        setQuarterHit(RIGHT_LEG_DR, BDRU, V008, patternId2, 3, hasOutput);
        setSemiquaverHit(RIGHT_LEG_DR, BDRU, V014, patternId2, 11, hasOutput);

        setQuaverHit(LEFT_ARM_DR, HHSN, V007, patternId2, 1, hasOutput);
        setQuaverHit(LEFT_ARM_DR, HHSN, V007, patternId2, 2, hasOutput);
        setQuaverHit(LEFT_ARM_DR, HHSN, V012, patternId2, 3, hasOutput);
        setQuaverHit(LEFT_ARM_DR, HHSN, V008, patternId2, 4, hasOutput);
        setQuaverHit(LEFT_ARM_DR, HHSN, V010, patternId2, 5, hasOutput);
        setQuaverHit(LEFT_ARM_DR, HHSN, V006, patternId2, 6, hasOutput);
        setQuaverHit(LEFT_ARM_DR, HHSN, V012, patternId2, 7, hasOutput);
        setQuaverHit(LEFT_ARM_DR, HHSN, V009, patternId2, 8, hasOutput);

        setQuarterHit(RIGHT_ARM_DR, HHSN, V014, patternId2, 2, hasOutput);
        setQuarterHit(RIGHT_ARM_DR, HHSN, V015, patternId2, 4, hasOutput);

        byte rudyPattSeq[nbMeasures_] = { 0, 1, 2, 1, 2, 1, 2, 1, 2, 1 };
        setPatternSequence(rudyPattSeq);
        break;
      }
      // -------------------------------------------- SMOKE -----------------------------------------------------
    case SMOKE:
      {
        nbPatterns_ = 3;
        nbMeasures_ = 22;
        initializeBlankPatterns(nbPatterns_, nbMeasures_);

        byte patternId0 = 0;
        byte patternId1 = 1;
        byte patternId2 = 2;

        // Head
        // ----------------------------------------0001----------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(HEAD_DR, patternId0, HEAD, REST, REST, REST, HEAD, REST, REST, REST, HEAD, REST, REST, REST, HEAD, REST, REST, REST, hasOutput);
        setVelPattern(HEAD_DR, patternId0, V012, V000, V000, V000, V000, V000, V000, V000, V008, V000, V015, V000, V000, V000, V000, V000, hasOutput);

        setHitPattern(HEAD_DR, patternId1, HEAD, REST, REST, REST, HEAD, REST, REST, REST, HEAD, REST, REST, REST, HEAD, REST, REST, REST, hasOutput);
        setVelPattern(HEAD_DR, patternId1, V012, V000, V000, V000, V000, V000, V000, V000, V008, V000, V015, V000, V000, V000, V000, V000, hasOutput);

        setHitPattern(HEAD_DR, patternId2, HEAD, REST, REST, REST, HEAD, REST, REST, REST, HEAD, REST, HEAD, REST, HEAD, REST, REST, REST, hasOutput);
        setVelPattern(HEAD_DR, patternId2, V012, V000, V000, V000, V000, V000, V000, V000, V008, V000, V015, V000, V000, V000, V000, V000, hasOutput);

        // Right leg
        // -----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_LEG_DR, patternId0, BDRU, REST, REST, REST, REST, REST, REST, REST, BDRU, REST, REST, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_LEG_DR, patternId0, V012, V000, V000, V000, V000, V000, V000, V000, V008, V000, V015, V000, V000, V000, V000, V000, hasOutput);

        setHitPattern(RIGHT_LEG_DR, patternId1, BDRU, REST, REST, REST, REST, REST, REST, REST, BDRU, REST, REST, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_LEG_DR, patternId1, V012, V000, V000, V000, V000, V000, V000, V000, V008, V000, V015, V000, V000, V000, V000, V000, hasOutput);

        setHitPattern(RIGHT_LEG_DR, patternId2, BDRU, REST, REST, REST, BDRU, REST, REST, REST, BDRU, REST, REST, REST, BDRU, REST, BDRU, REST, hasOutput);
        setVelPattern(RIGHT_LEG_DR, patternId2, V012, V000, V000, V000, V012, V000, V000, V000, V008, V000, V015, V000, V006, V000, V004, V000, hasOutput);


        // Left arm
        // ----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------

        setHitPattern(LEFT_ARM_DR, patternId0, HHSN, HHSN, HHSN, HHSN, HHSN, HHSN, HHSN, HHSN, HHSN, HHSN, HHSN, HHSN, HHSN, HHSN, HHSN, HHSN, hasOutput);
        setVelPattern(LEFT_ARM_DR, patternId0, V012, V000, V008, V000, V012, V000, V007, V000, V014, V000, V007, V000, V012, V000, V007, V000, hasOutput);

        setHitPattern(LEFT_ARM_DR, patternId1, HHSN, REST, HHSN, REST, HHSN, REST, HHSN, REST, HHSN, REST, HHSN, REST, HHSN, REST, HHSN, REST, hasOutput);
        setVelPattern(LEFT_ARM_DR, patternId1, V012, V000, V008, V000, V012, V000, V007, V000, V014, V000, V007, V000, V012, V006, V008, V005, hasOutput);

        setHitPattern(LEFT_ARM_DR, patternId2, SNCR, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(LEFT_ARM_DR, patternId2, V012, V000, V008, V000, V012, V000, V007, V000, V014, V000, V007, V000, V012, V006, V008, V005, hasOutput);

        // Right arm
        // ---------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_ARM_DR, patternId0, REST, REST, REST, REST, HHSN, REST, REST, REST, REST, REST, REST, REST, HHSN, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_ARM_DR, patternId0, V014, V000, V000, V000, V012, V000, V000, V008, V000, V000, V000, V000, V012, V000, V000, V000, hasOutput);

        setHitPattern(RIGHT_ARM_DR, patternId1, REST, REST, REST, REST, HHSN, REST, REST, REST, REST, REST, REST, REST, HHSN, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_ARM_DR, patternId1, V000, V000, V000, V000, V012, V000, V000, V008, V000, V000, V000, V000, V014, V000, V012, V000, hasOutput);

        setHitPattern(RIGHT_ARM_DR, patternId2, SNCR, REST, REST, REST, SNCR, REST, REST, REST, SNCR, REST, REST, REST, SNCR, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_ARM_DR, patternId2, V012, V000, V000, V000, V012, V000, V000, V008, V012, V000, V000, V000, V014, V000, V012, V000, hasOutput);

        byte smokePattSeq[nbMeasures_] = { 0, 0, 0, 0, 0, 0, 0, 0,
                                           1, 1, 1, 1, 1, 1, 1, 1,
                                           2, 2, 1, 1, 2, 2 };
        setPatternSequence(smokePattSeq);

        break;
      }
      // -------------------------------------------- SMELLS LIKE -----------------------------------------------------
    case SMELLS_LIKE:
      {
        nbPatterns_ = 4;
        nbMeasures_ = 20;
        initializeBlankPatterns(nbPatterns_, nbMeasures_);

        byte patternId0 = 0;
        byte patternId1 = 1;
        byte patternId2 = 2;
        byte patternId3 = 3;

        // Pattern 0: empty
        setHitPattern(HEAD_DR, patternId0, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, hasOutput);
        // -----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_LEG_DR, patternId0, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, hasOutput);
        // ----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(LEFT_ARM_DR, patternId0, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, hasOutput);
        // ----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_ARM_DR, patternId0, SNCR, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_ARM_DR, patternId0, V014, V000, V000, V000, V012, V000, V000, V008, V000, V000, V000, V000, V000, V000, V000, V000, hasOutput);


        // Pattern 1: intro
        // ------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(HEAD_DR, patternId1, REST, REST, REST, REST, REST, REST, REST, REST, HEAD, REST, REST, REST, HEAD, REST, REST, REST, hasOutput);
        setVelPattern(HEAD_DR, patternId1, V012, V000, V000, V000, V000, V000, V000, V000, V008, V000, V015, V000, V000, V000, V000, V000, hasOutput);

        // -----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_LEG_DR, patternId1, REST, BDRU, REST, BDRU, REST, BDRU, REST, BDRU, REST, BDRU, REST, BDRU, REST, BDRU, REST, REST, hasOutput);
        setVelPattern(RIGHT_LEG_DR, patternId1, V000, V012, V000, V012, V000, V000, V000, V000, V008, V000, V015, V000, V000, V000, V000, V000, hasOutput);

        // ----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(LEFT_ARM_DR, patternId1, SNSN, REST, REST, REST, SNSN, REST, REST, REST, SNSN, REST, REST, REST, SNSN, REST, REST, REST, hasOutput);
        setVelPattern(LEFT_ARM_DR, patternId1, V012, V000, V008, V000, V012, V000, V007, V000, V014, V000, V007, V000, V012, V006, V008, V005, hasOutput);

        // ---------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_ARM_DR, patternId1, SNSN, REST, REST, REST, SNSN, REST, REST, REST, SNSN, REST, REST, REST, SNSN, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_ARM_DR, patternId1, V015, V000, V000, V000, V012, V000, V000, V008, V015, V000, V000, V000, V014, V000, V012, V000, hasOutput);


        // Pattern 2: chorus
        // ------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(HEAD_DR, patternId2, HEAD, REST, REST, REST, HEAD, REST, REST, REST, HEAD, REST, REST, REST, HEAD, REST, REST, REST, hasOutput);
        setVelPattern(HEAD_DR, patternId2, V012, V000, V000, V000, V000, V000, V000, V000, V008, V000, V015, V000, V000, V000, V000, V000, hasOutput);

        // -----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_LEG_DR, patternId2, BDRU, REST, REST, BDRU, REST, REST, BDRU, REST, BDRU, REST, BDRU, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_LEG_DR, patternId2, V012, V000, V000, V012, V000, V000, V012, V000, V008, V000, V015, V000, V000, V000, V000, V000, hasOutput);

        // ----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(LEFT_ARM_DR, patternId2, REST, REST, REST, REST, SNCR, REST, REST, SNCR, REST, SNCR, REST, REST, SNCR, REST, REST, REST, hasOutput);
        setVelPattern(LEFT_ARM_DR, patternId2, V012, V000, V008, V000, V012, V000, V007, V012, V014, V012, V007, V000, V012, V000, V007, V000, hasOutput);

        // ---------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_ARM_DR, patternId2, SNCR, REST, REST, REST, SNCR, REST, REST, REST, SNCR, REST, REST, REST, SNCR, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_ARM_DR, patternId2, V012, V000, V000, V000, V012, V000, V000, V008, V012, V000, V000, V000, V014, V000, V012, V000, hasOutput);

        // Pattern 3: verse
        // ------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(HEAD_DR, patternId3, HEAD, REST, REST, REST, HEAD, REST, REST, REST, HEAD, REST, REST, REST, HEAD, REST, REST, REST, hasOutput);
        setVelPattern(HEAD_DR, patternId3, V012, V000, V000, V000, V008, V000, V000, V000, V008, V000, V015, V000, V000, V000, V000, V000, hasOutput);

        // -----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_LEG_DR, patternId3, BDRU, REST, BDRU, REST, REST, REST, REST, REST, BDRU, REST, BDRU, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_LEG_DR, patternId3, V012, V000, V000, V012, V000, V000, V012, V000, V008, V000, V015, V000, V000, V000, V000, V000, hasOutput);

        // ----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(LEFT_ARM_DR, patternId3, HHSN, REST, HHSN, REST, HHSN, REST, HHSN, REST, HHSN, REST, HHSN, REST, HHSN, REST, HHSN, REST, hasOutput);
        setVelPattern(LEFT_ARM_DR, patternId3, V012, V000, V008, V000, V012, V000, V007, V000, V014, V012, V007, V000, V012, V000, V007, V000, hasOutput);

        // ---------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_ARM_DR, patternId3, REST, REST, REST, REST, HHSN, REST, REST, REST, REST, REST, REST, REST, HHSN, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_ARM_DR, patternId3, V012, V000, V000, V000, V012, V000, V000, V008, V012, V000, V000, V000, V014, V000, V012, V000, hasOutput);

        byte smellsLikePattSeq[nbMeasures_] = { 0, 0, 0, 1, 2, 2, 2, 2,
                                                3, 3, 3, 3, 3, 3, 3, 3,
                                                2, 2, 2, 2 };
        setPatternSequence(smellsLikePattSeq);

        break;
      }
    case BASIC_RYTHM:
      {
        // -------------------------------------------- BASIC RYTHM -----------------------------------------------------
        nbPatterns_ = 2;
        nbMeasures_ = 10;
        initializeBlankPatterns(nbPatterns_, nbMeasures_);

        byte patternId0 = 0;
        byte patternId1 = 1;

        // Head
        // ----------------------------------------0001----------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(HEAD_DR, patternId0, HEAD, REST, REST, REST, REST, REST, REST, REST, HEAD, REST, HEAD, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(HEAD_DR, patternId0, V012, V000, V000, V000, V000, V000, V000, V000, V008, V000, V015, V000, V000, V000, V000, V000, hasOutput);

        setHitPattern(HEAD_DR, patternId1, HEAD, REST, REST, REST, REST, REST, REST, REST, HEAD, REST, HEAD, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(HEAD_DR, patternId1, V012, V000, V000, V000, V000, V000, V000, V000, V008, V000, V015, V000, V000, V000, V000, V000, hasOutput);

        // Right leg
        // ----------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_LEG_DR, patternId0, BDRU, REST, REST, REST, REST, REST, REST, REST, BDRU, REST, BDRU, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_LEG_DR, patternId0, V012, V000, V000, V000, V000, V000, V000, V000, V008, V000, V015, V000, V000, V000, V000, V000, hasOutput);

        setHitPattern(RIGHT_LEG_DR, patternId1, BDRU, REST, REST, REST, REST, REST, REST, REST, BDRU, REST, BDRU, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_LEG_DR, patternId1, V012, V000, V000, V000, V000, V000, V000, V000, V008, V000, V015, V000, V000, V000, V000, V000, hasOutput);


        // Left arm
        // ---------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(LEFT_ARM_DR, patternId0, REST, REST, HHSN, REST, HHSN, REST, HHSN, REST, HHSN, REST, HHSN, REST, HHSN, REST, HHSN, REST, hasOutput);
        setVelPattern(LEFT_ARM_DR, patternId0, V000, V000, V008, V000, V012, V000, V007, V000, V014, V000, V007, V000, V012, V000, V007, V000, hasOutput);

        setHitPattern(LEFT_ARM_DR, patternId1, HHSN, REST, HHSN, REST, HHSN, REST, HHSN, REST, HHSN, REST, REST, REST, REST, SNSN, REST, SNCR, hasOutput);
        setVelPattern(LEFT_ARM_DR, patternId1, V012, V000, V008, V000, V012, V000, V007, V000, V014, V000, V007, V000, V000, V006, V000, V005, hasOutput);

        // Right arm
        // ---------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_ARM_DR, patternId0, SNCR, REST, REST, REST, HHSN, REST, REST, HHSN, REST, REST, REST, REST, HHSN, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_ARM_DR, patternId0, V014, V000, V000, V000, V012, V000, V000, V008, V000, V000, V000, V000, V012, V000, V000, V000, hasOutput);

        setHitPattern(RIGHT_ARM_DR, patternId1, REST, REST, REST, REST, HHSN, REST, REST, HHSN, REST, REST, REST, REST, SNSN, REST, SNSN, REST, hasOutput);
        setVelPattern(RIGHT_ARM_DR, patternId1, V000, V000, V000, V000, V012, V000, V000, V008, V000, V000, V000, V000, V014, V000, V012, V000, hasOutput);

        byte basicPattSeq[nbMeasures_] = { 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 };

        setPatternSequence(basicPattSeq);
        break;
      }
  }
}