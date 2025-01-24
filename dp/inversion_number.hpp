#pragma once

#include "data_structure/fenwick_tree.hpp"
#include <algorithm>

template <class T> long long inversion_number(std::vector<T>& a) {
    auto z = a;
    std::sort(z.begin(), z.end());
    z.erase(std::unique(z.begin(), z.end()), z.end());
    const int n = (int)(z.size());
    FenwickTree<int> fen(n);
    long long ret = 0;
    for (auto& ai : a) {
        int i = lower_bound(z.begin(), z.end(), ai) - z.begin();
        ret += fen.sum(i + 1, n);
        fen.add(i, 1);
    }
    return ret;
}