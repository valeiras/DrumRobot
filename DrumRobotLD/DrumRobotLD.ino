#include <percu_controller.h>
#include <robo_communication.h>

#include "drum_robot_ld.h"
#include "drum_song_ld.h"
#include "drum_robot_config_ld.h"

#define HEAD_HIT_PIN 3
#define BD_HIT_PIN 5
#define LEFT_HIT_PIN 6
#define RIGHT_HIT_PIN 9
#define HIPS_POS_PIN 10

// This is a temporary hack: this was supposed to be the left pos servo, but we are using it to move the head against the movement of the hips
#define HEAD_POS_PIN 11

bool printOutput = false;
bool simulation = false;

DrumRobotLD *robot;
DrumSongLD *song;
PercuController<NB_HIT_JOINTS_DR, NB_POS_JOINTS_DR, BITS_FOR_POS_DR> *roboController;

void setup() {
  Serial.begin(9600);

  // -------------------------------------------------------- Pattern setting ----------------------------------------------------------
  song = new DrumSongLD();
  song->createPredefinedPatterns(BASIC_RYTHM, false);
  if (printOutput) {
    song->printPatterns();
  }

  // -------------------------------------------------------- Servo attaching ----------------------------------------------------------
  byte hitPins[NB_HIT_JOINTS_DR] = { LEFT_HIT_PIN, RIGHT_HIT_PIN, BD_HIT_PIN };
  byte posPins[NB_POS_JOINTS_DR] = { HIPS_POS_PIN, HEAD_POS_PIN };
  robot = new DrumRobotLD(hitPins, posPins);

  roboController = new PercuController<NB_HIT_JOINTS_DR, NB_POS_JOINTS_DR, BITS_FOR_POS_DR>(robot, song, DRUM_ADDRESS, simulation, printOutput);
  roboController->setReceptor();
}

void loop() {
  roboController->goToTime(millis(), printOutput);
}