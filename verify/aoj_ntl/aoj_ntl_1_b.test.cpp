#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B"

#include <bits/stdc++.h>

#include "src/math/pow_mod.hpp"

int main() {
    long long m, n;
    std::cin >> m >> n;
    std::cout << pow_mod(m, n, 1000000007) << '\n';
    return 0;
}