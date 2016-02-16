#ifndef RENDEREDFONT_H
#define RENDEREDFONT_H


#include <string>
#include "font/SizedFontCacheMap.h"
#include "graphics/GraphicsCore.h"
#include "font/WritePosition.h"
#include "graphics/DrawableSurface.h"
#include "graphics/DrawColor.h"
#include "font/FontCache.h"

namespace Luncheon {


class RenderedFont {
public:
  virtual ~RenderedFont();
  
  virtual std::string fontName();
  
  virtual SizedFontCacheMap& sizedFonts();
                                     
  virtual FontCache* getCachePointer(int pointSize);
                                     
  virtual int getLineHeight(int pointSize);
  
  virtual void renderASCIISet(int pointSize) =0;
  
  virtual WritePosition writeMessage(const std::string& message,
                                     int fontSize,
                                     DrawableSurface& destination,
                                     WritePosition penPosition,
                                     DrawColor penColor) =0;
protected:
  RenderedFont(GraphicsCore& graphicsCore__,
               const std::string& fontName__);
  
  GraphicsCore& graphicsCore_;
  
  std::string fontName_;
  
  // Container for the various font sizes rendered by this object
  SizedFontCacheMap sizedFonts_;
};


};


#endif 
