#include "sound/SDL2SoundCore.h"
#include <cstring>
#include <iostream>
#include "util/SignednessType.h"
#include "util/EndiannessType.h"
#include "util/ByteConversion.h"

namespace Luncheon {


SDL2SoundCore::~SDL2SoundCore() {
  // Pause and close the audio device (allowing
  // loaded sounds to be freed)
  if (device != 0) {
    SDL_PauseAudioDevice(device, 1);
    SDL_CloseAudioDevice(device);
  }
}

SDL2SoundCore::SDL2SoundCore(
              SoundMixerTypes::SoundMixerType soundMixerType__,
              SoundStateTypes::SoundStateType soundStateType__)
  : SoundCore(soundMixerType__,
              soundStateType__),
    device(0) {

  // Initialize the audio device
  desired.freq = desiredFreq;
  desired.format = desiredFormat;
  desired.channels = desiredChannels;
  desired.samples = desiredSamples;
  desired.callback = audioCallback;
  desired.userdata = state_;
  
/*  std::cout << "desired" << std::endl;
  std::cout << "freq: " << desired.freq << std::endl;
  std::cout << "format: " << desired.format << std::endl;
  std::cout << "channels: " << desired.channels << std::endl;
  std::cout << "samples: " << desired.samples << std::endl; */
  
  device = SDL_OpenAudioDevice(NULL,
                               0,
                               &desired,
                               &obtained,
                               SDL_AUDIO_ALLOW_ANY_CHANGE);
                               
/*  if (device == 0) {
    std::cerr << "error" << std::endl;
  }
  else {
    std::cout << "obtained" << std::endl;
    std::cout << "freq: " << obtained.freq << std::endl;
    std::cout << "format: " << obtained.format << std::endl;
    std::cout << "channels: " << obtained.channels << std::endl;
    std::cout << "samples: " << obtained.samples << std::endl;
  } */
  
  // Translate format settings
  
  SignednessTypes::SignednessType dataSignedness = SignednessTypes::nosign;
  if ( SDL_AUDIO_ISSIGNED( desired.format ) ) {
    dataSignedness = SignednessTypes::sign;
  }
  
  EndiannessTypes::EndiannessType dataEndianness = EndiannessTypes::little;
  if ( SDL_AUDIO_ISBIGENDIAN( desired.format ) ) {
    dataEndianness = EndiannessTypes::big;
  }
  
  // Initialize the mixer
  state_->mixer().initialize(obtained.samples,
                            desiredChannels,  // channels
                                // (SDL doesn't seem to record this correctly?)
                            dataSignedness,  // signedness
                            dataEndianness,  // endianness
                            (desired.format 
                              & SDL_AUDIO_MASK_BITSIZE) / 8,  // bytes per sample
                            desired.freq); // frequency
                            
  
  SDL_PauseAudioDevice(device, 0);
}
  
/*void SDL2SoundCore::loadSound(ResourceID soundID) {
  SoundFile* sound = resourceFile_.loadSoundFile(soundID,
                                                 loader_);
                                                 
//  SDL_LockAudioDevice(device);
//  state_->debugSoundPlayers.push_back(sound->createSoundPlayer());
//  SDL_UnlockAudioDevice(device);
}*/
  
void SDL2SoundCore::lock() {
  SDL_LockAudioDevice(device);
}
  
void SDL2SoundCore::unlock() {
  SDL_UnlockAudioDevice(device);
}

int SDL2SoundCore::obtainedFrequency() {
  return obtained.freq;
}

int SDL2SoundCore::obtainedChannels() {
  return obtained.channels;
}

int SDL2SoundCore::obtainedSamples() {
  return obtained.samples;
}
  
void SDL2SoundCore::audioCallback(void* userdata,
                                  Uint8* stream,
                                  int len) {
  SoundState& soundState = *((SoundState*)userdata);
                          
  std::memset(stream, 0, len);
    
  soundState.mixSound((char*)stream,
                      len);
    
//    std::memcpy((void*)stream, soundMixer.mixBuffer(), soundMixer.mixBufferSize());
  
/*  // cshhhhhhh
  for (int i = 1; i < len; i += 2) {
    stream[i - 1] = 0;
    stream[i] = rand() % (2 << 16);
  } */
}


}; 
