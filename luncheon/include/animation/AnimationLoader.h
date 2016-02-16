#ifndef ANIMATIONLOADER_H
#define ANIMATIONLOADER_H


#include "resource/ResourceFileHandle.h"
#include "resource/IndexResourceChunkEntry.h"
#include "animation/Animation.h"

namespace Luncheon {


class GraphicsCore;
class SerializableAnimation;

class AnimationLoader {
public:
  virtual ~AnimationLoader();
  
  AnimationLoader();
  
  virtual Animation* loadAnimation(IndexResourceChunkEntry indexEntry,
                                   ResourceFileHandle& fileHandle_,
                                   GraphicsCore& graphicsCore_);
                                   
  static SerializableAnimation* createSerializableAnimation(
                                   IndexResourceChunkEntry indexEntry,
                                   ResourceFileHandle& fileHandle_);
protected:
};


};


#endif 
