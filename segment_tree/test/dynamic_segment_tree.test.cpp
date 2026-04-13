#define PROBLEM "https://yukicoder.me/problems/no/789"

#include <iostream>

#include "../../algebra/monoid/monoid_plus.hpp"
#include "../../segment_tree/dynamic_segment_tree.hpp"

int main() {
    int n;
    std::cin >> n;
    const int m = 1000000001;
    // Q log_2(N) = n log_2(m) = 3000000 くらい
    DynamicSegmentTree<MonoidPlus<long long>, 3000000> seg_add(m);
    DynamicSegmentTree<MonoidPlus<long long>, 3000000> seg_set(m);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int type;
        std::cin >> type;
        if (type == 0) {
            int x, y;
            std::cin >> x >> y;
            seg_add.add(x, y);
            seg_set.set(x, seg_set.get(x) + y);
        } else {
            int l, r;
            std::cin >> l >> r;
            r++;
            assert(seg_add.prod(l, r) == seg_set.prod(l, r));
            ans += seg_add.prod(l, r);
        }
    }
    std::cout << ans << '\n';
    return 0;
}
