#ifndef ANIMATIONFRAME_H
#define ANIMATIONFRAME_H


#include "graphics/GraphicSurface.h"
#include "timing/GTick.h"

namespace Luncheon {


class AnimationFrame {
public:
  virtual ~AnimationFrame();
  
  virtual GraphicSurface& graphic() =0;
  
  virtual GTick duration() =0;
  
  virtual int xOffset() =0;
  
  virtual int yOffset() =0;
protected:
  AnimationFrame();
};


};


#endif
