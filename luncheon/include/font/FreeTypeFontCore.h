#ifndef FREETYPEFONTCORE_H
#define FREETYPEFONTCORE_H


#ifdef LUNCHEON_ENABLE_FREETYPE

#include "ft2build.h"
#include FT_FREETYPE_H
#include "font/FontCore.h"
#include "graphics/GraphicsCore.h"
#include <string>

namespace Luncheon {


class FreeTypeFontCore : public FontCore {
public:
  virtual ~FreeTypeFontCore();
  
  FreeTypeFontCore(GraphicsCore& graphicsCore__);
  
  // Abstract implementations
  
  virtual void loadAndRenderASCIIFont(std::string filename,
                                 int pointSize);
                                 
  virtual WritePosition writeMessage(const std::string& message,
                                     const std::string& fontName,
                                     int fontSize,
                                     DrawableSurface& destination,
                                     WritePosition penPosition,
                                     DrawColor penColor);
                                 
  // Extensions
  
  virtual FT_Library& ftLibraryObject();
protected:

  // FreeType library object
  FT_Library ftLibraryObject_;

};


};


#endif

#endif 
