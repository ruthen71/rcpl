#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include <iostream>

#include "../../algebra/monoid/monoid_plus.hpp"
#include "../../segment_tree/segment_tree_recursion.hpp"

int main() {
    int N, Q;
    std::cin >> N >> Q;
    std::vector<long long> a(N);
    for (int i = 0; i < N; i++) std::cin >> a[i];
    SegmentTreeRecursion<MonoidPlus<long long>> seg_add(a);
    SegmentTreeRecursion<MonoidPlus<long long>> seg_set(a);
    while (Q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int p, x;
            std::cin >> p >> x;
            seg_add.add(p, x);
            seg_set.set(p, seg_set.get(p) + x);
        } else {
            int l, r;
            std::cin >> l >> r;
            assert(seg_add.prod(l, r) == seg_set.prod(l, r));
            std::cout << seg_add.prod(l, r) << '\n';
        }
    }
    return 0;
}
