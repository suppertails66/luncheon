#ifndef SIMPLEANIMATIONFRAME_H
#define SIMPLEANIMATIONFRAME_H


#include "animation/AnimationFrame.h"
#include "graphics/GraphicSurface.h"
#include "timing/GTick.h"

namespace Luncheon {


class SimpleAnimationFrame : public AnimationFrame {
public:
  virtual ~SimpleAnimationFrame();
  
  SimpleAnimationFrame();
  
  SimpleAnimationFrame(GraphicSurface* graphic__,
                       GTick duration,
                       int xOffset__,
                       int yOffset__);
  
  virtual GraphicSurface& graphic();
  
  virtual GTick duration();
  
  virtual int xOffset();
  
  virtual int yOffset();
protected:

  GraphicSurface* graphic_;
  
  GTick duration_;
  
  int xOffset_;
  
  int yOffset_;
  
};


};


#endif
