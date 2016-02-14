#include "animation/SerializableRawAnimationFrame.h"
#include "animation/SimpleAnimationFrame.h"
#include "graphics/GraphicsCore.h"
#include <iostream>

namespace Luncheon {


SerializableRawAnimationFrame::~SerializableRawAnimationFrame() {
  delete pixels_;
}
  
SerializableRawAnimationFrame::SerializableRawAnimationFrame()
  : SerializableAnimationFrame(),
    pixels_(0),
    pixelsSize_(0) { };
  
void SerializableRawAnimationFrame::read(std::istream& ifs) {
  readStandardBlocks(ifs);
  resizeImage(width_, height_);
  ifs.read(pixels_, imageDataSize_);
}

void SerializableRawAnimationFrame::write(std::ostream& ofs) {
  calculateAndSetSizeFields();
  writeStandardBlocks(ofs);
  ofs.write(pixels_, imageDataSize_);
}
  
void SerializableRawAnimationFrame::calculateAndSetSizeFields() {
  imageDataSize_ = pixelsSize_;
  totalSize_ = baseSize() + imageDataSize_;
}

void SerializableRawAnimationFrame::resizeImage(int w, int h) {
  width_ = w;
  height_ = h;
  
  delete pixels_;
  pixelsSize_ = w * h * ByteSizes::uint32Size;
  pixels_ = new char[pixelsSize_];
}
  
void SerializableRawAnimationFrame::clearImage(DrawColor color) {
//  char* rowPosition = pixels_;
  for (int i = 0; i < width_; i++) {
    for (int j = 0; j < height_; j++) {
      putPixel(DrawPosition(i, j),
               color);
//      char* pos = (rowPosition + (j * ByteSizes::uint32Size));
//      pos[0] = color.r();
//      pos[1] = color.g();
//      pos[2] = color.b();
//      pos[3] = color.a();
    }
//    rowPosition += (width_ * ByteSizes::uint32Size);
  }
}
  
DrawColor SerializableRawAnimationFrame::getPixel(DrawPosition pos) {
  char* getPos = pixels_;
  getPos += (pos.y() * width_ * ByteSizes::uint32Size);
  getPos += (pos.x() * ByteSizes::uint32Size);
  
  return DrawColor(getPos[1], getPos[2], getPos[3], getPos[0]);
}
  
void SerializableRawAnimationFrame::putPixel(DrawPosition pos,
                                             DrawColor color) {
  char* putPos = pixels_;
  putPos += (pos.y() * width_ * ByteSizes::uint32Size);
  putPos += (pos.x() * ByteSizes::uint32Size);
  
//  std::cout << "r: " << color.r() << std::endl;
//  std::cout << "g: " << color.g() << std::endl;
//  std::cout << "b: " << color.b() << std::endl;
//  std::cout << "a: " << color.a() << std::endl;
//  std::cout << std::endl;
  
  putPos[1] = color.r();
  putPos[2] = color.g();
  putPos[3] = color.b();
  putPos[0] = color.a();
  
}
  
char* SerializableRawAnimationFrame::pixels() {
  return pixels_;
}
                        
AnimationFrame* SerializableRawAnimationFrame::convertToAnimationFrame(
                        GraphicsCore& graphicsCore) {
  DrawableSurface* drawable = graphicsCore.createDrawableSurface(width_,
                                                                 height_);
  
  for (int j = 0; j < height_; j++) {
    for (int i = 0; i < width_; i++) {
      DrawPosition pos(i, j);
      drawable->draw(pos,
                     getPixel(pos),
                     1);
                     
    }
  }
                        
  GraphicSurface* newSurface = drawable->toGraphicSurface(graphicsCore);
    
  delete drawable;
                        
  SimpleAnimationFrame* newFrame = new SimpleAnimationFrame(newSurface,
                                                            duration_,
                                                            xOffset_,
                                                            yOffset_);
  
  return newFrame;
}


}; 
