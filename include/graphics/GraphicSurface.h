#ifndef GRAPHICSURFACE_H
#define GRAPHICSURFACE_H


#include "graphics/DrawPosition.h"
#include "graphics/DrawColor.h"

namespace Luncheon {


class GraphicSurface {
public:
  virtual ~GraphicSurface();
  
  virtual void lock();
  
  virtual void unlock();
  
  virtual bool locked() const;
  
  virtual int getWidth() const =0;
  
  virtual int getHeight() const =0;
  
  virtual void draw(const GraphicSurface& source,
                    int x,
                    int y,
                    int w = 0,
                    int h = 0) =0;
                    
  virtual DrawPosition drawPixels(const DrawPosition& pos,
                          const DrawColor& color,
                          int length) =0;
  
protected:
  GraphicSurface();
  
  bool locked_;
  
};


};


#endif
