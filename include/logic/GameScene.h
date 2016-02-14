#ifndef GAMESCENE_H
#define GAMESCENE_H


#include "logic/GameObjectManager.h"
#include "logic/GameMemory.h"
#include "timing/TickTiming.h"
#include "graphics/ScreenBuffer.h"

namespace Luncheon {


class GameScene {
public:
  virtual ~GameScene();
  
  virtual void update(GTick ticks) =0;
  
  virtual void draw(ScreenBuffer& buffer) =0;
  
  virtual GameObjectManager& objectManager();
  
  virtual bool hasFocus();
  virtual void setHasFocus(bool hasFocus__);
  
  virtual bool needsDestruction();
  virtual void setNeedsDestruction(bool needsDestruction__);
  
  virtual bool hasParent();
  virtual bool hasChild();
  
  virtual GameScene& parent();
  virtual GameScene& child();
  
  virtual void setParent(GameScene* parent__);
  
  virtual void changeChild(GameScene* child__);
  
  virtual void destroyChild();
protected:
  GameScene(GameMemory& gameMemory__);
  
  GameObjectManager objectManager_;
  
  GameMemory& gameMemory_;
  
  GameScene* parent_;
  
  GameScene* child_;
  
  bool hasFocus_;
  
  bool needsDestruction_;
};


};


#endif 
