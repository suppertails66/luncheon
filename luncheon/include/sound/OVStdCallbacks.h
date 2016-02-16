#ifndef OVSTDCALLBACKS_H
#define OVSTDCALLBACKS_H


#include "codec.h"
#include "vorbisfile.h"
#include <fstream>

namespace Luncheon {


class OVStdCallbacks {
public:
  virtual ~OVStdCallbacks();
  
  OVStdCallbacks(std::ifstream& ifs__);
  
  ov_callbacks callbackFunctions();
  
  std::ifstream& ifs();
protected:

  // The actual callback functions
  
  static size_t read_func(void* ptr,
                   size_t size,
                   size_t nmemb,
                   void* datasource);
  
  static int seek_func(void* datasource,
                ogg_int64_t offset,
                int whence);
  
  static int close_func(void* datasource);
  
  static long tell_func(void* datasource);
  
  // Objects used for call to ov_open_callbacks

  ov_callbacks callbackFunctions_;

  std::ifstream& ifs_;
  
};


};


#endif
