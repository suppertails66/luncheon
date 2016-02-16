#include "animation/AnimationPlayer.h"
#include "util/DumbPointer.h"

namespace Luncheon {


AnimationPlayer::~AnimationPlayer() { };

AnimationPlayer::AnimationPlayer()
  : sourceAnimation_(0),
    speed_(1.00) { };
  
AnimationPlayer::AnimationPlayer(Animation* sourceAnimation__)
  : sourceAnimation_(sourceAnimation__),
    speed_(1.00) { };
  
double AnimationPlayer::speed() {
  return speed_;
}

void AnimationPlayer::setSpeed(double speed__) {
  speed_ = speed__;
}


}; 
