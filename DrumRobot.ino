#include <Servo.h>
#include "drum_robot.h"
#include "drum_song_sheets.h"
#include "robot_config.h"

#define BD_HIT_PIN 9
#define RIGHT_HIT_PIN 10
#define LEFT_HIT_PIN 11
#define RIGHT_POS_PIN 5
#define LEFT_POS_PIN 6

#define REST 0
#define HIT 1

unsigned int initialDelayMs =  1000;
unsigned long ellapsedTime;

unsigned long timeNextHitInstructionRightLeg, timeNextHitInstructionLeftArm, timeNextHitInstructionRightArm;
unsigned long timeNextPosInstructionLeftArm, timeNextPosInstructionRightArm;
bool nextInstructionRightLeg, nextInstructionLeftArm, nextInstructionRightArm;          // Indicates wheter next instruction is hit or rest
bool moveLeftArm, moveRightArm; 
byte currPosLeftArm, currPosRightArm;

unsigned long initTime;
unsigned short bpm = 150;

DrumRobot robot;
BasicDrumSong song; 

void setup() {
  Serial.begin(9600);

  song.initializeBlankPatterns(1, 1);
  
  song.setQuarterHit(RIGHT_LEG, 0, 1);
  song.setQuarterHit(RIGHT_LEG, 0, 3);
  song.setQuarterHit(RIGHT_ARM, 0, 2);
  song.setQuarterPos(RIGHT_ARM, 0, 2, 1);
  song.setQuarterHit(RIGHT_ARM, 0, 4);
  song.setQuarterPos(RIGHT_ARM, 0, 4, 1);
  song.setQuaverHit(LEFT_ARM, 0, 1);
  song.setQuaverPos(LEFT_ARM, 0, 1, 1);
  song.setQuaverHit(LEFT_ARM, 0, 2);
  song.setQuaverPos(LEFT_ARM, 0, 2, 1);
  song.setQuaverHit(LEFT_ARM, 0, 3);
  song.setQuaverPos(LEFT_ARM, 0, 3, 1);
  song.setQuaverHit(LEFT_ARM, 0, 4);
  song.setQuaverPos(LEFT_ARM, 0, 4, 1);
  song.setQuaverHit(LEFT_ARM, 0, 5);
  song.setQuaverPos(LEFT_ARM, 0, 5, 1);
  song.setQuaverHit(LEFT_ARM, 0, 6);
  song.setQuaverPos(LEFT_ARM, 0, 6, 1);
  song.setQuaverHit(LEFT_ARM, 0, 7);
  song.setQuaverPos(LEFT_ARM, 0, 7, 1);
  song.setQuaverHit(LEFT_ARM, 0, 8);
  song.setQuaverPos(LEFT_ARM, 0, 8, 2);

  byte pattSeq[1] = {0};
  song.setPatternSequence(pattSeq);
  
  song.printPosPattern(LEFT_ARM, 0);
  song.printHitPattern(LEFT_ARM, 0);
  
  song.setBpm(bpm);
  
  robot.attachServos(BD_HIT_PIN, RIGHT_HIT_PIN, LEFT_HIT_PIN, RIGHT_POS_PIN, LEFT_POS_PIN);
  robot.setupLimbParams(0.3, HIT_ANGLE_BD, REST_ANGLE_BD, POS_ANGLE_BD, 
                        HIT_ANGLE_STICKS_LEFT, REST_ANGLE_STICKS_LEFT, POS_ANGLE_STICKS_LEFT, 
                        HIT_ANGLE_HH, REST_ANGLE_HH, POS_ANGLE_HH,
                        HIT_ANGLE_SN_LEFT, REST_ANGLE_SN_LEFT, POS_ANGLE_SN_LEFT, 
                        HIT_ANGLE_STICKS_RIGHT, REST_ANGLE_STICKS_RIGHT, POS_ANGLE_STICKS_RIGHT, 
                        HIT_ANGLE_SN_RIGHT, REST_ANGLE_SN_RIGHT, POS_ANGLE_SN_RIGHT, 
                        HIT_ANGLE_CRASH, REST_ANGLE_CRASH, POS_ANGLE_CRASH);
                    
  initTime = millis();

  nextInstructionRightLeg = HIT;
  nextInstructionRightArm = HIT;
  nextInstructionLeftArm = HIT;
  
  // We set the current position as the first position of the first pattern
  currPosLeftArm = song.getPosNextHit(LEFT_ARM);
  currPosRightArm = song.getPosNextHit(RIGHT_ARM);

  timeNextHitInstructionRightLeg = initTime + song.getTimeToNextHit(RIGHT_LEG) - robot.getHitTime(RIGHT_LEG, 0);
  timeNextHitInstructionLeftArm = initTime + song.getTimeToNextHit(LEFT_ARM) -  robot.getHitTime(LEFT_ARM, currPosLeftArm);
  timeNextHitInstructionRightArm = initTime + song.getTimeToNextHit(RIGHT_ARM) - robot.getHitTime(RIGHT_ARM, currPosRightArm);

  timeNextPosInstructionLeftArm = 0;
  timeNextPosInstructionRightArm = 0;
  moveLeftArm = false;
  moveRightArm = false;

  robot.rest(RIGHT_LEG, 0);
  robot.goToPos(LEFT_ARM, currPosLeftArm);
  robot.rest(LEFT_ARM, currPosLeftArm);
  robot.goToPos(RIGHT_ARM, currPosRightArm);
  robot.rest(RIGHT_ARM, currPosRightArm);

//  while(true){
//    if(Serial.available() > 0){
//      long hitAngle = Serial.parseInt();
//      if(hitAngle > 0){
//        robot.goToHitAngle(RIGHT_ARM, hitAngle);
//        //robot.goToPosAngle(LEFT_ARM, posAngle);
//        Serial.println(hitAngle);
//      }
//    }
//  }
}

