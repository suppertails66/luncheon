#ifndef RESOURCEFILELOADER_H
#define RESOURCEFILELOADER_H


#include "resource/ResourceFileHandle.h"
#include "resource/IndexResourceChunk.h"
#include "util/ByteSizes.h"
#include "util/EndiannessType.h"
#include "util/SignednessType.h"

namespace Luncheon {


class ResourceFileLoader {
public:
  virtual ~ResourceFileLoader();
  
  IndexResourceChunk& index();
protected:
  ResourceFileLoader(const std::string& filename);
  
  ResourceFileHandle fileHandle_;
  
  IndexResourceChunk index_;
};


};


#endif 
