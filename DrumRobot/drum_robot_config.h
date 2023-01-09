#ifndef Drum_robot_config_h
#define Drum_robot_config_h

#define LEFT_ARM_DR 0
#define RIGHT_ARM_DR 1
#define RIGHT_LEG_DR 2

#define NB_HIT_JOINTS_DR 3
#define NB_POS_JOINTS_DR 2

#define NB_POS_LA_DR 3
#define NB_POS_RA_DR 3
#define NB_POS_RL_DR 1

#define BDRU 0
#define STCK 0
#define HHAT 1
#define SNLT 2
#define SNRG 1
#define CRSH 2

const signed char _dirRLDr = -1;
const signed char _dirLADr = +1;
const signed char _dirRADr = -1;

// Right leg, position 0: base drum
const byte _hitAngleBD = 140;
const byte _restAngleBD = 160;
const byte _posAngleBD = 0;

// Left arm, position 0: Sticks
const byte _hitAngleSticksLeft = 95;
const byte _restAngleSticksLeft = 80;
const byte _posAngleSticksLeft = 0;

// Left arm, position 1: HH
const byte _hitAngleHH = 110;
const byte _restAngleHH = 100;
const byte _posAngleHH = 50;

// Left arm, position 2: Snare
const byte _hitAngleSnLeft = 135;
const byte _restAngleSnLeft = 115;
const byte _posAngleSnLeft = 10;

// Right arm, position 0: Sticks
const byte _hitAngleSticksRight = 125;
const byte _restAngleSticksRight = 105;
const byte _posAngleSticksRight = 50;

// Right arm, position 1:
const byte _hitAngleSnRight = 82;
const byte _restAngleSnRight = 93;
const byte _posAngleSnRight = 40;

// _Right arm, position 2:
const byte _hitAngleCrash = 100;
const byte _restAngleCrash = 120;
const byte _posAngleCrash = 15;

const float _wServoDr = 0.6;

#endif
