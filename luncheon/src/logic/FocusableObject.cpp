#include "logic/FocusableObject.h"
#include <iostream>

namespace Luncheon {


FocusableObject::~FocusableObject() {
//  destroyChildFocusable();
  delete childFocusable_;
}

FocusableObject::FocusableObject(GameMemory& gameMemory__,
                                 GameScene& parent__)
  : GameObject(gameMemory__,
               parent__),
    hasFocus_(false),
    focusWasReturned_(false),
    sourceOfFocus_(0),
    targetOfFocus_(0),
    childFocusable_(0) { };
  
bool FocusableObject::hasFocus() {
  return hasFocus_;
}

void FocusableObject::setHasFocus(bool hasFocus__) {
  hasFocus_ = hasFocus__;
}
  
bool FocusableObject::focusWasReturned() {
  return focusWasReturned_;
}

void FocusableObject::setFocusWasReturned(bool focusWasReturned__) {
  focusWasReturned_ = focusWasReturned__;
}

FocusableObject* FocusableObject::sourceOfFocus() {
  return sourceOfFocus_;
}

void FocusableObject::setSourceOfFocus(FocusableObject* sourceOfFocus__) {
  sourceOfFocus_ = sourceOfFocus__;
}

FocusableObject* FocusableObject::targetOfFocus() {
  return targetOfFocus_;
}

void FocusableObject::setTargetOfFocus(FocusableObject* targetOfFocus__) {
  targetOfFocus_ = targetOfFocus__;
}
  
void FocusableObject::giveFocus(FocusableObject* source) {
  hasFocus_ = true;
  focusWasReturned_ = false;
  source->setHasFocus(false);
  source->setFocusWasReturned(false);
  source->setTargetOfFocus(this);
  sourceOfFocus_ = source;
}
  
void FocusableObject::returnFocus() {
  if (sourceOfFocus_ != 0 && hasFocus_) {
    hasFocus_ = false;
    focusWasReturned_ = false;
    sourceOfFocus_->setHasFocus(true);
    sourceOfFocus_->setFocusWasReturned(true);
    sourceOfFocus_->setTargetOfFocus(0);
    sourceOfFocus_ = 0;
  }
}
  
bool FocusableObject::hasChildFocusable() {
  return (childFocusable_ != 0);
}
  
void FocusableObject::changeChildFocusable(
                            FocusableObject* childFocusable__) {
  if (childFocusable_ != 0) {
    childFocusable_->returnFocus();
  }
  delete childFocusable_;
  childFocusable_ = childFocusable__;
  childFocusable_->giveFocus(this);
  
}

void FocusableObject::destroyChildFocusable() {
  if (childFocusable_ != 0) {
    childFocusable_->returnFocus();
  }
  delete childFocusable_;
  childFocusable_ = 0;
}
  
FocusableObject& FocusableObject::childFocusable() {
  return *childFocusable_;
}


}; 
