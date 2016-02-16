#ifndef SDL2GAMEWINDOW_H
#define SDL2GAMEWINDOW_H


#ifdef LUNCHEON_ENABLE_SDL2

#include "SDL.h"
#include "graphics/GameWindow.h"

namespace Luncheon {


class SDL2GameWindow : public GameWindow {
public:
  virtual ~SDL2GameWindow();
  
  SDL2GameWindow(GraphicsCore& graphicsCore__);
  
  // Implementations of pure virtual functions
  
  virtual void createWindow(int w,
                            int h,
                            int x,
                            int y,
                            int nativeW,
                            int nativeH);
                            
  virtual void changeWindowTitle(const std::string& title);
  
  virtual std::string getWindowTitle() const;
  
  virtual void flipToVisibleScreen();
  
  virtual void updateDisplayMode();
  
  virtual int getWidth();
  
  virtual int getHeight();
  
  virtual int getNativeWidth();
  
  virtual int getNativeHeight();
  
  /*virtual void changeResolution(int w, int h);*/
  
  // Extensions to interface
  
  virtual SDL_Window& nativeWindow();
                            
protected:
  
  SDL_Window* nativeWindow_;
  
  
};


};

#endif


#endif 
