#ifdef LUNCHEON_ENABLE_SDL2

#include "graphics/SDL2GraphicSurface.h"
#include "graphics/DrawPosition.h"
#include "graphics/SDL2ScreenBuffer.h"
#include "SDL.h"

namespace Luncheon {


SDL2GraphicSurface::~SDL2GraphicSurface() {
  SDL_DestroyTexture(texture_);
}

SDL2GraphicSurface::SDL2GraphicSurface(SDL2GraphicsCore& graphicsCore,
                                       int w,
                                       int h)
  : GraphicSurface(),
    texture_(0) {
  texture_ = graphicsCore.createTexture(w, h);
}

SDL2GraphicSurface::SDL2GraphicSurface(SDL2GraphicsCore& graphicsCore,
                   SDL2DrawableSurface& drawable)
  : GraphicSurface(),
    texture_(0) {
  SDL2ScreenBuffer& screenBuffer 
    = dynamic_cast<SDL2ScreenBuffer&>(graphicsCore.gameWindow().screenBuffer());
  texture_ = SDL_CreateTextureFromSurface(&(screenBuffer.renderer()),
                                          &(drawable.nativeSurface()));
}

SDL2GraphicSurface::SDL2GraphicSurface(SDL2GraphicsCore& graphicsCore,
                                       const std::string& filename)
  : GraphicSurface(),
    texture_(0) {
    
  // Temporary surface to contain pixels until we can
  // put them in a texture
  SDL_Surface* tempSurface = SDL_LoadBMP(filename.c_str());
  
  // To remove the pixels we want to be transparent, we
  // have to set the colorkey and blit to a new surface
/*  SDL_SetColorKey(tempSurface,
                  SDL_TRUE,
                  SDL_MapRGB(tempSurface->format,
                             0xFF,
                             0x00,
                             0xFF));
                             
  SDL_Surface* transparentTempSurface = SDL_CreateRGBSurface(0,
                                                              tempSurface->w,
                                                              tempSurface->h,
                                                              32,
                                                              tempSurface->format->Rmask,
                                                              tempSurface->format->Gmask,
                                                              tempSurface->format->Bmask,
                                                              0);
                             
  SDL_BlitSurface(tempSurface,
                  NULL,
                  transparentTempSurface,
                  NULL);
                  
  SDL_FreeSurface(tempSurface); */
  
  
  // Retrieve the renderer
  SDL2ScreenBuffer& screenBuffer 
    = dynamic_cast<SDL2ScreenBuffer&>(
    graphicsCore.gameWindow().screenBuffer());
  SDL_Renderer& renderer = screenBuffer.renderer();
  
  texture_ = SDL_CreateTextureFromSurface(&renderer,
                                          tempSurface);
  SDL_FreeSurface(tempSurface);
}

void SDL2GraphicSurface::lock() {
  SDL_LockTexture(texture_,
                  NULL,
                  NULL,
                  NULL);
  locked_ = true;
}

void SDL2GraphicSurface::unlock() {
  SDL_UnlockTexture(texture_);
  locked_ = false;
}
  
bool SDL2GraphicSurface::locked() const {
  return locked_;
}

int SDL2GraphicSurface::getWidth() const {
  int width;
  SDL_QueryTexture(texture_,
                   NULL,
                   NULL,
                   &width,
                   NULL);
  return width;
}

int SDL2GraphicSurface::getHeight() const {
  int height;
  SDL_QueryTexture(texture_,
                   NULL,
                   NULL,
                   NULL,
                   &height);
  return height;
}

void SDL2GraphicSurface::draw(const GraphicSurface& source,
                  int x,
                  int y,
                  int w,
                  int h) {
                  
}
                  
DrawPosition SDL2GraphicSurface::drawPixels(const DrawPosition& pos,
                        const DrawColor& color,
                        int length) {
  return DrawPosition();
}

SDL_Texture& SDL2GraphicSurface::texture() {
  return *texture_;
}
  
const SDL_Texture& SDL2GraphicSurface::texture() const {
  return *texture_;
}


};

#endif