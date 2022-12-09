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

unsigned int initialDelay =  1000;
unsigned long ellapsedTime;

unsigned long timeNextHitInstructionRightLeg, timeNextHitInstructionLeftArm, timeNextHitInstructionRightArm;
unsigned long timeNextPosInstructionLeftArm, timeNextPosInstructionRightArm;
bool nextInstructionRightLeg, nextInstructionLeftArm, nextInstructionRightArm;          // Indicates wheter next instruction is hit or rest
bool moveLeftArm, moveRightArm;
byte currPosLeftArm, currPosRightArm;

unsigned long initTime;
unsigned short bpm = 80;

bool printOutput = false;
bool simulation = false;
bool variableBpm = false;

int minBpm = 60;
int maxBpm = 150;

DrumRobot robot;
DrumSong song;

void setup() {
  Serial.begin(9600);

  // -------------------------------------------------------- Patter setting ----------------------------------------------------------
  song = DrumSong();
  song.createPredefinedPatterns(BASIC_RYTHM, printOutput);

  if (printOutput) {
    song.printPatterns();
  }

  if (variableBpm) {
    int sensorValue = analogRead(A0);
    bpm = map(sensorValue, ANALOG_MIN, ANALOG_MAX, minBpm, maxBpm);
    //Serial.println(bpm);
  }
  song.setBpm(bpm);

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

  nextInstructionRightLeg = HIT_INST;
  nextInstructionRightArm = HIT_INST;
  nextInstructionLeftArm = HIT_INST;

  timeNextHitInstructionRightLeg = initTime + initialDelay + song.getTimeToNextHit(RIGHT_LEG) - robot.getHitTime(RIGHT_LEG, 0, song.getVelNextHit(RIGHT_LEG), printOutput);
  timeNextHitInstructionLeftArm = initTime + initialDelay + song.getTimeToNextHit(LEFT_ARM) -  robot.getHitTime(LEFT_ARM, currPosLeftArm, song.getVelNextHit(LEFT_ARM), printOutput);
  timeNextHitInstructionRightArm = initTime + initialDelay + song.getTimeToNextHit(RIGHT_ARM) - robot.getHitTime(RIGHT_ARM, currPosRightArm, song.getVelNextHit(RIGHT_ARM), printOutput);

  // We set the current position as the first position of the first pattern
  currPosLeftArm = song.getPosNextHit(LEFT_ARM);
  currPosRightArm = song.getPosNextHit(RIGHT_ARM);

  if (printOutput) {
    Serial.print("Pos left arm: ");
    Serial.println(currPosLeftArm);
    Serial.print("Pos right arm: ");
    Serial.println(currPosRightArm);
  }

  timeNextPosInstructionLeftArm = 0;
  timeNextPosInstructionRightArm = 0;

  moveLeftArm = true;
  moveRightArm = true;

  robot.rest(RIGHT_LEG, 0);
  robot.goToPos(LEFT_ARM, currPosLeftArm);
  robot.rest(LEFT_ARM, currPosLeftArm);
  robot.goToPos(RIGHT_ARM, currPosRightArm);
  robot.rest(RIGHT_ARM, currPosRightArm);
}

void loop() {
  ellapsedTime = millis() - initTime;

  if (ellapsedTime >= timeNextHitInstructionRightLeg) {
    manageHitInstruction(RIGHT_LEG, ellapsedTime, timeNextHitInstructionRightLeg, nextInstructionRightLeg);
  }

  if (ellapsedTime >= timeNextHitInstructionLeftArm) {
    manageHitAndPosInstruction(LEFT_ARM, ellapsedTime, timeNextHitInstructionLeftArm, nextInstructionLeftArm, timeNextPosInstructionLeftArm, ellapsedTime, currPosLeftArm, moveLeftArm);
  }

  if (ellapsedTime >= timeNextHitInstructionRightArm) {
    manageHitAndPosInstruction(RIGHT_ARM, ellapsedTime, timeNextHitInstructionRightArm, nextInstructionRightArm, timeNextPosInstructionRightArm, ellapsedTime, currPosRightArm, moveRightArm);
  }

  if (moveLeftArm && ellapsedTime >= timeNextPosInstructionLeftArm) {
    robot.goToPos(LEFT_ARM, currPosLeftArm);
    moveLeftArm = false;
  }

  if (moveRightArm && ellapsedTime >= timeNextPosInstructionRightArm) {
    robot.goToPos(RIGHT_ARM, currPosRightArm);
    moveRightArm = false;
  }

  if (variableBpm) {
    int sensorValue = analogRead(A0);
    bpm = map(sensorValue, ANALOG_MIN, ANALOG_MAX, minBpm, maxBpm);
    //Serial.println(bpm);
    song.setBpm(bpm);
  }

}

void manageHitInstruction(byte limb, unsigned long ellTime, unsigned long &timeNextHitInstruction, bool &nextInstruction) {
  if (nextInstruction == HIT_INST) {
    if (simulation) {
      Serial.println("");
      Serial.print(robot.getPosName(limb, 0));
      Serial.print(" at time ");
      Serial.println(timeNextHitInstruction);

    }
    robot.hit(limb, 0, song.getVelNextHit(limb), printOutput);

    if (printOutput) {
      Serial.print("Hit time: ");
      Serial.println(robot.getHitTime(limb, 0, song.getVelNextHit(limb), false));
    }
    timeNextHitInstruction += robot.getHitTime(limb, 0, song.getVelNextHit(limb), printOutput);
    nextInstruction = REST_INST;
  }

  else if (nextInstruction == REST_INST) {
    timeNextHitInstruction += song.getTimeToNextHit(limb) - robot.getHitTime(limb, 0, song.getVelNextHit(limb), false);
    nextInstruction = HIT_INST;
    robot.rest(limb, 0);
  }
}

void manageHitAndPosInstruction(byte limb, unsigned long ellTime, unsigned long &timeNextHitInstruction, bool &nextInstruction, unsigned long &timeNextPosInstruction, unsigned long currTime, byte &currPos, bool &moveLimb) {
  if (nextInstruction == HIT_INST) {
    if (simulation) {
      Serial.println("");
      Serial.print(robot.getPosName(limb, currPos));
      Serial.print(" at time ");
      Serial.println(timeNextHitInstruction);
    }
    robot.hit(limb, currPos, song.getVelNextHit(limb), printOutput);

    if (printOutput) {
      Serial.print("Hit time: ");
      Serial.println(robot.getHitTime(limb, currPos, song.getVelNextHit(limb), false));
    }
    
    timeNextHitInstruction += robot.getHitTime(limb, currPos, song.getVelNextHit(limb), printOutput);
    nextInstruction = REST_INST;
  }

  else if (nextInstruction == REST_INST) {
    // We get the time to the next hit (thus updating the index)
    unsigned long timeToNextHit = song.getTimeToNextHit(limb);

    // We check if we need to move
    byte nextPos = song.getPosNextHit(limb);

    if (currPos != nextPos) {
      moveLimb = true;
      timeNextPosInstruction = currTime + abs(robot.getHitAngle(limb, currPos, song.getVelNextHit(limb)) - robot.getRestAngle(limb, nextPos)) / robot.getServoSpeed();
      currPos = nextPos;
    }

    // We inmmediately go the the rest state of the next posiion
    robot.rest(limb, currPos);

    timeNextHitInstruction += timeToNextHit - robot.getHitTime(limb, currPos, song.getVelNextHit(limb), false);
    nextInstruction = HIT_INST;
  }
}

void managePosInstruction(byte limb, byte &currPos, bool &moveLimb) {

}
