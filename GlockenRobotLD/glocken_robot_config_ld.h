#ifndef Glocken_robot_config_ld_h
#define Glocken_robot_config_ld_h

#define LEFT_ARM_GL 0
#define RIGHT_ARM_GL 1
#define HEAD_GL 2

#define NB_HIT_JOINTS_GL 3
#define NB_POS_JOINTS_GL 3

#define NB_POS_LA_GL 8
#define NB_POS_RA_GL 6
#define NB_POS_HD_GL 3

#define C00L 0
#define CS0L 1
#define D00L 2
#define DS0L 3
#define E00L 4
#define F00L 5
#define FS0L 6
#define G00L 7

#define G00R 0
#define GS0R 1
#define A00R 2
#define AS0R 3
#define B00R 4
#define C01R 5

#define HDLF 0
#define HDCN 1
#define HDRG 2

const signed char _dirLAGl = +1;
const signed char _dirRAGl = -1;
const signed char _dirHdGl = +1;

const byte _hitAngleLAGl = 115;
const byte _restAngleLAGl = 100;

const byte _hitAngleRAGl = 60;
const byte _restAngleRAGl = 75;

const byte _hitAngleHdGl = 125;
const byte _restAngleHdGl = 105;

const byte _inactiveAngleLAGL = 80;
const byte _inactiveAngleRAGL = 90;
const byte _inactiveAngleHdGL = 100;

// Angles for the left arm
const byte _posAngleC00L = 148;
const byte _posAngleCS0L = 137;
const byte _posAngleD00L = 125;
const byte _posAngleDS0L = 112;
const byte _posAngleE00L = 99;
const byte _posAngleF00L = 85;
const byte _posAngleFS0L = 74;
const byte _posAngleG00L = 64;

// Angles for the right arm
const byte _posAngleG00R = 112;
const byte _posAngleGS0R = 99;
const byte _posAngleA00R = 83;
const byte _posAngleAS0R = 70;
const byte _posAngleB00R = 55;
const byte _posAngleC01R = 42;


// Angles for the head
const byte _posAngleHdL = 110;
const byte _posAngleHdC = 90;
const byte _posAngleHdR = 70;

const float _wServoGl = 0.35;

#endif
