#include "logic/BorderedWindow.h"
#include "logic/WindowArea.h"
#include <iostream>

namespace Luncheon {


BorderedWindow::~BorderedWindow() {
  delete borderAnimationPlayers_;
//  delete backgroundAnimationPlayer_;
}
  
BorderedWindow::BorderedWindow(GameMemory& gameMemory__,
                               GameScene& parent__,
                               WindowArea* windowArea__,
                               WindowArea* parentWindowArea__,
                               RectArea dimensions__,
                               int borderHorizontalWidth__,
                               int borderVerticalWidth__,
                               BorderResourceIDs borderResourceIDs,
                               DrawColor backgroundColor__/*,
                               ResourceID backgroundID*/)
  : Window(gameMemory__,
           parent__,
           windowArea__,
           parentWindowArea__,
           dimensions__),
    borderHorizontalWidth_(borderHorizontalWidth__),
    borderVerticalWidth_(borderVerticalWidth__),
    borderAnimationPlayers_(new BorderAnimationPlayers(
                              gameMemory__.graphicsCore(),
                              borderResourceIDs)),
    backgroundColor_(backgroundColor__)
    /*backgroundAnimationEnabled(false),
    backgroundAnimationPlayer_(gameMemory__.graphicsCore()
                               .createAnimationPlayer(backgroundID))*/ { };
  
/*BorderedWindow::BorderedWindow(GameMemory& gameMemory__,
                               GameScene& parent__,
                               WindowArea* windowArea__,
                               RectArea dimensions__,
                               int borderHorizontalWidth__,
                               int borderVerticalWidth__,
                               BorderAnimationPlayers* borderAnimationPlayers__)
  : Window(gameMemory__,
           parent__,
           windowArea__,
           dimensions__),
    borderHorizontalWidth_(borderHorizontalWidth__),
    borderVerticalWidth_(borderVerticalWidth__),
    borderAnimationPlayers_(borderAnimationPlayers__) { }; */

void BorderedWindow::updateWindow(GTick ticks) {
  windowArea_->update(ticks);
  
  // Advance border animations
  advancePlayers(ticks);
//  backgroundAnimationPlayer_->advance(ticks);

}

void BorderedWindow::drawWindow(ScreenBuffer& buffer) {
  // Draw background
  drawBackground(buffer);

  // Draw border
  drawBorder(buffer);
  
  // Don't draw window area (or child windows) if hidden
  if (hideContent_) {
    return;
  }

  // Set clip window if enabled
  // (ensure everything within borders is clipped)
  bool hasClip = buffer.hasClipArea();
  ClipArea oldClipArea = buffer.getClipArea();
  if (clipping_) {
    buffer.setClipArea(ClipArea(contentX(),
                                contentY(),
                                contentW(),
                                contentH()));
  }
  
  drawContent(buffer);
  
  // Restore old clip area
  if (clipping_) {
    if (!hasClip) {
      buffer.clearClipArea();
    }
    else {
      buffer.setClipArea(oldClipArea);
    }
  }
}

void BorderedWindow::drawContent(ScreenBuffer& buffer) {
  windowArea_->draw(buffer);
}

int BorderedWindow::contentX() {
  return x_ + borderHorizontalWidth_;
}

int BorderedWindow::contentY() {
  return y_ + borderVerticalWidth_;
}

int BorderedWindow::contentW() {
  return w_ - (borderHorizontalWidth_ * 2);
}

int BorderedWindow::contentH() {
  return h_ - (borderVerticalWidth_ * 2);
}
  
int BorderedWindow::borderHorizontalWidth() {
  return borderHorizontalWidth_;
}

int BorderedWindow::borderVerticalWidth() {
  return borderVerticalWidth_;
}
  
DrawColor BorderedWindow::backgroundColor() {
  return backgroundColor_;
}

void BorderedWindow::setBackgroundColor(DrawColor backgroundColor__) {
  backgroundColor_ = backgroundColor__;
}
  
void BorderedWindow::drawBorder(ScreenBuffer& buffer) {
  // Top left corner
  buffer.draw(borderAnimationPlayers_->
                borderTopLeftCornerPlayer().currentFrame().graphic(),
              x(),
              y());
  
  // Top right corner
  buffer.draw(borderAnimationPlayers_->
                borderTopRightCornerPlayer().currentFrame().graphic(),
              contentX() + contentW(),
              y());
              
  // Bottom left corner
  buffer.draw(borderAnimationPlayers_->
                borderBottomLeftCornerPlayer().currentFrame().graphic(),
              x(),
              contentY() + contentH());
              
  // Bottom right corner
  buffer.draw(borderAnimationPlayers_->
                borderBottomRightCornerPlayer().currentFrame().graphic(),
              contentX() + contentW(),
              contentY() + contentH());
              
  // Horizontal frames
  int horizontalWidth = borderAnimationPlayers_->borderHorizontalPlayer()
                          .currentFrame().graphic().getWidth();
  int numHorizontalBlits = contentW() / horizontalWidth;
  for (int i = 0; i < numHorizontalBlits; i++) {
    // Top
    buffer.draw(borderAnimationPlayers_->
                  borderHorizontalPlayer().currentFrame().graphic(),
                contentX() + i * horizontalWidth,
                y());
    // Bottom
    buffer.draw(borderAnimationPlayers_->
                  borderHorizontalPlayer().currentFrame().graphic(),
                contentX() + i * horizontalWidth,
                contentY() + contentH());
  }
              
  // Vertical frames
  int verticalHeight = borderAnimationPlayers_->borderVerticalPlayer()
                          .currentFrame().graphic().getHeight();
  int numVerticalBlits = contentH() / verticalHeight;
  for (int i = 0; i < numVerticalBlits; i++) {
    // Top
    buffer.draw(borderAnimationPlayers_->
                  borderVerticalPlayer().currentFrame().graphic(),
                x(),
                contentY() + i * verticalHeight);
    // Bottom
    buffer.draw(borderAnimationPlayers_->
                  borderVerticalPlayer().currentFrame().graphic(),
                contentX() + contentW(),
                contentY() + i * verticalHeight);
  }
}
  
void BorderedWindow::drawBackground(ScreenBuffer& buffer) {
  // Set clip window if enabled
  // (ensure everything within borders is clipped)
/*  bool hasClip = buffer.hasClipArea();
  ClipArea oldClipArea = buffer.getClipArea();
  if (clipping_) {
    buffer.setClipArea(ClipArea(contentX(),
                                contentY(),
                                contentW(),
                                contentH()));
  } */
  
/*  GraphicSurface& graphic = backgroundAnimationPlayer_->currentFrame().graphic();
  for (int i = 0; i < contentW()/graphic.getWidth(); i++) {
    for (int j = 0; j < contentH()/graphic.getHeight(); j++) {
      buffer.draw(graphic,
                  contentX() + (i * graphic.getWidth()),
                  contentY() + (j * graphic.getHeight()));
    }
  }*/
  buffer.drawRect(backgroundColor_,
                  RectArea(contentX(),
                           contentY(),
                           contentW(),
                           contentH()));
  
  // Restore old clip area
/*  if (clipping_) {
    if (!hasClip) {
      buffer.clearClipArea();
    }
    else {
      buffer.setClipArea(oldClipArea);
    }
  } */
}
  
void BorderedWindow::advancePlayers(GTick ticks) {
  borderAnimationPlayers_->borderHorizontalPlayer().advance(ticks);
  borderAnimationPlayers_->borderVerticalPlayer().advance(ticks);
  borderAnimationPlayers_->borderTopLeftCornerPlayer().advance(ticks);
  borderAnimationPlayers_->borderTopRightCornerPlayer().advance(ticks);
  borderAnimationPlayers_->borderBottomLeftCornerPlayer().advance(ticks);
  borderAnimationPlayers_->borderBottomRightCornerPlayer().advance(ticks);
}


};
