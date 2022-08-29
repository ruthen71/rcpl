#pragma once

#include "src/data_structure/fenwick_tree.hpp"

template <class T> long long inversion_number(std::vector<T>& A) {
    auto B = A;
    sort(B.begin(), B.end());
    B.erase(unique(B.begin(), B.end()), B.end());
    int N = (int)B.size();
    fenwick_tree<int> fen(N);
    long long ret = 0;
    for (auto& ai : A) {
        int i = lower_bound(B.begin(), B.end(), ai) - B.begin();
        ret += fen.sum(i + 1, N);
        fen.add(i, 1);
    }
    return ret;
}

/**
 * @brief Inversion Number (転倒数)
 * @docs docs/data_structure/inversion_number.md
 */
