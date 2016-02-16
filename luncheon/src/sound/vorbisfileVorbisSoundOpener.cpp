#include "sound/vorbisfileVorbisSoundOpener.h"
#include "sound/RawSoundFile.h"
#include "util/EndiannessType.h"
#include <cstdio>
#include <iostream>
#include "sound/OVHandleCallbacks.h"

namespace Luncheon {


vorbisfileVorbisSoundOpener::~vorbisfileVorbisSoundOpener() { };
  
vorbisfileVorbisSoundOpener::vorbisfileVorbisSoundOpener()
  : VorbisSoundOpener() { };
  
SoundFile* vorbisfileVorbisSoundOpener::loadVorbis(
                                const std::string& filename) {
  // use OVStdCallbacks here
  // ...
  
  FILE* f = std::fopen(filename.c_str(), "rb");
  OggVorbis_File vf;
  if (ov_open_callbacks(f, &vf, 0, 0, OV_CALLBACKS_DEFAULT)) {
    // file is not an Ogg bitstream
    std::fclose(f);
    return 0;
  }
  
  // Get number of samples and create buffer
  vorbis_info* info = ov_info(&vf, -1);
  int numChannels = info->channels;
  ogg_int64_t totalSamples = ov_pcm_total(&vf, -1);
  long totalBytes = totalSamples * bytesPerSample * numChannels;
  char* rawSamples = new char[totalBytes];
  char* samplePutPos = rawSamples;
  
//  std::cerr << "totalSamples: " << totalSamples << std::endl;
  
//  char pcmout[4096];
  int current_section;
  bool eof = false;
  while (!eof) {
    long ret = ov_read(&vf,
                       samplePutPos,
                       maxReadSize,
                       nativeEndianness,
                       bytesPerSample,
                       nativeSignedness,
                       &current_section);
    if (ret == 0) {
      eof = true;
    }
    else if (ret < 0) {
      // error
    }
    else {
      samplePutPos += ret;
    }
  }
  
  ov_clear(&vf);
  
  // RawSoundFile is responsible for this buffer, so we
  // don't delete it here
  return new RawSoundFile(rawSamples, // buffer
                          totalBytes, // buffer size
                          bytesPerSample, // bytes per sample
                          numChannels,  // number of channels
                          EndiannessTypes::little,  // endianness
                          SignednessTypes::sign,    // signedness
                          44100,      // sample rate
                          true,      // looping?
                          0,          // loop start
                          totalSamples); // loop end
  
  return 0;
}
  
SoundFile* vorbisfileVorbisSoundOpener::loadVorbis(
                                    ResourceFileHandle& fileHandle_) {
  // Ignore repeat typeID
  fileHandle_.readInt(ByteSizes::uint32Size,
                       EndiannessTypes::little,
                       SignednessTypes::nosign);
                       
  // Ignore chunk size
  fileHandle_.readInt(ByteSizes::uint32Size,
                       EndiannessTypes::little,
                       SignednessTypes::nosign);
                       
  // looping?
  bool looping = (bool)(fileHandle_.readInt(ByteSizes::uint32Size,
                                           EndiannessTypes::little,
                                           SignednessTypes::nosign));
                                           
  // loop start
  int loopStart = fileHandle_.readInt(ByteSizes::uint32Size,
                                      EndiannessTypes::little,
                                      SignednessTypes::nosign);
                                           
  // loop end
  int loopEnd = fileHandle_.readInt(ByteSizes::uint32Size,
                                    EndiannessTypes::little,
                                    SignednessTypes::nosign);
                       
  // Embedded file size
  int oggFileSize = fileHandle_.readInt(ByteSizes::uint32Size,
                                        EndiannessTypes::little,
                                        SignednessTypes::nosign);
                                        
//  std::cout << "looping: " << looping << std::endl;
//  std::cout << "loopStart: " << loopStart << std::endl;
//  std::cout << "loopEnd: " << loopEnd << std::endl;
//  std::cout << "oggFileSize: " << oggFileSize << std::endl;
                       
  OVHandleCallbacks callbacks(fileHandle_,
                              fileHandle_.tell(),
                              oggFileSize);
  
  OggVorbis_File vf;
  if (ov_open_callbacks((void*)(&callbacks),
                        &vf,
                        0,
                        0,
                        callbacks.callbacks())) {
    // file is not an Ogg bitstream
//    std::cerr << "BAD BAD BAD" << std::endl;
    return 0;
  }
//  std::cout << "ok" << std::endl;
  
  // Get number of samples and create buffer
  vorbis_info* info = ov_info(&vf, -1);
  int numChannels = info->channels;
  int frequency = info->rate;
  ogg_int64_t totalSamples = ov_pcm_total(&vf, -1);
  long totalBytes = totalSamples * bytesPerSample * numChannels;
  
  char* rawSamples = new char[totalBytes];
  char* samplePutPos = rawSamples;
  
//  std::cout << "totalSamples: " << totalSamples << std::endl;
  
//  char pcmout[4096];
  int current_section;
  bool eof = false;
  while (!eof) {
    long ret = ov_read(&vf,
                       samplePutPos,
                       maxReadSize,
                       nativeEndianness,
                       bytesPerSample,
                       nativeSignedness,
                       &current_section);
                       
//    std::cout << ret << std::endl;
    
    if (ret == 0) {
      eof = true;
    }
    else if (ret < 0) {
      // error
    }
    else {
      samplePutPos += ret;
    }
  }
  
  ov_clear(&vf);
  
  // RawSoundFile is responsible for this buffer, so we
  // don't delete it here
  return new RawSoundFile(rawSamples, // buffer
                          totalBytes, // buffer size
                          bytesPerSample, // bytes per sample
                          numChannels,  // number of channels
                          EndiannessTypes::little,  // endianness
                          SignednessTypes::sign,    // signedness
                          frequency,    // sample rate
                          looping,  // looping?
                          loopStart,// loop start
                          loopEnd); // loop end
}


}; 
