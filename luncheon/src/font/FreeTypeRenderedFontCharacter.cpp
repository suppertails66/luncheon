#ifdef LUNCHEON_ENABLE_FREETYPE

#include "font/FreeTypeRenderedFontCharacter.h"
#include "graphics/DrawPosition.h"
#include <iostream>

namespace Luncheon {


FreeTypeRenderedFontCharacter::~FreeTypeRenderedFontCharacter() {
  // Destroy drawable
  delete drawable_;
  // Destroy source glyph
  FT_Done_Glyph(renderedGlyph_);
}

FreeTypeRenderedFontCharacter::FreeTypeRenderedFontCharacter(GraphicsCore& graphicsCore,
                                                             FT_Face& srcFace)
  : RenderedFontCharacter(),
    drawable_(0) {
  // initialize drawable
  FT_Get_Glyph(srcFace->glyph,
               &renderedGlyph_);
//  FT_Glyph temp;
    
//  FT_Get_Glyph(srcFace->glyph,
//               &temp);
//  FT_Glyph_Copy(temp,
//                &renderedGlyph_);
//  FT_Done_Glyph(temp);
  
  FT_BitmapGlyph bitmapGlyph
    = (FT_BitmapGlyph)renderedGlyph_;
               
  drawable_ = graphicsCore.createDrawableSurface(
    bitmapGlyph->bitmap.width,
    bitmapGlyph->bitmap.rows);
}
  
DrawableSurface& FreeTypeRenderedFontCharacter::generateDrawable(DrawColor color) {
  // Generate new drawable if color != currentColor_
  if (color != currentColor_) {
    copyGlyphToDrawable(color);
    currentColor_ = color;
  }
  return *drawable_;
}
  
WritePosition FreeTypeRenderedFontCharacter::writeCharacter(
                                     DrawableSurface& destination,
                                     WritePosition penPosition) {
  destination.blit(*drawable_,
                   penPosition.x() + getBitmapLeft(),
                   penPosition.y() - getBitmapTop());
//  std::cout << "writepos: " << penPosition.x() << " " << penPosition.y() << std::endl;
//  std::cout << "bitmapLeft: " << getBitmapLeft() << std::endl;
//  std::cout << "bitmapTop: " << getBitmapTop() << std::endl;
//  std::cout << "advanceX: " << (getAdvanceX() >> 16) << std::endl;
//  std::cout << "advanceY: " << (getAdvanceY() >> 16) << std::endl;
                   
  return WritePosition(penPosition.x() + (getAdvanceX() >> 16),
                       penPosition.y() + (getAdvanceY() >> 16),
                       penPosition.baseX(),
                       penPosition.baseY());
}

DrawableSurface& FreeTypeRenderedFontCharacter::currentDrawable() {
  return *drawable_;
}
  
DrawColor FreeTypeRenderedFontCharacter::currentColor() {
  return currentColor_;
}
  
int FreeTypeRenderedFontCharacter::getBitmapLeft() {
  return ((FT_BitmapGlyph)renderedGlyph_)->left;
}

int FreeTypeRenderedFontCharacter::getBitmapTop() {
  return ((FT_BitmapGlyph)renderedGlyph_)->top;
}

int FreeTypeRenderedFontCharacter::getAdvanceX() {
  return renderedGlyph_->advance.x;
  
}

int FreeTypeRenderedFontCharacter::getAdvanceY() {
  return renderedGlyph_->advance.y;
}
  
void FreeTypeRenderedFontCharacter::copyGlyphToDrawable(DrawColor color) {
  FT_BitmapGlyph nativeGlyph = (FT_BitmapGlyph)renderedGlyph_;
  
  // Mono mode
  if (nativeGlyph->bitmap.pixel_mode == FT_PIXEL_MODE_MONO) {
    unsigned char* pixPointer = nativeGlyph->bitmap.buffer;
    DrawPosition currentDrawPos(0, 0);
    
    // Starting position in byte: most significant bit
    int inPixPosition = 128;
    
    // Copy bitmap to drawable, replacing each set bit
    // with the specified DrawColor
    for (int i = 0; i < nativeGlyph->bitmap.rows; i++) {
      int pixelsLeft = nativeGlyph->bitmap.width;
      int rowPos = 0;
      while (pixelsLeft > 0) {
      
        if (*(pixPointer + rowPos) & inPixPosition) {
          currentDrawPos = drawable_->draw(currentDrawPos,
                                           color,
                                           1);
//          std::cout << "1";
        }
        else {
          // transparent: don't draw
          currentDrawPos.setX(currentDrawPos.x() + 1);
          if (currentDrawPos.x() >= nativeGlyph->bitmap.width) {
            currentDrawPos.setX(0);
            currentDrawPos.setY(currentDrawPos.y() + 1);
          }
//          std::cout << "0";
        }
        
        --pixelsLeft;
        
        inPixPosition >>= 1;
        // Move to next byte if at end of current one
        if (inPixPosition == 0) {
          inPixPosition = 128;
          ++rowPos;
        }
      }
//      std::cout << std::endl;
      pixPointer += nativeGlyph->bitmap.pitch;
      inPixPosition = 128;
    }
  }
}


}; 

#endif