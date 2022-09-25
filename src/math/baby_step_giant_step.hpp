#pragma once

#include "src/math/inv.hpp"
#include "src/math/pow_mod.hpp"

// find minimum K s.t. X ^ K = Y (mod M) and K >= lb
// O(sqrt(M))
long long baby_step_giant_step(long long X, long long Y, long long M, long long lb = 0LL) {
    X %= M, Y %= M;
    if (X < 0) X += M;
    if (Y < 0) Y += M;
    if (std::gcd(X, M) != 1) return -1;
    long long sqM = sqrt(M) + 1;
    std::unordered_map<long long, long long> mp;
    // Baby-step
    long long Z = pow_mod(X, lb, M);  // Z = X ^ lb (mod M)
    for (int i = 0; i < sqM; i++) {
        if (mp.find(Z) == mp.end()) mp[Z] = i + lb;
        Z = Z * X % M;
    }
    // Z = X ^ sqM (mod M)
    // R = Z ^ (-1) (mod M)
    long long R = inv(pow_mod(X, sqM, M), M);
    // Giant-step
    for (int i = 0; i <= sqM; i++) {
        if (mp.find(Y) != mp.end()) return mp[Y] + i * sqM;
        Y = Y * R % M;
    }
    return -1;
}