#ifndef CLICKER_HPP
#define CLICKER_HPP

#include <chrono>

struct Clicker
{
  Clicker();
  double millisec() const;

  private:
    std::chrono::time_point< std::chrono::system_clock > start_;
};

#endif