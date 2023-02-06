#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F"

#include <bits/stdc++.h>

#include "algebra/lazy_min_set.hpp"
#include "data_structure/lazy_segment_tree.hpp"

int main() {
    int N, Q;
    std::cin >> N >> Q;
    LazySegmentTree<LazyMinSet<int>> seg(N);
    while (Q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int l, r, x;
            std::cin >> l >> r >> x;
            seg.apply(l, r + 1, x);
        } else {
            int l, r;
            std::cin >> l >> r;
            std::cout << seg.prod(l, r + 1) << '\n';
        }
    }
    return 0;
}
