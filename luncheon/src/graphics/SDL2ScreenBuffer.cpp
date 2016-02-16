#include "graphics/SDL2ScreenBuffer.h"
#include "graphics/SDL2GraphicSurface.h"
#include "graphics/SDL2DrawableSurface.h"
#include "SDL.h"

namespace Luncheon {


SDL2ScreenBuffer::~SDL2ScreenBuffer() {
  SDL_DestroyRenderer(renderer_);
}

SDL2ScreenBuffer::SDL2ScreenBuffer(SDL2GameWindow& sourceWindow,
                                   int w,
                                   int h,
                                   int nativeW,
                                   int nativeH)
  : ScreenBuffer(),
    renderer_(0),
    hasClipArea_(false) {
  renderer_ = SDL_CreateRenderer(&sourceWindow.nativeWindow(),
                     -1,
                     0);
  SDL_RenderSetLogicalSize(renderer_, nativeW, nativeH);
}
  
void SDL2ScreenBuffer::lock() {
  locked_ = true;
}

void SDL2ScreenBuffer::unlock() {
  locked_ = false;
}

void SDL2ScreenBuffer::draw(GraphicSurface& source,
                            int x,
                            int y) {
  SDL2GraphicSurface& nativeSource = dynamic_cast<SDL2GraphicSurface&>(source);
  
  SDL_Rect dstRect;
  dstRect.x = x;
  dstRect.y = y;
  dstRect.w = source.getWidth();
  dstRect.h = source.getHeight();
  
  SDL_RenderCopy(renderer_,
                 &(nativeSource.texture()),
                 NULL,
                 &dstRect);
}

void SDL2ScreenBuffer::clear() {
  clear(DrawColor(0, 0, 0, SDL_ALPHA_OPAQUE));
}
                    
void SDL2ScreenBuffer::clear(DrawColor color) {
  SDL_SetRenderDrawColor(renderer_,
                      color.r(),
                      color.g(),
                      color.b(),
                      SDL_ALPHA_OPAQUE);
  SDL_RenderClear(renderer_);
}
  
void SDL2ScreenBuffer::draw(DrawableSurface& source,
                            int x,
                            int y) {
  SDL2DrawableSurface& nativeSource
    = dynamic_cast<SDL2DrawableSurface&>(source);
  
  SDL_Rect dstRect;
  dstRect.x = x;
  dstRect.y = y;
  dstRect.w = source.getWidth();
  dstRect.h = source.getHeight();
  
  SDL_RenderCopy(renderer_,
                 &(nativeSource.nativeSurfaceTexture()),
                 NULL,
                 &dstRect);
  
}
                    
void SDL2ScreenBuffer::drawRect(DrawColor color,
                                RectArea rect) {
  SDL_SetRenderDrawColor(renderer_,
                         color.r(),
                         color.g(),
                         color.b(),
                         color.a());
  
  // Temporarily enable alpha blending if needed
  SDL_BlendMode oldBlendMode;
  if (color.a() < 255) {
    SDL_GetRenderDrawBlendMode(renderer_,
			      &oldBlendMode);
    SDL_SetRenderDrawBlendMode(renderer_,
			      SDL_BLENDMODE_BLEND);
  }
  
  SDL_Rect nativeRect;
  nativeRect.x = rect.x();
  nativeRect.y = rect.y();
  nativeRect.w = rect.w();
  nativeRect.h = rect.h();
  SDL_RenderFillRect(renderer_,
                     &nativeRect);
  
  if (color.a() < 255) {
    SDL_SetRenderDrawBlendMode(renderer_,
			      oldBlendMode);
  }
}

void SDL2ScreenBuffer::flip() {
//  SDL_RenderCopy(renderer_, 
//                 &(dynamic_cast<SDL2GraphicSurface*>(nativeScreen_)->texture()),
//                 NULL,
//                 NULL);
  SDL_RenderPresent(renderer_);
}

SDL_Renderer& SDL2ScreenBuffer::renderer() {
  return *renderer_;
}
  
int SDL2ScreenBuffer::getNativeWidth() {
  int nativeWidth;
  SDL_RenderGetLogicalSize(renderer_,
                           &nativeWidth,
                           NULL);
  return nativeWidth;
}

int SDL2ScreenBuffer::getNativeHeight() {
  int nativeHeight;
  SDL_RenderGetLogicalSize(renderer_,
                           NULL,
                           &nativeHeight);
  return nativeHeight;
}
  
bool SDL2ScreenBuffer::hasClipArea() {
  return hasClipArea_;
}

ClipArea SDL2ScreenBuffer::getClipArea() {
  return clipArea_;
}

void SDL2ScreenBuffer::setClipArea(ClipArea area) {
  SDL_Rect rect;
  rect.x = area.x();
  rect.y = area.y();
  rect.w = area.w();
  rect.h = area.h();
  SDL_RenderSetClipRect(renderer_,
                        &rect);
  
  clipArea_ = area;
  hasClipArea_ = true;
}

void SDL2ScreenBuffer::clearClipArea() {

  SDL_RenderSetClipRect(renderer_,
                        0);

  clipArea_.setX(0);
  clipArea_.setY(0);
  clipArea_.setW(0);
  clipArea_.setH(0);
  hasClipArea_ = false;
}


};
