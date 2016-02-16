#include "sound/RawSoundPlayer.h"
#include <iostream>

namespace Luncheon {


RawSoundPlayer::~RawSoundPlayer() { };

RawSoundPlayer::RawSoundPlayer(RawSoundFile& soundFile__)
  : SoundPlayer(),
    soundFile_(soundFile__),
    done_(false),
    sampleFramePos_(0) { };
  
bool RawSoundPlayer::done() {
  return done_;
}
  
SampleFrameUnit RawSoundPlayer::sampleFramePos() {
  return sampleFramePos_;
}
  
void RawSoundPlayer::playSamples(char* buffer,
                                 int bufferSize,
                                 SampleFrameUnit numSampleFrames) {
  sampleFramePos_ = soundFile_.copySamples(buffer,
                                      bufferSize,
                                      sampleFramePos_,
                                      numSampleFrames);
                           
  // Sound is finished
  if (!soundFile_.looping() && sampleFramePos_ >= soundFile_.numSampleFrames()) {
    done_ = true;
  }
  
  if (soundFile_.looping() && sampleFramePos_ >= soundFile_.loopEnd()) {
    sampleFramePos_ = soundFile_.loopStart();
  }
}


}; 
