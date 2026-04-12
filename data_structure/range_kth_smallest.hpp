#pragma once

#include <algorithm>

#include "../algebra/monoid/monoid_plus.hpp"
#include "../segment_tree/persistent_segment_tree.hpp"

template <class T> struct RangeKthSmallest {
  public:
    RangeKthSmallest() = default;

    explicit RangeKthSmallest(const std::vector<T>& a)
        : n((int)(a.size())), comp(a) {
        std::sort(comp.begin(), comp.end());
        comp.erase(std::unique(comp.begin(), comp.end()), comp.end());
        m = (int)(comp.size());
        seg = PersistentSegmentTree<MonoidPlus<int>>(m);
        for (int i = 0; i < n; i++) {
            int index =
                std::lower_bound(comp.begin(), comp.end(), a[i]) - comp.begin();
            seg.add(index, 1);
        }
    }

    T query(int l, int r, int k) {
        assert(0 <= l and l < r and r <= n);
        auto f = [&](int v) -> bool {
            return seg.prod(0, v, r) - seg.prod(0, v, l) >= k + 1;
        };
        int ok = m, ng = 0;
        while (ok - ng > 1) {
            int md = (ok + ng) / 2;
            if (f(md)) {
                ok = md;
            } else {
                ng = md;
            }
        }
        return comp[ok - 1];
    }

  private:
    int n, m;
    std::vector<T> comp;
    PersistentSegmentTree<MonoidPlus<int>> seg;
};
