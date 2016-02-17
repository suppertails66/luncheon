#ifndef STARTUPSCENE_H
#define STARTUPSCENE_H


#include "logic/GameScene.h"
#include "TestMemory.h"

namespace LuncheonTest {


class StartupScene : public Luncheon::GameScene {
public:
  StartupScene(TestMemory& testMemory__);
  
  virtual void update(Luncheon::GTick ticks);
  
  virtual void draw(Luncheon::ScreenBuffer& buffer);
protected:
  
};


};


#endif
