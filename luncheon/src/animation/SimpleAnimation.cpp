#include "animation/SimpleAnimation.h"
#include "animation/SimpleAnimationFrame.h"
#include "timing/GTick.h"

namespace Luncheon {


SimpleAnimation::~SimpleAnimation() { };

SimpleAnimation::SimpleAnimation()
  : Animation(),
    looping_(false),
    loopStart_(0),
    loopEnd_(-1),
    manualLoopEnd_(false) { };
  
void SimpleAnimation::addFrame(GraphicSurface* surface,
                               GTick duration,
                               int xOffset,
                               int yOffset) {
  SimpleAnimationFrame* newFrame = new SimpleAnimationFrame(surface,
                                                            duration,
                                                            xOffset,
                                                            yOffset);
  frames_.push_back(newFrame);
  
  // if using automatic loop endpoint, increment loop endpoint
  // to newly added frame
  if (!manualLoopEnd_) {
    ++loopEnd_;
  }
}
                        
bool SimpleAnimation::looping() const {
  return looping_;
}
void SimpleAnimation::setLooping(bool looping__) {
  looping_ = looping__;
}

int SimpleAnimation::loopStart() const {
  return loopStart_;
}
void SimpleAnimation::setLoopStart(int loopStart__) {
  loopStart_ = loopStart__;
}

int SimpleAnimation::loopEnd() const {
  return loopEnd_;
}
void SimpleAnimation::setLoopEnd(int loopEnd__) {
  loopEnd_ = loopEnd__;
  
  if (!manualLoopEnd_) {
    manualLoopEnd_ = true;
  }
}


};
