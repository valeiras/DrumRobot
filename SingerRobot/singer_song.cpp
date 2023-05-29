#include "singer_song.h"

SingerSong::SingerSong()
  : PercuSong<NB_SHEETS, BITS_FOR_POS_SG>::PercuSong() {
  nbOfPositions_[AUTOMATIC_SINGER] = 1;
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
        setQuarterHit(AUTOMATIC_SINGER, POS_SG, C03S, patternId1, 1, hasOutput);
        setQuarterHit(AUTOMATIC_SINGER, POS_SG, G03S, patternId1, 2, hasOutput);
        setQuarterHit(AUTOMATIC_SINGER, POS_SG, C03S, patternId1, 3, hasOutput);
        setQuarterHit(AUTOMATIC_SINGER, POS_SG, OFFS, patternId1, 4, hasOutput);

        setQuarterHit(AUTOMATIC_SINGER, POS_SG, C03S, patternId2, 1, hasOutput);
        setQuarterHit(AUTOMATIC_SINGER, POS_SG, G03S, patternId2, 2, hasOutput);
        setQuarterHit(AUTOMATIC_SINGER, POS_SG, C03S, patternId2, 3, hasOutput);
        setQuarterHit(AUTOMATIC_SINGER, POS_SG, OFFS, patternId2, 4, hasOutput);

        setQuarterHit(AUTOMATIC_SINGER, POS_SG, C03S, patternId3, 1, hasOutput);
        setQuarterHit(AUTOMATIC_SINGER, POS_SG, G03S, patternId3, 2, hasOutput);
        setQuarterHit(AUTOMATIC_SINGER, POS_SG, C03S, patternId3, 3, hasOutput);
        setQuarterHit(AUTOMATIC_SINGER, POS_SG, OFFS, patternId3, 4, hasOutput);

        setQuarterHit(AUTOMATIC_SINGER, POS_SG, G03S, patternId4, 1, hasOutput);
        setQuarterHit(AUTOMATIC_SINGER, POS_SG, C03S, patternId4, 3, hasOutput);
        setQuarterHit(AUTOMATIC_SINGER, POS_SG, OFFS, patternId4, 4, hasOutput);

        // Singer 2
        setQuarterHit(AUTOMATIC_SINGER, POS_SG, E03S, patternId1, 1, hasOutput);
        setQuarterHit(AUTOMATIC_SINGER, POS_SG, B03S, patternId1, 2, hasOutput);
        setQuarterHit(AUTOMATIC_SINGER, POS_SG, E03S, patternId1, 3, hasOutput);
        setQuarterHit(AUTOMATIC_SINGER, POS_SG, OFFS, patternId1, 4, hasOutput);

        setQuarterHit(AUTOMATIC_SINGER, POS_SG, E03S, patternId2, 1, hasOutput);
        setQuarterHit(AUTOMATIC_SINGER, POS_SG, B03S, patternId2, 2, hasOutput);
        setQuarterHit(AUTOMATIC_SINGER, POS_SG, E03S, patternId2, 3, hasOutput);
        setQuarterHit(AUTOMATIC_SINGER, POS_SG, OFFS, patternId2, 4, hasOutput);

        setQuarterHit(AUTOMATIC_SINGER, POS_SG, E03S, patternId3, 1, hasOutput);
        setQuarterHit(AUTOMATIC_SINGER, POS_SG, B03S, patternId3, 2, hasOutput);
        setQuarterHit(AUTOMATIC_SINGER, POS_SG, E03S, patternId3, 3, hasOutput);
        setQuarterHit(AUTOMATIC_SINGER, POS_SG, OFFS, patternId3, 4, hasOutput);

        setQuarterHit(AUTOMATIC_SINGER, POS_SG, B03S, patternId4, 1, hasOutput);
        setQuarterHit(AUTOMATIC_SINGER, POS_SG, E03S, patternId4, 3, hasOutput);
        setQuarterHit(AUTOMATIC_SINGER, POS_SG, OFFS, patternId4, 4, hasOutput);

        // Singer 3
        setQuarterHit(AUTOMATIC_SINGER, POS_SG, G03S, patternId1, 1, hasOutput);
        setQuarterHit(AUTOMATIC_SINGER, POS_SG, D04S, patternId1, 2, hasOutput);
        setQuarterHit(AUTOMATIC_SINGER, POS_SG, G03S, patternId1, 3, hasOutput);
        setQuarterHit(AUTOMATIC_SINGER, POS_SG, OFFS, patternId1, 4, hasOutput);

        setQuarterHit(AUTOMATIC_SINGER, POS_SG, G03S, patternId2, 1, hasOutput);
        setQuarterHit(AUTOMATIC_SINGER, POS_SG, D04S, patternId2, 2, hasOutput);
        setQuarterHit(AUTOMATIC_SINGER, POS_SG, G03S, patternId2, 3, hasOutput);
        setQuarterHit(AUTOMATIC_SINGER, POS_SG, OFFS, patternId2, 4, hasOutput);

        setQuarterHit(AUTOMATIC_SINGER, POS_SG, G03S, patternId3, 1, hasOutput);
        setQuarterHit(AUTOMATIC_SINGER, POS_SG, D04S, patternId3, 2, hasOutput);
        setQuarterHit(AUTOMATIC_SINGER, POS_SG, G03S, patternId3, 3, hasOutput);
        setQuarterHit(AUTOMATIC_SINGER, POS_SG, OFFS, patternId3, 4, hasOutput);

        setQuarterHit(AUTOMATIC_SINGER, POS_SG, D04S, patternId4, 1, hasOutput);
        setQuarterHit(AUTOMATIC_SINGER, POS_SG, F04S, patternId4, 2, hasOutput);
        setQuarterHit(AUTOMATIC_SINGER, POS_SG, G03S, patternId4, 3, hasOutput);
        setQuarterHit(AUTOMATIC_SINGER, POS_SG, OFFS, patternId4, 4, hasOutput);

        byte frereJacquesPattSeq[nbMeasures_] = { 0, 1, 1, 2, 2, 3, 3, 4, 4 };
        setPatternSequence(frereJacquesPattSeq);

        break;
      }
    case HOUND_DOG:
      {
        nbPatterns_ = 5;
        nbMeasures_ = 21;
        initializeBlankPatterns(nbPatterns_, nbMeasures_);

        byte empty = 0;
        byte patternC = 1;
        byte patternF = 2;
        byte patternG = 3;
        byte endLoop = 4;

        // Pattern 1: C
        setSemiquaverHit(AUTOMATIC_SINGER, POS_SG, C03S, patternC, 1, hasOutput);
        setSemiquaverHit(AUTOMATIC_SINGER, POS_SG, C03S, patternC, 9, hasOutput);

        setSemiquaverHit(AUTOMATIC_SINGER, POS_SG, E03S, patternC, 4, hasOutput);
        setSemiquaverHit(AUTOMATIC_SINGER, POS_SG, E03S, patternC, 12, hasOutput);

        setSemiquaverHit(AUTOMATIC_SINGER, POS_SG, G03S, patternC, 7, hasOutput);
        setSemiquaverHit(AUTOMATIC_SINGER, POS_SG, G03S, patternC, 15, hasOutput);


        // Pattern 2: F
        setSemiquaverHit(AUTOMATIC_SINGER, POS_SG, F03S, patternF, 1, hasOutput);
        setSemiquaverHit(AUTOMATIC_SINGER, POS_SG, F03S, patternF, 9, hasOutput);

        setSemiquaverHit(AUTOMATIC_SINGER, POS_SG, A03S, patternF, 4, hasOutput);
        setSemiquaverHit(AUTOMATIC_SINGER, POS_SG, A03S, patternF, 12, hasOutput);

        setSemiquaverHit(AUTOMATIC_SINGER, POS_SG, C04S, patternF, 7, hasOutput);
        setSemiquaverHit(AUTOMATIC_SINGER, POS_SG, C04S, patternF, 15, hasOutput);

        // Pattern 3: G
        setSemiquaverHit(AUTOMATIC_SINGER, POS_SG, G03S, patternG, 1, hasOutput);
        setSemiquaverHit(AUTOMATIC_SINGER, POS_SG, F03S, patternG, 9, hasOutput);

        setSemiquaverHit(AUTOMATIC_SINGER, POS_SG, B03S, patternG, 4, hasOutput);
        setSemiquaverHit(AUTOMATIC_SINGER, POS_SG, A03S, patternG, 12, hasOutput);

        setSemiquaverHit(AUTOMATIC_SINGER, POS_SG, D04S, patternG, 7, hasOutput);
        setSemiquaverHit(AUTOMATIC_SINGER, POS_SG, C04S, patternG, 15, hasOutput);

        // Pattern 4: endloop
        setSemiquaverHit(AUTOMATIC_SINGER, POS_SG, C03S, endLoop, 1, hasOutput);
        setSemiquaverHit(AUTOMATIC_SINGER, POS_SG, C03S, endLoop, 9, hasOutput);
        setSemiquaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, endLoop, 12, hasOutput);

        setSemiquaverHit(AUTOMATIC_SINGER, POS_SG, E03S, endLoop, 4, hasOutput);

        setSemiquaverHit(AUTOMATIC_SINGER, POS_SG, G03S, endLoop, 7, hasOutput);

        byte houndDogPattSeq[nbMeasures_] = { empty, empty, empty, 
                                              patternC, patternC, patternF, patternC, patternG, endLoop,
                                              patternC, patternC, patternF, patternC, patternG, endLoop,
                                              patternC, patternC, patternF, patternC, patternG, endLoop };
        setPatternSequence(houndDogPattSeq);

        break;
      }
      // -------------------------------------------- MR_SANDMAN -----------------------------------------------------
    case MR_SANDMAN_LONG:
      {
        nbPatterns_ = 16;
        nbMeasures_ = 23;
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
        byte pattern9 = 9;
        byte pattern10 = 10;
        byte pattern11 = 11;
        byte pattern12 = 12;
        byte pattern13 = 13;
        byte pattern14 = 14;
        byte empty = 15;

        // --------------------------------------------------- Pattern 0:
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, DS3S, pattern0, 1, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern0, 2, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, G03S, pattern0, 2, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern0, 3, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, AS3S, pattern0, 3, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern0, 4, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, D04S, pattern0, 4, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern0, 5, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, C04S, pattern0, 5, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern0, 6, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, AS3S, pattern0, 6, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern0, 7, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, G03S, pattern0, 7, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern0, 8, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, DS3S, pattern0, 8, hasOutput);
        setSemiquaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern0, 16, hasOutput);


        // ------------------------------------------------- Pattern 1:
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, F03S, pattern1, 1, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern1, 2, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, GS3S, pattern1, 2, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern1, 3, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, C04S, pattern1, 3, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern1, 4, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, DS4S, pattern1, 4, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern1, 5, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, D04S, pattern1, 5, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern1, 6, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, DS2S, pattern1, 7, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern1, 8, hasOutput);



        // ------------------------------------------------ Pattern 2:
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, F03S, pattern2, 1, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern2, 2, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, GS3S, pattern2, 2, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern2, 3, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, C04S, pattern2, 3, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern2, 4, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, DS4S, pattern2, 4, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern2, 5, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, D04S, pattern2, 5, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern2, 6, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, G03S, pattern2, 7, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern2, 8, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, AS3S, pattern2, 8, hasOutput);
        setSemiquaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern2, 16, hasOutput);


        // ----------------------------------------------- Pattern 3:
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, D04S, pattern3, 1, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern3, 2, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, C04S, pattern3, 2, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern3, 3, hasOutput);


        // --------------------------------------------------- Pattern 4:
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, D04S, pattern4, 1, hasOutput);
        setSemiquaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern4, 2, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, D04S, pattern4, 2, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern4, 3, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, C04S, pattern4, 3, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern4, 4, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, D04S, pattern4, 4, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern4, 5, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, D02S, pattern4, 6, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern4, 7, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, E02S, pattern4, 7, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern4, 8, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, FS2S, pattern4, 8, hasOutput);
        setSemiquaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern4, 16, hasOutput);


        // --------------------------------------------------- Pattern 5:
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, G02S, pattern5, 1, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern5, 2, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, DS4S, pattern5, 2, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern5, 3, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, DS4S, pattern5, 3, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern5, 4, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, D04S, pattern5, 4, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern5, 5, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, DS4S, pattern5, 5, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern5, 6, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, DS4S, pattern5, 6, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern5, 7, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, D04S, pattern5, 8, hasOutput);
        setSemiquaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern5, 16, hasOutput);


        // --------------------------------------------------- Pattern 6:
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, GS3S, pattern6, 1, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern6, 2, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, GS3S, pattern6, 2, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern6, 3, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, G03S, pattern6, 3, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern6, 4, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, GS3S, pattern6, 4, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern6, 5, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, C02S, pattern6, 6, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern6, 7, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, D02S, pattern6, 7, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern6, 8, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, E02S, pattern6, 8, hasOutput);
        setSemiquaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern6, 16, hasOutput);


        // --------------------------------------------------- Pattern 7:
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, F02S, pattern7, 1, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern7, 2, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, D04S, pattern7, 2, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern7, 3, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, D04S, pattern7, 3, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern7, 4, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, C04S, pattern7, 4, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern7, 5, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, D04S, pattern7, 5, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern7, 6, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, C04S, pattern7, 8, hasOutput);
        setSemiquaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern7, 16, hasOutput);


        // --------------------------------------------------- Pattern 8:
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, G03S, pattern8, 1, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern8, 2, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, G03S, pattern8, 2, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern8, 3, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, F03S, pattern8, 3, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern8, 4, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, G03S, pattern8, 4, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern8, 5, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, AS3S, pattern8, 6, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern8, 7, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, C02S, pattern8, 7, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern8, 8, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, D02S, pattern8, 8, hasOutput);
        setSemiquaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern8, 16, hasOutput);

        // --------------------------------------------------- Pattern 9:
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, DS2S, pattern9, 1, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern9, 2, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, F04S, pattern9, 2, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern9, 3, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, F04S, pattern9, 3, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern9, 4, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, DS4S, pattern9, 4, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern9, 5, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, F04S, pattern9, 5, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern9, 6, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, DS4S, pattern9, 6, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern9, 7, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, F04S, pattern9, 7, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern9, 8, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, DS4S, pattern9, 8, hasOutput);
        setSemiquaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern9, 16, hasOutput);

        // --------------------------------------------------- Pattern 10:
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, FS4S, pattern10, 1, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern10, 2, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, FS4S, pattern10, 3, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern10, 4, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, F04S, pattern10, 5, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern10, 6, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, DS4S, pattern10, 6, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern10, 7, hasOutput);

        // --------------------------------------------------- Pattern 11:
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, C04S, pattern11, 1, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern11, 2, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, DS4S, pattern11, 3, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern11, 4, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, DS4S, pattern11, 4, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern11, 5, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, F04S, pattern11, 6, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern11, 7, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, DS4S, pattern11, 7, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern11, 8, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, F04S, pattern11, 8, hasOutput);
        setSemiquaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern11, 16, hasOutput);


        // --------------------------------------------------- Pattern 12:
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, G04S, pattern12, 1, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern12, 3, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, DS4S, pattern12, 7, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern12, 8, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, F04S, pattern12, 8, hasOutput);
        setSemiquaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern12, 16, hasOutput);

        // --------------------------------------------------- Pattern 13:
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, G04S, pattern13, 1, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern13, 2, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, G04S, pattern13, 3, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern13, 4, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, G04S, pattern13, 5, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern13, 6, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, DS4S, pattern13, 6, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern13, 7, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, G04S, pattern13, 7, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern13, 8, hasOutput);

        // --------------------------------------------------- Pattern 14:
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, DS4S, pattern14, 1, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern14, 5, hasOutput);

        byte mrSandmanPattSeq[nbMeasures_] = { empty, 0, 1, 0, 2, 3, 4, 5, 6, 7, 8, 9, 10, 3, 4, 5, 6, 11, 12, 13, 13, 13, 14 };
        setPatternSequence(mrSandmanPattSeq);

        break;
      }
      // -------------------------------------------- MR_SANDMAN -----------------------------------------------------
    case MR_SANDMAN_SHORT:
      {
        nbPatterns_ = 16;
        nbMeasures_ = 15;
        initializeBlankPatterns(nbPatterns_, nbMeasures_);

        byte pattern0 = 0;
        byte pattern1 = 1;
        byte pattern2 = 2;
        byte pattern3 = 3;
        byte pattern4 = 4;
        byte pattern5 = 5;
        byte pattern6 = 6;
        byte pattern11 = 11;
        byte pattern12 = 12;
        byte pattern13 = 13;
        byte pattern14 = 14;
        byte empty = 15;

        // --------------------------------------------------- Pattern 0:
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, DS3S, pattern0, 1, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern0, 2, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, G03S, pattern0, 2, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern0, 3, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, AS3S, pattern0, 3, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern0, 4, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, D04S, pattern0, 4, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern0, 5, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, C04S, pattern0, 5, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern0, 6, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, AS3S, pattern0, 6, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern0, 7, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, G03S, pattern0, 7, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern0, 8, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, DS3S, pattern0, 8, hasOutput);
        setSemiquaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern0, 16, hasOutput);


        // ------------------------------------------------- Pattern 1:
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, F03S, pattern1, 1, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern1, 2, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, GS3S, pattern1, 2, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern1, 3, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, C04S, pattern1, 3, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern1, 4, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, DS4S, pattern1, 4, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern1, 5, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, D04S, pattern1, 5, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern1, 6, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, DS2S, pattern1, 7, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern1, 8, hasOutput);



        // ------------------------------------------------ Pattern 2:
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, F03S, pattern2, 1, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern2, 2, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, GS3S, pattern2, 2, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern2, 3, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, C04S, pattern2, 3, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern2, 4, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, DS4S, pattern2, 4, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern2, 5, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, D04S, pattern2, 5, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern2, 6, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, G03S, pattern2, 7, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern2, 8, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, AS3S, pattern2, 8, hasOutput);
        setSemiquaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern2, 16, hasOutput);


        // ----------------------------------------------- Pattern 3:
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, D04S, pattern3, 1, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern3, 2, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, C04S, pattern3, 2, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern3, 3, hasOutput);


        // --------------------------------------------------- Pattern 4:
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, D04S, pattern4, 1, hasOutput);
        setSemiquaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern4, 2, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, D04S, pattern4, 2, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern4, 3, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, C04S, pattern4, 3, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern4, 4, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, D04S, pattern4, 4, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern4, 5, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, D02S, pattern4, 6, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern4, 7, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, E02S, pattern4, 7, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern4, 8, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, FS2S, pattern4, 8, hasOutput);
        setSemiquaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern4, 16, hasOutput);


        // --------------------------------------------------- Pattern 5:
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, G02S, pattern5, 1, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern5, 2, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, DS4S, pattern5, 2, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern5, 3, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, DS4S, pattern5, 3, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern5, 4, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, D04S, pattern5, 4, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern5, 5, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, DS4S, pattern5, 5, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern5, 6, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, DS4S, pattern5, 6, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern5, 7, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, D04S, pattern5, 8, hasOutput);
        setSemiquaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern5, 16, hasOutput);


        // --------------------------------------------------- Pattern 6:
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, GS3S, pattern6, 1, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern6, 2, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, GS3S, pattern6, 2, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern6, 3, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, G03S, pattern6, 3, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern6, 4, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, GS3S, pattern6, 4, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern6, 5, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, C02S, pattern6, 6, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern6, 7, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, D02S, pattern6, 7, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern6, 8, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, E02S, pattern6, 8, hasOutput);
        setSemiquaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern6, 16, hasOutput);

        // --------------------------------------------------- Pattern 11:
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, C04S, pattern11, 1, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern11, 2, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, DS4S, pattern11, 3, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern11, 4, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, DS4S, pattern11, 4, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern11, 5, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, F04S, pattern11, 6, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern11, 7, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, DS4S, pattern11, 7, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern11, 8, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, F04S, pattern11, 8, hasOutput);
        setSemiquaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern11, 16, hasOutput);


        // --------------------------------------------------- Pattern 12:
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, G04S, pattern12, 1, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern12, 3, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, DS4S, pattern12, 7, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern12, 8, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, F04S, pattern12, 8, hasOutput);
        setSemiquaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern12, 16, hasOutput);

        // --------------------------------------------------- Pattern 13:
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, G04S, pattern13, 1, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern13, 2, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, G04S, pattern13, 3, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern13, 4, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, G04S, pattern13, 5, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern13, 6, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, DS4S, pattern13, 6, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern13, 7, hasOutput);

        setQuaverHit(AUTOMATIC_SINGER, POS_SG, G04S, pattern13, 7, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern13, 8, hasOutput);

        // --------------------------------------------------- Pattern 14:
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, DS4S, pattern14, 1, hasOutput);
        setQuaverHit(AUTOMATIC_SINGER, POS_SG, OFFS, pattern14, 5, hasOutput);

        byte mrSandmanPattSeq[nbMeasures_] = { empty, 0, 1, 0, 2, 3, 4, 5, 6, 11, 12, 13, 13, 13, 14 };
        setPatternSequence(mrSandmanPattSeq);

        break;
      }
      // -------------------------------------------- SIMPLEST RYTHM -----------------------------------------------------
    case BASIC_RYTHM:
    default:
      {
        nbPatterns_ = 1;
        nbMeasures_ = 1;
        initializeBlankPatterns(nbPatterns_, nbMeasures_);

        byte patternId = 0;

        setQuarterHit(AUTOMATIC_SINGER, POS_SG, C03S, patternId, 1, hasOutput);
        setQuarterHit(AUTOMATIC_SINGER, POS_SG, OFFS, patternId, 2, hasOutput);

        setQuarterHit(AUTOMATIC_SINGER, POS_SG, C03S, patternId, 3, hasOutput);
        setQuarterHit(AUTOMATIC_SINGER, POS_SG, OFFS, patternId, 4, hasOutput);

        setQuarterHit(AUTOMATIC_SINGER, POS_SG, C03S, patternId, 3, hasOutput);
        setQuarterHit(AUTOMATIC_SINGER, POS_SG, OFFS, patternId, 4, hasOutput);

        byte simplestPattSeq[nbMeasures_] = { 0 };
        setPatternSequence(simplestPattSeq);

        break;
      }
  }
}
