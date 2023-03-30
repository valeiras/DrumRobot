#ifndef Robo_Receptor_h
#define Robo_Receptor_h

#include "robo_communication.h"

class RoboReceptor {
 public:
  RoboReceptor();
  RoboReceptor(int address);

  // This method needs to be called after the derived class has been instantiated
  setReceptor();

  virtual void treatStartMsg() = 0;
  virtual void treatStopMsg() = 0;
  virtual void treatResyncMsg() = 0;
  virtual void treatBpmChangeMsg(uint8_t messageContent) = 0;
  virtual void treatBpmIdxChangeMsg(uint8_t messageContent) = 0;  
  virtual void treatModeChangeMsg(uint8_t messageContent) = 0;
  virtual void treatSetResyncTimeMsg(uint16_t messageContent) = 0;
};

// I could not find another way to solve this: the function to be passed to the onReceive method of the Wire library
// needs to be static, which means that we cannot access pure virtual methods from it. We then use an outter method, and rely
// on the declaration of receptor
inline RoboReceptor* receptor;

uint16_t arrayToUint16(uint8_t* arr);

void receiveMessage(int howMany);

#endif