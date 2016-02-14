#ifndef SERIALIZABLERLE8ANIMATIONFRAME_H
#define SERIALIZABLERLE8ANIMATIONFRAME_H


#include "animation/SerializableAnimationFrame.h"
#include "animation/SerializableRawAnimationFrame.h"
#include "graphics/DrawColor.h"
#include "graphics/DrawPosition.h"
#include "graphics/ColorMap.h"
#include "graphics/ReverseColorMap.h"
#include "util/RLE8Compressor.h"
#include "util/RLE8CommandCollection.h"

namespace Luncheon {


class SerializableRLE8AnimationFrame : public SerializableRawAnimationFrame {
public:
  virtual ~SerializableRLE8AnimationFrame();
  
  SerializableRLE8AnimationFrame();
  
  virtual void calculateAndSetSizeFields();
  
  virtual void read(std::istream& ifs);
  
  virtual void write(std::ostream& ofs);
  
  virtual void compressPixels();
  
  virtual void decompressPixels();
protected:

  ReverseColorMap internalColorMap;

  ColorMap externalColorMap;
  
  RLE8CommandCollection compressionCommands;
  
  char* simplifiedColorData_;
  
  int simplifiedColorDataSize_;
  
  char* loadedCompressedData_;
  
  int loadedCompressedDataSize_;
  
  virtual void simplifyColors();

};


};


#endif 
