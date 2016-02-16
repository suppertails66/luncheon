#ifndef FREETYPEFONTCACHE_H
#define FREETYPEFONTCACHE_H


#include "ft2build.h"
#include FT_FREETYPE_H
#include "font/FontCache.h"
#include <string>

namespace Luncheon {


class FreeTypeFontCache : public FontCache {
public:
  virtual ~FreeTypeFontCache();
  
  FreeTypeFontCache(GraphicsCore& graphicsCore__,
                    const std::string& filename__,
                    int pointSize__,
                    FT_Face& ftFace__);
                                     
  virtual int lineHeight();
  
  virtual void cacheASCIICharacters();
  
  virtual WritePosition writeMessage(const std::string& message,
                                     DrawableSurface& destination,
                                     WritePosition penPosition,
                                     DrawColor penColor);
protected:

  FT_Face& ftFace_;
  
  int lineHeight_;

};


};


#endif 
