#ifndef SDL2SOUNDCORE_H
#define SDL2SOUNDCORE_H


#ifdef LUNCHEON_ENABLE_SDL2

#include "sound/SoundCore.h"
#include "SDL.h"

namespace Luncheon {


class SDL2SoundCore : public SoundCore {
public:
  virtual ~SDL2SoundCore();
  
  SDL2SoundCore(
              SoundMixerTypes::SoundMixerType soundMixerType__,
              SoundStateTypes::SoundStateType soundStateType__);
  
  /*virtual void loadSound(ResourceID soundID);*/
  
  virtual void lock();
  
  virtual void unlock();
  
  virtual int obtainedFrequency();
  
  virtual int obtainedChannels();
  
  virtual int obtainedSamples();
protected:
  
  // The target audio specs
  const static int desiredFreq = 44100;
  const static SDL_AudioFormat desiredFormat = AUDIO_S16LSB;
  const static int desiredChannels = 2;
  const static int desiredSamples = 4096;
  
  // The audio callback
  static void audioCallback(void* userdata,
                            Uint8* stream,
                            int len);
              
  SDL_AudioDeviceID device;
  SDL_AudioSpec desired;
  SDL_AudioSpec obtained;
};


};

#endif


#endif 
