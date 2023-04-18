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

unsigned long lastBpmTime = 0, lastBrightnessTime = 0;
byte lastBpmControllerVal, lastBrightnessControllerVal;
bool isBpmPending, isBrightnessPending;
unsigned int minTimeInterval = 100;

short minBpm = 60;
short maxBpm = 150;

bool isRobotPresent[NB_ROBOTS];

void setup() {
  isRobotPresent[DRUM_ROBOT] = true;
  isRobotPresent[GLOCKEN_ROBOT] = true;
  isRobotPresent[MUSIC_BOX_ROBOT] = false;
  isRobotPresent[LIGHTING_ROBOT] = false;

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
  checkCCPending(millis());
}

void notifyRobots(uint8_t messageType) {
  for (unsigned int ii = 0; ii < NB_ROBOTS; ii++) {
    sendMessage(ii, messageType);
  }
}

void notifyRobots(uint8_t messageType, uint8_t messageContent) {
  for (unsigned int ii = 0; ii < NB_ROBOTS; ii++) {
    sendMessage(ii, messageType, messageContent);
  }
}

void notifyRobots(uint8_t messageType, uint16_t messageContent) {
  for (unsigned int ii = 0; ii < NB_ROBOTS; ii++) {
    sendMessage(ii, messageType, messageContent);
  }
}

void sendMessage(uint8_t robot, uint8_t messageType) {
  if (isRobotPresent[robot]) {
    Serial.print("Sending message to robot ");
    Serial.print(robot);
    Serial.print(" at address ");
    Serial.println(_robotAddress[robot]);
    Wire.beginTransmission(_robotAddress[robot]);
    Wire.write(messageType);
    Wire.endTransmission();
  }
}

void sendMessage(uint8_t robot, uint8_t messageType, uint8_t messageContent) {
  if (isRobotPresent[robot]) {
    Serial.print("Sending message to robot ");
    Serial.print(robot);
    Serial.print(" at address ");
    Serial.println(_robotAddress[robot]);
    Wire.beginTransmission(_robotAddress[robot]);
    Wire.write(messageType);
    Wire.write(messageContent);
    Wire.endTransmission();
  }
}

void sendMessage(uint8_t robot, uint8_t messageType, uint16_t messageContent) {
  if (isRobotPresent[robot]) {
    Serial.print("Sending message to robot ");
    Serial.print(robot);
    Serial.print(" at address ");
    Serial.println(_robotAddress[robot]);

    uint8_t messageArray[BYTES_PER_UINT16];
    uint16ToArray(messageContent, messageArray);

    Wire.beginTransmission(_robotAddress[robot]);
    Wire.write(messageType);
    Wire.write(messageArray, BYTES_PER_UINT16);
    Wire.endTransmission();
  }
}

void uint16ToArray(uint16_t inputNumber, uint8_t* arr) {
  arr[0] = inputNumber & MASK_BYTE0;
  arr[1] = inputNumber & MASK_BYTE1;
}

void notifyChangeLightingMode(uint8_t lightingMode, uint8_t elementBit) {
  if (isRobotPresent[LIGHTING_ROBOT]) {
    uint8_t messageContent = (lightingMode << BITS_PER_ELEMENT_IDENTIFIER) | elementBit;
    sendMessage(LIGHTING_ADDRESS, MODE_CHANGE, messageContent);
  }
}

void notifyBrightnessChange(uint8_t brightness) {
  if (isRobotPresent[LIGHTING_ROBOT]) {
    sendMessage(LIGHTING_ADDRESS, BRIGHTNESS_CHANGE, brightness);
  }
}

