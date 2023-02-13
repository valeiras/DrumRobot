#include "singer_song.h"

SingerSong::SingerSong()
  : RoboSong<NB_LIMBS_SG, BITS_FOR_POS_SG>::RoboSong() {
  nbOfPositions_[SINGER_1] = NB_NOTES;
  nbOfPositions_[SINGER_2] = NB_NOTES;
  nbOfPositions_[SINGER_3] = NB_NOTES;
}

void SingerSong::createPredefinedPatterns(byte rythmName, bool printOutput = false) {
  switch (rythmName) {
    // -------------------------------------------- SIMPLEST RYTHM -----------------------------------------------------
    case C_SCALE:
    default:
      {
        if (printOutput) {
          Serial.println("Simplest rythm");
        }
        nbPatterns_ = 1;
        nbBeats_ = 1;
        initializeBlankPatterns(nbPatterns_, nbBeats_);

        byte patternId = 0;

        setSemiquaverHit(SINGER_1, C03_SG, NOTE_ON, patternId, 1, printOutput);
        setSemiquaverHit(SINGER_1, C03_SG, NOTE_OFF, patternId, 2, printOutput);
        setSemiquaverHit(SINGER_1, D03_SG, NOTE_ON, patternId, 3, printOutput);
        setSemiquaverHit(SINGER_1, D03_SG, NOTE_OFF, patternId, 4, printOutput);
        setSemiquaverHit(SINGER_1, E03_SG, NOTE_ON, patternId, 5, printOutput);
        setSemiquaverHit(SINGER_1, E03_SG, NOTE_OFF, patternId, 6, printOutput);
        setSemiquaverHit(SINGER_1, F03_SG, NOTE_ON, patternId, 7, printOutput);
        setSemiquaverHit(SINGER_1, F03_SG, NOTE_OFF, patternId, 8, printOutput);
        setSemiquaverHit(SINGER_1, G03_SG, NOTE_ON, patternId, 9, printOutput);
        setSemiquaverHit(SINGER_1, G03_SG, NOTE_OFF, patternId, 10, printOutput);
        setSemiquaverHit(SINGER_1, A03_SG, NOTE_ON, patternId, 11, printOutput);
        setSemiquaverHit(SINGER_1, A03_SG, NOTE_OFF, patternId, 12, printOutput);
        setSemiquaverHit(SINGER_1, B03_SG, NOTE_ON, patternId, 13, printOutput);
        setSemiquaverHit(SINGER_1, B03_SG, NOTE_OFF, patternId, 14, printOutput);
        setSemiquaverHit(SINGER_1, C04_SG, NOTE_ON, patternId, 15, printOutput);
        setSemiquaverHit(SINGER_1, C04_SG, NOTE_OFF, patternId, 16, printOutput);

        setQuarterHit(SINGER_2, C03_SG, NOTE_ON, patternId, 1, printOutput);
        setQuarterHit(SINGER_2, C03_SG, NOTE_OFF, patternId, 3, printOutput);

        setQuarterHit(SINGER_2, C03_SG, NOTE_ON, patternId, 1, printOutput);
        setQuarterHit(SINGER_2, C03_SG, NOTE_OFF, patternId, 3, printOutput);

        byte simplestPattSeq[nbBeats_] = { 0 };
        setPatternSequence(simplestPattSeq);

        break;
      }
  }
}

String SingerSong::getNoteName(byte note) {
  return noteNames_[note];
}

int SingerSong::getFreqNextHit(byte singerIdx) {
  byte note = getPosNextHit(singerIdx);
  return frequencies_[note];
}

void SingerSong::setFrequencies() {
  int freq[NB_NOTES_SG] = { FREQ_C03, FREQ_CS3, FREQ_D03, FREQ_DS3, FREQ_E03, FREQ_F03, FREQ_FS3, FREQ_G03, FREQ_GS3, FREQ_A03, FREQ_AS3, FREQ_B03,
                            FREQ_C04, FREQ_CS4, FREQ_D04, FREQ_DS4, FREQ_E04, FREQ_F04, FREQ_FS4, FREQ_G04, FREQ_GS4, FREQ_A04, FREQ_AS4, FREQ_B04 };

  String names[NB_NOTES_SG] = { "C03", "CS3", "D03", "DS3", "E03", "F03", "FS3", "G03", "GS3", "A03", "AS3", "B03",
                                "C04", "CS4", "D04", "DS4", "E04", "F04", "FS4", "G04", "GS4", "A04", "AS4", "B04" };

  for (unsigned int ii = 0; ii < NB_NOTES_SG; ii++) {
    frequencies_[ii] = freq[ii];
    noteNames_[ii] = names[ii];
  }
}