#include "logic/GameStarter.h"

namespace LuncheonTest {


class TestGameStarter : public Luncheon::GameStarter {
public:
  TestGameStarter();
  
  virtual void startGame();
protected:
  virtual void changeScene(int newScene);
  
};


};