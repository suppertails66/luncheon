#include "animation/Animation.h"

namespace Luncheon {


Animation::~Animation() {
  // Destroy all contained frames
  for (AnimationFrameCollection::iterator it = frames_.begin();
       it != frames_.end();
       it++) {
    delete (*it);
  }
}

Animation::Animation() { };

AnimationFrameCollection& Animation::frames() {
  return frames_;
}
  
const AnimationFrameCollection& Animation::frames() const {
  return frames_;
}
  
void Animation::addFrame(AnimationFrame* frame) {
  frames_.insert(frames_.end(), frame);
}


};
