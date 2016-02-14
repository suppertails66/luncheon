#ifndef ANIMATION_H
#define ANIMATION_H


#include "animation/AnimationFrameCollection.h"
#include "animation/AnimationFrame.h"
#include "graphics/GraphicSurface.h"
#include "timing/GTick.h"

namespace Luncheon {


class Animation {
public:
  virtual ~Animation();
  
  AnimationFrameCollection& frames();
  
  const AnimationFrameCollection& frames() const;
  
  virtual void addFrame(AnimationFrame* frame);
  
  // Probably will remove this
  virtual void addFrame(GraphicSurface* surface,
                        GTick duration,
                        int xOffset,
                        int yOffset) =0;
                        
  virtual bool looping() const =0;
  virtual void setLooping(bool looping__) =0;
  
  virtual int loopStart() const =0;
  virtual void setLoopStart(int loopStart__) =0;
  
  virtual int loopEnd() const =0;
  virtual void setLoopEnd(int loopEnd__) =0;
  
protected:
  Animation();
  
  AnimationFrameCollection frames_;
};


};


#endif 
