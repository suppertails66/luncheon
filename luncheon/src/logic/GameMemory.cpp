#include "logic/GameMemory.h"

namespace Luncheon {


GameMemory::~GameMemory() { };

GameMemory::GameMemory(GraphicsCore& graphicsCore__,
                       FontCore& fontCore__,
                       SoundCore& soundCore__,
                       InputCore& inputCore__,
                       TimingCore& timingCore__)
  : graphicsCore_(graphicsCore__),
    fontCore_(fontCore__),
    soundCore_(soundCore__),
    inputCore_(inputCore__),
    timingCore_(timingCore__),
    framesPerSecond_(0),
    currentScene_(0),
    needsSceneChange_(false) { };

GraphicsCore& GameMemory::graphicsCore() {
  return graphicsCore_;
}

FontCore& GameMemory::fontCore() {
  return fontCore_;
}

SoundCore& GameMemory::soundCore() {
  return soundCore_;
}

InputCore& GameMemory::inputCore() {
  return inputCore_;
}

TimingCore& GameMemory::timingCore() {
  return timingCore_;
}
  
int GameMemory::framesPerSecond() {
  return framesPerSecond_;
}

void GameMemory::setFramesPerSecond(int framesPerSecond__) {
  framesPerSecond_ = framesPerSecond__;
}

int GameMemory::currentScene() {
  return currentScene_;
}

void GameMemory::setCurrentScene(int currentScene__) {
  currentScene_ = currentScene__;
}

void GameMemory::changeCurrentScene(int currentScene__) {
  currentScene_ = currentScene__;
  needsSceneChange_ = true;
}

bool GameMemory::needsSceneChange() {
  return needsSceneChange_;
}

void GameMemory::setNeedsSceneChange(bool needsSceneChange__) {
  needsSceneChange_ = needsSceneChange__;
}


}; 
