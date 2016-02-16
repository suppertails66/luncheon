#ifndef RENDEREDFONTCHARACTER_H
#define RENDEREDFONTCHARACTER_H


#include "graphics/DrawableSurface.h"
#include "graphics/DrawColor.h"
#include "font/WritePosition.h"

namespace Luncheon {


class RenderedFontCharacter {
public:
  virtual ~RenderedFontCharacter();
  
  virtual DrawableSurface& generateDrawable(DrawColor color) =0;
  
  virtual WritePosition writeCharacter(DrawableSurface& destination,
                                       WritePosition penPosition) =0;
  
  virtual DrawableSurface& currentDrawable() =0;
  
  virtual DrawColor currentColor() =0;
  
  virtual int getBitmapLeft() =0;
  
  virtual int getBitmapTop() =0;
  
  virtual int getAdvanceX() =0;
  
  virtual int getAdvanceY() =0;
protected:
  RenderedFontCharacter();
};


};


#endif 
