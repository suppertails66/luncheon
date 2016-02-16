#ifndef WINDOWMENUAREA_H
#define WINDOWMENUAREA_H


#include "logic/WindowArea.h"

namespace Luncheon {


class MenuWindowArea : public WindowArea {
public:
  virtual ~MenuWindowArea();
protected:
  MenuWindowArea(GameMemory& gameMemory__,
                 GameScene& parent__,
                 Window* parentWindow__);
};


};


#endif 
