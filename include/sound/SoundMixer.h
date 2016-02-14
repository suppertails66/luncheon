#ifndef SOUNDMIXER_H
#define SOUNDMIXER_H


#include "sound/SampleFrameUnit.h"
#include "util/EndiannessType.h"
#include "util/SignednessType.h"

namespace Luncheon {


class SoundMixer {
public:
  virtual ~SoundMixer();
  
  virtual char* mixBuffer();
  
  virtual int mixBufferSize();
  
  virtual int* tempBuffer();
  
  virtual int tempBufferSize();
  
  virtual int* combineBuffer();
  
  virtual int combineBufferSize();
  
  virtual SampleFrameUnit numSampleFrames();
  
  virtual int bufferChannels();
  
  virtual SignednessTypes::SignednessType bufferSignedness();
  
  virtual EndiannessTypes::EndiannessType bufferEndianness();
  
  virtual int bufferBytesPerSample();
  
  virtual int bufferFrequency();
  
  virtual void initialize(SampleFrameUnit numSampleFrames__,
                          int bufferChannels__,
                          SignednessTypes::SignednessType bufferSignedness__,
                          EndiannessTypes::EndiannessType bufferEndianness__,
                          int bufferBytesPerSample__,
                          int bufferFrequency__) =0;
protected:
  SoundMixer();

  char* mixBuffer_;
  
  int mixBufferSize_;
  
  int* tempBuffer_;
  
  int tempBufferSize_;
  
  int* combineBuffer_;
  
  int combineBufferSize_;
  
  SampleFrameUnit numSampleFrames_;
  
  int bufferChannels_;
  
  SignednessTypes::SignednessType bufferSignedness_;
  
  EndiannessTypes::EndiannessType bufferEndianness_;
  
  int bufferBytesPerSample_;
  
  int bufferFrequency_;
};


};


#endif 
