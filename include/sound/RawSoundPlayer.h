#ifndef RAWSOUNDPLAYER_H
#define RAWSOUNDPLAYER_H


#include "sound/SoundPlayer.h"
#include "sound/RawSoundFile.h"
#include "sound/SampleFrameUnit.h"

namespace Luncheon {


class RawSoundPlayer : public SoundPlayer {
public:
  virtual ~RawSoundPlayer();
  
  RawSoundPlayer(RawSoundFile& soundFile__);
  
  virtual bool done();
  
  virtual SampleFrameUnit sampleFramePos();
  
  virtual void playSamples(char* buffer,
                            int bufferSize,
                            SampleFrameUnit numSampleFrames);
protected:

  RawSoundFile& soundFile_;
  
  bool done_;
  
  SampleFrameUnit sampleFramePos_;
  
};


};


#endif
