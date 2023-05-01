#include "glocken_song_ld.h"

GlockenSongLD::GlockenSongLD()
  : PercuSong<NB_HIT_JOINTS_GL, BITS_FOR_POS_GL>::PercuSong() {
  nbOfPositions_[LEFT_ARM_GL] = NB_POS_LA_GL;
  nbOfPositions_[RIGHT_ARM_GL] = NB_POS_RA_GL;
}

void GlockenSongLD::createPredefinedPatterns(Songs songName, bool hasOutput = false) {
  switch (songName) {
    // -------------------------------------------- FRERE JACQUES -----------------------------------------------------
    case FRERE_JACQUES:
    default:
      {
        nbPatterns_ = 4;
        nbMeasures_ = 8;
        initializeBlankPatterns(nbPatterns_, nbMeasures_);

        byte patternId0 = 0;
        byte patternId1 = 1;
        byte patternId2 = 2;
        byte patternId3 = 3;

        // Left Arm
        // -----------------------------------------------0001-------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(LEFT_ARM_GL, patternId0, C00L, REST, REST, REST, D00L, REST, REST, REST, E00L, REST, REST, REST, C00L, REST, REST, REST, hasOutput);
        setVelPattern(LEFT_ARM_GL, patternId0, V015, V000, V000, V000, V006, V000, V000, V000, V008, V000, V000, V000, V015, V000, V000, V000, hasOutput);

        setHitPattern(LEFT_ARM_GL, patternId1, E00L, REST, REST, REST, F00L, REST, REST, REST, G00L, REST, REST, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(LEFT_ARM_GL, patternId1, V012, V000, V000, V000, V009, V000, V000, V000, V008, V000, V015, V000, V000, V000, V000, V000, hasOutput);

        setHitPattern(LEFT_ARM_GL, patternId2, G00L, REST, E00L, REST, G00L, REST, F00L, REST, E00L, REST, REST, REST, C00L, REST, REST, REST, hasOutput);
        setVelPattern(LEFT_ARM_GL, patternId2, V012, V000, V006, V000, V009, V000, V008, V000, V008, V000, V000, V000, V010, V000, V000, V000, hasOutput);

        setHitPattern(LEFT_ARM_GL, patternId3, D00L, REST, REST, REST, G00L, REST, REST, REST, C00L, REST, REST, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(LEFT_ARM_GL, patternId3, V009, V000, V000, V000, V006, V000, V000, V000, V015, V000, V000, V000, V000, V000, V000, V000, hasOutput);

        // Right Arm
        // -----------------------------------------------0001-------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_ARM_GL, patternId0, A00R, REST, REST, REST, C01R, REST, REST, REST, A00R, REST, REST, REST, C01R, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_ARM_GL, patternId0, V009, V000, V000, V000, V006, V000, V000, V000, V008, V000, V000, V000, V006, V000, V000, V000, hasOutput);

        setHitPattern(RIGHT_ARM_GL, patternId1, A00R, REST, REST, REST, C01R, REST, REST, REST, C01R, REST, C01R, REST, B00R, REST, C01R, REST, hasOutput);
        setVelPattern(RIGHT_ARM_GL, patternId1, V012, V000, V000, V000, V009, V000, V000, V000, V008, V000, V015, V000, V015, V000, V012, V000, hasOutput);

        setHitPattern(RIGHT_ARM_GL, patternId2, C01R, REST, A00R, REST, C01R, REST, C01R, REST, A00R, REST, REST, REST, C01R, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_ARM_GL, patternId2, V012, V000, V006, V000, V009, V000, V008, V000, V008, V000, V000, V000, V010, V000, V000, V000, hasOutput);

        setHitPattern(RIGHT_ARM_GL, patternId3, C01R, REST, REST, REST, C01R, REST, REST, REST, C01R, REST, REST, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_ARM_GL, patternId3, V009, V000, V000, V000, V006, V000, V000, V000, V008, V000, V000, V000, V000, V000, V000, V000, hasOutput);

        // Head
        // ------------------------------------------0001-------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(HEAD_GL, patternId0, HDCN, REST, REST, REST, HDRG, REST, REST, REST, HDLF, REST, REST, REST, HDRG, REST, REST, REST, hasOutput);
        setVelPattern(HEAD_GL, patternId0, V015, V000, V000, V000, V006, V000, V000, V000, V008, V000, V000, V000, V015, V000, V000, V000, hasOutput);

        setHitPattern(HEAD_GL, patternId1, HDRG, REST, REST, REST, HDCN, REST, REST, REST, HDLF, REST, REST, REST, HDCN, REST, REST, REST, hasOutput);
        setVelPattern(HEAD_GL, patternId1, V012, V000, V000, V000, V009, V000, V000, V000, V008, V000, V015, V000, V000, V000, V000, V000, hasOutput);

        setHitPattern(HEAD_GL, patternId2, HDRG, REST, REST, REST, HDLF, REST, HDRG, REST, HDLF, REST, HDRG, REST, HDCN, REST, REST, REST, hasOutput);
        setVelPattern(HEAD_GL, patternId2, V012, V000, V006, V000, V009, V000, V008, V000, V008, V000, V000, V000, V010, V000, V000, V000, hasOutput);

        setHitPattern(HEAD_GL, patternId3, HDCN, REST, REST, REST, HDRG, REST, REST, REST, HDLF, REST, REST, REST, HDCN, REST, REST, REST, hasOutput);
        setVelPattern(HEAD_GL, patternId3, V009, V000, V000, V000, V006, V000, V000, V000, V015, V000, V000, V000, V000, V000, V000, V000, hasOutput);

        byte frereJacquesPattSeq[nbMeasures_] = { 0, 0, 1, 1, 2, 2, 3, 3 };
        setPatternSequence(frereJacquesPattSeq);

        break;
      }
      // -------------------------------------------- HOUND_DOG -----------------------------------------------------
    case HOUND_DOG:
      {
        nbPatterns_ = 4;
        nbMeasures_ = 6;
        initializeBlankPatterns(nbPatterns_, nbMeasures_);

        byte initialChord = 0;
        byte patternA = 1;
        byte patternD = 2;
        byte patternE = 3;

        // Pattern 0 ----------------------------------------------------------
        // Left Arm
        setSemiquaverHit(LEFT_ARM_GL, CS0L, V009, initialChord, 1, hasOutput);
        setSemiquaverHit(LEFT_ARM_GL, E00L, V012, initialChord, 4, hasOutput);
        setSemiquaverHit(LEFT_ARM_GL, E00L, V015, initialChord, 7, hasOutput);

        // Right Arm
        setSemiquaverHit(RIGHT_ARM_GL, A00R, V009, initialChord, 1, hasOutput);
        setSemiquaverHit(RIGHT_ARM_GL, A00R, V012, initialChord, 4, hasOutput);
        setSemiquaverHit(RIGHT_ARM_GL, A00R, V015, initialChord, 7, hasOutput);

        setHitPattern(HEAD_GL, initialChord, HDCN, REST, REST, REST, HDRG, REST, REST, REST, HDLF, REST, REST, REST, HDCN, REST, REST, REST, hasOutput);
        setVelPattern(HEAD_GL, initialChord, V009, V000, V000, V000, V006, V000, V000, V000, V015, V000, V000, V000, V000, V000, V000, V000, hasOutput);

        // Pattern 1: A--------------------------------------------------------
        // Left Arm
        setSemiquaverHit(LEFT_ARM_GL, CS0L, V009, patternA, 1, hasOutput);
        setSemiquaverHit(LEFT_ARM_GL, E00L, V012, patternA, 4, hasOutput);
        setSemiquaverHit(LEFT_ARM_GL, C00L, V015, patternA, 7, hasOutput);

        setSemiquaverHit(LEFT_ARM_GL, CS0L, V009, patternA, 9, hasOutput);
        setSemiquaverHit(LEFT_ARM_GL, E00L, V012, patternA, 12, hasOutput);
        setSemiquaverHit(LEFT_ARM_GL, C00L, V015, patternA, 15, hasOutput);

        // Right Arm
        setQuaverHit(RIGHT_ARM_GL, A00R, V012, patternA, 1, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, A00R, V009, patternA, 2, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, A00R, V012, patternA, 3, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, A00R, V009, patternA, 4, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, A00R, V012, patternA, 5, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, A00R, V009, patternA, 6, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, G00R, V012, patternA, 7, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, G00R, V009, patternA, 8, hasOutput);

        setHitPattern(HEAD_GL, patternA, HDCN, REST, REST, REST, HDRG, REST, REST, REST, HDLF, REST, REST, REST, HDCN, REST, REST, REST, hasOutput);
        setVelPattern(HEAD_GL, patternA, V009, V000, V000, V000, V006, V000, V000, V000, V015, V000, V000, V000, V000, V000, V000, V000, hasOutput);

        // Pattern 2: D--------------------------------------------------------
        // Left Arm
        setSemiquaverHit(LEFT_ARM_GL, D00L, V009, patternD, 1, hasOutput);
        setSemiquaverHit(LEFT_ARM_GL, FS0L, V012, patternD, 4, hasOutput);
        setSemiquaverHit(LEFT_ARM_GL, D00L, V015, patternD, 7, hasOutput);

        setSemiquaverHit(LEFT_ARM_GL, D00L, V009, patternD, 9, hasOutput);
        setSemiquaverHit(LEFT_ARM_GL, FS0L, V012, patternD, 12, hasOutput);
        setSemiquaverHit(LEFT_ARM_GL, D00L, V015, patternD, 15, hasOutput);

        // Right Arm
        setQuaverHit(RIGHT_ARM_GL, A00R, V012, patternD, 1, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, A00R, V009, patternD, 2, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, A00R, V012, patternD, 3, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, A00R, V009, patternD, 4, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, A00R, V012, patternD, 5, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, A00R, V009, patternD, 6, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, B00R, V012, patternD, 7, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, B00R, V009, patternD, 8, hasOutput);

        setHitPattern(HEAD_GL, patternD, HDCN, REST, REST, REST, HDRG, REST, REST, REST, HDLF, REST, REST, REST, HDCN, REST, REST, REST, hasOutput);
        setVelPattern(HEAD_GL, patternD, V009, V000, V000, V000, V006, V000, V000, V000, V015, V000, V000, V000, V000, V000, V000, V000, hasOutput);

        // Pattern 3: E--------------------------------------------------------
        // Left Arm
        setSemiquaverHit(LEFT_ARM_GL, E00L, V009, patternE, 1, hasOutput);
        setSemiquaverHit(LEFT_ARM_GL, E00L, V012, patternE, 4, hasOutput);
        setSemiquaverHit(LEFT_ARM_GL, E00L, V015, patternE, 7, hasOutput);

        setSemiquaverHit(LEFT_ARM_GL, D00L, V009, patternE, 9, hasOutput);
        setSemiquaverHit(LEFT_ARM_GL, FS0L, V012, patternE, 12, hasOutput);
        setSemiquaverHit(LEFT_ARM_GL, D00L, V015, patternE, 15, hasOutput);

        // Right Arm
        setQuaverHit(RIGHT_ARM_GL, GS0R, V012, patternE, 1, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, GS0R, V009, patternE, 2, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, B00R, V012, patternE, 3, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, B00R, V009, patternE, 4, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, A00R, V012, patternE, 5, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, A00R, V009, patternE, 6, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, B00R, V012, patternE, 7, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, B00R, V009, patternE, 8, hasOutput);

        setHitPattern(HEAD_GL, patternD, HDCN, REST, REST, REST, HDRG, REST, REST, REST, HDLF, REST, REST, REST, HDCN, REST, REST, REST, hasOutput);
        setVelPattern(HEAD_GL, patternD, V009, V000, V000, V000, V006, V000, V000, V000, V015, V000, V000, V000, V000, V000, V000, V000, hasOutput);

        byte houndDogPattSeq[nbMeasures_] = { initialChord, patternA, patternA, patternD,
                                              patternA, patternE };
        setPatternSequence(houndDogPattSeq);

        break;
      }
      // ----------------------------- RUDY -----------------------------------------
    case RUDY:
      {
        nbPatterns_ = 6;
        nbMeasures_ = 10;
        initializeBlankPatterns(nbPatterns_, nbMeasures_);

        byte pattern0 = 0;
        byte pattern1 = 1;
        byte pattern2 = 2;
        byte pattern3 = 3;
        byte pattern4 = 4;
        byte pattern5 = 5;

        // Pattern 0 ----------------------------------------------------------
        setQuarterHit(LEFT_ARM_GL, D00L, V010, pattern0, 1, hasOutput);
        setQuarterHit(LEFT_ARM_GL, E00L, V010, pattern0, 3, hasOutput);

        setQuarterHit(RIGHT_ARM_GL, A00R, V008, pattern0, 1, hasOutput);
        setQuarterHit(RIGHT_ARM_GL, A00R, V008, pattern0, 2, hasOutput);
        setQuarterHit(RIGHT_ARM_GL, B00R, V008, pattern0, 3, hasOutput);
        setQuarterHit(RIGHT_ARM_GL, GS0R, V015, pattern0, 4, hasOutput);

        setHitPattern(HEAD_GL, pattern0, HDCN, REST, REST, REST, HDRG, REST, REST, REST, HDLF, REST, REST, REST, HDCN, REST, REST, REST, hasOutput);
        setVelPattern(HEAD_GL, pattern0, V009, V000, V000, V000, V006, V000, V000, V000, V015, V000, V000, V000, V000, V000, V000, V000, hasOutput);

        // Pattern 1
        setQuarterHit(LEFT_ARM_GL, E00L, V015, pattern1, 1, hasOutput);
        setQuaverHit(LEFT_ARM_GL, CS0L, V009, pattern1, 8, hasOutput);

        setQuarterHit(RIGHT_ARM_GL, A00R, V015, pattern1, 1, hasOutput);

        setHitPattern(HEAD_GL, pattern1, HDCN, REST, REST, REST, HDRG, REST, REST, REST, HDLF, REST, REST, REST, HDCN, REST, REST, REST, hasOutput);
        setVelPattern(HEAD_GL, pattern1, V009, V000, V000, V000, V006, V000, V000, V000, V015, V000, V000, V000, V000, V000, V000, V000, hasOutput);

        // Pattern 2
        setQuaverHit(LEFT_ARM_GL, D00L, V015, pattern2, 1, hasOutput);
        setQuaverHit(LEFT_ARM_GL, D00L, V009, pattern2, 2, hasOutput);
        setQuaverHit(LEFT_ARM_GL, D00L, V009, pattern2, 4, hasOutput);
        setQuaverHit(LEFT_ARM_GL, E00L, V009, pattern2, 5, hasOutput);
        setQuaverHit(LEFT_ARM_GL, E00L, V009, pattern2, 7, hasOutput);

        setQuarterHit(RIGHT_ARM_GL, A00R, V009, pattern2, 1, hasOutput);
        setQuarterHit(RIGHT_ARM_GL, A00R, V012, pattern2, 2, hasOutput);
        setQuarterHit(RIGHT_ARM_GL, B00R, V015, pattern2, 3, hasOutput);
        setQuarterHit(RIGHT_ARM_GL, B00R, V015, pattern2, 4, hasOutput);

        setHitPattern(HEAD_GL, pattern2, HDCN, REST, REST, REST, HDRG, REST, REST, REST, HDLF, REST, REST, REST, HDCN, REST, REST, REST, hasOutput);
        setVelPattern(HEAD_GL, pattern2, V009, V000, V000, V000, V006, V000, V000, V000, V015, V000, V000, V000, V000, V000, V000, V000, hasOutput);

        // Pattern 3
        setQuarterHit(LEFT_ARM_GL, CS0L, V015, pattern3, 1, hasOutput);
        setQuaverHit(LEFT_ARM_GL, CS0L, V009, pattern3, 8, hasOutput);

        setQuarterHit(RIGHT_ARM_GL, A00R, V009, pattern2, 1, hasOutput);
        setQuarterHit(RIGHT_ARM_GL, A00R, V012, pattern2, 2, hasOutput);
        setQuarterHit(RIGHT_ARM_GL, A00R, V015, pattern2, 3, hasOutput);
        setQuarterHit(RIGHT_ARM_GL, A00R, V015, pattern2, 4, hasOutput);

        setHitPattern(HEAD_GL, pattern3, HDCN, REST, REST, REST, HDRG, REST, REST, REST, HDLF, REST, REST, REST, HDCN, REST, REST, REST, hasOutput);
        setVelPattern(HEAD_GL, pattern3, V009, V000, V000, V000, V006, V000, V000, V000, V015, V000, V000, V000, V000, V000, V000, V000, hasOutput);

        // Pattern 4
        setQuaverHit(LEFT_ARM_GL, D00L, V015, pattern4, 1, hasOutput);
        setQuaverHit(LEFT_ARM_GL, D00L, V009, pattern4, 2, hasOutput);
        setQuaverHit(LEFT_ARM_GL, D00L, V009, pattern4, 4, hasOutput);
        setQuaverHit(LEFT_ARM_GL, E00L, V009, pattern4, 5, hasOutput);

        setQuarterHit(RIGHT_ARM_GL, A00R, V009, pattern4, 1, hasOutput);
        setQuarterHit(RIGHT_ARM_GL, A00R, V012, pattern4, 2, hasOutput);
        setQuarterHit(RIGHT_ARM_GL, B00R, V015, pattern4, 3, hasOutput);
        setQuarterHit(RIGHT_ARM_GL, B00R, V015, pattern4, 4, hasOutput);

        setHitPattern(HEAD_GL, pattern4, HDCN, REST, REST, REST, HDRG, REST, REST, REST, HDLF, REST, REST, REST, HDCN, REST, REST, REST, hasOutput);
        setVelPattern(HEAD_GL, pattern4, V009, V000, V000, V000, V006, V000, V000, V000, V015, V000, V000, V000, V000, V000, V000, V000, hasOutput);

        // Pattern 5
        setSemiquaverHit(LEFT_ARM_GL, E00L, V012, pattern5, 1, hasOutput);
        setSemiquaverHit(LEFT_ARM_GL, FS0L, V012, pattern5, 3, hasOutput);
        setSemiquaverHit(LEFT_ARM_GL, FS0L, V012, pattern5, 7, hasOutput);
        setSemiquaverHit(LEFT_ARM_GL, FS0L, V012, pattern0, 9, hasOutput);
        setSemiquaverHit(LEFT_ARM_GL, E00L, V012, pattern0, 15, hasOutput);

        setSemiquaverHit(RIGHT_ARM_GL, A00R, V015, pattern5, 4, hasOutput);
        setSemiquaverHit(RIGHT_ARM_GL, A00R, V015, pattern5, 8, hasOutput);

        setHitPattern(HEAD_GL, pattern5, HDCN, REST, REST, REST, HDRG, REST, REST, REST, HDLF, REST, REST, REST, HDCN, REST, REST, REST, hasOutput);
        setVelPattern(HEAD_GL, pattern5, V009, V000, V000, V000, V006, V000, V000, V000, V015, V000, V000, V000, V000, V000, V000, V000, hasOutput);

        byte RudyPattSeq[nbMeasures_] = { 0, 1, 2, 3, 4, 5, 0, 5, 0, 5 };
        setPatternSequence(RudyPattSeq);

        break;
      }
      // ----------------------------- SMOKE -----------------------------------------
    case SMOKE:
      {
        nbPatterns_ = 9;
        nbMeasures_ = 22;
        initializeBlankPatterns(nbPatterns_, nbMeasures_);

        byte pattern0 = 0;
        byte pattern1 = 1;
        byte pattern2 = 2;
        byte pattern3 = 3;
        byte pattern4 = 4;
        byte pattern5 = 5;
        byte pattern6 = 6;
        byte pattern7 = 7;
        byte pattern8 = 8;

        // Left Arm
        // Pattern 0 ----------------------------------------------------------
        setQuaverHit(LEFT_ARM_GL, FS0L, V015, pattern0, 1, hasOutput);
        setQuaverHit(LEFT_ARM_GL, E00L, V015, pattern0, 3, hasOutput);
        // setQuaverHit(LEFT_ARM_GL, FS0L, V005, pattern0, 5, hasOutput);
        setQuaverHit(LEFT_ARM_GL, FS0L, V015, pattern0, 8, hasOutput);

        // setQuaverHit(RIGHT_ARM_GL, CS0G, V005, pattern0, 1, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, A00R, V005, pattern0, 3, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, B00R, V015, pattern0, 5, hasOutput);
        // setQuaverHit(RIGHT_ARM_GL, CS0G, V005, pattern0, 8, hasOutput);

        setHitPattern(HEAD_GL, pattern0, HDCN, REST, REST, REST, HDRG, REST, REST, REST, HDLF, REST, REST, REST, HDCN, REST, REST, REST, hasOutput);
        setVelPattern(HEAD_GL, pattern0, V009, V000, V000, V000, V006, V000, V000, V000, V015, V000, V000, V000, V000, V000, V000, V000, hasOutput);

        // Pattern 1 ----------------------------------------------------------
        setQuaverHit(LEFT_ARM_GL, E00L, V009, pattern1, 2, hasOutput);

        setQuaverHit(RIGHT_ARM_GL, A00R, V009, pattern1, 2, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, C01R, V009, pattern1, 4, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, B00R, V015, pattern1, 5, hasOutput);

        setHitPattern(HEAD_GL, pattern1, HDCN, REST, REST, REST, HDRG, REST, REST, REST, HDLF, REST, REST, REST, HDCN, REST, REST, REST, hasOutput);
        setVelPattern(HEAD_GL, pattern1, V009, V000, V000, V000, V006, V000, V000, V000, V015, V000, V000, V000, V000, V000, V000, V000, hasOutput);

        // Pattern 2 ----------------------------------------------------------
        setQuaverHit(LEFT_ARM_GL, FS0L, V015, pattern2, 1, hasOutput);
        setQuaverHit(LEFT_ARM_GL, E00L, V015, pattern2, 3, hasOutput);
        // setQuaverHit(LEFT_ARM_GL, FS0G, V005, pattern0, 5, hasOutput);
        setQuaverHit(LEFT_ARM_GL, E00L, V015, pattern2, 8, hasOutput);

        // setQuaverHit(RIGHT_ARM_GL, CS0G, V005, pattern2, 1, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, A00R, V005, pattern2, 3, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, B00R, V014, pattern2, 5, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, A00R, V005, pattern2, 8, hasOutput);

        setHitPattern(HEAD_GL, pattern2, HDCN, REST, REST, REST, HDRG, REST, REST, REST, HDLF, REST, REST, REST, HDCN, REST, REST, REST, hasOutput);
        setVelPattern(HEAD_GL, pattern2, V009, V000, V000, V000, V006, V000, V000, V000, V015, V000, V000, V000, V000, V000, V000, V000, hasOutput);

        // Pattern 3
        setQuaverHit(LEFT_ARM_GL, FS0L, V009, pattern3, 2, hasOutput);
        setQuaverHit(LEFT_ARM_GL, DS0L, V009, pattern3, 6, hasOutput);
        setQuaverHit(LEFT_ARM_GL, E00L, V009, pattern3, 7, hasOutput);
        setQuaverHit(LEFT_ARM_GL, F00L, V009, pattern3, 8, hasOutput);

        // setQuaverHit(RIGHT_ARM_GL, CS0G, V009, pattern3, 2, hasOutput);

        setHitPattern(HEAD_GL, pattern3, HDCN, REST, REST, REST, HDRG, REST, REST, REST, HDLF, REST, REST, REST, HDCN, REST, REST, REST, hasOutput);
        setVelPattern(HEAD_GL, pattern3, V009, V000, V000, V000, V006, V000, V000, V000, V015, V000, V000, V000, V000, V000, V000, V000, hasOutput);

        // Pattern 4: FS
        setQuaverHit(LEFT_ARM_GL, FS0L, V009, pattern4, 1, hasOutput);
        setQuaverHit(LEFT_ARM_GL, FS0L, V009, pattern4, 2, hasOutput);
        setQuaverHit(LEFT_ARM_GL, FS0L, V015, pattern4, 3, hasOutput);
        setQuaverHit(LEFT_ARM_GL, FS0L, V009, pattern4, 5, hasOutput);
        setQuaverHit(LEFT_ARM_GL, FS0L, V009, pattern4, 6, hasOutput);
        setQuaverHit(LEFT_ARM_GL, FS0L, V015, pattern4, 7, hasOutput);

        setHitPattern(HEAD_GL, pattern4, HDCN, REST, REST, REST, HDRG, REST, REST, REST, HDLF, REST, REST, REST, HDCN, REST, REST, REST, hasOutput);
        setVelPattern(HEAD_GL, pattern4, V009, V000, V000, V000, V006, V000, V000, V000, V015, V000, V000, V000, V000, V000, V000, V000, hasOutput);


        // setQuaverHit(RIGHT_ARM_GL, CS0G, V009, pattern4, 1, hasOutput);
        // setQuaverHit(RIGHT_ARM_GL, CS0G, V009, pattern4, 2, hasOutput);
        // setQuaverHit(RIGHT_ARM_GL, CS0G, V015, pattern4, 3, hasOutput);
        // setQuaverHit(RIGHT_ARM_GL, CS0G, V015, pattern4, 5, hasOutput);
        // setQuaverHit(RIGHT_ARM_GL, CS0G, V009, pattern4, 6, hasOutput);
        // setQuaverHit(RIGHT_ARM_GL, CS0G, V009, pattern4, 7, hasOutput);

        // Pattern 5: E
        setQuaverHit(LEFT_ARM_GL, E00L, V015, pattern5, 1, hasOutput);
        setQuaverHit(LEFT_ARM_GL, E00L, V009, pattern5, 2, hasOutput);
        setQuaverHit(LEFT_ARM_GL, E00L, V009, pattern5, 3, hasOutput);
        setQuaverHit(LEFT_ARM_GL, E00L, V015, pattern5, 5, hasOutput);
        setQuaverHit(LEFT_ARM_GL, E00L, V009, pattern5, 6, hasOutput);
        setQuaverHit(LEFT_ARM_GL, E00L, V009, pattern5, 7, hasOutput);

        setQuaverHit(RIGHT_ARM_GL, B00R, V015, pattern5, 1, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, B00R, V009, pattern5, 2, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, B00R, V009, pattern5, 3, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, B00R, V015, pattern5, 5, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, B00R, V009, pattern5, 6, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, B00R, V009, pattern5, 7, hasOutput);

        setHitPattern(HEAD_GL, pattern5, HDCN, REST, REST, REST, HDRG, REST, REST, REST, HDLF, REST, REST, REST, HDCN, REST, REST, REST, hasOutput);
        setVelPattern(HEAD_GL, pattern5, V009, V000, V000, V000, V006, V000, V000, V000, V015, V000, V000, V000, V000, V000, V000, V000, hasOutput);


        // Pattern 6: B
        setQuarterHit(LEFT_ARM_GL, FS0L, V015, pattern6, 1, hasOutput);
        setQuarterHit(LEFT_ARM_GL, FS0L, V005, pattern6, 2, hasOutput);
        setQuarterHit(LEFT_ARM_GL, FS0L, V005, pattern6, 3, hasOutput);
        setQuarterHit(LEFT_ARM_GL, FS0L, V005, pattern6, 4, hasOutput);
        setQuaverHit(LEFT_ARM_GL, FS0L, V015, pattern6, 8, hasOutput);

        setQuarterHit(RIGHT_ARM_GL, B00R, V008, pattern6, 1, hasOutput);
        setQuarterHit(RIGHT_ARM_GL, B00R, V008, pattern6, 2, hasOutput);
        setQuarterHit(RIGHT_ARM_GL, B00R, V008, pattern6, 3, hasOutput);
        setQuarterHit(RIGHT_ARM_GL, B00R, V008, pattern6, 4, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, A00R, V015, pattern6, 7, hasOutput);

        setHitPattern(HEAD_GL, pattern6, HDCN, REST, REST, REST, HDRG, REST, REST, REST, HDLF, REST, REST, REST, HDCN, REST, REST, REST, hasOutput);
        setVelPattern(HEAD_GL, pattern6, V009, V000, V000, V000, V006, V000, V000, V000, V015, V000, V000, V000, V000, V000, V000, V000, hasOutput);


        // Pattern 7: G
        setQuaverHit(LEFT_ARM_GL, FS0L, V015, pattern7, 4, hasOutput);
        setQuaverHit(LEFT_ARM_GL, DS0L, V009, pattern7, 6, hasOutput);
        setQuaverHit(LEFT_ARM_GL, E00L, V009, pattern7, 7, hasOutput);
        setQuaverHit(LEFT_ARM_GL, F00L, V009, pattern7, 8, hasOutput);

        setQuaverHit(RIGHT_ARM_GL, A00R, V015, pattern7, 1, hasOutput);
        setQuarterHit(RIGHT_ARM_GL, G00R, V015, pattern7, 2, hasOutput);
        setQuarterHit(RIGHT_ARM_GL, G00R, V015, pattern7, 3, hasOutput);
        setQuarterHit(RIGHT_ARM_GL, G00R, V015, pattern7, 4, hasOutput);

        setHitPattern(HEAD_GL, pattern7, HDCN, REST, REST, REST, HDRG, REST, REST, REST, HDLF, REST, REST, REST, HDCN, REST, REST, REST, hasOutput);
        setVelPattern(HEAD_GL, pattern7, V009, V000, V000, V000, V006, V000, V000, V000, V015, V000, V000, V000, V000, V000, V000, V000, hasOutput);


        // Pattern 8: FS
        // setQuaverHit(LEFT_ARM_GL, FS0G, V009, pattern8, 1, hasOutput);
        setQuaverHit(LEFT_ARM_GL, FS0L, V009, pattern8, 2, hasOutput);
        setQuaverHit(LEFT_ARM_GL, FS0L, V009, pattern8, 3, hasOutput);
        setQuaverHit(LEFT_ARM_GL, FS0L, V015, pattern8, 4, hasOutput);
        setQuaverHit(LEFT_ARM_GL, FS0L, V009, pattern8, 5, hasOutput);
        setQuaverHit(LEFT_ARM_GL, FS0L, V009, pattern8, 6, hasOutput);
        setQuaverHit(LEFT_ARM_GL, E00L, V009, pattern8, 7, hasOutput);
        // setQuaverHit(LEFT_ARM_GL, FS0G, V015, pattern8, 8, hasOutput);

        // setQuaverHit(RIGHT_ARM_GL, CS0G, V009, pattern8, 1, hasOutput);
        //  setQuaverHit(RIGHT_ARM_GL, CS0G, V009, pattern8, 2, hasOutput);
        //  setQuaverHit(RIGHT_ARM_GL, CS0G, V009, pattern8, 3, hasOutput);
        //  setQuaverHit(RIGHT_ARM_GL, CS0G, V015, pattern8, 4, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, A00R, V015, pattern8, 5, hasOutput);
        // setQuaverHit(RIGHT_ARM_GL, CS0G, V015, pattern8, 6, hasOutput);
        // setQuaverHit(RIGHT_ARM_GL, CS0G, V009, pattern8, 7, hasOutput);
        // setQuaverHit(RIGHT_ARM_GL, CS0G, V009, pattern8, 8, hasOutput);

        setHitPattern(HEAD_GL, pattern8, HDCN, REST, REST, REST, HDRG, REST, REST, REST, HDLF, REST, REST, REST, HDCN, REST, REST, REST, hasOutput);
        setVelPattern(HEAD_GL, pattern8, V009, V000, V000, V000, V006, V000, V000, V000, V015, V000, V000, V000, V000, V000, V000, V000, hasOutput);


        byte smokePattSeq[nbMeasures_] = { 7, 0, 1, 2, 3, 0, 1, 2, 3,
                                           4, 4, 5, 4, 4, 4, 5, 4,
                                           6, 7, 8, 8, 6 };

        setPatternSequence(smokePattSeq);

        break;
      }
      // ----------------------------- SMELLS_LIKE -----------------------------------------
    case SMELLS_LIKE:
      {
        nbPatterns_ = 4;
        nbMeasures_ = 20;
        initializeBlankPatterns(nbPatterns_, nbMeasures_);

        byte pattern0 = 0;
        byte pattern1 = 1;
        byte pattern2 = 2;
        byte pattern3 = 3;

        // Pattern 0: FS-B ----------------------------------------------------------
        // ----------------------------------------------0001-------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(LEFT_ARM_GL, pattern0, FS0L, REST, REST, FS0L, FS0L, REST, REST, REST, REST, REST, FS0L, REST, FS0L, REST, REST, REST, hasOutput);
        setVelPattern(LEFT_ARM_GL, pattern0, V015, V000, V000, V009, V000, V000, V000, V000, V008, V000, V006, V000, V006, V000, V000, V000, hasOutput);

        // ----------------------------------------------0001-------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_ARM_GL, pattern0, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, B00R, REST, B00R, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_ARM_GL, pattern0, V006, V000, V000, V006, V006, V015, V000, V000, V008, V000, V015, V000, V015, V000, V000, V000, hasOutput);

        // -----------------------------------------0001-------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(HEAD_GL, pattern0, HDCN, REST, REST, HDLF, HDRG, REST, REST, REST, REST, REST, HDRG, REST, HDCN, REST, REST, REST, hasOutput);
        setVelPattern(HEAD_GL, pattern0, V009, V000, V000, V000, V006, V000, V000, V000, V015, V000, V000, V000, V000, V000, V000, V000, hasOutput);


        // Pattern 1: A-D ----------------------------------------------------------
        // ----------------------------------------------0001-------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(LEFT_ARM_GL, pattern1, E00L, REST, REST, E00L, E00L, REST, REST, REST, REST, REST, D00L, REST, D00L, REST, REST, REST, hasOutput);
        setVelPattern(LEFT_ARM_GL, pattern1, V009, V000, V000, V009, V008, V000, V000, V000, V008, V000, V015, V000, V015, V000, V000, V000, hasOutput);

        // ----------------------------------------------0001-------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_ARM_GL, pattern1, A00R, REST, REST, A00R, A00R, REST, REST, REST, REST, REST, A00R, REST, A00R, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_ARM_GL, pattern1, V015, V000, V000, V015, V015, V015, V000, V000, V008, V000, V002, V000, V005, V000, V000, V000, hasOutput);

        // -----------------------------------------0001-------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(HEAD_GL, pattern1, HDCN, REST, REST, HDLF, HDRG, REST, REST, REST, REST, REST, HDRG, REST, HDCN, REST, REST, REST, hasOutput);
        setVelPattern(HEAD_GL, pattern1, V009, V000, V000, V000, V006, V000, V000, V000, V015, V000, V000, V000, V000, V000, V000, V000, hasOutput);

        // Pattern 2: FS-B ----------------------------------------------------------
        // ----------------------------------------------0001------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(LEFT_ARM_GL, pattern2, FS0L, REST, FS0L, REST, FS0L, REST, FS0L, REST, FS0L, REST, FS0L, REST, FS0L, REST, FS0L, REST, hasOutput);
        setVelPattern(LEFT_ARM_GL, pattern2, V015, V000, V009, V000, V009, V000, V012, V000, V002, V000, V002, V000, V002, V000, V002, V000, hasOutput);

        // ----------------------------------------------0001-------////--------0002--------////--------0003--------////--------0004--------////-----
        setHitPattern(RIGHT_ARM_GL, pattern2, REST, REST, REST, REST, REST, REST, REST, REST, B00R, REST, B00R, REST, B00R, REST, B00R, REST, hasOutput);
        setVelPattern(RIGHT_ARM_GL, pattern2, V006, V000, V006, V000, V006, V000, V006, V000, V015, V000, V015, V000, V015, V000, V015, V000, hasOutput);

        // -----------------------------------------0001-------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(HEAD_GL, pattern2, HDCN, REST, REST, REST, HDRG, REST, REST, REST, HDCN, REST, REST, REST, HDLF, REST, REST, REST, hasOutput);
        setVelPattern(HEAD_GL, pattern2, V009, V000, V000, V000, V006, V000, V000, V000, V015, V000, V000, V000, V000, V000, V000, V000, hasOutput);

        // Pattern 3: A-D ----------------------------------------------------------
        // ----------------------------------------------0001-------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(LEFT_ARM_GL, pattern3, E00L, REST, E00L, REST, E00L, REST, E00L, REST, D00L, REST, D00L, REST, D00L, REST, D00L, REST, hasOutput);
        setVelPattern(LEFT_ARM_GL, pattern3, V005, V000, V005, V000, V005, V000, V005, V000, V015, V000, V015, V000, V015, V000, V015, V000, hasOutput);

        // ----------------------------------------------0001-------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_ARM_GL, pattern3, A00R, REST, A00R, REST, A00R, REST, A00R, REST, A00R, REST, A00R, REST, A00R, REST, A00R, REST, hasOutput);
        setVelPattern(RIGHT_ARM_GL, pattern3, V015, V000, V015, V000, V015, V000, V015, V000, V005, V000, V005, V000, V005, V000, V005, V000, hasOutput);

        // -----------------------------------------0001-------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(HEAD_GL, pattern3, HDCN, REST, REST, REST, HDRG, REST, REST, REST, HDCN, REST, REST, REST, HDLF, REST, REST, REST, hasOutput);
        setVelPattern(HEAD_GL, pattern3, V009, V000, V000, V000, V006, V000, V000, V000, V015, V000, V000, V000, V000, V000, V000, V000, hasOutput);

        byte smellsLikePattSeq[nbMeasures_] = { 0, 1, 0, 1, 0, 1, 0, 1,
                                                2, 3, 2, 3, 2, 3, 2, 3,
                                                0, 1, 0, 1 };
        setPatternSequence(smellsLikePattSeq);

        break;
      }
  }
}