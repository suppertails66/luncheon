#ifndef GAMEOBJECTCOLLECTIONMAP_H
#define GAMEOBJECTCOLLECTIONMAP_H


#include <unordered_map>
#include "logic/GameObjectID.h"
#include "logic/GameObjectCollection.h"

namespace Luncheon {


typedef std::unordered_map<GameObjectID, GameObjectCollection>
  GameObjectCollectionMap;
typedef std::pair<GameObjectID, GameObjectCollection>
  GameObjectCollectionMapPair;


};


#endif 
