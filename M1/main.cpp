#include <iostream>

int main(int argc, char* argv[])
{
  if (argc == 0 || argc > 2)
  {
    std::cerr << "Invalid number of elements!";
  }
  double seed = argv[0];
  double tries = 0;
  if (argc == 2)
  {
    tries = argv[1];
  }
  while (!std::cin.eof())
  {
    unsigned double radius = 0;
    unsigned int number_of_threads = 0;
    std::cin >> radius >> number_of_threads;
    //i would put start clock here when i remember how to do it
    //some tricky wise multithreaded calculations
    //end clock
    std::cout << radius << " " << number_of_threads << "\n";
    //time output
  }
}
