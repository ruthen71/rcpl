#pragma once

#include "src/math/ext_gcd.hpp"

long long inv(long long a, long long mod) {
    assert(a != 0);
    long long x, y;
    ext_gcd(a, mod, x, y);
    x %= mod;
    if (x < 0) x += mod;
    return x;
}
