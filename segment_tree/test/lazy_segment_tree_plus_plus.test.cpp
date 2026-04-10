#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G"

#include <iostream>

#include "../../algebra/acted_monoid/acted_monoid_plus_plus.hpp"
#include "../../segment_tree/lazy_segment_tree.hpp"

int main() {
    int N, Q;
    std::cin >> N >> Q;
    LazySegmentTree<ActedMonoidPlusPlus<long long>> seg(N);
    while (Q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int l, r, x;
            std::cin >> l >> r >> x;
            l--;
            seg.apply(l, r, x);
        } else {
            int l, r;
            std::cin >> l >> r;
            l--;
            std::cout << seg.prod(l, r) << '\n';
        }
    }
    return 0;
}
