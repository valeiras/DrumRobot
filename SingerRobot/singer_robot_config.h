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

#define OFFG 0
#define C03G 1
#define CS3G 2
#define D03G 3
#define DS3G 4
#define E03G 5
#define F03G 6
#define FS3G 7
#define G03G 8
#define GS3G 9
#define A03G 10
#define AS3G 11
#define B03G 12
#define C04G 13
#define CS4G 14
#define D04G 15
#define DS4G 16
#define E04G 17
#define F04G 18
#define FS4G 19
#define G04G 20
#define GS4G 21
#define A04G 22
#define AS4G 23
#define B04G 24

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