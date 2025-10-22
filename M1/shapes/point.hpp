#ifndef POINT_HPP
#define POINT_HPP

#include <ostream>

struct Point
{
  Point();
  Point(double x, double y);

  double x_, y_;
};

std::ostream& operator<<(std::ostream& out, const Point& point);

#endif
