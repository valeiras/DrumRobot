#include "glocken_song_gr.h"

GlockenSongGR::GlockenSongGR()
  : PercuSong<NB_LIMBS_GL, BITS_FOR_POS_GL>::PercuSong() {
  nbOfPositions_[LEFT_ARM_GL] = NB_POS_LA_GL;
  nbOfPositions_[RIGHT_ARM_GL] = NB_POS_RA_GL;
}

void GlockenSongGR::createPredefinedPatterns(Songs songName, bool hasOutput = false) {
  switch (songName) {
      // -------------------------------------------- SIMPLEST_RYTHM -----------------------------------------------------
    case SIMPLEST_RYTHM:
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

        byte simplestPattSeq[nbMeasures_] = { 0 };
        setPatternSequence(simplestPattSeq);

        break;
      }
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
  }
}