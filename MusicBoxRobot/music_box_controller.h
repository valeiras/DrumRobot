#ifndef Music_box_controller_h
#define Music_box_controller_h

#include <Arduino.h>
#include <robo_receptor.h>

#include "music_box_robot.h"
#include "music_box_song.h"

#define MIN_BPM 50
#define MAX_BPM 180
#define MIN_V 1
#define MAX_V 180

class MusicBoxController : public RoboReceptor {
public:
  MusicBoxController();
  MusicBoxController(int address, MusicBoxRobot* robot, MusicBoxSong* song);

  void treatStartMsg();
  void treatResyncMsg();
  void treatBpmChangeMsg(uint8_t messageContent);
  void treatModeChangeMsg(uint8_t messageContent);
  void treatSetResyncTimeMsg(uint16_t messageContent);

  void setBpm(int bpm);

private:
  unsigned short bpm_, v_;
  unsigned int timePerSemiquaver_;
  unsigned long timeNextSemiquaver_, initialTime_;

  bool hasStarted_;

  MusicBoxRobot* robot_;
  MusicBoxSong* song_;
};

#endif