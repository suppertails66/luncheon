#include "font/WritePosition.h"

namespace Luncheon {


WritePosition::~WritePosition() { };
  
WritePosition::WritePosition()
  : x_(0),
    y_(0),
    baseX_(0),
    baseY_(0) { };
  
WritePosition::WritePosition(int x__,
                             int y__)
  : x_(x__),
    y_(y__),
    baseX_(x__),
    baseY_(y__) { };
  
WritePosition::WritePosition(int x__,
                             int y__,
                             int baseX__,
                             int baseY__)
  : x_(x__),
    y_(y__),
    baseX_(baseX__),
    baseY_(baseY__) { };
                
int WritePosition::x() {
  return x_;
}

void WritePosition::setX(int x__) {
  x_ = x__;
}
  
int WritePosition::y() {
  return y_;
}

void WritePosition::setY(int y__) {
  y_ = y__;
}
  
int WritePosition::baseX() {
  return baseX_;
}

void WritePosition::setBaseX(int baseX__) {
  baseX_ = baseX__;
}

int WritePosition::baseY() {
  return baseY_;
}

void WritePosition::setBaseY(int baseY__) {
  baseY_ = baseY__;
}


}; 
