#ifndef SDL2SCREENBUFFER_H
#define SDL2SCREENBUFFER_H


#ifdef LUNCHEON_ENABLE_SDL2

#include "graphics/ScreenBuffer.h"
#include "graphics/SDL2GameWindow.h"
#include "SDL.h"

namespace Luncheon {


class SDL2GameWindow;

class SDL2ScreenBuffer : public ScreenBuffer {
public:
  virtual ~SDL2ScreenBuffer();
  
  SDL2ScreenBuffer(SDL2GameWindow& sourceWindow,
                   int w,
                   int h,
                   int nativeW,
                   int nativeH);
  
  virtual void lock();
  
  virtual void unlock();
                   
  // Abstract implementations
  
  virtual void draw(GraphicSurface& source,
                    int x,
                    int y);
  
  virtual void draw(DrawableSurface& source,
                    int x,
                    int y);
                    
  virtual void drawRect(DrawColor color,
                        RectArea rect);
                    
  virtual void clear();
                    
  virtual void clear(DrawColor color);
  
  virtual void flip();
  
  virtual int getNativeWidth();
  
  virtual int getNativeHeight();
  
  virtual bool hasClipArea();
  
  virtual ClipArea getClipArea();
  
  virtual void setClipArea(ClipArea area);
  
  virtual void clearClipArea();
  
  // Additional functions
  
  virtual SDL_Renderer& renderer();
protected:
  
  SDL_Renderer* renderer_;
  
  bool hasClipArea_;
  
  ClipArea clipArea_;
  
};


};

#endif


#endif
