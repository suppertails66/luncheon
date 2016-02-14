#ifndef BORDERANIMATIONPLAYERS_H
#define BORDERANIMATIONPLAYERS_H


#include "animation/AnimationPlayer.h"
#include "resource/ResourceID.h"
#include "graphics/GraphicsCore.h"
#include "logic/BorderResourceIDs.h"

namespace Luncheon {


class BorderAnimationPlayers {
public:
  virtual ~BorderAnimationPlayers();
  
  BorderAnimationPlayers(GraphicsCore& graphicsCore,
                         BorderResourceIDs borderResourceIDs);
  
  BorderAnimationPlayers(AnimationPlayer* borderHorizontalPlayer__,
                         AnimationPlayer* borderVerticalPlayer__,
                         AnimationPlayer* borderTopLeftCornerPlayer__,
                         AnimationPlayer* borderTopRightCornerPlayer__,
                         AnimationPlayer* borderBottomLeftCornerPlayer__,
                         AnimationPlayer* borderBottomRightCornerPlayer__);
                         
  virtual AnimationPlayer& borderHorizontalPlayer();
  virtual AnimationPlayer& borderVerticalPlayer();
  virtual AnimationPlayer& borderTopLeftCornerPlayer();
  virtual AnimationPlayer& borderTopRightCornerPlayer();
  virtual AnimationPlayer& borderBottomLeftCornerPlayer();
  virtual AnimationPlayer& borderBottomRightCornerPlayer();
  virtual AnimationPlayer& borderYPipeUpPlayer();
  virtual AnimationPlayer& borderYPipeDownPlayer();
  virtual AnimationPlayer& borderYPipeLeftPlayer();
  virtual AnimationPlayer& borderYPipeRightPlayer();
  
protected:
  AnimationPlayer* borderHorizontalPlayer_;
  AnimationPlayer* borderVerticalPlayer_;
  AnimationPlayer* borderTopLeftCornerPlayer_;
  AnimationPlayer* borderTopRightCornerPlayer_;
  AnimationPlayer* borderBottomLeftCornerPlayer_;
  AnimationPlayer* borderBottomRightCornerPlayer_;
  AnimationPlayer* borderYPipeUpPlayer_;
  AnimationPlayer* borderYPipeDownPlayer_;
  AnimationPlayer* borderYPipeLeftPlayer_;
  AnimationPlayer* borderYPipeRightPlayer_;
};


};


#endif 
