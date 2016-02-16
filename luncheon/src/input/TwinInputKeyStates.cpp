#include "input/TwinInputKeyStates.h"
#include <utility>

namespace Luncheon {


TwinInputKeyStates::~TwinInputKeyStates() {
  delete inactiveStates_;
  delete activeStates_;
}

TwinInputKeyStates::TwinInputKeyStates()
  : activeStates_(new InputKeyStates()),
    inactiveStates_(new InputKeyStates()) { };
  
InputKeyState& TwinInputKeyStates::getActiveState(InputKeys::InputKey key) {
  return activeStates_->state(key);
}

InputKeyState& TwinInputKeyStates::getInactiveState(InputKeys::InputKey key) {
  return inactiveStates_->state(key);
}
  
void TwinInputKeyStates::swapAndCopyStates() {
  swapStates();
  copyInactiveToActive();
}
  
void TwinInputKeyStates::swapStates() {
  std::swap(activeStates_, inactiveStates_);
}
  
void TwinInputKeyStates::copyInactiveToActive() {
/*  InputKeyStateMap::iterator destination = activeStates_->states().begin();
  for (InputKeyStateMap::iterator it = inactiveStates_->states().begin();
       it != inactiveStates_->states().end();
       it++) {
    if (destination == activeStates_->states().end()) {
      // shouldn't happen
      break;
    }
    
    destination->second = it->second;
    ++destination;
  } */
  
  *activeStates_ = *inactiveStates_;
  
}

InputKeyStates& TwinInputKeyStates::activeStates() {
  return *activeStates_;
}

InputKeyStates& TwinInputKeyStates::inactiveStates() {
  return *inactiveStates_;
}
  
  
};
