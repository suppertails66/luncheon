#ifndef TIMINGCORE_H
#define TIMINGCORE_H


#include "RTick.h"

namespace Luncheon {


class TimingCore {
public:
  virtual ~TimingCore();
  
  virtual RTick getTicks() =0;
  
  virtual void delay(RTick ticks) =0;
protected:
  TimingCore();
};


};


#endif 
