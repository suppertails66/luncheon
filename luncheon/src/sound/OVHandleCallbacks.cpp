#ifdef LUNCHEON_ENABLE_VORBISFILE

#include "sound/OVHandleCallbacks.h"
#include "util/ByteSizes.h"
#include <iostream>

namespace Luncheon {


OVHandleCallbacks::~OVHandleCallbacks() { };

OVHandleCallbacks::OVHandleCallbacks(ResourceFileHandle& fileHandle__,
                                     int baseAddress__,
                                     int oggFileSize__)
  : fileHandle_(fileHandle__),
    baseAddress_(baseAddress__),
    oggFileSize_(oggFileSize__) {
    
  callbacks_.read_func = read_func;
  callbacks_.seek_func = seek_func;
  // Close function is null to prevent vorbisfile from automatically
  // closing the resource file stream when done
  callbacks_.close_func = 0;
  callbacks_.tell_func = tell_func;
  
//  std::cout << "oggFileSize_: " << oggFileSize_ << std::endl;
//  std::cout << "baseAddress_: " << baseAddress_ << std::endl;
  
}
  
ResourceFileHandle& OVHandleCallbacks::fileHandle() {
  return fileHandle_;
}

int OVHandleCallbacks::baseAddress() {
  return baseAddress_;
}
  
int OVHandleCallbacks::oggFileSize() {
  return oggFileSize_;
}
  
ov_callbacks OVHandleCallbacks::callbacks() {
  return callbacks_;
}
  
size_t OVHandleCallbacks::read_func(void* ptr,
                 size_t size,
                 size_t nmemb,
                 void* datasource) {
  OVHandleCallbacks& source = *((OVHandleCallbacks*)datasource);
  
//  std::cout << "start" << std::endl;
  
//  std::cout << "size: " << size << std::endl;
//  std::cout << "nmemb: " << nmemb << std::endl;
  
  int toRead = size * nmemb;
  int dataEnd = source.baseAddress() + source.oggFileSize();
  
  // Check how many bytes to end of file
  int remaining = dataEnd - source.fileHandle().tell();
  
//  std::cout << "pos: " << source.fileHandle().tell() << std::endl;
//  std::cout << "toRead: " << toRead << std::endl;
//  std::cout << "dataEnd: " << dataEnd << std::endl;
//  std::cout << "remaining: " << remaining << std::endl;
  
  // End of data
  if (remaining <= 0) {
    return 0;
  }
  
//  std::cout << "here" << std::endl;
  
  // Don't read past end of file
  if (toRead > remaining) {
    toRead = remaining;
  }
  
  source.fileHandle().read((char*)ptr,
                           toRead);
             
  // End of data              
//  if (source.fileHandle().tell() >= dataEnd) {
//    return 0;
//  }
  
  return toRead/size;
}

int OVHandleCallbacks::seek_func(void* datasource,
              ogg_int64_t offset,
              int whence) {
  OVHandleCallbacks& source = *((OVHandleCallbacks*)datasource);
  
  int base;
  if (whence == SEEK_SET) {
    base = source.baseAddress();
  
//    std::cout << "beginning" << std::endl;
//    std::cout << '\t' << "pos: " << source.fileHandle().tell() << std::endl;
//    std::cout << '\t' << "base: " << base << std::endl;
//    std::cout << '\t' << "offset: " << offset << std::endl;
  }
  else if (whence == SEEK_END) {
    base = source.baseAddress() + source.oggFileSize();
  
//    std::cout << "end" << std::endl;
//    std::cout << '\t' << "pos: " << source.fileHandle().tell() << std::endl;
//    std::cout << '\t' << "base: " << base << std::endl;
//    std::cout << '\t' << "offset: " << offset << std::endl;
  }
  else {
    base = source.fileHandle().tell();
  
//    std::cout << "current" << std::endl;
//    std::cout << '\t' << "pos: " << source.fileHandle().tell() << std::endl;
//    std::cout << '\t' << "base: " << base << std::endl;
//    std::cout << '\t' << "offset: " << offset << std::endl;
  }
//  std::cout << '\t' << "target: " << base + offset << std::endl;
  
  source.fileHandle().seek(base + offset);
  
  return 0;
}

/*int OVHandleCallbacks::close_func(void* datasource) {
  return 0;
} */

long OVHandleCallbacks::tell_func(void* datasource) {
  OVHandleCallbacks& source = *((OVHandleCallbacks*)datasource);
  
//  std::cout << (source.fileHandle().tell() - source.baseAddress()) << std::endl;
  
  return (source.fileHandle().tell() - source.baseAddress());
}


}; 

#endif