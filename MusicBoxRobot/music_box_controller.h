#ifndef Music_box_controller_h
#define Music_box_controller_h

#include <Arduino.h>
#include <percu_controller.h>
#include <bpm_orders.h>
#include <bpm_values.h>

#include "music_box_config.h"
#include "music_box_robot.h"
#include "music_box_song.h"
#include "music_box_percu_robot.h"
#include "music_box_percu_song.h"

class MusicBoxController : public PercuController<NB_HIT_JOINTS_MB, NB_POS_JOINTS_MB, BITS_FOR_POS_MB> {
public:
  MusicBoxController(MusicBoxRobot* mbRobot, MusicBoxSong* mbSong,
                     MusicBoxPercuRobot* prcRobot, PercuSong<NB_HIT_JOINTS_MB, BITS_FOR_POS_MB>* prcSong,
                     int address, bool simulation, bool printOutput);

  void processStartMsg();
  void processStopMsg();
  void processResyncMsg();
  void processBpmChangeMsg(uint8_t messageContent);
  void processBpmIdxChangeMsg(uint8_t messageContent);
  void processModeChangeMsg(uint8_t messageContent);
  void processSetResyncTimeMsg(uint16_t messageContent);

  void goToTime(unsigned long currTime);

private:
  uint8_t nbSemiquaversNextInstruction_, semiquaverCount_;
  bool currInstructionIsOn_, firstMbAfterStart_;

  MusicBoxRobot* mbRobot_;
  MusicBoxSong* mbSong_;
  unsigned long lastOrderTime_;

  uint8_t currVelOrder_;
};

#endif