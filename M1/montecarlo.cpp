#include "montecarlo.hpp"
#include <random>

Point generatePoint(int seed, Rectangle frameRectangle)
{
  double lower_bound = frameRectangle.bl_.y_;
  double upper_bound = frameRectangle.tr_.y_;
  double left_bound = frameRectangle.bl_.x_;
  double right_bound = frameRectangle.tr_.x_;

  std::mt19937 gen(seed);
  std::uniform_real_distribution<> distr_y(lower_bound, upper_bound);
  std::uniform_real_distribution<> distr_x(left_bound, right_bound);

  Point tmp(distr_x(gen), distr_y(gen));
  return tmp;
}
