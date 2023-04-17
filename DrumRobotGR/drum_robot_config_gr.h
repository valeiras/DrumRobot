#ifndef Drum_robot_config_gr_h
#define Drum_robot_config_gr_h

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
const byte _hitAngleBD = 50;
const byte _restAngleBD = 95;
const byte _posAngleBD = 0;

// Left arm, position 0: Sticks
const byte _hitAngleSticksLeft = 90;
const byte _restAngleSticksLeft = 80;
const byte _posAngleSticksLeft = 115;

// Left arm, position 1: HH
const byte _hitAngleHH = 110;
const byte _restAngleHH = 100;
const byte _posAngleHH = 150;

// Left arm, position 2: Snare
const byte _hitAngleSnLeft = 125;
const byte _restAngleSnLeft = 105;
const byte _posAngleSnLeft = 125;

// Right arm, position 0: Sticks
const byte _hitAngleSticksRight = 105;
const byte _restAngleSticksRight = 85;
const byte _posAngleSticksRight = 60;

// Right arm, position 1:
const byte _hitAngleSnRight = 70;
const byte _restAngleSnRight = 85;
const byte _posAngleSnRight = 55;

// _Right arm, position 2:
const byte _hitAngleCrash = 90;
const byte _restAngleCrash = 110;
const byte _posAngleCrash = 30;

// InactiveAngles
const byte _inactiveAngleLADr = 40;
const byte _inactiveAngleRADr = 110;
const byte _inactiveAngleRLDr = 100;

const float _wServoDr = 0.6;

#endif
