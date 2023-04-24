#include "glocken_song_ld.h"

GlockenSongLD::GlockenSongLD()
  : PercuSong<NB_HIT_JOINTS_GL, BITS_FOR_POS_GL>::PercuSong() {
  nbOfPositions_[LEFT_ARM_GL] = NB_POS_LA_GL;
  nbOfPositions_[RIGHT_ARM_GL] = NB_POS_RA_GL;
}

void GlockenSongLD::createPredefinedPatterns(byte songName, bool hasOutput = false) {
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
  }
}