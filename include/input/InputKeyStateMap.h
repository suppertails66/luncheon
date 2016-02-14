#ifndef INPUTKEYSTATEMAP_H
#define INPUTKEYSTATEMAP_H


#include <unordered_map>
#include "input/InputKey.h"
#include "input/InputKeyState.h"

namespace Luncheon {



// Custom hash function for DrawColors
template <class T>
class InputKeyIntCastHash {
public:
  std::size_t operator()(const T& obj) const {
    return static_cast<int>(obj);
  }
};

typedef std::unordered_map<InputKeys::InputKey,
                           InputKeyState,
                           InputKeyIntCastHash<InputKeys::InputKey> >
  InputKeyStateMap;
typedef std::pair<InputKeys::InputKey, InputKeyState>
  InputKeyStateMapPair;


};


#endif 
