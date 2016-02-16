#ifndef FREETYPERENDEREDFONTCHARACTER_H
#define FREETYPERENDEREDFONTCHARACTER_H


#ifdef LUNCHEON_ENABLE_FREETYPE

#include "ft2build.h"
#include FT_FREETYPE_H
#include FT_GLYPH_H
#include "font/RenderedFontCharacter.h"
#include "graphics/DrawableSurface.h"
#include "graphics/GraphicsCore.h"

namespace Luncheon {


class FreeTypeRenderedFontCharacter : public RenderedFontCharacter {
public:
  virtual ~FreeTypeRenderedFontCharacter();
  
  FreeTypeRenderedFontCharacter(GraphicsCore& graphicsCore,
                                FT_Face& srcFace);
  
  virtual DrawableSurface& generateDrawable(DrawColor color);
  
  virtual WritePosition writeCharacter(DrawableSurface& destination,
                                       WritePosition penPosition);
  
  virtual DrawableSurface& currentDrawable();
  
  virtual DrawColor currentColor();
  
  virtual int getBitmapLeft();
  
  virtual int getBitmapTop();
  
  virtual int getAdvanceX();
  
  virtual int getAdvanceY();
protected:

  FT_Glyph renderedGlyph_;

  DrawableSurface* drawable_;
  
  DrawColor currentColor_;
  
  virtual void copyGlyphToDrawable(DrawColor color);

};


};

#endif


#endif
