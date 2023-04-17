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
const signed char _dirHdDr = +1;

// Head
const byte _hitAngleHD = 70;
const byte _restAngleHD = 100;
const byte _posAngleHD = 0;

// Right leg, position 0: base drum
const byte _hitAngleBD = 75;
const byte _restAngleBD = 95;
const byte _posAngleBD = 0;

// Left arm, position 0: HH-Snare
const byte _hitAngleHH = 70;
const byte _restAngleHH = 55;

// Left arm, positions 1: Sn-Sn
const byte _hitAngleSn1L = 70;
const byte _restAngleSn1L = 55;

// Left arm, positions 1: Sn-Sn
const byte _hitAngleSn2L = 75;
const byte _restAngleSn2L = 60;

// Right arm, position 0 and 1: Snare
const byte _hitAngleSn1R = 75;
const byte _restAngleSn1R = 95;

// Right arm, position 0 and 1: Snare
const byte _hitAngleSn2R = 75;
const byte _restAngleSn2R = 95;

// _Right arm, position 2: Crash
const byte _hitAngleCr = 77;
const byte _restAngleCr = 97;

// Positions for left and right arms
const byte _posAngleHHSn = 90;
const byte _posAngleSnSn = 78;
const byte _posAngleSnCr = 65;

// InactiveAngles
const byte _inactiveAngleLADr = 40;
const byte _inactiveAngleRADr = 110;
const byte _inactiveAngleRLDr = 100;
const byte _inactiveAngleHdDr = 90;

const float _wServoDr = 0.3;

#endif
