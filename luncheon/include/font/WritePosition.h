#ifndef WRITEPOSITION_H
#define WRITEPOSITION_H


namespace Luncheon {


class WritePosition {
public:
  virtual ~WritePosition();
  
  WritePosition();
  
  WritePosition(int x__,
                int y__);
  
  WritePosition(int x__,
                int y__,
                int baseX__,
                int baseY__);
                
  virtual int x();
  virtual void setX(int x__);
  
  virtual int y();
  virtual void setY(int y__);
  
  virtual int baseX();
  virtual void setBaseX(int baseX__);
  
  virtual int baseY();
  virtual void setBaseY(int baseY__);
  
protected:

  int x_;
  int y_;
  
  int baseX_;
  int baseY_;

};


};


#endif 
