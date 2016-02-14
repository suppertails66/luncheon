#ifndef ANIMATIONRESOURCEFILELOADER_H
#define ANIMATIONRESOURCEFILELOADER_H


#include "resource/ResourceFileLoader.h"
#include "animation/Animation.h"
#include "resource/ResourceID.h"
#include "animation/AnimationLoader.h"
#include <string>

namespace Luncheon {


class GraphicsCore;
class SerializableAnimation;

class AnimationResourceFileLoader : public ResourceFileLoader {
public:
  virtual ~AnimationResourceFileLoader();
  
  AnimationResourceFileLoader(const std::string& filename);
  
  virtual Animation* loadAnimationFile(ResourceID id,
                                   AnimationLoader& animationLoader,
                                   GraphicsCore& graphicsCore);
                                   
  virtual SerializableAnimation* createSerializableAnimation(
    ResourceID id);
protected:
  
};


};


#endif 
