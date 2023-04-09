#include <Wire.h>
#include <MIDI.h>
#include <robo_communication.h>

#include "midi_notes.h"

#define CC_MIN 0
#define CC_MAX 127
#define MAX_BRIGHTNESS 64

#define LED_PIN 13

#define MIN_BPM_CHANGE 5
#define MIN_BPM_IDX 11

// Create and bind the MIDI interface to the default hardware Serial port
MIDI_CREATE_DEFAULT_INSTANCE();

const uint16_t RESYNC_TIME = 10000;
uint8_t bpm = DEFAULT_BPM;
uint8_t bpmIdx = DEFAULT_BPM_IDX;

unsigned long lastFad1Time = 0, lastFad2Time = 0;
byte lastFad1Val, lastFad2Val;
bool fad1Pending, fad2Pending;
unsigned int minTimeInterval = 100;

short minBpm = 60;
short maxBpm = 150;

bool robotIsPresent[NB_ROBOTS];

void setup() {
  robotIsPresent[DRUM_ROBOT] = true;
  robotIsPresent[GLOCKEN_ROBOT] = true;
  robotIsPresent[MUSIC_BOX_ROBOT] = true;
  robotIsPresent[LIGHTING_ROBOT] = true;

  MIDI.begin(MIDI_CHANNEL_OMNI);  // Initialize the Midi Library.
  MIDI.setHandleNoteOn(handleNoteOn);
  MIDI.setHandleNoteOff(handleNoteOff);
  MIDI.setHandleControlChange(handleCCMessage);

  Wire.begin();
  notifyRobots(BPM_IDX_CHANGE, bpmIdx);

  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  MIDI.read();
  checkFadersPending(millis());
}

void notifyRobots(uint8_t messageType) {
  for (unsigned int ii = 0; ii < NB_ROBOTS; ii++) {
    if (robotIsPresent[ii]) {
      sendMessage(robotAddresses[ii], messageType);
    }
  }
}

void notifyRobots(uint8_t messageType, uint8_t messageContent) {
  for (unsigned int ii = 0; ii < NB_ROBOTS; ii++) {
    if (robotIsPresent[ii]) {
      sendMessage(robotAddresses[ii], messageType, messageContent);
    }
  }
}

void notifyRobots(uint8_t messageType, uint16_t messageContent) {
  for (unsigned int ii = 0; ii < NB_ROBOTS; ii++) {
    if (robotIsPresent[ii]) {
      sendMessage(robotAddresses[ii], messageType, messageContent);
    }
  }
}

void sendMessage(uint8_t robotAddress, uint8_t messageType) {
  Wire.beginTransmission(robotAddress);
  Wire.write(messageType);
  Wire.endTransmission();
}

void sendMessage(uint8_t robotAddress, uint8_t messageType, uint8_t messageContent) {
  Wire.beginTransmission(robotAddress);
  Wire.write(messageType);
  Wire.write(messageContent);
  Wire.endTransmission();
}

void sendMessage(uint8_t robotAddress, uint8_t messageType, uint16_t messageContent) {
  uint8_t messageArray[BYTES_PER_UINT16];
  uint16ToArray(messageContent, messageArray);

  Wire.beginTransmission(robotAddress);
  Wire.write(messageType);
  Wire.write(messageArray, BYTES_PER_UINT16);
  Wire.endTransmission();
}

void uint16ToArray(uint16_t inputNumber, uint8_t* arr) {
  arr[0] = inputNumber & MASK_BYTE0;
  arr[1] = inputNumber & MASK_BYTE1;
}

void notifyChangeLightingMode(uint8_t lightingMode, uint8_t elementBit) {
  if (robotIsPresent[LIGHTING_ROBOT]) {
    uint8_t messageContent = (lightingMode << BITS_PER_ELEMENT_IDENTIFIER) | elementBit;
    sendMessage(LIGHTING_ADDRESS, MODE_CHANGE, messageContent);
  }
}

void notifyBrightnessChange(uint8_t brightness) {
  if (robotIsPresent[LIGHTING_ROBOT]) {
    sendMessage(LIGHTING_ADDRESS, BRIGHTNESS_CHANGE, brightness);
  }
}

void handleNoteOn(byte channel, byte pitch, byte velocity) {
  digitalWrite(LED_BUILTIN, HIGH);
  switch (pitch) {
    case PAD_09:
      notifyChangeLightingMode(MATRIX_OFF_MODE, MATRIX);
      break;
    case PAD_10:
      notifyChangeLightingMode(MATRIX_BLINKING_MODE, MATRIX);
      break;
    case PAD_11:
      notifyChangeLightingMode(MATRIX_NAME_MODE, MATRIX);
      break;
    case PAD_12:
      notifyChangeLightingMode(MATRIX_LOGO_MODE, MATRIX);
      break;
    case PAD_05:
      notifyChangeLightingMode(MATRIX_RECTANGLES_MODE, MATRIX);
      break;
    case PAD_06:
      notifyChangeLightingMode(MATRIX_BARS_MODE, MATRIX);
      break;
    case PAD_01:
      notifyChangeLightingMode(SPOTLIGHT_OFF_MODE, SPOTLIGHT);
      break;
    case PAD_02:
      notifyChangeLightingMode(SPOTLIGHT_BLINKING_MODE, SPOTLIGHT);
      break;
    case PAD_03:
      notifyChangeLightingMode(SPOTLIGHT_SEQUENCE_MODE, SPOTLIGHT);
      break;
    case PAD_04:
      notifyChangeLightingMode(SPOTLIGHT_CONSTANT_MODE, SPOTLIGHT);
      break;
    case PAD_15:
      notifyRobots(START);
      break;
    case PAD_16:
      notifyRobots(STOP);
      break;
  }
}

void handleNoteOff(byte channel, byte pitch, byte velocity) {
  digitalWrite(LED_BUILTIN, LOW);
}

void handleCCMessage(byte channel, byte number, byte value) {
  switch (number) {
    case FAD1:
      lastFad1Val = value;
      fad1Pending = true;
      break;
    case FAD2:
      lastFad2Val = value;
      fad2Pending = true;
      break;
  }
}

void checkFadersPending(unsigned long currTime) {
  if (fad1Pending && currTime - lastFad1Time > minTimeInterval) {
    lastFad1Time = currTime;
    fad1Pending = false;
    int newBpmIdx = map(lastFad1Val, CC_MAX, CC_MIN, MIN_BPM_IDX, NB_BPM_VALUES-1);
    if (newBpmIdx != bpmIdx) {
      bpmIdx = newBpmIdx;
      notifyRobots(BPM_IDX_CHANGE, bpmIdx);
    }
  }
  if (fad2Pending && currTime - lastFad2Time > minTimeInterval) {
    lastFad2Time = currTime;
    fad2Pending = false;
    uint8_t newBrightness = map(lastFad2Val, CC_MIN, CC_MAX, 0, MAX_BRIGHTNESS);
    notifyBrightnessChange(newBrightness);
  }
}