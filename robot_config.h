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
const byte _hitAngleSticksLeft = 40;
const byte _restAngleSticksLeft = 50;
const byte _posAngleSticksLeft = 30;

// Left arm, position 1: HH
const byte _hitAngleHH = 85;
const byte _restAngleHH = 70;
const byte _posAngleHH = 55;

// Left arm, position 2: Snare
const byte _hitAngleSnLeft = 110;
const byte _restAngleSnLeft = 85;
const byte _posAngleSnLeft = 0;

// Right arm, position 0: Sticks
const byte _hitAngleSticksRight = 120;
const byte _restAngleSticksRight = 100;
const byte _posAngleSticksRight = 0;

// Right arm, position 1:
const byte _hitAngleSnRight = 70;
const byte _restAngleSnRight = 100;
const byte _posAngleSnRight = 0;

// _Right arm, position 2:
const byte _hitAngleCrash = 90;
const byte _restAngleCrash = 120;
const byte _posAngleCrash = 100;

const float _wServo = 0.6;

#endif
