#ifdef LUNCHEON_ENABLE_FREETYPE

#include "font/FreeTypeFontCore.h"
#include "font/FreeTypeRenderedFont.h"
#include <string>
#include <iostream>

namespace Luncheon {


FreeTypeFontCore::~FreeTypeFontCore() {
  // Destroy all loaded fonts
  for (RenderedFontMap::iterator it = fonts_.begin();
       it != fonts_.end();
       it++) {
    delete (*it).second;
  }
  
  FT_Done_FreeType(ftLibraryObject_);
}

FreeTypeFontCore::FreeTypeFontCore(GraphicsCore& graphicsCore__)
  : FontCore(graphicsCore__) {
  FT_Init_FreeType(&ftLibraryObject_);
}
  
void FreeTypeFontCore::loadAndRenderASCIIFont(std::string filename,
                                         int pointSize) {
  RenderedFontMap::iterator existingFont
    = fonts_.find(filename);
    
  // Font already exists at some size
  if (existingFont != fonts_.end()) {
    // stop here if existingFont matches the specified point size
    // ...
  }
  // Font does not exist
  else {
    // Create new entry
    RenderedFont* newRenderedFont = new FreeTypeRenderedFont(graphicsCore_,
                                                             filename,
                                                             ftLibraryObject_);
    // Attempt to insert the new entry
    std::pair<RenderedFontMap::iterator, bool> insertResult
      = fonts_.insert(RenderedFontMapPair(newRenderedFont->fontName(),
                                          newRenderedFont));
     
    // Insert succeeded: update existingFont
    if (insertResult.second) {
      existingFont = insertResult.first;
    }
    // Insert failed: stop
    else {
      return;
    }
  }
  
  // add new font size
  existingFont->second->renderASCIISet(pointSize);
  
}

WritePosition FreeTypeFontCore::writeMessage(const std::string& message,
                                             const std::string& fontName,
                                             int fontSize,
                                             DrawableSurface& destination,
                                             WritePosition penPosition,
                                             DrawColor penColor) {
  // Get the specified font
  RenderedFontMap::iterator targetFontIterator
    = fonts_.find(fontName);
    
  if (targetFontIterator == fonts_.end()) {
    // font not loaded:
    // either load font or bail
    // ...
    return WritePosition();
  }
  
  // check if target font size is loaded
  // ...
    
    
  // Draw message
  return targetFontIterator->second->writeMessage(message,
                                                  fontSize,
                                                  destination,
                                                  penPosition,
                                                  penColor);
}
  
FT_Library& FreeTypeFontCore::ftLibraryObject() {
  return ftLibraryObject_;
}


}; 

#endif