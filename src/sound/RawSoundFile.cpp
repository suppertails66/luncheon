#include "sound/RawSoundFile.h"
#include "sound/RawSoundPlayer.h"
#include <cstring>
#include <iostream>

namespace Luncheon {


RawSoundFile::~RawSoundFile() {
  delete sampleBuffer_;
}

RawSoundFile::RawSoundFile(char* sampleBuffer__,
                           int sampleBufferLen__,
                           int bytesPerSample__,
                           int channels__,
                           EndiannessTypes::EndiannessType endiannessType__,
                           SignednessTypes::SignednessType signednessType__,
                           int frequency__,
                           bool looping__,
                           SampleFrameUnit loopStart__,
                           SampleFrameUnit loopEnd__)
  : SoundFile(looping__,
              loopStart__,
              loopEnd__),
    sampleBuffer_(sampleBuffer__),
    sampleBufferLen_(sampleBufferLen__),
    bytesPerSample_(bytesPerSample__),
    channels_(channels__),
    endiannessType_(endiannessType__),
    signednessType_(signednessType__),
    frequency_(frequency__) { };
               
int RawSoundFile::sampleBufferLen() {
  return sampleBufferLen_;
}
             
int RawSoundFile::bytesPerSample() {
  return bytesPerSample_;
}
               
int RawSoundFile::channels() {
  return channels_;
}
               
SignednessTypes::SignednessType RawSoundFile::signednessType() {
  return signednessType_;
}
               
EndiannessTypes::EndiannessType RawSoundFile::endiannessType() {
  return endiannessType_;
}
             
int RawSoundFile::frequency() {
  return frequency_;
}
  
int RawSoundFile::copySamples(char* target,
                               int bufferSize,
                               SampleFrameUnit offset,
                               SampleFrameUnit numFramesToCopy) {
  // zero buffer
  std::memset(target, 0, bufferSize);
  
  SampleFrameUnit endPoint = (looping_ ? loopEnd_ : numSampleFrames());
  
  // we can stop here if not looping and endPoint == offset
  // ...
  
  SampleFrameUnit leftover = offset + numFramesToCopy - endPoint;
  
  // If leftover is positive, we've reached the end
  // of the buffer and may need to loop (if enabled)
  SampleFrameUnit toCopy 
    = (leftover > 0 ? numFramesToCopy - leftover : numFramesToCopy);
  std::memcpy(target,
              sampleBuffer_ + sampleFrameToByte(offset),
              sampleFrameToByte(toCopy));
              
//  std::cout << leftover << std::endl;
              
//  std::cout << offset + toCopy << std::endl;
  
  // If we have samples to spare, we're done
  if (leftover < 0) {
    return offset + numFramesToCopy;
  }
  
  // If we're out of samples but aren't looping,
  // remain at the end of the sample data and don't
  // play any more
  if (!looping_) {
    return endPoint;
  }
  
  // If we're looping and happened to copy to exactly
  // the end of the data, return to the starting position
  if (leftover == 0) {
    return loopStart_;
  }
  
  // If loop size is 0 or less (which should never happen),
  // stop here to avoid endlessly copying nothing
  if (endPoint <= loopStart_) {
    return endPoint;
  }
  
  // Loop over sample buffer starting from beginning
  // until target is filled
  
  SampleFrameUnit putOffset = numFramesToCopy - leftover;
  SampleFrameUnit remaining = leftover;
  
  while (remaining > 0) {
    offset = loopStart_;
    leftover = offset + remaining - endPoint;
    toCopy = (leftover > 0 ? remaining - leftover : remaining);
    std::memcpy(target + sampleFrameToByte(putOffset),
                sampleBuffer_ + sampleFrameToByte(offset),
                sampleFrameToByte(toCopy));
    remaining -= toCopy;
    putOffset += toCopy;
  }
  
  return offset + toCopy;
}
  
SoundPlayer* RawSoundFile::createSoundPlayer() {
  return new RawSoundPlayer(*this);
}

int RawSoundFile::sampleFrameToByte(SampleFrameUnit sample) {
  return sampleFrameToSample(sample) * bytesPerSample_;
}

SampleUnit RawSoundFile::sampleFrameToSample(SampleFrameUnit sample) {
  return sample * channels_;
}

SampleFrameUnit RawSoundFile::numSampleFrames() {
  return sampleBufferLen_ / bytesPerSample_ / channels_;
}


}; 
