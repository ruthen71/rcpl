#pragma once

#include "math/prime_factor.hpp"

long long totient(long long n) {
    auto pf = prime_factor(n);
    for (auto &[p, e] : pf) {
        n /= p;
        n *= p - 1;
    }
    return n;
}