#ifndef Singer_robot__h
#define Singer_robot__h

#include <Array.h>
#include <percu_robot.h>
#include "singer_robot_config.h"

#define FIRST_AVAILABLE_NOTE_IDX 84

class SingerRobot : public PercuRobot<NB_SHEETS, NB_POS_JOINTS_SG> {
public:
  SingerRobot(byte vibratoPins[NB_SINGERS]);

  unsigned int getFrequency(byte singerIdx);

  void hit(byte singerIdx, byte pos, byte noteIdx, bool hasOutput = 0);
  void rest(byte singerIdx, byte pos = 0, bool hasOutput = 0);

  void processNoteOnMessage(byte noteIdx);
  void processNoteOffMessage(byte noteIdx);
  void processVibratoAmpChangeMessage(byte vibratoAmp);

  void stop();

  void makeNoteOn(byte singerIdx, byte noteIdx, bool hasOutput = 0);
  void makeNoteOff(byte singerIdx);

  bool isNoteOn(byte singerIdx);
  bool isNoteOnPending(byte singerIdx);
  bool isNoteOffPending(byte singerIdx);
  bool unsetNoteOnPending(byte singerIdx);
  bool unsetNoteOffPending(byte singerIdx);

  void startVibrato(byte singerIdx, unsigned long currTime, bool hasOutput = 0);
  void stopVibrato(byte singerIdx, bool hasOutput = 0);
  void checkVibrato(byte singerIdx, unsigned long currTime, bool hasOutput = 0);

  void setVibrato(bool hasVibrato);
  void setVibratoParams(byte closedPos[NB_SINGERS], byte openPos[NB_SINGERS], byte vibratoAmp);

private:
  void setLimbParams();
  void setFrequencies();

  void goToNextVibratoPosition(byte singerIdx);

  Array<unsigned int, NB_NOTES_SG> frequencies_;

  bool noteOn_[NB_SINGERS], noteOnPending_[NB_SINGERS], noteOffPending_[NB_SINGERS];
  byte currNoteIdx_[NB_SINGERS];
  Servo vibratoServos_[NB_SINGERS];

  unsigned int currSinger_;


  bool hasVibrato_;
  unsigned char vibratoDirection_[NB_SINGERS];
  unsigned long nextVibratoInstructionTime_[NB_SINGERS];
  byte closedPosition_[NB_SINGERS], openPosition_[NB_SINGERS], vibratoAmplitude_;
};

#endif
