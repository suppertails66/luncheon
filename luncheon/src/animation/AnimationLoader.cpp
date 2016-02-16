#include "animation/AnimationLoader.h"
#include "animation/SerializableAnimation.h"
#include "animation/SerializableSimpleAnimation.h"
#include "resource/AnimationTypeID.h"
#include "animation/SimpleAnimation.h"
#include "graphics/GraphicsCore.h"

namespace Luncheon {


AnimationLoader::~AnimationLoader() { };

AnimationLoader::AnimationLoader() { };
  
Animation* AnimationLoader::loadAnimation(
                         IndexResourceChunkEntry indexEntry,
                         ResourceFileHandle& fileHandle,
                         GraphicsCore& graphicsCore_) {
  
  SerializableAnimation* loadedAnimation = createSerializableAnimation(
                                             indexEntry,
                                             fileHandle);
  
/*  SerializableAnimation* loadedAnimation;
  
  // If I ever implment multiple animation types,
  // the switch statement goes here
  
  loadedAnimation = new SerializableSimpleAnimation();
  
  fileHandle.seek(indexEntry.address());
  
  loadedAnimation->read(fileHandle.resourceFile()); */
  
  Animation* animation
    = loadedAnimation->convertToAnimation(graphicsCore_);
  
  delete loadedAnimation;
                         
  return animation;
}
                                   
SerializableAnimation* AnimationLoader::createSerializableAnimation(
                                 IndexResourceChunkEntry indexEntry,
                                 ResourceFileHandle& fileHandle_) {
  SerializableAnimation* loadedAnimation;
  
  // If I ever implment multiple animation types,
  // the switch statement goes here
  
  loadedAnimation = new SerializableSimpleAnimation();
  
  fileHandle_.seek(indexEntry.address());
  
  loadedAnimation->read(fileHandle_.resourceFile());
  
  return loadedAnimation;
}


}; 
