#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A"

#include <bits/stdc++.h>

#include "src/math/prime_factor.hpp"

int main() {
    long long n;
    std::cin >> n;
    auto pf = prime_factor(n);
    std::cout << n << ':';
    for (auto &[p, e] : pf)
        for (int i = 0; i < e; i++) std::cout << ' ' << p;
    std::cout << '\n';
    return 0;
}