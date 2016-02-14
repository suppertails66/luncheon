#include "animation/SerializableAnimation.h"
#include "graphics/GraphicsCore.h"
#include "animation/SimpleAnimation.h"
#include <iostream>

namespace Luncheon {


SerializableAnimation::~SerializableAnimation() {
  for (SerializableAnimationFrameCollection::iterator it 
         = frames_.begin();
       it != frames_.end();
       it++) {
     delete *it;
  }
}

SerializableAnimation::SerializableAnimation()
  : typeID_(0),
    totalSize_(0),
    looping_(0),
    loopStart_(0),
    loopEnd_(0) { };
  
SerializableAnimationFrameCollection& SerializableAnimation::frames() {
  return frames_;
}
  
ResourceID SerializableAnimation::typeID() {
  return typeID_;
}

void SerializableAnimation::setTypeID(ResourceID typeID__) {
  typeID_ = typeID__;
}

int SerializableAnimation::totalSize() {
  return totalSize_;
}

void SerializableAnimation::setTotalSize(int totalSize__) {
  totalSize_ = totalSize__;
}

bool SerializableAnimation::looping() {
  return looping_;
}

void SerializableAnimation::setLooping(bool looping__) {
  looping_ = looping__;
}

int SerializableAnimation::loopStart() {
  return loopStart_;
}

void SerializableAnimation::setLoopStart(int loopStart__) {
  loopStart_ = loopStart__;
}

int SerializableAnimation::loopEnd() {
  return loopEnd_;
}

void SerializableAnimation::setLoopEnd(int loopEnd__) {
  loopEnd_ = loopEnd__;
}
  
int SerializableAnimation::baseSize() {
  int total = 0;
  
  // Not counted towards chunk size
//  total += ByteSizes::uint32Size; // typeID
//  total += ByteSizes::uint32Size; // totalSize
  
  total += ByteSizes::uint32Size; // looping
  total += ByteSizes::uint32Size; // loopStart
  total += ByteSizes::uint32Size; // loopEnd
  total += ByteSizes::uint32Size; // numFrames
  total += ByteSizes::uint32Size; // frameDataSize
  
  return total;
}
  
int SerializableAnimation::numFrames() {
  return frames_.size();
}

int SerializableAnimation::calculateFrameDataSize() {
  int total = 0;
  for (SerializableAnimationFrameCollection::iterator it
         = frames_.begin();
       it != frames_.end();
       it++) {
      (*it)->calculateAndSetSizeFields();
      total += (*it)->totalSize();
      // must account for header size, which is not included
      // in frame's reported total size
      total += ByteSizes::uint32Size * 3;
  }
  return total;
}
  
void SerializableAnimation::calculateAndUpdateSizeFields() {
  totalSize_ = baseSize() + calculateFrameDataSize();
}
  
void SerializableAnimation::addFrame(SerializableAnimationFrame* frame) {
  frames_.insert(frames_.end(), frame);
}
  
SerializableAnimationFrame& SerializableAnimation::frame(int pos) {
  if ((unsigned int)pos > frames_.size()) {
    // no
  }
  
  SerializableAnimationFrameCollection::iterator it 
         = frames_.begin();
  for (int i = 0; i < pos; i++) {
    ++it;
  }
  return *(*it);
}
  
void SerializableAnimation::read(std::istream& ifs) {
  
  // Header
  
  // TypeID
  ifs.read(byteBuffer, ByteSizes::uint32Size);
  typeID_ = ByteConversion::fromBytes(byteBuffer,
                                        ByteSizes::uint32Size,
                                        EndiannessTypes::little,
                                        SignednessTypes::nosign);
  
  // Total chunk size
  ifs.read(byteBuffer, ByteSizes::uint32Size);
  totalSize_ = ByteConversion::fromBytes(byteBuffer,
                                        ByteSizes::uint32Size,
                                        EndiannessTypes::little,
                                        SignednessTypes::nosign);
  // Looping
  ifs.read(byteBuffer, ByteSizes::uint32Size);
  looping_ = static_cast<bool>(ByteConversion::fromBytes(byteBuffer,
                                        ByteSizes::uint32Size,
                                        EndiannessTypes::little,
                                        SignednessTypes::nosign));
  
  // loopStart
  ifs.read(byteBuffer, ByteSizes::uint32Size);
  loopStart_ = ByteConversion::fromBytes(byteBuffer,
                                        ByteSizes::uint32Size,
                                        EndiannessTypes::little,
                                        SignednessTypes::nosign);
  
  // loopEnd
  ifs.read(byteBuffer, ByteSizes::uint32Size);
  loopEnd_ = ByteConversion::fromBytes(byteBuffer,
                                        ByteSizes::uint32Size,
                                        EndiannessTypes::little,
                                        SignednessTypes::nosign);
                                        
  int numFramesF;
  ifs.read(byteBuffer, ByteSizes::uint32Size);
  numFramesF = ByteConversion::fromBytes(byteBuffer,
                                        ByteSizes::uint32Size,
                                        EndiannessTypes::little,
                                        SignednessTypes::nosign);
                                        
//  int frameDataSize;
  ifs.read(byteBuffer, ByteSizes::uint32Size);
  /*frameDataSize = */ByteConversion::fromBytes(byteBuffer,
                                        ByteSizes::uint32Size,
                                        EndiannessTypes::little,
                                        SignednessTypes::nosign);
                                        
  for (int i = 0; i < numFramesF; i++) {
  
    switch (static_cast<AnimationTypeIDs::AnimationTypeID>(typeID_)) {
    case AnimationTypeIDs::raw:
    {
      SerializableRawAnimationFrame* newFrame
        = new SerializableRawAnimationFrame();
      newFrame->read(ifs);
      addFrame(newFrame);
    }
      break;
    case AnimationTypeIDs::rle:
    {
      SerializableRawAnimationFrame* newFrame
        = new SerializableRLE8AnimationFrame();
      newFrame->read(ifs);
      addFrame(newFrame);
    }
      break;
    default:
    
      break;
    }
    
  }
}

void SerializableAnimation::write(std::ostream& ofs) {
  ByteConversion::toBytes(typeID_,
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
  
  ByteConversion::toBytes(static_cast<int>(looping_),
                          byteBuffer,
                          ByteSizes::uint32Size,
                          EndiannessTypes::little,
                          SignednessTypes::nosign);
  ofs.write(byteBuffer, ByteSizes::uint32Size);
  
  ByteConversion::toBytes(loopStart_,
                          byteBuffer,
                          ByteSizes::uint32Size,
                          EndiannessTypes::little,
                          SignednessTypes::nosign);
  ofs.write(byteBuffer, ByteSizes::uint32Size);
  
  ByteConversion::toBytes(loopEnd_,
                          byteBuffer,
                          ByteSizes::uint32Size,
                          EndiannessTypes::little,
                          SignednessTypes::nosign);
  ofs.write(byteBuffer, ByteSizes::uint32Size);
  
  ByteConversion::toBytes(numFrames(),
                          byteBuffer,
                          ByteSizes::uint32Size,
                          EndiannessTypes::little,
                          SignednessTypes::nosign);
  ofs.write(byteBuffer, ByteSizes::uint32Size);
  
  ByteConversion::toBytes(calculateFrameDataSize(),
                          byteBuffer,
                          ByteSizes::uint32Size,
                          EndiannessTypes::little,
                          SignednessTypes::nosign);
  ofs.write(byteBuffer, ByteSizes::uint32Size);
                                  
  for (SerializableAnimationFrameCollection::iterator it
        = frames_.begin();
       it != frames_.end();
       it++) {
      (*it)->write(ofs);
  }
}
  
Animation* SerializableAnimation::convertToAnimation(
                  GraphicsCore& graphicsCore) {
                  
  Animation* animation = new SimpleAnimation();
  
  animation->setLooping(looping_);
  animation->setLoopStart(loopStart_);
  animation->setLoopEnd(loopEnd_);
  
  for (SerializableAnimationFrameCollection::iterator it
          = frames_.begin();
       it != frames_.end();
       it++) {
    animation->addFrame((*it)->convertToAnimationFrame(graphicsCore));
  }
  
  return animation;
}


}; 
