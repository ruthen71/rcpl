#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E"

#include <bits/stdc++.h>

#include "algebra/monoid_f/monoid_add.hpp"
#include "data_structure/dual_segment_tree.hpp"

int main() {
    int N, Q;
    std::cin >> N >> Q;
    DualSegmentTree<MonoidAdd<long long>> seg(N);
    while (Q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int l, r, x;
            std::cin >> l >> r >> x;
            seg.apply(--l, r, x);
        } else {
            int i;
            std::cin >> i;
            std::cout << seg[--i] << '\n';
        }
    }
    return 0;
}
