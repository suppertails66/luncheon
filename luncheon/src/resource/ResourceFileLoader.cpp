#include "resource/ResourceFileLoader.h"
#include <iostream>

namespace Luncheon {


ResourceFileLoader::~ResourceFileLoader() { };
  
IndexResourceChunk& ResourceFileLoader::index() {
  return index_;
}

ResourceFileLoader::ResourceFileLoader(const std::string& filename)
  : fileHandle_(filename) {
  // Read the file index
  index_.readIndexChunk(fileHandle_);
                                                                  
/*  ResourceIDIndexMap::iterator it
    = index_.entries().find(1);
  if (it == index_.entries().end()) {
    std::cerr << "bad" << std::endl;
  }
  else {
    std::cout << it->second.address() << std::endl;
  } */
}
  

}; 
