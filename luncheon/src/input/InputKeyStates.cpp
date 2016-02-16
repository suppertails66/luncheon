#include "input/InputKeyStates.h"

namespace Luncheon {


InputKeyStates::~InputKeyStates() { };

InputKeyStates::InputKeyStates() {
  initializeMap();
}
  
InputKeyState& InputKeyStates::state(InputKeys::InputKey key) {
  InputKeyStateMap::iterator it = states_.find(key);
  
  if (it == states_.end()) {
    // shouldn't happen
    // ...
  }
  
  return (it->second);
}
  
InputKeyStateMap& InputKeyStates::states() {
  return states_;
}

void InputKeyStates::initializeMap() {
  for (int i = 1;
       i < static_cast<int>(InputKeys::EndOfEnumPlaceholder);
       i++) {
    states_.insert(InputKeyStateMapPair(static_cast<InputKeys::InputKey>(i),
                                        InputKeyState()));
  }
}


};
