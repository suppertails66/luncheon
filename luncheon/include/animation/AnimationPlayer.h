#ifndef ANIMATIONPLAYER_H
#define ANIMATIONPLAYER_H


#include "timing/GTick.h"
#include "animation/AnimationFrame.h"
#include "animation/Animation.h"
#include "util/DumbPointer.h"

namespace Luncheon {


class AnimationPlayer {
public:
  virtual ~AnimationPlayer();
  
  virtual void seekToFrame(int frameNum) =0;
  
  virtual void advance(GTick time) =0;
  
  virtual AnimationFrame& currentFrame() =0;
  
  virtual void reset() =0;
  
  virtual int currentFrameNum() =0;
  virtual void setCurrentFrameNum(int currentFrameNum__) =0;
  
  virtual int currentFrameTimer() =0;
  virtual void setCurrentFrameTimer(int currentFrameTimer__) =0;
  
  virtual double speed();
  virtual void setSpeed(double speed__);
protected:
  AnimationPlayer();
  
  AnimationPlayer(Animation* sourceAnimation__);
  
  DumbPointer<Animation> sourceAnimation_;
  
  double speed_;
};


};


#endif
