#ifndef INDEXRESOURCECHUNK_H
#define INDEXRESOURCECHUNK_H


#include "resource/ResourceChunk.h"
#include "resource/ResourceIDIndexMap.h"
#include "resource/ResourceFileHandle.h"
#include "resource/ResourceTypeID.h"
#include "resource/ResourceID.h"
#include "resource/ResourceAddress.h"
#include "IndexResourceChunkEntry.h"

namespace Luncheon {


class IndexResourceChunk : public ResourceChunk {
public:
  virtual ~IndexResourceChunk();
  
  IndexResourceChunk();
  
  virtual IndexResourceChunkEntry getIndexEntry(ResourceID id);
  
  virtual int numEntries();
  virtual void setNumEntries(int numEntries__);
  
  virtual void readIndexChunk(ResourceFileHandle& fileHandle_);
  
  virtual ResourceIDIndexMap& entries();
  
protected:
  
  int numEntries_;
  
  ResourceIDIndexMap entries_;
  
};


};


#endif 
