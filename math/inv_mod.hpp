#pragma once

#include "math/extended_gcd.hpp"

// mod >= 2
long long inv_mod(long long a, long long mod) {
    a %= mod;
    if (a < 0) a += mod;
    assert(a != 0);
    auto [x, y, g] = extended_gcd(a, m);
    x %= mod;
    if (x < 0) x += mod;
    return x;
}