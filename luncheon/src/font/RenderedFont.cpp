#include "font/RenderedFont.h"

namespace Luncheon {


RenderedFont::~RenderedFont() {
  // Destroy all loaded sizes
  for (SizedFontCacheMap::iterator it = sizedFonts_.begin();
       it != sizedFonts_.end();
       it++) {
    delete it->second;
  }
}

RenderedFont::RenderedFont(GraphicsCore& graphicsCore__,
                           const std::string& fontName__)
  : graphicsCore_(graphicsCore__),
    fontName_(fontName__) { };
  
std::string RenderedFont::fontName() {
  return fontName_;
}
  
SizedFontCacheMap& RenderedFont::sizedFonts() {
  return sizedFonts_;
}
                                     
FontCache* RenderedFont::getCachePointer(int pointSize) {
  SizedFontCacheMap::iterator targetSizeIterator
    = sizedFonts_.find(pointSize);
  
  if (targetSizeIterator == sizedFonts_.end()) {
    return 0;
  }
  
  return targetSizeIterator->second;
}

int RenderedFont::getLineHeight(int pointSize) {
  SizedFontCacheMap::iterator targetSizeIterator
    = sizedFonts_.find(pointSize);
    
  // Size not found
  if (targetSizeIterator == sizedFonts_.end()) {
    return 0;
  }
  
  return targetSizeIterator->second->lineHeight();
}


}; 
