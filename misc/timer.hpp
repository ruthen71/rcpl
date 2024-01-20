#pragma once

#include <chrono>

struct Timer {
    std::chrono::high_resolution_clock::time_point st;

    Timer() { reset(); }
    void reset() { st = std::chrono::high_resolution_clock::now(); }

    // t [ms]
    long long elapsed() {
        auto ed = std::chrono::high_resolution_clock::now();
        return std::chrono::duration_cast<std::chrono::milliseconds>(ed - st).count();
    }
    long long operator()() { return elapsed(); }
} timer;