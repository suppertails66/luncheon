#ifndef DRAWCOLOR_H
#define DRAWCOLOR_H


namespace Luncheon {


class DrawColor {
public:
  virtual ~DrawColor();
  
  DrawColor();
  
  DrawColor(int colorComponents);
  
  DrawColor(int r__, int g__, int b__);
  
  DrawColor(int r__, int g__, int b__, int a__);
  
  operator int() const;
  
  static int fullAlphaOpacity();
  static int maxExpression();
  
  virtual int r() const;
  virtual void setR(int r__);
  
  virtual int g() const;
  virtual void setG(int g__);
  
  virtual int b() const;
  virtual void setB(int b__);
  
  virtual int a() const;
  virtual void setA(int a__);
  
  virtual bool operator==(const DrawColor& color);
  virtual bool operator!=(const DrawColor& color);

protected:

  const static int fullAlphaOpacity_ = 255;
  const static int maxExpression_ = 255;
  
  int r_;
  int g_;
  int b_;
  int a_;
  
};


};


#endif
