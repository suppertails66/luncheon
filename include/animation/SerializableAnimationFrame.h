#ifndef SERIALIZABLEANIMATIONFRAME_H
#define SERIALIZABLEANIMATIONFRAME_H


#include "util/ByteSizes.h"
#include "util/ByteConversion.h"
#include "util/EndiannessType.h"
#include "util/SignednessType.h"
#include "resource/ResourceID.h"
#include "animation/AnimationFrame.h"
#include <istream>
#include <ostream>

namespace Luncheon {


class GraphicsCore;

class SerializableAnimationFrame {
public:
  virtual ~SerializableAnimationFrame();
  
  ResourceID animationTypeID();
  void setAnimationTypeID(ResourceID animationTypeID__);
  
  int totalSize();
  void setTotalSize(int totalSize__);
  
  int width();
  void setWidth(int width__);
  
  int height();
  void setHeight(int height__);
  
  int xOffset();
  void setXOffset(int xOffset__);
  
  int yOffset();
  void setYOffset(int yOffset__);
  
  int duration();
  void setDuration(int duration__);
  
  ResourceID imageDataFormat();
  void setImageDataFormat(ResourceID imageDataFormat__);
  
  int imageDataSize();
  void setImageDataSize(int imageDataSize__);
  
  virtual void read(std::istream& ifs);
  
  virtual void write(std::ostream& ofs);
  
  virtual char* pixels() =0;
                        
  virtual AnimationFrame* convertToAnimationFrame(
                              GraphicsCore& graphicsCore) =0;
  
  virtual void calculateAndSetSizeFields() =0;
  
protected:
  SerializableAnimationFrame();
  
  virtual int baseSize();
  
  virtual void readStandardBlocks(std::istream& ifs);
  
  virtual void writeStandardBlocks(std::ostream& ofs);
  
  char byteBuffer[ByteSizes::uint128Size];
  
  ResourceID animationTypeID_;
  
  int totalSize_;
  
  int width_;
  
  int height_;
  
  int xOffset_;
  
  int yOffset_;
  
  int duration_;
  
  ResourceID imageDataFormat_;
  
  int imageDataSize_;
};


};


#endif 
