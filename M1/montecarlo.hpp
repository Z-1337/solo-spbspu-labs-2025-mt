#ifndef MONTECARLO_HPP
#define MONTECARLO_HPP

#include "shapes/circle.hpp"

Point generatePoint(std::mt19937& gen, Rectangle frameRectangle);
bool isInCircle(Point point, Circle circle);

#endif
