#include "input/InputKeyState.h"

namespace Luncheon {


InputKeyState::~InputKeyState() { };

InputKeyState::InputKeyState()
  : down_(false) { };
  
void InputKeyState::setDown(bool down__) {
  down_ = down__;
}
  
bool InputKeyState::down() {
  return down_;
}

bool InputKeyState::up() {
  return !down_;
}


};
