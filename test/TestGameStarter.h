#ifndef TESTGAMESTARTER_H
#define TESTGAMESTARTER_H

#include "TestMemory.h"
#include "logic/GameStarter.h"
#include "util/DumbPointer.h"

namespace LuncheonTest {


class TestGameStarter : public Luncheon::GameStarter {
public:
  TestGameStarter();
  
  virtual void startGame();
protected:
  virtual void changeScene(int newScene);
  
  Luncheon::DumbPointer<TestMemory> sMemory_;
  
};


};


#endif
