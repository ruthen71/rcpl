#pragma once

long long pow_mod(long long a, long long n, const long long mod) {
    assert(n >= 0 and mod >= 1);
    if (mod == 1) return 0;
    a %= mod;
    if (a < 0) a += mod;
    long long res = 1;
    while (n) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}