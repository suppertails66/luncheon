#ifndef SIMPLEMESSAGEPRINTINGWINDOWAREA_H
#define SIMPLEMESSAGEPRINTINGWINDOWAREA_H


#include "logic/MessagePrintingWindowArea.h"
#include <string>

namespace Luncheon {


class SimpleMessagePrintingWindowArea
  : public MessagePrintingWindowArea {
public:
  virtual ~SimpleMessagePrintingWindowArea();
  
  SimpleMessagePrintingWindowArea(
             GameMemory& gameMemory__,
             GameScene& parent__,
             Window* parentWindow__,
             MessagePrintingFunctor* callback__,
             const std::string& font__,
             int fontSize__,
             int paddingLeft__ = 0,
             int paddingTop__ = 0);
  
  virtual void updateMessage(GTick ticks);
             
  virtual std::string& printString();
  virtual void setPrintString(const std::string& printString__);
  
  virtual double ticksPerCharacter();
  virtual void setTicksPerCharacter(double ticksPerCharacter__);
  
  virtual int printingPosition();
  virtual void setPrintingPosition(int printingPosition__);
  
  virtual void emptyMessageAction();
  
  virtual void continueConditionAction();
  
  virtual bool continueConditionMet() =0;
protected:

  bool printStringInitialized_;

  std::string printString_;
  
  double ticksPerCharacter_;
  
  int printingPosition_;
  
  bool needsReset_;
  
  GTick printingTickCounter_;
  
  virtual void writeNextCharacter();
  
};


};


#endif 
