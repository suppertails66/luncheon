#ifndef ANIMATIONPLAYERMAP_H
#define ANIMATIONPLAYERMAP_H


#include <unordered_map>
#include "animation/AnimationPlayer.h"

namespace Luncheon {


typedef std::unordered_map<int, AnimationPlayer*>
  AnimationPlayerMap;
typedef std::pair<int, AnimationPlayer*>
  AnimationPlayerMapPair;


};


#endif 
