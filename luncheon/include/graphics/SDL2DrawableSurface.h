#ifndef SDL2DRAWABLESURFACE_H
#define SDL2DRAWABLESURFACE_H


#ifdef LUNCHEON_ENABLE_SDL2

#include "graphics/DrawableSurface.h"
#include "graphics/DrawPosition.h"
#include "graphics/DrawColor.h"
#include "SDL.h"

namespace Luncheon {


class SDL2DrawableSurface : public DrawableSurface {
public:
  virtual ~SDL2DrawableSurface();
  
  SDL2DrawableSurface(int w__,
                      int h__,
                      SDL_Renderer& renderer);
  
  // Abstract implementations
  
  virtual DrawPosition draw(DrawPosition pos,
                    DrawColor color,
                    int length);
                    
  virtual void blit(DrawableSurface& source,
            int x,
            int y,
            int w,
            int h);
            
  virtual void update();
            
  virtual int getWidth();
  
  virtual int getHeight();
  
  virtual GraphicSurface* toGraphicSurface(GraphicsCore& graphicsCore);
            
  // Extensions
  
  virtual void flipSurfaceToTexture();
  
  virtual SDL_Surface& nativeSurface();
  
  virtual SDL_Texture& nativeSurfaceTexture();
  
  virtual void clearTexture();
protected:
  
  SDL_Surface* nativeSurface_;
  
  SDL_Texture* nativeSurfaceTexture_;
  
};


};

#endif


#endif
