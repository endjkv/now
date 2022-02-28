#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>

#include "lib/cxxopts.hpp"

auto make_options() {
  cxxopts::Options options("now", "Print now!");
  options.set_tab_expansion().add_options()(
      "f,format", "Specify format",
      cxxopts::value<std::string>()->default_value("%Y-%m-%d %X"))(
      "h,help", "Print usage");
  return options;
}

int main(int argc, char **argv) {
  auto options = make_options();
  auto result = options.parse(argc, argv);

  if (result.count("help")) {
    std::cout << options.help() << std::endl;
    exit(0);
  }

  auto format = result["format"].as<std::string>().c_str();
  auto now = std::chrono::system_clock::now();
  auto time = std::chrono::system_clock::to_time_t(now);
  auto formatted = std::put_time(std::localtime(&time), format);
  std::cout << formatted << std::endl;
}