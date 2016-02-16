#include "animation/SerializableRLE8AnimationFrame.h"
#include <iostream>

namespace Luncheon {


SerializableRLE8AnimationFrame::~SerializableRLE8AnimationFrame() {
  delete simplifiedColorData_;
  delete loadedCompressedData_;
}

SerializableRLE8AnimationFrame::SerializableRLE8AnimationFrame()
  : SerializableRawAnimationFrame(),
    simplifiedColorData_(0),
    simplifiedColorDataSize_(0),
    loadedCompressedData_(0),
    loadedCompressedDataSize_(0) { };

void SerializableRLE8AnimationFrame::calculateAndSetSizeFields() {
  // imageDataSize_ = colormap size + compressed data size
  int colorMapSize = (1 * ByteSizes::uint32Size)  // number of color entries
                     + (internalColorMap.size() * ByteSizes::uint32Size); // colors
  imageDataSize_ = colorMapSize + loadedCompressedDataSize_;
    
  totalSize_ = baseSize() + imageDataSize_;
  
}
  
void SerializableRLE8AnimationFrame::read(std::istream& ifs) {
  readStandardBlocks(ifs);
  resizeImage(width_, height_);
//  ifs.read(pixels_, imageDataSize_);

  int imageChunkRemaining = imageDataSize_;

  // read color map
  ifs.read(byteBuffer, ByteSizes::uint32Size);
  int numColors = ByteConversion::fromBytes(byteBuffer,
                                        ByteSizes::uint32Size,
                                        EndiannessTypes::little,
                                        SignednessTypes::nosign);
  imageChunkRemaining -= ByteSizes::uint32Size;
                                        
  for (int i = 0; i < numColors; i++) {
    ifs.read(byteBuffer, ByteSizes::uint32Size);
    int color = ByteConversion::fromBytes(byteBuffer,
                                          ByteSizes::uint32Size,
                                          EndiannessTypes::big,
                                          SignednessTypes::nosign);
    imageChunkRemaining -= ByteSizes::uint32Size;

/*    DrawColor test(color);
    std::cout << std::hex << color << std::endl;
    std::cout << test.a() << std::endl;
    std::cout << test.r() << std::endl;
    std::cout << test.g() << std::endl;
    std::cout << test.b() << std::endl; */
                                        
    externalColorMap.push_back(DrawColor(color));
  }
  
  // read compressed pixel data
  delete loadedCompressedData_;
  loadedCompressedDataSize_ = imageChunkRemaining;
  loadedCompressedData_ = new char[loadedCompressedDataSize_];
  ifs.read(loadedCompressedData_, loadedCompressedDataSize_);
  
  // decompress pixel data
  decompressPixels();
}

void SerializableRLE8AnimationFrame::write(std::ostream& ofs) {
//  compressPixels();

  calculateAndSetSizeFields();
  writeStandardBlocks(ofs);

  // Write number of colors in map
  ByteConversion::toBytes(internalColorMap.size(),
                          byteBuffer,
                          ByteSizes::uint32Size,
                          EndiannessTypes::little,
                          SignednessTypes::nosign);
  ofs.write(byteBuffer, ByteSizes::uint32Size);
  
  // Write colormap
/*  for (ReverseColorMap::iterator it = internalColorMap.begin();
       it != internalColorMap.end();
       it++) {
//    std::cout << std::hex << static_cast<int>(it->second) << std::endl;
    ByteConversion::toBytes(static_cast<int>(it->first),
                            byteBuffer,
                            ByteSizes::uint32Size,
                            EndiannessTypes::big,
                            SignednessTypes::nosign);
    ofs.write(byteBuffer, ByteSizes::uint32Size);
  } */
  // whoops, fucked myself over by using a map here!
  for (int i = 0; i < internalColorMap.size(); i++) {
    for (ReverseColorMap::iterator it = internalColorMap.begin();
         it != internalColorMap.end();
         it++) {
      if (it->second == i) {
//        byteBuffer[0] = 0;
//        byteBuffer[1] = 0;
//        byteBuffer[2] = 0;
//        byteBuffer[3] = 0;
//        std::cout << std::hex << static_cast<int>(it->first) << std::endl;
        ByteConversion::toBytes(static_cast<int>(it->first),
                            byteBuffer,
                            ByteSizes::uint32Size,
                            EndiannessTypes::big,
                            SignednessTypes::nosign);
        ofs.write(byteBuffer, ByteSizes::uint32Size);
        break;
      }
    }
  }
  
  // Write image data
  ofs.write(loadedCompressedData_,
            loadedCompressedDataSize_);
}
  
void SerializableRLE8AnimationFrame::simplifyColors() {
  // Delete existing data
  delete simplifiedColorData_;
  simplifiedColorDataSize_ = width_ * height_;
  simplifiedColorData_ = new char[simplifiedColorDataSize_];
  internalColorMap.clear();
  
  int colorNum = 0;
  int pos = 0;
  for (int j = 0; j < height_; j++) {
    for (int i = 0; i < width_; i++) {
      DrawColor pixel = getPixel(DrawPosition(i, j));
      
      // Check if this color is in the map
      ReverseColorMap::iterator colorCheck
        = internalColorMap.find(pixel);
      
      // Add color to map if it's not already there
      if (colorCheck == internalColorMap.end()) {
        internalColorMap.insert(
          ReverseColorMapPair(pixel, colorNum));
//        std::cout << "a: " << pixel.a() << std::endl;
//        std::cout << "r: " << pixel.r() << std::endl;
//        std::cout << "g: " << pixel.g() << std::endl;
//        std::cout << "b: " << pixel.b() << std::endl;
//        std::cout << std::endl;
        ++colorNum;
      }
      
      // Add compressed pixel
      simplifiedColorData_[pos]
        = static_cast<char>(internalColorMap.find(pixel)->second);
      ++pos;
    }
  }
}

void SerializableRLE8AnimationFrame::compressPixels() {
  // Reduce to 256 colors
  simplifyColors();

  // Create compression command list
  RLE8Compressor::compress(simplifiedColorData_,
                          simplifiedColorDataSize_,
                          compressionCommands);
                          
  // Clear existing compressed data
  delete loadedCompressedData_;
  loadedCompressedDataSize_
    = RLE8Compressor::calculateCompressedByteSize(compressionCommands);
  loadedCompressedData_ = new char[loadedCompressedDataSize_];
  
  // Create compressed bytecode
  RLE8Compressor::compressToBytes(compressionCommands,
                                  loadedCompressedData_,
                                  loadedCompressedDataSize_);
}
  
void SerializableRLE8AnimationFrame::decompressPixels() {
  // Decompress the 256-color data
  delete simplifiedColorData_;
  simplifiedColorDataSize_ = width_ * height_;
  simplifiedColorData_ = new char[simplifiedColorDataSize_];
  RLE8Compressor::decompressToBytes(loadedCompressedData_,
                                    loadedCompressedDataSize_,
                                    simplifiedColorData_,
                                    simplifiedColorDataSize_);
  
  // Use the color map to generate the full-color graphic
  for (int i = 0; i < simplifiedColorDataSize_; i++) {
    ByteConversion::toBytes(externalColorMap[simplifiedColorData_[i]],
                            pixels_ + (i * ByteSizes::uint32Size),
                            ByteSizes::uint32Size,
                            EndiannessTypes::big,
                            SignednessTypes::nosign);
  }
}


}; 
