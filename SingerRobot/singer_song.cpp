#include "singer_song.h"

SingerSong::SingerSong()
  : PercuSong<NB_LIMBS_SG, BITS_FOR_POS_SG>::PercuSong() {
  nbOfPositions_[SINGER_1] = 1;
  nbOfPositions_[SINGER_2] = 1;
  nbOfPositions_[SINGER_3] = 1;
}

void SingerSong::createPredefinedPatterns(byte rythmName, bool hasOutput = false) {
  switch (rythmName) {
    // -------------------------------------------- SIMPLEST RYTHM -----------------------------------------------------
    case C_SCALE:
    default:
      {
        nbPatterns_ = 1;
        nbMeasures_ = 1;
        initializeBlankPatterns(nbPatterns_, nbMeasures_);

        byte patternId = 0;

        setQuarterHit(SINGER_1, POS_SG, C03_SG, patternId, 1, hasOutput);
        setQuarterHit(SINGER_1, POS_SG, OFF_SG, patternId, 4, hasOutput);

        setQuarterHit(SINGER_2, POS_SG, C03_SG, patternId, 2, hasOutput);
        setQuarterHit(SINGER_2, POS_SG, OFF_SG, patternId, 4, hasOutput);

        setSemiquaverHit(SINGER_3, POS_SG, E03_SG, patternId, 9, hasOutput);
        setSemiquaverHit(SINGER_3, POS_SG, OFF_SG, patternId, 14, hasOutput);

        byte simplestPattSeq[nbMeasures_] = { 0 };
        setPatternSequence(simplestPattSeq);

        break;
      }
  }
}
