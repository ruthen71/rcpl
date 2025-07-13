#pragma once

#include <cassert>
#include <utility>
#include <vector>

// 商列挙 (quotient enumeration)
// {l, r, d}: floor(n / x) = d となる x が l <= x <= r (閉区間)
template <class T> std::vector<std::tuple<T, T, T>> quotient_enumeration(T n) {
    assert(n > 0);
    std::vector<std::tuple<T, T, T>> res;
    T l = T(1);
    while (l < n) {
        T d = n / l;
        T r = n / d;
        res.emplace_back(l, r, d);
        l = r + 1;
    }
    return res;
}
