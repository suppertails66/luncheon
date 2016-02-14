#include "logic/SimpleMessagePrintingWindowArea.h"
#include "logic/Window.h"
#include <iostream>

namespace Luncheon {


SimpleMessagePrintingWindowArea::~SimpleMessagePrintingWindowArea() { };
  
SimpleMessagePrintingWindowArea::SimpleMessagePrintingWindowArea(
             GameMemory& gameMemory__,
             GameScene& parent__,
             Window* parentWindow__,
             MessagePrintingFunctor* callback__,
             const std::string& font__,
             int fontSize__,
             int paddingLeft__,
             int paddingTop__)
  : MessagePrintingWindowArea(gameMemory__,
                              parent__,
                              parentWindow__,
                              callback__,
                              font__,
                              fontSize__,
                              paddingLeft__,
                              paddingTop__),
    printStringInitialized_(false),
    ticksPerCharacter_(32.0),
    printingPosition_(0),
    needsReset_(false),
    printingTickCounter_(0) { };

void SimpleMessagePrintingWindowArea::updateMessage(GTick ticks) {
  
  // On the initial call to this function, fill the print string
  // with text from the callback
  if (!printStringInitialized_) {
    callCallback(ticks);
    printStringInitialized_ = true;
  }
  
  // Waiting for input
  if (pausedForInput_) {
    if (continueConditionMet()) {
      continueConditionAction();
    }
    else {
      return;
    }
  }
  
//  if (pausedForInput_) {
//    return;
//  }
  
  // If out of characters, we're done
  if ((unsigned int)printingPosition_ >= printString_.size()) {
    emptyMessageAction();
    return;
  }
  // Otherwise, print as much as we need to
  else {
    // basically a hack for StandardMessageWindow
    if (needsReset_) {
      resetPrintedText();
      needsReset_ = false;
    }
  
    printingTickCounter_ += ticks;
    
    // Wait until the specified time has passed to print
    // the next character
    if ((unsigned int)printingPosition_ < printString_.size()
      && printingTickCounter_ < ticksPerCharacter()) {
      return;
    }
    
    int charactersToPrint;
    // Print speed of 0 = print all
    if (ticksPerCharacter() == 0) {
      charactersToPrint = printString_.size() - printingPosition_;
    }
    else {
      charactersToPrint = (double)printingTickCounter_
                              / ticksPerCharacter();
    }
    // Reset printing counter
    printingTickCounter_ = 0;
    
    // Don't print more characters than there are
    if (charactersToPrint > printString_.size() - printingPosition_) {
      charactersToPrint
        = printString_.size() - printingPosition_;
    }
    
    // Print characters
    for (int i = 0; i < charactersToPrint; i++) {
      writeNextCharacter();
    }
    printedText_->update();
  
    // Trigger the message printing callback if out of characters
    if ((unsigned int)printingPosition_ >= printString_.size()) {
      pausedForInput_ = true;
      callCallback(ticks);
    }
  }
}
             
std::string& SimpleMessagePrintingWindowArea::printString() {
  return printString_;
}

void SimpleMessagePrintingWindowArea::setPrintString(
  const std::string& printString__) {
  printString_ = printString__;
}
  
double SimpleMessagePrintingWindowArea::ticksPerCharacter() {
  return ticksPerCharacter_;
}

void SimpleMessagePrintingWindowArea::setTicksPerCharacter(
  double ticksPerCharacter__) {
  ticksPerCharacter_ = ticksPerCharacter__;
}

int SimpleMessagePrintingWindowArea::printingPosition() {
  return printingPosition_;
}

void SimpleMessagePrintingWindowArea
  ::setPrintingPosition(int printingPosition__) {
  printingPosition_ = printingPosition__;
}
  
void SimpleMessagePrintingWindowArea::writeNextCharacter() {
  char nextChar = printString_[printingPosition_++];
  writePosition_
    = gameMemory_.fontCore().writeMessage(std::string() + nextChar,
                                          font_,
                                          fontSize_,
                                          *printedText_,
                                          writePosition_,
                                          drawColor_);
}
  
void SimpleMessagePrintingWindowArea::continueConditionAction() {
  pausedForInput_ = false;
  resetPrintedText();
}
  
void SimpleMessagePrintingWindowArea::emptyMessageAction() {
  die();
}


};
