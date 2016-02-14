#ifndef FONTCACHE_H
#define FONTCACHE_H


#include "font/CharacterCodeFontMap.h"
#include <string>
#include "graphics/GraphicsCore.h"
#include "graphics/DrawableSurface.h"
#include "font/WritePosition.h"
#include "graphics/DrawColor.h"

namespace Luncheon {


class FontCache {
public:
  virtual ~FontCache();
  
  virtual CharacterCodeFontMap& characters();
  
  virtual int pointSize();
                                     
  virtual int lineHeight() =0;
  
  virtual void cacheASCIICharacters() =0;
  
  virtual WritePosition writeMessage(const std::string& message,
                                     DrawableSurface& destination,
                                     WritePosition penPosition,
                                     DrawColor penColor) =0;
protected:
  FontCache(GraphicsCore& graphicsCore__,
            const std::string& filename__,
            int pointSize__);
            
  GraphicsCore& graphicsCore_;
  
  CharacterCodeFontMap characters_;
  
  int pointSize_;
};


};


#endif 
