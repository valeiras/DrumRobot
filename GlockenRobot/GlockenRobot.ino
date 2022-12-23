#include <Servo.h>
#include "glocken_robot.h"
#include "glocken_song.h"
#include "glocken_robot_config.h"

#define RIGHT_HIT_PIN_GL 6
#define LEFT_HIT_PIN_GL 9
#define RIGHT_POS_PIN_GL 10
#define LEFT_POS_PIN_GL 11

#define BPM_INPUT_PIN A0

#define ANALOG_MIN 0
#define ANALOG_MAX 1023

unsigned int initialDelay = 1000;
unsigned long ellapsedTime;

unsigned long timeNextHitInstruction[NB_HIT_JOINTS_GL], timeNextPosInstruction[NB_POS_JOINTS_GL];
byte nextInstruction[NB_HIT_JOINTS_GL];  // Indicates wheter next instruction is hit or rest
bool moveLimb[NB_POS_JOINTS_GL];
byte nextPos[NB_POS_JOINTS_GL];

unsigned long initTime;
unsigned short bpm = 110;

bool printOutput = false;
bool simulation = true;

int minBpm = 60;
int maxBpm = 150;

GlockenRobot robot;
GlockenSong song;

void setup() {
  Serial.begin(9600);

  // -------------------------------------------------------- Pattern setting ----------------------------------------------------------
  song.createPredefinedPatterns(0, false);
  song.setBpm(bpm);

  if (printOutput) {
    song.printPatterns();
  }

  byte hitPins[NB_HIT_JOINTS_GL] = {RIGHT_HIT_PIN_GL, LEFT_HIT_PIN_GL};
  byte posPins[NB_POS_JOINTS_GL] = {RIGHT_POS_PIN_GL, LEFT_POS_PIN_GL};
  robot.attachServos(hitPins, posPins);
  robot.setWServo(0.3);

  initTime = millis();

  song.setInitialTime(initTime + initialDelay);

  for (unsigned int limb = 0; limb < NB_POS_JOINTS_GL; limb++) {
    timeNextPosInstruction[limb] = 0;
    moveLimb[limb] = false;
  }

  for (unsigned int limb = 0; limb < NB_HIT_JOINTS_GL; limb++) {
    song.computeNextHit(limb, printOutput);
    nextInstruction[limb] = HIT;

    if (limb < NB_POS_JOINTS_GL) {
      nextPos[limb] = song.getPosNextHit(limb);
      timeNextHitInstruction[limb] = song.getTimeNextHit(limb) - robot.getHitTime(limb, nextPos[limb], song.getVelNextHit(limb));
      robot.rest(limb, nextPos[limb]);
      robot.goToPos(limb, nextPos[limb]);
    } else {
      timeNextHitInstruction[limb] = song.getTimeNextHit(limb) - robot.getHitTime(limb, 0, song.getVelNextHit(limb));
      robot.rest(limb);
    }
  }

  if (printOutput) {
    Serial.print("Pos left arm: ");
    Serial.println(nextPos[0]);
    Serial.print("Pos right arm: ");
    Serial.println(nextPos[1]);
  }
}

void loop() {
  ellapsedTime = millis() - initTime;

  for (unsigned int limb = 0; limb < NB_HIT_JOINTS_GL; limb++) {
    if (ellapsedTime >= timeNextHitInstruction[limb]) {
      manageHitInstruction(limb, ellapsedTime);
    }

    if (limb < NB_POS_JOINTS_GL && moveLimb[limb] && ellapsedTime >= timeNextPosInstruction[limb]) {
      managePosInstruction(limb);
    }
  }
}

void manageHitInstruction(byte limb, unsigned long currTime) {
  byte currentPosition = limb < NB_POS_JOINTS_GL ? nextPos[limb] : 0;

  if (nextInstruction[limb] == HIT) {
    if (simulation) {
      Serial.println("");
      Serial.print(robot.getPosName(limb, currentPosition));
      Serial.print(" at time ");
      Serial.println(timeNextHitInstruction[limb]);
    }
    robot.hit(limb, currentPosition, song.getVelNextHit(limb), printOutput);

    if (printOutput) {
      Serial.print("Hit time: ");
      Serial.println(robot.getHitTime(limb, currentPosition, song.getVelNextHit(limb)));
    }

    timeNextHitInstruction[limb] += robot.getHitTime(limb, currentPosition, song.getVelNextHit(limb));
    nextInstruction[limb] = REST;
  }

  else if (nextInstruction[limb] == REST) {
    song.computeNextHit(limb, printOutput);

    if (limb < NB_POS_JOINTS_GL) {
      // We check if we need to move
      nextPos[limb] = song.getPosNextHit(limb);

      if (currentPosition != nextPos[limb]) {
        moveLimb[limb] = true;
        timeNextPosInstruction[limb] = currTime + abs(robot.getHitAngle(limb, currentPosition, song.getVelNextHit(limb)) - robot.getRestAngle(limb, nextPos[limb])) / (robot.getServoSpeed());
        currentPosition = nextPos[limb];
      }
    }

    timeNextHitInstruction[limb] = song.getTimeNextHit(limb) - robot.getHitTime(limb, currentPosition, song.getVelNextHit(limb));
    nextInstruction[limb] = HIT;
    // We inmmediately go the the rest state of the next posiion
    robot.rest(limb, nextPos[limb]);
  }
}

void managePosInstruction(byte limb) {
  robot.goToPos(limb, nextPos[limb]);
  moveLimb[limb] = false;
}