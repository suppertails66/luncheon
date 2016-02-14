#ifndef SOUNDRESOURCEFILELOADER_H
#define SOUNDRESOURCEFILELOADER_H


#include "resource/ResourceFileLoader.h"
#include <string>
#include "sound/SoundFile.h"
#include "sound/SoundLoader.h"
#include "resource/ResourceID.h"

namespace Luncheon {


class SoundResourceFileLoader : public ResourceFileLoader {
public:
  virtual ~SoundResourceFileLoader();
  
  SoundResourceFileLoader(const std::string& filename);
  
  virtual SoundFile* loadSoundFile(ResourceID id,
                                   SoundLoader& soundLoader);
protected:
};


};


#endif 
