#include "sound/SoundState.h"
#include "sound/SimpleSoundMixer.h"
#include "util/ByteConversion.h"
#include <iostream>
#include <cstring>
#include "util/MiscMath.h"

namespace Luncheon {


const double SoundState::masterVolumeScale = 0.25;

SoundState::~SoundState() {
  // Delete all queued or playing sound players
  while (queuedSoundEffectPlayers_.size()) {
    delete (queuedSoundEffectPlayers_.front());
    queuedSoundEffectPlayers_.erase(queuedSoundEffectPlayers_.begin());
  }
  
  while (soundEffectPlayers_.size()) {
    delete (soundEffectPlayers_.front());
    soundEffectPlayers_.erase(soundEffectPlayers_.begin());
  }
  
  delete queuedMusicPlayer_;
  delete musicPlayer_;
  
  delete mixer_;
}

SoundState::SoundState(SoundMixerTypes::SoundMixerType mixerType__)
  : mixer_(0),
    queuedMusicPlayer_(0),
    musicPlayer_(0) {
  
  switch (mixerType__) {
  case SoundMixerTypes::dummy:
    break;
  case SoundMixerTypes::Simple:
    mixer_ = new SimpleSoundMixer();
    break;
  default:
    break;
  }
  
}
  
SoundMixer& SoundState::mixer() {
  return *mixer_;
}
  
void SoundState::mixSound(char* putbuf,
                          int putbufLen) {
                          
  // Zero the combine buffer
  std::memset(mixer_->combineBuffer(),
              0,
              mixer_->combineBufferSize() * sizeof(int));
              
  // Set clamping limits
  int upperSampleLimit;
  int lowerSampleLimit;
  if (mixer_->bufferSignedness() == SignednessTypes::sign) {
    upperSampleLimit = ((1 << ((mixer_->bufferBytesPerSample() * 8)))/2) - 1;
    lowerSampleLimit = -upperSampleLimit - 1;
  }
  else {
    upperSampleLimit = (1 << (mixer_->bufferBytesPerSample() * 8)) - 1;
    lowerSampleLimit = 0;
  }
  
  // Combine all sound effects
  for (SoundPlayerCollection::iterator it = soundEffectPlayers_.begin();
       it != soundEffectPlayers_.end();
       it++) {
  
    mixToCombineBuffer(*(*it),
                       upperSampleLimit,
                       lowerSampleLimit,
                       *mixer_);
  }
  
  // Combine music
  if (musicPlayer_ != 0) {
    mixToCombineBuffer(*musicPlayer_,
                       upperSampleLimit,
                       lowerSampleLimit,
                       *mixer_);
  }
  
  // Convert combine buffer to native format and place in stream
  for (int i = 0; i < mixer_->combineBufferSize(); i++) {
    ByteConversion::toBytes(mixer_->combineBuffer()[i],
                            putbuf + (i * mixer_->bufferBytesPerSample()),
                            mixer_->bufferBytesPerSample(),
                            mixer_->bufferEndianness(),
                            mixer_->bufferSignedness());
  }
  
}

void SoundState::queueSoundEffect(SoundPlayer* sound) {
  queuedSoundEffectPlayers_.push_back(sound);
}

void SoundState::queueMusic(SoundPlayer* music) {
  // Delete any existing queued music player (in case multiple
  // music players are queued sequentially)
  delete queuedMusicPlayer_;
  queuedMusicPlayer_ = music;
}
                        
void SoundState::updateQueues() {
  // Remove any sounds that have finished playing from the
  // playing collection
  SoundPlayerCollection::iterator doneIterator
    = soundEffectPlayers_.begin();
  while (doneIterator != soundEffectPlayers_.end()) {
    if ((*doneIterator)->done()) {
      SoundPlayerCollection::iterator temp
        = doneIterator;
      ++doneIterator;
      
      delete (*temp);
      soundEffectPlayers_.erase(temp);
    }
    else {
      ++doneIterator;
    }
  }

  // Transfer all queued sounds to playing collection
  while (queuedSoundEffectPlayers_.size()) {
    soundEffectPlayers_.push_back(queuedSoundEffectPlayers_.front());
    queuedSoundEffectPlayers_.pop_front();
  }
  
  // Switch playing music if needed
  if (queuedMusicPlayer_ != 0) {
    delete musicPlayer_;
    musicPlayer_ = queuedMusicPlayer_;
    // Zero the queue pointer until next music change
    queuedMusicPlayer_ = 0;
  }
}
  
void SoundState::mixToCombineBuffer(SoundPlayer& player,
                                    int upperSampleLimit,
                                    int lowerSampleLimit,
                                    SoundMixer& mixer_) {
  // Put next batch of raw samples in the mix buffer
  player.playSamples(
                 mixer_.mixBuffer(),
                 mixer_.mixBufferSize(),
                 mixer_.numSampleFrames());
  
  // Convert samples to ints for mixing
  for (int i = 0;
           i < mixer_.mixBufferSize();
           i += mixer_.bufferBytesPerSample()) {
           
    // Convert each sample and place in temp buffer
    mixer_.tempBuffer()[i / mixer_.bufferBytesPerSample()]
       = ByteConversion::fromBytes(mixer_.mixBuffer() + i,
                                   mixer_.bufferBytesPerSample(),
                                   mixer_.bufferEndianness(),
                                   mixer_.bufferSignedness())
           * masterVolumeScale;
  }
  
  // Add each sample in temp buffer to combine buffer,
  // clamping values at maximum range
  for (int i = 0; i < mixer_.tempBufferSize(); i++) {
    mixer_.combineBuffer()[i] += mixer_.tempBuffer()[i];
    MiscMath::clamp(mixer_.combineBuffer()[i],
                    lowerSampleLimit,
                    upperSampleLimit);
  }
}


}; 
