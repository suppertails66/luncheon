#ifndef LISTMENUITEMFUNCTOR_H
#define LISTMENUITEMFUNCTOR_H


#include "logic/ListMenuItemEventType.h"

namespace Luncheon {


class ListMenuWindowArea;
class GameMemory;
class GameScene;

class ListMenuItemFunctor {
public:
  virtual ~ListMenuItemFunctor();
  
  virtual void operator()(GameMemory* gameMemory,
                          GameScene* parentScene,
                          ListMenuWindowArea* source,
                          ListMenuItemEventTypes
                            ::ListMenuItemEventType eventType,
                          int optionNum,
                          int optionID) =0;
protected:
  ListMenuItemFunctor();
};


};


#endif 
