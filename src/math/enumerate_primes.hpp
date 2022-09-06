#pragma once

#include "src/math/prime_table.hpp"

std::vector<int> enumerate_primes(int n) {
    auto pt = prime_table(n);
    std::vector<int> res;
    res.reserve(std::count(pt.begin(), pt.end(), true));
    for (int i = 0; i < pt.size(); i++) {
        if (pt[i]) res.push_back(i);
    }
    return res;
}