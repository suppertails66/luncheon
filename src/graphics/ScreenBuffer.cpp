#include "graphics/ScreenBuffer.h"

namespace Luncheon {


ScreenBuffer::~ScreenBuffer() { };
  
void ScreenBuffer::lock() {
  locked_ = true;
}

void ScreenBuffer::unlock() {
  locked_ = false;
}

bool ScreenBuffer::locked() const {
  return locked_;
}

ScreenBuffer::ScreenBuffer()
  : locked_(false) { };


};
