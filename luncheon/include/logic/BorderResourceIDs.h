#ifndef BORDERRESOURCEIDS_H
#define BORDERRESOURCEIDS_H


#include "resource/ResourceID.h"

namespace Luncheon {


class BorderResourceIDs {
public:
  virtual ~BorderResourceIDs();
  
  BorderResourceIDs(ResourceID borderHorizontalID__,
                    ResourceID borderVerticalID__,
                    ResourceID borderTopLeftCornerID__,
                    ResourceID borderTopRightCornerID__,
                    ResourceID borderBottomLeftCornerID__,
                    ResourceID borderBottomRightCornerID__,
                    ResourceID borderYPipeUpID__,
                    ResourceID borderYPipeDownID__,
                    ResourceID borderYPipeLeftID__,
                    ResourceID borderYPipeRightID__);
  
  ResourceID borderHorizontalID();
  ResourceID borderVerticalID();
  ResourceID borderTopLeftCornerID();
  ResourceID borderTopRightCornerID();
  ResourceID borderBottomLeftCornerID();
  ResourceID borderBottomRightCornerID();
  ResourceID borderYPipeUpID();
  ResourceID borderYPipeDownID();
  ResourceID borderYPipeLeftID();
  ResourceID borderYPipeRightID();
  
protected:

  ResourceID borderHorizontalID_;
  ResourceID borderVerticalID_;
  ResourceID borderTopLeftCornerID_;
  ResourceID borderTopRightCornerID_;
  ResourceID borderBottomLeftCornerID_;
  ResourceID borderBottomRightCornerID_;
  ResourceID borderYPipeUpID_;
  ResourceID borderYPipeDownID_;
  ResourceID borderYPipeLeftID_;
  ResourceID borderYPipeRightID_;

};


};


#endif 
