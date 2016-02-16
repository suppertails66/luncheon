#ifndef RECTAREA_H
#define RECTAREA_H


namespace Luncheon {


class RectArea {
public:
  virtual ~RectArea();
  
  RectArea();
  
  RectArea(int x__,
           int y__,
           int w__,
           int h__);
           
  int x();
  void setX(int x__);
           
  int y();
  void setY(int y__);
           
  int w();
  void setW(int w__);
           
  int h();
  void setH(int h__);

protected:
  
  int x_;
  int y_;
  int w_;
  int h_;
};


};


#endif 
