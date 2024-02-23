#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E"

#include <bits/stdc++.h>

#include "math/extended_gcd.hpp"

int main() {
    long long a, b, x, y;
    std::cin >> a >> b;
    auto [x, y, g] = extended_gcd(a, b);
    std::cout << x << ' ' << y << '\n';
    return 0;
}