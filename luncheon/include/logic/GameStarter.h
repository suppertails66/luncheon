#ifndef GAME_STARTER_H
#define GAME_STARTER_H


#include "CoreManager.h"
#include "logic/GameMemory.h"
#include "logic/GameScene.h"

namespace Luncheon {


class GameStarter {
public:
  virtual ~GameStarter();
  
  virtual void gameLoop();
  
  virtual void startGame() =0;
  
protected:
  GameStarter();
  
  virtual void changeScene(int newScene) =0;
  
  CoreManager coreManager_;
  
  GameMemory* memory_;
  
  GameScene* scene_;
  
  virtual void sceneUpdateStep(GameScene& scene);
  
  virtual void sceneDrawStep(GameScene& scene);
  
};


};



#endif
