#ifndef LOADCOUNTMAP
#define LOADCOUNTMAP


#include <unordered_map>
#include "resource/ResourceID.h"

namespace Luncheon {


typedef std::unordered_map<Luncheon::ResourceID, int> LoadCountMap;
typedef std::pair<Luncheon::ResourceID, int> LoadCountMapPair;



};


#endif 
