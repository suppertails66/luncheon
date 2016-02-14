#include "font/FontCore.h"

namespace Luncheon {


FontCore::~FontCore() {
  /* Ideally, the pointers in fonts_ would be deleted here.
     However, C++'s immutable reverse order of destructor invocation
     conflicts with the call to FT_Done_FreeType() needed
     to shut down the FreeType library in FreeTypeFontCore
     -- that call must occur in the subclass's destructor,
     but that destructor will be invoked before this one,
     causing the FreeType function calls used for cleanup
     in the stored fonts' destructors to go nowhere. Thus,
     the responsibility for deleting all of the pointers
     in the RenderedFontMap is delegated to derived classes.
     Any subclass that fails to do so will leak memory. */
}

FontCore::FontCore(GraphicsCore& graphicsCore__)
  : graphicsCore_(graphicsCore__) { };
  
FontWriter FontCore::makeFontWriter(const std::string filename,
                                    int pointSize) {
  RenderedFontMap::iterator targetFontIterator
    = fonts_.find(filename);
    
  if (targetFontIterator == fonts_.end()) {
    return FontWriter();
  }
  
  return FontWriter(
    targetFontIterator->second->getCachePointer(pointSize));
}
                                     
int FontCore::getLineHeight(const std::string filename,
                            int pointSize) {
  RenderedFontMap::iterator targetFontIterator
    = fonts_.find(filename);
    
  if (targetFontIterator == fonts_.end()) {
    return 0;
  }
  
  return targetFontIterator->second->getLineHeight(pointSize);
}
  
RenderedFontMap& FontCore::fonts() {
  return fonts_;
}


}; 
