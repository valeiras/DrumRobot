#include <robo_communication.h>
#include <Wire.h>

#define BPM_INPUT_PIN A0

#define ANALOG_MIN 0
#define ANALOG_MAX 1023

#define MIN_BPM_CHANGE 3

#define NB_ROBOTS 3

const uint16_t RESYNC_TIME = 10000;
uint8_t bpm = 90;

unsigned int initialDelay = 1000;
unsigned long ellapsedTime, initTime, lastResync;

bool printOutput = false;
bool variableBpm = false;
bool hasStarted = false;

short minBpm = 60;
short maxBpm = 150;

short robotAddresses[NB_ROBOTS] = { DRUM_ADDRESS, GLOCKEN_ADDRESS, MUSIC_BOX_ADDRESS };

void setup() {
  if (printOutput) {
    Serial.begin(9600);
  }

  pinMode(BPM_INPUT_PIN, INPUT);

  Wire.begin();
  notifyRobots(SET_RESYNC_TIME, RESYNC_TIME);

  initTime = millis();
}

void loop() {
  ellapsedTime = millis() - initTime;
  if (!hasStarted) {
    if (ellapsedTime >= initialDelay) {
      // We start robots
      notifyRobots(START);
      lastResync = ellapsedTime;
    }
  } else {
    if (variableBpm) {
      int sensorValue = analogRead(BPM_INPUT_PIN);
      int newBpm = map(sensorValue, ANALOG_MIN, ANALOG_MAX, minBpm, maxBpm);
      if (abs(newBpm - bpm) >= MIN_BPM_CHANGE) {
        bpm = newBpm;
        notifyRobots(BPM_CHANGE, bpm);
      }
    }
    if( ellapsedTime - lastResync >= RESYNC_TIME){
      notifyRobots(RESYNC);
      lastResync += RESYNC_TIME;
    }
  }
}

void notifyRobots(short messageType) {
  for (unsigned int ii = 0; ii < NB_ROBOTS; ii++) {
    sendMessage(robotAddresses[ii], messageType);
  }
}

void notifyRobots(uint8_t messageType, uint8_t messageContent) {
  for (unsigned int ii = 0; ii < NB_ROBOTS; ii++) {
    sendMessage(robotAddresses[ii], messageType, messageContent);
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
  uint8_t messageArray[BYTES_PER_INT];
  intToArray(messageContent, messageArray);

  Wire.beginTransmission(robotAddress);
  Wire.write(messageType);
  Wire.write(messageArray, BYTES_PER_INT);
  Wire.endTransmission();
}

void intToArray(uint16_t inputNumber, uint8_t* arr) {
  arr[0] = inputNumber & MASK_BYTE0;
  arr[1] = inputNumber & MASK_BYTE1;
}