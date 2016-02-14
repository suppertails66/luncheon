#include "logic/CoreManager.h"
#include "graphics/GraphicsCoreType.h"
#include "SDL.h"
#include "graphics/SDL2GraphicsCore.h"
#include "font/FreeTypeFontCore.h"
#include "sound/SDL2SoundCore.h"
#include "sound/SoundMixerType.h"
#include "sound/SoundStateType.h"
#include "input/SDL2InputCore.h"
#include "timing/SDL2TimingCore.h"
#include <iostream>

namespace Luncheon {


CoreManager::~CoreManager() {
  // Destroy in reverse order of initialization
  delete timingCore_;
  delete inputCore_;
  delete soundCore_;
  delete fontCore_;
  delete graphicsCore_;
  
  shutDownCorePrerequisites();
}

CoreManager::CoreManager()
  : graphicsCoreType_(GraphicsCoreTypes::dummy),
    fontCoreType_(FontCoreTypes::dummy),
    soundCoreType_(SoundCoreTypes::dummy),
    inputCoreType_(InputCoreTypes::dummy),
    timingCoreType_(TimingCoreTypes::dummy),
    
    graphicsCore_(0),
    fontCore_(0),
    soundCore_(0),
    inputCore_(0),
    timingCore_(0) { };

void CoreManager::initializeCores() {
  initializeCorePrerequisites();

  // Instantiate graphics core
  switch (graphicsCoreType_) {
  case GraphicsCoreTypes::dummy:
    // Instantiate dummy core
    // ...
    break;
  case GraphicsCoreTypes::SDL2:
    graphicsCore_ = new SDL2GraphicsCore();
    break;
  default:
    graphicsCore_ = 0;
    break;
  }
  
  // Instantiate font core
  switch (fontCoreType_) {
  case FontCoreTypes::dummy:
    // Instantiate dummy core
    // ...
    break;
  case FontCoreTypes::FreeType:
    fontCore_ = new FreeTypeFontCore(*graphicsCore_);
    break;
  default:
    fontCore_ = 0;
    break;
  }
  
  // Instantiate sound core
  switch (soundCoreType_) {
  case SoundCoreTypes::dummy:
    // Instantiate dummy core
    // ...
    break;
  case SoundCoreTypes::SDL2:
    soundCore_ = new SDL2SoundCore(SoundMixerTypes::Simple,
                                   SoundStateTypes::Simple);
    break;
  default:
    soundCore_ = 0;
    break;
  }
  
  // Instantiate input core
  switch (inputCoreType_) {
  case InputCoreTypes::dummy:
    // Instantiate dummy core
    // ...
    break;
  case InputCoreTypes::SDL2:
    inputCore_ = new SDL2InputCore();
    break;
  default:
    inputCore_ = 0;
    break;
  }
  
  // Instantiate timing core
  switch (timingCoreType_) {
  case TimingCoreTypes::dummy:
    // Instantiate dummy core
    // ...
    break;
  case TimingCoreTypes::SDL2:
    timingCore_ = new SDL2TimingCore();
    break;
  default:
    timingCore_ = 0;
    break;
  }
}

GraphicsCoreTypes::GraphicsCoreType CoreManager::graphicsCoreType() {
  return graphicsCoreType_;
}

void CoreManager::setGraphicsCoreType(GraphicsCoreTypes::GraphicsCoreType
  graphicsCoreType__) {
  graphicsCoreType_ = graphicsCoreType__;  
}
  
FontCoreTypes::FontCoreType CoreManager::fontCoreType() {
  return fontCoreType_;
}

void CoreManager::setFontCoreType(FontCoreTypes::FontCoreType
  fontCoreType__) {
  fontCoreType_ = fontCoreType__;
}
  
SoundCoreTypes::SoundCoreType CoreManager::soundCoreType() {
  return soundCoreType_;
}

void CoreManager::setSoundCoreType(SoundCoreTypes::SoundCoreType
  soundCoreType__) {
  soundCoreType_ = soundCoreType__;
}
  
InputCoreTypes::InputCoreType CoreManager::inputCoreType() {
  return inputCoreType_;
}

void CoreManager::setInputCoreType(InputCoreTypes::InputCoreType
  inputCoreType__) {
  inputCoreType_ = inputCoreType__;
}
  
TimingCoreTypes::TimingCoreType CoreManager::timingCoreType() {
  return timingCoreType_;
}

void CoreManager::setTimingCoreType(TimingCoreTypes::TimingCoreType
  timingCoreType__) {
  timingCoreType_ = timingCoreType__;
}

GraphicsCore& CoreManager::graphicsCore() {
  return *graphicsCore_;
}

FontCore& CoreManager::fontCore() {
  return *fontCore_;
}

SoundCore& CoreManager::soundCore() {
  return *soundCore_;
}

InputCore& CoreManager::inputCore() {
  return *inputCore_;
}
  
TimingCore& CoreManager::timingCore() {
  return *timingCore_;
}


void CoreManager::initializeCorePrerequisites() {
  // Check which libraries we need and what parts to
  // initialize
  
  // Bitfield of SDL2 subsystems to initialize
  int SDL2SystemsToInitialize = 0;
  
  
  
  // Check graphics core
  switch (graphicsCoreType_) {
  case GraphicsCoreTypes::dummy:
    break;
  case GraphicsCoreTypes::SDL2:
    SDL2SystemsToInitialize |= SDL_INIT_VIDEO;
    break;
  }
  
  // Check font core
  switch (fontCoreType_) {
  case FontCoreTypes::dummy:
    break;
  case FontCoreTypes::FreeType:
    // no action needed (initialized and shut down in core)
    break;
  }
  
  // Check sound core
  switch (soundCoreType_) {
  case SoundCoreTypes::dummy:
    break;
  case SoundCoreTypes::SDL2:
    SDL2SystemsToInitialize |= SDL_INIT_AUDIO;
    break;
  }
  
  // Check input core
  switch (inputCoreType_) {
  case InputCoreTypes::dummy:
    break;
  case InputCoreTypes::SDL2:
    SDL2SystemsToInitialize |= SDL_INIT_EVENTS;
    break;
  }
  
  // Check input core
  switch (timingCoreType_) {
  case TimingCoreTypes::dummy:
    break;
  case TimingCoreTypes::SDL2:
    SDL2SystemsToInitialize |= SDL_INIT_TIMER;
    break;
  }
  
  
  
  // Start SDL if needed
  if (SDL2SystemsToInitialize != 0) {
    /*int result = */SDL_Init(SDL2SystemsToInitialize);
  }
}

void CoreManager::shutDownCorePrerequisites() {
  // check which systems are running
  // ...
  
  // shut down SDL if running
  if (SDL_WasInit(0)) {
    SDL_Quit();
  }
}


};
