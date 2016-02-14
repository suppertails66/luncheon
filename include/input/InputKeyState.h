#ifndef INPUTKEYSTATE_H
#define INPUTKEYSTATE_H


namespace Luncheon {


class InputKeyState {
public:
  virtual ~InputKeyState();
  
  InputKeyState();
  
  void setDown(bool down__);
  
  bool down();
  
  bool up();
  
protected:

  bool down_;
  
};


};


#endif 
