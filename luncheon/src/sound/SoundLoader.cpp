#include "sound/SoundLoader.h"
#include "resource/SoundTypeID.h"
#include <cstdlib>
#include <iostream>

namespace Luncheon {


SoundLoader::~SoundLoader() { };

SoundLoader::SoundLoader() { };
  
SoundFile* SoundLoader::loadVorbis(const std::string& filename) {
#ifdef LUNCHEON_ENABLE_VORBISFILE
  return vorbisSoundOpener_.loadVorbis(filename);
#else
  return NULL;
#endif
}
  
SoundFile* SoundLoader::loadSound(IndexResourceChunkEntry indexEntry,
                                  ResourceFileHandle& fileHandle) {
  switch (static_cast<SoundTypeIDs::SoundTypeID>(indexEntry.typeID())) {
  case SoundTypeIDs::OggVorbis:
    #ifdef LUNCHEON_ENABLE_VORBISFILE
	  fileHandle.seek(indexEntry.address());
      return vorbisSoundOpener_.loadVorbis(fileHandle);
    #else
      return NULL;
    #endif
    break;
  default:
    return 0;
    break;
  }
}


}; 
