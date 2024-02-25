#pragma once

#include <vector>

// Segment Tree において区間 [l, r) をカバーする区間のノード番号を出力
// 区間の位置が小さい順に(左から)出力
// size は SegmentTree の size と同じ
std::vector<int> enumerate_segment_tree_range_covering_nodes(const int size, int l, int r) {
    std::vector<int> ret, ret_rev;
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

// Segment Tree において区間 [p, p + 1) が含まれる区間のノード番号を出力
// 区間の幅が小さい順に(下から)出力
// size は SegmentTree の size と同じ
std::vector<int> enumerate_segment_tree_point_containing_nodes(const int size, int p) {
    p += size;
    std::vector<int> ret;
    for (int i = 0; (1 << i) <= size; i++) ret.push_back(p >> i);
    return ret;
}