#include "animation/SerializableAnimationFrame.h"
#include "graphics/GraphicsCore.h"

namespace Luncheon {


SerializableAnimationFrame::~SerializableAnimationFrame() { };

SerializableAnimationFrame::SerializableAnimationFrame()
  : animationTypeID_(0),
    totalSize_(0),
    width_(0),
    height_(0),
    xOffset_(0),
    yOffset_(0),
    imageDataFormat_(0),
    imageDataSize_(0) { };
  
ResourceID SerializableAnimationFrame::animationTypeID() {
  return animationTypeID_;
}

void SerializableAnimationFrame::setAnimationTypeID(
          ResourceID animationTypeID__) {
  animationTypeID_ = animationTypeID__;
}
    
int SerializableAnimationFrame::totalSize() {
  return totalSize_;
}

void SerializableAnimationFrame::setTotalSize(int totalSize__) {
  totalSize_ = totalSize__;
}

int SerializableAnimationFrame::width() {
  return width_;
}
void SerializableAnimationFrame::setWidth(int width__) {
  width_ = width__;
}

int SerializableAnimationFrame::height() {
  return height_;
}
void SerializableAnimationFrame::setHeight(int height__) {
  height_ = height__;
}

int SerializableAnimationFrame::xOffset() {
  return xOffset_;
}

void SerializableAnimationFrame::setXOffset(int xOffset__) {
  xOffset_ = xOffset__;
}

int SerializableAnimationFrame::yOffset() {
  return yOffset_;
}

void SerializableAnimationFrame::setYOffset(int yOffset__) {
  yOffset_ = yOffset__;
}

int SerializableAnimationFrame::duration() {
  return duration_;
}

void SerializableAnimationFrame::setDuration(int duration__) {
  duration_ = duration__;
}

ResourceID SerializableAnimationFrame::imageDataFormat() {
  return imageDataFormat_;
}

void SerializableAnimationFrame::setImageDataFormat(ResourceID imageDataFormat__) {
  imageDataFormat_ = imageDataFormat__;
}

int SerializableAnimationFrame::imageDataSize() {
  return imageDataSize_;
}

void SerializableAnimationFrame::setImageDataSize(int imageDataSize__) {
  imageDataSize_ = imageDataSize__;
}
  
void SerializableAnimationFrame::read(std::istream& ifs) {
  readStandardBlocks(ifs);
}
  
void SerializableAnimationFrame::write(std::ostream& ofs) {
  // no image data or format
  totalSize_ = baseSize();
  imageDataSize_ = 0;
  
  writeStandardBlocks(ofs);
}

int SerializableAnimationFrame::baseSize() {
  int total = 0;
  
  // Not included in total count
//  total += ByteSizes::uint32Size; // typeID
//  total += ByteSizes::uint32Size; // chunk size

  total += ByteSizes::uint32Size; // width
  total += ByteSizes::uint32Size; // height
  total += ByteSizes::uint32Size; // x offset
  total += ByteSizes::uint32Size; // y offset
  total += ByteSizes::uint32Size; // duration
  total += ByteSizes::uint32Size; // image format
  total += ByteSizes::uint32Size; // image size
  
  return total;
}
  
void SerializableAnimationFrame::readStandardBlocks(std::istream& ifs) {
  
  // Header
  
  // TypeID
  ifs.read(byteBuffer, ByteSizes::uint32Size);
  animationTypeID_ = ByteConversion::fromBytes(byteBuffer,
                                        ByteSizes::uint32Size,
                                        EndiannessTypes::little,
                                        SignednessTypes::nosign);
  
  // Total chunk size
  ifs.read(byteBuffer, ByteSizes::uint32Size);
  totalSize_ = ByteConversion::fromBytes(byteBuffer,
                                        ByteSizes::uint32Size,
                                        EndiannessTypes::little,
                                        SignednessTypes::nosign);
  
  // Width
  ifs.read(byteBuffer, ByteSizes::uint32Size);
  width_ = ByteConversion::fromBytes(byteBuffer,
                                        ByteSizes::uint32Size,
                                        EndiannessTypes::little,
                                        SignednessTypes::nosign);
  
  // Height
  ifs.read(byteBuffer, ByteSizes::uint32Size);
  height_ = ByteConversion::fromBytes(byteBuffer,
                                        ByteSizes::uint32Size,
                                        EndiannessTypes::little,
                                        SignednessTypes::nosign);
  
  // xOffset
  ifs.read(byteBuffer, ByteSizes::uint32Size);
  xOffset_ = ByteConversion::fromBytes(byteBuffer,
                                        ByteSizes::uint32Size,
                                        EndiannessTypes::little,
                                        SignednessTypes::sign);
  
  // yOffset
  ifs.read(byteBuffer, ByteSizes::uint32Size);
  yOffset_ = ByteConversion::fromBytes(byteBuffer,
                                        ByteSizes::uint32Size,
                                        EndiannessTypes::little,
                                        SignednessTypes::sign);
  
  // Duration
  ifs.read(byteBuffer, ByteSizes::uint32Size);
  duration_ = ByteConversion::fromBytes(byteBuffer,
                                        ByteSizes::uint32Size,
                                        EndiannessTypes::little,
                                        SignednessTypes::nosign);
  
  // Image format
  ifs.read(byteBuffer, ByteSizes::uint32Size);
  imageDataFormat_ = ByteConversion::fromBytes(byteBuffer,
                                        ByteSizes::uint32Size,
                                        EndiannessTypes::little,
                                        SignednessTypes::nosign);
  
  // Image size
  ifs.read(byteBuffer, ByteSizes::uint32Size);
  imageDataSize_ = ByteConversion::fromBytes(byteBuffer,
                                        ByteSizes::uint32Size,
                                        EndiannessTypes::little,
                                        SignednessTypes::nosign);
}
  
void SerializableAnimationFrame::writeStandardBlocks(std::ostream& ofs) {
  ByteConversion::toBytes(animationTypeID_,
                          byteBuffer,
                          ByteSizes::uint32Size,
                          EndiannessTypes::little,
                          SignednessTypes::nosign);
  ofs.write(byteBuffer, ByteSizes::uint32Size);
  
  ByteConversion::toBytes(totalSize_,
                          byteBuffer,
                          ByteSizes::uint32Size,
                          EndiannessTypes::little,
                          SignednessTypes::nosign);
  ofs.write(byteBuffer, ByteSizes::uint32Size);
  
  ByteConversion::toBytes(width_,
                          byteBuffer,
                          ByteSizes::uint32Size,
                          EndiannessTypes::little,
                          SignednessTypes::nosign);
  ofs.write(byteBuffer, ByteSizes::uint32Size);
  
  ByteConversion::toBytes(height_,
                          byteBuffer,
                          ByteSizes::uint32Size,
                          EndiannessTypes::little,
                          SignednessTypes::nosign);
  ofs.write(byteBuffer, ByteSizes::uint32Size);
  
  ByteConversion::toBytes(xOffset_,
                          byteBuffer,
                          ByteSizes::uint32Size,
                          EndiannessTypes::little,
                          SignednessTypes::sign);
  ofs.write(byteBuffer, ByteSizes::uint32Size);
  
  ByteConversion::toBytes(yOffset_,
                          byteBuffer,
                          ByteSizes::uint32Size,
                          EndiannessTypes::little,
                          SignednessTypes::sign);
  ofs.write(byteBuffer, ByteSizes::uint32Size);
  
  ByteConversion::toBytes(duration_,
                          byteBuffer,
                          ByteSizes::uint32Size,
                          EndiannessTypes::little,
                          SignednessTypes::nosign);
  ofs.write(byteBuffer, ByteSizes::uint32Size);
  
  ByteConversion::toBytes(imageDataFormat_,
                          byteBuffer,
                          ByteSizes::uint32Size,
                          EndiannessTypes::little,
                          SignednessTypes::nosign);
  ofs.write(byteBuffer, ByteSizes::uint32Size);
  
  ByteConversion::toBytes(imageDataSize_,
                          byteBuffer,
                          ByteSizes::uint32Size,
                          EndiannessTypes::little,
                          SignednessTypes::nosign);
  ofs.write(byteBuffer, ByteSizes::uint32Size);
}


}; 
