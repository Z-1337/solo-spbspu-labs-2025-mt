#include "montecarlo.hpp"
#include <random>

Point generatePoint(std::mt19937& gen, Rectangle frameRectangle)
{
  double lower_bound = frameRectangle.bl_.y_;
  double upper_bound = frameRectangle.tr_.y_;
  double left_bound = frameRectangle.bl_.x_;
  double right_bound = frameRectangle.tr_.x_;

  std::uniform_real_distribution<> distr_y(lower_bound, upper_bound);
  std::uniform_real_distribution<> distr_x(left_bound, right_bound);

  Point tmp(distr_x(gen), distr_y(gen));
  return tmp;
}

bool isInCircle(Point point, Circle circle)
{
  double sqrt_circ_eq = point.x_ * point.x_ + point.y_ * point.y_;
  double sqrt_radius = circle.radius_ * circle.radius_;
  return sqrt_circ_eq <= sqrt_radius;
}