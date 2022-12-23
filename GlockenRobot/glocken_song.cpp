#include "glocken_song.h"

GlockenSong::GlockenSong()
  : RoboSong<NB_LIMBS_GL, BITS_FOR_POS_GL>::RoboSong() {
  nbOfPositions_[LEFT_ARM_GL] = NB_POS_LA_GL;
  nbOfPositions_[RIGHT_ARM_GL] = NB_POS_RA_GL;
}

void GlockenSong::createPredefinedPatterns(byte rythmName, bool printOutput = false) {
  switch (rythmName) {
    // -------------------------------------------- SIMPLEST RYTHM -----------------------------------------------------
    default:

      break;
  }
}