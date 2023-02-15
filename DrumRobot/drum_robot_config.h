#ifndef Drum_robot_config_h
#define Drum_robot_config_h

#define LEFT_ARM_DR 0
#define RIGHT_ARM_DR 1
#define RIGHT_LEG_DR 2
#define HEAD_DR 3

#define NB_HIT_JOINTS_DR 4
#define NB_POS_JOINTS_DR 2

#define NB_POS_LA_DR 3
#define NB_POS_RA_DR 3
#define NB_POS_RL_DR 1
#define NB_POS_HD_DR 1

#define HEAD 0
#define BDRU 0
#define HHSN 0
#define SNSN 1
#define SNCR 2

const signed char _dirRLDr = -1;
const signed char _dirLADr = +1;
const signed char _dirRADr = -1;
const signed char _dirHead = +1;

// Head
const byte _hitAngleHD = 70;
const byte _restAngleHD = 110;
const byte _posAngleHD = 0;

// Right leg, position 0: base drum
const byte _hitAngleBD = 70;
const byte _restAngleBD = 95;
const byte _posAngleBD = 0;

// Left arm, position 0: HH-Snare
const byte _hitAngleHH = 110;
const byte _restAngleHH = 100;

// Left arm, positions 1 and 2: Snare
const byte _hitAngleSnL = 125;
const byte _restAngleSnL = 105;

// Right arm, position 0 and 1: Snare
const byte _hitAngleSnR = 105;
const byte _restAngleSnR = 85;

// _Right arm, position 2: Crash
const byte _hitAngleCr = 90;
const byte _restAngleCr = 110;

// Positions for left and right arms
const byte _posAngleHHSn = 150;
const byte _posAngleSnSn = 125;
const byte _posAngleSnCr = 90;

const float _wServoDr = 0.35;

#endif
