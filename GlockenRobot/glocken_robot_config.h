#ifndef Glocken_robot_config_h
#define Glocken_robot_config_h

#define LEFT_ARM_GL 0
#define RIGHT_ARM_GL 1
#define HEAD_GL 2

#define NB_HIT_JOINTS_GL 3
#define NB_POS_JOINTS_GL 3

#define NB_POS_LA_GL 8
#define NB_POS_RA_GL 8
#define NB_POS_HD_GL 3

#define C00L 0
#define CS0L 1
#define D00L 2
#define DS0L 3
#define E00L 4
#define F00L 5
#define FS0L 6
#define G00L 7

#define GS0R 0
#define A00R 1
#define AS0R 2
#define B00R 3
#define C01R 4
#define CS1R 5
#define D01R 6
#define DS1R 7

#define HDLF 0
#define HDCN 1
#define HDRG 2

const signed char _dirLAGl = +1;
const signed char _dirRAGl = -1;
const signed char _dirHdGl = +1;

const byte _hitAngleLAGl = 145;
const byte _restAngleLAGl = 130;

const byte _hitAngleRAGl = 40;
const byte _restAngleRAGl = 60;

const byte _hitAngleHdGl = 125;
const byte _restAngleHdGl = 105;

// Angles for the left arm
const byte _posAngleC00L = 172;
const byte _posAngleCS0L = 155;
const byte _posAngleD00L = 137;
const byte _posAngleDS0L = 121;
const byte _posAngleE00L = 106;
const byte _posAngleF00L = 85;
const byte _posAngleFS0L = 71;
const byte _posAngleG00L = 53;

// Angles for the right arm
const byte _posAngleG00R = 113;
const byte _posAngleGS0R = 98;
const byte _posAngleA00R = 80;
const byte _posAngleAS0R = 61;
const byte _posAngleB00R = 43;
const byte _posAngleC01R = 26;
const byte _posAngleCS1R = 0;
const byte _posAngleD01R = 0;


// Angles for the head
const byte _posAngleHdL = 110;
const byte _posAngleHdC = 90;
const byte _posAngleHdR = 70;

const float _wServoGl = 0.35;

#endif
