#include "music_box_song.h"

MusicBoxSong::MusicBoxSong() {
  currInstructionIndex_ = -1;
  nbInstructions_ = 0;
}

void MusicBoxSong::setOnInstruction(uint8_t nbSemiquavers) {
  setInstruction(nbSemiquavers, ON);
}

void MusicBoxSong::setOffInstruction(uint8_t nbSemiquavers) {
  setInstruction(nbSemiquavers, OFF);
}

bool MusicBoxSong::getNextInstruction(uint8_t &nbSemiquavers) {
  Serial.print("Curr instruction index: ");
  Serial.println(currInstructionIndex_);

  currInstructionIndex_ = ++currInstructionIndex_ % nbInstructions_;
  nbSemiquavers = ((instructions_[currInstructionIndex_] & SEMIQUAVERS_MASK) >> BITS_FOR_ON_OFF) + 1;
  return bitRead(instructions_[currInstructionIndex_], 0);
}

void MusicBoxSong::setInstruction(uint8_t nbSemiquavers, bool onOrOff) {
  if (nbSemiquavers > SEMIQUAVERS_PER_LOOP) {
    Serial.print("The number of semiquavers cannot be greater than ");
    Serial.println(SEMIQUAVERS_PER_LOOP);
  } else {
    instructions_[nbInstructions_++] = ((nbSemiquavers - 1) << BITS_FOR_ON_OFF) | onOrOff;
  }
}

void MusicBoxSong::printInstructions() {
  Serial.println("Print instructions: ");
  for (unsigned int ii = 0; ii < nbInstructions_; ii++) {
    Serial.print("Instruction ");
    Serial.print(ii);
    if (bitRead(instructions_[currInstructionIndex_], 0)) {
      Serial.print(" ON for ");
    } else {
      Serial.print(" OFF for ");
    }
    Serial.print(((instructions_[ii] & SEMIQUAVERS_MASK) >> BITS_FOR_ON_OFF) + 1);
    Serial.println(" semiquavers");
  }
}