#ifndef midi_notes_h
#define midi_notes_h

#define GR
//#define LD

#ifdef LD
#define PAD_01 36
#define PAD_02 37
#define PAD_03 38
#define PAD_04 39
#define PAD_05 40
#define PAD_06 41
#define PAD_07 42
#define PAD_08 43
#define PAD_09 44
#define PAD_10 45
#define PAD_11 46
#define PAD_12 47
#define PAD_13 48
#define PAD_14 49
#define PAD_15 50
#define PAD_16 51
#define PAD_17 52
#define PAD_18 53
#define PAD_19 54
#define PAD_20 55
#define PAD_21 56
#define PAD_22 57
#define PAD_23 58
#define PAD_24 59
#define PAD_25 60
#define PAD_26 61
#define PAD_27 62
#define PAD_28 63
#define PAD_29 64
#define PAD_30 65
#define PAD_31 66
#define PAD_32 67
#define PAD_33 68
#define PAD_34 69
#define PAD_35 70
#define PAD_36 71
#define PAD_37 72
#define PAD_38 73
#define PAD_39 74
#define PAD_40 75
#define PAD_41 76
#define PAD_42 77
#define PAD_43 78
#define PAD_44 79
#define PAD_45 80
#define PAD_46 81
#define PAD_47 82
#define PAD_48 83

#define POT1 28
#define POT2 29

#define FAD1 20
#define FAD2 21

#define PLAY 60
#define REC 62

#define MOD 01

#define START_KEY PAD_45
#define STOP_KEY PAD_46
#define MTX_BLINK_KEY PAD_47
#define MTX_NAME_KEY PAD_48
#define MTX_LOGO_KEY PAD_41
#define MTX_RCT_KEY PAD_42
#define MTX_BARS_KEY PAD_43
#define SPL_TOP_KEY PAD_44
#define SPL_BOTTOM_KEY PAD_37
#define SPL_BLINK_KEY PAD_38
#define SPL_SEQ_KEY PAD_39
#define MB_STOP_KEY PAD_40
#define DRUM_LA_STOP_KEY PAD_34
#define DRUM_RA_STOP_KEY PAD_33
#define GLOCK_LA_STOP_KEY PAD_36
#define GLOCK_RA_STOP_KEY PAD_35

#define BPM_CONTROLLER FAD1
#define BRIGHTNESS_CONTROLLER FAD2
#define MTX_BLINK_CONTROLLER POT1
#define SPL_BLINK_CONTROLLER POT2

#endif

#ifdef GR
#define C03 48
#define CS3 49
#define D03 50
#define DS3 51
#define E03 52
#define F03 53
#define FS3 54
#define G03 55
#define GS3 56
#define A03 57
#define AS3 58
#define B03 59
#define C04 60
#define CS4 61
#define D04 62
#define DS4 63
#define E04 64
#define F04 65
#define FS4 66
#define G04 67
#define GS4 68
#define A04 69
#define AS4 70
#define B04 71
#define C05 72
#define CS5 73
#define D05 74
#define DS5 75
#define E05 76
#define F05 77
#define FS5 78
#define G05 79
#define GS5 80
#define A05 81
#define AS5 82
#define B05 83

#define POT1 74
#define POT2 71
#define POT3 79
#define POT4 78
#define POT5 14
#define POT6 15
#define POT7 73
#define POT8 09

#define MOD 01

#define START_KEY C05
#define STOP_KEY B04
#define MTX_BLINK_KEY A03
#define MTX_NAME_KEY B03
#define MTX_LOGO_KEY C04
#define MTX_RCT_KEY D04
#define MTX_BARS_KEY E04
#define SPL_TOP_KEY F04
#define SPL_BOTTOM_KEY G04
#define SPL_BLINK_KEY GS4
#define SPL_SEQ_KEY AS4
#define MB_STOP_KEY C03
#define DRUM_LA_STOP_KEY E03
#define DRUM_RA_STOP_KEY D03
#define GLOCK_LA_STOP_KEY G03
#define GLOCK_RA_STOP_KEY F03

#define BPM_CONTROLLER POT1
#define BRIGHTNESS_CONTROLLER POT2
#define MTX_BLINK_CONTROLLER POT3
#define SPL_BLINK_CONTROLLER POT4

#endif

#define C06 84
#define CS6 85
#define D06 86
#define DS6 87
#define E06 88
#define F06 89
#define FS6 90
#define G06 91
#define GS6 92
#define A06 93
#define AS6 94
#define B06 95
#define C07 96
#define CS7 97
#define D07 98
#define DS7 99
#define E07 100
#define F07 101
#define FS7 102
#define G07 103
#define GS7 104
#define A07 105
#define AS7 106
#define B07 107
#define C08 108

#define VIBRATO_AMP_CONTROLLER POT5

#endif