#ifdef LUNCHEON_ENABLE_VORBISFILE

#include "sound/OVStdCallbacks.h"

namespace Luncheon {


OVStdCallbacks::~OVStdCallbacks() { };
  
OVStdCallbacks::OVStdCallbacks(std::ifstream& ifs__)
  : ifs_(ifs__) {
  callbackFunctions_.read_func = read_func;
  callbackFunctions_.seek_func = seek_func;
  callbackFunctions_.close_func = close_func;
  callbackFunctions_.tell_func = tell_func;
}
  
ov_callbacks OVStdCallbacks::callbackFunctions() {
  return callbackFunctions_;
}
  
std::ifstream& OVStdCallbacks::ifs() {
  return ifs_;
}
  
size_t OVStdCallbacks::read_func(void* ptr,
                 size_t size,
                 size_t nmemb,
                 void* datasource) {
  std::ifstream& ifs = (std::ifstream&) *((std::ifstream*)datasource);
  char* dst = (char*)ptr;
  ifs.read(dst, size * nmemb);
  
  // should really look up how to handle failure here...
  if (ifs.eof()) {
    return 0;
  }
  return nmemb;
}

int OVStdCallbacks::seek_func(void* datasource,
              ogg_int64_t offset,
              int whence) {
  std::ifstream& ifs = (std::ifstream&) *((std::ifstream*)datasource);
  ifs.clear();
}

int OVStdCallbacks::close_func(void* datasource) {
  
}

long OVStdCallbacks::tell_func(void* datasource) {
  
}


}; 

#endif