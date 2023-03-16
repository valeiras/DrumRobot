#include <Arduino.h>
#include <robo_communication.h>

#include "music_box_controller.h"
#include "music_box_robot.h"

#define SERVO_PIN 6
#define SENSOR_PIN A0

MusicBoxRobot *robot;
MusicBoxSong *song;

MusicBoxController *controller;

void setup() {
  robot = new MusicBoxRobot(SERVO_PIN, SENSOR_PIN);
  song = new MusicBoxSong();

  song->setOnInstruction(64);
  song->setOffInstruction(16);
  song->setOnInstruction(64);
  song->setOffInstruction(16);
  
  controller = new MusicBoxController(MUSIC_BOX_ADDRESS, robot, song);
}

void loop() {
  // put your main code here, to run repeatedly:
}
