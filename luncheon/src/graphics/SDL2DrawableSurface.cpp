#ifdef LUNCHEON_ENABLE_SDL2

#include "graphics/SDL2DrawableSurface.h"
#include "graphics/DrawPosition.h"
#include "graphics/DrawColor.h"
#include "graphics/SDL2GraphicSurface.h"
#include "SDL.h"
#include <iostream>

namespace Luncheon {


SDL2DrawableSurface::~SDL2DrawableSurface() {
  SDL_FreeSurface(nativeSurface_);
  SDL_DestroyTexture(nativeSurfaceTexture_);
}

SDL2DrawableSurface::SDL2DrawableSurface(int w__,
                                         int h__,
                                         SDL_Renderer& renderer)
  : DrawableSurface(),
    nativeSurface_(0),
    nativeSurfaceTexture_(0) {
  nativeSurface_ = SDL_CreateRGBSurface(0,
                                       w__,
                                       h__,
                                       32,
                                       0x00FF0000,
                                       0x0000FF00,
                                       0x000000FF,
                                       0xFF000000);
                                       

  
/*  Uint32 clearColor = SDL_MapRGBA(nativeSurface_->format,
                                   0,
                                   0,
                                   0,
                                   0);
  
  Uint32* rowBase = (Uint32*)nativeSurface_->pixels;
  for (int i = 0; i < getHeight(); i++) {
    rowBase = (Uint32*)(nativeSurface_->pixels + (nativeSurface_->pitch * i));
    for (int j = 0; j < getWidth(); j++) {
      *(rowBase + j) = clearColor;
    }
  } */
  
  nativeSurfaceTexture_ = SDL_CreateTextureFromSurface(&renderer,
                                                       nativeSurface_);
  
/*// why doesn't this work??                                       
  nativeSurfaceTexture_ = SDL_CreateTexture(&renderer,
                                            SDL_PIXELFORMAT_ARGB8888,
                                            SDL_TEXTUREACCESS_STREAMING,
                                            w__,
                                            h__);
                                            
//  clearTexture(); */
}

// Abstract implementations

DrawPosition SDL2DrawableSurface::draw(DrawPosition pos,
                  DrawColor color,
                  int length) {
  unsigned char* rowBase = (unsigned char*)(nativeSurface_->pixels);
  
  // Current row
  int rowNum = pos.y();
  // Number of pixels handled in row
  int rowPos = pos.x();
  // pixels left to color
  int remaining = length;
  
  // Get a pointer to target draw position
  rowBase += (nativeSurface_->pitch * pos.y());
  
  while (remaining > 0 && rowNum < nativeSurface_->h) {
  
    // Find and color the target pixel
    Uint32* targetPixel = (Uint32*)(rowBase 
                          + (rowPos * nativeSurface_->format->BytesPerPixel));
    *targetPixel = SDL_MapRGBA(nativeSurface_->format,
                              color.r(),
                              color.g(),
                              color.b(),
                              color.a());
                              
    --remaining;
    ++rowPos;
    
    // wrap to next row if needed
    if (rowPos == nativeSurface_->w) {
      ++rowNum;
      rowPos = 0;
      rowBase += (nativeSurface_->pitch);
    }
  }
  
  // Return the next drawing position
  return DrawPosition(rowPos, rowNum);
}
                  
void SDL2DrawableSurface::blit(DrawableSurface& source,
          int x,
          int y,
          int w,
          int h) {
  SDL2DrawableSurface& nativeSource
    = dynamic_cast<SDL2DrawableSurface&>(source);
    
  SDL_Rect dstRect;
  dstRect.x = x;
  dstRect.y = y;
  
  // Note that the w and h parameters are not used
  // by SDL, but are included in the DrawableSurface interface
  // (and thus here) for completeness and in case of
  // future extensions
  dstRect.w = w;
  dstRect.w = h;
  
  SDL_BlitSurface(&(nativeSource.nativeSurface()),
                  NULL,
                  nativeSurface_,
                  &dstRect);
                  
}
            
void SDL2DrawableSurface::update() {
  flipSurfaceToTexture();
}
            
int SDL2DrawableSurface::getWidth() {
  return nativeSurface_->w;
}

int SDL2DrawableSurface::getHeight() {
  return nativeSurface_->h;
}
  
GraphicSurface* SDL2DrawableSurface::toGraphicSurface(
                                GraphicsCore& graphicsCore) {
  return new SDL2GraphicSurface(dynamic_cast<SDL2GraphicsCore&>(graphicsCore),
                                *this);
}
  
void SDL2DrawableSurface::flipSurfaceToTexture() {
  SDL_UpdateTexture(nativeSurfaceTexture_,
                    NULL,
                    nativeSurface_->pixels,
                    nativeSurface_->pitch);
}
  
SDL_Surface& SDL2DrawableSurface::nativeSurface() {
  return *nativeSurface_;
}
  
SDL_Texture& SDL2DrawableSurface::nativeSurfaceTexture() {
  return *nativeSurfaceTexture_;
}
  
void SDL2DrawableSurface::clearTexture() {
  void* pixels;
  int pitch;
  SDL_LockTexture(nativeSurfaceTexture_,
                  NULL,
                  &pixels,
                  &pitch);
  
  Uint32 clearColor = SDL_MapRGBA(nativeSurface_->format,
                                   0,
                                   0,
                                   0,
                                   255);
  
  Uint32* rowBase = (Uint32*)pixels;
  for (int i = 0; i < getHeight(); i++) {
    rowBase = (Uint32*)((Uint32*)pixels + (pitch * i));
    for (int j = 0; j < getWidth(); j++) {
      *(rowBase + j) = clearColor;
    }
  }
  
  SDL_UnlockTexture(nativeSurfaceTexture_);
}


};

#endif