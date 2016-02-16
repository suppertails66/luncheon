#ifndef FOCUSABLEOBJECT_H
#define FOCUSABLEOBJECT_H

#include "logic/GameObject.h"

namespace Luncheon {


class FocusableObject : public GameObject {
public:
  virtual ~FocusableObject();
  
  virtual bool hasFocus();
  virtual void setHasFocus(bool hasFocus__);
  
  virtual bool focusWasReturned();
  virtual void setFocusWasReturned(bool focusWasReturned__);
  
  virtual FocusableObject* sourceOfFocus();
  virtual void setSourceOfFocus(FocusableObject* sourceOfFocus__);
  
  virtual FocusableObject* targetOfFocus();
  virtual void setTargetOfFocus(FocusableObject* targetOfFocus__);
  
  virtual void giveFocus(FocusableObject* source);
  
  virtual void returnFocus();
  
  virtual bool hasChildFocusable();
  
  virtual FocusableObject& childFocusable();
  
  virtual void changeChildFocusable(FocusableObject* childFocusable__);
  
  virtual void destroyChildFocusable();
protected:
  FocusableObject(GameMemory& gameMemory__,
                  GameScene& parent__);
                  
  bool hasFocus_;
  
  bool focusWasReturned_;
  
  FocusableObject* sourceOfFocus_;
  
  FocusableObject* targetOfFocus_;
  
  FocusableObject* childFocusable_;
};


};


#endif
