#ifndef FONTWRITER_H
#define FONTWRITER_H


#include "util/DumbPointer.h"
#include "font/FontCache.h"
#include "font/WritePosition.h"
#include "graphics/DrawableSurface.h"
#include "graphics/DrawColor.h"

namespace Luncheon {


class FontWriter {
public:
  virtual ~FontWriter();
  
  FontWriter();
  
  FontWriter(FontCache* sourceCache__);
                                 
  virtual WritePosition writeMessage(const std::string& message,
                                     DrawableSurface& destination,
                                     WritePosition penPosition,
                                     DrawColor penColor);
protected:
  
  DumbPointer<FontCache> sourceCache_;
};


};


#endif 
