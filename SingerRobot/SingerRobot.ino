#include <percu_controller.h>
#include <robo_communication.h>

#include "singer_robot.h"
#include "singer_song.h"
#include "singer_robot_config.h"

// Since the tone() library uses timer2, which also controls PWM in pins 3 and 11, these cannot be used
#define SERVO_PIN_SINGER1 6
#define SERVO_PIN_SINGER2 9
#define SERVO_PIN_SINGER3 10
#define BUZZ_PIN_SINGER1 2
#define BUZZ_PIN_SINGER2 4
#define BUZZ_PIN_SINGER3 5

bool hasOutput = false;
bool isSimulation = false;
bool hasVibrato = true;
bool hasAutomaticStart = false;
Songs automaticSong = MR_SANDMAN;
uint8_t automaticBpm = 100;

const byte openPos1 = 165;
const byte openPos2 = 140;
const byte openPos3 = 150;
const byte closedPos1 = 180;
const byte closedPos2 = 180;
const byte closedPos3 = 180;

const byte vibratoAmp = 10;

byte closedPositions[NB_SINGERS] = { closedPos1, closedPos2, closedPos3 };
byte openPositions[NB_SINGERS] = { openPos1, openPos2, openPos3 };

byte buzzPins[NB_SINGERS] = { BUZZ_PIN_SINGER1, BUZZ_PIN_SINGER2, BUZZ_PIN_SINGER3 };
byte vibratoPins[NB_SINGERS] = { SERVO_PIN_SINGER1, SERVO_PIN_SINGER2, SERVO_PIN_SINGER3 };

SingerRobot *robot;
SingerSong *song;
PercuController<NB_SHEETS, NB_POS_JOINTS_SG, BITS_FOR_POS_SG> *roboController;

void setup() {
  Serial.begin(9600);
  Serial.println("");
  Serial.println("SINGER: setup");

  // -------------------------------------------------------- Pattern setting ----------------------------------------------------------
  song = new SingerSong();
  song->createPredefinedPatterns(automaticSong, false);

  // -------------------------------------------------------- Servo attaching ----------------------------------------------------------
  robot = new SingerRobot(vibratoPins);
  robot->setVibrato(hasVibrato);
  robot->setVibratoParams(closedPositions, openPositions, vibratoAmp);
  robot->setServoSpeed(0.2);

  // Configure buzzPins for output and the timer
  for (unsigned int ii = 0; ii < NB_SINGERS; ii++) {
    pinMode(buzzPins[ii], OUTPUT);
  }

  // -------------------------------------------------------- Creation of the controller ------------------------------------------------
  roboController = new PercuController<NB_SHEETS, NB_POS_JOINTS_SG, BITS_FOR_POS_SG>(robot, song, SINGER_ADDRESS, isSimulation, hasOutput);
  roboController->setReceptor();
  if (hasAutomaticStart) {
    roboController->setBpm(automaticBpm);
    roboController->processStartSongMsg(automaticSong);
  }
}

void loop() {
  //Serial.println("SINGER: loop");
  unsigned long currTime = millis();
  roboController->goToTime(currTime, hasOutput);
  // We first check if there a note to be turned off
  for (unsigned int singerIdx = 0; singerIdx < NB_SINGERS; singerIdx++) {
    if (robot->isNoteOffPending(singerIdx)) {
      noTone(buzzPins[singerIdx]);
      robot->stopVibrato(singerIdx);
      robot->unsetNoteOffPending(singerIdx);
    }
  }
  // We then iterate again to check notes on
  for (unsigned int singerIdx = 0; singerIdx < NB_SINGERS; singerIdx++) {
    if (robot->isNoteOn(singerIdx)) {
      if (robot->isNoteOnPending(singerIdx)) {
        tone(buzzPins[singerIdx], robot->getFrequency(singerIdx));
        robot->startVibrato(singerIdx, currTime);
        robot->unsetNoteOnPending(singerIdx);
      }
      robot->checkVibrato(singerIdx, currTime);
    }
  }
}