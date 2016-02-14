#include "logic/GameObjectManager.h"
#include "logic/GameObject.h"

namespace Luncheon {


GameObjectManager::~GameObjectManager() {
  // Delete all objects
  for (GameObjectCollectionMap::iterator it = objects_.begin();
       it != objects_.end();
       it++) {
    for (GameObjectCollection::iterator targetListIterator 
           = it->second.begin();
         targetListIterator != it->second.end();
         targetListIterator++) {
      delete (*targetListIterator);
    }
  }
}

GameObjectManager::GameObjectManager() { };
  
void GameObjectManager::update(GTick ticks) {
  // Update all objects
  for (GameObjectCollectionMap::iterator it = objects_.begin();
       it != objects_.end();
       it++) {
    for (GameObjectCollection::iterator targetListIterator 
           = it->second.begin();
         targetListIterator != it->second.end();
         targetListIterator++) {
      (*targetListIterator)->update(ticks);
    }
  }
  
  // Check for dead objects to be pruned
  for (GameObjectCollectionMap::iterator it = objects_.begin();
       it != objects_.end();
       it++) {
       
    GameObjectCollection::iterator targetListIterator 
           = it->second.begin();
           
    while (targetListIterator != it->second.end()) {
    
      if ((*targetListIterator)->dead()) {
        GameObjectCollection::iterator pos = targetListIterator;
        ++targetListIterator;
        delete (*pos);
        it->second.erase(pos);
      }
      else {
        ++targetListIterator;
      }
    }
  }
}
  
void GameObjectManager::addObject(GameObject* object) {
  GameObjectCollectionMap::iterator target
    = findOrCreate(object->objectID());
  target->second.push_back(object);
}
  
GameObjectCollection& GameObjectManager::getObjectsOfType(
    GameObjectID objectID) {
  return findOrCreate(objectID)->second;
}
  
GameObjectCollectionMap::iterator GameObjectManager::findOrCreate(
                                    GameObjectID objectID) {
  GameObjectCollectionMap::iterator target
    = objects_.find(objectID);
  
  if (target == objects_.end()) {
    // Insert a new list corresponding to the requested type
    // (since we'll probably have to find it again later anyway)
    objects_.insert(GameObjectCollectionMapPair(objectID,
                                                GameObjectCollection()));
    return objects_.find(objectID);
  }
  
  return target;
}


}; 
