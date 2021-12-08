#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>

int main()
{
    auto now = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(now);
    auto formatted = std::put_time(std::localtime(&time), "%Y-%m-%d %X");
    std::cout << formatted << std::endl;
}