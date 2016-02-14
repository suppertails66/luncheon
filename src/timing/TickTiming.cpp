#include "timing/TickTiming.h"
#include "timing/GTick.h"

namespace Luncheon {


const double TickTiming::GTicksPerSecond_ = 960;

const double TickTiming::RTicksPerSecond_ = 1000;

double TickTiming::GTicksPerSecond() {
  return GTicksPerSecond();
}
  
double TickTiming::GTicksPerFrame(int framesPerSecond) {
  return (GTicksPerSecond_/(double)framesPerSecond);
}

double TickTiming::RTicksPerSecond() {
  return RTicksPerSecond();
}
  
double TickTiming::RTicksPerFrame(int framesPerSecond) {
  return (RTicksPerSecond_/(double)framesPerSecond);
}


}; 
