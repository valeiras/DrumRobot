#ifndef Robo_communication_h
#define Robo_communication_h

#include <Arduino.h>
#include <Wire.h>

#define NB_ROBOTS 4
#define NB_LIGHTING_MODES 3

#define DRUM_ADDRESS 1
#define GLOCKEN_ADDRESS 2
#define MUSIC_BOX_ADDRESS 3
#define LIGHTING_ADDRESS 4

enum MessageType {
  START,
  RESYNC,
  BPM_CHANGE,
  MODE_CHANGE,  
  SET_RESYNC_TIME  
};

#define BLINKING_MODE 0
#define NAME_MODE 1
#define LOGO_MODE 2

inline uint8_t robotAddresses[NB_ROBOTS] = {DRUM_ADDRESS, GLOCKEN_ADDRESS, MUSIC_BOX_ADDRESS, LIGHTING_ADDRESS};
inline uint8_t lightingModes[NB_LIGHTING_MODES] = {BLINKING_MODE, NAME_MODE, LOGO_MODE};

#define MASK_BYTE0 0x00FF
#define MASK_BYTE1 0xFF00

#define BITS_PER_BYTE 1
#define BYTES_PER_UINT8 1
#define BYTES_PER_UINT16 2


#endif