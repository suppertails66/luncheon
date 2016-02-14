#ifndef RESOURCEIDINDEXMAP_H
#define RESOURCEIDINDEXMAP_H


#include <unordered_map>
#include "resource/ResourceID.h"
#include "resource/IndexResourceChunkEntry.h"

namespace Luncheon {


typedef std::unordered_map<ResourceID, IndexResourceChunkEntry>
  ResourceIDIndexMap;
typedef std::pair<ResourceID, IndexResourceChunkEntry>
  ResourceIDIndexMapPair;


};


#endif 
