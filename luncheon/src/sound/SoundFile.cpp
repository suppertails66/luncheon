#include "sound/SoundFile.h"

namespace Luncheon {


SoundFile::~SoundFile() { };

SoundFile::SoundFile()
  : looping_(false),
    loopStart_(0),
    loopEnd_(0) { };
  
SoundFile::SoundFile(bool looping__,
                     int loopStart__,
                     int loopEnd__)
  : looping_(looping__),
    loopStart_(loopStart__),
    loopEnd_(loopEnd__) { };
  
bool SoundFile::looping() {
  return looping_;
}

SampleFrameUnit SoundFile::loopStart() {
  return loopStart_;
}

SampleFrameUnit SoundFile::loopEnd() {
  return loopEnd_;
}


}; 
