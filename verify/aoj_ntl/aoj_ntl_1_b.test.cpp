#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B"

#include <bits/stdc++.h>

#include "math/pow_mod.hpp"

int main() {
    // a = 0
    assert(pow_mod(0, 0, 1) == 0);  // 0 ^ 0 = 1
    assert(pow_mod(0, 0, 2) == 1);
    assert(pow_mod(0, 0, 3) == 1);
    assert(pow_mod(0, 1, 1) == 0);  // 0 ^ 1 = 0
    assert(pow_mod(0, 1, 2) == 0);
    assert(pow_mod(0, 1, 3) == 0);
    assert(pow_mod(0, 2, 1) == 0);  // 0 ^ 2 = 0
    assert(pow_mod(0, 2, 2) == 0);
    assert(pow_mod(0, 2, 3) == 0);
    // a > 0, n = 0
    assert(pow_mod(1, 0, 1) == 0);  // 1 ^ 0 = 1
    assert(pow_mod(1, 0, 2) == 1);
    assert(pow_mod(1, 0, 3) == 1);
    assert(pow_mod(2, 0, 1) == 0);  // 2 ^ 0 = 1
    assert(pow_mod(2, 0, 2) == 1);
    assert(pow_mod(2, 0, 3) == 1);
    long long m, n;
    std::cin >> m >> n;
    std::cout << pow_mod(m, n, 1000000007) << '\n';
    return 0;
}