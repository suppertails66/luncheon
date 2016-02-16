#include "logic/ListMenuItem.h"

namespace Luncheon {


ListMenuItem::~ListMenuItem() {
  delete callback_;
}
  
ListMenuItem::ListMenuItem(const std::string& label__,
                           int optionID__,
                           ListMenuItemFunctor* callback__,
                           bool enabled__)
  : label_(label__),
    optionID_(optionID__),
    callback_(callback__),
    enabled_(enabled__),
    enabledColor_(0, 0, 0, 255),
    disabledColor_(160, 160, 160, 255) { };
  
ListMenuItem::ListMenuItem(const std::string& label__,
                           int optionID__,
                           ListMenuItemFunctor* callback__,
                           bool enabled__,
                           DrawColor enabledColor__,
                           DrawColor disabledColor__)
  : label_(label__),
    optionID_(optionID__),
    callback_(callback__),
    enabled_(enabled__),
    enabledColor_(enabledColor__),
    disabledColor_(disabledColor__) { };
  
const std::string& ListMenuItem::label() {
  return label_;
}

void ListMenuItem::setLabel(const std::string& label__) {
  label_ = label__;
}

int ListMenuItem::optionID() {
  return optionID_;
}

void ListMenuItem::setOptionID(int optionID__) {
  optionID_ = optionID__;
}
  
ListMenuItemFunctor& ListMenuItem::callback() {
  return *callback_;
}

bool ListMenuItem::enabled() {
  return enabled_;
}

void ListMenuItem::setEnabled(bool enabled__) {
  enabled_ = enabled__;
}
  
DrawColor ListMenuItem::enabledColor() {
  return enabledColor_;
}

void ListMenuItem::setEnabledColor(DrawColor enabledColor__) {
  enabledColor_ = enabledColor__;
}

DrawColor ListMenuItem::disabledColor() {
  return disabledColor_;
}

void ListMenuItem::setDisabledColor(DrawColor disabledColor__) {
  disabledColor_ = disabledColor__;
}


}; 
