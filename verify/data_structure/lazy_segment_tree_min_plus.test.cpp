#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H"

#include <iostream>
#include <limits>

#include "../../algebra/acted_monoid/acted_monoid_max_plus.hpp"
#include "../../algebra/acted_monoid/acted_monoid_min_plus.hpp"
#include "../../data_structure/lazy_segment_tree.hpp"

int main() {
    int N, Q;
    std::cin >> N >> Q;
    constexpr long long INF = std::numeric_limits<long long>::max();
    LazySegmentTree<ActedMonoidMinPlus<long long, INF>> segmin(N);
    LazySegmentTree<ActedMonoidMaxPlus<long long, INF>> segmax(N);
    while (Q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int l, r, x;
            std::cin >> l >> r >> x;
            r++;
            segmin.apply(l, r, x);
            segmax.apply(l, r, -x);
        } else {
            int l, r;
            std::cin >> l >> r;
            r++;
            assert(segmin.prod(l, r) == -segmax.prod(l, r));
            std::cout << segmin.prod(l, r) << '\n';
        }
    }
    return 0;
}
