#ifndef SOUNDPLAYER_H
#define SOUNDPLAYER_H


#include "sound/SampleFrameUnit.h"

namespace Luncheon {


class SoundPlayer {
public:
  virtual ~SoundPlayer();
  
  virtual bool done() =0;
  
  virtual SampleFrameUnit sampleFramePos() =0;
  
  virtual void playSamples(char* buffer,
                            int bufferSize,
                            SampleFrameUnit numSamples) =0;
protected:
  SoundPlayer();
};


};


#endif 
