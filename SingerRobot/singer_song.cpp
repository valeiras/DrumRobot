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
        setQuarterHit(SINGER_1, POS_SG, C03G, patternId1, 1, hasOutput);
        setQuarterHit(SINGER_1, POS_SG, G03G, patternId1, 2, hasOutput);
        setQuarterHit(SINGER_1, POS_SG, C03G, patternId1, 3, hasOutput);
        setQuarterHit(SINGER_1, POS_SG, OFFG, patternId1, 4, hasOutput);

        setQuarterHit(SINGER_1, POS_SG, C03G, patternId2, 1, hasOutput);
        setQuarterHit(SINGER_1, POS_SG, G03G, patternId2, 2, hasOutput);
        setQuarterHit(SINGER_1, POS_SG, C03G, patternId2, 3, hasOutput);
        setQuarterHit(SINGER_1, POS_SG, OFFG, patternId2, 4, hasOutput);

        setQuarterHit(SINGER_1, POS_SG, C03G, patternId3, 1, hasOutput);
        setQuarterHit(SINGER_1, POS_SG, G03G, patternId3, 2, hasOutput);
        setQuarterHit(SINGER_1, POS_SG, C03G, patternId3, 3, hasOutput);
        setQuarterHit(SINGER_1, POS_SG, OFFG, patternId3, 4, hasOutput);

        setQuarterHit(SINGER_1, POS_SG, G03G, patternId4, 1, hasOutput);
        setQuarterHit(SINGER_1, POS_SG, C03G, patternId4, 3, hasOutput);
        setQuarterHit(SINGER_1, POS_SG, OFFG, patternId4, 4, hasOutput);

        // Singer 2
        setQuarterHit(SINGER_2, POS_SG, E03G, patternId1, 1, hasOutput);
        setQuarterHit(SINGER_2, POS_SG, B03G, patternId1, 2, hasOutput);
        setQuarterHit(SINGER_2, POS_SG, E03G, patternId1, 3, hasOutput);
        setQuarterHit(SINGER_2, POS_SG, OFFG, patternId1, 4, hasOutput);

        setQuarterHit(SINGER_2, POS_SG, E03G, patternId2, 1, hasOutput);
        setQuarterHit(SINGER_2, POS_SG, B03G, patternId2, 2, hasOutput);
        setQuarterHit(SINGER_2, POS_SG, E03G, patternId2, 3, hasOutput);
        setQuarterHit(SINGER_2, POS_SG, OFFG, patternId2, 4, hasOutput);

        setQuarterHit(SINGER_2, POS_SG, E03G, patternId3, 1, hasOutput);
        setQuarterHit(SINGER_2, POS_SG, B03G, patternId3, 2, hasOutput);
        setQuarterHit(SINGER_2, POS_SG, E03G, patternId3, 3, hasOutput);
        setQuarterHit(SINGER_2, POS_SG, OFFG, patternId3, 4, hasOutput);

        setQuarterHit(SINGER_2, POS_SG, B03G, patternId4, 1, hasOutput);
        setQuarterHit(SINGER_2, POS_SG, E03G, patternId4, 3, hasOutput);
        setQuarterHit(SINGER_2, POS_SG, OFFG, patternId4, 4, hasOutput);

        // Singer 3
        setQuarterHit(SINGER_3, POS_SG, G03G, patternId1, 1, hasOutput);
        setQuarterHit(SINGER_3, POS_SG, D04G, patternId1, 2, hasOutput);
        setQuarterHit(SINGER_3, POS_SG, G03G, patternId1, 3, hasOutput);
        setQuarterHit(SINGER_3, POS_SG, OFFG, patternId1, 4, hasOutput);

        setQuarterHit(SINGER_3, POS_SG, G03G, patternId2, 1, hasOutput);
        setQuarterHit(SINGER_3, POS_SG, D04G, patternId2, 2, hasOutput);
        setQuarterHit(SINGER_3, POS_SG, G03G, patternId2, 3, hasOutput);
        setQuarterHit(SINGER_3, POS_SG, OFFG, patternId2, 4, hasOutput);

        setQuarterHit(SINGER_3, POS_SG, G03G, patternId3, 1, hasOutput);
        setQuarterHit(SINGER_3, POS_SG, D04G, patternId3, 2, hasOutput);
        setQuarterHit(SINGER_3, POS_SG, G03G, patternId3, 3, hasOutput);
        setQuarterHit(SINGER_3, POS_SG, OFFG, patternId3, 4, hasOutput);

        setQuarterHit(SINGER_3, POS_SG, D04G, patternId4, 1, hasOutput);
        setQuarterHit(SINGER_3, POS_SG, F04G, patternId4, 2, hasOutput);
        setQuarterHit(SINGER_3, POS_SG, G03G, patternId4, 3, hasOutput);
        setQuarterHit(SINGER_3, POS_SG, OFFG, patternId4, 4, hasOutput);

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
        setSemiquaverHit(SINGER_1, POS_SG, C03G, initialChord, 1, hasOutput);
        setSemiquaverHit(SINGER_1, POS_SG, OFFG, initialChord, 9, hasOutput);

        setSemiquaverHit(SINGER_2, POS_SG, E03G, initialChord, 4, hasOutput);
        setSemiquaverHit(SINGER_2, POS_SG, OFFG, initialChord, 9, hasOutput);

        setSemiquaverHit(SINGER_3, POS_SG, OFFG, initialChord, 1, hasOutput);
        setSemiquaverHit(SINGER_3, POS_SG, G03G, initialChord, 7, hasOutput);
        setSemiquaverHit(SINGER_3, POS_SG, OFFG, initialChord, 9, hasOutput);

        // Pattern 1: C
        setSemiquaverHit(SINGER_1, POS_SG, C03G, patternC, 1, hasOutput);
        setSemiquaverHit(SINGER_1, POS_SG, OFFG, patternC, 4, hasOutput);
        setSemiquaverHit(SINGER_1, POS_SG, C03G, patternC, 9, hasOutput);
        setSemiquaverHit(SINGER_1, POS_SG, OFFG, patternC, 12, hasOutput);

        setSemiquaverHit(SINGER_2, POS_SG, E03G, patternC, 4, hasOutput);
        setSemiquaverHit(SINGER_2, POS_SG, OFFG, patternC, 7, hasOutput);
        setSemiquaverHit(SINGER_2, POS_SG, E03G, patternC, 12, hasOutput);
        setSemiquaverHit(SINGER_2, POS_SG, OFFG, patternC, 15, hasOutput);

        setSemiquaverHit(SINGER_3, POS_SG, G03G, patternC, 7, hasOutput);
        setSemiquaverHit(SINGER_3, POS_SG, OFFG, patternC, 9, hasOutput);
        setSemiquaverHit(SINGER_3, POS_SG, G03G, patternC, 15, hasOutput);
        setSemiquaverHit(SINGER_3, POS_SG, OFFG, patternC, 1, hasOutput);


        // Pattern 2: F
        setSemiquaverHit(SINGER_1, POS_SG, F03G, patternF, 1, hasOutput);
        setSemiquaverHit(SINGER_1, POS_SG, OFFG, patternF, 4, hasOutput);
        setSemiquaverHit(SINGER_1, POS_SG, F03G, patternF, 9, hasOutput);
        setSemiquaverHit(SINGER_1, POS_SG, OFFG, patternF, 12, hasOutput);

        setSemiquaverHit(SINGER_2, POS_SG, A03G, patternF, 4, hasOutput);
        setSemiquaverHit(SINGER_2, POS_SG, OFFG, patternF, 7, hasOutput);
        setSemiquaverHit(SINGER_2, POS_SG, A03G, patternF, 12, hasOutput);
        setSemiquaverHit(SINGER_2, POS_SG, OFFG, patternF, 15, hasOutput);

        setSemiquaverHit(SINGER_3, POS_SG, C04G, patternF, 7, hasOutput);
        setSemiquaverHit(SINGER_3, POS_SG, OFFG, patternF, 9, hasOutput);
        setSemiquaverHit(SINGER_3, POS_SG, C04G, patternF, 15, hasOutput);
        setSemiquaverHit(SINGER_3, POS_SG, OFFG, patternF, 1, hasOutput);

        // Pattern 3: G
        setSemiquaverHit(SINGER_1, POS_SG, G03G, patternG, 1, hasOutput);
        setSemiquaverHit(SINGER_1, POS_SG, OFFG, patternG, 4, hasOutput);
        setSemiquaverHit(SINGER_1, POS_SG, F03G, patternG, 9, hasOutput);
        setSemiquaverHit(SINGER_1, POS_SG, OFFG, patternG, 12, hasOutput);

        setSemiquaverHit(SINGER_2, POS_SG, B03G, patternG, 4, hasOutput);
        setSemiquaverHit(SINGER_2, POS_SG, OFFG, patternG, 7, hasOutput);
        setSemiquaverHit(SINGER_2, POS_SG, A03G, patternG, 12, hasOutput);
        setSemiquaverHit(SINGER_2, POS_SG, OFFG, patternG, 15, hasOutput);

        setSemiquaverHit(SINGER_3, POS_SG, D04G, patternG, 7, hasOutput);
        setSemiquaverHit(SINGER_3, POS_SG, OFFG, patternG, 9, hasOutput);
        setSemiquaverHit(SINGER_3, POS_SG, C04G, patternG, 15, hasOutput);
        setSemiquaverHit(SINGER_3, POS_SG, OFFG, patternG, 1, hasOutput);

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

        setQuarterHit(SINGER_1, POS_SG, C03G, patternId, 1, hasOutput);
        setQuarterHit(SINGER_1, POS_SG, OFFG, patternId, 2, hasOutput);

        setQuarterHit(SINGER_2, POS_SG, C03G, patternId, 3, hasOutput);
        setQuarterHit(SINGER_2, POS_SG, OFFG, patternId, 4, hasOutput);

        setQuarterHit(SINGER_3, POS_SG, C03G, patternId, 3, hasOutput);
        setQuarterHit(SINGER_3, POS_SG, OFFG, patternId, 4, hasOutput);

        byte simplestPattSeq[nbMeasures_] = { 0 };
        setPatternSequence(simplestPattSeq);

        break;
      }
  }
}
