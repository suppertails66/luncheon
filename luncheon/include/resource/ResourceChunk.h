#ifndef RESOURCECHUNK_H
#define RESOURCECHUNK_H


#include "resource/ResourceFileHandle.h"
#include "resource/ResourceChunkHeader.h"
#include "util/ByteSizes.h"
#include "util/EndiannessType.h"
#include "util/SignednessType.h"

namespace Luncheon {


class ResourceChunk {
public:
  virtual ~ResourceChunk();
  
  virtual ResourceChunkHeader& header();
  
  virtual void readResourceChunkHeader(ResourceFileHandle& fileHandle_);
  
protected:
  ResourceChunk();
  
  ResourceChunkHeader header_;
};


};


#endif 
