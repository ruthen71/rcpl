#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I"

#include <iostream>
#include <limits>

#include "../../algebra/acted_monoid/acted_monoid_plus_assign.hpp"
#include "../../data_structure/lazy_segment_tree.hpp"

int main() {
    int N, Q;
    std::cin >> N >> Q;
    constexpr long long NONE = std::numeric_limits<long long>::max();
    LazySegmentTree<ActedMonoidPlusAssign<long long, NONE>> seg(N);
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
