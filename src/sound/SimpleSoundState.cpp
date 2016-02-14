#include "sound/SimpleSoundState.h"

namespace Luncheon {


SimpleSoundState::~SimpleSoundState() { };
  
SimpleSoundState::SimpleSoundState(SoundMixerTypes::SoundMixerType mixerType__)
  : SoundState(mixerType__) { };


}; 
