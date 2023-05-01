#include "glocken_song_gr.h"

GlockenSongGR::GlockenSongGR()
  : PercuSong<NB_LIMBS_GL, BITS_FOR_POS_GL>::PercuSong() {
  nbOfPositions_[LEFT_ARM_GL] = NB_POS_LA_GL;
  nbOfPositions_[RIGHT_ARM_GL] = NB_POS_RA_GL;
}

void GlockenSongGR::createPredefinedPatterns(Songs songName, bool hasOutput = false) {
  switch (songName) {
      // -------------------------------------------- FRERE_JACQUES -----------------------------------------------------
    case FRERE_JACQUES:
      {
        nbPatterns_ = 5;
        nbMeasures_ = 9;
        initializeBlankPatterns(nbPatterns_, nbMeasures_);

        byte patternId0 = 0;
        byte patternId1 = 1;
        byte patternId2 = 2;
        byte patternId3 = 3;
        byte patternId4 = 4;

        // Left Arm
        // -----------------------------------------------0001-------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(LEFT_ARM_GL, patternId0, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(LEFT_ARM_GL, patternId0, V015, V000, V000, V000, V006, V000, V000, V000, V008, V000, V000, V000, V015, V000, V000, V000, hasOutput);

        setHitPattern(LEFT_ARM_GL, patternId1, C00G, REST, REST, REST, D00G, REST, REST, REST, E00G, REST, REST, REST, C00G, REST, REST, REST, hasOutput);
        setVelPattern(LEFT_ARM_GL, patternId1, V015, V000, V000, V000, V006, V000, V000, V000, V008, V000, V000, V000, V015, V000, V000, V000, hasOutput);

        setHitPattern(LEFT_ARM_GL, patternId2, E00G, REST, REST, REST, F00G, REST, REST, REST, G00G, REST, REST, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(LEFT_ARM_GL, patternId2, V012, V000, V000, V000, V009, V000, V000, V000, V008, V000, V015, V000, V000, V000, V000, V000, hasOutput);

        setHitPattern(LEFT_ARM_GL, patternId3, G00G, REST, A00G, REST, G00G, REST, F00G, REST, E00G, REST, REST, REST, C00G, REST, REST, REST, hasOutput);
        setVelPattern(LEFT_ARM_GL, patternId3, V012, V000, V006, V000, V009, V000, V008, V000, V008, V000, V000, V000, V010, V000, V000, V000, hasOutput);

        setHitPattern(LEFT_ARM_GL, patternId4, D00G, REST, REST, REST, G00G, REST, REST, REST, C00G, REST, REST, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(LEFT_ARM_GL, patternId4, V009, V000, V000, V000, V006, V000, V000, V000, V015, V000, V000, V000, V000, V000, V000, V000, hasOutput);

        // Right Arm
        // -----------------------------------------------0001-------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_ARM_GL, patternId0, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_ARM_GL, patternId0, V009, V000, V000, V000, V006, V000, V000, V000, V008, V000, V000, V000, V006, V000, V000, V000, hasOutput);

        setHitPattern(RIGHT_ARM_GL, patternId1, E01G, REST, REST, REST, D01G, REST, REST, REST, E01G, REST, REST, REST, C01G, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_ARM_GL, patternId1, V009, V000, V000, V000, V006, V000, V000, V000, V008, V000, V000, V000, V006, V000, V000, V000, hasOutput);

        setHitPattern(RIGHT_ARM_GL, patternId2, E01G, REST, REST, REST, C01G, REST, REST, REST, D01G, REST, C01G, REST, B00G, REST, C01G, REST, hasOutput);
        setVelPattern(RIGHT_ARM_GL, patternId2, V012, V000, V000, V000, V009, V000, V000, V000, V008, V000, V015, V000, V015, V000, V012, V000, hasOutput);

        setHitPattern(RIGHT_ARM_GL, patternId3, D01G, REST, E01G, REST, D01G, REST, F01G, REST, E01G, REST, REST, REST, C01G, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_ARM_GL, patternId3, V012, V000, V006, V000, V009, V000, V008, V000, V008, V000, V000, V000, V010, V000, V000, V000, hasOutput);

        setHitPattern(RIGHT_ARM_GL, patternId4, D01G, REST, REST, REST, D01G, REST, REST, REST, C01G, REST, REST, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_ARM_GL, patternId4, V009, V000, V000, V000, V006, V000, V000, V000, V008, V000, V000, V000, V000, V000, V000, V000, hasOutput);

        byte frereJacquesPattSeq[nbMeasures_] = { 0, 1, 1, 2, 2, 3, 3, 4, 4 };
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
        byte patternC = 1;
        byte patternF = 2;
        byte patternG = 3;

        // Pattern 0 ----------------------------------------------------------
        // Left Arm
        setSemiquaverHit(LEFT_ARM_GL, C00G, V009, initialChord, 1, hasOutput);
        setSemiquaverHit(LEFT_ARM_GL, E00G, V012, initialChord, 4, hasOutput);
        setSemiquaverHit(LEFT_ARM_GL, G00G, V015, initialChord, 7, hasOutput);

        // Right Arm
        setSemiquaverHit(RIGHT_ARM_GL, C00G, V009, initialChord, 1, hasOutput);
        setSemiquaverHit(RIGHT_ARM_GL, E00G, V009, initialChord, 4, hasOutput);
        setSemiquaverHit(RIGHT_ARM_GL, C00G, V009, initialChord, 7, hasOutput);

        // Pattern 1: C--------------------------------------------------------
        // Left Arm
        setSemiquaverHit(LEFT_ARM_GL, C00G, V009, patternC, 1, hasOutput);
        setSemiquaverHit(LEFT_ARM_GL, E00G, V012, patternC, 4, hasOutput);
        setSemiquaverHit(LEFT_ARM_GL, G00G, V015, patternC, 7, hasOutput);

        setSemiquaverHit(LEFT_ARM_GL, C00G, V009, patternC, 9, hasOutput);
        setSemiquaverHit(LEFT_ARM_GL, E00G, V012, patternC, 12, hasOutput);
        setSemiquaverHit(LEFT_ARM_GL, G00G, V015, patternC, 15, hasOutput);

        // Right Arm
        setQuaverHit(RIGHT_ARM_GL, C01G, V012, patternC, 1, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, C01G, V009, patternC, 2, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, E01G, V012, patternC, 3, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, E01G, V009, patternC, 4, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, C01G, V012, patternC, 5, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, C01G, V009, patternC, 6, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, E01G, V012, patternC, 7, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, E01G, V009, patternC, 8, hasOutput);

        // Pattern 2: F--------------------------------------------------------
        // Left Arm
        setSemiquaverHit(LEFT_ARM_GL, F00G, V009, patternF, 1, hasOutput);
        setSemiquaverHit(LEFT_ARM_GL, A00G, V012, patternF, 4, hasOutput);
        setSemiquaverHit(LEFT_ARM_GL, C00G, V015, patternF, 7, hasOutput);

        setSemiquaverHit(LEFT_ARM_GL, F00G, V009, patternF, 9, hasOutput);
        setSemiquaverHit(LEFT_ARM_GL, A00G, V012, patternF, 12, hasOutput);
        setSemiquaverHit(LEFT_ARM_GL, C00G, V015, patternF, 15, hasOutput);

        // Right Arm
        setQuaverHit(RIGHT_ARM_GL, F01G, V012, patternF, 1, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, F01G, V009, patternF, 2, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, C01G, V012, patternF, 3, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, C01G, V009, patternF, 4, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, F01G, V012, patternF, 5, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, F01G, V009, patternF, 6, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, C01G, V012, patternF, 7, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, C01G, V009, patternF, 8, hasOutput);

        // Pattern 3: G--------------------------------------------------------
        // Left Arm
        setSemiquaverHit(LEFT_ARM_GL, G00G, V009, patternG, 1, hasOutput);
        setSemiquaverHit(LEFT_ARM_GL, D00G, V012, patternG, 4, hasOutput);
        setSemiquaverHit(LEFT_ARM_GL, G00G, V015, patternG, 7, hasOutput);

        setSemiquaverHit(LEFT_ARM_GL, F00G, V009, patternG, 9, hasOutput);
        setSemiquaverHit(LEFT_ARM_GL, A00G, V012, patternG, 12, hasOutput);
        setSemiquaverHit(LEFT_ARM_GL, C00G, V015, patternG, 15, hasOutput);

        // Right Arm
        setQuaverHit(RIGHT_ARM_GL, B00G, V012, patternG, 1, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, B00G, V009, patternG, 2, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, D01G, V012, patternG, 3, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, D01G, V009, patternG, 4, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, F01G, V012, patternG, 5, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, F01G, V009, patternG, 6, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, C01G, V012, patternG, 7, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, C01G, V009, patternG, 8, hasOutput);

        byte houndDogPattSeq[nbMeasures_] = { initialChord, patternC, patternC, patternF,
                                              patternC, patternG };
        setPatternSequence(houndDogPattSeq);

        break;
      }
      // ----------------------------- RUDY -----------------------------------------
    case RUDY:
      {
        nbPatterns_ = 6;
        nbMeasures_ = 8;
        initializeBlankPatterns(nbPatterns_, nbMeasures_);

        byte pattern0 = 0;
        byte pattern1 = 1;
        byte pattern2 = 2;
        byte pattern3 = 3;
        byte pattern4 = 4;
        byte pattern5 = 5;

        // Left Arm
        // Pattern 0 ----------------------------------------------------------
        setQuarterHit(LEFT_ARM_GL, GS0G, V009, pattern0, 4, hasOutput);

        // Pattern 1
        setQuarterHit(LEFT_ARM_GL, A00G, V015, pattern1, 1, hasOutput);
        setQuaverHit(LEFT_ARM_GL, CS0G, V009, pattern1, 8, hasOutput);

        // Pattern 2
        setQuaverHit(LEFT_ARM_GL, D00G, V015, pattern2, 1, hasOutput);
        setQuaverHit(LEFT_ARM_GL, D00G, V009, pattern2, 2, hasOutput);
        setQuaverHit(LEFT_ARM_GL, D00G, V009, pattern2, 4, hasOutput);
        setQuaverHit(LEFT_ARM_GL, E00G, V009, pattern2, 5, hasOutput);
        setQuaverHit(LEFT_ARM_GL, E00G, V009, pattern2, 7, hasOutput);

        // Pattern 3
        setQuarterHit(LEFT_ARM_GL, CS0G, V015, pattern3, 1, hasOutput);
        setQuaverHit(LEFT_ARM_GL, CS0G, V009, pattern3, 8, hasOutput);

        // Pattern 4
        setQuaverHit(LEFT_ARM_GL, D00G, V015, pattern4, 1, hasOutput);
        setQuaverHit(LEFT_ARM_GL, D00G, V009, pattern4, 2, hasOutput);
        setQuaverHit(LEFT_ARM_GL, D00G, V009, pattern4, 4, hasOutput);
        setQuaverHit(LEFT_ARM_GL, E00G, V009, pattern4, 5, hasOutput);

        // Pattern 5: empty

        // Right Arm
        // Pattern 0: empty
        // Pattern 1:
        setQuaverHit(RIGHT_ARM_GL, E00G, V009, pattern1, 4, hasOutput);

        // Pattern 2: D-E -------------------------------------------------------
        setQuarterHit(RIGHT_ARM_GL, D01G, V009, pattern2, 1, hasOutput);
        setQuarterHit(RIGHT_ARM_GL, D01G, V012, pattern2, 2, hasOutput);
        setQuarterHit(RIGHT_ARM_GL, E01G, V015, pattern2, 3, hasOutput);
        setQuarterHit(RIGHT_ARM_GL, E01G, V015, pattern2, 4, hasOutput);

        // Pattern 3:
        setQuaverHit(RIGHT_ARM_GL, E00G, V009, pattern3, 4, hasOutput);

        // Pattern 4:
        setQuarterHit(RIGHT_ARM_GL, D01G, V009, pattern4, 1, hasOutput);
        setQuarterHit(RIGHT_ARM_GL, D01G, V012, pattern4, 2, hasOutput);
        setQuarterHit(RIGHT_ARM_GL, E01G, V015, pattern4, 3, hasOutput);
        setQuarterHit(RIGHT_ARM_GL, E01G, V015, pattern4, 4, hasOutput);

        // Pattern 5: empty

        byte rudyPattSeq[nbMeasures_] = { 0, 1, 2, 3, 4, 5, 5, 5 };
        setPatternSequence(rudyPattSeq);

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
        setQuaverHit(LEFT_ARM_GL, FS0G, V015, pattern0, 1, hasOutput);
        setQuaverHit(LEFT_ARM_GL, A00G, V015, pattern0, 3, hasOutput);
        //setQuaverHit(LEFT_ARM_GL, FS0G, V005, pattern0, 5, hasOutput);
        setQuaverHit(LEFT_ARM_GL, FS0G, V015, pattern0, 8, hasOutput);

        setQuaverHit(RIGHT_ARM_GL, CS0G, V005, pattern0, 1, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, E00G, V005, pattern0, 3, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, B00G, V015, pattern0, 5, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, CS0G, V005, pattern0, 8, hasOutput);

        // Pattern 1 ----------------------------------------------------------
        setQuaverHit(LEFT_ARM_GL, A00G, V009, pattern1, 2, hasOutput);

        setQuaverHit(RIGHT_ARM_GL, E00G, V009, pattern1, 2, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, C01G, V009, pattern1, 4, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, B00G, V015, pattern1, 5, hasOutput);

        // Pattern 2 ----------------------------------------------------------
        setQuaverHit(LEFT_ARM_GL, FS0G, V015, pattern2, 1, hasOutput);
        setQuaverHit(LEFT_ARM_GL, A00G, V015, pattern2, 3, hasOutput);
        //setQuaverHit(LEFT_ARM_GL, FS0G, V005, pattern0, 5, hasOutput);
        setQuaverHit(LEFT_ARM_GL, A00G, V015, pattern2, 8, hasOutput);

        setQuaverHit(RIGHT_ARM_GL, CS0G, V005, pattern2, 1, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, E00G, V005, pattern2, 3, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, B00G, V014, pattern2, 5, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, E00G, V005, pattern2, 8, hasOutput);

        // Pattern 3
        setQuaverHit(LEFT_ARM_GL, FS0G, V009, pattern3, 2, hasOutput);
        setQuaverHit(LEFT_ARM_GL, DS0G, V009, pattern3, 6, hasOutput);
        setQuaverHit(LEFT_ARM_GL, E00G, V009, pattern3, 7, hasOutput);
        setQuaverHit(LEFT_ARM_GL, F00G, V009, pattern3, 8, hasOutput);

        setQuaverHit(RIGHT_ARM_GL, CS0G, V009, pattern3, 2, hasOutput);

        // Pattern 4: FS
        setQuaverHit(LEFT_ARM_GL, FS0G, V009, pattern4, 1, hasOutput);
        setQuaverHit(LEFT_ARM_GL, FS0G, V009, pattern4, 2, hasOutput);
        setQuaverHit(LEFT_ARM_GL, FS0G, V015, pattern4, 3, hasOutput);
        setQuaverHit(LEFT_ARM_GL, FS0G, V009, pattern4, 5, hasOutput);
        setQuaverHit(LEFT_ARM_GL, FS0G, V009, pattern4, 6, hasOutput);
        setQuaverHit(LEFT_ARM_GL, FS0G, V015, pattern4, 7, hasOutput);

        setQuaverHit(RIGHT_ARM_GL, CS0G, V009, pattern4, 1, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, CS0G, V009, pattern4, 2, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, CS0G, V015, pattern4, 3, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, CS0G, V015, pattern4, 5, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, CS0G, V009, pattern4, 6, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, CS0G, V009, pattern4, 7, hasOutput);

        // Pattern 5: E
        setQuaverHit(LEFT_ARM_GL, E00G, V015, pattern5, 1, hasOutput);
        setQuaverHit(LEFT_ARM_GL, E00G, V009, pattern5, 2, hasOutput);
        setQuaverHit(LEFT_ARM_GL, E00G, V009, pattern5, 3, hasOutput);
        setQuaverHit(LEFT_ARM_GL, E00G, V015, pattern5, 5, hasOutput);
        setQuaverHit(LEFT_ARM_GL, E00G, V009, pattern5, 6, hasOutput);
        setQuaverHit(LEFT_ARM_GL, E00G, V009, pattern5, 7, hasOutput);

        setQuaverHit(RIGHT_ARM_GL, B00G, V015, pattern5, 1, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, B00G, V009, pattern5, 2, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, B00G, V009, pattern5, 3, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, B00G, V015, pattern5, 5, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, B00G, V009, pattern5, 6, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, B00G, V009, pattern5, 7, hasOutput);

        // Pattern 6: B
        setQuarterHit(LEFT_ARM_GL, FS0G, V015, pattern6, 1, hasOutput);
        setQuarterHit(LEFT_ARM_GL, FS0G, V005, pattern6, 2, hasOutput);
        setQuarterHit(LEFT_ARM_GL, FS0G, V005, pattern6, 3, hasOutput);
        setQuarterHit(LEFT_ARM_GL, FS0G, V005, pattern6, 4, hasOutput);
        setQuaverHit(LEFT_ARM_GL, A00G, V015, pattern6, 7, hasOutput);
        setQuaverHit(LEFT_ARM_GL, FS0G, V015, pattern6, 8, hasOutput);

        setQuarterHit(RIGHT_ARM_GL, B00G, V008, pattern6, 1, hasOutput);
        setQuarterHit(RIGHT_ARM_GL, B00G, V008, pattern6, 2, hasOutput);
        setQuarterHit(RIGHT_ARM_GL, B00G, V008, pattern6, 3, hasOutput);
        setQuarterHit(RIGHT_ARM_GL, B00G, V008, pattern6, 4, hasOutput);

        // Pattern 7: G
        setQuaverHit(LEFT_ARM_GL, A00G, V015, pattern7, 1, hasOutput);
        setQuaverHit(LEFT_ARM_GL, FS0G, V015, pattern7, 4, hasOutput);
        setQuaverHit(LEFT_ARM_GL, DS0G, V009, pattern7, 6, hasOutput);
        setQuaverHit(LEFT_ARM_GL, E00G, V009, pattern7, 7, hasOutput);
        setQuaverHit(LEFT_ARM_GL, F00G, V009, pattern7, 8, hasOutput);

        setQuarterHit(RIGHT_ARM_GL, D01G, V015, pattern7, 1, hasOutput);
        setQuarterHit(RIGHT_ARM_GL, D01G, V015, pattern7, 2, hasOutput);
        setQuarterHit(RIGHT_ARM_GL, D01G, V015, pattern7, 3, hasOutput);
        setQuarterHit(RIGHT_ARM_GL, D01G, V015, pattern7, 4, hasOutput);

        // Pattern 8: FS
        //setQuaverHit(LEFT_ARM_GL, FS0G, V009, pattern8, 1, hasOutput);
        setQuaverHit(LEFT_ARM_GL, FS0G, V009, pattern8, 2, hasOutput);
        setQuaverHit(LEFT_ARM_GL, FS0G, V009, pattern8, 3, hasOutput);
        setQuaverHit(LEFT_ARM_GL, FS0G, V015, pattern8, 4, hasOutput);
        setQuaverHit(LEFT_ARM_GL, A00G, V009, pattern8, 5, hasOutput);
        setQuaverHit(LEFT_ARM_GL, FS0G, V009, pattern8, 6, hasOutput);
        setQuaverHit(LEFT_ARM_GL, E00G, V009, pattern8, 7, hasOutput);
        //setQuaverHit(LEFT_ARM_GL, FS0G, V015, pattern8, 8, hasOutput);

        //setQuaverHit(RIGHT_ARM_GL, CS0G, V009, pattern8, 1, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, CS0G, V009, pattern8, 2, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, CS0G, V009, pattern8, 3, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, CS0G, V015, pattern8, 4, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, CS0G, V015, pattern8, 5, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, CS0G, V015, pattern8, 6, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, CS0G, V009, pattern8, 7, hasOutput);
        // setQuaverHit(RIGHT_ARM_GL, CS0G, V009, pattern8, 8, hasOutput);

        byte smokePattSeq[nbMeasures_] = { 0, 1, 2, 3, 0, 1, 2, 3,
                                           4, 4, 5, 4, 4, 4, 5, 4,
                                           6, 7, 8, 8, 6, 7 };

        setPatternSequence(smokePattSeq);

        break;
      }
      // ----------------------------- SHOULD I STAY -----------------------------------------
    case SHOULD_I_STAY:
      {
        nbPatterns_ = 4;
        nbMeasures_ = 14;
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

        // Pattern 0: FS-B without melody ----------------------------------------------------------
        setQuaverHit(LEFT_ARM_GL, FS0G, V015, pattern0, 2, hasOutput);
        setQuaverHit(LEFT_ARM_GL, FS0G, V015, pattern0, 3, hasOutput);
        setQuaverHit(LEFT_ARM_GL, FS0G, V015, pattern0, 4, hasOutput);
        setQuaverHit(LEFT_ARM_GL, FS0G, V009, pattern0, 5, hasOutput);
        setQuaverHit(LEFT_ARM_GL, FS0G, V009, pattern0, 6, hasOutput);
        setQuaverHit(LEFT_ARM_GL, FS0G, V009, pattern0, 7, hasOutput);
        setQuaverHit(LEFT_ARM_GL, FS0G, V009, pattern0, 8, hasOutput);

        setQuaverHit(RIGHT_ARM_GL, CS1G, V009, pattern0, 2, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, CS1G, V009, pattern0, 3, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, CS1G, V009, pattern0, 4, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, B00G, V015, pattern0, 5, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, B00G, V015, pattern0, 6, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, B00G, V015, pattern0, 7, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, B00G, V015, pattern0, 8, hasOutput);

        // Pattern 1: one Fs hit without melody  ----------------------------------------------------------
        setQuaverHit(LEFT_ARM_GL, FS0G, V015, pattern1, 1, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, CS1G, V009, pattern1, 1, hasOutput);

        // Pattern 2: one Fs hit with melody  ----------------------------------------------------------
        setQuaverHit(LEFT_ARM_GL, FS0G, V015, pattern2, 1, hasOutput);
        setQuaverHit(LEFT_ARM_GL, FS0G, V015, pattern2, 2, hasOutput);
        setQuaverHit(LEFT_ARM_GL, FS0G, V015, pattern2, 3, hasOutput);
        setQuaverHit(LEFT_ARM_GL, FS0G, V015, pattern2, 4, hasOutput);
        setQuaverHit(LEFT_ARM_GL, A00G, V015, pattern2, 5, hasOutput);
        setQuaverHit(LEFT_ARM_GL, FS0G, V015, pattern2, 6, hasOutput);
        setQuaverHit(LEFT_ARM_GL, FS0G, V015, pattern2, 7, hasOutput);
        setQuaverHit(LEFT_ARM_GL, E00G, V015, pattern2, 8, hasOutput);

        setQuaverHit(RIGHT_ARM_GL, CS1G, V009, pattern2, 1, hasOutput);

        // Pattern 3: one Fs hit with b melody  ----------------------------------------------------------
        setQuaverHit(LEFT_ARM_GL, FS0G, V009, pattern3, 1, hasOutput);
        setQuaverHit(LEFT_ARM_GL, A00G, V015, pattern3, 8, hasOutput);

        setQuaverHit(RIGHT_ARM_GL, CS1G, V015, pattern3, 1, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, B00G, V015, pattern3, 3, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, B00G, V015, pattern3, 4, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, D00G, V015, pattern3, 5, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, B00G, V015, pattern3, 6, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, B00G, V015, pattern3, 7, hasOutput);


        // Pattern 4: B-A ----------------------------------------------------------
        setQuaverHit(LEFT_ARM_GL, FS0G, V009, pattern4, 2, hasOutput);
        setQuaverHit(LEFT_ARM_GL, FS0G, V009, pattern4, 3, hasOutput);
        setQuaverHit(LEFT_ARM_GL, FS0G, V009, pattern4, 4, hasOutput);
        setQuaverHit(LEFT_ARM_GL, A00G, V015, pattern4, 5, hasOutput);
        setQuaverHit(LEFT_ARM_GL, A00G, V015, pattern4, 6, hasOutput);
        setQuaverHit(LEFT_ARM_GL, A00G, V015, pattern4, 7, hasOutput);
        setQuaverHit(LEFT_ARM_GL, A00G, V015, pattern4, 8, hasOutput);

        setQuaverHit(RIGHT_ARM_GL, B00G, V015, pattern4, 2, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, B00G, V015, pattern4, 3, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, B00G, V015, pattern4, 4, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, E01G, V009, pattern4, 5, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, E01G, V009, pattern4, 6, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, E01G, V009, pattern4, 7, hasOutput);
        setQuaverHit(RIGHT_ARM_GL, E01G, V009, pattern4, 8, hasOutput);

        setQuaverHit(LEFT_ARM_GL, FS0G, V009, pattern4, 2, hasOutput);

        setQuaverHit(RIGHT_ARM_GL, B00G, V015, pattern4, 2, hasOutput);

        byte shouldIStayPattSeq[nbMeasures_] = { 0, 1, 0, 1, 0, 1 };
        setPatternSequence(shouldIStayPattSeq);

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
        setHitPattern(LEFT_ARM_GL, pattern0, FS0G, REST, REST, FS0G, FS0G, REST, REST, REST, REST, REST, FS0G, REST, FS0G, REST, REST, REST, hasOutput);
        setVelPattern(LEFT_ARM_GL, pattern0, V015, V000, V000, V009, V000, V000, V000, V000, V008, V000, V006, V000, V006, V000, V000, V000, hasOutput);

        // ----------------------------------------------0001-------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_ARM_GL, pattern0, CS1G, REST, REST, CS1G, CS1G, REST, REST, REST, REST, REST, B00G, REST, B00G, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_ARM_GL, pattern0, V006, V000, V000, V006, V006, V015, V000, V000, V008, V000, V015, V000, V015, V000, V000, V000, hasOutput);

        // Pattern 1: A-D ----------------------------------------------------------
        // ----------------------------------------------0001-------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(LEFT_ARM_GL, pattern1, A00G, REST, REST, A00G, A00G, REST, REST, REST, REST, REST, A00G, REST, A00G, REST, REST, REST, hasOutput);
        setVelPattern(LEFT_ARM_GL, pattern1, V015, V000, V000, V009, V000, V000, V000, V000, V008, V000, V002, V000, V002, V000, V000, V000, hasOutput);

        // ----------------------------------------------0001-------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_ARM_GL, pattern1, E01G, REST, REST, E01G, E01G, REST, REST, REST, REST, REST, D01G, REST, D01G, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_ARM_GL, pattern1, V006, V000, V000, V006, V006, V015, V000, V000, V008, V000, V015, V000, V015, V000, V000, V000, hasOutput);

        // Pattern 2: FS-B ----------------------------------------------------------
        // ----------------------------------------------0001------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(LEFT_ARM_GL, pattern2, FS0G, REST, FS0G, REST, FS0G, REST, FS0G, REST, FS0G, REST, FS0G, REST, FS0G, REST, FS0G, REST, hasOutput);
        setVelPattern(LEFT_ARM_GL, pattern2, V015, V000, V009, V000, V009, V000, V012, V000, V002, V000, V002, V000, V002, V000, V002, V000, hasOutput);

        // ----------------------------------------------0001-------////--------0002--------////--------0003--------////--------0004--------////-----
        setHitPattern(RIGHT_ARM_GL, pattern2, CS1G, REST, CS1G, REST, CS1G, REST, CS1G, REST, B00G, REST, B00G, REST, B00G, REST, B00G, REST, hasOutput);
        setVelPattern(RIGHT_ARM_GL, pattern2, V006, V000, V006, V000, V006, V000, V006, V000, V015, V000, V015, V000, V015, V000, V015, V000, hasOutput);

        // Pattern 3: A-D ----------------------------------------------------------
        // ----------------------------------------------0001-------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(LEFT_ARM_GL, pattern3, A00G, REST, A00G, REST, A00G, REST, A00G, REST, A00G, REST, A00G, REST, A00G, REST, A00G, REST, hasOutput);
        setVelPattern(LEFT_ARM_GL, pattern3, V015, V000, V009, V000, V015, V000, V012, V000, V002, V000, V002, V000, V002, V000, V002, V000, hasOutput);

        // ----------------------------------------------0001-------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_ARM_GL, pattern3, E01G, REST, E01G, REST, E01G, REST, E01G, REST, D01G, REST, D01G, REST, D01G, REST, D01G, REST, hasOutput);
        setVelPattern(RIGHT_ARM_GL, pattern3, V006, V000, V006, V000, V006, V000, V006, V000, V015, V000, V015, V000, V015, V000, V015, V000, hasOutput);

        byte smellsLikePattSeq[nbMeasures_] = { 0, 1, 0, 1, 0, 1, 0, 1,
                                                2, 3, 2, 3, 2, 3, 2, 3,
                                                0, 1, 0, 1 };
        setPatternSequence(smellsLikePattSeq);

        break;
      }
      // ----------------------------- SEVEN_NATION -----------------------------------------
    case SEVEN_NATION:
      {
        nbPatterns_ = 5;
        nbMeasures_ = 14;
        initializeBlankPatterns(nbPatterns_, nbMeasures_);

        byte pattern0 = 0;
        byte pattern1 = 1;
        byte pattern2 = 2;
        byte pattern3 = 3;
        byte pattern4 = 4;

        // Pattern 0:
        // ----------------------------------------------0001------////--------0002-------////--------0003--------////--------0004--------////------
        setHitPattern(LEFT_ARM_GL, pattern0, FS0G, REST, REST, REST, REST, REST, FS0G, REST, A00G, REST, REST, FS0G, REST, REST, E00G, REST, hasOutput);
        setVelPattern(LEFT_ARM_GL, pattern0, V015, V000, V000, V009, V000, V000, V015, V000, V008, V000, V006, V013, V006, V015, V012, V000, hasOutput);

        // ----------------------------------------------0001-------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_ARM_GL, pattern0, CS1G, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, CS1G, REST, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_ARM_GL, pattern0, V006, V000, V000, V006, V006, V015, V000, V000, V008, V000, V015, V015, V015, V000, V000, V000, hasOutput);

        // Pattern 1: ----------------------------------------------------------
        // ----------------------------------------------0001-------////--------0002-------////--------0003--------////--------0004--------////------
        setHitPattern(LEFT_ARM_GL, pattern1, D00G, REST, REST, REST, REST, REST, REST, REST, CS0G, REST, REST, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(LEFT_ARM_GL, pattern1, V015, V000, V000, V009, V000, V000, V000, V000, V008, V000, V002, V000, V002, V000, V000, V000, hasOutput);

        // ----------------------------------------------0001-------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_ARM_GL, pattern1, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_ARM_GL, pattern1, V006, V000, V000, V006, V006, V015, V000, V000, V008, V000, V015, V000, V015, V000, V000, V000, hasOutput);

        // Pattern 2: ----------------------------------------------------------
        // ----------------------------------------------0001------////--------0002-------////--------0003--------////--------0004--------////------
        setHitPattern(LEFT_ARM_GL, pattern2, D00G, REST, REST, E00G, REST, REST, D00G, REST, CS0G, REST, REST, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(LEFT_ARM_GL, pattern2, V015, V000, V000, V009, V000, V000, V000, V000, V008, V000, V002, V000, V002, V000, V000, V000, hasOutput);

        // ----------------------------------------------0001-------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_ARM_GL, pattern2, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, REST, hasOutput);
        setVelPattern(RIGHT_ARM_GL, pattern2, V006, V000, V000, V006, V006, V015, V000, V000, V008, V000, V015, V000, V015, V000, V000, V000, hasOutput);

        // Pattern 3: ----------------------------------------------------------
        // ----------------------------------------------0001------////--------0002-------////--------0003--------////--------0004--------////------
        setHitPattern(LEFT_ARM_GL, pattern3, G00G, REST, G00G, REST, G00G, REST, G00G, REST, G00G, REST, G00G, REST, G00G, REST, G00G, REST, hasOutput);
        setVelPattern(LEFT_ARM_GL, pattern3, V015, V000, V012, V000, V015, V000, V010, V000, V013, V000, V008, V000, V014, V000, V012, V000, hasOutput);

        // ----------------------------------------------0001-------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_ARM_GL, pattern3, D01G, REST, D01G, REST, D01G, REST, D01G, REST, D01G, REST, D01G, REST, D01G, REST, D01G, REST, hasOutput);
        setVelPattern(RIGHT_ARM_GL, pattern3, V014, V000, V008, V006, V014, V015, V012, V000, V014, V000, V009, V000, V015, V000, V008, V000, hasOutput);

        // Pattern 4: ----------------------------------------------------------
        // ----------------------------------------------0001------////--------0002-------////--------0003--------////--------0004--------////------
        setHitPattern(LEFT_ARM_GL, pattern4, A00G, REST, A00G, REST, A00G, REST, A00G, REST, A00G, REST, A00G, REST, A00G, REST, A00G, REST, hasOutput);
        setVelPattern(LEFT_ARM_GL, pattern4, V015, V000, V012, V000, V015, V000, V010, V000, V013, V000, V008, V000, V014, V000, V012, V000, hasOutput);

        // ----------------------------------------------0001-------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_ARM_GL, pattern4, E01G, REST, E01G, REST, E01G, REST, E01G, REST, E01G, REST, E01G, REST, E01G, REST, E01G, REST, hasOutput);
        setVelPattern(RIGHT_ARM_GL, pattern4, V014, V000, V008, V006, V014, V015, V012, V000, V014, V000, V009, V000, V015, V000, V008, V000, hasOutput);


        byte sevenNationPattSeq[nbMeasures_] = { 0, 1, 0, 1, 0, 1, 0, 2,
                                                3, 4, 0, 1, 0, 2 };
        setPatternSequence(sevenNationPattSeq);

        break;
      }
      // -------------------------------------------- BASIC_RYTHM -----------------------------------------------------
    case BASIC_RYTHM:
    default:
      {
        nbPatterns_ = 1;
        nbMeasures_ = 1;
        initializeBlankPatterns(nbPatterns_, nbMeasures_);

        byte patternId = 0;
        // Left Arm
        // ----------------------------------------------0001-------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(LEFT_ARM_GL, patternId, A00G, REST, REST, REST, E00G, REST, REST, REST, A00G, REST, REST, REST, E00G, REST, REST, REST, hasOutput);
        setVelPattern(LEFT_ARM_GL, patternId, V015, V000, V000, V000, V006, V000, V000, V000, V008, V000, V000, V000, V015, V000, V000, V000, hasOutput);

        // Right Arm
        // -----------------------------------------------0001-------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_ARM_GL, patternId, CS1G, REST, E01G, REST, CS1G, REST, E01G, REST, CS1G, REST, E01G, REST, CS1G, REST, E01G, REST, hasOutput);
        setVelPattern(RIGHT_ARM_GL, patternId, V009, V000, V012, V000, V006, V000, V008, V000, V008, V000, V012, V000, V006, V000, V009, V000, hasOutput);

        byte basicPattSeq[nbMeasures_] = { 0 };
        setPatternSequence(basicPattSeq);

        break;
      }
  }
}