#include <functional>
#include <iostream>
#include <thread>
#include <vector>
#include "../common/clicker.hpp"
#include "../common/streamguard.hpp"
#include "shapes/circle.hpp"
#include "montecarlo.hpp"

int main(int argc, char* argv[])
{
  if (argc == 1 || argc > 3)
  {
    std::cerr << "Invalid number of elements!\n";
    return 1;
  }

  int tries = std::atoi(argv[1]);
  if (tries < 1)
  {
    std::cerr << "Invalid amount of tries!\n";
    return 1;
  }

  int seed = 0;
  if (argc == 3)
  {
    seed = std::atoi(argv[2]);
    if (seed < 0)
    {
      std::cerr << "Invalid seed value!\n";
      return 1;
    }
  }

  std::mt19937 gen(seed);

  while (true)
  {
    double radius = 0;
    int number_of_threads = 0;
    std::cin >> radius >> number_of_threads;
    if (std::cin.eof())
    {
      break;
    }
    if (radius < 0)
    {
      std::cerr << "Invalid radius!\n";
      return 1;
    }
    if (number_of_threads < 1)
    {
      std::cerr << "Invalid number of threads!\n";
      return 1;
    }

    Clicker cl;
    double init = cl.microsec();

    Circle circle(radius);
    Rectangle MonteCarloZone = circle.getFrameRectangle();

    std::vector< Point > generatedPoints;
    std::vector< Point > filteredPoints;
    for (size_t i = 0; i < tries; ++i)
    {
      Point p = generatePoint(gen, MonteCarloZone);
      generatedPoints.push_back(p);
      if (isInCircle(p, circle))
      {
        filteredPoints.push_back(p);
      }
    }
    double ratio = static_cast< double >(filteredPoints.size()) / static_cast< double >(generatedPoints.size());
    double circleArea = ratio * MonteCarloZone.getArea();
    StreamGuard s(std::cout);
    std::cout << "Area of the circle: " << std::fixed << std::setprecision(3) << circleArea << "\n";

    double end = cl.microsec();
    double total = (end - init) / 1000;

    std::cout << "radius: " << radius << "\n";
    std::cout << "number of threads: " << number_of_threads << "\n";
    std::cout << std::fixed << std::setprecision(3) << "time: " << total << " ms\n\n";
  }

  std::cout << "tries: " << tries << "\n";
  std::cout << "seed: " << seed << "\n";
}
