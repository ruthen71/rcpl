#pragma once

long long pow_mod(long long a, long long n, const long long mod) {
    assert(n >= 0 and mod >= 0);
    a %= mod;
    if (a < 0) a += mod;
    if (a == 0) return (n == 0 ? 1 % mod : 0);  // 0 ^ 0 = 1
    long long res = 1;
    while (n) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
