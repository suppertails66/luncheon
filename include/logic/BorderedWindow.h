#ifndef BORDEREDWINDOW_H
#define BORDEREDWINDOW_H


#include "logic/Window.h"
#include "animation/Animation.h"
#include "animation/AnimationPlayer.h"
#include "logic/BorderAnimationPlayers.h"
#include "logic/BorderResourceIDs.h"
#include "graphics/DrawColor.h"

namespace Luncheon {


class BorderedWindow : public Window {
public:
  virtual ~BorderedWindow();
  
  virtual void updateWindow(GTick ticks);
  
  virtual void drawWindow(ScreenBuffer& buffer);
  
  virtual void drawContent(ScreenBuffer& buffer);
  
  virtual int contentX();
  virtual int contentY();
  virtual int contentW();
  virtual int contentH();
  
  virtual int borderHorizontalWidth();
  virtual int borderVerticalWidth();
  
  virtual DrawColor backgroundColor();
  virtual void setBackgroundColor(DrawColor backgroundColor__);
protected:
  BorderedWindow(GameMemory& gameMemory__,
                 GameScene& parent__,
                 WindowArea* windowArea__,
                 WindowArea* parentWindowArea__,
                 RectArea dimensions__,
                 int borderHorizontalWidth__,
                 int borderVerticalWidth__,
                 BorderResourceIDs borderResourceIDs,
                 DrawColor backgroundColor__/*,
                 ResourceID backgroundID */);
                 
/*  BorderedWindow(GameMemory& gameMemory__,
                 GameScene& parent__,
                 WindowArea* windowArea__,
                 RectArea dimensions__,
                 int borderHorizontalWidth__,
                 int borderVerticalWidth__,
                 BorderAnimationPlayers* borderAnimationPlayers__); */
                 
  int borderHorizontalWidth_;
  
  int borderVerticalWidth_;
  
  virtual void drawBackground(ScreenBuffer& buffer);
  
  virtual void drawBorder(ScreenBuffer& buffer);
  
  virtual void advancePlayers(GTick ticks);
  
  BorderAnimationPlayers* borderAnimationPlayers_;
  
  DrawColor backgroundColor_;
  
//  bool backgroundAnimationEnabled_;
  
//  AnimationPlayer* backgroundAnimationPlayer_;
};


};


#endif 
