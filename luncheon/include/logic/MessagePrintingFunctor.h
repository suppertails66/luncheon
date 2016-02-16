#ifndef MESSAGEPRINTINGFUNCTOR_H
#define MESSAGEPRINTINGFUNCTOR_H


#include "logic/GameMemory.h"
#include "logic/GameScene.h"
#include "timing/GTick.h"

namespace Luncheon {


class MessagePrintingWindowArea;

class MessagePrintingFunctor {
public:
  virtual ~MessagePrintingFunctor();
  
  MessagePrintingFunctor();
  
  virtual void operator()(GameMemory* gameMemory,
                          GameScene* parentScene,
                          MessagePrintingWindowArea* source,
                          GTick ticks) =0;
protected:
};


};


#endif
