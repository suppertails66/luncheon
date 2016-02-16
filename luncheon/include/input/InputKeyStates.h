#ifndef INPUTKEYSTATES_H
#define INPUTKEYSTATES_H


#include "input/InputKeyStateMap.h"

namespace Luncheon {


class InputKeyStates {
public:
  virtual ~InputKeyStates();
  
  InputKeyStates();
  
  InputKeyState& state(InputKeys::InputKey key);
  
  InputKeyStateMap& states();
  
protected:
  
  InputKeyStateMap states_;
  
  void initializeMap();
  
};


};


#endif 
