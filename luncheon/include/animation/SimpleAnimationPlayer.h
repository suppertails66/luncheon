#ifndef SIMPLEANIMATIONPLAYER_H
#define SIMPLEANIMATIONPLAYER_H


#include "animation/AnimationPlayer.h"
#include "animation/Animation.h"
#include "timing/GTick.h"

namespace Luncheon {


class SimpleAnimationPlayer : public AnimationPlayer {
public:
  virtual ~SimpleAnimationPlayer();
  
  SimpleAnimationPlayer();
  
  SimpleAnimationPlayer(Animation* sourceAnimation__);
  
  // Abstract implementations
  
  virtual void advance(GTick time);
  
  virtual void seekToFrame(int frameNum);
  
  virtual AnimationFrame& currentFrame();
  
  virtual void reset();
  
  // Extensions
  
  virtual int currentFrameNum();
  virtual void setCurrentFrameNum(int currentFrameNum__);
  
  virtual int currentFrameTimer();
  virtual void setCurrentFrameTimer(int currentFrameTimer__);
  
protected:
  
  int currentFrameNum_;
  GTick currentFrameTimer_;
  
};


};


#endif
