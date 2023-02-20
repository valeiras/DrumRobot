#include <Servo.h>
#include <robo_controller.h>

#include "drum_robot.h"
#include "drum_song.h"
#include "drum_robot_config.h"

#define HEAD_HIT_PIN 3
#define BD_HIT_PIN 5
#define LEFT_HIT_PIN 6
#define RIGHT_HIT_PIN 9
#define HIPS_POS_PIN 10
#define USELESS_PIN 11

#define BPM_INPUT_PIN A1
#define ANALOG_INPUT_PIN1 A0
#define ANALOG_INPUT_PIN2 A2
#define ANALOG_INPUT_PIN3 A3
#define DIGITAL_INPUT_PIN2 12
#define DIGITAL_INPUT_PIN3 13

#define ANALOG_MIN 0
#define ANALOG_MAX 1023

unsigned int initialDelay = 1000;
unsigned long ellapsedTime;

unsigned long initTime;
unsigned short bpm = 90;

bool printOutput = false;
bool simulation = false;
bool variableBpm = false;

int minBpm = 60;
int maxBpm = 150;

DrumRobot robot = DrumRobot();
DrumSong song = DrumSong();
RoboController<NB_HIT_JOINTS_DR, NB_POS_JOINTS_DR, BITS_FOR_POS_DR> roboController(&robot, &song, bpm, simulation, printOutput);

void setup() {
  Serial.begin(9600);

  // -------------------------------------------------------- Pattern setting ----------------------------------------------------------
  song.createPredefinedPatterns(BASIC_RYTHM, false);
  robot.printPosNames();

  if (printOutput) {
    song.printPatterns();
  }

  byte hitPins[NB_HIT_JOINTS_DR] = { LEFT_HIT_PIN, RIGHT_HIT_PIN, BD_HIT_PIN, HEAD_HIT_PIN };
  byte posPins[NB_POS_JOINTS_DR] = { HIPS_POS_PIN, USELESS_PIN };
  robot.attachServos(hitPins, posPins);

  initTime = millis();
  roboController.setInitialTime(initTime + initialDelay);
  roboController.initializeRobot();

  pinMode(BPM_INPUT_PIN, INPUT);
  pinMode(ANALOG_INPUT_PIN1, INPUT);
  pinMode(ANALOG_INPUT_PIN2, INPUT);
  pinMode(ANALOG_INPUT_PIN3, INPUT);

  pinMode(DIGITAL_INPUT_PIN2, INPUT);
  pinMode(DIGITAL_INPUT_PIN3, INPUT);
}

void loop() {
  ellapsedTime = millis() - initTime;
  roboController.goToTime(ellapsedTime, printOutput);

  if (variableBpm) {
    int sensorValue = analogRead(BPM_INPUT_PIN);
    int newBpm = map(sensorValue, ANALOG_MIN, ANALOG_MAX, minBpm, maxBpm);
    if (newBpm != bpm) {
      bpm = newBpm;
      //roboController.setBpm(bpm);
    }
  }
}