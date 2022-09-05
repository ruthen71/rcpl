#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D"

#include <bits/stdc++.h>

#include "src/math/divisor.hpp"

int main() {
    long long a, b, c;
    std::cin >> a >> b >> c;
    auto dv = divisor(c);
    int ans = 0;
    for (auto &d : dv) {
        if (a <= d and d <= b) {
            ans++;
        }
    }
    std::cout << ans << '\n';
    return 0;
}