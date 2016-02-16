#ifndef FREETYPERENDEREDFONT_H
#define FREETYPERENDEREDFONT_H


#ifdef LUNCHEON_ENABLE_FREETYPE

#include "ft2build.h"
#include FT_FREETYPE_H
#include "font/RenderedFont.h"
#include "font/FreeTypeFontCore.h"
#include <string>
#include "graphics/GraphicsCore.h"

namespace Luncheon {


class FreeTypeRenderedFont : public RenderedFont {
public:
  virtual ~FreeTypeRenderedFont();
  
  FreeTypeRenderedFont(GraphicsCore& graphicsCore__,
                       const std::string& fontName__,
                       FT_Library& ftLibraryObject__);
  
  virtual void renderASCIISet(int pointSize);
  
  virtual WritePosition writeMessage(const std::string& message,
                                     int fontSize,
                                     DrawableSurface& destination,
                                     WritePosition penPosition,
                                     DrawColor penColor);
protected:

  FT_Library& ftLibraryObject_;

  FT_Face ftFace;
};


};


#endif


#endif 
