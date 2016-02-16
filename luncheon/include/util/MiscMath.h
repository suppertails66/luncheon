#ifndef MISCMATH_H
#define MISCMATH_H


namespace Luncheon {


class MiscMath {
public:
  template<class T>
  static void clamp(T& value, T lower, T upper) {
    if (value < lower) {
      value = lower;
    }
    else if (value > upper) {
      value = upper;
    }
  }
protected:
  
};


};


#endif 
