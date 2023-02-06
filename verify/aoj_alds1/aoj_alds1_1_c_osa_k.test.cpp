#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C"

#include <bits/stdc++.h>

#include "math/osa_k.hpp"

int main() {
    auto osak = osa_k(100000000);
    int n;
    std::cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        ans += osak.is_prime(a);
    }
    std::cout << ans << '\n';
    return 0;
}