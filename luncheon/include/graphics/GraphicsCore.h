#ifndef GRAPHICSCORE_H
#define GRAPHICSCORE_H

#include "graphics/GraphicsCoreType.h"
#include "graphics/GraphicSurface.h"
#include "graphics/GameWindow.h"
#include "graphics/DrawableSurface.h"
#include "animation/AnimationLoader.h"
#include "resource/AnimationResourceFileLoader.h"
#include "resource/ResourceID.h"
#include "animation/ResourceIDAnimationMap.h"
#include "animation/AnimationPlayer.h"
#include "resource/LoadCountMap.h"
#include <string>
#include <map>

namespace Luncheon {


class GameWindow;

class GraphicsCore {
public:
  virtual ~GraphicsCore();
  
  virtual AnimationLoader& loader();
  
  // Abstract functions
  
  virtual GraphicSurface* createGraphicSurface(int w,
                                               int h) =0;
  
  virtual DrawableSurface* createDrawableSurface(int w,
                                                int h) =0;
                                               
  // should probably remove this once better methods are implemented
  virtual GraphicSurface* loadBMPFromFile(const std::string& filename) =0;
  
  // Provided functions
  
  virtual GraphicsCoreTypes::GraphicsCoreType coreType() const;
  virtual void setCoreType(GraphicsCoreTypes::GraphicsCoreType coreType__);
  
  virtual GameWindow& gameWindow();
  
  virtual void loadAnimation(ResourceID id);
  
  virtual void unloadAnimation(ResourceID id);
  
  virtual void unloadAllAnimations();
  
  virtual AnimationPlayer* createAnimationPlayer(ResourceID id);
  
protected:
  const static char* graphicsResourceFileName_;

  GraphicsCore();
  
  GraphicsCoreTypes::GraphicsCoreType coreType_;
  
  GameWindow* gameWindow_;
  
  AnimationLoader loader_;
  
  AnimationResourceFileLoader resourceFile_;
  
  ResourceIDAnimationMap loadedAnimations_;
  
  LoadCountMap loadedAnimationCounts_;
  
};


};


#endif
