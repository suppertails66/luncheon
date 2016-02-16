#ifndef SIMPLEMESSAGEPRINTINGFUNCTOR_H
#define SIMPLEMESSAGEPRINTINGFUNCTOR_H


#include "logic/MessagePrintingFunctor.h"
#include "logic/SimpleMessageQueue.h"
#include <string>

namespace Luncheon {


class SimpleMessagePrintingFunctor
  : public MessagePrintingFunctor {
public:
  virtual ~SimpleMessagePrintingFunctor();
  
  SimpleMessagePrintingFunctor();
  
  virtual void operator()(GameMemory* gameMemory,
                          GameScene* parentScene,
                          MessagePrintingWindowArea* source,
                          GTick ticks);
                          
  virtual void queueMessage(const std::string& message);
protected:

  SimpleMessageQueue messageQueue_;
  
};


};


#endif 
