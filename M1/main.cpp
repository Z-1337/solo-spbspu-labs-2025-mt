#include <iostream>
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

  while (true)
  {
    double radius = 0;
    int number_of_threads = 0;
    std::cin >> radius >> number_of_threads;
    if (std::cin.eof())
    {
      break;
    }
    if (radius < 1)
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

    volatile long long result = 1;
    for (size_t i = 0; i < 100000000; ++i)
    {
      result = result * 2;
    }
    Circle circle(radius);
    Rectangle MonteCarloZone = circle.getFrameRectangle();
    //std::cout << "testgen: " << generatePoint(seed, MonteCarloZone) << "\n"; //Оставил под комментом в коде, чтоб не потерять. Рабочий генератор

    double end = cl.microsec();
    double total = (end - init) / 1000;

    std::cout << "radius: " << radius << "\n";
    std::cout << "number of threads: " << number_of_threads << "\n";
    StreamGuard s(std::cout);
    std::cout << std::fixed << std::setprecision(3) << "time: " << total << "\n\n";
  }

  std::cout << "tries: " << tries << "\n";
  std::cout << "seed: " << seed << "\n";
}
