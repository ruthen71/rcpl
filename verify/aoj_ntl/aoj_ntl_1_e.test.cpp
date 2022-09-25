#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E"

#include <bits/stdc++.h>

#include "src/math/extgcd.hpp"

int main() {
    long long a, b, x, y;
    std::cin >> a >> b;
    extgcd(a, b, x, y);
    std::cout << x << ' ' << y << '\n';
    return 0;
}