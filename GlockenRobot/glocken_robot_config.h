#ifndef Glocken_robot_config_h
#define Glocken_robot_config_h

#define LEFT_ARM_GL 0
#define RIGHT_ARM_GL 1

#define NB_HIT_JOINTS_GL 2
#define NB_POS_JOINTS_GL 2

#define NB_POS_LA_GL 10
#define NB_POS_RA_GL 8

#define C00G 0
#define CS0G 1
#define D00G 2
#define DS0G 3
#define E00G 4
#define F00G 5
#define FS0G 6
#define G00G 7
#define GS0G 8
#define A00G 9

#define AS0G 0
#define B00G 1
#define C01G 2
#define CS1G 3
#define D01G 4
#define DS1G 5
#define E01G 6
#define F01G 7

const signed char _dirLAGl = +1;
const signed char _dirRAGl = -1;

const byte _hitAngleLAGl = 122;
const byte _restAngleLAGl = 107;

const byte _hitAngleRAGl = 68;
const byte _restAngleRAGl = 83;

// Angles for the left arm
const byte _posAngleC00 = 180;
const byte _posAngleCS0 = 165;
const byte _posAngleD00 = 145;
const byte _posAngleDS0 = 128;
const byte _posAngleE00 = 110;
const byte _posAngleF00 = 85;
const byte _posAngleFS0 = 70;
const byte _posAngleG00 = 48;
const byte _posAngleGS0 = 33;
const byte _posAngleA00 = 18;

// Angles for the right arm
const byte _posAngleAS0 = 150;
const byte _posAngleB00 = 130;
const byte _posAngleC01 = 110;
const byte _posAngleCS1 = 90;
const byte _posAngleD01 = 70;
const byte _posAngleDS1 = 50;
const byte _posAngleE01 = 30;
const byte _posAngleF01 = 15;

const float _wServoGl = 0.6;

#endif
