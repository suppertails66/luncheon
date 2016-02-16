#ifndef RESOURCECHUNKHEADER_H
#define RESOURCECHUNKHEADER_H


#include "resource/ResourceChunkID.h"

namespace Luncheon {


class ResourceChunkHeader {
public:
  virtual ~ResourceChunkHeader();
  
  ResourceChunkHeader();
  
  ResourceChunkHeader(int chunkID__,
                      int chunkSize__);
  
  virtual ResourceChunkID chunkID();
  virtual void setChunkID(ResourceChunkID chunkID__);
  
  virtual int chunkSize();
  virtual void setChunkSize(int chunkSize__);
protected:

  int chunkID_;
  
  int chunkSize_;

};


};


#endif 
