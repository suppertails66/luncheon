#ifndef DRAWABLESURFACE_H
#define DRAWABLESURFACE_H


#include "graphics/DrawPosition.h"
#include "graphics/DrawColor.h"
#include "graphics/GraphicSurface.h"

namespace Luncheon {


class GraphicsCore;

class DrawableSurface {
public:
  virtual ~DrawableSurface();
  
  virtual DrawPosition draw(DrawPosition pos,
                    DrawColor color,
                    int length) =0;
                    
  virtual void blit(DrawableSurface& source,
            int x,
            int y,
            int w = 0,
            int h = 0) =0;
            
  virtual void update() =0;
            
  virtual int getWidth() =0;
  
  virtual int getHeight() =0;
  
  virtual GraphicSurface* toGraphicSurface(GraphicsCore& graphicsCore) =0;
protected:
  DrawableSurface();
};


};


#endif 
