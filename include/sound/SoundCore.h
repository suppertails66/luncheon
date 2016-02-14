#ifndef SOUNDCORE_H
#define SOUNDCORE_H


#include "sound/SoundMixer.h"
#include "sound/SoundMixerType.h"
#include "sound/SoundState.h"
#include "sound/SoundStateType.h"
#include "sound/SoundLoader.h"
#include "resource/SoundResourceFileLoader.h"
#include "resource/ResourceID.h"
#include "sound/ResourceIDSoundMap.h"
#include "resource/LoadCountMap.h"
#include <vector>

namespace Luncheon {


class SoundCore {
public:
  virtual ~SoundCore();
    
  virtual SoundMixerTypes::SoundMixerType soundMixerType();
    
  virtual SoundStateTypes::SoundStateType soundStateType();
  
  virtual SoundLoader& loader();
  
  virtual SoundState& state();
  
  virtual void loadSound(ResourceID soundID);
  
  virtual void unloadSound(ResourceID soundID);
  
  virtual void unloadAllSounds();
  
  virtual void update();
  
  virtual void lock() =0;
  
  virtual void unlock() =0;
  
  virtual int obtainedFrequency() =0;
  
  virtual int obtainedChannels() =0;
  
  virtual int obtainedSamples() =0;
  
  // Playback functions
  
  virtual void playSoundEffect(ResourceID soundID);
  
  virtual void changeMusic(ResourceID soundID);
  
  virtual void pauseMusic();
  
  virtual void resumeMusic();
  
protected:
  SoundCore(
    SoundMixerTypes::SoundMixerType soundMixerType__,
    SoundStateTypes::SoundStateType soundStateType__);
    
  SoundMixerTypes::SoundMixerType soundMixerType_;
    
  SoundStateTypes::SoundStateType soundStateType_;
  
  SoundLoader loader_;
  
  SoundState* state_;
  
  SoundResourceFileLoader resourceFile_;
  
  ResourceIDSoundMap loadedFiles_;
  
  LoadCountMap loadedSoundCounts_;
};


};


#endif
