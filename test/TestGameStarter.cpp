#include "TestGameStarter.h"
#include "TestMemory.h"
#include "StartupScene.h"
#include "TestSceneType.h"
#include "logic/CoreManager.h"
#include <iostream>

using namespace Luncheon;

namespace LuncheonTest {


TestGameStarter::TestGameStarter()
  : GameStarter() { };

void TestGameStarter::startGame() {
  coreManager_.setGraphicsCoreType(GraphicsCoreTypes::SDL2);
  coreManager_.setFontCoreType(FontCoreTypes::FreeType);
  coreManager_.setSoundCoreType(SoundCoreTypes::SDL2);
  coreManager_.setInputCoreType(InputCoreTypes::SDL2);
  coreManager_.setTimingCoreType(TimingCoreTypes::SDL2);
  
  coreManager_.initializeCores();
                                                       
  coreManager_.graphicsCore().gameWindow().changeWindowTitle("Test window");
  
  coreManager_.graphicsCore().gameWindow().createWindow(640,
                                                       480,
                                                       100,
                                                       100,
                                                       320,
                                                       240);
  
  TestMemory* sMemory = new TestMemory(coreManager_.graphicsCore(),
                               coreManager_.fontCore(),
                               coreManager_.soundCore(),
                               coreManager_.inputCore(),
                               coreManager_.timingCore());
                               
  sMemory_ = DumbPointer<TestMemory>(sMemory);
  
  memory_ = sMemory;
                               
  scene_ = new StartupScene(*sMemory);
  sMemory->setCurrentScene(TestSceneTypes::startup);
  sMemory->setNeedsSceneChange(false);
                               
  sMemory->setFramesPerSecond(60);
    
  gameLoop();
}

void TestGameStarter::changeScene(int newScene) {
  delete scene_;
  
  switch (static_cast<TestSceneTypes::TestSceneType>(newScene)) {
  case TestSceneTypes::dummy:
    // CRASH
    scene_ = 0;
    break;
  case TestSceneTypes::startup:
    scene_ = new StartupScene(sMemory_.reference());
    break;
  default:
    // CRASH
    scene_ = 0;
    break;
  }
}


};
