#include "font/FontWriter.h"

namespace Luncheon {


FontWriter::~FontWriter() { };

FontWriter::FontWriter()
  : sourceCache_(0) { };
  
FontWriter::FontWriter(FontCache* sourceCache__)
  : sourceCache_(sourceCache__) { };
                                 
WritePosition FontWriter::writeMessage(const std::string& message,
                                       DrawableSurface& destination,
                                       WritePosition penPosition,
                                       DrawColor penColor) {
  return sourceCache_.reference().writeMessage(message,
                                               destination,
                                               penPosition,
                                               penColor);
}


}; 
