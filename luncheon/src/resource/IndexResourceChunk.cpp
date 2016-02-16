#include "resource/IndexResourceChunk.h"
#include <iostream>

namespace Luncheon {


IndexResourceChunk::~IndexResourceChunk() { };

IndexResourceChunk::IndexResourceChunk()
  : numEntries_(0) { };
  
IndexResourceChunkEntry IndexResourceChunk::getIndexEntry(ResourceID id) {
  ResourceIDIndexMap::iterator targetEntry
    = entries_.find(id);
  
  // Resource not in index
  if (targetEntry == entries_.end()) {
    return IndexResourceChunkEntry();
  }
  
  return targetEntry->second;
}
  
int IndexResourceChunk::numEntries() {
  return numEntries_;
}
void IndexResourceChunk::setNumEntries(int numEntries__) {
  numEntries_ = numEntries__;
}
  
ResourceIDIndexMap& IndexResourceChunk::entries() {
  return entries_;
}

  
void IndexResourceChunk::readIndexChunk(ResourceFileHandle& fileHandle_) {
  readResourceChunkHeader(fileHandle_);

  numEntries_ = fileHandle_.readInt(ByteSizes::uint32Size,
                                    EndiannessTypes::little,
                                    SignednessTypes::nosign);
  
  // Read each entry and add to index
  for (int i = 0; i < numEntries_; i++) {
    ResourceTypeID typeID = fileHandle_.readInt(ByteSizes::uint32Size,
                                                EndiannessTypes::little,
                                                SignednessTypes::nosign);
                                                
    ResourceID id = fileHandle_.readInt(ByteSizes::uint32Size,
                                        EndiannessTypes::little,
                                        SignednessTypes::nosign);
                                        
    ResourceAddress address = fileHandle_.readInt(ByteSizes::uint32Size,
                                                  EndiannessTypes::little,
                                                  SignednessTypes::nosign);
                                                  
//    std::cout << "typeID: " << std::hex << typeID << std::endl;
//    std::cout << "id: " << std::hex << id << std::endl;
//    std::cout << "address: " << std::hex << address << std::endl;
                                                  
    IndexResourceChunkEntry entry(typeID, id, address);
                                                  
    entries_.insert(ResourceIDIndexMapPair(id, 
                                          IndexResourceChunkEntry(typeID, 
                                                                  id,
                                                                  address)));
  }
}



}; 
