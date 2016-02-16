#include "graphics/GameWindow.h"
#include "graphics/GraphicSurface.h"
#include <iostream>

namespace Luncheon {


GameWindow::~GameWindow() {
  delete screenBuffer_;
}

ScreenBuffer& GameWindow::screenBuffer() {
  return *screenBuffer_;
}
  
GameWindowModes::GameWindowMode GameWindow::displayMode() {
  return displayMode_;
}
void GameWindow::setDisplayMode(GameWindowModes::GameWindowMode
  displayMode__) {
  displayMode_ = displayMode__; 
}

GameWindow::GameWindow(GraphicsCore& graphicsCore__)
  : graphicsCore_(graphicsCore__),
    screenBuffer_(0),
    displayMode_(GameWindowModes::windowed) { };


}; 
