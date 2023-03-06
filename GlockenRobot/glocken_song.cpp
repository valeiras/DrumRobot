#include "glocken_song.h"

GlockenSong::GlockenSong()
  : PercuSong<NB_LIMBS_GL, BITS_FOR_POS_GL>::PercuSong() {
  nbOfPositions_[LEFT_ARM_GL] = NB_POS_LA_GL;
  nbOfPositions_[RIGHT_ARM_GL] = NB_POS_RA_GL;
}

void GlockenSong::createPredefinedPatterns(byte songName, bool printOutput = false) {
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
        setHitPattern(LEFT_ARM_GL, patternId0, C00G, REST, REST, REST, D00G, REST, REST, REST, E00G, REST, REST, REST, C00G, REST, REST, REST, printOutput);
        setVelPattern(LEFT_ARM_GL, patternId0, V015, V000, V000, V000, V006, V000, V000, V000, V008, V000, V000, V000, V015, V000, V000, V000, printOutput);

        setHitPattern(LEFT_ARM_GL, patternId1, E00G, REST, REST, REST, F00G, REST, REST, REST, G00G, REST, REST, REST, REST, REST, REST, REST, printOutput);
        setVelPattern(LEFT_ARM_GL, patternId1, V012, V000, V000, V000, V009, V000, V000, V000, V008, V000, V015, V000, V000, V000, V000, V000, printOutput);

        setHitPattern(LEFT_ARM_GL, patternId2, G00G, REST, A00G, REST, G00G, REST, F00G, REST, E00G, REST, REST, REST, C00G, REST, REST, REST, printOutput);
        setVelPattern(LEFT_ARM_GL, patternId2, V012, V000, V006, V000, V009, V000, V008, V000, V008, V000, V000, V000, V010, V000, V000, V000, printOutput);

        setHitPattern(LEFT_ARM_GL, patternId3, D00G, REST, REST, REST, G00G, REST, REST, REST, C00G, REST, REST, REST, REST, REST, REST, REST, printOutput);
        setVelPattern(LEFT_ARM_GL, patternId3, V009, V000, V000, V000, V006, V000, V000, V000, V015, V000, V000, V000, V000, V000, V000, V000, printOutput);

        // Right Arm
        // -----------------------------------------------0001-------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(RIGHT_ARM_GL, patternId0, E01G, REST, REST, REST, D01G, REST, REST, REST, E01G, REST, REST, REST, C01G, REST, REST, REST, printOutput);
        setVelPattern(RIGHT_ARM_GL, patternId0, V009, V000, V000, V000, V006, V000, V000, V000, V008, V000, V000, V000, V006, V000, V000, V000, printOutput);

        setHitPattern(RIGHT_ARM_GL, patternId1, E01G, REST, REST, REST, C01G, REST, REST, REST, D01G, REST, C01G, REST, B00G, REST, C01G, REST, printOutput);
        setVelPattern(RIGHT_ARM_GL, patternId1, V012, V000, V000, V000, V009, V000, V000, V000, V008, V000, V015, V000, V015, V000, V012, V000, printOutput);

        setHitPattern(RIGHT_ARM_GL, patternId2, D01G, REST, E01G, REST, D01G, REST, F01G, REST, E01G, REST, REST, REST, C01G, REST, REST, REST, printOutput);
        setVelPattern(RIGHT_ARM_GL, patternId2, V012, V000, V006, V000, V009, V000, V008, V000, V008, V000, V000, V000, V010, V000, V000, V000, printOutput);

        setHitPattern(RIGHT_ARM_GL, patternId3, D01G, REST, REST, REST, D01G, REST, REST, REST, C01G, REST, REST, REST, REST, REST, REST, REST, printOutput);
        setVelPattern(RIGHT_ARM_GL, patternId3, V009, V000, V000, V000, V006, V000, V000, V000, V008, V000, V000, V000, V000, V000, V000, V000, printOutput);

        byte frereJacquesPattSeq[nbMeasures_] = { 0, 0, 1, 1, 2, 2, 3, 3 };
        setPatternSequence(frereJacquesPattSeq);

        break;
      }
  }
}