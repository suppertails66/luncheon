#include "graphics/GraphicsCore.h"
#include "graphics/GraphicsCoreType.h"
#include "animation/SimpleAnimationPlayer.h"
#include <iostream>

namespace Luncheon {


GraphicsCore::~GraphicsCore() { 
  delete gameWindow_;
  
  for (ResourceIDAnimationMap::iterator it = loadedAnimations_.begin();
       it != loadedAnimations_.end();
       it++) {
    delete (it->second);
  }
}
  
GraphicsCore::GraphicsCore()
  : coreType_(GraphicsCoreTypes::dummy),
    gameWindow_(0),
    resourceFile_("res/animation.res") { };

GraphicsCoreTypes::GraphicsCoreType GraphicsCore::coreType() const {
  return coreType_;
}
  
AnimationLoader& GraphicsCore::loader() {
  return loader_;
}

void GraphicsCore::setCoreType(
                  GraphicsCoreTypes::GraphicsCoreType coreType__) {
  coreType_ = coreType__;
}
  
GameWindow& GraphicsCore::gameWindow() {
  return *gameWindow_;
}
  
void GraphicsCore::loadAnimation(ResourceID id) {
  ResourceIDAnimationMap::iterator target
      = loadedAnimations_.find(id);
  
  // No double loading
  if (target != loadedAnimations_.end()) {
    // Increase load count
    ++(loadedAnimationCounts_.find(id)->second);
    return;
  }

  Animation* loadedAnimation 
    = resourceFile_.loadAnimationFile(id, 
                                      loader_,
                                      *this);
    
  loadedAnimations_.insert(ResourceIDAnimationMapPair(id, loadedAnimation));
  loadedAnimationCounts_.insert(LoadCountMapPair(id, 1));
}
  
void GraphicsCore::unloadAnimation(ResourceID id) {
  ResourceIDAnimationMap::iterator target
    = loadedAnimations_.find(id);
  
  if (target == loadedAnimations_.end()) {
    return;
  }
  
  LoadCountMap::iterator targetCount = loadedAnimationCounts_
    .find(id);
    
  // If load count is 1, unload the resource
  if (targetCount->second == 1) {
    loadedAnimationCounts_.erase(targetCount);
    delete target->second;
    loadedAnimations_.erase(id);
  }
  // Otherwise, decrement the load count
  else {
    --(targetCount->second);
  }
}
  
void GraphicsCore::unloadAllAnimations() {
  while (loadedAnimations_.size()) {
    delete ((loadedAnimations_.begin())->second);
    loadedAnimations_.erase(loadedAnimations_.begin());
  }
  loadedAnimationCounts_.clear();
}
  
AnimationPlayer* GraphicsCore::createAnimationPlayer(ResourceID id) {
  ResourceIDAnimationMap::iterator target
    = loadedAnimations_.find(id);
  
  if (target == loadedAnimations_.end()) {
    return 0;
  }
  
  return new SimpleAnimationPlayer(target->second);
}


};
