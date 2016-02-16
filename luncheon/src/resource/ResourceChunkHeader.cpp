#include "resource/ResourceChunkHeader.h"

namespace Luncheon {


ResourceChunkHeader::~ResourceChunkHeader() { };

ResourceChunkHeader::ResourceChunkHeader()
  : chunkID_(0),
    chunkSize_(0) { };
  
ResourceChunkHeader::ResourceChunkHeader(int chunkID__,
                                         int chunkSize__)
  : chunkID_(chunkID__),
    chunkSize_(chunkSize__) { };
  
ResourceChunkID ResourceChunkHeader::chunkID() {
  return chunkID_;
}

void ResourceChunkHeader::setChunkID(ResourceChunkID chunkID__) {
  chunkID_ = chunkID__;
}

int ResourceChunkHeader::chunkSize() {
  return chunkSize_;
}

void ResourceChunkHeader::setChunkSize(int chunkSize__) {
  chunkSize_ = chunkSize__;
}


};
