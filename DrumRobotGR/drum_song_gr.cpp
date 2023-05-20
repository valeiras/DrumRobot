#include "drum_song_gr.h"

DrumSongGR::DrumSongGR()
  : PercuSong<NB_LIMBS_DR, BITS_FOR_POS_DR>::PercuSong() {
  nbOfPositions_[RIGHT_ARM_DR] = NB_POS_RA_DR;
  nbOfPositions_[LEFT_ARM_DR] = NB_POS_LA_DR;
  nbOfPositions_[RIGHT_LEG_DR] = NB_POS_RL_DR;
}

void DrumSongGR::createPredefinedPatterns(Songs songName, bool hasOutput = false) {
  switch (songName) {
    case FRERE_JACQUES:
      {
        // -------------------------------------------- FRERE JACQUES    -----------------------------------------------------
        nbPatterns_ = 3;
        nbMeasures_ = 9;
        initializeBlankPatterns(nbPatterns_, nbMeasures_);

        byte patternId0 = 0;
        byte patternId1 = 1;
        byte patternId2 = 2;

        // Right leg
        // -----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_LEG_DR, patternId0, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_LEG_DR, patternId0, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, hasOutput);

        setHitPattern(RIGHT_LEG_DR, patternId1, BDRU, REST, REST, REST, REST, REST, REST, REST, BDRU, REST, BDRU, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_LEG_DR, patternId1, V012, V000, V000, V000, V000, V000, V000, V000, V008, V000, V015, V000, V000, V000, V000, V000, hasOutput);

        setHitPattern(RIGHT_LEG_DR, patternId2, BDRU, REST, REST, REST, REST, REST, REST, REST, BDRU, REST, BDRU, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_LEG_DR, patternId2, V012, V000, V000, V000, V000, V000, V000, V000, V008, V000, V015, V000, V000, V000, V000, V000, hasOutput);


        // Left arm
        // ---------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(LEFT_ARM_DR, patternId0, STCK, REST, REST, REST, STCK, REST, REST, REST, STCK, REST, REST, REST, STCK, REST, REST, REST, hasOutput);
        setVelPattern(LEFT_ARM_DR, patternId0, V012, V000, V000, V000, V010, V000, V000, V000, V012, V000, V000, V000, V010, V000, V000, V000, hasOutput);

        setHitPattern(LEFT_ARM_DR, patternId1, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, hasOutput);
        setVelPattern(LEFT_ARM_DR, patternId1, V012, V000, V008, V000, V012, V000, V007, V000, V014, V000, V007, V000, V012, V000, V007, V000, hasOutput);

        setHitPattern(LEFT_ARM_DR, patternId2, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, REST, SNLT, REST, SNLT, hasOutput);
        setVelPattern(LEFT_ARM_DR, patternId2, V012, V000, V008, V000, V012, V000, V007, V000, V014, V000, V007, V000, V000, V006, V000, V005, hasOutput);

        // Right arm
        // ----------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_ARM_DR, patternId0, STCK, REST, REST, REST, STCK, REST, REST, REST, STCK, REST, REST, REST, STCK, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_ARM_DR, patternId0, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, hasOutput);

        setHitPattern(RIGHT_ARM_DR, patternId1, CRSH, REST, REST, REST, SNRG, REST, REST, SNRG, REST, REST, REST, REST, SNRG, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_ARM_DR, patternId1, V014, V000, V000, V000, V012, V000, V000, V008, V000, V000, V000, V000, V012, V000, V000, V000, hasOutput);

        setHitPattern(RIGHT_ARM_DR, patternId2, REST, REST, REST, REST, SNRG, REST, REST, SNRG, REST, REST, REST, REST, SNRG, REST, SNRG, REST, hasOutput);
        setVelPattern(RIGHT_ARM_DR, patternId2, V000, V000, V000, V000, V012, V000, V000, V008, V000, V000, V000, V000, V014, V000, V012, V000, hasOutput);

        // Right leg
        // ----------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_LEG_DR, patternId0, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_LEG_DR, patternId0, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, hasOutput);

        setHitPattern(RIGHT_LEG_DR, patternId1, BDRU, REST, REST, REST, REST, REST, REST, REST, BDRU, REST, BDRU, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_LEG_DR, patternId1, V012, V000, V000, V000, V000, V000, V000, V000, V008, V000, V015, V000, V000, V000, V000, V000, hasOutput);

        setHitPattern(RIGHT_LEG_DR, patternId2, BDRU, REST, REST, REST, REST, REST, REST, REST, BDRU, REST, BDRU, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_LEG_DR, patternId2, V012, V000, V000, V000, V000, V000, V000, V000, V008, V000, V015, V000, V000, V000, V000, V000, hasOutput);


        // Left arm
        // ---------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(LEFT_ARM_DR, patternId0, STCK, REST, REST, REST, STCK, REST, REST, REST, STCK, REST, REST, REST, STCK, REST, REST, REST, hasOutput);
        setVelPattern(LEFT_ARM_DR, patternId0, V012, V000, V000, V000, V010, V000, V000, V000, V012, V000, V000, V000, V010, V000, V000, V000, hasOutput);

        setHitPattern(LEFT_ARM_DR, patternId1, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, hasOutput);
        setVelPattern(LEFT_ARM_DR, patternId1, V012, V000, V008, V000, V012, V000, V007, V000, V014, V000, V007, V000, V012, V000, V007, V000, hasOutput);

        setHitPattern(LEFT_ARM_DR, patternId2, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, REST, SNLT, REST, SNLT, hasOutput);
        setVelPattern(LEFT_ARM_DR, patternId2, V012, V000, V008, V000, V012, V000, V007, V000, V014, V000, V007, V000, V000, V006, V000, V005, hasOutput);

        // Right arm
        // ----------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_ARM_DR, patternId0, STCK, REST, REST, REST, STCK, REST, REST, REST, STCK, REST, REST, REST, STCK, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_ARM_DR, patternId0, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, hasOutput);

        setHitPattern(RIGHT_ARM_DR, patternId1, CRSH, REST, REST, REST, SNRG, REST, REST, SNRG, REST, REST, REST, REST, SNRG, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_ARM_DR, patternId1, V014, V000, V000, V000, V012, V000, V000, V008, V000, V000, V000, V000, V012, V000, V000, V000, hasOutput);

        setHitPattern(RIGHT_ARM_DR, patternId2, REST, REST, REST, REST, SNRG, REST, REST, SNRG, REST, REST, REST, REST, SNRG, REST, SNRG, REST, hasOutput);
        setVelPattern(RIGHT_ARM_DR, patternId2, V000, V000, V000, V000, V012, V000, V000, V008, V000, V000, V000, V000, V014, V000, V012, V000, hasOutput);

        byte frereJacquesPattSeq[nbMeasures_] = { 0, 1, 2, 1, 2, 1, 2, 1, 2 };

        setPatternSequence(frereJacquesPattSeq);
        break;
      }
      // -------------------------------------------- SIMPLEST RYTHM -----------------------------------------------------
    case HOUND_DOG:
      {
        nbPatterns_ = 3;
        nbMeasures_ = 6;
        initializeBlankPatterns(nbPatterns_, nbMeasures_);

        byte patternId0 = 0;
        byte patternId1 = 1;
        byte patternId2 = 2;

        // --------------------------------------------- Pattern 0--------------------------------------------------------------

        setQuarterHit(RIGHT_LEG_DR, BDRU, V012, patternId0, 1, hasOutput);
        setQuarterHit(RIGHT_LEG_DR, BDRU, V012, patternId0, 2, hasOutput);
        setQuarterHit(RIGHT_LEG_DR, BDRU, V008, patternId0, 3, hasOutput);

        setSemiquaverHit(LEFT_ARM_DR, SNLT, V014, patternId0, 2, hasOutput);
        setSemiquaverHit(LEFT_ARM_DR, SNLT, V008, patternId0, 4, hasOutput);
        setSemiquaverHit(LEFT_ARM_DR, SNLT, V006, patternId0, 6, hasOutput);
        setSemiquaverHit(LEFT_ARM_DR, SNLT, V009, patternId0, 8, hasOutput);

        setSemiquaverHit(RIGHT_ARM_DR, SNRG, V012, patternId0, 1, hasOutput);
        setSemiquaverHit(RIGHT_ARM_DR, SNRG, V011, patternId0, 3, hasOutput);
        setSemiquaverHit(RIGHT_ARM_DR, CRSH, V013, patternId0, 5, hasOutput);
        setSemiquaverHit(RIGHT_ARM_DR, CRSH, V012, patternId0, 7, hasOutput);
        setSemiquaverHit(RIGHT_ARM_DR, CRSH, V015, patternId0, 9, hasOutput);

        // --------------------------------------------- Pattern 1--------------------------------------------------------------

        setQuarterHit(RIGHT_LEG_DR, BDRU, V012, patternId1, 1, hasOutput);
        setQuarterHit(RIGHT_LEG_DR, BDRU, V008, patternId1, 3, hasOutput);

        setQuaverHit(LEFT_ARM_DR, HHAT, V007, patternId1, 1, hasOutput);
        setQuaverHit(LEFT_ARM_DR, HHAT, V007, patternId1, 2, hasOutput);
        setQuaverHit(LEFT_ARM_DR, HHAT, V012, patternId1, 3, hasOutput);
        setQuaverHit(LEFT_ARM_DR, HHAT, V008, patternId1, 4, hasOutput);
        setQuaverHit(LEFT_ARM_DR, HHAT, V010, patternId1, 5, hasOutput);
        setQuaverHit(LEFT_ARM_DR, HHAT, V006, patternId1, 6, hasOutput);
        setQuaverHit(LEFT_ARM_DR, HHAT, V012, patternId1, 7, hasOutput);
        setQuaverHit(LEFT_ARM_DR, HHAT, V009, patternId1, 8, hasOutput);

        setQuarterHit(RIGHT_ARM_DR, SNRG, V014, patternId1, 2, hasOutput);
        setQuarterHit(RIGHT_ARM_DR, SNRG, V014, patternId1, 4, hasOutput);

        // --------------------------------------------- Pattern 2--------------------------------------------------------------
        setQuarterHit(RIGHT_LEG_DR, BDRU, V012, patternId2, 1, hasOutput);
        setQuarterHit(RIGHT_LEG_DR, BDRU, V008, patternId2, 3, hasOutput);
        setSemiquaverHit(RIGHT_LEG_DR, BDRU, V014, patternId2, 11, hasOutput);

        setQuaverHit(LEFT_ARM_DR, HHAT, V007, patternId2, 1, hasOutput);
        setQuaverHit(LEFT_ARM_DR, HHAT, V007, patternId2, 2, hasOutput);
        setQuaverHit(LEFT_ARM_DR, HHAT, V012, patternId2, 3, hasOutput);
        setQuaverHit(LEFT_ARM_DR, HHAT, V008, patternId2, 4, hasOutput);
        setQuaverHit(LEFT_ARM_DR, HHAT, V010, patternId2, 5, hasOutput);
        setQuaverHit(LEFT_ARM_DR, HHAT, V006, patternId2, 6, hasOutput);
        setQuaverHit(LEFT_ARM_DR, HHAT, V012, patternId2, 7, hasOutput);
        setQuaverHit(LEFT_ARM_DR, HHAT, V009, patternId2, 8, hasOutput);

        setQuarterHit(RIGHT_ARM_DR, SNRG, V014, patternId2, 1, hasOutput);
        setQuarterHit(RIGHT_ARM_DR, SNRG, V014, patternId2, 2, hasOutput);
        setSemiquaverHit(RIGHT_ARM_DR, SNRG, V014, patternId2, 8, hasOutput);
        setQuarterHit(RIGHT_ARM_DR, CRSH, V015, patternId2, 4, hasOutput);

        byte houndDogPattSeq[nbMeasures_] = { 0, 1, 2, 1, 2, 1 };
        setPatternSequence(houndDogPattSeq);

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
        setHitPattern(LEFT_ARM_DR, patternId0, HHAT, HHAT, HHAT, HHAT, HHAT, HHAT, HHAT, HHAT, HHAT, HHAT, HHAT, HHAT, HHAT, HHAT, HHAT, HHAT, hasOutput);
        setVelPattern(LEFT_ARM_DR, patternId0, V012, V000, V008, V000, V012, V000, V007, V000, V014, V000, V007, V000, V012, V000, V007, V000, hasOutput);

        setHitPattern(LEFT_ARM_DR, patternId1, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, hasOutput);
        setVelPattern(LEFT_ARM_DR, patternId1, V012, V000, V008, V000, V012, V000, V007, V000, V014, V000, V007, V000, V012, V006, V008, V005, hasOutput);

        setHitPattern(LEFT_ARM_DR, patternId2, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(LEFT_ARM_DR, patternId2, V012, V000, V008, V000, V012, V000, V007, V000, V014, V000, V007, V000, V012, V006, V008, V005, hasOutput);

        // Right arm
        // ---------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_ARM_DR, patternId0, REST, REST, REST, REST, SNRG, REST, REST, REST, REST, REST, REST, REST, SNRG, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_ARM_DR, patternId0, V014, V000, V000, V000, V012, V000, V000, V008, V000, V000, V000, V000, V012, V000, V000, V000, hasOutput);

        setHitPattern(RIGHT_ARM_DR, patternId1, REST, REST, REST, REST, SNRG, REST, REST, REST, REST, REST, REST, REST, SNRG, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_ARM_DR, patternId1, V000, V000, V000, V000, V012, V000, V000, V008, V000, V000, V000, V000, V014, V000, V012, V000, hasOutput);

        setHitPattern(RIGHT_ARM_DR, patternId2, CRSH, REST, REST, REST, CRSH, REST, REST, REST, CRSH, REST, REST, REST, CRSH, REST, REST, REST, hasOutput);
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
        // -----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_LEG_DR, patternId0, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, hasOutput);

        // ----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(LEFT_ARM_DR, patternId0, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, hasOutput);

        // ----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_ARM_DR, patternId0, CRSH, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_ARM_DR, patternId0, V014, V000, V000, V000, V012, V000, V000, V008, V000, V000, V000, V000, V000, V000, V000, V000, hasOutput);


        // Pattern 1: intro
        // -----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_LEG_DR, patternId1, REST, BDRU, REST, BDRU, REST, BDRU, REST, BDRU, REST, BDRU, REST, BDRU, REST, BDRU, REST, REST, hasOutput);
        setVelPattern(RIGHT_LEG_DR, patternId1, V000, V012, V000, V012, V000, V000, V000, V000, V008, V000, V015, V000, V000, V000, V000, V000, hasOutput);

        // ----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(LEFT_ARM_DR, patternId1, SNLT, REST, REST, REST, SNLT, REST, REST, REST, SNLT, REST, REST, REST, SNLT, REST, REST, REST, hasOutput);
        setVelPattern(LEFT_ARM_DR, patternId1, V012, V000, V008, V000, V012, V000, V007, V000, V014, V000, V007, V000, V012, V006, V008, V005, hasOutput);

        // ---------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_ARM_DR, patternId1, SNRG, REST, REST, REST, SNRG, REST, REST, REST, SNRG, REST, REST, REST, SNRG, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_ARM_DR, patternId1, V015, V000, V000, V000, V012, V000, V000, V008, V015, V000, V000, V000, V014, V000, V012, V000, hasOutput);


        // Pattern 2: chorus
        // -----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_LEG_DR, patternId2, BDRU, REST, REST, BDRU, REST, REST, BDRU, REST, BDRU, REST, BDRU, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_LEG_DR, patternId2, V012, V000, V000, V012, V000, V000, V012, V000, V008, V000, V015, V000, V000, V000, V000, V000, hasOutput);

        // ----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(LEFT_ARM_DR, patternId2, REST, REST, REST, REST, SNLT, REST, REST, SNLT, REST, SNLT, REST, REST, SNLT, REST, REST, REST, hasOutput);
        setVelPattern(LEFT_ARM_DR, patternId2, V012, V000, V008, V000, V012, V000, V007, V012, V014, V012, V007, V000, V012, V000, V007, V000, hasOutput);

        // ---------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_ARM_DR, patternId2, CRSH, REST, REST, REST, CRSH, REST, REST, REST, CRSH, REST, REST, REST, CRSH, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_ARM_DR, patternId2, V012, V000, V000, V000, V012, V000, V000, V008, V012, V000, V000, V000, V014, V000, V012, V000, hasOutput);

        // Pattern 3: verse
        // -----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_LEG_DR, patternId3, BDRU, REST, BDRU, REST, REST, REST, REST, REST, BDRU, REST, BDRU, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_LEG_DR, patternId3, V012, V000, V000, V012, V000, V000, V012, V000, V008, V000, V015, V000, V000, V000, V000, V000, hasOutput);

        // ----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(LEFT_ARM_DR, patternId3, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, hasOutput);
        setVelPattern(LEFT_ARM_DR, patternId3, V012, V000, V008, V000, V012, V000, V007, V000, V014, V012, V007, V000, V012, V000, V007, V000, hasOutput);

        // ---------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_ARM_DR, patternId3, CRSH, REST, REST, REST, SNRG, REST, REST, REST, REST, REST, REST, REST, SNRG, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_ARM_DR, patternId3, V012, V000, V000, V000, V012, V000, V000, V008, V012, V000, V000, V000, V014, V000, V012, V000, hasOutput);

        byte smellsLikePattSeq[nbMeasures_] = { 0, 0, 0, 1, 2, 2, 2, 2,
                                                3, 3, 3, 3, 3, 3, 3, 3,
                                                2, 2, 2, 2 };
        setPatternSequence(smellsLikePattSeq);

        break;
      }
      // ----------------------------- SEVEN_NATION -----------------------------------------
    case SEVEN_NATION:
      {
        nbPatterns_ = 4;
        nbMeasures_ = 14;
        initializeBlankPatterns(nbPatterns_, nbMeasures_);

        byte patternId0 = 0;
        byte patternId1 = 1;
        byte patternId2 = 2;
        byte patternId3 = 3;

        // Pattern 0: empty
        // -----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_LEG_DR, patternId0, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, hasOutput);
        // ----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(LEFT_ARM_DR, patternId0, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, hasOutput);
        // ----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_ARM_DR, patternId0, CRSH, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_ARM_DR, patternId0, V014, V000, V000, V000, V012, V000, V000, V008, V000, V000, V000, V000, V000, V000, V000, V000, hasOutput);

        // Pattern 1: intro
        // -----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_LEG_DR, patternId1, BDRU, REST, REST, REST, BDRU, REST, REST, REST, BDRU, REST, REST, REST, BDRU, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_LEG_DR, patternId1, V015, V012, V000, V012, V014, V000, V000, V000, V013, V000, V015, V000, V012, V000, V000, V000, hasOutput);

        // ----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(LEFT_ARM_DR, patternId1, SNLT, REST, REST, REST, SNLT, REST, REST, REST, SNLT, REST, REST, REST, SNLT, REST, REST, REST, hasOutput);
        setVelPattern(LEFT_ARM_DR, patternId1, V008, V000, V008, V000, V008, V000, V007, V000, V008, V000, V007, V000, V008, V006, V008, V005, hasOutput);

        // ---------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_ARM_DR, patternId1, SNRG, REST, REST, REST, SNRG, REST, REST, REST, SNRG, REST, REST, REST, SNRG, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_ARM_DR, patternId1, V008, V000, V000, V000, V008, V000, V000, V008, V008, V000, V000, V000, V008, V000, V012, V000, hasOutput);

        // Pattern 2: bridge
        // -----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_LEG_DR, patternId2, BDRU, REST, REST, BDRU, REST, REST, REST, REST, BDRU, REST, REST, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_LEG_DR, patternId2, V012, V000, V000, V012, V000, V000, V012, V000, V008, V000, V015, V000, V000, V000, V000, V000, hasOutput);

        // ----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(LEFT_ARM_DR, patternId2, SNLT, REST, REST, REST, SNLT, REST, REST, REST, SNLT, REST, REST, REST, SNLT, REST, REST, REST, hasOutput);
        setVelPattern(LEFT_ARM_DR, patternId2, V012, V000, V008, V000, V012, V000, V007, V012, V014, V012, V007, V000, V012, V000, V007, V000, hasOutput);

        // ---------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_ARM_DR, patternId2, CRSH, REST, REST, REST, CRSH, REST, REST, REST, CRSH, REST, REST, REST, CRSH, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_ARM_DR, patternId2, V012, V000, V000, V000, V012, V000, V000, V008, V012, V000, V000, V000, V014, V000, V012, V000, hasOutput);

        // Pattern 3: chorus
        // -----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_LEG_DR, patternId3, BDRU, REST, REST, REST, REST, REST, REST, REST, BDRU, REST, REST, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_LEG_DR, patternId3, V012, V000, V000, V012, V000, V000, V012, V000, V008, V000, V015, V000, V000, V000, V000, V000, hasOutput);

        // ----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(LEFT_ARM_DR, patternId3, REST, REST, REST, REST, SNLT, REST, REST, REST, REST, REST, REST, REST, SNLT, REST, REST, REST, hasOutput);
        setVelPattern(LEFT_ARM_DR, patternId3, V012, V000, V008, V000, V015, V000, V007, V000, V014, V012, V007, V000, V012, V000, V007, V000, hasOutput);

        // ---------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_ARM_DR, patternId3, CRSH, REST, REST, REST, SNRG, REST, REST, REST, REST, REST, REST, REST, SNRG, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_ARM_DR, patternId3, V012, V000, V000, V000, V012, V000, V000, V008, V012, V000, V000, V000, V014, V000, V012, V000, hasOutput);

        byte sevenNationPattSeq[nbMeasures_] = { 0, 0, 0, 0, 1, 1, 1, 1,
                                                 2, 2, 3, 3, 3, 3 };
        setPatternSequence(sevenNationPattSeq);
        break;
      }
      // -------------------------------------------- BASIC RYTHM -----------------------------------------------------
    case BASIC_RYTHM:
      {
        nbPatterns_ = 3;
        nbMeasures_ = 10;
        initializeBlankPatterns(nbPatterns_, nbMeasures_);

        byte patternId0 = 0;
        byte patternId1 = 1;
        byte patternId2 = 2;

        // Right leg
        // ----------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_LEG_DR, patternId0, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_LEG_DR, patternId0, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, hasOutput);

        setHitPattern(RIGHT_LEG_DR, patternId1, BDRU, REST, REST, REST, REST, REST, REST, REST, BDRU, REST, BDRU, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_LEG_DR, patternId1, V012, V000, V000, V000, V000, V000, V000, V000, V008, V000, V015, V000, V000, V000, V000, V000, hasOutput);

        setHitPattern(RIGHT_LEG_DR, patternId2, BDRU, REST, REST, REST, REST, REST, REST, REST, BDRU, REST, BDRU, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_LEG_DR, patternId2, V012, V000, V000, V000, V000, V000, V000, V000, V008, V000, V015, V000, V000, V000, V000, V000, hasOutput);


        // Left arm
        // ---------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(LEFT_ARM_DR, patternId0, STCK, REST, REST, REST, STCK, REST, REST, REST, STCK, REST, REST, REST, STCK, REST, REST, REST, hasOutput);
        setVelPattern(LEFT_ARM_DR, patternId0, V012, V000, V000, V000, V010, V000, V000, V000, V012, V000, V000, V000, V010, V000, V000, V000, hasOutput);

        setHitPattern(LEFT_ARM_DR, patternId1, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, hasOutput);
        setVelPattern(LEFT_ARM_DR, patternId1, V012, V000, V008, V000, V012, V000, V007, V000, V014, V000, V007, V000, V012, V000, V007, V000, hasOutput);

        setHitPattern(LEFT_ARM_DR, patternId2, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, REST, SNLT, REST, SNLT, hasOutput);
        setVelPattern(LEFT_ARM_DR, patternId2, V012, V000, V008, V000, V012, V000, V007, V000, V014, V000, V007, V000, V000, V006, V000, V005, hasOutput);

        // Right arm
        // -----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_ARM_DR, patternId0, STCK, REST, REST, REST, STCK, REST, REST, REST, STCK, REST, REST, REST, STCK, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_ARM_DR, patternId0, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, hasOutput);

        setHitPattern(RIGHT_ARM_DR, patternId1, CRSH, REST, REST, REST, SNRG, REST, REST, SNRG, REST, REST, REST, REST, SNRG, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_ARM_DR, patternId1, V014, V000, V000, V000, V012, V000, V000, V008, V000, V000, V000, V000, V012, V000, V000, V000, hasOutput);

        setHitPattern(RIGHT_ARM_DR, patternId2, REST, REST, REST, REST, SNRG, REST, REST, SNRG, REST, REST, REST, REST, SNRG, REST, SNRG, REST, hasOutput);
        setVelPattern(RIGHT_ARM_DR, patternId2, V000, V000, V000, V000, V012, V000, V000, V008, V000, V000, V000, V000, V014, V000, V012, V000, hasOutput);

        byte basicPattSeq[nbMeasures_] = { 0, 1, 2, 1, 2, 1, 2, 1, 2, 1 };

        setPatternSequence(basicPattSeq);
        break;
      }
      // -------------------------------------------- COOLEST RYTHM -----------------------------------------------------
    case COOLEST_RYTHM:
      {
        nbPatterns_ = 6;
        nbMeasures_ = 7;
        initializeBlankPatterns(nbPatterns_, nbMeasures_);

        byte patternId0 = 0;
        byte patternId1 = 1;
        byte patternId2 = 2;
        byte patternId3 = 3;
        byte patternId4 = 4;
        byte patternId5 = 5;

        // Pattern 0: rest
        // ----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_LEG_DR, patternId0, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_LEG_DR, patternId0, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, hasOutput);

        // ---------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(LEFT_ARM_DR, patternId0, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(LEFT_ARM_DR, patternId0, V012, V000, V000, V000, V010, V000, V000, V000, V012, V000, V000, V000, V010, V000, V000, V000, hasOutput);

        // ----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_ARM_DR, patternId0, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_ARM_DR, patternId0, V012, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, hasOutput);


        // Pattern 1: intro
        // ----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_LEG_DR, patternId1, BDRU, REST, BDRU, REST, BDRU, REST, BDRU, REST, BDRU, REST, BDRU, REST, BDRU, REST, BDRU, REST, hasOutput);
        setVelPattern(RIGHT_LEG_DR, patternId1, V008, V000, V009, V000, V010, V000, V011, V000, V012, V000, V013, V000, V012, V014, V014, V014, hasOutput);

        // ---------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(LEFT_ARM_DR, patternId1, SNLT, REST, SNLT, REST, SNLT, REST, SNLT, REST, SNLT, REST, SNLT, REST, SNLT, REST, SNLT, REST, hasOutput);
        setVelPattern(LEFT_ARM_DR, patternId1, V008, V000, V009, V000, V010, V000, V011, V000, V012, V000, V013, V000, V012, V014, V014, V014, hasOutput);

        // ----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_ARM_DR, patternId1, SNRG, REST, SNRG, REST, SNRG, REST, SNRG, REST, SNRG, REST, SNRG, REST, SNRG, REST, SNRG, REST, hasOutput);
        setVelPattern(RIGHT_ARM_DR, patternId1, V008, V000, V009, V000, V010, V000, V011, V000, V012, V000, V013, V000, V014, V000, V014, V000, hasOutput);


        // Pattern 2: basic
        // ----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_LEG_DR, patternId2, BDRU, REST, REST, REST, REST, REST, REST, REST, BDRU, REST, BDRU, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_LEG_DR, patternId2, V012, V000, V000, V000, V000, V000, V000, V000, V008, V000, V015, V000, V000, V000, V000, V000, hasOutput);

        // ---------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(LEFT_ARM_DR, patternId2, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, hasOutput);
        setVelPattern(LEFT_ARM_DR, patternId2, V012, V000, V008, V000, V012, V000, V007, V000, V014, V000, V007, V000, V012, V000, V007, V000, hasOutput);

        // ----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_ARM_DR, patternId2, CRSH, REST, REST, REST, SNRG, REST, REST, SNRG, REST, REST, REST, REST, SNRG, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_ARM_DR, patternId2, V014, V000, V000, V000, V012, V000, V000, V013, V000, V000, V000, V000, V012, V000, V000, V000, hasOutput);


        // Pattern 3: basic 2
        // ----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_LEG_DR, patternId3, BDRU, REST, REST, REST, REST, REST, BDRU, REST, BDRU, REST, BDRU, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_LEG_DR, patternId3, V012, V000, V000, V000, V000, V000, V008, V000, V008, V000, V015, V000, V000, V000, V000, V000, hasOutput);

        // ---------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(LEFT_ARM_DR, patternId3, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, REST, SNLT, REST, SNLT, hasOutput);
        setVelPattern(LEFT_ARM_DR, patternId3, V012, V000, V008, V000, V012, V000, V007, V000, V014, V000, V007, V000, V013, V012, V012, V012, hasOutput);

        // ----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_ARM_DR, patternId3, REST, REST, REST, REST, SNRG, REST, REST, SNRG, REST, REST, REST, REST, SNRG, REST, SNRG, REST, hasOutput);
        setVelPattern(RIGHT_ARM_DR, patternId3, V014, V000, V000, V000, V012, V000, V000, V008, V000, V000, V000, V000, V015, V000, V015, V000, hasOutput);

        // Pattern 4: break
        // ----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_LEG_DR, patternId4, BDRU, REST, REST, REST, REST, REST, BDRU, REST, BDRU, REST, BDRU, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_LEG_DR, patternId4, V012, V000, V000, V000, V000, V000, V012, V000, V008, V000, V015, V000, V000, V000, V000, V000, hasOutput);

        // ---------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(LEFT_ARM_DR, patternId4, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, REST, SNLT, REST, SNLT, hasOutput);
        setVelPattern(LEFT_ARM_DR, patternId4, V012, V000, V008, V000, V012, V000, V006, V000, V010, V000, V007, V000, V012, V010, V007, V012, hasOutput);

        // ----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_ARM_DR, patternId4, REST, REST, REST, REST, SNRG, REST, SNRG, REST, SNRG, REST, SNRG, REST, SNRG, REST, SNRG, REST, hasOutput);
        setVelPattern(RIGHT_ARM_DR, patternId4, V014, V000, V000, V000, V008, V000, V009, V008, V010, V000, V011, V000, V012, V012, V014, V000, hasOutput);


        // Pattern 5: end
        // ----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_LEG_DR, patternId5, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_LEG_DR, patternId5, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, hasOutput);

        // ---------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(LEFT_ARM_DR, patternId5, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(LEFT_ARM_DR, patternId5, V012, V000, V000, V000, V010, V000, V000, V000, V012, V000, V000, V000, V010, V000, V000, V000, hasOutput);

        // ----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_ARM_DR, patternId5, CRSH, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_ARM_DR, patternId5, V015, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, hasOutput);


        byte coolestPattSeq[nbMeasures_] = { 0, 1, 2, 3, 2, 4, 5 };

        setPatternSequence(coolestPattSeq);
        break;
      }
      // -------------------------------------------- MR SANDMAN -----------------------------------------------------
    case MR_SANDMAN:
      {
        nbPatterns_ = 8;
        nbMeasures_ = 21;
        initializeBlankPatterns(nbPatterns_, nbMeasures_);

        byte patternId0 = 0;
        byte patternId1 = 1;
        byte patternId2 = 2;
        byte patternId3 = 3;
        byte patternId4 = 4;
        byte patternId5 = 5;
        byte patternId6 = 6;
        byte empty = 7;

        // Empty
        // ----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_LEG_DR, empty, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_LEG_DR, empty, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, hasOutput);

        // ---------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(LEFT_ARM_DR, empty, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(LEFT_ARM_DR, empty, V012, V000, V000, V000, V010, V000, V000, V000, V012, V000, V000, V000, V010, V000, V000, V000, hasOutput);

        // ----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_ARM_DR, empty, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_ARM_DR, empty, V012, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, hasOutput);

        // Pattern 0
        // ----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_LEG_DR, patternId0, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_LEG_DR, patternId0, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, hasOutput);

        // ---------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(LEFT_ARM_DR, patternId0, STCK, REST, REST, REST, STCK, REST, REST, REST, STCK, REST, REST, REST, STCK, REST, REST, REST, hasOutput);
        setVelPattern(LEFT_ARM_DR, patternId0, V012, V000, V000, V000, V010, V000, V000, V000, V012, V000, V000, V000, V010, V000, V000, V000, hasOutput);

        // ----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_ARM_DR, patternId0, STCK, REST, REST, REST, STCK, REST, REST, REST, STCK, REST, REST, REST, STCK, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_ARM_DR, patternId0, V012, V000, V000, V000, V010, V000, V000, V000, V012, V000, V000, V000, V010, V000, V000, V000, hasOutput);


        // Pattern 1
        // ----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_LEG_DR, patternId1, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, BDRU, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_LEG_DR, patternId1, V008, V000, V009, V000, V010, V000, V011, V000, V012, V000, V013, V000, V012, V014, V014, V014, hasOutput);

        // ---------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(LEFT_ARM_DR, patternId1, STCK, REST, REST, REST, STCK, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(LEFT_ARM_DR, patternId1, V008, V000, V009, V000, V010, V000, V011, V000, V012, V000, V013, V000, V012, V014, V014, V014, hasOutput);

        // ----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_ARM_DR, patternId1, STCK, REST, REST, REST, STCK, REST, REST, REST, CRSH, REST, REST, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_ARM_DR, patternId1, V008, V000, V009, V000, V010, V000, V011, V000, V012, V000, V013, V000, V014, V000, V014, V000, hasOutput);


        // Pattern 2
        // ----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_LEG_DR, patternId2, BDRU, REST, REST, REST, BDRU, REST, REST, REST, BDRU, REST, REST, REST, BDRU, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_LEG_DR, patternId2, V012, V000, V000, V000, V000, V000, V000, V000, V008, V000, V015, V000, V000, V000, V000, V000, hasOutput);

        // ---------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(LEFT_ARM_DR, patternId2, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, hasOutput);
        setVelPattern(LEFT_ARM_DR, patternId2, V004, V000, V012, V000, V003, V000, V013, V000, V004, V000, V012, V000, V003, V000, V013, V000, hasOutput);

        // ----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_ARM_DR, patternId2, REST, REST, SNRG, REST, REST, REST, SNRG, REST, REST, REST, SNRG, REST, REST, REST, SNRG, REST, hasOutput);
        setVelPattern(RIGHT_ARM_DR, patternId2, V014, V000, V000, V000, V012, V000, V012, V013, V000, V000, V011, V000, V012, V000, V013, V000, hasOutput);


        // Pattern 3: basic 2
        // ----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_LEG_DR, patternId3, BDRU, REST, REST, REST, BDRU, REST, REST, REST, BDRU, REST, BDRU, REST, BDRU, REST, BDRU, REST, hasOutput);
        setVelPattern(RIGHT_LEG_DR, patternId3, V012, V000, V000, V000, V000, V000, V000, V000, V008, V000, V015, V000, V000, V000, V000, V000, hasOutput);

        // ---------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(LEFT_ARM_DR, patternId3, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, hasOutput);
        setVelPattern(LEFT_ARM_DR, patternId3, V004, V000, V012, V000, V003, V000, V013, V000, V004, V000, V012, V000, V003, V000, V013, V000, hasOutput);

        // ----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_ARM_DR, patternId3, REST, REST, SNRG, REST, REST, REST, SNRG, REST, REST, REST, SNRG, REST, REST, REST, SNRG, REST, hasOutput);
        setVelPattern(RIGHT_ARM_DR, patternId3, V014, V000, V000, V000, V012, V000, V012, V013, V000, V000, V011, V000, V012, V000, V013, V000, hasOutput);


        // Pattern 4
        // ----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_LEG_DR, patternId4, BDRU, REST, REST, REST, BDRU, REST, REST, REST, BDRU, REST, REST, REST, BDRU, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_LEG_DR, patternId4, V012, V000, V000, V000, V000, V000, V000, V000, V008, V000, V015, V000, V000, V000, V000, V000, hasOutput);

        // ---------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(LEFT_ARM_DR, patternId4, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, hasOutput);
        setVelPattern(LEFT_ARM_DR, patternId4, V004, V000, V012, V000, V003, V000, V013, V000, V004, V000, V012, V000, V003, V000, V013, V000, hasOutput);

        // ----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_ARM_DR, patternId4, CRSH, REST, SNRG, REST, REST, REST, SNRG, REST, REST, REST, SNRG, REST, REST, REST, SNRG, REST, hasOutput);
        setVelPattern(RIGHT_ARM_DR, patternId4, V014, V000, V000, V000, V012, V000, V012, V013, V000, V000, V011, V000, V012, V000, V013, V000, hasOutput);


        // Pattern 5
        // ----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_LEG_DR, patternId5, BDRU, REST, REST, REST, BDRU, REST, REST, REST, BDRU, REST, REST, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_LEG_DR, patternId5, V012, V000, V000, V000, V000, V000, V000, V000, V008, V000, V015, V000, V000, V000, V000, V000, hasOutput);

        // ---------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(LEFT_ARM_DR, patternId5, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, REST, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(LEFT_ARM_DR, patternId5, V004, V000, V012, V000, V003, V000, V013, V000, V004, V000, V012, V000, V003, V000, V013, V000, hasOutput);

        // ----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_ARM_DR, patternId5, REST, REST, SNRG, REST, REST, REST, SNRG, REST, REST, REST, CRSH, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_ARM_DR, patternId5, V014, V000, V000, V000, V012, V000, V012, V013, V000, V000, V011, V000, V012, V000, V013, V000, hasOutput);


        // Pattern 6
        // ----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_LEG_DR, patternId6, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_LEG_DR, patternId6, V012, V000, V000, V000, V000, V000, V000, V000, V008, V000, V015, V000, V000, V000, V000, V000, hasOutput);

        // ---------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(LEFT_ARM_DR, patternId6, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(LEFT_ARM_DR, patternId6, V004, V000, V012, V000, V003, V000, V013, V000, V004, V000, V012, V000, V003, V000, V013, V000, hasOutput);

        // ----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_ARM_DR, patternId6, CRSH, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_ARM_DR, patternId6, V014, V000, V000, V000, V012, V000, V012, V013, V000, V000, V011, V000, V012, V000, V013, V000, hasOutput);


        byte coolestPattSeq[nbMeasures_] = { 0, 1, 2, 3, 2, 4, 5 };

        setPatternSequence(coolestPattSeq);
        break;
      }
      // -------------------------------------------- PUN TAS -----------------------------------------------------
    case PUN_TAS:
      {
        nbPatterns_ = 5;
        nbMeasures_ = 8;
        initializeBlankPatterns(nbPatterns_, nbMeasures_);

        byte patternId0 = 0;
        byte patternId1 = 1;
        byte patternId2 = 2;
        byte patternId3 = 3;
        byte patternId4 = 4;

        // Pattern 0: rest
        // ----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_LEG_DR, patternId0, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_LEG_DR, patternId0, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, hasOutput);

        // ---------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(LEFT_ARM_DR, patternId0, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(LEFT_ARM_DR, patternId0, V012, V000, V000, V000, V010, V000, V000, V000, V012, V000, V000, V000, V010, V000, V000, V000, hasOutput);

        // ----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_ARM_DR, patternId0, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_ARM_DR, patternId0, V012, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, hasOutput);


        // Pattern 1: basic
        // ----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_LEG_DR, patternId1, BDRU, REST, REST, REST, REST, REST, REST, REST, BDRU, REST, BDRU, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_LEG_DR, patternId1, V012, V000, V000, V000, V000, V000, V000, V000, V008, V000, V015, V000, V000, V000, V000, V000, hasOutput);

        // ---------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(LEFT_ARM_DR, patternId1, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, hasOutput);
        setVelPattern(LEFT_ARM_DR, patternId1, V012, V000, V008, V000, V012, V000, V007, V000, V010, V000, V007, V000, V012, V000, V007, V000, hasOutput);

        // ----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_ARM_DR, patternId1, REST, REST, REST, REST, SNRG, REST, REST, REST, REST, REST, REST, REST, SNRG, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_ARM_DR, patternId1, V014, V000, V000, V000, V012, V000, V000, V013, V000, V000, V000, V000, V012, V000, V012, V000, hasOutput);

        // Pattern 2: basic with crash
        // ----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_LEG_DR, patternId2, BDRU, REST, REST, REST, REST, REST, REST, REST, BDRU, REST, BDRU, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_LEG_DR, patternId2, V012, V000, V000, V000, V000, V000, V000, V000, V008, V000, V015, V000, V000, V000, V000, V000, hasOutput);

        // ---------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(LEFT_ARM_DR, patternId2, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, hasOutput);
        setVelPattern(LEFT_ARM_DR, patternId2, V012, V000, V008, V000, V012, V000, V007, V000, V008, V000, V007, V000, V012, V000, V007, V000, hasOutput);

        // ----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_ARM_DR, patternId2, CRSH, REST, REST, REST, SNRG, REST, REST, REST, REST, REST, REST, REST, SNRG, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_ARM_DR, patternId2, V014, V000, V000, V000, V012, V000, V000, V013, V000, V000, V000, V000, V012, V000, V012, V000, hasOutput);


        // Pattern 3: basic with fill
        // ----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_LEG_DR, patternId3, BDRU, REST, REST, REST, REST, REST, REST, REST, BDRU, REST, BDRU, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_LEG_DR, patternId3, V012, V000, V000, V000, V000, V000, V000, V000, V008, V000, V015, V000, V000, V000, V000, V000, hasOutput);

        // ---------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(LEFT_ARM_DR, patternId3, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, HHAT, REST, REST, SNLT, REST, SNLT, hasOutput);
        setVelPattern(LEFT_ARM_DR, patternId3, V012, V000, V008, V000, V012, V000, V007, V000, V014, V000, V007, V000, V012, V013, V013, V013, hasOutput);

        // ---------------------------------------0001--------////--------0002--------////--------0003-------////--------0004--------////------
        setHitPattern(RIGHT_ARM_DR, patternId3, REST, REST, REST, REST, SNRG, REST, REST, REST, REST, REST, REST, REST, SNRG, REST, SNRG, REST, hasOutput);
        setVelPattern(RIGHT_ARM_DR, patternId3, V014, V000, V000, V000, V012, V000, V000, V013, V000, V000, V000, V000, V012, V012, V012, V013, hasOutput);


        // Pattern 4: end
        // ----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_LEG_DR, patternId4, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_LEG_DR, patternId4, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, hasOutput);

        // ---------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(LEFT_ARM_DR, patternId4, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(LEFT_ARM_DR, patternId4, V012, V000, V000, V000, V010, V000, V000, V000, V012, V000, V000, V000, V010, V000, V000, V000, hasOutput);

        // ----------------------------------------------0001--------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_ARM_DR, patternId4, CRSH, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_ARM_DR, patternId4, V015, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, V000, hasOutput);


        byte punTasPattSeq[nbMeasures_] = { 0, 2, 1, 2, 1, 2, 3, 4 };

        setPatternSequence(punTasPattSeq);
        break;
      }
  }
}