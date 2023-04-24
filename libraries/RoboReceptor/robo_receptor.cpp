#include "robo_receptor.h"

RoboReceptor::RoboReceptor() {
}

RoboReceptor::RoboReceptor(int address) {
  Wire.begin(address);
  Wire.onReceive(receiveMessage);
}

RoboReceptor::setReceptor() {
  receptor = this;
}

uint16_t arrayToUint16(uint8_t* arr) {
  return arr[0] | (arr[1] << BYTES_PER_UINT8 * BITS_PER_BYTE);
}

void receiveMessage(int howMany) {
  Serial.println("Robo receptor: message received");
  MessageType msgType = Wire.read();

  switch (howMany) {
    case 1:
      switch (msgType) {
        case START:
          Serial.println("RoboReceptor -> start");
          receptor->processStartMsg();
          break;
        case STOP:
          receptor->processStopMsg();
          break;
        case RESYNC:
          receptor->processResyncMsg();
          break;
      }
      break;
    case 2:
      uint8_t msgContent8 = Wire.read();
      switch (msgType) {
        case BPM_CHANGE:
          receptor->processBpmChangeMsg(msgContent8);
          break;
        case BPM_IDX_CHANGE:
          receptor->processBpmIdxChangeMsg(msgContent8);
          break;
        case MTX_MODE_CHANGE:
          receptor->processMtxModeChangeMsg(msgContent8);
          break;
        case SPL_MODE_CHANGE:
          receptor->processSplModeChangeMsg(msgContent8);
          break;
        case MTX_BLINK_CHANGE:
          receptor->processMtxBlinkChangeMsg(msgContent8);
          break;
        case SPL_BLINK_CHANGE:
          receptor->processSplBlinkChangeMsg(msgContent8);
          break;
        case BRIGHTNESS_CHANGE:
          receptor->processBrightnessChangeMsg(msgContent8);
          break;
        case LIMB_STOP:
          receptor->processLimbStopMsg(msgContent8);
          break;
        case LIMB_START:
          receptor->processLimbStartMsg(msgContent8);
          break;
      }
      break;
    case 3:
      uint8_t dataArr[2];
      dataArr[0] = Wire.read();
      dataArr[1] = Wire.read();
      uint16_t msgContent16 = arrayToUint16(dataArr);
      receptor->processSetResyncTimeMsg(msgContent16);
      break;
  }
}

// We provide empty implementations of some of these functions, as not all of the robots need them
void RoboReceptor::processBrightnessChangeMsg(uint8_t messageContent) {}
void RoboReceptor::processLimbStopMsg(uint8_t messageContent) {}
void RoboReceptor::processLimbStartMsg(uint8_t messageContent) {}
void RoboReceptor::processNoteOnMsg(uint8_t messageContent) {}
void RoboReceptor::processNoteOffMsg(uint8_t messageContent) {}
void RoboReceptor::processMtxModeChangeMsg(uint8_t messageContent) {}
void RoboReceptor::processSplModeChangeMsg(uint8_t messageContent) {}
void RoboReceptor::processMtxBlinkChangeMsg(uint8_t messageContent) {}
void RoboReceptor::processSplBlinkChangeMsg(uint8_t messageContent) {}
