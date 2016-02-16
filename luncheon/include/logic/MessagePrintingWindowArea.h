#ifndef MESSAGEPRINTINGWINDOWAREA_H
#define MESSAGEPRINTINGWINDOWAREA_H


#include "logic/WindowArea.h"
#include "graphics/DrawableSurface.h"
#include "graphics/DrawColor.h"
#include <string>

namespace Luncheon {


class MessagePrintingFunctor;

class MessagePrintingWindowArea : public WindowArea {
public:
  virtual ~MessagePrintingWindowArea();
  
  MessagePrintingWindowArea(
             GameMemory& gameMemory__,
             GameScene& parent__,
             Window* parentWindow__,
             MessagePrintingFunctor* callback__,
             const std::string& font__,
             int fontSize__,
             int paddingLeft__ = 0,
             int paddingTop__ = 0);
  
  virtual void updateSelf(GTick ticks);
  
  virtual void updateMessage(GTick ticks);
  
  virtual void drawSelf(ScreenBuffer& buffer,
                        int drawX,
                        int drawY);
  
  virtual void drawMessage(ScreenBuffer& buffer,
                           int drawX,
                           int drawY);
  
  virtual void resetPrintedText();

  virtual int paddingLeft();
  virtual void setPaddingLeft(int paddingLeft__);

  virtual int paddingTop();
  virtual void setPaddingTop(int paddingTop__);
  
  virtual int printedTextOffsetX();
  virtual void setPrintedTextOffsetX(
    int printedTextOffsetX__);
  
  virtual int printedTextOffsetY();
  virtual void setPrintedTextOffsetY(
    int printedTextOffsetY__);
    
  virtual bool pausedForInput();
  virtual void setPausedForInput(bool pausedForInput__);
  
  virtual DrawColor drawColor();
  virtual void setDrawColor(DrawColor drawColor__);
protected:

  DrawableSurface* printedText_;
  
  MessagePrintingFunctor* callback_;
  
  std::string font_;
  
  int fontSize_;
  
  int paddingLeft_;
  
  int paddingTop_;
  
  int printedTextOffsetX_;
  
  int printedTextOffsetY_;
  
  bool pausedForInput_;
  
  DrawColor drawColor_;
  
  WritePosition writePosition_;
  
  virtual void callCallback(GTick ticks);

};

  
};


#endif 
