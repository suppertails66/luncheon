#ifndef SCREENBUFFER_H
#define SCREENBUFFER_H


#include "graphics/GraphicSurface.h"
#include "graphics/DrawableSurface.h"
#include "graphics/DrawColor.h"
#include "graphics/ClipArea.h"
#include "graphics/RectArea.h"

namespace Luncheon {


class ScreenBuffer {
public:
  virtual ~ScreenBuffer();
  
  virtual void lock();
  
  virtual void unlock();
  
  virtual bool locked() const;
  
  virtual void draw(GraphicSurface& source,
                    int x,
                    int y) =0;
  
  virtual void draw(DrawableSurface& source,
                    int x,
                    int y) =0;
                    
  virtual void drawRect(DrawColor color,
                        RectArea rect) =0;
                    
  virtual void clear() =0;
                    
  virtual void clear(DrawColor color) =0;
  
  virtual void flip() =0;
  
  virtual int getNativeWidth() =0;
  
  virtual int getNativeHeight() =0;
  
  virtual bool hasClipArea() =0;
  
  virtual ClipArea getClipArea() =0;
  
  virtual void setClipArea(ClipArea area) =0;
  
  virtual void clearClipArea() =0;
  
protected:
  ScreenBuffer();
  
  bool locked_;
};


};


#endif
