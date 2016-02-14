#ifndef SERIALIZABLERAWANIMATIONFRAME_H
#define SERIALIZABLERAWANIMATIONFRAME_H


#include "animation/SerializableAnimationFrame.h"
#include "graphics/DrawColor.h"
#include "graphics/DrawPosition.h"

namespace Luncheon {


class SerializableRawAnimationFrame : public SerializableAnimationFrame {
public:
  virtual ~SerializableRawAnimationFrame();
  
  SerializableRawAnimationFrame();
  
  virtual void read(std::istream& ifs);
  
  virtual void write(std::ostream& ofs);
  
  virtual void calculateAndSetSizeFields();
  
  virtual void resizeImage(int w, int h);
  
  virtual void clearImage(DrawColor color);
  
  virtual DrawColor getPixel(DrawPosition pos);
  
  virtual void putPixel(DrawPosition pos,
                        DrawColor color);
  
  virtual char* pixels();
                        
  virtual AnimationFrame* convertToAnimationFrame(
                              GraphicsCore& graphicsCore);
protected:
  
  char* pixels_;
  
  int pixelsSize_;
  
};


};


#endif 
