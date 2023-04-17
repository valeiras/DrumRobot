#include "drum_song.h"

DrumSong::DrumSong()
  : PercuSong<NB_HIT_JOINTS_DR, BITS_FOR_POS_DR>::PercuSong() {
  nbOfPositions_[RIGHT_ARM_DR] = NB_POS_RA_DR;
  nbOfPositions_[LEFT_ARM_DR] = NB_POS_LA_DR;
  nbOfPositions_[RIGHT_LEG_DR] = NB_POS_RL_DR;
  nbOfPositions_[HEAD_DR] = NB_POS_HD_DR;
}

void DrumSong::createPredefinedPatterns(byte rythmName, bool printOutput = false) {
  switch (rythmName) {
    // -------------------------------------------- SIMPLEST RYTHM -----------------------------------------------------
    case SIMPLEST_RYTHM:
    default:
      {
        nbPatterns_ = 1;
        nbMeasures_ = 1;
        initializeBlankPatterns(nbPatterns_, nbMeasures_);

        byte patternId = 0;

        setQuarterHit(HEAD_DR, HEAD, V012, patternId, 1, printOutput);
        setQuarterHit(HEAD_DR, HEAD, V000, patternId, 2, printOutput);
        setQuarterHit(HEAD_DR, HEAD, V008, patternId, 3, printOutput);
        setQuarterHit(HEAD_DR, HEAD, V014, patternId, 3, printOutput);

        setQuarterHit(RIGHT_LEG_DR, BDRU, V008, patternId, 1, printOutput);
        setQuaverHit(RIGHT_LEG_DR, BDRU, V014, patternId, 6, printOutput);
        setQuarterHit(RIGHT_LEG_DR, BDRU, V008, patternId, 3, printOutput);

        setQuaverHit(LEFT_ARM_DR, HHSN, V014, patternId, 1, printOutput);
        setQuaverHit(LEFT_ARM_DR, HHSN, V007, patternId, 2, printOutput);
        setQuaverHit(LEFT_ARM_DR, HHSN, V012, patternId, 3, printOutput);
        setQuaverHit(LEFT_ARM_DR, HHSN, V008, patternId, 4, printOutput);
        setQuaverHit(LEFT_ARM_DR, HHSN, V010, patternId, 5, printOutput);
        setQuaverHit(LEFT_ARM_DR, HHSN, V006, patternId, 6, printOutput);
        setQuaverHit(LEFT_ARM_DR, HHSN, V012, patternId, 7, printOutput);
        setQuaverHit(LEFT_ARM_DR, SNCR, V009, patternId, 8, printOutput);

        setQuarterHit(RIGHT_ARM_DR, HHSN, V014, patternId, 1, printOutput);
        setQuarterHit(RIGHT_ARM_DR, HHSN, V014, patternId, 2, printOutput);
        setQuarterHit(RIGHT_ARM_DR, SNCR, V010, patternId, 4, printOutput);

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
        setHitPattern(HEAD_DR, patternId0, HEAD, REST, REST, REST, REST, REST, REST, REST, HEAD, REST, HEAD, REST, REST, REST, REST, REST, printOutput);
        setVelPattern(HEAD_DR, patternId0, V012, V000, V000, V000, V000, V000, V000, V000, V008, V000, V015, V000, V000, V000, V000, V000, printOutput);

        setHitPattern(HEAD_DR, patternId1, HEAD, REST, REST, REST, REST, REST, REST, REST, HEAD, REST, HEAD, REST, REST, REST, REST, REST, printOutput);
        setVelPattern(HEAD_DR, patternId1, V012, V000, V000, V000, V000, V000, V000, V000, V008, V000, V015, V000, V000, V000, V000, V000, printOutput);

        // Right leg
        // ----------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_LEG_DR, patternId0, BDRU, REST, REST, REST, REST, REST, REST, REST, BDRU, REST, BDRU, REST, REST, REST, REST, REST, printOutput);
        setVelPattern(RIGHT_LEG_DR, patternId0, V012, V000, V000, V000, V000, V000, V000, V000, V008, V000, V015, V000, V000, V000, V000, V000, printOutput);

        setHitPattern(RIGHT_LEG_DR, patternId1, BDRU, REST, REST, REST, REST, REST, REST, REST, BDRU, REST, BDRU, REST, REST, REST, REST, REST, printOutput);
        setVelPattern(RIGHT_LEG_DR, patternId1, V012, V000, V000, V000, V000, V000, V000, V000, V008, V000, V015, V000, V000, V000, V000, V000, printOutput);


        // Left arm
        // ---------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(LEFT_ARM_DR, patternId0, REST, REST, HHSN, REST, HHSN, REST, HHSN, REST, HHSN, REST, HHSN, REST, HHSN, REST, HHSN, REST, printOutput);
        setVelPattern(LEFT_ARM_DR, patternId0, V000, V000, V008, V000, V012, V000, V007, V000, V014, V000, V007, V000, V012, V000, V007, V000, printOutput);

        setHitPattern(LEFT_ARM_DR, patternId1, HHSN, REST, HHSN, REST, HHSN, REST, HHSN, REST, HHSN, REST, REST, REST, REST, SNSN, REST, SNCR, printOutput);
        setVelPattern(LEFT_ARM_DR, patternId1, V012, V000, V008, V000, V012, V000, V007, V000, V014, V000, V007, V000, V000, V006, V000, V005, printOutput);

        // Right arm
        // ---------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_ARM_DR, patternId0, SNCR, REST, REST, REST, HHSN, REST, REST, HHSN, REST, REST, REST, REST, HHSN, REST, REST, REST, printOutput);
        setVelPattern(RIGHT_ARM_DR, patternId0, V014, V000, V000, V000, V012, V000, V000, V008, V000, V000, V000, V000, V012, V000, V000, V000, printOutput);

        setHitPattern(RIGHT_ARM_DR, patternId1, REST, REST, REST, REST, HHSN, REST, REST, HHSN, REST, REST, REST, REST, SNSN, REST, SNSN, REST, printOutput);
        setVelPattern(RIGHT_ARM_DR, patternId1, V000, V000, V000, V000, V012, V000, V000, V008, V000, V000, V000, V000, V014, V000, V012, V000, printOutput);

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

        setQuaverHit(HEAD_DR, HEAD, V001, patternId, 1, printOutput);
        setQuaverHit(HEAD_DR, HEAD, V003, patternId, 2, printOutput);
        setQuaverHit(HEAD_DR, HEAD, V005, patternId, 3, printOutput);
        setQuaverHit(HEAD_DR, HEAD, V007, patternId, 4, printOutput);
        setQuaverHit(HEAD_DR, HEAD, V009, patternId, 5, printOutput);
        setQuaverHit(HEAD_DR, HEAD, V011, patternId, 6, printOutput);
        setQuaverHit(HEAD_DR, HEAD, V013, patternId, 7, printOutput);
        setQuaverHit(HEAD_DR, HEAD, V015, patternId, 8, printOutput);

        setQuaverHit(RIGHT_LEG_DR, BDRU, V001, patternId, 1, printOutput);
        setQuaverHit(RIGHT_LEG_DR, BDRU, V003, patternId, 2, printOutput);
        setQuaverHit(RIGHT_LEG_DR, BDRU, V005, patternId, 3, printOutput);
        setQuaverHit(RIGHT_LEG_DR, BDRU, V007, patternId, 4, printOutput);
        setQuaverHit(RIGHT_LEG_DR, BDRU, V009, patternId, 5, printOutput);
        setQuaverHit(RIGHT_LEG_DR, BDRU, V011, patternId, 6, printOutput);
        setQuaverHit(RIGHT_LEG_DR, BDRU, V013, patternId, 7, printOutput);
        setQuaverHit(RIGHT_LEG_DR, BDRU, V015, patternId, 8, printOutput);

        setQuaverHit(LEFT_ARM_DR, SNSN, V001, patternId, 1, printOutput);
        setQuaverHit(LEFT_ARM_DR, SNSN, V003, patternId, 2, printOutput);
        setQuaverHit(LEFT_ARM_DR, SNSN, V005, patternId, 3, printOutput);
        setQuaverHit(LEFT_ARM_DR, SNSN, V007, patternId, 4, printOutput);
        setQuaverHit(LEFT_ARM_DR, SNSN, V009, patternId, 5, printOutput);
        setQuaverHit(LEFT_ARM_DR, SNSN, V011, patternId, 6, printOutput);
        setQuaverHit(LEFT_ARM_DR, SNSN, V013, patternId, 7, printOutput);
        setQuaverHit(LEFT_ARM_DR, SNCR, V015, patternId, 8, printOutput);

        setQuaverHit(RIGHT_ARM_DR, SNSN, V001, patternId, 1, printOutput);
        setQuaverHit(RIGHT_ARM_DR, SNSN, V003, patternId, 2, printOutput);
        setQuaverHit(RIGHT_ARM_DR, SNSN, V005, patternId, 3, printOutput);
        setQuaverHit(RIGHT_ARM_DR, SNSN, V007, patternId, 4, printOutput);
        setQuaverHit(RIGHT_ARM_DR, SNSN, V009, patternId, 5, printOutput);
        setQuaverHit(RIGHT_ARM_DR, SNSN, V011, patternId, 6, printOutput);
        setQuaverHit(RIGHT_ARM_DR, SNSN, V013, patternId, 7, printOutput);
        setQuaverHit(RIGHT_ARM_DR, SNCR, V015, patternId, 8, printOutput);

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

        setQuarterHit(HEAD_DR, HEAD, V015, patternId, 1, printOutput);
        setQuarterHit(HEAD_DR, HEAD, V015, patternId, 2, printOutput);
        setQuarterHit(HEAD_DR, HEAD, V015, patternId, 3, printOutput);
        setQuarterHit(HEAD_DR, HEAD, V015, patternId, 4, printOutput);

        setQuarterHit(RIGHT_LEG_DR, BDRU, V015, patternId, 1, printOutput);
        setQuarterHit(RIGHT_LEG_DR, BDRU, V015, patternId, 2, printOutput);
        setQuarterHit(RIGHT_LEG_DR, BDRU, V015, patternId, 3, printOutput);
        setQuarterHit(RIGHT_LEG_DR, BDRU, V015, patternId, 4, printOutput);

        setQuarterHit(LEFT_ARM_DR, SNSN, V015, patternId, 1, printOutput);
        setQuarterHit(LEFT_ARM_DR, SNSN, V015, patternId, 2, printOutput);
        setQuarterHit(LEFT_ARM_DR, SNSN, V015, patternId, 3, printOutput);
        setQuarterHit(LEFT_ARM_DR, SNSN, V015, patternId, 4, printOutput);

        setQuarterHit(RIGHT_ARM_DR, SNSN, V015, patternId, 1, printOutput);
        setQuarterHit(RIGHT_ARM_DR, SNSN, V015, patternId, 2, printOutput);
        setQuarterHit(RIGHT_ARM_DR, SNSN, V015, patternId, 3, printOutput);
        setQuarterHit(RIGHT_ARM_DR, SNSN, V015, patternId, 4, printOutput);

        byte simplestPattSeq[nbMeasures_] = { 0 };
        setPatternSequence(simplestPattSeq);

        break;
      }
  }
}