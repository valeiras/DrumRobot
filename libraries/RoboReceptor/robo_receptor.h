#ifndef Robo_Receptor_h
#define Robo_Receptor_h

#include "robo_communication.h"

class RoboReceptor {
 public:
  RoboReceptor();
  RoboReceptor(int address);

  // This method needs to be called after the derived class has been instantiated
  setReceptor();

  virtual void processStartMsg() = 0;
  virtual void processStopMsg() = 0;
  virtual void processResyncMsg() = 0;
  virtual void processBpmChangeMsg(uint8_t messageContent) = 0;
  virtual void processBpmIdxChangeMsg(uint8_t messageContent) = 0;
  virtual void processMtxModeChangeMsg(uint8_t messageContent);
  virtual void processSplModeChangeMsg(uint8_t messageContent);
  virtual void processMtxBlinkChangeMsg(uint8_t messageContent);
  virtual void processSplBlinkChangeMsg(uint8_t messageContent);
  virtual void processLimbStopMsg(uint8_t messageContent);
  virtual void processLimbStartMsg(uint8_t messageContent);
  virtual void processNoteOnMsg(uint8_t messageContent);
  virtual void processNoteOffMsg(uint8_t messageContent);
  virtual void processBrightnessChangeMsg(uint8_t messageContent);
  virtual void processSetResyncTimeMsg(uint16_t messageContent) = 0;
};

// I could not find another way to solve this: the function to be passed to the onReceive method of the Wire library
// needs to be static, which means that we cannot access pure virtual methods from it. We then use an outter method, and rely
// on the declaration of receptor
inline RoboReceptor* receptor;

uint16_t arrayToUint16(uint8_t* arr);

void receiveMessage(int howMany);

#endif