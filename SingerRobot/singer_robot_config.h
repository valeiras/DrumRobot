#ifndef Singer_robot_config__h
#define Singer_robot_config__h

#define FREQ_C02 65
#define FREQ_CS2 69
#define FREQ_D02 73
#define FREQ_DS2 78
#define FREQ_E02 82
#define FREQ_F02 87
#define FREQ_FS2 92
#define FREQ_G02 98
#define FREQ_GS2 104
#define FREQ_A02 110
#define FREQ_AS2 117
#define FREQ_B02 123
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
#define FREQ_E04 333
#define FREQ_F04 349
#define FREQ_FS4 370
#define FREQ_G04 392
#define FREQ_GS4 415
#define FREQ_A04 440
#define FREQ_AS4 466
#define FREQ_B04 494

#define OFFS 0
#define C02S 1
#define CS2S 2
#define D02S 3
#define DS2S 4
#define E02S 5
#define F02S 6
#define FS2S 7
#define G02S 8
#define GS2S 9
#define A02S 10
#define AS2S 11
#define B02S 12
#define C03S 13
#define CS3S 14
#define D03S 15
#define DS3S 16
#define E03S 17
#define F03S 18
#define FS3S 19
#define G03S 20
#define GS3S 21
#define A03S 22
#define AS3S 23
#define B03S 24
#define C04S 25
#define CS4S 26
#define D04S 27
#define DS4S 28
#define E04S 29
#define F04S 30
#define FS4S 31
#define G04S 32
#define GS4S 33
#define A04S 34
#define AS4S 35
#define B04S 36

#define NOTE_OFF 0
#define NOTE_ON 1

#define SINGER_1 0
#define SINGER_2 1
#define SINGER_3 2
#define AUTOMATIC_SINGER 0

#define NB_SINGERS 3
#define NB_POS_JOINTS_SG 0
#define NB_NOTES_SG 37

#define DEFAULT_CLOSED_POS 180
#define DEFAULT_OPEN_POS 20
#define DEFAULT_VIBRATO_AMP 10

const float _wServoSg = 0.1;

#endif