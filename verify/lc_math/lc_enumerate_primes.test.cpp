#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_primes"

#include <bits/stdc++.h>

#include "math/enumerate_primes.hpp"

int main() {
    int n, a, b;
    std::cin >> n >> a >> b;
    auto pl = enumerate_primes(n);
    std::vector<int> ans;
    for (int i = b; i < pl.size(); i += a) ans.push_back(pl[i]);
    std::cout << pl.size() << ' ' << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) std::cout << ans[i] << " \n"[i == ans.size() - 1];
    return 0;
}