#ifndef SOUNDFILE_H
#define SOUNDFILE_H


#include "sound/SoundPlayer.h"
#include "sound/SampleFrameUnit.h"

namespace Luncheon {


class SoundFile {
public:
  virtual ~SoundFile();
  
  virtual bool looping();
  
  virtual SampleFrameUnit loopStart();
  
  virtual SampleFrameUnit loopEnd();
  
  virtual SampleFrameUnit numSampleFrames() =0;
  
  virtual SoundPlayer* createSoundPlayer() =0;
  
protected:
  SoundFile();
  
  SoundFile(bool looping__,
            SampleFrameUnit loopStart__,
            SampleFrameUnit loopEnd__);
  
  bool looping_;
  
  SampleFrameUnit loopStart_;
  
  SampleFrameUnit loopEnd_;
};


};


#endif 
