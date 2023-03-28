#include <Wire.h>
#include <MIDI.h>
#include <robo_communication.h>

#include "midi_notes.h"

#define CC_MIN 0
#define CC_MAX 127

#define LED_PIN 13

#define MIN_BPM_CHANGE 5

// Create and bind the MIDI interface to the default hardware Serial port
MIDI_CREATE_DEFAULT_INSTANCE();

const uint16_t RESYNC_TIME = 10000;
uint8_t bpm = DEFAULT_BPM;
uint8_t bpmIdx = DEFAULT_BPM_IDX;

unsigned int initialDelay = 1000;
unsigned long ellapsedTime, initTime, lastResync;

bool variableBpm = true;

short minBpm = 60;
short maxBpm = 150;

// ------------------------------- DRUM -GLOCK -MBOX -LIGHT
bool robotIsPresent[NB_ROBOTS] = { false, false, true, false };

void setup() {
  MIDI.begin(MIDI_CHANNEL_OMNI);  // Initialize the Midi Library.
  MIDI.setHandleNoteOn(handleNoteOn);
  MIDI.setHandleNoteOff(handleNoteOff);
  MIDI.setHandleControlChange(handleCCMessage);

  Wire.begin();
  //notifyRobots(BPM_CHANGE, bpm);
  notifyRobots(BPM_IDX_CHANGE, bpmIdx);
  //notifyRobots(SET_RESYNC_TIME, RESYNC_TIME);

  pinMode(LED_PIN, OUTPUT);

  initTime = millis();
}

void loop() {
  // digitalWrite(LED_BUILTIN, HIGH);
  // delay(100);
  // digitalWrite(LED_BUILTIN, LOW);
  // delay(100);
  ellapsedTime = millis() - initTime;
  MIDI.read();
  if (ellapsedTime - lastResync >= RESYNC_TIME) {
    //notifyRobots(RESYNC);
    lastResync += RESYNC_TIME;
  }
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
  if (robotIsPresent[3]) {
    uint8_t messageContent = (lightingMode << BITS_PER_ELEMENT_IDENTIFIER) | elementBit;
    sendMessage(LIGHTING_ADDRESS, MODE_CHANGE, messageContent);
  }
}

void handleNoteOn(byte channel, byte pitch, byte velocity) {
  digitalWrite(LED_BUILTIN, HIGH);
  switch (pitch) {
    case C03:
      notifyChangeLightingMode(MATRIX_OFF_MODE, MATRIX);
      break;
    case D03:
      notifyChangeLightingMode(MATRIX_BLINKING_MODE, MATRIX);
      break;
    case E03:
      notifyChangeLightingMode(MATRIX_NAME_MODE, MATRIX);
      break;
    case F03:
      notifyChangeLightingMode(MATRIX_LOGO_MODE, MATRIX);
      break;
    case G03:
      notifyChangeLightingMode(MATRIX_RECTANGLES_MODE, MATRIX);
      break;
    case A03:
      notifyChangeLightingMode(MATRIX_BARS_MODE, MATRIX);
      break;
    case C04:
      notifyChangeLightingMode(SPOTLIGHT_OFF_MODE, SPOTLIGHT);
      break;
    case D04:
      notifyChangeLightingMode(SPOTLIGHT_BLINKING_MODE, SPOTLIGHT);
      break;
    case E04:
      notifyChangeLightingMode(SPOTLIGHT_SEQUENCE_MODE, SPOTLIGHT);
      break;
    case F04:
      notifyChangeLightingMode(SPOTLIGHT_CONSTANT_MODE, SPOTLIGHT);
      break;
    case B04:
      notifyRobots(STOP);
      break;
    case C05:
      notifyRobots(START);
      break;
  }
}

void handleNoteOff(byte channel, byte pitch, byte velocity) {
  digitalWrite(LED_BUILTIN, LOW);
}

void handleCCMessage(byte channel, byte number, byte value) {
  switch (number) {
    case POT1:
      if (variableBpm) {
        int newBpmIdx = map(value, CC_MAX, CC_MIN, 0, NB_BPM_VALUES - 1);
        if (newBpmIdx != bpmIdx) {
          bpmIdx = newBpmIdx;
          notifyRobots(BPM_IDX_CHANGE, bpmIdx);
        }
      }
      break;
  }
}