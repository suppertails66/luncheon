#ifndef INPUTCORE_H
#define INPUTCORE_H


#include "input/InputKey.h"
#include "input/TwinInputKeyStates.h"

namespace Luncheon {


class InputCore {
public:
  virtual ~InputCore();
  
  virtual void updateInputs() =0;
  
  virtual void rememberFirstTriggeredInputKey() =0;
  
  virtual InputKeys::InputKey firstTriggeredInputKey();
  
  virtual void resetFirstTriggeredInputKey();
  
  virtual bool wantsQuit();
  
  virtual void setWantsQuit(bool wantsQuit__);
  
  virtual bool pressed(InputKeys::InputKey key);
  
  virtual bool triggered(InputKeys::InputKey key);
  
  virtual bool held(InputKeys::InputKey key);
  
  virtual bool released(InputKeys::InputKey key);
  
/*  virtual bool up(InputKeys::InputKey key) =0;
  
  virtual bool down(InputKeys::InputKey key) =0; */
  
protected:
  InputCore();
  
  TwinInputKeyStates inputKeyStates_;
  
  InputKeys::InputKey firstTriggeredInputKey_;
  
  bool wantsQuit_;
  
  virtual void clearActiveInputState();
};


};


#endif
