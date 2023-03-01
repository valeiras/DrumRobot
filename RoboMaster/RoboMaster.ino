#include <Wire.h>
#include <robo_communication.h>

#define BPM_INPUT_PIN A0
#define BUTTON1_PIN 2

#define ANALOG_MIN 0
#define ANALOG_MAX 1023

#define MIN_BPM_CHANGE 5

const uint16_t RESYNC_TIME = 10000;
uint8_t bpm = 90;

unsigned int initialDelay = 1000;
unsigned long ellapsedTime, initTime, lastResync;

bool printOutput = true;
bool variableBpm = true;
bool hasStarted = false;

short minBpm = 60;
short maxBpm = 150;

int lastButtonState = LOW;
int currLightMode = 0;

bool robotIsPresent[NB_ROBOTS] = { false, false, false, true };

void setup() {
  if (printOutput) {
    Serial.begin(9600);
  }

  pinMode(BPM_INPUT_PIN, INPUT);
  pinMode(BUTTON1_PIN, INPUT);

  Wire.begin();
  //notifyRobots(SET_RESYNC_TIME, RESYNC_TIME);

  initTime = millis();
}

void loop() {
  ellapsedTime = millis() - initTime;
  if (!hasStarted) {
    if (ellapsedTime >= initialDelay) {
      // We start robots
      Serial.println("[RoboMaster] Start!");
      notifyRobots(START);
      lastResync = ellapsedTime;
      hasStarted = true;
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
    if (ellapsedTime - lastResync >= RESYNC_TIME) {
      //notifyRobots(RESYNC);
      lastResync += RESYNC_TIME;
    }

    int currButtonState = digitalRead(BUTTON1_PIN);
    if (currButtonState == HIGH && lastButtonState == LOW) {
      currLightMode = ++currLightMode % NB_LIGHTING_MODES;
      sendMessage(LIGHTING_ADDRESS, MODE_CHANGE, lightingModes[currLightMode]);
    }
    lastButtonState = currButtonState;
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