#include "clicker.hpp"

Clicker::Clicker():
  start_(std::chrono::high_resolution_clock::now())
{}

double Clicker::millisec() const
{
  using std::chrono::high_resolution_clock;
  using std::chrono::duration_cast;
  using std::chrono::microseconds;

  auto t = high_resolution_clock::now();
  return duration_cast< microseconds >(t - start_).count();
}