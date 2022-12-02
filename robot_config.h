#ifndef Robot_config_h
#define Robot_config_h

#define RIGHT_LEG 0
#define LEFT_ARM 1
#define RIGHT_ARM 2

#define REST 0
#define HIT 1

#define BD 0
#define STICK 0
#define HH 1
#define SN_LEFT 2
#define SN_RIGHT 1
#define CRASH 2
 
const byte _nbPosRightLeg = 1;
const byte _nbPosLeftArm = 3;
const byte _nbPosRightArm = 3;

const byte _hitAngle_BD = 50;
const byte _restAngle_BD = 80;
const byte _posAngle_BD = 0;

// Left arm, position 0: Sticks
const byte _hitAngleSticksLeft = 80;
const byte _restAngleSticksLeft = 60;
const byte _posAngleSticksLeft = 0;

// Left arm, position 1: HH
const byte _hitAngleHH = 85;
const byte _restAngleHH = 70;
const byte _posAngleHH = 60;

// Left arm, position 2: Snare
const byte _hitAngleSnLeft = 115;
const byte _restAngleSnLeft = 70;
const byte _posAngleSnLeft = 15;

// Right arm, position 0: Sticks
const byte _hitAngleSticksRight = 120;
const byte _restAngleSticksRight = 110;
const byte _posAngleSticksRight = 50;

// Right arm, position 1:
const byte _hitAngleSnRight = 75;
const byte _restAngleSnRight = 100;
const byte _posAngleSnRight = 35;

// _Right arm, position 2:
const byte _hitAngleCrash = 100;
const byte _restAngleCrash = 120;
const byte _posAngleCrash = 5;

const float _wServo = 0.6;

#endif
