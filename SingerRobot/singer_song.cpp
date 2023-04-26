#include "singer_song.h"

SingerSong::SingerSong()
  : PercuSong<NB_LIMBS_SG, BITS_FOR_POS_SG>::PercuSong() {
  nbOfPositions_[SINGER_1] = 1;
  nbOfPositions_[SINGER_2] = 1;
  nbOfPositions_[SINGER_3] = 1;
}

void SingerSong::createPredefinedPatterns(Songs songName, bool hasOutput = false) {
  switch (songName) {
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

        // Singer 1
        setQuarterHit(SINGER_1, POS_SG, C03S, patternId1, 1, hasOutput);
        setQuarterHit(SINGER_1, POS_SG, G03S, patternId1, 2, hasOutput);
        setQuarterHit(SINGER_1, POS_SG, C03S, patternId1, 3, hasOutput);
        setQuarterHit(SINGER_1, POS_SG, OFFS, patternId1, 4, hasOutput);

        setQuarterHit(SINGER_1, POS_SG, C03S, patternId2, 1, hasOutput);
        setQuarterHit(SINGER_1, POS_SG, G03S, patternId2, 2, hasOutput);
        setQuarterHit(SINGER_1, POS_SG, C03S, patternId2, 3, hasOutput);
        setQuarterHit(SINGER_1, POS_SG, OFFS, patternId2, 4, hasOutput);

        setQuarterHit(SINGER_1, POS_SG, C03S, patternId3, 1, hasOutput);
        setQuarterHit(SINGER_1, POS_SG, G03S, patternId3, 2, hasOutput);
        setQuarterHit(SINGER_1, POS_SG, C03S, patternId3, 3, hasOutput);
        setQuarterHit(SINGER_1, POS_SG, OFFS, patternId3, 4, hasOutput);

        setQuarterHit(SINGER_1, POS_SG, G03S, patternId4, 1, hasOutput);
        setQuarterHit(SINGER_1, POS_SG, C03S, patternId4, 3, hasOutput);
        setQuarterHit(SINGER_1, POS_SG, OFFS, patternId4, 4, hasOutput);

        // Singer 2
        setQuarterHit(SINGER_2, POS_SG, E03S, patternId1, 1, hasOutput);
        setQuarterHit(SINGER_2, POS_SG, B03S, patternId1, 2, hasOutput);
        setQuarterHit(SINGER_2, POS_SG, E03S, patternId1, 3, hasOutput);
        setQuarterHit(SINGER_2, POS_SG, OFFS, patternId1, 4, hasOutput);

        setQuarterHit(SINGER_2, POS_SG, E03S, patternId2, 1, hasOutput);
        setQuarterHit(SINGER_2, POS_SG, B03S, patternId2, 2, hasOutput);
        setQuarterHit(SINGER_2, POS_SG, E03S, patternId2, 3, hasOutput);
        setQuarterHit(SINGER_2, POS_SG, OFFS, patternId2, 4, hasOutput);

        setQuarterHit(SINGER_2, POS_SG, E03S, patternId3, 1, hasOutput);
        setQuarterHit(SINGER_2, POS_SG, B03S, patternId3, 2, hasOutput);
        setQuarterHit(SINGER_2, POS_SG, E03S, patternId3, 3, hasOutput);
        setQuarterHit(SINGER_2, POS_SG, OFFS, patternId3, 4, hasOutput);

        setQuarterHit(SINGER_2, POS_SG, B03S, patternId4, 1, hasOutput);
        setQuarterHit(SINGER_2, POS_SG, E03S, patternId4, 3, hasOutput);
        setQuarterHit(SINGER_2, POS_SG, OFFS, patternId4, 4, hasOutput);

        // Singer 3
        setQuarterHit(SINGER_3, POS_SG, G03S, patternId1, 1, hasOutput);
        setQuarterHit(SINGER_3, POS_SG, D04S, patternId1, 2, hasOutput);
        setQuarterHit(SINGER_3, POS_SG, G03S, patternId1, 3, hasOutput);
        setQuarterHit(SINGER_3, POS_SG, OFFS, patternId1, 4, hasOutput);

        setQuarterHit(SINGER_3, POS_SG, G03S, patternId2, 1, hasOutput);
        setQuarterHit(SINGER_3, POS_SG, D04S, patternId2, 2, hasOutput);
        setQuarterHit(SINGER_3, POS_SG, G03S, patternId2, 3, hasOutput);
        setQuarterHit(SINGER_3, POS_SG, OFFS, patternId2, 4, hasOutput);

        setQuarterHit(SINGER_3, POS_SG, G03S, patternId3, 1, hasOutput);
        setQuarterHit(SINGER_3, POS_SG, D04S, patternId3, 2, hasOutput);
        setQuarterHit(SINGER_3, POS_SG, G03S, patternId3, 3, hasOutput);
        setQuarterHit(SINGER_3, POS_SG, OFFS, patternId3, 4, hasOutput);

        setQuarterHit(SINGER_3, POS_SG, D04S, patternId4, 1, hasOutput);
        setQuarterHit(SINGER_3, POS_SG, F04S, patternId4, 2, hasOutput);
        setQuarterHit(SINGER_3, POS_SG, G03S, patternId4, 3, hasOutput);
        setQuarterHit(SINGER_3, POS_SG, OFFS, patternId4, 4, hasOutput);

        byte frereJacquesPattSeq[nbMeasures_] = { 0, 1, 1, 2, 2, 3, 3, 4, 4 };
        setPatternSequence(frereJacquesPattSeq);

        break;
      }
    case HOUND_DOG:
      {
        nbPatterns_ = 4;
        nbMeasures_ = 6;
        initializeBlankPatterns(nbPatterns_, nbMeasures_);

        byte initialChord = 0;
        byte patternC = 1;
        byte patternF = 2;
        byte patternG = 3;

        // Pattern 0
        setSemiquaverHit(SINGER_1, POS_SG, C03S, initialChord, 1, hasOutput);
        setSemiquaverHit(SINGER_1, POS_SG, OFFS, initialChord, 9, hasOutput);

        setSemiquaverHit(SINGER_2, POS_SG, E03S, initialChord, 4, hasOutput);
        setSemiquaverHit(SINGER_2, POS_SG, OFFS, initialChord, 9, hasOutput);

        setSemiquaverHit(SINGER_3, POS_SG, OFFS, initialChord, 1, hasOutput);
        setSemiquaverHit(SINGER_3, POS_SG, G03S, initialChord, 7, hasOutput);
        setSemiquaverHit(SINGER_3, POS_SG, OFFS, initialChord, 9, hasOutput);

        // Pattern 1: C
        setSemiquaverHit(SINGER_1, POS_SG, C03S, patternC, 1, hasOutput);
        setSemiquaverHit(SINGER_1, POS_SG, OFFS, patternC, 4, hasOutput);
        setSemiquaverHit(SINGER_1, POS_SG, C03S, patternC, 9, hasOutput);
        setSemiquaverHit(SINGER_1, POS_SG, OFFS, patternC, 12, hasOutput);

        setSemiquaverHit(SINGER_2, POS_SG, E03S, patternC, 4, hasOutput);
        setSemiquaverHit(SINGER_2, POS_SG, OFFS, patternC, 7, hasOutput);
        setSemiquaverHit(SINGER_2, POS_SG, E03S, patternC, 12, hasOutput);
        setSemiquaverHit(SINGER_2, POS_SG, OFFS, patternC, 15, hasOutput);

        setSemiquaverHit(SINGER_3, POS_SG, G03S, patternC, 7, hasOutput);
        setSemiquaverHit(SINGER_3, POS_SG, OFFS, patternC, 9, hasOutput);
        setSemiquaverHit(SINGER_3, POS_SG, G03S, patternC, 15, hasOutput);
        setSemiquaverHit(SINGER_3, POS_SG, OFFS, patternC, 1, hasOutput);


        // Pattern 2: F
        setSemiquaverHit(SINGER_1, POS_SG, F03S, patternF, 1, hasOutput);
        setSemiquaverHit(SINGER_1, POS_SG, OFFS, patternF, 4, hasOutput);
        setSemiquaverHit(SINGER_1, POS_SG, F03S, patternF, 9, hasOutput);
        setSemiquaverHit(SINGER_1, POS_SG, OFFS, patternF, 12, hasOutput);

        setSemiquaverHit(SINGER_2, POS_SG, A03S, patternF, 4, hasOutput);
        setSemiquaverHit(SINGER_2, POS_SG, OFFS, patternF, 7, hasOutput);
        setSemiquaverHit(SINGER_2, POS_SG, A03S, patternF, 12, hasOutput);
        setSemiquaverHit(SINGER_2, POS_SG, OFFS, patternF, 15, hasOutput);

        setSemiquaverHit(SINGER_3, POS_SG, C04S, patternF, 7, hasOutput);
        setSemiquaverHit(SINGER_3, POS_SG, OFFS, patternF, 9, hasOutput);
        setSemiquaverHit(SINGER_3, POS_SG, C04S, patternF, 15, hasOutput);
        setSemiquaverHit(SINGER_3, POS_SG, OFFS, patternF, 1, hasOutput);

        // Pattern 3: G
        setSemiquaverHit(SINGER_1, POS_SG, G03S, patternG, 1, hasOutput);
        setSemiquaverHit(SINGER_1, POS_SG, OFFS, patternG, 4, hasOutput);
        setSemiquaverHit(SINGER_1, POS_SG, F03S, patternG, 9, hasOutput);
        setSemiquaverHit(SINGER_1, POS_SG, OFFS, patternG, 12, hasOutput);

        setSemiquaverHit(SINGER_2, POS_SG, B03S, patternG, 4, hasOutput);
        setSemiquaverHit(SINGER_2, POS_SG, OFFS, patternG, 7, hasOutput);
        setSemiquaverHit(SINGER_2, POS_SG, A03S, patternG, 12, hasOutput);
        setSemiquaverHit(SINGER_2, POS_SG, OFFS, patternG, 15, hasOutput);

        setSemiquaverHit(SINGER_3, POS_SG, D04S, patternG, 7, hasOutput);
        setSemiquaverHit(SINGER_3, POS_SG, OFFS, patternG, 9, hasOutput);
        setSemiquaverHit(SINGER_3, POS_SG, C04S, patternG, 15, hasOutput);
        setSemiquaverHit(SINGER_3, POS_SG, OFFS, patternG, 1, hasOutput);

        byte houndDogPattSeq[nbMeasures_] = { initialChord, patternC, patternC, patternF,
                                              patternC, patternG };
        setPatternSequence(houndDogPattSeq);

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

        setQuarterHit(SINGER_1, POS_SG, C03S, patternId, 1, hasOutput);
        setQuarterHit(SINGER_1, POS_SG, OFFS, patternId, 2, hasOutput);

        setQuarterHit(SINGER_2, POS_SG, C03S, patternId, 3, hasOutput);
        setQuarterHit(SINGER_2, POS_SG, OFFS, patternId, 4, hasOutput);

        setQuarterHit(SINGER_3, POS_SG, C03S, patternId, 3, hasOutput);
        setQuarterHit(SINGER_3, POS_SG, OFFS, patternId, 4, hasOutput);

        byte simplestPattSeq[nbMeasures_] = { 0 };
        setPatternSequence(simplestPattSeq);

        break;
      }
  }
}
