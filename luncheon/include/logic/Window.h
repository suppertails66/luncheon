#ifndef WINDOW_H
#define WINDOW_H


#include "logic/FocusableObject.h"
#include "graphics/RectArea.h"

namespace Luncheon {


class WindowArea;

class Window : public FocusableObject {
public:
  virtual ~Window();
  
  Window(GameMemory& gameMemory__,
         GameScene& parent__,
         WindowArea* windowArea__,
         WindowArea* parentWindowArea__,
         RectArea dimensions__/*,
         Window* parentWindow__*/);
  
  virtual void updateSelf(GTick ticks);
  
  virtual void updateWindow(GTick ticks);
  
  virtual void drawSelf(ScreenBuffer& buffer,
                        int drawX,
                        int drawY);
  
  virtual void drawWindow(ScreenBuffer& buffer);
  
  virtual void drawContent(ScreenBuffer& buffer);
  
  virtual bool hideContent();
  virtual void setHideContent(bool hideContent__);
  
  virtual int x();
  virtual int y();
  virtual int w();
  virtual int h();
  
  virtual void setX(int x__);
  virtual void setY(int y__);
  virtual void setW(int w__);
  virtual void setH(int h__);
  
  virtual int contentX();
  virtual int contentY();
  virtual int contentW();
  virtual int contentH();
  
  virtual bool clipping();
  virtual void setClipping(bool clipping__);
  
//  virtual bool hasParentWindow();
  
//  virtual Window& parentWindow();

  virtual void changeWindowArea
    (WindowArea* windowArea__);
  
  virtual WindowArea& windowArea();
  
  virtual bool hasParentWindowArea();
  
  virtual WindowArea& parentWindowArea();
             
  virtual GameObjectID objectID();
protected:
         
//  Window* parentWindow_;
             
  WindowArea* windowArea_;
             
  WindowArea* parentWindowArea_;
  
  int x_;
  int y_;
  int w_;
  int h_;
  
  bool clipping_;
  
  bool hideContent_;
};


};


#endif 
