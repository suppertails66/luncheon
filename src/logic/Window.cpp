#include "logic/Window.h"
#include "logic/WindowArea.h"
#include <iostream>

namespace Luncheon {


Window::~Window() {
  delete windowArea_;
}

Window::Window(GameMemory& gameMemory__,
               GameScene& parent__,
               WindowArea* windowArea__,
               WindowArea* parentWindowArea__,
               RectArea dimensions__/*,
               Window* parentWindow__*/)
  : FocusableObject(gameMemory__,
               parent__),
    windowArea_(windowArea__),
    parentWindowArea_(parentWindowArea__),
    x_(dimensions__.x()),
    y_(dimensions__.y()),
    w_(dimensions__.w()),
    h_(dimensions__.h()),
    clipping_(true),
    hideContent_(false)/*,
    parentWindow_(parentWindow__)*/ { };
  
void Window::updateSelf(GTick ticks) {
  // PROTIP: don't try to open a child window and give
  // something other than it the focus, because it won't work
  // (you should really rewrite this so that FocusableObjects are
  // used instead of child windows)

  // Update child first if it exists
  if (windowArea_->hasChildWindow()) {
    windowArea_->childWindow().update(ticks);
  }
  else if (windowArea_->hasChildFocusable()) {
    windowArea_->childFocusable().update(ticks);
    if (windowArea_->childFocusable().dead()) {
      if (windowArea_->childFocusable().hasFocus()) {
        windowArea_->childFocusable().returnFocus();
      }
      windowArea_->destroyChildFocusable();
    }
  }
  // If no child window exists, update child Focusable if it exists
/*  else if (windowArea_->targetOfFocus() != 0) {
    windowArea_->targetOfFocus()->update(ticks);
    if (windowArea_->targetOfFocus()->dead()) {
      FocusableObject* destroy = windowArea_->targetOfFocus();
      windowArea_->targetOfFocus()->returnFocus();
      delete destroy;
    }
  } */
  // Update self last (child windows are updated first)
  updateWindow(ticks);
  
  // Die if contained area is dead
  if (windowArea_->dead()) {
    die();
  }
}

void Window::updateWindow(GTick ticks) {
  windowArea_->update(ticks);
}
  
void Window::drawSelf(ScreenBuffer& buffer,
                      int drawX,
                      int drawY) {
  drawWindow(buffer);
  
  // Draw child last if it exists
  if (windowArea_->hasChildWindow()) {
    windowArea_->childWindow().draw(buffer);
  }
  else if (windowArea_->hasChildFocusable()) {
    windowArea_->childFocusable().draw(buffer,
                                       drawX,
                                       drawY);
  }
  // If no child window exists, draw child Focusable if it exists
/*  else if (windowArea_->targetOfFocus() != 0) {
    windowArea_->targetOfFocus()->draw(buffer);
  } */
}
  
void Window::drawWindow(ScreenBuffer& buffer) {
  // Draw self first (child windows go on top)
  
  // Set clip window if enabled
  bool hasClip = buffer.hasClipArea();
  ClipArea oldClipArea = buffer.getClipArea();
  if (clipping_) {
    buffer.setClipArea(ClipArea(x(),
                                y(),
                                w(),
                                h()));
  }
  
  drawContent(buffer);
  
  // Restore old clip area
  if (clipping_) {
    if (!hasClip) {
      buffer.clearClipArea();
    }
    else {
      buffer.setClipArea(oldClipArea);
    }
  }
}

void Window::drawContent(ScreenBuffer& buffer) {
  windowArea_->draw(buffer);
}
  
bool Window::hideContent() {
 return hideContent_;
}

void Window::setHideContent(bool hideContent__) {
  hideContent_ = hideContent__;
}
  
int Window::x() {
  return x_;
}

int Window::y() {
  return y_;
}

int Window::w() {
  return w_;
}

int Window::h() {
  return h_;
}
  
void Window::setX(int x__) {
  x_ = x__;
}

void Window::setY(int y__) {
  y_ = y__;
}

void Window::setW(int w__) {
  w_ = w__;
}

void Window::setH(int h__) {
  h_ = h__;
}

int Window::contentX() {
  return x_;
}

int Window::contentY() {
  return y_;
}

int Window::contentW() {
  return w_;
}

int Window::contentH() {
  return h_;
}
  
bool Window::clipping() {
  return clipping_;
}

void Window::setClipping(bool clipping__) {
  clipping_ = clipping__;
}

/*bool Window::hasParentWindow() {
  return (parentWindow_ != 0);
}

Window& Window::parentWindow() {
  return *parentWindow_;
} */

void Window::changeWindowArea
  (WindowArea* windowArea__) {
  delete windowArea_;
  windowArea_ = windowArea__;
}
  
WindowArea& Window::windowArea() {
  return *windowArea_;
}
  
bool Window::hasParentWindowArea() {
  return (parentWindowArea_ != 0);
}

WindowArea& Window::parentWindowArea() {
  return *parentWindowArea_;
}
             
GameObjectID Window::objectID() {
  return -2;
}


}; 
