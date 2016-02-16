#ifndef RESOURCEIDSOUNDMAP_H
#define RESOURCEIDSOUNDMAP_H


#include "resource/ResourceID.h"
#include "sound/SoundFile.h"
#include <unordered_map>

namespace Luncheon {


typedef std::unordered_map<ResourceID, SoundFile*> ResourceIDSoundMap;
typedef std::pair<ResourceID, SoundFile*> ResourceIDSoundMapPair;


};


#endif 
