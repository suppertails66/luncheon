#include "GameStarter.h"
#include "timing/TickTiming.h"
#include <iostream>

namespace Luncheon {


GameStarter::~GameStarter() {
  delete scene_;
  delete memory_;
}
  
GameStarter::GameStarter()
  : memory_(0),
    scene_(0) { };
  
void GameStarter::gameLoop() {

  GraphicsCore& graphicsCore = coreManager_.graphicsCore();
  FontCore& fontCore = coreManager_.fontCore();
  SoundCore& soundCore = coreManager_.soundCore();
  InputCore& inputCore = coreManager_.inputCore();
  TimingCore& timingCore = coreManager_.timingCore();

  do {
    // Start frame timing
    int frameStart = timingCore.getTicks();
    
    // Calculate number of RTicks in the next frame
    int targetFrameTime = TickTiming::RTicksPerFrame(memory_->framesPerSecond());
    
    // Get new input
    inputCore.updateInputs();
    
    // Update sound queues
    soundCore.update();
    
    
    // Update scene
    sceneUpdateStep(*scene_);
    
    
    // Clear screen
    graphicsCore.gameWindow().screenBuffer().clear();
    
    // Draw scene
    sceneDrawStep(*scene_);
    
    // Refresh screen
    coreManager_.graphicsCore().gameWindow().flipToVisibleScreen();
    

    // Change scene if needed
    if (memory_->needsSceneChange()) {
      changeScene(memory_->currentScene());
      memory_->setNeedsSceneChange(false);
    }
    
    // End frame timing
    int frameEnd = timingCore.getTicks();
    
    int remainingTime = targetFrameTime - (frameEnd - frameStart);
    
//    std::cout << "Remaining time: " << remainingTime << std::endl;
    
    if (remainingTime > 0) {
      timingCore.delay(remainingTime);
    }
    
  } while (!inputCore.wantsQuit());
}
  
void GameStarter::sceneUpdateStep(GameScene& scene) {
  // Update child, if it exists, before scene ("bottom-to-top" ordering)
  if (scene.hasChild()) {
    sceneUpdateStep(scene.child());
    
    // Destroy the child if needed
    if (scene.child().needsDestruction()) {
      scene.destroyChild();
    }
  }
  // Update scene
  scene.update(TickTiming::GTicksPerFrame(memory_->framesPerSecond()));
}
  
void GameStarter::sceneDrawStep(GameScene& scene) {
  // Draw scene
  scene.draw(coreManager_.graphicsCore().gameWindow().screenBuffer());
  // Draw child, if it exists, after scene ("top-to-bottom" ordering)
  if (scene.hasChild()) {
    sceneDrawStep(scene.child());
  }
}


};
