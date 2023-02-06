#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D"

#include <bits/stdc++.h>

#include "dp/sliding_window_minimum.hpp"

int main() {
    int N, L;
    std::cin >> N >> L;
    std::vector<int> a(N);
    for (int i = 0; i < N; i++) std::cin >> a[i];
    auto b = sliding_window_minimum(a, L);
    for (int i = 0; i < N - L + 1; i++) std::cout << b[i] << " \n"[i == N - L];
    return 0;
}