#ifndef Singer_robot_config__h
#define Singer_robot_config__h

#define FREQ_C03 130.81
#define FREQ_CS3 138.60
#define FREQ_D03 146.83
#define FREQ_DS3 155.56
#define FREQ_E03 164.81
#define FREQ_F03 174.61
#define FREQ_FS3 185.00
#define FREQ_G03 196.00
#define FREQ_GS3 207.65
#define FREQ_A03 220.00
#define FREQ_AS3 233.08
#define FREQ_B03 246.94
#define FREQ_C04 261.63
#define FREQ_CS4 277.18
#define FREQ_D04 293.66
#define FREQ_DS4 311.13
#define FREQ_E04 329.63
#define FREQ_F04 349.23
#define FREQ_FS4 370.00
#define FREQ_G04 392.00
#define FREQ_GS4 415.30
#define FREQ_A04 440.00
#define FREQ_AS4 466.16
#define FREQ_B04 493.83

#define OFFS 0
#define C03S 1
#define CS3S 2
#define D03S 3
#define DS3S 4
#define E03S 5
#define F03S 6
#define FS3S 7
#define G03S 8
#define GS3S 9
#define A03S 10
#define AS3S 11
#define B03S 12
#define C04S 13
#define CS4S 14
#define D04S 15
#define DS4S 16
#define E04S 17
#define F04S 18
#define FS4S 19
#define G04S 20
#define GS4S 21
#define A04S 22
#define AS4S 23
#define B04S 24

#define NOTE_OFF 0
#define NOTE_ON 1

#define SINGER_1 0
#define SINGER_2 1
#define SINGER_3 2

#define NB_SINGERS 3
#define NB_POS_JOINTS_SG 0
#define NB_NOTES_SG 25

#define DEFAULT_CLOSED_POS 180
#define DEFAULT_OPEN_POS 20
#define DEFAULT_VIBRATO_AMP 10

const float _wServoSg = 0.1;

#endif