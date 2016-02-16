#include "graphics/DrawPosition.h"

namespace Luncheon {


DrawPosition::~DrawPosition() { };

int DrawPosition::x() const {
  return x_;
}
void DrawPosition::setX(int x__) {
  x_ = x__;
}

int DrawPosition::y() const {
  return y_;
}
void DrawPosition::setY(int y__) {
  y_ = y__;
}

DrawPosition::DrawPosition()
  : x_(0), y_(0) { };

DrawPosition::DrawPosition(int x__, int y__)
  : x_(x__), y_(y__) { };


};