void loop() {
  ellapsedTime = millis() - initTime;  

  if(ellapsedTime>=timeNextHitInstructionRightLeg){
    manageHitInstruction(RIGHT_LEG, ellapsedTime, timeNextHitInstructionRightLeg, nextInstructionRightLeg);
  }
   
  if(ellapsedTime>=timeNextHitInstructionLeftArm){ 
    manageHitAndPosInstruction(LEFT_ARM, ellapsedTime, timeNextHitInstructionLeftArm, nextInstructionLeftArm, timeNextPosInstructionLeftArm, ellapsedTime, currPosLeftArm, moveLeftArm);
  }

  if(ellapsedTime>=timeNextHitInstructionRightArm){
    manageHitAndPosInstruction(RIGHT_ARM, ellapsedTime, timeNextHitInstructionRightArm, nextInstructionRightArm, timeNextPosInstructionRightArm, ellapsedTime, currPosRightArm, moveRightArm);
  }

  if(moveLeftArm && ellapsedTime>=timeNextPosInstructionLeftArm){
    robot.goToPos(LEFT_ARM, currPosLeftArm);
    moveLeftArm = false;
  }

  if(moveRightArm && ellapsedTime>=timeNextPosInstructionRightArm){
    robot.goToPos(RIGHT_ARM, currPosRightArm);
    moveRightArm = false;
  }

/*
  Serial.print("Servo 1: ");
  Serial.print(posServoLeftArm.read());

  Serial.print(", Servo 2: ");
  Serial.println(posServoRightArm.read());
*/
}

void manageHitInstruction(byte limb, unsigned long ellTime, unsigned long &timeNextHitInstruction, bool &nextInstruction){
  if(nextInstruction == HIT){
    robot.hit(limb, 0);
    timeNextHitInstruction += robot.getHitTime(limb, 0);
    nextInstruction = REST;
  }
  
  else if(nextInstruction == REST){
    timeNextHitInstruction += song.getTimeToNextHit(limb) - robot.getHitTime(limb, 0);
    nextInstruction = HIT;
    robot.rest(limb, 0);
  }
}

void manageHitAndPosInstruction(byte limb, unsigned long ellTime, unsigned long &timeNextHitInstruction, bool &nextInstruction, unsigned long &timeNextPosInstruction, unsigned long currTime, byte &currPos, bool &moveLimb){
  if(nextInstruction == HIT){
    robot.hit(limb, currPos);
    timeNextHitInstruction += robot.getHitTime(limb, currPos);
    nextInstruction = REST;
  }
  
  else if(nextInstruction == REST){
    // We get the time to the next hit (thus updating the index)
    unsigned long timeToNextHit = song.getTimeToNextHit(limb);
    
    // We check if we need to move
    byte nextPos = song.getPosNextHit(limb);

    if(currPos != nextPos){
      moveLimb = true;
      timeNextPosInstruction = currTime + abs(robot.getHitAngle(limb, currPos) - robot.getRestAngle(limb, nextPos))/robot.getServoSpeed();
      currPos = nextPos;      
    }
    
    // We inmmediately go the the rest state of the next posiion
    robot.rest(limb, currPos);
  
    timeNextHitInstruction += timeToNextHit - robot.getHitTime(limb, currPos);
    nextInstruction = HIT;
  }
}

void managePosInstruction(byte limb, byte &currPos, bool &moveLimb){

}
