#include "resource/AnimationResourceFileLoader.h"
#include "graphics/GraphicsCore.h"
#include "animation/SerializableAnimation.h"

namespace Luncheon {


AnimationResourceFileLoader::~AnimationResourceFileLoader() { };
  
AnimationResourceFileLoader::AnimationResourceFileLoader(
                                   const std::string& filename)
  : ResourceFileLoader(filename) { };
  
Animation* AnimationResourceFileLoader::loadAnimationFile(
                                   ResourceID id,
                                   AnimationLoader& animationLoader,
                                   GraphicsCore& graphicsCore) {
  IndexResourceChunkEntry entry = index_.getIndexEntry(id);
  
  return animationLoader.loadAnimation(entry,
                                       fileHandle_,
                                       graphicsCore);
}
                                   
SerializableAnimation* AnimationResourceFileLoader
  ::createSerializableAnimation(ResourceID id) {
  IndexResourceChunkEntry entry = index_.getIndexEntry(id);
  
  return AnimationLoader::createSerializableAnimation(
                                       entry,
                                       fileHandle_);
}


}; 
