#include <iostream>
#include "clicker.hpp"
#include "../common/streamguard.hpp"

int main(int argc, char* argv[])
{
  if (argc == 1 || argc > 3)
  {
    std::cerr << "Invalid number of elements!\n";
    return 0;
  }
  unsigned int tries = std::atoi(argv[1]);
  unsigned int seed = 0;
  if (argc == 3)
  {
    seed = std::atoi(argv[2]);
  }
  while (!std::cin.eof())
  {
    double radius = 0;
    unsigned int number_of_threads = 0;
    std::cin >> radius >> number_of_threads;
    if (radius < 0)
    {
      std::cerr << "Incorrect radius!\n";
      continue;
    }
    Clicker cl;
    double init = cl.millisec();
    volatile long long result = 1;
    for (size_t i = 0; i < 100000000; ++i)
    {
      result = result * 2;
    }
    std::cout << "result: " << result << "\n";
    double end = cl.millisec();
    //i would put start clock here when i remember how to do it
    //some tricky wise multithreaded calculations
    //end clock
    double total = (end - init) / 1000;
    std::cout << "radius: " << radius << "\nnumber of threads: " << number_of_threads << "\n";
    StreamGuard s(std::cout);
    std::cout << std::fixed << std::setprecision(3) << "time: " << total << "\n\n";
    //time output
  }
  std::cout << "tries: " << tries << "\nseed: " << seed << "\n";
}
