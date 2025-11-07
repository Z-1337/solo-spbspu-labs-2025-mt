#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "point.hpp"
#include <random>

struct Rectangle
{
  Rectangle();
  double getArea();
  Point tr_, tl_, br_, bl_;
};

#endif
