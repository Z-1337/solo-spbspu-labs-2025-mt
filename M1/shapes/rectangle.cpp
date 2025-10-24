#include "rectangle.hpp"

Rectangle::Rectangle():
  tr_(0, 0),
  tl_(0, 0),
  br_(0, 0),
  bl_(0, 0)
{}

double Rectangle::getArea()
{
  return tr_.x_ * tr_.y_ * 4;
}