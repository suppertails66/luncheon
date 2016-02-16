#ifndef SIZEDFONTCACHEMAP_H
#define SIZEDFONTCACHEMAP_H


#include <unordered_map>
#include "font/FontCache.h"

namespace Luncheon {


typedef std::unordered_map<int, FontCache*> SizedFontCacheMap;
typedef std::pair<int, FontCache*> SizedFontCacheMapPair;


};


#endif 
