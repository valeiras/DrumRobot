#ifndef Robot_config_h
#define Robot_config_h

#define LEFT_ARM 0
#define RIGHT_ARM 1
#define RIGHT_LEG 2

#define NB_HIT_JOINTS 3
#define NB_POS_JOINTS 2

#define NB_POS_RIGHT_LEG 1
#define NB_POS_LEFT_ARM 3
#define NB_POS_RIGHT_ARM 3

//#define REST_INST 0
#define HIT 1
#define REST 255

#define BDRU 0
#define STCK 0
#define HHAT 1
#define SNLT 2
#define SNRG 1
#define CRSH 2

const signed char _dirRightLeg = -1;
const signed char _dirLeftArm = +1;
const signed char _dirRightArm = -1;

// Right leg, position 0: base drum
const byte _hitAngle_BD = 59;
const byte _restAngle_BD = 70;
const byte _posAngle_BD = 0;

// Left arm, position 0: Sticks
const byte _hitAngleSticksLeft = 80;
const byte _restAngleSticksLeft = 60;
const byte _posAngleSticksLeft = 0;

// Left arm, position 1: HH
const byte _hitAngleHH = 90;
const byte _restAngleHH = 70;
const byte _posAngleHH = 60;

// Left arm, position 2: Snare
const byte _hitAngleSnLeft = 110;
const byte _restAngleSnLeft = 95;
const byte _posAngleSnLeft = 20;

// Right arm, position 0: Sticks
const byte _hitAngleSticksRight = 120;
const byte _restAngleSticksRight = 110;
const byte _posAngleSticksRight = 50;

// Right arm, position 1:
const byte _hitAngleSnRight = 87;
const byte _restAngleSnRight = 98;
const byte _posAngleSnRight = 35;

// _Right arm, position 2:
const byte _hitAngleCrash = 110;
const byte _restAngleCrash = 130;
const byte _posAngleCrash = 5;

const float _wServo = 0.6;

#endif
