#ifndef GAMEOBJECTMANAGER_H
#define GAMEOBJECTMANAGER_H


#include "logic/GameObjectCollectionMap.h"
#include "timing/GTick.h"

namespace Luncheon {


class GameObject;

class GameObjectManager {
public:
  virtual ~GameObjectManager();
  
  GameObjectManager();
  
  virtual void update(GTick ticks);
  
  virtual void addObject(GameObject* object);
  
  virtual GameObjectCollection& getObjectsOfType(GameObjectID objectID);
protected:
  
  GameObjectCollectionMap objects_;
  
  GameObjectCollectionMap::iterator findOrCreate(GameObjectID objectID);
};


};


#endif 
