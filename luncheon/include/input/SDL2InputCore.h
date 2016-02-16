#ifndef SDL2INPUTCORE_H
#define SDL2INPUTCORE_H


#ifdef LUNCHEON_ENABLE_SDL2

#include "input/InputCore.h"
#include "SDL.h"

namespace Luncheon {


class SDL2InputCore : public InputCore {
public:
  virtual ~SDL2InputCore();
  
  SDL2InputCore();
  
  virtual void updateInputs();
  
  virtual void rememberFirstTriggeredInputKey();
protected:

  void handleKeyPress(SDL_KeyboardEvent& keyEvent);

  void handleKeyRelease(SDL_KeyboardEvent& keyEvent);

  void handleQuitEvent(SDL_QuitEvent& quitEvent);
  
  void pressKey(InputKeys::InputKey key);
  
  void releaseKey(InputKeys::InputKey key);
  
  InputKeys::InputKey mapSDLScancodeToInputKey(SDL_Scancode scancode);
  
  bool waitingForFirstTriggeredInputKey_;
  
};


};

#endif


#endif 
