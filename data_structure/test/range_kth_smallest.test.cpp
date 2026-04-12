#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"

#include <iostream>

#include "../../data_structure/range_kth_smallest.hpp"

int main() {
    int N, Q;
    std::cin >> N >> Q;
    std::vector<long long> a(N);
    for (int i = 0; i < N; i++) std::cin >> a[i];
    RangeKthSmallest rks(a);
    while (Q--) {
        int l, r, k;
        std::cin >> l >> r >> k;
        std::cout << rks.query(l, r, k) << '\n';
    }
    return 0;
}
