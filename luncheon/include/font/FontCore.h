#ifndef FONTCORE_H
#define FONTCORE_H


#include "graphics/GraphicsCore.h"
#include "font/RenderedFontMap.h"
#include <string>
#include "font/WritePosition.h"
#include "graphics/DrawColor.h"
#include "graphics/DrawableSurface.h"
#include "font/FontWriter.h"

namespace Luncheon {


class FontCore {
public:
  virtual ~FontCore();
  
  virtual RenderedFontMap& fonts();
  
  virtual FontWriter makeFontWriter(const std::string filename,
                                    int pointSize);
                                     
  virtual int getLineHeight(const std::string filename,
                            int pointSize);
  
  virtual void loadAndRenderASCIIFont(std::string filename,
                                 int pointSize) =0;
                                 
  virtual WritePosition writeMessage(const std::string& message,
                                     const std::string& fontName,
                                     int fontSize,
                                     DrawableSurface& destination,
                                     WritePosition penPosition,
                                     DrawColor penColor) =0;
protected:
  FontCore(GraphicsCore& graphicsCore__);
  
  GraphicsCore& graphicsCore_;
  
  RenderedFontMap fonts_;
};


};


#endif
