#ifndef VORBISSOUNDOPENER_H
#define VORBISSOUNDOPENER_H


#include "sound/SoundOpener.h"
#include "sound/SoundFile.h"
#include <string>
#include "resource/ResourceFileHandle.h"

namespace Luncheon {


class VorbisSoundOpener : public SoundOpener {
public:
  virtual ~VorbisSoundOpener();
  
  virtual SoundFile* loadVorbis(const std::string& filename) =0;
  
  virtual SoundFile* loadVorbis(ResourceFileHandle& fileHandle_) =0;
protected:
  VorbisSoundOpener();
};


};


#endif 
