#ifndef SIMPLESOUNDSTATE_H
#define SIMPLESOUNDSTATE_H


#include "sound/SoundState.h"
#include "sound/SoundMixer.h"
#include "sound/SoundMixerType.h"

namespace Luncheon {


class SimpleSoundState : public SoundState {
public:
  virtual ~SimpleSoundState();
  
  SimpleSoundState(SoundMixerTypes::SoundMixerType mixerType__);
protected:
};


};


#endif 
