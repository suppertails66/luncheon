#include "logic/WindowArea.h"
#include "logic/Window.h"


namespace Luncheon {


WindowArea::~WindowArea() {
/*  if (!hasChildWindow()) {
    if (targetOfFocus_ != 0) {
      delete targetOfFocus_;
    }
  } */
  
  delete childWindow_;
}

WindowArea::WindowArea(GameMemory& gameMemory__,
                       GameScene& parent__,
                       Window* parentWindow__)
  : FocusableObject(gameMemory__,
                    parent__),
    parentWindow_(parentWindow__),
    childWindow_(0) { };
  
Window& WindowArea::childWindow() {
  return *childWindow_;
}

Window& WindowArea::parentWindow() {
  return *parentWindow_;
}
  
WindowArea& WindowArea::childWindowArea() {
  return childWindow_->windowArea();
}
  
bool WindowArea::hasParentWindow() {
  return (parentWindow_ != 0);
}

bool WindowArea::hasChildWindow() {
  return (childWindow_ != 0);
}
  
void WindowArea::changeChildWindow(Window* childWindow__) {
  delete childWindow_;
  childWindow_ = childWindow__;
}
  
void WindowArea::destroyChildWindow() {
  delete childWindow_;
  childWindow_ = 0;
}
                        
void WindowArea::close() {
  die();
}
             
GameObjectID WindowArea::objectID() {
  return -1;
}


}; 
