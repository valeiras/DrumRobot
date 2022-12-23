#include <Servo.h>
#include <robo_controller.h>

#include "drum_robot.h"
#include "drum_song.h"
#include "drum_robot_config.h"

#define BD_HIT_PIN 5
#define RIGHT_HIT_PIN 6
#define LEFT_HIT_PIN 9
#define RIGHT_POS_PIN 10
#define LEFT_POS_PIN 11

#define BPM_INPUT_PIN A0

#define ANALOG_MIN 0
#define ANALOG_MAX 1023

unsigned int initialDelay = 1000;
unsigned long ellapsedTime;

unsigned long initTime;
unsigned short bpm = 110;

bool printOutput = false;
bool simulation = true;

int minBpm = 60;
int maxBpm = 150;

DrumRobot robot;
DrumSong song;
RoboController<NB_HIT_JOINTS_DR, NB_POS_JOINTS_DR, BITS_FOR_POS_DR> roboController(&robot, &song, simulation, printOutput);

void setup() {
  Serial.begin(9600);

  // -------------------------------------------------------- Pattern setting ----------------------------------------------------------
  song.createPredefinedPatterns(BASIC_RYTHM, false);
  song.setBpm(bpm);

  if (printOutput) {
    song.printPatterns();
  }

  byte hitPins[NB_HIT_JOINTS_DR] = {BD_HIT_PIN, RIGHT_HIT_PIN, LEFT_HIT_PIN};
  byte posPins[NB_POS_JOINTS_DR] = {RIGHT_POS_PIN, LEFT_POS_PIN};
  robot.attachServos(hitPins, posPins);
  robot.setServoSpeed(0.3);

  initTime = millis();
  song.setInitialTime(initTime + initialDelay);

  roboController.initializeRobot();
}

void loop() {
  ellapsedTime = millis() - initTime;

  for (unsigned int limb = 0; limb < NB_HIT_JOINTS_DR; limb++) {
    if (ellapsedTime >= roboController.getTimeNextHitInstruction(limb)) {
      roboController.manageHitInstruction(limb, ellapsedTime);
    }
    if (roboController.isTimeToChangePos(limb, ellapsedTime)){
      roboController.managePosInstruction(limb);
    }
  }
}