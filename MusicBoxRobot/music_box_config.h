#ifndef Music_box_config_h
#define Music_box_config_h

#define SENSOR_MIN 0
#define SENSOR_MAX 706

#define DEGREES_PER_SEMIQUAVER 3.21
#define SENSOR_POINTS_PER_SEMIQUAVER 33.77

#define START_POSITION 123

#define NB_HIT_JOINTS_MB 2
#define NB_POS_JOINTS_MB 0
#define BITS_FOR_POS_MB 0

#define FOOT_MB 0
#define HEAD_MB 1

#define BITS_FOR_POS_MB 0

#define HITP 0

const float _wServoMB = 0.6;

const signed char _dirFootMB = -1;
const signed char _dirHeadMB = +1;

// Foot
const byte _hitAngleFootMB = 50;
const byte _restAngleFootMB = 95;

// Head
const byte _hitAngleHeadMB = 50;
const byte _restAngleHeadMB = 95;

#endif