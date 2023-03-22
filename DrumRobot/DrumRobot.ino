#include <percu_controller.h>
#include <robo_communication.h>

#include "drum_robot.h"
#include "drum_song.h"
#include "drum_robot_config.h"

#define BD_HIT_PIN 3
#define LEFT_HIT_PIN 6
#define RIGHT_HIT_PIN 9
#define LEFT_POS_PIN 10
#define RIGHT_POS_PIN 11

bool printOutput = false;
bool simulation = false;

DrumRobot *robot;
DrumSong *song;
PercuController<NB_HIT_JOINTS_DR, NB_POS_JOINTS_DR, BITS_FOR_POS_DR> *roboController;

void setup() {
  Serial.begin(9600);

  // -------------------------------------------------------- Pattern setting ----------------------------------------------------------
  song = new DrumSong();
  song->createPredefinedPatterns(BASIC_RYTHM, false);
  if (printOutput) {
    song->printPatterns();
  }

  // -------------------------------------------------------- Servo attaching ----------------------------------------------------------
  byte hitPins[NB_HIT_JOINTS_DR] = { LEFT_HIT_PIN, RIGHT_HIT_PIN, BD_HIT_PIN };
  byte posPins[NB_POS_JOINTS_DR] = { LEFT_POS_PIN, RIGHT_POS_PIN };
  robot = new DrumRobot(hitPins, posPins);

  roboController = new PercuController<NB_HIT_JOINTS_DR, NB_POS_JOINTS_DR, BITS_FOR_POS_DR>(robot, song, DRUM_ADDRESS, simulation, printOutput);
  roboController->setReceptor();
}

void loop() {
  roboController->goToTime(millis(), printOutput);
}