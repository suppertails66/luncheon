#ifndef VORBISFILEVORBISSOUNDOPENER_H
#define VORBISFILEVORBISSOUNDOPENER_H


#ifdef LUNCHEON_ENABLE_VORBISFILE

#include "sound/VorbisSoundOpener.h"
#include "vorbisfile.h"
#include "codec.h"

namespace Luncheon {


class vorbisfileVorbisSoundOpener : public VorbisSoundOpener {
public:
  virtual ~vorbisfileVorbisSoundOpener();
  
  vorbisfileVorbisSoundOpener();
  
  virtual SoundFile* loadVorbis(const std::string& filename);
  
  virtual SoundFile* loadVorbis(ResourceFileHandle& fileHandle_);
protected:

  const static int maxReadSize = 4096;

  const static int bytesPerSample = 2;
  
  // 0 = unsigned, 1 = signed
  const static int nativeSignedness = 1;
  
  // 0 = little, 1 = big
  const static int nativeEndianness = 0;
  
};


};

#endif	// LUNCHEON_ENABLE_VORBISFILE


#endif 
