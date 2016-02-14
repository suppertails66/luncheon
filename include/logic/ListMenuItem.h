#ifndef LISTMENUITEM_H
#define LISTMENUITEM_H


#include "ListMenuItemFunctor.h"
#include "graphics/DrawColor.h"
#include <string>

namespace Luncheon {


class ListMenuItem {
public:
  virtual ~ListMenuItem();
  
  ListMenuItem(const std::string& label__,
               int optionID__,
               ListMenuItemFunctor* callback__,
               bool enabled__ = true);
  
  ListMenuItem(const std::string& label__,
               int optionID__,
               ListMenuItemFunctor* callback__,
               bool enabled__,
               DrawColor enabledColor__,
               DrawColor disabledColor__);
  
  virtual const std::string& label();
  virtual void setLabel(const std::string& label__);
  
  virtual int optionID();
  virtual void setOptionID(int optionID__);
  
  virtual ListMenuItemFunctor& callback();
  
  virtual bool enabled();
  virtual void setEnabled(bool enabled__);
  
  virtual DrawColor enabledColor();
  virtual void setEnabledColor(DrawColor enabledColor__);
  
  virtual DrawColor disabledColor();
  virtual void setDisabledColor(DrawColor disabledColor__);
  
protected:
  std::string label_;
  
  int optionID_;
  
  ListMenuItemFunctor* callback_;
  
  bool enabled_;
  
  DrawColor enabledColor_;
  
  DrawColor disabledColor_;

};


};


#endif 
