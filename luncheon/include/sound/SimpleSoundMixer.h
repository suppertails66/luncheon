#ifndef SIMPLESOUNDMIXER_H
#define SIMPLESOUNDMIXER_H


#include "sound/SoundMixer.h"

namespace Luncheon {


class SimpleSoundMixer : public SoundMixer {
public:
  virtual ~SimpleSoundMixer();
  
  SimpleSoundMixer();
  
  virtual void initialize(SampleFrameUnit numSampleFrames__,
                          int bufferChannels__,
                          SignednessTypes::SignednessType bufferSignedness__,
                          EndiannessTypes::EndiannessType bufferEndianness__,
                          int bufferBytesPerSample__,
                          int bufferFrequency__);
protected:

};


};


#endif 
