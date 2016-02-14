#include "graphics/DrawColor.h"
#include <iostream>
 
namespace Luncheon {
 
 
DrawColor::~DrawColor() { };
  
DrawColor::DrawColor(int colorComponents)
  : r_((colorComponents >> 16) & 0xFF),
    g_((colorComponents >> 8) & 0xFF),
    b_((colorComponents) & 0xFF),
    a_((colorComponents >> 24) & 0xFF) { };

DrawColor::DrawColor()
  : r_(0), g_(0), b_(0), a_(0) { };
  
DrawColor::DrawColor(int r__, int g__, int b__)
  : r_(r__), g_(g__), b_(b__), a_(fullAlphaOpacity_) { };
  
DrawColor::DrawColor(int r__, int g__, int b__, int a__)
  : r_(r__), g_(g__), b_(b__), a_(a__) { };
  
DrawColor::operator int() const {

/*  std::cout << "a: " << a_ << std::endl;
  std::cout << "r: " << r_ << std::endl;
  std::cout << "g: " << g_ << std::endl;
  std::cout << "b: " << b_ << std::endl;
  std::cout << std::endl; */
  
  int result = 0;
  result |= ((a_ & 0xFF) << 24);
  result |= ((r_ & 0xFF) << 16);
  result |= ((g_ & 0xFF) << 8);
  result |= ((b_ & 0xFF));

  return result;
}
  
int DrawColor::fullAlphaOpacity() {
  return fullAlphaOpacity_;
}

int DrawColor::maxExpression() {
  return maxExpression_;
}

int DrawColor::r() const {
  return r_;
}
void DrawColor::setR(int r__) {
  r_ = r__;
}

int DrawColor::g() const {
  return g_;
}
void DrawColor::setG(int g__) {
  g_ = g__;
}

int DrawColor::b() const {
  return b_;
}
void DrawColor::setB(int b__) {
  b_ = b__;
}

int DrawColor::a() const {
  return a_;
}
void DrawColor::setA(int a__) {
  a_ = a__;
}
  
bool DrawColor::operator==(const DrawColor& color) {
  if (r_ != color.r_) {
    return false;
  }
  if (g_ != color.g_) {
    return false;
  }
  if (b_ != color.b_) {
    return false;
  }
  if (a_ != color.a_) {
    return false;
  }
  return true;
}

bool DrawColor::operator!=(const DrawColor& color) {
  return !(*this == color);
}


};
