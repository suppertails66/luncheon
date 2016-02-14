#include "sound/SimpleSoundMixer.h"

namespace Luncheon {


SimpleSoundMixer::~SimpleSoundMixer() { };

SimpleSoundMixer::SimpleSoundMixer()
  : SoundMixer() { };
  
void SimpleSoundMixer::initialize(SampleFrameUnit numSampleFrames__,
                                  int bufferChannels__,
                                  SignednessTypes::SignednessType bufferSignedness__,
                                  EndiannessTypes::EndiannessType bufferEndianness__,
                                  int bufferBytesPerSample__,
                                  int bufferFrequency__) {
  // destroy the buffers if they already exist
  delete mixBuffer_;
  delete tempBuffer_;
  delete combineBuffer_;
  
  numSampleFrames_ = numSampleFrames__;
  
  mixBufferSize_ = numSampleFrames__ 
                    * bufferChannels__
                    * bufferBytesPerSample__;
  mixBuffer_ = new char[mixBufferSize_];
  
  tempBufferSize_ = numSampleFrames__ * bufferChannels__;
  tempBuffer_ = new int[tempBufferSize_];
  
  combineBufferSize_ = tempBufferSize_;
  combineBuffer_ = new int[combineBufferSize_];
  
  bufferChannels_ = bufferChannels__;
  bufferSignedness_ = bufferSignedness__;
  bufferEndianness_ = bufferEndianness__;
  bufferBytesPerSample_ = bufferBytesPerSample__;
  bufferFrequency_ = bufferFrequency__;
}


}; 
