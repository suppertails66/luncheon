#include "logic/MessagePrintingWindowArea.h"
#include "logic/Window.h"
#include "logic/MessagePrintingFunctor.h"
#include <iostream>

namespace Luncheon {


MessagePrintingWindowArea::~MessagePrintingWindowArea() {
  delete callback_;
  delete printedText_;
}

MessagePrintingWindowArea::MessagePrintingWindowArea(
           GameMemory& gameMemory__,
           GameScene& parent__,
           Window* parentWindow__,
           MessagePrintingFunctor* callback__,
           const std::string& font__,
           int fontSize__,
           int paddingLeft__,
           int paddingTop__)
  : WindowArea(gameMemory__,
               parent__,
               parentWindow__),
    printedText_(0),
    callback_(callback__),
    font_(font__),
    fontSize_(fontSize__),
    paddingLeft_(paddingLeft__),
    paddingTop_(paddingTop__),
    printedTextOffsetX_(0),
    printedTextOffsetY_(0),
    pausedForInput_(false),
    drawColor_(255, 255, 255, 255),
    writePosition_(0, 0) {
  // Create the printing surface
  resetPrintedText();
}
  
void MessagePrintingWindowArea::resetPrintedText() {
  delete printedText_;
  printedText_ = gameMemory_
    .graphicsCore().createDrawableSurface(parentWindow_->contentW()
                                            - paddingLeft_,
                                          parentWindow_->contentH()
                                            - paddingTop_);
  
  writePosition_ = WritePosition(0,
    gameMemory_.fontCore().getLineHeight(font_,
                                         fontSize_));
}

int MessagePrintingWindowArea::paddingLeft() {
  return paddingLeft_;
}

void MessagePrintingWindowArea::setPaddingLeft(int paddingLeft__) {
  paddingLeft_ = paddingLeft__;
}

int MessagePrintingWindowArea::paddingTop() {
  return paddingTop_;
}

void MessagePrintingWindowArea::setPaddingTop(int paddingTop__) {
  paddingTop_ = paddingTop__;
}
  
int MessagePrintingWindowArea::printedTextOffsetX() {
  return printedTextOffsetX_;
}

void MessagePrintingWindowArea::setPrintedTextOffsetX(
  int printedTextOffsetX__) {
  printedTextOffsetX_ = printedTextOffsetX__;
}

int MessagePrintingWindowArea::printedTextOffsetY() {
  return printedTextOffsetY_;
}

void MessagePrintingWindowArea::setPrintedTextOffsetY(
  int printedTextOffsetY__) {
  printedTextOffsetY_ = printedTextOffsetY__;
}
    
bool MessagePrintingWindowArea::pausedForInput() {
  return pausedForInput_;
}

void MessagePrintingWindowArea::setPausedForInput(
  bool pausedForInput__) {
  pausedForInput_ = pausedForInput__;
}
  
DrawColor MessagePrintingWindowArea::drawColor() {
  return drawColor_;
}

void MessagePrintingWindowArea::setDrawColor(DrawColor drawColor__) {
  drawColor_ = drawColor__;
}
  
void MessagePrintingWindowArea::updateSelf(GTick ticks) {
  updateMessage(ticks);
}

void MessagePrintingWindowArea::updateMessage(GTick ticks) {
  // Trigger the message printing callback
  (*callback_)(&gameMemory_,
               &parent_,
               this,
               ticks);
}

void MessagePrintingWindowArea::drawSelf(ScreenBuffer& buffer,
                      int drawX,
                      int drawY) {
  drawMessage(buffer,
              drawX,
              drawY);
}
  
void MessagePrintingWindowArea::drawMessage(ScreenBuffer& buffer,
                                            int drawX,
                                            int drawY) {
  // Set clip window if enabled
  // (ensure everything within borders is clipped)
  bool hasClip = buffer.hasClipArea();
  ClipArea oldClipArea = buffer.getClipArea();
  buffer.setClipArea(ClipArea(parentWindow_->contentX()
                                + paddingLeft_,
                              parentWindow_->contentY()
                                + paddingTop_,
                              printedText_->getWidth(),
                              printedText_->getHeight()));
  
  buffer.draw(*printedText_,
              parentWindow_->contentX()
                + paddingLeft_
                + printedTextOffsetX_,
              parentWindow_->contentY()
                + paddingTop_
                + printedTextOffsetY_);
  
  // Restore old clip area
  if (!hasClip) {
    buffer.clearClipArea();
  }
  else {
    buffer.setClipArea(oldClipArea);
  }
  
  // print "more" indicator if needed and enabled
  // ...
  
}
  
void MessagePrintingWindowArea::callCallback(GTick ticks) {
  (*callback_)(&gameMemory_,
               &parent_,
               this,
               ticks);
}


};
