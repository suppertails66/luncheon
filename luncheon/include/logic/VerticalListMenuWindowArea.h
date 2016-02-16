#ifndef VERTICALLISTMENUWINDOWAREA_H
#define VERTICALLISTMENUWINDOWAREA_H


#include "logic/ListMenuWindowArea.h"
#include "logic/GameObjectID.h"

namespace Luncheon {


class VerticalListMenuWindowArea : public ListMenuWindowArea {
public:
  virtual ~VerticalListMenuWindowArea();
  
  VerticalListMenuWindowArea(GameMemory& gameMemory__,
                             GameScene& parent__,
                             Window* parentWindow__,
                             ResourceID cursorEnabledID__,
                             ResourceID cursorDisabledID__,
                             ResourceID cursorEnabledSoundID__,
                             ResourceID cursorDisabledSoundID__);
  
//  virtual void updateSelection(GTick ticks);
  
  virtual void drawItems(ScreenBuffer& buffer);
  
  virtual int maxVisibleItems();
  
  virtual int highestFullyVisibleItemNum();
  
  virtual int lowestFullyVisibleItemNum();
  
  virtual void scrollItemToBottom(int itemNum);
  
  virtual void scrollItemToTop(int itemNum);
             
  /* Remove these? */
  
  virtual bool selectionIncrementInputActivated();
  
  virtual bool selectionDecrementInputActivated();
  
  virtual bool selectionPageDownInputActivated();
  
  virtual bool selectionPageUpInputActivated();
  
  virtual bool selectionConfirmInputActivated();
  
  virtual bool selectionCancelInputActivated();
  
  /* Definitely remove this */
  
  virtual GameObjectID objectID();
protected:
  
};


};


#endif 
