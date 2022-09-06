#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C"

#include <bits/stdc++.h>

#include "src/math/prime_table.hpp"

int main() {
    auto pt = prime_table(100000000);
    int n;
    std::cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        ans += pt[a];
    }
    std::cout << ans << '\n';
    return 0;
}