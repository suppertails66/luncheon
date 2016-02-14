#ifndef LISTMENUWINDOWAREA_H
#define LISTMENUWINDOWAREA_H


#include "logic/MenuWindowArea.h"
#include "logic/ListMenuItemCollection.h"
#include "graphics/DrawColor.h"
#include "graphics/DrawableSurface.h"
#include "resource/ResourceID.h"
#include <string>

namespace Luncheon {


class ListMenuWindowArea : public MenuWindowArea {
public:
  virtual ~ListMenuWindowArea();
  
  virtual void updateSelf(GTick ticks);
  
  virtual void updateSelection(GTick ticks);
  
  virtual void preUpdate(GTick ticks);
  
  virtual void postUpdate(GTick ticks);
  
  virtual void drawSelf(ScreenBuffer& buffer,
                        int drawX,
                        int drawY);
  
  virtual void drawItems(ScreenBuffer& buffer) =0;
  
  virtual void changeSelection(int newSelection);
  
  virtual void changeSelectionPage(int newSelection);
  
  virtual void makeSelection();
  
  virtual int maxVisibleItems() =0;
  
  virtual int highestFullyVisibleItemNum() =0;
  
  virtual int lowestFullyVisibleItemNum() =0;
  
  virtual void scrollItemToBottom(int itemNum) =0;
  
  virtual void scrollItemToTop(int itemNum) =0;
  
  virtual bool selectionIncrementInputActivated() =0;
  
  virtual bool selectionDecrementInputActivated() =0;
  
  virtual bool selectionPageDownInputActivated() =0;
  
  virtual bool selectionPageUpInputActivated() =0;
  
  virtual bool selectionConfirmInputActivated() =0;
  
  virtual bool selectionCancelInputActivated() =0;
  
  virtual bool scrolling();
  virtual void setScrolling(bool scrolling__);
  
  virtual int scrollX();
  virtual void setScrollX(int scrollX__);
  
  virtual int scrollY();
  virtual void setScrollY(int scrollY__);
  
  virtual bool cancellable();
  virtual void setCancellable(bool cancellable__);
  
  virtual bool selectionMade();
  virtual void setSelectionMade(bool selectionMade__);
  
  virtual bool wraparound();
  virtual void setWraparound(bool wraparound__);
  
  virtual int spacing();
  virtual void setSpacing(int spacing__);
  
  virtual int paddingLeft();
  virtual void setPaddingLeft(int paddingLeft__);
  
  virtual int paddingTop();
  virtual void setPaddingTop(int paddingTop__);
  
  virtual int paddingRight();
  virtual void setPaddingRight(int paddingRight__);
  
  virtual int paddingBottom();
  virtual void setPaddingBottom(int paddingBottom__);
  
  virtual int selectedItemNum();
  virtual void setSelectedItemNum(int selectedItemNum__);
  
  virtual const std::string& font();
  virtual void setFont(const std::string& font__);
  
  virtual int fontSize();
  virtual void setFontSize(int fontSize__);
  
//  virtual DrawColor disabledColor();
//  virtual void setDisabledColor(DrawColor disabledColor__);

  virtual bool needsRedraw();
  virtual void setNeedsRedraw(bool needsRedraw__);
  
  virtual int numItems();
  
  virtual void addItem(const std::string& label__,
                       int optionID__,
                       ListMenuItemFunctor* callback__,
                       bool enabled__);
  
  virtual void addItem(const std::string& label__,
                       int optionID__,
                       ListMenuItemFunctor* callback__,
                       bool enabled__,
                       DrawColor enabledColor__,
                       DrawColor disabledColor__);
  
  virtual ListMenuItem& getItem(int itemNum);
  
  virtual void removeItem(int itemNum);
  
  virtual void reloadItems();
  
protected:
  ListMenuWindowArea(GameMemory& gameMemory__,
                     GameScene& parent__,
                     Window* parentWindow__,
                     ResourceID cursorEnabledID__,
                     ResourceID cursorDisabledID__,
                     ResourceID cursorEnabledSoundID__,
                     ResourceID cursorDisabledSoundID__);
  
  virtual void loadItems();
                     
  virtual void drawItem(ListMenuItem& menuItem,
                        DrawableSurface& drawable,
                        int xOffset,
                        int yOffset);
                     
  ListMenuItemCollection menuItems_;
                     
  bool scrolling_;
  
  int scrollX_;
  
  int scrollY_;
  
  bool cancellable_;
  
  bool selectionMade_;
  
  bool wraparound_;
  
  int spacing_;
  
  int paddingLeft_;
  
  int paddingTop_;
  
  int paddingRight_;
  
  int paddingBottom_;
  
  int selectedItemNum_;
  
  std::string font_;
  
  int fontSize_;
  
//  DrawColor disabledColor_;

  AnimationPlayer* cursorEnabledAnimation_;

  AnimationPlayer* cursorDisabledAnimation_;
  
  ResourceID cursorEnabledSoundID_;
  
  ResourceID cursorDisabledSoundID_;
  
  GTick incrementHoldCount_;
  
  GTick decrementHoldCount_;
  
  GTick pageUpHoldCount_;
  
  GTick pageDownHoldCount_;
  
  GTick incrementRepeatCount_;
  
  GTick decrementRepeatCount_;
  
  GTick pageUpRepeatCount_;
  
  GTick pageDownRepeatCount_;
  
  bool needsRedraw_;
  
  // Number of gticks that must pass before commands will
  // be repeated
  const static GTick holdRepeatTolerance;
  
  // Number of gticks between repeated commands
  const static GTick delayBetweenRepeatInputs;
  
  DrawableSurface* itemSurface_;
};


};


#endif 
