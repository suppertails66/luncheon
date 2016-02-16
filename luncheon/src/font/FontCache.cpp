#include "font/FontCache.h"

namespace Luncheon {


FontCache::~FontCache() {
  // Destroy all loaded characters
  for (CharacterCodeFontMap::iterator it = characters_.begin();
       it != characters_.end();
       it++) {
    delete it->second;
  }
}

FontCache::FontCache(GraphicsCore& graphicsCore__,
                     const std::string& filename__,
                     int pointSize__)
  : graphicsCore_(graphicsCore__),
    pointSize_(pointSize__) { };
  
CharacterCodeFontMap& FontCache::characters() {
  return characters_;
}
  
int FontCache::pointSize() {
  return pointSize_;
}


}; 
