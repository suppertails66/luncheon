#include "timing/SDL2TimingCore.h"

namespace Luncheon {


bool SDL2TimingCore::delayFinished(false);
  
SDL2TimingCore::~SDL2TimingCore() { };

SDL2TimingCore::SDL2TimingCore() { };
  
RTick SDL2TimingCore::getTicks() {
  return SDL_GetTicks();
}
  
void SDL2TimingCore::delay(RTick ticks) {

  SDL_Delay(ticks);

/*  
  // this is broken

  SDL_AddTimer(ticks, delayCallback, &delayFinished);
  
  while (!delayFinished); */
}
  
Uint32 SDL2TimingCore::delayCallback(Uint32 interval, void* param) {
  bool& target = *((bool*)param);
  
  target = false;
  
  return interval;
}


}; 
