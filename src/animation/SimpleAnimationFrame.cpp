#include "animation/SimpleAnimationFrame.h"
#include "graphics/GraphicSurface.h"
#include "timing/GTick.h"

namespace Luncheon {


SimpleAnimationFrame::~SimpleAnimationFrame() {
  delete graphic_;
}

SimpleAnimationFrame::SimpleAnimationFrame()
  : AnimationFrame(),
    graphic_(0),
    duration_(0),
    xOffset_(0),
    yOffset_(0) { };
  
SimpleAnimationFrame::SimpleAnimationFrame(GraphicSurface* graphic__,
                                           GTick duration__,
                                           int xOffset__,
                                           int yOffset__)
  : AnimationFrame(),
    graphic_(graphic__),
    duration_(duration__),
    xOffset_(xOffset__),
    yOffset_(yOffset__) { };
  
GraphicSurface& SimpleAnimationFrame::graphic() {
  return *graphic_;
}
  
GTick SimpleAnimationFrame::duration() {
  return duration_;
}
  
int SimpleAnimationFrame::xOffset() {
  return xOffset_;
}

int SimpleAnimationFrame::yOffset() {
  return yOffset_;
}


}; 
