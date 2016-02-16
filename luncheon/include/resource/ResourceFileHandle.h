#ifndef RESOURCEFILEHANDLE_H
#define RESOURCEFILEHANDLE_H


#include <string>
#include <fstream>
#include "resource/ResourceChunkHeader.h"
#include "util/ByteConversion.h"
#include "util/ByteSizes.h"
#include "util/EndiannessType.h"
#include "util/SignednessType.h"

namespace Luncheon {


class ResourceFileHandle {
public:
  virtual ~ResourceFileHandle();
  
  ResourceFileHandle(const std::string& resourceFileName__);
  
  std::ifstream& resourceFile();
  
  std::string resourceFileName();
  
  virtual void seek(int position);
  
  virtual int tell();
  
  virtual void read(char* dest,
                    int num);
                    
  virtual int readInt(int numBytes,
                      EndiannessTypes::EndiannessType endianness,
                      SignednessTypes::SignednessType signedness);
  
  virtual void readResourceChunkHeader(ResourceChunkHeader& dest);
protected:
  
  std::ifstream resourceFile_;
  
  std::string resourceFileName_;
  
  const static int readBufferSize = ByteSizes::uint128Size;
  
  // Buffer to temporarily store raw representation of ints
  // and other formats that require conversion
  char readBuffer[readBufferSize];
  
};


};


#endif 
