#include "robo_receptor.h"

RoboReceptor::RoboReceptor() {
}

RoboReceptor::RoboReceptor(int address) {
  Serial.println("[RoboReceptor] Constructor");
  Wire.begin(address);
  Wire.onReceive(receiveMessage);
}

RoboReceptor::setReceptor() {
  receptor = this;
}

uint16_t arrayToUint16(uint8_t* arr) {
  return arr[0] | arr[1] << BYTES_PER_UINT8 * BITS_PER_BYTE;
}

void receiveMessage(int howMany) {
  MessageType msgType = Wire.read();

//   Serial.println("[RoboReceptor] Message Received");
//   Serial.print("[RoboReceptor] Message type: ");
//   Serial.println(msgType);
//   Serial.print("[RoboReceptor] Nb of bytes: ");
//   Serial.println(howMany);

  switch (howMany) {
    case 1:
      switch (msgType) {
        case START:
          receptor->treatStartMsg();
          break;
        case RESYNC:
          receptor->treatResyncMsg();
          break;
      }
      break;
    case 2:
      uint8_t msgContent8 = Wire.read();
      switch (msgType) {
        case BPM_CHANGE:
          receptor->treatBpmChangeMsg(msgContent8);
          break;
        case MODE_CHANGE:
          receptor->treatModeChangeMsg(msgContent8);
          break;
      }
      break;
    case 3:
      uint8_t dataArr[2];
      dataArr[0] = Wire.read();
      dataArr[1] = Wire.read();
      uint16_t msgContent16 = arrayToUint16(dataArr);
      receptor->treatSetResyncTimeMsg(msgContent16);
      break;
  }
}