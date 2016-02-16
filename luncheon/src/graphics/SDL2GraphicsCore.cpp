#ifdef LUNCHEON_ENABLE_SDL2

#include "graphics/SDL2GraphicsCore.h"
#include "graphics/GraphicsCoreType.h"
#include "graphics/SDL2GameWindow.h"
#include "graphics/SDL2GraphicSurface.h"
#include "graphics/SDL2ScreenBuffer.h"
#include "graphics/SDL2DrawableSurface.h"
#include <string>
#include "SDL.h"

namespace Luncheon {


SDL2GraphicsCore::~SDL2GraphicsCore() {
  
}
	
SDL2GraphicsCore::SDL2GraphicsCore()
  : GraphicsCore() {
  coreType_ = GraphicsCoreTypes::SDL2;
  
  // Initialize the game window
  gameWindow_ = new SDL2GameWindow(*this);
  
}

GraphicSurface* SDL2GraphicsCore::createGraphicSurface(
                                             int w, 
                                             int h) {
  // Return a new GraphicSurface
  return new SDL2GraphicSurface(*this, w, h);
}


DrawableSurface* SDL2GraphicsCore::createDrawableSurface(int w, 
                                                         int h) {
  SDL2GameWindow& window 
    = dynamic_cast<SDL2GameWindow&>(*gameWindow_);
  SDL2ScreenBuffer& screenBuffer 
    = dynamic_cast<SDL2ScreenBuffer&>(window.screenBuffer());
  return new SDL2DrawableSurface(w,
                                 h,
                                 screenBuffer.renderer());
}

SDL_Texture* SDL2GraphicsCore::createTexture(int w,
                           int h) {
  // Retrieve the renderer by appropriate casts
  SDL2GameWindow& gameWindowR = *(dynamic_cast<SDL2GameWindow*>(gameWindow_));
  SDL2ScreenBuffer& screenBufferR = dynamic_cast<SDL2ScreenBuffer&>(gameWindowR.screenBuffer());
  SDL_Renderer& rendererR = screenBufferR.renderer();
  
  return SDL_CreateTexture(&rendererR,
                         SDL_PIXELFORMAT_ARGB8888,
                         SDL_TEXTUREACCESS_STREAMING,
                         w,
                         h);
}
                             
GraphicSurface* SDL2GraphicsCore::loadBMPFromFile(const std::string& filename) {
  return new SDL2GraphicSurface(*this, filename);
}


}; 

#endif