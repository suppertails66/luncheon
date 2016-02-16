#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
 

#include "graphics/GraphicSurface.h"
#include <string>
#include "graphics/GameWindowMode.h"
#include "graphics/ScreenBuffer.h"

namespace Luncheon {


class GraphicsCore;

class GameWindow {
public:
  virtual ~GameWindow();
  
  // Provided
  
  virtual ScreenBuffer& screenBuffer();
  
  virtual GameWindowModes::GameWindowMode displayMode();
  virtual void setDisplayMode(GameWindowModes::GameWindowMode
    displayMode__);
  
  // Abstract
  
  virtual void createWindow(int w,
                            int h,
                            int x,
                            int y,
                            int nativeW,
                            int nativeH) =0;
                            
  virtual void changeWindowTitle(const std::string& title) =0;
  
  virtual std::string getWindowTitle() const =0;
  
  virtual void flipToVisibleScreen() =0;
  
  virtual void updateDisplayMode() =0;
  
  virtual int getWidth() =0;
  
  virtual int getHeight() =0;
  
  virtual int getNativeWidth() =0;
  
  virtual int getNativeHeight() =0;
  
  /*virtual void changeResolution(int w, int h) =0;*/

protected:
  GameWindow(GraphicsCore& graphicsCore__);
  
  GraphicsCore& graphicsCore_;
  
  ScreenBuffer* screenBuffer_;
  
  GameWindowModes::GameWindowMode displayMode_;
  
};


};


#endif
