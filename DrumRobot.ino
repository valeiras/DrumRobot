#include <Servo.h>
#include "drum_robot.h"
#include "drum_song.h"
#include "robot_config.h"

#define BD_HIT_PIN 5
#define RIGHT_HIT_PIN 6
#define LEFT_HIT_PIN 9
#define RIGHT_POS_PIN 10
#define LEFT_POS_PIN 11

#define ANALOG_MIN 0
#define ANALOG_MAX 1023

unsigned int initialDelay = 1000;
unsigned long ellapsedTime;

unsigned long timeNextHitInstruction[NB_HIT_JOINTS], timeNextPosInstruction[NB_POS_JOINTS];
byte nextInstruction[NB_HIT_JOINTS];  // Indicates wheter next instruction is hit or rest
bool moveLimb[NB_POS_JOINTS];
byte nextPos[NB_POS_JOINTS];

unsigned long initTime;
unsigned short bpm = 110;

bool printOutput = true;
bool simulation = true;
bool variableBpm = false;

int minBpm = 60;
int maxBpm = 150;

DrumRobot robot;
DrumSong song;

void setup() {
  Serial.begin(9600);

  // -------------------------------------------------------- Pattern setting ----------------------------------------------------------
  song = DrumSong();
  song.createPredefinedPatterns(BASIC_RYTHM_WO_ACC, false);

  if (printOutput) {
    song.printPatterns();
  }

  if (variableBpm) {
    int sensorValue = analogRead(A0);
    bpm = map(sensorValue, ANALOG_MIN, ANALOG_MAX, minBpm, maxBpm);
    if (printOutput) {
      Serial.println(bpm);
    }
  }

  robot.attachServos(BD_HIT_PIN, RIGHT_HIT_PIN, LEFT_HIT_PIN, RIGHT_POS_PIN, LEFT_POS_PIN);
  robot.setupLimbParams(0.3, _dirRightLeg, _dirLeftArm, _dirRightArm,
                        _hitAngle_BD, _restAngle_BD, _posAngle_BD,
                        _hitAngleSticksLeft, _restAngleSticksLeft, _posAngleSticksLeft,
                        _hitAngleHH, _restAngleHH, _posAngleHH,
                        _hitAngleSnLeft, _restAngleSnLeft, _posAngleSnLeft,
                        _hitAngleSticksRight, _restAngleSticksRight, _posAngleSticksRight,
                        _hitAngleSnRight, _restAngleSnRight, _posAngleSnRight,
                        _hitAngleCrash, _restAngleCrash, _posAngleCrash);

  initTime = millis();
  
  song.setBpm(bpm);
  song.setInitialTime(initTime + initialDelay);

  for (unsigned int limb = 0; limb < NB_POS_JOINTS; limb++) {
    timeNextPosInstruction[limb] = 0;
    moveLimb[limb] = false;
  }

  for (unsigned int limb = 0; limb < NB_HIT_JOINTS; limb++) {
    song.computeNextHit(limb, printOutput);
    nextInstruction[limb] = HIT;

    if (limb < NB_POS_JOINTS) {
      nextPos[limb] = song.getPosNextHit(limb);
      timeNextHitInstruction[limb] = song.getTimeNextHit(limb) - robot.getHitTime(limb, nextPos[limb], song.getVelNextHit(limb), printOutput);
      robot.rest(limb, nextPos[limb]);
      robot.goToPos(limb, nextPos[limb]);
    } else {
      timeNextHitInstruction[limb] = song.getTimeNextHit(limb) - robot.getHitTime(limb, 0, song.getVelNextHit(limb), printOutput);
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

  for (unsigned int limb = 0; limb < NB_HIT_JOINTS; limb++) {
    if (ellapsedTime >= timeNextHitInstruction[limb]) {
      manageHitInstruction(limb, ellapsedTime);
    }

    if (limb < NB_POS_JOINTS && moveLimb[limb] && ellapsedTime >= timeNextPosInstruction[limb]) {
      managePosInstruction(limb);
    }
  }
}


void manageHitInstruction(byte limb, unsigned long currTime) {
  byte currentPosition = limb < NB_POS_JOINTS ? nextPos[limb] : 0;

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
      Serial.println(robot.getHitTime(limb, currentPosition, song.getVelNextHit(limb), false));
    }

    timeNextHitInstruction[limb] += robot.getHitTime(limb, currentPosition, song.getVelNextHit(limb), printOutput);
    nextInstruction[limb] = REST;
  }

  else if (nextInstruction[limb] == REST) {
    song.computeNextHit(limb, printOutput);

    if (limb < NB_POS_JOINTS) {
      // We check if we need to move
      nextPos[limb] = song.getPosNextHit(limb);

      if (currentPosition != nextPos[limb]) {
        moveLimb[limb] = true;
        timeNextPosInstruction[limb] = currTime + abs(robot.getHitAngle(limb, currentPosition, song.getVelNextHit(limb)) - robot.getRestAngle(limb, nextPos[limb])) / robot.getServoSpeed();
        currentPosition = nextPos[limb];
      }
    }

    timeNextHitInstruction[limb] = song.getTimeNextHit(limb) - robot.getHitTime(limb, currentPosition, song.getVelNextHit(limb), printOutput);
    nextInstruction[limb] = HIT;
    // We inmmediately go the the rest state of the next posiion
    robot.rest(limb, nextPos[limb]);
  }
}

void managePosInstruction(byte limb) {
  robot.goToPos(limb, nextPos[limb]);
  moveLimb[limb] = false;
}
