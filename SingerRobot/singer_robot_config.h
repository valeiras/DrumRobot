#ifndef Singer_robot_config_h
#define Singer_robot_config_h

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

#define C03_SG 0
#define CS3_SG 1
#define D03_SG 2
#define DS3_SG 3
#define E03_SG 4
#define F03_SG 5
#define FS3_SG 6
#define G03_SG 7
#define GS3_SG 8
#define A03_SG 9
#define AS3_SG 10
#define B03_SG 11
#define C04_SG 12
#define CS4_SG 13
#define D04_SG 14
#define DS4_SG 15
#define E04_SG 16
#define F04_SG 17
#define FS4_SG 18
#define G04_SG 19
#define GS4_SG 20
#define A04_SG 21
#define AS4_SG 22
#define B04_SG 23

#define NOTE_OFF 0
#define NOTE_ON 1

#define NB_NOTES 24

#define SINGER_1 0
#define SINGER_2 1
#define SINGER_3 2

#define NB_SINGERS 3
#define NB_NOTES_SG 24

#define DEFAULT_CLOSED_POS 180
#define DEFAULT_OPEN_POS 20
#define DEFAULT_VIBRATO_AMP 10

const float _wServoSg = 0.1;

const int _freqs[NB_NOTES_SG] = { FREQ_C03, FREQ_CS3, FREQ_D03, FREQ_DS3, FREQ_E03, FREQ_F03, FREQ_FS3, FREQ_G03, FREQ_GS3, FREQ_A03, FREQ_AS3, FREQ_B03,
                                  FREQ_C04, FREQ_CS4, FREQ_D04, FREQ_DS4, FREQ_E04, FREQ_F04, FREQ_FS4, FREQ_G04, FREQ_GS4, FREQ_A04, FREQ_AS4, FREQ_B04 };

const String _notes[NB_NOTES_SG] = { "C03", "CS3", "D03", "DS3", "E03", "F03", "FS3", "G03", "GS3", "A03", "AS3", "B03",
                                     "C04", "CS4", "D04", "DS4", "E04", "F04", "FS4", "G04", "GS4", "A04", "AS4", "B04" };

#endif
