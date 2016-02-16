#ifndef SOUNDSTATE_H
#define SOUNDSTATE_H


#include "sound/SoundMixer.h"
#include "sound/SoundPlayer.h"
#include "sound/SoundMixerType.h"
#include "sound/SampleFrameUnit.h"
#include "sound/SoundPlayerCollection.h"
#include "util/DumbPointer.h"
#include <vector>

namespace Luncheon {


class SoundState {
public:
  virtual ~SoundState();
  
  virtual SoundMixer& mixer();
  
//  virtual void addSoundEffect();
  
  virtual void mixSound(char* putbuf,
                        int putbufLen);
  
  virtual void queueSoundEffect(SoundPlayer* sound);
  
  virtual void queueMusic(SoundPlayer* music);
                        
  virtual void updateQueues();
  
//  std::vector<SoundPlayer*> debugSoundPlayers;
protected:
  // Every sample played is multiplied by this amount,
  // regardless of other volume settings
  const static double masterVolumeScale;
  
  SoundState(SoundMixerTypes::SoundMixerType mixerType__);
  
  SoundMixer* mixer_;
  
  SoundPlayerCollection queuedSoundEffectPlayers_;
  
  SoundPlayerCollection soundEffectPlayers_;
  
  SoundPlayer* queuedMusicPlayer_;
  
  SoundPlayer* musicPlayer_;
  
  virtual void mixToCombineBuffer(SoundPlayer& player,
                                  int upperSampleLimit,
                                  int lowerSampleLimit,
                                  SoundMixer& mixer_);
};


};


#endif 
