#include "lib/cxxopts.hpp"
#include "now.hpp"

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

  auto format = result["format"].as<std::string>();
  now::print(format);
}