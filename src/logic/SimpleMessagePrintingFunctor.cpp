#include "logic/SimpleMessagePrintingFunctor.h"
#include "logic/SimpleMessagePrintingWindowArea.h"

namespace Luncheon {


SimpleMessagePrintingFunctor::~SimpleMessagePrintingFunctor() { };

SimpleMessagePrintingFunctor::SimpleMessagePrintingFunctor()
  : MessagePrintingFunctor() { };

void SimpleMessagePrintingFunctor::operator()(
                GameMemory* gameMemory,
                GameScene* parentScene,
                MessagePrintingWindowArea* source,
                GTick ticks) {
                
  if (!messageQueue_.empty()) {
    // Put next message into printer if it exists
    SimpleMessagePrintingWindowArea* nativeSource
      = dynamic_cast<SimpleMessagePrintingWindowArea*>(source);
    nativeSource->setPrintString(messageQueue_.front());
    messageQueue_.pop();
    
    nativeSource->setPrintingPosition(0);
  }
  else {
    // Do nothing
  }
}
                          
void SimpleMessagePrintingFunctor::queueMessage(
  const std::string& message) {
  messageQueue_.push(message);
}


};
