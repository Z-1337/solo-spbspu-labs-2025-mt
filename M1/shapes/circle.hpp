#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "rectangle.hpp"

struct Circle
{
  Circle(double radius);
  Rectangle getFrameRectangle();

  double radius_;
  Point center_;
};

#endif
