#include "music_box_percu_song.h"

MusicBoxPercuSong::MusicBoxPercuSong()
  : PercuSong<NB_HIT_JOINTS_MB, BITS_FOR_POS_MB>::PercuSong() {
}

void MusicBoxPercuSong::createPredefinedPatterns(Songs songName, bool hasOutput = false) {
  switch (songName) {
    // -------------------------------------------- SIMPLEST -----------------------------------------------------
    case BASIC_RYTHM:
    default:
      {
        nbPatterns_ = 1;
        nbMeasures_ = 1;
        initializeBlankPatterns(nbPatterns_, nbMeasures_);

        byte patternId0 = 0;

        // Foot
        // -------------------------------------------0001-------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(FOOT_MB, patternId0, HITP, REST, REST, REST, HITP, REST, REST, REST, HITP, REST, REST, REST, HITP, REST, REST, REST, hasOutput);
        setVelPattern(FOOT_MB, patternId0, V015, V000, V000, V000, V006, V000, V000, V000, V008, V000, V000, V000, V015, V000, V000, V000, hasOutput);

        // Head
        // -----------------------------------------------0001-------////--------0002--------////--------0003--------////--------0004--------////------
        setHitPattern(HEAD_MB, patternId0, HITP, REST, REST, REST, HITP, REST, REST, REST, HITP, REST, REST, REST, HITP, REST, REST, REST, hasOutput);
        setVelPattern(HEAD_MB, patternId0, V015, V000, V000, V000, V006, V000, V000, V000, V008, V000, V000, V000, V015, V000, V000, V000, hasOutput);


        byte simplestPattSeq[nbMeasures_] = { 0 };
        setPatternSequence(simplestPattSeq);

        break;
      }
  }
}