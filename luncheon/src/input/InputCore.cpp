#include "input/InputCore.h"

namespace Luncheon {


InputCore::~InputCore() { };

InputCore::InputCore()
  : firstTriggeredInputKey_(InputKeys::dummy),
    wantsQuit_(false) { };
  
InputKeys::InputKey InputCore::firstTriggeredInputKey() {
  return firstTriggeredInputKey_;
}

void InputCore::resetFirstTriggeredInputKey() {
  firstTriggeredInputKey_ = InputKeys::dummy;
}
  
bool InputCore::wantsQuit() {
  return wantsQuit_;
}

void InputCore::setWantsQuit(bool wantsQuit__) {
  wantsQuit_ = wantsQuit__;
}
  
bool InputCore::pressed(InputKeys::InputKey key) {
  if (inputKeyStates_.getActiveState(key).down()) {
    // key is currently down
    return true;
  }
  return false;
}

bool InputCore::triggered(InputKeys::InputKey key) {
  if (inputKeyStates_.getActiveState(key).down()
      && !(inputKeyStates_.getInactiveState(key).down())) {
    // key is down and was not down at last update
    return true;
  }
  return false;
}

bool InputCore::held(InputKeys::InputKey key) {
  if (inputKeyStates_.getActiveState(key).down()
      && inputKeyStates_.getInactiveState(key).down()) {
    // key is down and was down at last update
    return true;
  }
  return false;
}
  
bool InputCore::released(InputKeys::InputKey key) {
  if (!(inputKeyStates_.getActiveState(key).down())
      && inputKeyStates_.getInactiveState(key).down()) {
    // key is not down and was down at last update
    return true;
  }
  return false;
}
  
void InputCore::clearActiveInputState() {
  for (int i = 1;
       i < static_cast<int>(InputKeys::EndOfEnumPlaceholder);
       i++) {
    inputKeyStates_.getActiveState(
      static_cast<InputKeys::InputKey>(i)).setDown(false);
  }
}


};
