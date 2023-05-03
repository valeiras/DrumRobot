#include <Arduino.h>
#include <robo_communication.h>

#include "music_box_controller.h"
#include "music_box_robot.h"
#include "music_box_song.h"
#include "music_box_percu_robot.h"
#include "music_box_percu_song.h"

#define MUSIC_BOX_PIN 6
#define FOOT_PIN 9
#define HEAD_PIN 10

#define SENSOR_PIN A0

bool hasOutput = false;
bool isSimulation = false;
bool hasAutomaticStart = false;
Songs automaticSong = SEVEN_NATION;

MusicBoxRobot *mbRobot;
MusicBoxSong *mbSong;

MusicBoxPercuRobot *prcRobot;
MusicBoxPercuSong *prcSong;

MusicBoxController *controller;

void setup() {
  Serial.begin(9600);

  mbRobot = new MusicBoxRobot(MUSIC_BOX_PIN, SENSOR_PIN);
  mbSong = new MusicBoxSong();

  mbSong->setOnInstruction(16);

  // -------------------------------------------------------- Pattern setting ----------------------------------------------------------
  prcSong = new MusicBoxPercuSong();
  prcSong->createPredefinedPatterns(BASIC_RYTHM, false);
  if (hasOutput) {
    prcSong->printPatterns();
  }

  // -------------------------------------------------------- Servo attaching ----------------------------------------------------------
  byte hitPins[NB_HIT_JOINTS_MB] = { FOOT_PIN, HEAD_PIN };
  prcRobot = new MusicBoxPercuRobot(hitPins);

  controller = new MusicBoxController(mbRobot, mbSong, prcRobot, prcSong, MUSIC_BOX_ADDRESS, isSimulation, hasOutput);
  controller->setReceptor();
  if (hasAutomaticStart) {
    controller->processStartSongMsg(automaticSong);
  }
}

void loop() {
  controller->goToTime(millis());
}
