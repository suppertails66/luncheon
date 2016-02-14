#ifndef RESOURCEIDANIMATIONMAP_H
#define RESOURCEIDANIMATIONMAP_H


#include "resource/ResourceID.h"
#include "animation/Animation.h"
#include <unordered_map>

namespace Luncheon {


typedef std::unordered_map<ResourceID, Animation*> ResourceIDAnimationMap;
typedef std::pair<ResourceID, Animation*> ResourceIDAnimationMapPair;


};


#endif 
