#pragma once

#include <vector>
#include <cassert>
#include <algorithm>

// 長さ size (2べき) の Segment Tree において区間 [l, r) をカバーする区間のノード番号を返す
// 区間の位置が小さい順に (左から) 返す
template <class T> std::vector<T> enumerate_segment_tree_range_covering_nodes(const T size, T l, T r) {
    std::vector<T> ret, ret_rev;
    l += size;
    r += size;
    while (l < r) {
        if (l & 1) ret.push_back(l++);
        if (r & 1) ret_rev.push_back(--r);
        l >>= 1;
        r >>= 1;
    }
    std::reverse(ret_rev.begin(), ret_rev.end());
    ret.insert(ret.end(), ret_rev.begin(), ret_rev.end());
    return ret;
}

// 長さ size (2べき) の Segment Tree において seg[p] が含まれる区間のノード番号を返す
// 区間の幅が小さい順に (下から) 返す
template <class T> std::vector<T> enumerate_segment_tree_point_containing_nodes(const T size, T p) {
    p += size;
    std::vector<T> ret;
    for (int i = 0; (1LL << i) <= size; i++) ret.push_back(p >> i);
    return ret;
}

// 長さ size (2べき) の Segment Tree においてノード番号 i に対応する区間 [l, r) を返す
// https://atcoder.jp/contests/abc349/tasks/abc349_d
// https://atcoder.jp/contests/abc355/tasks/abc355_e
template <class T> std::pair<T, T> segment_tree_node_to_range(const T size, const T i) {
    assert(size > 0 and i > 0);
    // (1 << n) = size
    const int n = 63 - __builtin_clzll(size);
    // i の最上位ビット
    const int topbiti = 63 - __builtin_clzll(i);
    // [(2 ^ x) * y, (2 ^ x) * (y + 1))
    const int x = n - topbiti;
    const T y = i - (1LL << topbiti);
    return {(1LL << x) * y, (1LL << x) * (y + 1)};
}