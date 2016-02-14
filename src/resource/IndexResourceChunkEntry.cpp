#include "resource/IndexResourceChunkEntry.h"

namespace Luncheon {


IndexResourceChunkEntry::~IndexResourceChunkEntry() { }
  
IndexResourceChunkEntry::IndexResourceChunkEntry()
  : typeID_(0),
    id_(0),
    address_(0) { };
    
IndexResourceChunkEntry::IndexResourceChunkEntry(
                                        ResourceTypeID typeID__,
                                        ResourceID id__,
                                        ResourceAddress address__)
  : typeID_(typeID__),
    id_(id__),
    address_(address__) { };
  
ResourceTypeID IndexResourceChunkEntry::typeID() {
  return typeID_;
}

void IndexResourceChunkEntry::setTypeID(ResourceTypeID typeID__) {
  typeID_ = typeID__;
}

ResourceID IndexResourceChunkEntry::id() {
  return id_;
}
void IndexResourceChunkEntry::setID(ResourceID id__) {
  id_ = id__;
}

ResourceAddress IndexResourceChunkEntry::address() {
  return address_;
}

void IndexResourceChunkEntry::setAddress(ResourceAddress address__) {
  address_ = address__;
}


}; 
