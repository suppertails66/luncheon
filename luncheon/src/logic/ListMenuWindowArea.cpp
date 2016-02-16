#include "logic/ListMenuWindowArea.h"
#include "logic/Window.h"
#include <iostream>

namespace Luncheon {


  
// Number of gticks that must pass before commands will
// be repeated
const GTick ListMenuWindowArea::holdRepeatTolerance(320);

// Number of gticks between repeated commands
const GTick ListMenuWindowArea::delayBetweenRepeatInputs(96);

ListMenuWindowArea::~ListMenuWindowArea() {
  // Destroy all contained items
  for (ListMenuItemCollection::iterator it = menuItems_.begin();
       it != menuItems_.end();
       it++) {
    delete (*it);
  }
  
  delete cursorEnabledAnimation_;
  delete cursorDisabledAnimation_;
  delete itemSurface_;
}

ListMenuWindowArea::ListMenuWindowArea(GameMemory& gameMemory__,
                                       GameScene& parent__,
                                       Window* parentWindow__,
                                       ResourceID cursorEnabledID__,
                                       ResourceID cursorDisabledID__,
                                       ResourceID cursorEnabledSoundID__,
                                       ResourceID cursorDisabledSoundID__)
  : MenuWindowArea(gameMemory__,
                   parent__,
                   parentWindow__),
    scrolling_(true),
    scrollX_(0),
    scrollY_(0),
    cancellable_(true),
    selectionMade_(false),
    wraparound_(false),
    spacing_(0),
    paddingLeft_(8),
    paddingTop_(8),
    paddingRight_(8),
    paddingBottom_(8),
    selectedItemNum_(0),
    font_("res/LiberationMono-Regular.ttf"),
    fontSize_(14),
    cursorEnabledAnimation_(0),
    cursorDisabledAnimation_(0),
    cursorEnabledSoundID_(cursorEnabledSoundID__),
    cursorDisabledSoundID_(cursorDisabledSoundID__),
    incrementHoldCount_(0),
    decrementHoldCount_(0),
    pageUpHoldCount_(0),
    pageDownHoldCount_(0),
    incrementRepeatCount_(0),
    decrementRepeatCount_(0),
    pageUpRepeatCount_(0),
    pageDownRepeatCount_(0),
    needsRedraw_(true),
    itemSurface_(0) {
    
  spacing_ = gameMemory__.fontCore().getLineHeight(font_,
                                                   fontSize_);

  cursorEnabledAnimation_
    = gameMemory__.graphicsCore().createAnimationPlayer(cursorEnabledID__);

  cursorDisabledAnimation_
    = gameMemory__.graphicsCore().createAnimationPlayer(cursorDisabledID__);
    
  itemSurface_ = gameMemory__.graphicsCore().createDrawableSurface(
                                parentWindow_->contentW() - paddingLeft_
                                                          - paddingRight_,
                                parentWindow_->contentH() - paddingTop_
                                                          - paddingBottom_);
  
//  loadItems();
}
  
void ListMenuWindowArea::updateSelf(GTick ticks) {
  preUpdate(ticks);

  // Advance cursor animations
  cursorEnabledAnimation_->advance(ticks);
  cursorDisabledAnimation_->advance(ticks);
  
  // Modify selected item
  updateSelection(ticks);
  
  postUpdate(ticks);
}
  
void ListMenuWindowArea::preUpdate(GTick ticks) {
  
}

void ListMenuWindowArea::postUpdate(GTick ticks) {
  
}

void ListMenuWindowArea::updateSelection(GTick ticks) {
  if (hasFocus()) {
  
    // If we just got the focus back from a child window,
    // skip this window's update to prevent it from
    // using input that was intended for the child window
    if (focusWasReturned()) {
    
      ListMenuItem& item = getItem(selectedItemNum_);
      item.callback()(&gameMemory_,
                    &parent_,
                    this,
                    ListMenuItemEventTypes::focusReturned,
                    selectedItemNum_,
                    item.optionID());
                    
      reloadItems();
                    
      focusWasReturned_ = false;
      return;
    }
  
    if (hasChildWindow()) {
      if (childWindow_->dead()) {
        destroyChildWindow();
      }
    }
    
    if (selectionIncrementInputActivated()) {
      // Trigger immediately if the input was just activated
      if (incrementHoldCount_ == 0) {
        changeSelection(selectedItemNum_ + 1);
      }
      // Otherwise, wait until the repeat trigger time has passed
      else if (incrementHoldCount_ >= holdRepeatTolerance) {
        // Don't allow a hold command to increment past the end of the list
        if (selectedItemNum_ != numItems() - 1) {
          incrementRepeatCount_ += ticks;
          // Only trigger after the allotted repeat time has passed
          if (incrementRepeatCount_ >= delayBetweenRepeatInputs) {
            incrementRepeatCount_
              = incrementRepeatCount_ % delayBetweenRepeatInputs;
            changeSelection(selectedItemNum_ + 1);
          }
        }
      }
    }
    else if (selectionDecrementInputActivated()) {
      if (decrementHoldCount_ == 0) {
        changeSelection(selectedItemNum_ - 1);
      }
      else if (decrementHoldCount_ >= holdRepeatTolerance) {
        // Don't allow a hold command to decrement past the start of the list
        if (selectedItemNum_ != 0) {
          decrementRepeatCount_ += ticks;
          // Only trigger after the allotted repeat time has passed
          if (decrementRepeatCount_ >= delayBetweenRepeatInputs) {
            decrementRepeatCount_
              = decrementRepeatCount_ % delayBetweenRepeatInputs;
            changeSelection(selectedItemNum_ - 1);
          }
        }
      }
    }
    else if (selectionPageUpInputActivated()) {
      if (pageUpHoldCount_ == 0) {
        changeSelectionPage(selectedItemNum_ - maxVisibleItems() + 1);
      }
      else if (pageUpHoldCount_ >= holdRepeatTolerance) {
        // Don't allow a hold command to page past the start of the list
        if (selectedItemNum_ != 0) {
          pageUpRepeatCount_ += ticks;
          // Only trigger after the allotted repeat time has passed
          if (pageUpRepeatCount_ >= delayBetweenRepeatInputs) {
            pageUpRepeatCount_
              = pageUpRepeatCount_ % delayBetweenRepeatInputs;
            changeSelectionPage(selectedItemNum_ - maxVisibleItems() + 1);
          }
        }
      }
    }
    else if (selectionPageDownInputActivated()) {
      // Trigger immediately if the input was just activated
      if (pageDownHoldCount_ == 0) {
        changeSelectionPage(selectedItemNum_ + maxVisibleItems() - 1);
      }
      // Otherwise, wait until the repeat trigger time has passed
      else if (pageDownHoldCount_ >= holdRepeatTolerance) {
        // Don't allow a hold command to page past the end of the list
        if (selectedItemNum_ != numItems() - 1) {
          pageDownRepeatCount_ += ticks;
          // Only trigger after the allotted repeat time has passed
          if (pageDownRepeatCount_ >= delayBetweenRepeatInputs) {
            pageDownRepeatCount_
              = pageDownRepeatCount_ % delayBetweenRepeatInputs;
            changeSelectionPage(selectedItemNum_ + maxVisibleItems() - 1);
          }
        }
      }
    }
    
    if (scrolling_) {
//      std::cout << "Lowest fully visible: " << lowestFullyVisibleItemNum() << std::endl;
//      std::cout << "Highest fully visible: " << highestFullyVisibleItemNum() << std::endl;
//      std::cout << "Max visible items: " << maxVisibleItems() << std::endl;
//        std::cout << "highest: " << highestFullyVisibleItemNum() << std::endl;
//        std::cout << "lowest: " << lowestFullyVisibleItemNum() << std::endl;

      // scroll if necessary
      if (selectedItemNum_ > highestFullyVisibleItemNum()) {
        scrollItemToBottom(selectedItemNum_);
      }
      else if (selectedItemNum_ < lowestFullyVisibleItemNum()) {
        scrollItemToTop(selectedItemNum_);
      }
    }
    
    if (selectionConfirmInputActivated()) {
      makeSelection();
    }
    else if (selectionCancelInputActivated()) {
      if (cancellable_) {
        if (sourceOfFocus_ != 0) {
          returnFocus();
        }
        close();
      }
      else {
        ListMenuItem& item = getItem(selectedItemNum_);
        item.callback()(&gameMemory_,
                      &parent_,
                      this,
                      ListMenuItemEventTypes::cancelled,
                      selectedItemNum_,
                      item.optionID());
      }
    }
    
    // Update selection hold counters
    
    // Input is being held
    if (selectionIncrementInputActivated()) {
      incrementHoldCount_ += ticks;
    }
    // Input is released
    else {
      incrementHoldCount_ = 0;
      incrementRepeatCount_ = 0;
    }
    
    if (selectionDecrementInputActivated()) {
      decrementHoldCount_ += ticks;
    }
    else {
      decrementHoldCount_ = 0;
      decrementRepeatCount_ = 0;
    }
    
    if (selectionPageUpInputActivated()) {
      pageUpHoldCount_ += ticks;
    }
    else {
      pageUpHoldCount_ = 0;
      pageUpRepeatCount_ = 0;
    }
    
    if (selectionPageDownInputActivated()) {
      pageDownHoldCount_ += ticks;
    }
    else {
      pageDownHoldCount_ = 0;
      pageDownRepeatCount_ = 0;
    }
    
    
  
  }
}
  
void ListMenuWindowArea::drawSelf(ScreenBuffer& buffer,
                                  int drawX,
                                  int drawY) {
//  if (needsRedraw_) {
    drawItems(buffer);
//    needsRedraw_ = false;
//  }
}
  
void ListMenuWindowArea::changeSelection(int newSelection) {
  needsRedraw_ = true;
  
  if (newSelection < 0) {
    if (wraparound_) {
      selectedItemNum_ = numItems() - 1;
    }
    else {
      selectedItemNum_ = 0;
    }
  }
  else if (newSelection > numItems() - 1) {
    if (wraparound_) {
      selectedItemNum_ = 0;
    }
    else {
      selectedItemNum_ = numItems() - 1;
    }
  }
  else {
    selectedItemNum_ = newSelection;
  }
  
  // Trigger item callback
  ListMenuItem& item = getItem(selectedItemNum_);
  item.callback()(&gameMemory_,
                &parent_,
                this,
                ListMenuItemEventTypes::moved,
                selectedItemNum_,
                item.optionID());
}
  
void ListMenuWindowArea::changeSelectionPage(int newSelection) {
  needsRedraw_ = true;

  if (!wraparound_
      || (newSelection >= 0 && newSelection < numItems())) {
    changeSelection(newSelection);
    return;
  }

  // Paging up
  if (newSelection < 0) {
    // If at beginning of list, go to end
    if (selectedItemNum_ == 0) {
//      selectedItemNum_ = numItems() - 1;
    }
    // Otherwise, cap at start of list
    else {
      selectedItemNum_ = 0;
    }
  }
  // Paging down
  else {
    // If at end of list, go to beginning
    if (selectedItemNum_ == numItems() - 1) {
//      selectedItemNum_ = 0;
    }
    // Otherwise, cap at end of list
    else {
      selectedItemNum_ = numItems() - 1;
    }
  }
  
  // Trigger item callback
  ListMenuItem& item = getItem(selectedItemNum_);
  item.callback()(&gameMemory_,
                &parent_,
                this,
                ListMenuItemEventTypes::moved,
                selectedItemNum_,
                item.optionID());
}
  
void ListMenuWindowArea::makeSelection() {
  ListMenuItem& item = getItem(selectedItemNum_);
  if (!item.enabled()) {
    // disabled item: play disabled sound effect?
    // ...
  
    // Trigger item callback
    item.callback()(&gameMemory_,
                  &parent_,
                  this,
                  ListMenuItemEventTypes::confirmedDisabledItem,
                  selectedItemNum_,
                  item.optionID());
//    std::cout << "disabled item" << std::endl;
  }
  else {
    selectionMade_ = true;
    
    // Redraw in case user modifies menu in callback
    needsRedraw_ = true;
  
    // Trigger item callback
    item.callback()(&gameMemory_,
                  &parent_,
                  this,
                  ListMenuItemEventTypes::confirmed,
                  selectedItemNum_,
                  item.optionID());
  }
}
                   
bool ListMenuWindowArea::scrolling() {
  return scrolling_;
}
  
int ListMenuWindowArea::scrollX() {
  return scrollX_;
}

void ListMenuWindowArea::setScrollX(int scrollX__) {
  scrollX_ = scrollX__;
}

int ListMenuWindowArea::scrollY() {
  return scrollY_;
}
  
bool ListMenuWindowArea::wraparound() {
  return wraparound_;
}
  
bool ListMenuWindowArea::cancellable() {
  return cancellable_;
}

void ListMenuWindowArea::setCancellable(bool cancellable__) {
  cancellable_ = cancellable__;
}
  
bool ListMenuWindowArea::selectionMade() {
  return selectionMade_;
}

void ListMenuWindowArea::setSelectionMade(bool selectionMade__) {
  selectionMade_ = selectionMade__;
}

void ListMenuWindowArea::setWraparound(bool wraparound__) {
  wraparound_ = wraparound__;
}

void ListMenuWindowArea::setScrollY(int scrollY__) {
  scrollY_ = scrollY__;
}

void ListMenuWindowArea::setScrolling(bool scrolling__) {
  scrolling_ = scrolling__;
}
  
int ListMenuWindowArea::spacing() {
  return spacing_;
}

void ListMenuWindowArea::setSpacing(int spacing__) {
  spacing_ = spacing__;
}
  
int ListMenuWindowArea::paddingLeft() {
  return paddingLeft_;
}

void ListMenuWindowArea::setPaddingLeft(int paddingLeft__) {
  paddingLeft_ = paddingLeft__;
}

int ListMenuWindowArea::paddingTop() {
  return paddingTop_;
}

void ListMenuWindowArea::setPaddingTop(int paddingTop__) {
  paddingTop_ = paddingTop__;
}

int ListMenuWindowArea::paddingRight() {
  return paddingRight_;
}

void ListMenuWindowArea::setPaddingRight(int paddingRight__) {
  paddingRight_ = paddingRight__;
}

int ListMenuWindowArea::paddingBottom() {
  return paddingBottom_;
}

void ListMenuWindowArea::setPaddingBottom(int paddingBottom__) {
  paddingBottom_ = paddingBottom__;
}
  
int ListMenuWindowArea::selectedItemNum() {
  return selectedItemNum_;
}

void ListMenuWindowArea::setSelectedItemNum(int selectedItemNum__) {
  selectedItemNum_ = selectedItemNum__;
}
  
const std::string& ListMenuWindowArea::font() {
  return font_;
}

void ListMenuWindowArea::setFont(const std::string& font__) {
  font_ = font__;
}
  
int ListMenuWindowArea::fontSize() {
  return fontSize_;
}

void ListMenuWindowArea::setFontSize(int fontSize__) {
  fontSize_ = fontSize__;
}

/*DrawColor ListMenuWindowArea::disabledColor() {
  return disabledColor_;
}

void ListMenuWindowArea::setDisabledColor(DrawColor disabledColor__) {
  disabledColor_ = disabledColor__;
} */

bool ListMenuWindowArea::needsRedraw() {
  return needsRedraw_;
}

void ListMenuWindowArea::setNeedsRedraw(bool needsRedraw__) {
  needsRedraw_ = needsRedraw__;
}
  
int ListMenuWindowArea::numItems() {
  return menuItems_.size();
}
  
void ListMenuWindowArea::addItem(const std::string& label__,
                                 int optionID__,
                                 ListMenuItemFunctor* callback__,
                                 bool enabled__) {
  menuItems_.push_back(new ListMenuItem(label__,
                                    optionID__,
                                    callback__,
                                    enabled__));
}
  
void ListMenuWindowArea::addItem(const std::string& label__,
                                 int optionID__,
                                 ListMenuItemFunctor* callback__,
                                 bool enabled__,
                                 DrawColor enabledColor__,
                                 DrawColor disabledColor__) {
  menuItems_.push_back(new ListMenuItem(label__,
                                    optionID__,
                                    callback__,
                                    enabled__,
                                    enabledColor__,
                                    disabledColor__));
  
}
  
ListMenuItem& ListMenuWindowArea::getItem(int itemNum) {
  ListMenuItemCollection::iterator it = menuItems_.begin();
  for (int i = 0; i < itemNum; i++) {
    ++it;
  }
  return *(*it);
}
  
void ListMenuWindowArea::removeItem(int itemNum) {
  ListMenuItemCollection::iterator it = menuItems_.begin();
  for (int i = 0; i < itemNum; i++) {
    ++it;
  }
  delete (*it);
  menuItems_.erase(it);
}


  
void ListMenuWindowArea::reloadItems() {
  // Destroy all items
  for (ListMenuItemCollection::iterator it = menuItems_.begin();
       it != menuItems_.end();
       it++) {
    delete (*it);
  }
  menuItems_.clear();
  
  // Load items
  loadItems();
  
  if (selectedItemNum_ > menuItems_.size()) {
    selectedItemNum_ = menuItems_.size() - 1;
  }
  
  needsRedraw_ = true;
}
  
void ListMenuWindowArea::loadItems() {
  
}
                     
void ListMenuWindowArea::drawItem(ListMenuItem& menuItem,
                                  DrawableSurface& drawable,
                                  int xOffset,
                                  int yOffset) {
  WritePosition writePos(xOffset, yOffset);
  
  DrawColor color = menuItem.enabledColor();
  if (!menuItem.enabled()) {
    color = menuItem.disabledColor();
  }
  
  gameMemory_.fontCore().writeMessage(
                        menuItem.label(),
                        font_,
                        fontSize_,
                        drawable,
                        writePos,
                        color);
}


}; 
