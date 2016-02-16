#include "resource/ResourceFileHandle.h"
#include "util/EndiannessType.h"
#include "util/SignednessType.h"
#include <cstring>
#include <iostream>

namespace Luncheon {


ResourceFileHandle::~ResourceFileHandle() { };
  
ResourceFileHandle::ResourceFileHandle(
                      const std::string& resourceFileName__)
  : resourceFile_(resourceFileName__, 
        std::ios_base::in
          | std::ios_base::binary),
    resourceFileName_(resourceFileName__) { };
  
std::ifstream& ResourceFileHandle::resourceFile() {
  return resourceFile_;
}

std::string ResourceFileHandle::resourceFileName() {
  return resourceFileName_;
}
  
void ResourceFileHandle::seek(int position) {
  resourceFile_.seekg(position);
}
  
int ResourceFileHandle::tell() {
  return resourceFile_.tellg();
}
  
void ResourceFileHandle::read(char* dest,
                              int num) {
  resourceFile_.read(dest, num);
}
                    
int ResourceFileHandle::readInt(int numBytes,
                                EndiannessTypes::EndiannessType endianness,
                                SignednessTypes::SignednessType signedness) {
  if (numBytes > readBufferSize) {
    // we can't do this...
  }
  
  // zero the read buffer
//  std::memset(readBuffer, 0, readBufferSize);
  
  resourceFile_.read((char*)readBuffer, numBytes);
  return ByteConversion::fromBytes((char*)readBuffer,
                                   numBytes,
                                   endianness,
                                   signedness);
}
  
void ResourceFileHandle::readResourceChunkHeader(ResourceChunkHeader& dest) {
  dest.setChunkID(readInt(ByteSizes::uint32Size,
                          EndiannessTypes::little,
                          SignednessTypes::nosign));
  
  dest.setChunkSize(readInt(ByteSizes::uint32Size,
                          EndiannessTypes::little,
                          SignednessTypes::nosign));
  
}


}; 
