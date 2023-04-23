#ifndef Singer_robot_config__h
#define Singer_robot_config__h

#define FREQ_C03 131
#define FREQ_CS3 139
#define FREQ_D03 147
#define FREQ_DS3 156
#define FREQ_E03 165
#define FREQ_F03 175
#define FREQ_FS3 185
#define FREQ_G03 196
#define FREQ_GS3 208
#define FREQ_A03 220
#define FREQ_AS3 233
#define FREQ_B03 247
#define FREQ_C04 262
#define FREQ_CS4 277
#define FREQ_D04 294
#define FREQ_DS4 311
#define FREQ_E04 330
#define FREQ_F04 349
#define FREQ_FS4 370
#define FREQ_G04 392
#define FREQ_GS4 415
#define FREQ_A04 440
#define FREQ_AS4 466
#define FREQ_B04 494

#define OFF_SG 0
#define C03_SG 1
#define CS3_SG 2
#define D03_SG 3
#define DS3_SG 4
#define E03_SG 5
#define F03_SG 6
#define FS3_SG 7
#define G03_SG 8
#define GS3_SG 9
#define A03_SG 10
#define AS3_SG 11
#define B03_SG 12
#define C04_SG 13
#define CS4_SG 14
#define D04_SG 15
#define DS4_SG 16
#define E04_SG 17
#define F04_SG 18
#define FS4_SG 19
#define G04_SG 20
#define GS4_SG 21
#define A04_SG 22
#define AS4_SG 23
#define B04_SG 24

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