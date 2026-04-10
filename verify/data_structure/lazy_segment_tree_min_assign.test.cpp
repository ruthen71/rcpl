#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F"

#include <iostream>
#include <limits>

#include "../../algebra/acted_monoid/acted_monoid_max_assign.hpp"
#include "../../algebra/acted_monoid/acted_monoid_min_assign.hpp"
#include "../../data_structure/lazy_segment_tree.hpp"

int main() {
    int N, Q;
    std::cin >> N >> Q;
    constexpr int INF = std::numeric_limits<int>::max();
    LazySegmentTree<ActedMonoidMinAssign<int, INF, INF>> segmin(N);
    LazySegmentTree<ActedMonoidMaxAssign<int, INF, INF>> segmax(N);
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
