#ifndef DRAWPOSITION_H
#define DRAWPOSITION_H


namespace Luncheon {


class DrawPosition {
 public:
  virtual ~DrawPosition();

  DrawPosition();
  DrawPosition(int x__, int y__);

  virtual int x() const;
  virtual void setX(int x__);

  virtual int y() const;
  virtual void setY(int y__);

 protected:
  int x_;
  int y_;
};


};


#endif
