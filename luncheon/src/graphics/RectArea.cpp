#include "graphics/RectArea.h"

namespace Luncheon {


RectArea::~RectArea() { };
  
RectArea::RectArea()
  : x_(0),
    y_(0),
    w_(0),
    h_(0) { };
  
RectArea::RectArea(int x__,
                   int y__,
                   int w__,
                   int h__)
  : x_(x__),
    y_(y__),
    w_(w__),
    h_(h__) { };

int RectArea::x() {
  return x_;
}

void RectArea::setX(int x__) {
  x_ = x__;
}
         
int RectArea::y() {
  return y_;
}

void RectArea::setY(int y__) {
  y_ = y__;
}
         
int RectArea::w() {
  return w_;
}

void RectArea::setW(int w__) {
  w_ = w__;
}
         
int RectArea::h() {
  return h_;
}

void RectArea::setH(int h__) {
  h_ = h__;
}


}; 
