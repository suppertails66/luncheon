#include "logic/MenuWindowArea.h"

namespace Luncheon {


MenuWindowArea::~MenuWindowArea() { };

MenuWindowArea::MenuWindowArea(
                 GameMemory& gameMemory__,
                 GameScene& parent__,
                 Window* parentWindow__)
  : WindowArea(gameMemory__,
               parent__,
               parentWindow__) { };


}; 
