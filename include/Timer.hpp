#pragma once

#include <chrono>
#include <iostream>
#include <string>

class Timer {
public:
    Timer(const std::string& name = "")
        : name_(name), start_(std::chrono::high_resolution_clock::now()) {}

    ~Timer() {
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = end - start_;
        auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();

        std::cout << "[Timer] " << (name_.empty() ? "" : name_ + ": ") << ms << " ms" << std::endl;
    }

private:
    std::string name_;
    std::chrono::time_point<std::chrono::high_resolution_clock> start_;
};
