#include "graphics/GraphicSurface.h"

namespace Luncheon {


GraphicSurface::~GraphicSurface() { };

GraphicSurface::GraphicSurface()
  : locked_(false) { };
  
void GraphicSurface::lock() {
  locked_ = true;
}

void GraphicSurface::unlock() {
  locked_ = false;
}

bool GraphicSurface::locked() const {
  return locked_;
}


};
