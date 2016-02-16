#include "animation/SimpleAnimationPlayer.h"
#include "timing/GTick.h"
#include "animation/SimpleAnimationFrame.h"
#include <iostream>

namespace Luncheon {


SimpleAnimationPlayer::~SimpleAnimationPlayer() { };
  
SimpleAnimationPlayer::SimpleAnimationPlayer()
  : AnimationPlayer(),
    currentFrameNum_(0),
    currentFrameTimer_(0) { };

SimpleAnimationPlayer::SimpleAnimationPlayer(Animation* sourceAnimation__)
  : AnimationPlayer(sourceAnimation__),
    currentFrameNum_(0),
    currentFrameTimer_(0) { };

// Abstract implementations

void SimpleAnimationPlayer::advance(GTick time) {
  Animation& animation = sourceAnimation_.reference();
  
  // do nothing if animation is empty
  if (!animation.frames().size()) {
    return;
  }

  currentFrameTimer_ += (time * speed_);
  
  // Continually advance through frames until we reach
  // the one that should be displayed after the given time
  // has passed
  while (currentFrameTimer_ >= animation.frames()[currentFrameNum_]->duration()) {
    AnimationFrame& currentFrame = *(animation.frames()[currentFrameNum_]);
    currentFrameTimer_ -= currentFrame.duration();
    
    if (animation.looping() 
     && currentFrameNum_ == animation.loopEnd()) {
      // Reached end of loop: go to beginning
      currentFrameNum_ = animation.loopStart();
    }
    else {
      if (currentFrameNum_ == 
        static_cast<int>(animation.frames().size()) - 1) {
        // Reached end of animation and not looping (or loop points are bad):
        // remain on final frame indefinitely
      }
      else {
        // Go to next frame
        ++currentFrameNum_;
      }
    }
  }
}
  
void SimpleAnimationPlayer::seekToFrame(int frameNum) {
  currentFrameTimer_ = 0;
  currentFrameNum_ = frameNum;
}

AnimationFrame& SimpleAnimationPlayer::currentFrame() {
  return *(sourceAnimation_.reference().frames()[currentFrameNum_]);
}
  
void SimpleAnimationPlayer::reset() {
  currentFrameTimer_ = 0;
  currentFrameNum_ = 0;
}
  
int SimpleAnimationPlayer::currentFrameNum() {
  return currentFrameNum_;
}
void SimpleAnimationPlayer::setCurrentFrameNum(int currentFrameNum__) {
  currentFrameNum_ = currentFrameNum__;
}
  
int SimpleAnimationPlayer::currentFrameTimer() {
  return currentFrameTimer_;
}
void SimpleAnimationPlayer::setCurrentFrameTimer(int currentFrameTimer__) {
  currentFrameTimer_ = currentFrameTimer__;
}


}; 
