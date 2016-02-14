#ifndef REVERSECOLORMAP_H
#define REVERSECOLORMAP_H


#include "graphics/DrawColor.h"
#include <unordered_map>
#include <functional>

namespace Luncheon {


// Custom hash function for DrawColors
template <class T>
class DrawColorIntCastHash {
public:
  std::size_t operator()(const T& obj) const {
    return static_cast<int>(obj);
  }
};

typedef std::unordered_map<DrawColor,
                           int,
                           DrawColorIntCastHash<DrawColor> > ReverseColorMap;
typedef std::pair<DrawColor, int> ReverseColorMapPair;


};


#endif 
