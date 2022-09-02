#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include <bits/stdc++.h>

#include "src/data_structure/cumulative_sum.hpp"

int main() {
    int N, Q;
    std::cin >> N >> Q;
    std::vector<long long> A(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];
    cumulative_sum<long long> rui(A);
    while (Q--) {
        int l, r;
        std::cin >> l >> r;
        std::cout << rui.sum(l, r) << '\n';
    }
    return 0;
}