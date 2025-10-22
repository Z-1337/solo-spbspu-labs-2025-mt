#include "circle.hpp"

Circle::Circle(double radius):
  radius_(radius),
  center_(0, 0)
{}

Rectangle Circle::getFrameRectangle()
{
  Rectangle rectangle;
  rectangle.tr_ = Point(this->radius_, this->radius_);
  rectangle.tl_ = Point(-this->radius_, this->radius_);
  rectangle.br_ = Point(this->radius_, -this->radius_);
  rectangle.bl_ = Point(-this->radius_, -this->radius_);
  return rectangle;
}
