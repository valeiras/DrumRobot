#include <Servo.h>
#include <robo_controller.h>

#include "glocken_robot.h"
#include "glocken_song.h"
#include "glocken_robot_config.h"

#define LEFT_HIT_PIN_GL 5
#define RIGHT_HIT_PIN_GL 6
#define LEFT_POS_PIN_GL 9
#define RIGHT_POS_PIN_GL 10

#define BPM_INPUT_PIN A0

#define ANALOG_MIN 0
#define ANALOG_MAX 1023

unsigned int initialDelay = 1000;
unsigned long ellapsedTime;

unsigned long initTime;
unsigned short bpm = 100;

bool printOutput = false;
bool simulation = false;
bool variableBpm = false;

int minBpm = 60;
int maxBpm = 150;

byte songName = FRERE_JACQUES;

GlockenRobot robot = GlockenRobot();
GlockenSong song = GlockenSong();
RoboController<NB_HIT_JOINTS_GL, NB_POS_JOINTS_GL, BITS_FOR_POS_GL> roboController(&robot, &song, bpm, simulation, printOutput);

void setup() {
  Serial.begin(9600);

  // -------------------------------------------------------- Pattern setting ----------------------------------------------------------
  song.createPredefinedPatterns(songName, false);

  if (printOutput) {
    song.printPatterns();
  }

  byte hitPins[NB_HIT_JOINTS_GL] = { LEFT_HIT_PIN_GL, RIGHT_HIT_PIN_GL };
  byte posPins[NB_POS_JOINTS_GL] = { LEFT_POS_PIN_GL, RIGHT_POS_PIN_GL };
  robot.attachServos(hitPins, posPins, printOutput);

  initTime = millis();
  roboController.setInitialTime(initTime + initialDelay);
  roboController.initializeRobot();
}

void loop() {
  ellapsedTime = millis() - initTime;
  roboController.goToTime(ellapsedTime, printOutput);
}