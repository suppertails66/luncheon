#ifdef LUNCHEON_ENABLE_SDL2

#include "input/SDL2InputCore.h"
#include <iostream>

namespace Luncheon {


SDL2InputCore::~SDL2InputCore() { };

SDL2InputCore::SDL2InputCore()
  : waitingForFirstTriggeredInputKey_(false) { };
  
void SDL2InputCore::updateInputs() {
  // Move old input to inactive input
  inputKeyStates_.swapAndCopyStates();
  
  // Poll all events
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    switch (event.type) {
    case SDL_KEYDOWN:
      handleKeyPress(event.key);
      break;
    case SDL_KEYUP:
      handleKeyRelease(event.key);
      break;
    case SDL_QUIT:
      handleQuitEvent(event.quit);
      break;
    default:
      // ignore
      break;
    }
  }
  
/*  for (int i = 1;
       i < static_cast<int>(InputKeys::EndOfEnumPlaceholder);
       i++) {
    InputKeys::InputKey currentKey = static_cast<InputKeys::InputKey>(i);
    
    if (triggered(currentKey)) {
      std::cout << "Triggered: " << InputKeys::getKeyString(currentKey) << std::endl;
    }
    if (pressed(currentKey)) {
      std::cout << "Pressed: " << InputKeys::getKeyString(currentKey) << std::endl;
    }
    if (held(currentKey)) {
      std::cout << "Held: " << InputKeys::getKeyString(currentKey) << std::endl;
    }
    if (released(currentKey)) {
      std::cout << "Released: " << InputKeys::getKeyString(currentKey) << std::endl;
    }
  } */
}
  
void SDL2InputCore::rememberFirstTriggeredInputKey() {
  waitingForFirstTriggeredInputKey_ = true;
}

void SDL2InputCore::handleKeyPress(SDL_KeyboardEvent& keyEvent) {
  InputKeys::InputKey targetKey 
    = mapSDLScancodeToInputKey(keyEvent.keysym.scancode);
    
  // ignore unrecognized keys
  if (targetKey != InputKeys::dummy) {
    // if waiting for first triggered key, mark this one
    if (waitingForFirstTriggeredInputKey_) {
      firstTriggeredInputKey_ = targetKey;
      waitingForFirstTriggeredInputKey_ = false;
    }
    
    pressKey(targetKey);
  }
}

void SDL2InputCore::handleKeyRelease(SDL_KeyboardEvent& keyEvent) {
  InputKeys::InputKey targetKey 
    = mapSDLScancodeToInputKey(keyEvent.keysym.scancode);
    
  // ignore unrecognized keys
  if (targetKey != InputKeys::dummy) {
    releaseKey(targetKey);
  }
}
  
void SDL2InputCore::pressKey(InputKeys::InputKey key) {
  inputKeyStates_.getActiveState(key).setDown(true);
}

void SDL2InputCore::releaseKey(InputKeys::InputKey key) {
  inputKeyStates_.getActiveState(key).setDown(false);
}

void SDL2InputCore::handleQuitEvent(SDL_QuitEvent& quitEvent) {
  wantsQuit_ = true;
}
  
