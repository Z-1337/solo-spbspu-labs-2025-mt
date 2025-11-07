#include <functional>
#include <numeric>
#include <iostream>
#include <thread>
#include <vector>
#include "../common/clicker.hpp"
#include "../common/streamguard.hpp"
#include "shapes/circle.hpp"
#include "montecarlo.hpp"

double gen_points(size_t per_thread, Rectangle MonteCarloZone, Circle circle, int seed)
{
  std::mt19937 gen(seed);
  double local_amount = 0;
  for (size_t i = 0; i < per_thread; ++i)
  {
    if (isInCircle(generatePoint(gen, MonteCarloZone), circle))
    {
      ++local_amount;
    }
  }
  return local_amount;
}

void gen_points_th(size_t per_thread, Rectangle MonteCarloZone, Circle circle, std::vector< double >::iterator results, int seed)
{
  *results = gen_points(per_thread, MonteCarloZone, circle, seed);
}

int main(int argc, char* argv[])
{
  if (argc == 1 || argc > 3)
  {
    std::cerr << "Invalid number of elements!\n";
    return 1;
  }

  size_t tries = std::stoll(argv[1]);
  if (tries < 1)
  {
    std::cerr << "Invalid amount of tries!\n";
    return 1;
  }

  int seed = 0;
  if (argc == 3)
  {
    seed = std::stoi(argv[2]);
    if (seed < 0)
    {
      std::cerr << "Invalid seed value!\n";
      return 1;
    }
  }

  while (true)
  {
    double radius = 0;
    size_t number_of_threads = 0;
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

    std::vector< std::thread > ths;
    ths.reserve(number_of_threads);

    Clicker cl;
    double init = cl.microsec();

    size_t per_thread = tries / number_of_threads;
    size_t i = 0;
    std::vector< double > results(number_of_threads, 0);

    Circle circle(radius);
    Rectangle MonteCarloZone = circle.getFrameRectangle();

    for (; i < number_of_threads - 1; ++i)
    {
      ths.emplace_back(gen_points_th, per_thread, MonteCarloZone, circle, results.begin() + i, seed);
    }
    gen_points_th((tries % number_of_threads) + per_thread, MonteCarloZone, circle, results.begin() + i, seed);

    for (auto& th: ths)
    {
      th.join();
    }

    double amount_of_filtered_points = std::accumulate(results.begin(), results.end(), 0);
    double ratio = amount_of_filtered_points / tries;
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
