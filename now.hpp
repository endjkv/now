#ifndef NOW_HPP
#define NOW_HPP

#include <chrono>
#include <iomanip>
#include <string>
#include <iostream>

namespace now {
void print(std::string format) {
  auto now = std::chrono::system_clock::now();
  auto time = std::chrono::system_clock::to_time_t(now);
  auto formatted = std::put_time(std::localtime(&time), format.c_str());
  std::cout << formatted << std::endl;
}
} // namespace now

#endif