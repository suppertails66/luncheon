#include "resource/ResourceChunk.h"

namespace Luncheon {


ResourceChunk::~ResourceChunk() { };
  
ResourceChunk::ResourceChunk() { };
  
ResourceChunkHeader& ResourceChunk::header() {
  return header_;
}
  
void ResourceChunk::readResourceChunkHeader(ResourceFileHandle& fileHandle_) {
  header_.setChunkID(fileHandle_.readInt(ByteSizes::uint32Size,
                                         EndiannessTypes::little,
                                         SignednessTypes::nosign));
  header_.setChunkSize(fileHandle_.readInt(ByteSizes::uint32Size,
                                           EndiannessTypes::little,
                                           SignednessTypes::nosign));
}


}; 
