#include "sound/SoundLoader.h"
#include "resource/SoundTypeID.h"
#include <iostream>

namespace Luncheon {


SoundLoader::~SoundLoader() { };

SoundLoader::SoundLoader() { };
  
SoundFile* SoundLoader::loadVorbis(const std::string& filename) {
  return vorbisSoundOpener_.loadVorbis(filename);
}
  
SoundFile* SoundLoader::loadSound(IndexResourceChunkEntry indexEntry,
                                  ResourceFileHandle& fileHandle) {
  switch (static_cast<SoundTypeIDs::SoundTypeID>(indexEntry.typeID())) {
  case SoundTypeIDs::OggVorbis:
    fileHandle.seek(indexEntry.address());
    return vorbisSoundOpener_.loadVorbis(fileHandle);
    break;
  default:
    return 0;
    break;
  }
}


}; 
