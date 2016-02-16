#include "font/FreeTypeFontCache.h"
#include "font/FreeTypeRenderedFontCharacter.h"
#include <iostream>

namespace Luncheon {


FreeTypeFontCache::~FreeTypeFontCache() { };

FreeTypeFontCache::FreeTypeFontCache(GraphicsCore& graphicsCore__,
                                     const std::string& filename__,
                                     int pointSize__,
                                     FT_Face& ftFace__)
  : FontCache(graphicsCore__,
              filename__, 
              pointSize__),
    ftFace_(ftFace__) {
//  int pixelSize = pointSize__ * resolution / 72;
//  int pizelCoord = gridCoord * pixelSize / EMSize;
}
                                     
int FreeTypeFontCache::lineHeight() {
  return lineHeight_;
}
  
void FreeTypeFontCache::cacheASCIICharacters() {
  // Set face object to selected size
  FT_Set_Char_Size(ftFace_,
                   0,
                   pointSize_ * 64, // fix this
                   0,
                   0);
                   
  lineHeight_ = (ftFace_->size->metrics.height >> 6);
//  std::cout << lineSpacing_ << std::endl;
/*  // Load ASCII characters and add to map
  // ...
  int glyphIndex = FT_Get_Char_Index(ftFace_, 65);
  FT_Load_Glyph(ftFace_,
                glyphIndex,
                FT_LOAD_DEFAULT);
  FT_Render_Glyph(ftFace_->glyph,
                            FT_RENDER_MODE_MONO);
                            
  std::cout << "rows: " << ftFace_->glyph->bitmap.rows << std::endl;
  std::cout << "width: " << ftFace_->glyph->bitmap.width << std::endl;
  std::cout << "pitch: " << ftFace_->glyph->bitmap.pitch << std::endl;
                            
  if (ftFace_->glyph->bitmap.pixel_mode == FT_PIXEL_MODE_MONO) {
    unsigned char* pixPointer = ftFace_->glyph->bitmap.buffer;
    int inPixPosition = 128;
    for (int i = 0; i < ftFace_->glyph->bitmap.rows; i++) {
      int pixelsLeft = ftFace_->glyph->bitmap.width;
      int rowPos = 0;
      while (pixelsLeft > 0) {
      
        if (*(pixPointer + rowPos) & inPixPosition) {
          std::cout << "1";
        }
        else {
          std::cout << "0";
        }
        
        --pixelsLeft;
        
        inPixPosition >>= 1;
        if (inPixPosition == 0) {
          inPixPosition = 128;
          ++rowPos;
        }
      }
      std::cout << std::endl;
      pixPointer += ftFace_->glyph->bitmap.pitch;
      inPixPosition = 128;
    }
  } */
  for (int i = 0; i < 256; i++) {
    CharacterCodeFontMap::iterator targetCharacter
      = characters_.find(static_cast<CharacterCode>(i));
    
    // Ignore character if already rendered
    if (targetCharacter != characters_.end()) {
      continue;
    }
      
    int glyphIndex = FT_Get_Char_Index(ftFace_, i);
    
    int error = FT_Load_Glyph(ftFace_,
                              glyphIndex,
                              FT_LOAD_DEFAULT);
                              
    if (error != 0) {
//      std::cout << "load error at " << i << std::endl;
      continue;
    }
    
    // Render without antialiasing (we want blocky fonts!)
    error = FT_Render_Glyph(ftFace_->glyph,
                            FT_RENDER_MODE_MONO);
                              
    if (error != 0) {
//      std::cout << "render error at " << i << std::endl;
      continue;
    }
    
    RenderedFontCharacter* newCharacter
      = new FreeTypeRenderedFontCharacter(graphicsCore_,
                                          ftFace_);
                      
/*    if (i >= 65) {
      std::cout << "num: " << i << std::endl;
      std::cout << "rows: " << ftFace_->glyph->bitmap.rows << std::endl;
      std::cout << "width: " << ftFace_->glyph->bitmap.width << std::endl;
      std::cout << "pitch: " << ftFace_->glyph->bitmap.pitch << std::endl;
                        
      if (ftFace_->glyph->bitmap.pixel_mode == FT_PIXEL_MODE_MONO) {
        unsigned char* pixPointer = ftFace_->glyph->bitmap.buffer;
        int inPixPosition = 128;
        for (int i = 0; i < ftFace_->glyph->bitmap.rows; i++) {
          int pixelsLeft = ftFace_->glyph->bitmap.width;
          int rowPos = 0;
          while (pixelsLeft > 0) {
          
            if (*(pixPointer + rowPos) & inPixPosition) {
              std::cout << "1";
            }
            else {
              std::cout << "0";
            }
            
            --pixelsLeft;
            
            inPixPosition >>= 1;
            if (inPixPosition == 0) {
              inPixPosition = 128;
              ++rowPos;
            }
          }
          std::cout << std::endl;
          pixPointer += ftFace_->glyph->bitmap.pitch;
          inPixPosition = 128;
        }
      }
      char c;
      std::cin >> c;
    } */
    
    characters_.insert(CharacterCodeFontMapPair(
                        static_cast<CharacterCode>(i),
                        newCharacter)
                      );
    
  }
}
  
WritePosition FreeTypeFontCache::writeMessage(
                                     const std::string& message,
                                     DrawableSurface& destination,
                                     WritePosition penPosition,
                                     DrawColor penColor) {
  // Write each character in message
  for (std::string::const_iterator it = message.begin();
       it != message.end();
       it++) {
       
//    std::cout << "printing: " << (*it) << std::endl;

    // Auto-newlines
    if ((*it) == '\n') {
      penPosition.setX(penPosition.baseX());
      penPosition.setY(penPosition.y() + lineHeight_);
      continue;
    }
    
    CharacterCodeFontMap::iterator targetCharacterIterator
      = characters_.find(static_cast<CharacterCode>(*it));
      
    // Character is not loaded: skip
    if (targetCharacterIterator == characters_.end()) {
      continue;
    }
    
    // Generate target character's DrawableSurface for this color
    targetCharacterIterator->second->generateDrawable(penColor);
    
    // Copy to destination
    penPosition = targetCharacterIterator->second->writeCharacter(
                                                    destination,
                                                    penPosition);
    
  }
  
  return penPosition;
}
  
  
};
