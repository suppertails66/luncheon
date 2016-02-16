#ifndef TWININPUTKEYSTATES_H
#define TWININPUTKEYSTATES_H


#include "input/InputKeyStates.h"

namespace Luncheon {


class TwinInputKeyStates {
public:
  virtual ~TwinInputKeyStates();
  
  TwinInputKeyStates();
  
  InputKeyState& getActiveState(InputKeys::InputKey key);
  
  InputKeyState& getInactiveState(InputKeys::InputKey key);
  
  void swapAndCopyStates();
  
  InputKeyStates& activeStates();
  
  InputKeyStates& inactiveStates();
  
protected:
  
  InputKeyStates* activeStates_;
  
  InputKeyStates* inactiveStates_;
  
  void swapStates();
  
  void copyInactiveToActive();
};


};


#endif 
