#ifndef SDL2TIMINGCORE_H
#define SDL2TIMINGCORE_H


#ifdef LUNCHEON_ENABLE_SDL2

#include "timing/TimingCore.h"
#include "SDL.h"

namespace Luncheon {


class SDL2TimingCore : public TimingCore {
public:
  virtual ~SDL2TimingCore();
  
  SDL2TimingCore();
  
  virtual RTick getTicks();
  
  virtual void delay(RTick ticks);
protected:

  static bool delayFinished;
  
  static Uint32 delayCallback(Uint32 interval, void* param);

};


};

#endif


#endif 
