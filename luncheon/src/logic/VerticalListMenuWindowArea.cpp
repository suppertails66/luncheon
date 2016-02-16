#include "logic/VerticalListMenuWindowArea.h"
#include "logic/Window.h"
#include <iostream>

namespace Luncheon {


VerticalListMenuWindowArea::~VerticalListMenuWindowArea() { };
  
VerticalListMenuWindowArea::VerticalListMenuWindowArea(
                             GameMemory& gameMemory__,
                             GameScene& parent__,
                             Window* parentWindow__,
                             ResourceID cursorEnabledID__,
                             ResourceID cursorDisabledID__,
                             ResourceID cursorEnabledSoundID__,
                             ResourceID cursorDisabledSoundID__)
  : ListMenuWindowArea(gameMemory__,
                       parent__,
                       parentWindow__,
                       cursorEnabledID__,
                       cursorDisabledID__,
                       cursorEnabledSoundID__,
                       cursorDisabledSoundID__) {
  
}
  
/*void VerticalListMenuWindowArea::updateSelection(GTick ticks) {
  if (hasFocus()) {
  
    // If we just got the focus back from a child window,
    // skip this window's update to prevent it from
    // using input that was intended for the child window
    if (focusWasReturned()) {
      focusWasReturned_ = false;
      return;
    }
  
    // Update here in derived classes
    if (hasChildWindow()) {
      if (childWindow_->dead()) {
        destroyChildWindow();
      }
    }
    
    if (selectionIncrementInputActivated()) {
      changeSelection(selectedItemNum_ + 1);
//      if (selectedItemNum_ > 0) {
//        --selectedItemNum_;
//      }
    }
    else if (selectionDecrementInputActivated()) {
      changeSelection(selectedItemNum_ - 1);
//      if (selectedItemNum_ < numItems() - 1) {
//        ++selectedItemNum_;
//      }
    }
    else if (selectionPageUpInputActivated()) {
//      changeSelection(selectedItemNum_ - maxVisibleItems() - 1);
      changeSelectionPage(selectedItemNum_ - maxVisibleItems() + 1);
    }
    else if (selectionPageDownInputActivated()) {
//      changeSelection(selectedItemNum_ + maxVisibleItems() - 1);
      changeSelectionPage(selectedItemNum_ + maxVisibleItems() - 1);
    }
    
    if (scrolling_) {
//      std::cout << "Lowest fully visible: " << lowestFullyVisibleItemNum() << std::endl;
//      std::cout << "Highest fully visible: " << highestFullyVisibleItemNum() << std::endl;
//      std::cout << "Max visible items: " << maxVisibleItems() << std::endl;
      // scroll if necessary
      if (selectedItemNum_ > highestFullyVisibleItemNum()) {
        scrollItemToBottom(selectedItemNum_);
      }
      else if (selectedItemNum_ < lowestFullyVisibleItemNum()) {
        scrollItemToTop(selectedItemNum_);
      }
    }
    
//    if (gameMemory_.inputCore().pressed(InputKeys::left)) {
//      --scrollY_;
//    }
//    else if (gameMemory_.inputCore().pressed(InputKeys::right)) {
//      ++scrollY_;
//    }
    
    if (selectionConfirmInputActivated()) {
      makeSelection();
    }
    else if (selectionCancelInputActivated()) {
      if (cancellable_) {
        if (sourceOfFocus_ != 0) {
          returnFocus();
        }
        die();
      }
    }
    
  
  }
} */

void VerticalListMenuWindowArea::drawItems(ScreenBuffer& buffer) {
  // Get coordinates of the top-left corner of the menu content
  // relative to the top-left corner of the containing window
  int xBase = parentWindow_->contentX() - parentWindow_->x() + paddingLeft_;
  int yBase = parentWindow_->contentY() - parentWindow_->y() + paddingTop_;
  
/*  DrawableSurface* drawable
    = gameMemory_.graphicsCore().createDrawableSurface(
                                    parentWindow_->contentW() - paddingLeft_
                                                              - paddingRight_,
                                    parentWindow_->contentH() - paddingTop_
                                                              - paddingBottom_); */
  
/*  // Draw items
  int firstItem = 0;
  int lastItem = numItems();
  int numHiddenItemsAbove = 0;
  
  // If scrolling is enabled, print only the fully visible
  // items and the entries directly above and below them
  if (scrolling_) {
    firstItem = selectedItemNum_;
    lastItem = firstItem + maxVisibleItems();
    
    if (lastItem > numItems()) {
      lastItem = numItems() - 1;
    }
    else if (lastItem < numItems() - 1) {
//      lastItem = 
    }
    
    if (selectedItemNum_ != 0) {
      --firstItem;
    }
  } */
  
  if (needsRedraw_) {
                
    delete itemSurface_;
    itemSurface_ = gameMemory_.graphicsCore().createDrawableSurface(
                     parentWindow_->contentW() - paddingLeft_
                                                - paddingRight_,
                     parentWindow_->contentH() - paddingTop_
                                               - paddingBottom_);
    
    DrawableSurface* drawable = itemSurface_;
    
    for (int i = 0; i < numItems(); i++) {
  //    int xPos = xBase - scrollX_;
  //    int yPos = yBase + (spacing_ * i) - scrollY_;

      int xPos = -scrollX_;
      // The (i + 1) here is necessary because text is drawn upward
      // from the base position rather than downward
      int yPos = (spacing_ * (i + 1)) - scrollY_;
      
      drawItem(getItem(i),
               *drawable,
               xPos,
               yPos);
    }
    drawable->update();
  
    needsRedraw_ = false;
  }
    
  // Blit drawn items to buffer
  buffer.draw(*itemSurface_,
              parentWindow_->contentX() + paddingLeft_,
              parentWindow_->contentY() + paddingTop_);
              
//  delete drawable;
  
  // Draw cursor
  buffer.draw(cursorEnabledAnimation_->currentFrame().graphic(),
              parentWindow_->contentX(),
              parentWindow_->contentY()
                + paddingTop_                   // skip padding
                + (selectedItemNum_ * spacing_) // skip height of items above
                + (spacing_/2)                  // center vertically on item
                - scrollY_                      // account for scolling
                - (((spacing_/11) <= 0) 
                    ? (spacing_/3) 
                    : (spacing_/8)));           // this aligns better with the
                                                // fonts we're using
}
  
int VerticalListMenuWindowArea::maxVisibleItems() {
  return ((parentWindow_->contentH() - paddingTop_ - paddingBottom_)
            / spacing_);
}
  
int VerticalListMenuWindowArea::highestFullyVisibleItemNum() {
  int result = lowestFullyVisibleItemNum() + maxVisibleItems();
  
  if (result > numItems()) {
    result = numItems() - 1;
    return result;
  }
  
  // Account for partial visibility
  if (((scrollY_ + paddingBottom_) % spacing_ != 0)) {
    --result;
    if (result <= 0) {
      result = 0;
    }
  }
  
  
  
  return result;
}

int VerticalListMenuWindowArea::lowestFullyVisibleItemNum() {
  if (spacing_ == 0) {
    return 0;
  }
  
//  int result = (scrollY_/spacing_);
  
  if (scrollY_ % spacing_ == 0) {
    // Top item is fully visible
    return (scrollY_/spacing_);
  }
  else {
    // Top item is partially obscured
    return (scrollY_/spacing_) + 1;
  }
}
  
void VerticalListMenuWindowArea::scrollItemToBottom(int itemNum) {
  int topItem = itemNum - maxVisibleItems();
  if (topItem < 0) {
    topItem = 0;
  }
  scrollY_ = (topItem + 1) * spacing_;
}

void VerticalListMenuWindowArea::scrollItemToTop(int itemNum) {
  int topItem = itemNum;
  if (topItem > 0) {
//    --topItem;
  }
  scrollY_ = (topItem) * spacing_;
}
  
bool VerticalListMenuWindowArea::selectionIncrementInputActivated() {
  return (gameMemory_.inputCore().pressed(InputKeys::down));
}

bool VerticalListMenuWindowArea::selectionDecrementInputActivated() {
  return (gameMemory_.inputCore().pressed(InputKeys::up));
}

bool VerticalListMenuWindowArea::selectionPageDownInputActivated() {
  return (gameMemory_.inputCore().pressed(InputKeys::right));
}

bool VerticalListMenuWindowArea::selectionPageUpInputActivated() {
  return (gameMemory_.inputCore().pressed(InputKeys::left));
}

bool VerticalListMenuWindowArea::selectionConfirmInputActivated() {
  return (gameMemory_.inputCore().triggered(InputKeys::p));
}

bool VerticalListMenuWindowArea::selectionCancelInputActivated() {
  return (gameMemory_.inputCore().triggered(InputKeys::o));
}

GameObjectID VerticalListMenuWindowArea::objectID() {
  return 2;
}


}; 
