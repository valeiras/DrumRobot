#include <percu_controller.h>
#include <robo_communication.h>

#include "glocken_robot_gr.h"
#include "glocken_song_gr.h"
#include "glocken_robot_config_gr.h"

#define LEFT_HIT_PIN_GL 5
#define RIGHT_HIT_PIN_GL 6
#define LEFT_POS_PIN_GL 9
#define RIGHT_POS_PIN_GL 10

bool hasOutput = false;
bool isSimulation = false;
bool hasAutomaticStart = false;
Songs automaticSong = HOUND_DOG;

byte songName = FRERE_JACQUES;

GlockenRobotGR *robot;
GlockenSongGR *song;
PercuController<NB_HIT_JOINTS_GL, NB_POS_JOINTS_GL, BITS_FOR_POS_GL> *roboController;

void setup() {
  Serial.begin(9600);

  // -------------------------------------------------------- Pattern setting ----------------------------------------------------------
  song = new GlockenSongGR();
  song->createPredefinedPatterns(songName, false);
  if (hasOutput) {
    song->printPatterns();
  }

  // ------------------------------------------------------- Servo Attaching ---------------------------------------------
  byte hitPins[NB_HIT_JOINTS_GL] = { LEFT_HIT_PIN_GL, RIGHT_HIT_PIN_GL };
  byte posPins[NB_POS_JOINTS_GL] = { LEFT_POS_PIN_GL, RIGHT_POS_PIN_GL };
  robot = new GlockenRobotGR(hitPins, posPins);

  roboController = new PercuController<NB_HIT_JOINTS_GL, NB_POS_JOINTS_GL, BITS_FOR_POS_GL>(robot, song, GLOCKEN_ADDRESS, isSimulation, hasOutput);
  roboController->setReceptor();

  if (hasAutomaticStart) {
    roboController->processStartSongMsg(automaticSong);
  }
}

void loop() {
  roboController->goToTime(millis(), hasOutput);
}