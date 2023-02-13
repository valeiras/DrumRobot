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

const byte _hitAngleLAGl = 120;
const byte _restAngleLAGl = 105;

const byte _hitAngleRAGl = 70;
const byte _restAngleRAGl = 85;

// Angles for the left arm
const byte _posAngleC00 = 168;
const byte _posAngleCS0 = 146;
const byte _posAngleD00 = 130;
const byte _posAngleDS0 = 114;
const byte _posAngleE00 = 97;
const byte _posAngleF00 = 72;
const byte _posAngleFS0 = 58;
const byte _posAngleG00 = 37;
const byte _posAngleGS0 = 19;
const byte _posAngleA00 = 0;

// Angles for the right arm
const byte _posAngleAS0 = 136;
const byte _posAngleB00 = 117;
const byte _posAngleC01 = 93;
const byte _posAngleCS1 = 71;
const byte _posAngleD01 = 49;
const byte _posAngleDS1 = 33;
const byte _posAngleE01 = 12;
const byte _posAngleF01 = 0;

const float _wServoGl = 0.6;

#endif
