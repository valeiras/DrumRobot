#include "drum_song_ld.h"

DrumSongLD::DrumSongLD()
  : PercuSong<NB_HIT_JOINTS_DR, BITS_FOR_POS_DR>::PercuSong() {
  nbOfPositions_[RIGHT_ARM_DR] = NB_POS_RA_DR;
  nbOfPositions_[LEFT_ARM_DR] = NB_POS_LA_DR;
  nbOfPositions_[RIGHT_LEG_DR] = NB_POS_RL_DR;
  nbOfPositions_[HEAD_DR] = NB_POS_HD_DR;
}

void DrumSongLD::createPredefinedPatterns(byte rythmName, bool hasOutput = false) {
  switch (rythmName) {
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