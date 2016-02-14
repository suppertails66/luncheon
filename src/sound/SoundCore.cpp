#include "sound/SoundCore.h"
#include "sound/SimpleSoundMixer.h"
#include "sound/SimpleSoundState.h"
#include <iostream>
#include "sound/SoundFile.h"

namespace Luncheon {


SoundCore::~SoundCore() {
  delete state_;
  
  // Destroy all loaded sounds
  for (ResourceIDSoundMap::iterator it = loadedFiles_.begin();
       it != loadedFiles_.end();
       it++) {
    delete it->second;
  }
}

SoundCore::SoundCore(
                  SoundMixerTypes::SoundMixerType soundMixerType__,
                  SoundStateTypes::SoundStateType soundStateType__)
  : soundMixerType_(soundMixerType__),
    soundStateType_(soundStateType__),
    state_(0),
    resourceFile_("res/sound.res") {
  
  // Instantiate state
  switch (soundStateType_) {
  case SoundStateTypes::dummy:
  
    break;
  case SoundStateTypes::Simple:
    state_ = new SimpleSoundState(soundMixerType__);
    break;
  default:
    break;
  }
  
  
}
    
SoundMixerTypes::SoundMixerType SoundCore::soundMixerType() {
  return soundMixerType_;
}
    
SoundStateTypes::SoundStateType SoundCore::soundStateType() {
  return soundStateType_;
}

SoundLoader& SoundCore::loader() {
  return loader_;
}
  
SoundState& SoundCore::state() {
  return *state_;
}
  
void SoundCore::loadSound(ResourceID soundID) {
  ResourceIDSoundMap::iterator targetSound
    = loadedFiles_.find(soundID);
    
  // No double loading
  if (targetSound != loadedFiles_.end()) {
    ++(loadedSoundCounts_.find(soundID)->second);
    return;
  }
  
  SoundFile* sound = resourceFile_.loadSoundFile(soundID,
                                                 loader_);
                                                 
//  debugLoadedFiles.push_back(sound);
  
  loadedFiles_.insert(ResourceIDSoundMapPair(soundID, sound));
  loadedSoundCounts_.insert(LoadCountMapPair(soundID, 1));
  
//  state_->debugSoundPlayers.push_back(sound->createSoundPlayer());
}
  
void SoundCore::unloadSound(ResourceID soundID) {
  ResourceIDSoundMap::iterator targetSound
    = loadedFiles_.find(soundID);
    
  if (targetSound == loadedFiles_.end()) {
    return;
  }
  
  LoadCountMap::iterator targetCount = loadedSoundCounts_.find(soundID);
  
  if (targetCount->second == 1) {
    delete targetSound->second;
    loadedFiles_.erase(targetSound);
    loadedSoundCounts_.erase(targetCount);
  }
  else {
    --(targetCount->second);
  }
}
  
void SoundCore::unloadAllSounds() {
  while (loadedFiles_.size()) {
    delete (loadedFiles_.begin()->second);
    loadedFiles_.erase(loadedFiles_.begin());
  }
  loadedSoundCounts_.clear();
}
  
void SoundCore::update() {
  lock();
  
  state_->updateQueues();
  
  unlock();
}
  
void SoundCore::playSoundEffect(ResourceID soundID) {
  ResourceIDSoundMap::iterator targetSound
    = loadedFiles_.find(soundID);
  
  state_->queueSoundEffect(targetSound->second->createSoundPlayer());
}

void SoundCore::changeMusic(ResourceID soundID) {
  ResourceIDSoundMap::iterator targetSound
    = loadedFiles_.find(soundID);
  
  state_->queueMusic(targetSound->second->createSoundPlayer());
}

void SoundCore::pauseMusic() {

}

void SoundCore::resumeMusic() {

}


}; 
