#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D"

#include <bits/stdc++.h>

#include "algebra/dual_set.hpp"
#include "data_structure/dual_segment_tree.hpp"

int main() {
    int N, Q;
    std::cin >> N >> Q;
    DualSegmentTree<DualSet<int>> seg(N);
    while (Q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int l, r, x;
            std::cin >> l >> r >> x;
            seg.apply(l, r + 1, x);
        } else {
            int i;
            std::cin >> i;
            std::cout << seg[i] << '\n';
        }
    }
    return 0;
}
