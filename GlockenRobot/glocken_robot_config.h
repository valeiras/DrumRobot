#ifndef Glocken_robot_config_h
#define Glocken_robot_config_h

#define LEFT_ARM_GLOCK 0
#define RIGHT_ARM_GLOCK 1

#define NB_HIT_JOINTS_GLOCK 2
#define NB_POS_JOINTS_GLOCK 2

#define NB_POS_LAG 9
#define NB_POS_RAG 9

#define C00 0
#define CS0 1
#define D00 2
#define DS0 3
#define E00 4
#define F00 5
#define FS0 6
#define G00 7
#define GS0 8

#define A00 0
#define AS0 1
#define B00 2
#define C01 3
#define CS1 4
#define D01 5
#define DS1 6
#define E01 7
#define F01 8

const signed char _dirLAG = +1;
const signed char _dirRAG = -1;

const byte _hitAngleRAG = 60;
const byte _restAngleRAG = 70;

const byte _hitAngleLAG = 70;
const byte _restAngleLAG = 60;

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

const float _wServo = 0.6;

#endif
