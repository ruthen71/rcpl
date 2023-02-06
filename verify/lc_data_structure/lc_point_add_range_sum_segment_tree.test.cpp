#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include <bits/stdc++.h>

#include "algebra/monoid_sum.hpp"
#include "data_structure/segment_tree.hpp"

int main() {
    int N, Q;
    std::cin >> N >> Q;
    std::vector<long long> a(N);
    for (int i = 0; i < N; i++) std::cin >> a[i];
    segment_tree<monoid_sum<long long>> fen(a);
    while (Q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int p, x;
            std::cin >> p >> x;
            fen.chset(p, x);
        } else {
            int l, r;
            std::cin >> l >> r;
            std::cout << fen.prod(l, r) << '\n';
        }
    }
    return 0;
}
