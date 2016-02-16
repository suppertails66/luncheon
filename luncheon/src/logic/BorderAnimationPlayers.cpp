#include "logic/BorderAnimationPlayers.h"

namespace Luncheon {


BorderAnimationPlayers::~BorderAnimationPlayers() {
  delete borderHorizontalPlayer_;
  delete borderVerticalPlayer_;
  delete borderTopLeftCornerPlayer_;
  delete borderTopRightCornerPlayer_;
  delete borderBottomLeftCornerPlayer_;
  delete borderBottomRightCornerPlayer_;
}
  
BorderAnimationPlayers::BorderAnimationPlayers(
                       GraphicsCore& graphicsCore,
                       BorderResourceIDs borderResourceIDs)
  : borderHorizontalPlayer_(
      graphicsCore.createAnimationPlayer(
        borderResourceIDs.borderHorizontalID())),
    borderVerticalPlayer_(
      graphicsCore.createAnimationPlayer(
        borderResourceIDs.borderVerticalID())),
    borderTopLeftCornerPlayer_(
      graphicsCore.createAnimationPlayer(
        borderResourceIDs.borderTopLeftCornerID())),
    borderTopRightCornerPlayer_(
      graphicsCore.createAnimationPlayer(
        borderResourceIDs.borderTopRightCornerID())),
    borderBottomLeftCornerPlayer_(
      graphicsCore.createAnimationPlayer(
        borderResourceIDs.borderBottomLeftCornerID())),
    borderBottomRightCornerPlayer_(
      graphicsCore.createAnimationPlayer(
        borderResourceIDs.borderBottomRightCornerID())),
    borderYPipeUpPlayer_(
      graphicsCore.createAnimationPlayer(
        borderResourceIDs.borderYPipeUpID())),
    borderYPipeDownPlayer_(
      graphicsCore.createAnimationPlayer(
        borderResourceIDs.borderYPipeDownID())),
    borderYPipeLeftPlayer_(
      graphicsCore.createAnimationPlayer(
        borderResourceIDs.borderYPipeLeftID())),
    borderYPipeRightPlayer_(
      graphicsCore.createAnimationPlayer(
        borderResourceIDs.borderYPipeRightID())) { };
  
BorderAnimationPlayers::BorderAnimationPlayers(
                         AnimationPlayer* borderHorizontalPlayer__,
                         AnimationPlayer* borderVerticalPlayer__,
                         AnimationPlayer* borderTopLeftCornerPlayer__,
                         AnimationPlayer* borderTopRightCornerPlayer__,
                         AnimationPlayer* borderBottomLeftCornerPlayer__,
                         AnimationPlayer* borderBottomRightCornerPlayer__)
  : borderHorizontalPlayer_(borderHorizontalPlayer__),
    borderVerticalPlayer_(borderVerticalPlayer__),
    borderTopLeftCornerPlayer_(borderTopLeftCornerPlayer__),
    borderTopRightCornerPlayer_(borderTopRightCornerPlayer__),
    borderBottomLeftCornerPlayer_(borderBottomLeftCornerPlayer__),
    borderBottomRightCornerPlayer_(borderBottomRightCornerPlayer__) { };
                         
AnimationPlayer& BorderAnimationPlayers::borderHorizontalPlayer() {
  return *borderHorizontalPlayer_;
}

AnimationPlayer& BorderAnimationPlayers::borderVerticalPlayer() {
  return *borderVerticalPlayer_;
}

AnimationPlayer& BorderAnimationPlayers::borderTopLeftCornerPlayer() {
  return *borderTopLeftCornerPlayer_;
}

AnimationPlayer& BorderAnimationPlayers::borderTopRightCornerPlayer() {
  return *borderTopRightCornerPlayer_;
}

AnimationPlayer& BorderAnimationPlayers::borderBottomLeftCornerPlayer() {
  return *borderBottomLeftCornerPlayer_;
}

AnimationPlayer& BorderAnimationPlayers::borderBottomRightCornerPlayer() {
  return *borderBottomRightCornerPlayer_;
}

AnimationPlayer& BorderAnimationPlayers::borderYPipeUpPlayer() {
  return *borderYPipeUpPlayer_;
}

AnimationPlayer& BorderAnimationPlayers::borderYPipeDownPlayer() {
  return *borderYPipeDownPlayer_;
}

AnimationPlayer& BorderAnimationPlayers::borderYPipeLeftPlayer() {
  return *borderYPipeLeftPlayer_;
}

AnimationPlayer& BorderAnimationPlayers::borderYPipeRightPlayer() {
  return *borderYPipeRightPlayer_;
}


}; 
