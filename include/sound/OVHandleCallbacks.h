#ifndef OVHANDLECALLBACKS_H
#define OVHANDLECALLBACKS_H


#include "codec.h"
#include "vorbisfile.h"
#include "resource/ResourceFileHandle.h"

namespace Luncheon {


class OVHandleCallbacks {
public:
  virtual ~OVHandleCallbacks();
  
  OVHandleCallbacks(ResourceFileHandle& fileHandle__,
                    int baseAddress__,
                    int oggFileSize__);
  
  virtual ResourceFileHandle& fileHandle();
  
  virtual int baseAddress();
  
  virtual int oggFileSize();
  
  virtual ov_callbacks callbacks();
protected:

  ResourceFileHandle& fileHandle_;
  
  int baseAddress_;
  
  int oggFileSize_;

  // The actual callback functions
  
  static size_t read_func(void* ptr,
                   size_t size,
                   size_t nmemb,
                   void* datasource);
  
  static int seek_func(void* datasource,
                ogg_int64_t offset,
                int whence);
  
  /*static int close_func(void* datasource); */
  
  static long tell_func(void* datasource);
  
  // Objects used for call to ov_open_callbacks

  ov_callbacks callbacks_;

};


};


#endif 
