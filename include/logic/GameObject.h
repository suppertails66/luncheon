#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H


#include "logic/GameObjectID.h"
#include "logic/GameMemory.h"
#include "timing/GTick.h"
#include "logic/GameObjectManager.h"
#include "graphics/ScreenBuffer.h"

namespace Luncheon {


class GameScene;

class GameObject {
public:
  virtual ~GameObject();
  
  virtual GameObjectID objectID();
  
  virtual void update(GTick ticks);
  
  virtual void draw(ScreenBuffer& buffer);
  
  virtual void draw(ScreenBuffer& buffer,
                    int drawX,
                    int drawY);
  
/*  virtual int drawX();
  virtual void setDrawX(int drawX__);
  
  virtual int drawY();
  virtual void setDrawY(int drawY__); */
  
  virtual bool hidden();
  virtual void setHidden(bool hidden__);
  
  virtual void die();
  virtual bool dead();
  
  virtual GameObjectManager& children();
  virtual GameObjectManager& subChildren();
protected:
  virtual void updateSelf(GTick ticks) =0;
  
  virtual void drawSelf(ScreenBuffer& buffer);
  
  virtual void drawSelf(ScreenBuffer& buffer,
                        int drawX,
                        int drawY) =0;
  
  GameObject(GameMemory& gameMemory__,
             GameScene& parent__);
  
  GameObjectManager children_;
  GameObjectManager subChildren_;
             
  GameMemory& gameMemory_;
  
  GameScene& parent_;
  
//  int drawX_;
//  int drawY_;
  
  bool hidden_;
  
  bool dead_;
             
};


};


#endif 
