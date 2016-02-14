#include "sound/SoundMixer.h"

namespace Luncheon {


SoundMixer::~SoundMixer() {
  delete mixBuffer_;
  delete tempBuffer_;
  delete combineBuffer_;
}

SoundMixer::SoundMixer()
  : mixBuffer_(0),
    tempBuffer_(0),
    combineBuffer_(0) { };
  
char* SoundMixer::mixBuffer() {
  return mixBuffer_;
}

int SoundMixer::mixBufferSize() {
  return mixBufferSize_;
}
  
int* SoundMixer::tempBuffer() {
  return tempBuffer_;
}

int SoundMixer::tempBufferSize() {
  return tempBufferSize_;
}
  
int* SoundMixer::combineBuffer() {
  return combineBuffer_;
}

int SoundMixer::combineBufferSize() {
  return combineBufferSize_;
}

SampleFrameUnit SoundMixer::numSampleFrames() {
  return numSampleFrames_;
}

int SoundMixer::bufferChannels() {
  return bufferChannels_;
}
  
SignednessTypes::SignednessType SoundMixer::bufferSignedness() {
  return bufferSignedness_;
}
  
EndiannessTypes::EndiannessType SoundMixer::bufferEndianness() {
  return bufferEndianness_;
}

int SoundMixer::bufferBytesPerSample() {
  return bufferBytesPerSample_;
}

int SoundMixer::bufferFrequency() {
  return bufferFrequency_;
}


}; 
