#include "logic/BorderResourceIDs.h"

namespace Luncheon {


BorderResourceIDs::~BorderResourceIDs() { };
  
BorderResourceIDs::BorderResourceIDs(
                    ResourceID borderHorizontalID__,
                    ResourceID borderVerticalID__,
                    ResourceID borderTopLeftCornerID__,
                    ResourceID borderTopRightCornerID__,
                    ResourceID borderBottomLeftCornerID__,
                    ResourceID borderBottomRightCornerID__,
                    ResourceID borderYPipeUpID__,
                    ResourceID borderYPipeDownID__,
                    ResourceID borderYPipeLeftID__,
                    ResourceID borderYPipeRightID__)
  : borderHorizontalID_(borderHorizontalID__),
    borderVerticalID_(borderVerticalID__),
    borderTopLeftCornerID_(borderTopLeftCornerID__),
    borderTopRightCornerID_(borderTopRightCornerID__),
    borderBottomLeftCornerID_(borderBottomLeftCornerID__),
    borderBottomRightCornerID_(borderBottomRightCornerID__),
    borderYPipeUpID_(borderYPipeUpID__),
    borderYPipeDownID_(borderYPipeDownID__),
    borderYPipeLeftID_(borderYPipeLeftID__),
    borderYPipeRightID_(borderYPipeRightID__) { };
  
ResourceID BorderResourceIDs::borderHorizontalID() {
  return borderHorizontalID_;
}

ResourceID BorderResourceIDs::borderVerticalID() {
  return borderVerticalID_;
}

ResourceID BorderResourceIDs::borderTopLeftCornerID() {
  return borderTopLeftCornerID_;
}

ResourceID BorderResourceIDs::borderTopRightCornerID() {
  return borderTopRightCornerID_;
}

ResourceID BorderResourceIDs::borderBottomLeftCornerID() {
  return borderBottomLeftCornerID_;
}

ResourceID BorderResourceIDs::borderBottomRightCornerID() {
  return borderBottomRightCornerID_;
}

ResourceID BorderResourceIDs::borderYPipeUpID() {
  return borderYPipeUpID_;
}

ResourceID BorderResourceIDs::borderYPipeDownID() {
  return borderYPipeDownID_;
}

ResourceID BorderResourceIDs::borderYPipeLeftID() {
  return borderYPipeLeftID_;
}

ResourceID BorderResourceIDs::borderYPipeRightID() {
  return borderYPipeRightID_;
}



}; 
