#ifndef WINDOWAREA_H
#define WINDOWAREA_H


#include "logic/FocusableObject.h"

namespace Luncheon {


class Window;

class WindowArea : public FocusableObject {
public:
  virtual ~WindowArea();
  
  virtual void updateSelf(GTick ticks) =0;
  
  virtual void drawSelf(ScreenBuffer& buffer,
                        int drawX,
                        int drawY) =0;
  
  virtual Window& parentWindow();
  
  virtual Window& childWindow();
  
  virtual WindowArea& childWindowArea();
  
  virtual bool hasParentWindow();
  
  virtual bool hasChildWindow();
  
  virtual void changeChildWindow(Window* childWindow__);
  
  virtual void destroyChildWindow();
                        
  virtual void close();
             
  virtual GameObjectID objectID();
protected:
  WindowArea(GameMemory& gameMemory__,
             GameScene& parent__,
             Window* parentWindow__);
             
  Window* parentWindow_;
  
  Window* childWindow_;
};


};


#endif 