void handleNoteOn(byte channel, byte pitch, byte velocity) {
  digitalWrite(LED_BUILTIN, HIGH);
  switch (pitch) {
    case START_KEY:
      notifyRobots(START);
      break;
    case STOP_KEY:
      notifyRobots(STOP);
      break;
    case MTX_BLINK_KEY:
      notifyChangeLightingMode(MATRIX_BLINKING_MODE, MATRIX);
      break;
    case MTX_NAME_KEY:
      notifyChangeLightingMode(MATRIX_NAME_MODE, MATRIX);
      break;
    case MTX_LOGO_KEY:
      notifyChangeLightingMode(MATRIX_LOGO_MODE, MATRIX);
      break;
    case MTX_RCT_KEY:
      notifyChangeLightingMode(MATRIX_RECTANGLES_MODE, MATRIX);
      break;
    case MTX_BARS_KEY:
      notifyChangeLightingMode(MATRIX_BARS_MODE, MATRIX);
      break;
    case SPL_TOP_KEY:
      notifyChangeLightingMode(SPOTLIGHT_TOP_MODE, SPOTLIGHT);
      break;
    case SPL_BOTTOM_KEY:
      notifyChangeLightingMode(SPOTLIGHT_BOTTOM_MODE, SPOTLIGHT);
      break;
    case SPL_BLINK_KEY:
      notifyChangeLightingMode(SPOTLIGHT_BLINKING_MODE, SPOTLIGHT);
      break;
    case SPL_SEQ_KEY:
      notifyChangeLightingMode(SPOTLIGHT_SEQUENCE_MODE, SPOTLIGHT);
      break;
    case MB_STOP_KEY:
      sendMessage(MUSIC_BOX_ADDRESS, LIMB_STOP, uint8_t(0));
      break;
    case DRUM_LA_STOP_KEY:
      sendMessage(DRUM_ROBOT, LIMB_STOP, uint8_t(0));
      break;
    case DRUM_RA_STOP_KEY:
      sendMessage(DRUM_ROBOT, LIMB_STOP, uint8_t(1));
      break;
    case GLOCK_LA_STOP_KEY:
      sendMessage(GLOCKEN_ROBOT, LIMB_STOP, uint8_t(0));
      break;
    case GLOCK_RA_STOP_KEY:
      sendMessage(GLOCKEN_ROBOT, LIMB_STOP, uint8_t(1));
      break;
  }
}

void handleNoteOff(byte channel, byte pitch, byte velocity) {
  digitalWrite(LED_BUILTIN, LOW);
  switch (pitch) {
    case MTX_BLINK_KEY:
    case MTX_NAME_KEY:
    case MTX_LOGO_KEY:
    case MTX_RCT_KEY:
    case MTX_BARS_KEY:
      notifyChangeLightingMode(MATRIX_CONSTANT_MODE, MATRIX);
      break;
    case SPL_TOP_KEY:
    case SPL_BOTTOM_KEY:
    case SPL_BLINK_KEY:
    case SPL_SEQ_KEY:
      notifyChangeLightingMode(SPOTLIGHT_OFF_MODE, SPOTLIGHT);
      break;
    case MB_STOP_KEY:
      sendMessage(MUSIC_BOX_ROBOT, LIMB_START, uint8_t(0));
      break;
    case DRUM_LA_STOP_KEY:
      sendMessage(DRUM_ROBOT, LIMB_START, uint8_t(0));
      break;
    case DRUM_RA_STOP_KEY:
      sendMessage(DRUM_ROBOT, LIMB_START, uint8_t(1));
      break;
    case GLOCK_LA_STOP_KEY:
      sendMessage(GLOCKEN_ROBOT, LIMB_START, uint8_t(0));
      break;
    case GLOCK_RA_STOP_KEY:
      sendMessage(GLOCKEN_ROBOT, LIMB_START, uint8_t(1));
      break;
  }
}

void handleCCMessage(byte channel, byte number, byte value) {
  switch (number) {
    case BPM_CONTROLLER:
      lastBpmControllerVal = value;
      isBpmPending = true;
      break;
    case BRIGHTNESS_CONTROLLER:
      lastBrightnessControllerVal = value;
      isBrightnessPending = true;
      break;
  }
}

void checkCCPending(unsigned long currTime) {
  if (isBpmPending && currTime - lastBpmTime > minTimeInterval) {
    lastBpmTime = currTime;
    isBpmPending = false;
    int newBpmIdx = map(lastBpmControllerVal, CC_MAX, CC_MIN, MIN_BPM_IDX, NB_BPM_VALUES - 1);
    if (newBpmIdx != bpmIdx) {
      bpmIdx = newBpmIdx;
      notifyRobots(BPM_IDX_CHANGE, bpmIdx);
    }
  }
  if (isBrightnessPending && currTime - lastBrightnessTime > minTimeInterval) {
    lastBrightnessTime = currTime;
    isBrightnessPending = false;
    uint8_t newBrightness = map(lastBrightnessControllerVal, CC_MIN, CC_MAX, 0, MAX_BRIGHTNESS);
    notifyBrightnessChange(newBrightness);
  }
}