#include "font/FreeTypeRenderedFont.h"
#include "font/FontCache.h"
#include "font/FreeTypeFontCache.h"
#include <iostream>

namespace Luncheon {


FreeTypeRenderedFont::~FreeTypeRenderedFont() {
  // Destroy face object
  FT_Done_Face(ftFace);
};

FreeTypeRenderedFont::FreeTypeRenderedFont(GraphicsCore& graphicsCore__,
                                           const std::string& fontName__,
                                           FT_Library& ftLibraryObject__)
  : RenderedFont(graphicsCore__,
                 fontName__),
    ftLibraryObject_(ftLibraryObject__) {
  // Initialize face object
  /*int error = */FT_New_Face(ftLibraryObject_,
              fontName__.c_str(),
              0,
              &ftFace);
};
  
void FreeTypeRenderedFont::renderASCIISet(int pointSize) {
  SizedFontCacheMap::iterator existingSize
    = sizedFonts_.find(pointSize);
    
  // Size already exists
  if (existingSize != sizedFonts_.end()) {
    // nothing to do
    return;
  }
  // Size does not exist
  else {
    // Create cache
    FontCache* newCache = new FreeTypeFontCache(graphicsCore_,
                                                fontName_,
                                                pointSize,
                                                ftFace);
    // load file into new cache
    newCache->cacheASCIICharacters();
    
    // Add to caches
    sizedFonts_.insert(SizedFontCacheMapPair(pointSize,
                                             newCache));
  }
}
  
WritePosition FreeTypeRenderedFont::writeMessage(const std::string& message,
                                                 int fontSize,
                                                 DrawableSurface& destination,
                                                 WritePosition penPosition,
                                                 DrawColor penColor) {
  SizedFontCacheMap::iterator targetCacheIterator
    = sizedFonts_.find(fontSize);
    
  if (targetCacheIterator == sizedFonts_.end()) {
    // this font doesn't exist
    // ...
    return WritePosition();
  }
  
  // Draw message
  return targetCacheIterator->second->writeMessage(message,
                                                   destination,
                                                   penPosition,
                                                   penColor);
}


};
