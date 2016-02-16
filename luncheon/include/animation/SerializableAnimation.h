#ifndef SERIALIZABLEANIMATION_H
#define SERIALIZABLEANIMATION_H


#include "animation/SerializableAnimationFrame.h"
#include "animation/SerializableRawAnimationFrame.h"
#include "animation/SerializableRLE8AnimationFrame.h"
#include "animation/SerializableAnimationFrameCollection.h"
#include "resource/ResourceID.h"
#include "resource/AnimationTypeID.h"
#include "util/ByteSizes.h"
#include "util/ByteConversion.h"
#include "util/EndiannessType.h"
#include "util/SignednessType.h"
#include "animation/Animation.h"
#include <istream>
#include <ostream>

namespace Luncheon {


class GraphicsCore;

class SerializableAnimation {
public:
  virtual ~SerializableAnimation();
  
  SerializableAnimationFrameCollection& frames();
  
  ResourceID typeID();
  void setTypeID(ResourceID typeID__);
  
  int totalSize();
  void setTotalSize(int totalSize__);
  
  bool looping();
  void setLooping(bool looping__);
  
  int loopStart();
  void setLoopStart(int loopStart__);
  
  int loopEnd();
  void setLoopEnd(int loopEnd__);
  
  
  
  virtual int baseSize();
  
  virtual int numFrames();
  
  virtual int calculateFrameDataSize();
  
  virtual void calculateAndUpdateSizeFields();
  
  virtual void addFrame(SerializableAnimationFrame* frame);
  
  virtual SerializableAnimationFrame& frame(int pos);
  
//  virtual void readStandardBlocks(std::istream& ifs);
  
//  virtual void writeStandardBlocks(std::ostream& ofs);
  
  virtual void read(std::istream& ifs);
  
  virtual void write(std::ostream& ofs);
  
  virtual Animation* convertToAnimation(GraphicsCore& graphicsCore);
protected:
  SerializableAnimation();
  
  char byteBuffer[ByteSizes::uint128Size];
  
  SerializableAnimationFrameCollection frames_;
  
  ResourceID typeID_;
  
  int totalSize_;
  
  bool looping_;
  
  int loopStart_;
  
  int loopEnd_;
  
  // numFrames
  
  // frameDataSize
};


};


#endif 
