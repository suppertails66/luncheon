#ifndef GAMEMEMORY_H
#define GAMEMEMORY_H


#include "graphics/GraphicsCore.h"
#include "font/FontCore.h"
#include "sound/SoundCore.h"
#include "input/InputCore.h"
#include "timing/TimingCore.h"

namespace Luncheon {


class GameMemory {
public:
  virtual ~GameMemory();
  
  GraphicsCore& graphicsCore();
  
  FontCore& fontCore();
  
  SoundCore& soundCore();
  
  InputCore& inputCore();
  
  TimingCore& timingCore();
  
  virtual int framesPerSecond();
  virtual void setFramesPerSecond(int framesPerSecond__);
  
  virtual int currentScene();
  virtual void setCurrentScene(int currentScene__);
  virtual void changeCurrentScene(int currentScene__);
  
  virtual bool needsSceneChange();
  virtual void setNeedsSceneChange(bool needsSceneChange__);
  
protected:
  GameMemory(GraphicsCore& graphicsCore__,
             FontCore& fontCore__,
             SoundCore& soundCore__,
             InputCore& inputCore__,
             TimingCore& timingCore__);
  
  GraphicsCore& graphicsCore_;
  FontCore& fontCore_;
  SoundCore& soundCore_;
  InputCore& inputCore_;
  TimingCore& timingCore_;
  
  int framesPerSecond_;
  
  int currentScene_;
  
  bool needsSceneChange_;
};


};


#endif 
