#ifndef SIMPLEANIMATION_H
#define SIMPLEANIMATION_H


#include "animation/Animation.h"
#include "timing/GTick.h"

namespace Luncheon {


class SimpleAnimation : public Animation {
public:
  virtual ~SimpleAnimation();
  
  SimpleAnimation();
  
  // Probably will remove or protect this
  virtual void addFrame(GraphicSurface* surface,
                        GTick duration,
                        int xOffset,
                        int yOffset);
                        
  virtual bool looping() const;
  virtual void setLooping(bool looping__);
  
  virtual int loopStart() const;
  virtual void setLoopStart(int loopStart__);
  
  virtual int loopEnd() const;
  virtual void setLoopEnd(int loopEnd__);
protected:
  
  bool looping_;
  int loopStart_;
  int loopEnd_;
  
  // Set to true after a call to setLoopEnd();
  // until the end point is manually set, the
  // last frame is always treated as the loop point
  bool manualLoopEnd_;
  
};


};


#endif 
