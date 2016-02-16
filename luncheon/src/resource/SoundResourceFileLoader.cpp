#include "resource/SoundResourceFileLoader.h"
#include <iostream>

namespace Luncheon {


SoundResourceFileLoader::~SoundResourceFileLoader() { };
  
SoundResourceFileLoader::SoundResourceFileLoader(
                            const std::string& filename)
  : ResourceFileLoader(filename) { };
  
SoundFile* SoundResourceFileLoader::loadSoundFile(
                                       ResourceID id,
                                       SoundLoader& soundLoader) {
  IndexResourceChunkEntry entry = index_.getIndexEntry(id);
  
  return soundLoader.loadSound(entry,
                               fileHandle_);
}


}; 
