#ifndef Glocken_robot_config_h
#define Glocken_robot_config_h

#define LEFT_ARM_GL 0
#define RIGHT_ARM_GL 1

#define NB_HIT_JOINTS_GL 2
#define NB_POS_JOINTS_GL 2

#define NB_POS_LA_GL 9
#define NB_POS_RA_GL 9

#define C00_GL 0
#define CS0_GL 1
#define D00_GL 2
#define DS0_GL 3
#define E00_GL 4
#define F00_GL 5
#define FS0_GL 6
#define G00_GL 7
#define GS0_GL 8

#define A00_GL 0
#define AS0_GL 1
#define B00_GL 2
#define C01_GL 3
#define CS1_GL 4
#define D01_GL 5
#define DS1_GL 6
#define E01_GL 7
#define F01_GL 8

const signed char _dirLAGl = +1;
const signed char _dirRAGl = -1;

const byte _hitAngleLAGl = 70;
const byte _restAngleLAGl = 60;

const byte _hitAngleRAGl = 60;
const byte _restAngleRAGl = 70;

// Angles for the left arm
const byte _posAngleC00 = 0;
const byte _posAngleCS0 = 0;
const byte _posAngleD00 = 0;
const byte _posAngleDS0 = 0;
const byte _posAngleE00 = 0;
const byte _posAngleF00 = 0;
const byte _posAngleFS0 = 0;
const byte _posAngleG00 = 0;
const byte _posAngleGS0 = 0;

// Angles for the right arm
const byte _posAngleA00 = 0;
const byte _posAngleAS0 = 0;
const byte _posAngleB00 = 0;
const byte _posAngleC01 = 0;
const byte _posAngleCS1 = 0;
const byte _posAngleD01 = 0;
const byte _posAngleDS1 = 0;
const byte _posAngleE01 = 0;
const byte _posAngleF01 = 0;

const float _wServoGl = 0.6;

#endif
