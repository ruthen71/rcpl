#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D"

#include <iostream>
#include <numeric>

#include "algebra/monoid/monoid_assign.hpp"
#include "data_structure/dual_segment_tree.hpp"

int main() {
    int N, Q;
    std::cin >> N >> Q;
    constexpr int NONE = std::numeric_limits<int>::max();
    DualSegmentTree<MonoidAssign<int, NONE>> seg(N);
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
