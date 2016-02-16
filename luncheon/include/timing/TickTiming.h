#ifndef TICKTIMING_H
#define TICKTIMING_H


#include "timing/GTick.h"

namespace Luncheon {


class TickTiming {
public:
  
  static double GTicksPerSecond();
  
  static double GTicksPerFrame(int framesPerSecond);
  
  static double RTicksPerSecond();
  
  static double RTicksPerFrame(int framesPerSecond);
  
protected:
  
  const static double GTicksPerSecond_;
  
  const static double RTicksPerSecond_;
};


};


#endif 
