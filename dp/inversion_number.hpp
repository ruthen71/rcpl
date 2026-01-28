#pragma once

#include <algorithm>
#include "../data_structure/fenwick_tree.hpp"

// a を sorted にするための隣接 swap の操作回数
template <class T> long long inversion_number(std::vector<T>& a) {
    auto za = a;
    std::sort(za.begin(), za.end());
    za.erase(std::unique(za.begin(), za.end()), za.end());
    const int m = (int)(za.size());
    FenwickTree<int> seg(m);
    long long res = 0;
    for (auto&& e : a) {
        int i = std::lower_bound(za.begin(), za.end(), e) - za.begin();
        res += seg.sum(i + 1, m);
        seg.add(i, 1);
    }
    return res;
}

// a -> b にするための隣接 swap の操作回数
template <class T>
long long inversion_number(std::vector<T>& a, std::vector<T>& b) {
    auto za = a;
    auto zb = b;
    std::sort(za.begin(), za.end());
    std::sort(zb.begin(), zb.end());
    assert(za == zb);
    za.erase(std::unique(za.begin(), za.end()), za.end());
    // a = [100, 1, 10, 1], b = [10, 1, 1, 100] (n = 4, m = 3)
    // a = [3, 1, 0, 2] を b = [0, 1, 2, 3] にするための操作回数に帰着する
    // g = [[1, 2], [0], [3]] になる
    const int n = (int)(a.size());
    const int m = (int)(za.size());
    std::vector<std::vector<int>> g(m);
    for (int i = 0; i < n; i++) {
        int index = std::lower_bound(za.begin(), za.end(), b[i]) - za.begin();
        g[index].push_back(i);
    }
    std::vector<int> g_offset(m, 0);
    FenwickTree<int> seg(n);
    long long res = 0;
    for (int i = 0; i < n; i++) {
        int index = std::lower_bound(za.begin(), za.end(), a[i]) - za.begin();
        int offset = g_offset[index];
        int a_pos = g[index][offset];
        res += seg.sum(a_pos + 1, n);
        seg.add(a_pos, 1);
        g_offset[index]++;
    }
    return res;
}
