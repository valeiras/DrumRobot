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
    // -------------------------------------------- SIMPLEST RYTHM -----------------------------------------------------
    case SIMPLEST_RYTHM:
    default:
      {
        nbPatterns_ = 1;
        nbMeasures_ = 1;
        initializeBlankPatterns(nbPatterns_, nbMeasures_);

        byte patternId = 0;

        setQuarterHit(HEAD_DR, HEAD, V012, patternId, 1, hasOutput);
        setQuarterHit(HEAD_DR, HEAD, V000, patternId, 2, hasOutput);
        setQuarterHit(HEAD_DR, HEAD, V008, patternId, 3, hasOutput);
        setQuarterHit(HEAD_DR, HEAD, V014, patternId, 3, hasOutput);

        setQuarterHit(RIGHT_LEG_DR, BDRU, V008, patternId, 1, hasOutput);
        setQuaverHit(RIGHT_LEG_DR, BDRU, V014, patternId, 6, hasOutput);
        setQuarterHit(RIGHT_LEG_DR, BDRU, V008, patternId, 3, hasOutput);

        setQuaverHit(LEFT_ARM_DR, HHSN, V014, patternId, 1, hasOutput);
        setQuaverHit(LEFT_ARM_DR, HHSN, V007, patternId, 2, hasOutput);
        setQuaverHit(LEFT_ARM_DR, HHSN, V012, patternId, 3, hasOutput);
        setQuaverHit(LEFT_ARM_DR, HHSN, V008, patternId, 4, hasOutput);
        setQuaverHit(LEFT_ARM_DR, HHSN, V010, patternId, 5, hasOutput);
        setQuaverHit(LEFT_ARM_DR, HHSN, V006, patternId, 6, hasOutput);
        setQuaverHit(LEFT_ARM_DR, HHSN, V012, patternId, 7, hasOutput);
        setQuaverHit(LEFT_ARM_DR, SNCR, V009, patternId, 8, hasOutput);

        setQuarterHit(RIGHT_ARM_DR, HHSN, V014, patternId, 1, hasOutput);
        setQuarterHit(RIGHT_ARM_DR, HHSN, V014, patternId, 2, hasOutput);
        setQuarterHit(RIGHT_ARM_DR, SNCR, V010, patternId, 4, hasOutput);

        byte simplestPattSeq[nbMeasures_] = { 0 };
        setPatternSequence(simplestPattSeq);

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
    case CRESCENDO:
      {
        nbPatterns_ = 1;
        nbMeasures_ = 1;
        initializeBlankPatterns(nbPatterns_, nbMeasures_);

        byte patternId = 0;

        setQuaverHit(HEAD_DR, HEAD, V001, patternId, 1, hasOutput);
        setQuaverHit(HEAD_DR, HEAD, V003, patternId, 2, hasOutput);
        setQuaverHit(HEAD_DR, HEAD, V005, patternId, 3, hasOutput);
        setQuaverHit(HEAD_DR, HEAD, V007, patternId, 4, hasOutput);
        setQuaverHit(HEAD_DR, HEAD, V009, patternId, 5, hasOutput);
        setQuaverHit(HEAD_DR, HEAD, V011, patternId, 6, hasOutput);
        setQuaverHit(HEAD_DR, HEAD, V013, patternId, 7, hasOutput);
        setQuaverHit(HEAD_DR, HEAD, V015, patternId, 8, hasOutput);

        setQuaverHit(RIGHT_LEG_DR, BDRU, V001, patternId, 1, hasOutput);
        setQuaverHit(RIGHT_LEG_DR, BDRU, V003, patternId, 2, hasOutput);
        setQuaverHit(RIGHT_LEG_DR, BDRU, V005, patternId, 3, hasOutput);
        setQuaverHit(RIGHT_LEG_DR, BDRU, V007, patternId, 4, hasOutput);
        setQuaverHit(RIGHT_LEG_DR, BDRU, V009, patternId, 5, hasOutput);
        setQuaverHit(RIGHT_LEG_DR, BDRU, V011, patternId, 6, hasOutput);
        setQuaverHit(RIGHT_LEG_DR, BDRU, V013, patternId, 7, hasOutput);
        setQuaverHit(RIGHT_LEG_DR, BDRU, V015, patternId, 8, hasOutput);

        setQuaverHit(LEFT_ARM_DR, SNSN, V001, patternId, 1, hasOutput);
        setQuaverHit(LEFT_ARM_DR, SNSN, V003, patternId, 2, hasOutput);
        setQuaverHit(LEFT_ARM_DR, SNSN, V005, patternId, 3, hasOutput);
        setQuaverHit(LEFT_ARM_DR, SNSN, V007, patternId, 4, hasOutput);
        setQuaverHit(LEFT_ARM_DR, SNSN, V009, patternId, 5, hasOutput);
        setQuaverHit(LEFT_ARM_DR, SNSN, V011, patternId, 6, hasOutput);
        setQuaverHit(LEFT_ARM_DR, SNSN, V013, patternId, 7, hasOutput);
        setQuaverHit(LEFT_ARM_DR, SNCR, V015, patternId, 8, hasOutput);

        setQuaverHit(RIGHT_ARM_DR, SNSN, V001, patternId, 1, hasOutput);
        setQuaverHit(RIGHT_ARM_DR, SNSN, V003, patternId, 2, hasOutput);
        setQuaverHit(RIGHT_ARM_DR, SNSN, V005, patternId, 3, hasOutput);
        setQuaverHit(RIGHT_ARM_DR, SNSN, V007, patternId, 4, hasOutput);
        setQuaverHit(RIGHT_ARM_DR, SNSN, V009, patternId, 5, hasOutput);
        setQuaverHit(RIGHT_ARM_DR, SNSN, V011, patternId, 6, hasOutput);
        setQuaverHit(RIGHT_ARM_DR, SNSN, V013, patternId, 7, hasOutput);
        setQuaverHit(RIGHT_ARM_DR, SNCR, V015, patternId, 8, hasOutput);

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

        setQuarterHit(HEAD_DR, HEAD, V015, patternId, 1, hasOutput);
        setQuarterHit(HEAD_DR, HEAD, V015, patternId, 2, hasOutput);
        setQuarterHit(HEAD_DR, HEAD, V015, patternId, 3, hasOutput);
        setQuarterHit(HEAD_DR, HEAD, V015, patternId, 4, hasOutput);

        setQuarterHit(RIGHT_LEG_DR, BDRU, V015, patternId, 1, hasOutput);
        setQuarterHit(RIGHT_LEG_DR, BDRU, V015, patternId, 2, hasOutput);
        setQuarterHit(RIGHT_LEG_DR, BDRU, V015, patternId, 3, hasOutput);
        setQuarterHit(RIGHT_LEG_DR, BDRU, V015, patternId, 4, hasOutput);

        setQuarterHit(LEFT_ARM_DR, SNSN, V015, patternId, 1, hasOutput);
        setQuarterHit(LEFT_ARM_DR, SNSN, V015, patternId, 2, hasOutput);
        setQuarterHit(LEFT_ARM_DR, SNSN, V015, patternId, 3, hasOutput);
        setQuarterHit(LEFT_ARM_DR, SNSN, V015, patternId, 4, hasOutput);

        setQuarterHit(RIGHT_ARM_DR, SNSN, V015, patternId, 1, hasOutput);
        setQuarterHit(RIGHT_ARM_DR, SNSN, V015, patternId, 2, hasOutput);
        setQuarterHit(RIGHT_ARM_DR, SNSN, V015, patternId, 3, hasOutput);
        setQuarterHit(RIGHT_ARM_DR, SNSN, V015, patternId, 4, hasOutput);

        byte simplestPattSeq[nbMeasures_] = { 0 };
        setPatternSequence(simplestPattSeq);

        break;
      }
  }
}