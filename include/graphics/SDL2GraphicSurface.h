#ifndef SDL2GRAPHICSURFACE_H
#define SDL2GRAPHICSURFACE_H


#include "graphics/GraphicSurface.h"
#include "graphics/SDL2GraphicsCore.h"
#include "graphics/DrawPosition.h"
#include "SDL.h"
#include <string>
#include "graphics/SDL2DrawableSurface.h"

namespace Luncheon {


class SDL2GraphicSurface : public GraphicSurface {
public:
  virtual ~SDL2GraphicSurface();
  
  SDL2GraphicSurface(SDL2GraphicsCore& graphicsCore,
                     int w,
                     int h);
  
  SDL2GraphicSurface(SDL2GraphicsCore& graphicsCore,
                     SDL2DrawableSurface& drawable);
  
  SDL2GraphicSurface(SDL2GraphicsCore& graphicsCore,
                     const std::string& filename);
                     
  // Abstract implementations
  
  virtual void lock();
  
  virtual void unlock();
  
  virtual bool locked() const;
  
  virtual int getWidth() const;
  
  virtual int getHeight() const;
  
  virtual void draw(const GraphicSurface& source,
                    int x,
                    int y,
                    int w = 0,
                    int h = 0);
                    
  virtual DrawPosition drawPixels(const DrawPosition& pos,
                          const DrawColor& color,
                          int length);
                          
  // Added functions
  
  virtual SDL_Texture& texture();
  
  virtual const SDL_Texture& texture() const;
  
protected:
  
  SDL_Texture* texture_;
  
};


};


#endif
