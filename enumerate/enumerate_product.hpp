#pragma once

#include <cassert>
#include <vector>

// enumerate product
// enumerate p (0 <= p[i] < a[i])
template <class F> void enumerate_product(std::vector<int> a, F f) {
    const int n = (int)(a.size());
    std::vector<int> p;
    auto dfs = [&](auto g, int i) -> void {
        if (i == n) {
            f(p);
            return;
        }
        for (int x = 0; x < a[i]; x++) {
            p.push_back(x);
            g(g, i + 1);
            p.pop_back();
        }
    };
    dfs(dfs, 0);
    return;
}
