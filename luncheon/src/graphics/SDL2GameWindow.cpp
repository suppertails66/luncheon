#ifdef LUNCHEON_ENABLE_SDL2

#include "SDL.h"
#include "graphics/SDL2GameWindow.h"
#include "graphics/SDL2GraphicSurface.h"
#include "graphics/SDL2ScreenBuffer.h"
#include <string>
#include <iostream>

namespace Luncheon {


SDL2GameWindow::~SDL2GameWindow() {
  SDL_DestroyWindow(nativeWindow_);
}

SDL2GameWindow::SDL2GameWindow(GraphicsCore& graphicsCore__)
  : GameWindow(graphicsCore__),
    nativeWindow_(0) { };

void SDL2GameWindow::createWindow(int w,
                          int h,
                          int x,
                          int y,
                          int nativeW,
                          int nativeH) {
                          
  nativeWindow_ = SDL_CreateWindow("",
                                   /*SDL_WINDOWPOS_UNDEFINED*/x,
                                   /*SDL_WINDOWPOS_UNDEFINED*/y,
                                   w,
                                   h,
                                   SDL_WINDOW_OPENGL);
                                   
//  renderer_ = SDL_CreateRenderer(nativeWindow_, -1, 0);
  
  // set renderer's logical size to native resolution
//  SDL_RenderSetLogicalSize(renderer_, nativeW, nativeH);
/*  // fill with red
  SDL_SetRenderDrawColor(renderer_, 255, 0, 0, 255);
  SDL_RenderClear(renderer_);
  // blue dot
  SDL_SetRenderDrawColor(renderer_, 0, 0, 255, 255);
  SDL_Rect col;
  col.x = 2;
  col.y = 2;
  col.w = 2;
  col.h = 2;
  SDL_RenderFillRect(renderer_, &col); */
  
  screenBuffer_ = new SDL2ScreenBuffer(*this,
                                  w,
                                  h,
                                  nativeW,
                                  nativeH);
  
/*  // Test: fill up the native screen with some pixel data
  // and see what happens                                
  SDL_Texture& rawtex = static_cast<SDL2GraphicSurface*>(nativeScreen_)->texture();
  int pixsize = nativeW * nativeH * 8 * 4;
  unsigned char* testPixels = new unsigned char[pixsize];
  for (int i = 0; i < pixsize; i += 4) {
    // blue
    testPixels[i] = 255;
    // green
    testPixels[i + 1] = 0;
    // red
    testPixels[i + 2] = 0;
    // alpha
    testPixels[i + 3] = 0;
    
    if (i % 400 == 0) {
      // blue
      testPixels[i] = 0;
      // green
      testPixels[i + 1] = 0;
      // red
      testPixels[i + 2] = 255;
      // alpha
      testPixels[i + 3] = 0;
    }
  }
  SDL_UpdateTexture(&rawtex,
                    NULL,
                    (void*)testPixels,
                    nativeW * 4);
  delete testPixels; */
}
                          
void SDL2GameWindow::changeWindowTitle(const std::string& title) {
  SDL_SetWindowTitle(nativeWindow_,
                     title.c_str());
}

std::string SDL2GameWindow::getWindowTitle() const {
  return std::string(SDL_GetWindowTitle(nativeWindow_));
}

void SDL2GameWindow::flipToVisibleScreen() {
//  SDL_RenderClear(renderer_);
//  SDL_RenderCopy(renderer_, 
//                 &(static_cast<SDL2GraphicSurface*>(nativeScreen_)->texture()),
//                 NULL,
//                 NULL);

//  SDL_RenderPresent(renderer_);
  
  screenBuffer_->flip();
}

void SDL2GameWindow::updateDisplayMode() {

}
  
SDL_Window& SDL2GameWindow::nativeWindow() {
  return *nativeWindow_;
}
  
int SDL2GameWindow::getWidth() {
  int width;
  SDL_GetWindowSize(nativeWindow_,
                    &width,
                    NULL);
  return width;
}

int SDL2GameWindow::getHeight() {
  int height;
  SDL_GetWindowSize(nativeWindow_,
                    NULL,
                    &height);
  return height;
}

int SDL2GameWindow::getNativeWidth() {
  return screenBuffer_->getNativeWidth();
}

int SDL2GameWindow::getNativeHeight() {
  return screenBuffer_->getNativeHeight();
}
  
/*void SDL2GameWindow::changeResolution(int w, int h) {
  SDL_SetWindowSize(nativeWindow_,
                    w,
                    h);
} */


}; 

#endif