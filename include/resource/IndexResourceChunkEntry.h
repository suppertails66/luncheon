#ifndef INDEXRESOURCECHUNKENTRY_H
#define INDEXRESOURCECHUNKENTRY_H


#include "resource/ResourceTypeID.h"
#include "resource/ResourceID.h"
#include "resource/ResourceAddress.h"

namespace Luncheon {


class IndexResourceChunkEntry {
public:
  virtual ~IndexResourceChunkEntry();
  
  IndexResourceChunkEntry();
  
  IndexResourceChunkEntry(ResourceTypeID typeID__,
                          ResourceID id__,
                          ResourceAddress address__);
  
  virtual ResourceTypeID typeID();
  virtual void setTypeID(ResourceTypeID typeID__);
  
  virtual ResourceID id();
  virtual void setID(ResourceID id__);
  
  virtual ResourceAddress address();
  virtual void setAddress(ResourceAddress address__);
  
protected:
  
  ResourceTypeID typeID_;
  
  ResourceID id_;
  
  ResourceAddress address_;
  
};


};


#endif 