InputKeys::InputKey SDL2InputCore::mapSDLScancodeToInputKey(
                                        SDL_Scancode scancode) {
  
  switch (scancode) {
  case SDL_SCANCODE_ESCAPE:
    return InputKeys::esc;
    break;
  case SDL_SCANCODE_BACKSPACE:
    return InputKeys::backspace;
    break;
  case SDL_SCANCODE_TAB:
    return InputKeys::tab;
    break;
  case SDL_SCANCODE_RETURN:
    return InputKeys::enter;
    break;
  case SDL_SCANCODE_LSHIFT:
    return InputKeys::lshift;
    break;
  case SDL_SCANCODE_RSHIFT:
    return InputKeys::rshift;
    break;
  case SDL_SCANCODE_LCTRL:
    return InputKeys::lctrl;
    break;
  case SDL_SCANCODE_RCTRL:
    return InputKeys::rctrl;
    break;
  case SDL_SCANCODE_LALT:
    return InputKeys::lalt;
    break;
  case SDL_SCANCODE_RALT:
    return InputKeys::ralt;
    break;
  case SDL_SCANCODE_0:
    return InputKeys::zero;
    break;
  case SDL_SCANCODE_1:
    return InputKeys::one;
    break;
  case SDL_SCANCODE_2:
    return InputKeys::two;
    break;
  case SDL_SCANCODE_3:
    return InputKeys::three;
    break;
  case SDL_SCANCODE_4:
    return InputKeys::four;
    break;
  case SDL_SCANCODE_5:
    return InputKeys::five;
    break;
  case SDL_SCANCODE_6:
    return InputKeys::six;
    break;
  case SDL_SCANCODE_7:
    return InputKeys::seven;
    break;
  case SDL_SCANCODE_8:
    return InputKeys::eight;
    break;
  case SDL_SCANCODE_9:
    return InputKeys::nine;
    break;
  case SDL_SCANCODE_A:
    return InputKeys::a;
    break;
  case SDL_SCANCODE_B:
    return InputKeys::b;
    break;
  case SDL_SCANCODE_C:
    return InputKeys::c;
    break;
  case SDL_SCANCODE_D:
    return InputKeys::d;
    break;
  case SDL_SCANCODE_E:
    return InputKeys::e;
    break;
  case SDL_SCANCODE_F:
    return InputKeys::f;
    break;
  case SDL_SCANCODE_G:
    return InputKeys::g;
    break;
  case SDL_SCANCODE_H:
    return InputKeys::h;
    break;
  case SDL_SCANCODE_I:
    return InputKeys::i;
    break;
  case SDL_SCANCODE_J:
    return InputKeys::j;
    break;
  case SDL_SCANCODE_K:
    return InputKeys::k;
    break;
  case SDL_SCANCODE_L:
    return InputKeys::l;
    break;
  case SDL_SCANCODE_M:
    return InputKeys::m;
    break;
  case SDL_SCANCODE_N:
    return InputKeys::n;
    break;
  case SDL_SCANCODE_O:
    return InputKeys::o;
    break;
  case SDL_SCANCODE_P:
    return InputKeys::p;
    break;
  case SDL_SCANCODE_Q:
    return InputKeys::q;
    break;
  case SDL_SCANCODE_R:
    return InputKeys::r;
    break;
  case SDL_SCANCODE_S:
    return InputKeys::s;
    break;
  case SDL_SCANCODE_T:
    return InputKeys::t;
    break;
  case SDL_SCANCODE_U:
    return InputKeys::u;
    break;
  case SDL_SCANCODE_V:
    return InputKeys::v;
    break;
  case SDL_SCANCODE_W:
    return InputKeys::w;
    break;
  case SDL_SCANCODE_X:
    return InputKeys::x;
    break;
  case SDL_SCANCODE_Y:
    return InputKeys::y;
    break;
  case SDL_SCANCODE_Z:
    return InputKeys::z;
    break;
  case SDL_SCANCODE_SPACE:
    return InputKeys::space;
    break;
  case SDL_SCANCODE_GRAVE:
    return InputKeys::grave;
    break;
  case SDL_SCANCODE_MINUS:
    return InputKeys::minus;
    break;
  case SDL_SCANCODE_EQUALS:
    return InputKeys::equals;
    break;
  case SDL_SCANCODE_LEFTBRACKET:
    return InputKeys::lbracket;
    break;
  case SDL_SCANCODE_RIGHTBRACKET:
    return InputKeys::rbracket;
    break;
  case SDL_SCANCODE_BACKSLASH:
    return InputKeys::backslash;
    break;
  case SDL_SCANCODE_SEMICOLON:
    return InputKeys::semicolon;
    break;
  case SDL_SCANCODE_APOSTROPHE:
    return InputKeys::apostrophe;
    break;
  case SDL_SCANCODE_COMMA:
    return InputKeys::comma;
    break;
  case SDL_SCANCODE_PERIOD:
    return InputKeys::period;
    break;
  case SDL_SCANCODE_SLASH:
    return InputKeys::slash;
    break;
  case SDL_SCANCODE_F1:
    return InputKeys::f1;
    break;
  case SDL_SCANCODE_F2:
    return InputKeys::f2;
    break;
  case SDL_SCANCODE_F3:
    return InputKeys::f3;
    break;
  case SDL_SCANCODE_F4:
    return InputKeys::f4;
    break;
  case SDL_SCANCODE_F5:
    return InputKeys::f5;
    break;
  case SDL_SCANCODE_F6:
    return InputKeys::f6;
    break;
  case SDL_SCANCODE_F7:
    return InputKeys::f7;
    break;
  case SDL_SCANCODE_F8:
    return InputKeys::f8;
    break;
  case SDL_SCANCODE_F9:
    return InputKeys::f9;
    break;
  case SDL_SCANCODE_F10:
    return InputKeys::f10;
    break;
  case SDL_SCANCODE_F11:
    return InputKeys::f11;
    break;
  case SDL_SCANCODE_F12:
    return InputKeys::f12;
    break;
  case SDL_SCANCODE_PRINTSCREEN:
    return InputKeys::printscreen;
    break;
  case SDL_SCANCODE_PAUSE:
    return InputKeys::pause;
    break;
  case SDL_SCANCODE_INSERT:
    return InputKeys::insert;
    break;
  case SDL_SCANCODE_HOME:
    return InputKeys::home;
    break;
  case SDL_SCANCODE_PAGEUP:
    return InputKeys::pageup;
    break;
  case SDL_SCANCODE_DELETE:
    return InputKeys::deletekey;
    break;
  case SDL_SCANCODE_END:
    return InputKeys::end;
    break;
  case SDL_SCANCODE_PAGEDOWN:
    return InputKeys::pagedown;
    break;
  case SDL_SCANCODE_UP:
    return InputKeys::up;
    break;
  case SDL_SCANCODE_DOWN:
    return InputKeys::down;
    break;
  case SDL_SCANCODE_LEFT:
    return InputKeys::left;
    break;
  case SDL_SCANCODE_RIGHT:
    return InputKeys::right;
    break;
  case SDL_SCANCODE_KP_DIVIDE:
    return InputKeys::kp_divide;
    break;
  case SDL_SCANCODE_KP_MULTIPLY:
    return InputKeys::kp_multiply;
    break;
  case SDL_SCANCODE_KP_MINUS:
    return InputKeys::kp_minus;
    break;
  case SDL_SCANCODE_KP_PLUS:
    return InputKeys::kp_plus;
    break;
  case SDL_SCANCODE_KP_ENTER:
    return InputKeys::kp_enter;
    break;
  case SDL_SCANCODE_KP_0:
    return InputKeys::kp_zero;
    break;
  case SDL_SCANCODE_KP_1:
    return InputKeys::kp_one;
    break;
  case SDL_SCANCODE_KP_2:
    return InputKeys::kp_two;
    break;
  case SDL_SCANCODE_KP_3:
    return InputKeys::kp_three;
    break;
  case SDL_SCANCODE_KP_4:
    return InputKeys::kp_four;
    break;
  case SDL_SCANCODE_KP_5:
    return InputKeys::kp_five;
    break;
  case SDL_SCANCODE_KP_6:
    return InputKeys::kp_six;
    break;
  case SDL_SCANCODE_KP_7:
    return InputKeys::kp_seven;
    break;
  case SDL_SCANCODE_KP_8:
    return InputKeys::kp_eight;
    break;
  case SDL_SCANCODE_KP_9:
    return InputKeys::kp_nine;
    break;
  case SDL_SCANCODE_KP_PERIOD:
    return InputKeys::kp_period;
    break;
  default:
    return InputKeys::dummy;
    break;
  };
  
}


};

#endif