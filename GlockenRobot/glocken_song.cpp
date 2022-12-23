#include "glocken_song.h"

GlockenSong::GlockenSong()
  : RoboSong<NB_LIMBS_GLOCK, BITS_FOR_POS_GLOCK>::RoboSong() {
  nbOfPositions_[LEFT_ARM_GLOCK] = NB_POS_LAG;
  nbOfPositions_[RIGHT_ARM_GLOCK] = NB_POS_RAG;
}

void GlockenSong::createPredefinedPatterns(byte rythmName, bool printOutput = false) {
  switch (rythmName) {
    // -------------------------------------------- SIMPLEST RYTHM -----------------------------------------------------
    default:

      break;
  }
}