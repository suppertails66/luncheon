#ifndef SOUNDLOADER_H
#define SOUNDLOADER_H


#include "sound/SoundFile.h"
#include "sound/RawSoundFile.h"
#include <string>
#include "sound/vorbisfileVorbisSoundOpener.h"
#include "resource/ResourceFileHandle.h"
#include "resource/IndexResourceChunkEntry.h"

namespace Luncheon {


class SoundLoader {
public:
  virtual ~SoundLoader();
  
  SoundLoader();
  
  SoundFile* loadVorbis(const std::string& filename);
  
  SoundFile* loadSound(IndexResourceChunkEntry indexEntry,
                       ResourceFileHandle& fileHandle);
  
protected:

  vorbisfileVorbisSoundOpener vorbisSoundOpener_;

};

  
};


#endif 
