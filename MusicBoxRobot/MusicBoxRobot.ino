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

bool printOutput = false;
bool simulation = false;

MusicBoxRobot *mbRobot;
MusicBoxSong *mbSong;

MusicBoxPercuRobot *prcRobot;
MusicBoxPercuSong *prcSong;

MusicBoxController *controller;

void setup() {
  Serial.begin(9600);

  mbRobot = new MusicBoxRobot(MUSIC_BOX_PIN, SENSOR_PIN);
  mbSong = new MusicBoxSong();

  for (unsigned int ii = 0; ii < 10; ii++) {
    mbSong->setOnInstruction(112);
    mbSong->setOffInstruction(16);
  }

  // -------------------------------------------------------- Pattern setting ----------------------------------------------------------
  prcSong = new MusicBoxPercuSong();
  prcSong->createPredefinedPatterns(SIMPLEST_RYTHM, false);
  if (printOutput) {
    prcSong->printPatterns();
  }

  // -------------------------------------------------------- Servo attaching ----------------------------------------------------------
  byte hitPins[NB_HIT_JOINTS_MB] = { FOOT_PIN, HEAD_PIN };
  prcRobot = new MusicBoxPercuRobot(hitPins);

  controller = new MusicBoxController(mbRobot, mbSong, prcRobot, prcSong, MUSIC_BOX_ADDRESS, simulation, printOutput);
  controller->setReceptor();
}

void loop() {
  controller->goToTime(millis());
}
