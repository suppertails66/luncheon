#ifndef SDL2GRAPHICSCORE_H
#define SDL2GRAPHICSCORE_H


#include "graphics/GraphicsCore.h"
#include "graphics/GraphicSurface.h"
#include <string>
#include "SDL.h"

namespace Luncheon {


class SDL2GraphicsCore : public GraphicsCore {
public:
	virtual ~SDL2GraphicsCore();
	
  SDL2GraphicsCore();
	
	virtual GraphicSurface* createGraphicSurface(int w, 
                                               int h);
  
  virtual DrawableSurface* createDrawableSurface(int w, 
                                                 int h);
                                               
  SDL_Texture* createTexture(int w,
                             int h);
                             
  virtual GraphicSurface* loadBMPFromFile(const std::string& filename);
	
protected:
	
};


};



#endif
