#ifndef RAWSOUNDFILE_H
#define RAWSOUNDFILE_H


#include "sound/SoundFile.h"
#include "util/EndiannessType.h"
#include "util/SignednessType.h"
#include "sound/SoundPlayer.h"
#include "sound/SampleUnit.h"

namespace Luncheon {


class RawSoundFile : public SoundFile {
public:
  virtual ~RawSoundFile();
  
  RawSoundFile(char* sampleBuffer__,
               int sampleBufferLen__,
               int bytesPerSample__,
               int channels__,
               EndiannessTypes::EndiannessType endiannessType__,
               SignednessTypes::SignednessType signednessType__,
               int frequency__,
               bool looping__ = false,
               SampleFrameUnit loopStart__ = 0,
               SampleFrameUnit loopEnd__ = 0);
               
  virtual int sampleBufferLen();
               
  virtual int bytesPerSample();
               
  virtual int channels();
               
  virtual EndiannessTypes::EndiannessType endiannessType();
               
  virtual SignednessTypes::SignednessType signednessType();
               
  virtual int frequency();

  virtual SampleFrameUnit numSampleFrames();
  
  virtual int copySamples(char* target,
                           int bufferSize,
                           SampleFrameUnit offset,
                           SampleFrameUnit numSamples);
  
  virtual SoundPlayer* createSoundPlayer();
protected:

  virtual int sampleFrameToByte(SampleFrameUnit sample);

  virtual SampleUnit sampleFrameToSample(SampleFrameUnit sample);

  char* sampleBuffer_;
  
  int sampleBufferLen_;
  
  int bytesPerSample_;
  
  int channels_;
  
  EndiannessTypes::EndiannessType endiannessType_;
  
  SignednessTypes::SignednessType signednessType_;
  
  int frequency_;
};


};


#endif 
