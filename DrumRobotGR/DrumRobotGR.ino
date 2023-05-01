#include <percu_controller.h>
#include <robo_communication.h>

#include "drum_robot_gr.h"
#include "drum_song_gr.h"
#include "drum_robot_config_gr.h"

#define BD_HIT_PIN 3
#define LEFT_HIT_PIN 6
#define RIGHT_HIT_PIN 9
#define LEFT_POS_PIN 10
#define RIGHT_POS_PIN 11

bool hasOutput = false;
bool isSimulation = false;
bool hasAutomaticStart = false;
Songs automaticSong = SEVEN_NATION;

DrumRobotGR *robot;
DrumSongGR *song;
PercuController<NB_HIT_JOINTS_DR, NB_POS_JOINTS_DR, BITS_FOR_POS_DR> *roboController;

void setup() {
  Serial.begin(9600);

  // -------------------------------------------------------- Pattern setting ----------------------------------------------------------
  song = new DrumSongGR();
  song->createPredefinedPatterns(BASIC_RYTHM, false);
  if (hasOutput) {
    song->printPatterns();
  }

  // -------------------------------------------------------- Servo attaching ----------------------------------------------------------
  byte hitPins[NB_HIT_JOINTS_DR] = { LEFT_HIT_PIN, RIGHT_HIT_PIN, BD_HIT_PIN };
  byte posPins[NB_POS_JOINTS_DR] = { LEFT_POS_PIN, RIGHT_POS_PIN };
  robot = new DrumRobotGR(hitPins, posPins);

  roboController = new PercuController<NB_HIT_JOINTS_DR, NB_POS_JOINTS_DR, BITS_FOR_POS_DR>(robot, song, DRUM_ADDRESS, isSimulation, hasOutput);
  roboController->setReceptor();

  if (hasAutomaticStart) {
    roboController->processStartSongMsg(automaticSong);
  }
}

void loop() {
  roboController->goToTime(millis(), hasOutput);
}