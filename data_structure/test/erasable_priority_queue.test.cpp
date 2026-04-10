#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include <iostream>

#include "../../data_structure/erasable_priority_queue.hpp"
#include "../../misc/bit_ceil.hpp"
#include "../../segment_tree/enumerate_segment_tree_nodes.hpp"

std::vector<int> solve(std::vector<int>& a,
                       std::vector<std::tuple<int, int, int, int>>& query) {
    const int n = (int)(a.size());

    // 削除可能な priority_queue を乗せたセグ木を作成
    int size = bit_ceil(n);
    std::vector<ErasablePriorityQueue<int>> d(size << 1);
    for (int i = 0; i < n; i++) d[i + size].push(a[i]);

    std::vector<int> ans;
    for (auto&& [type, l, r, x] : query) {
        if (type == 1) {
            l--;
            auto nodes =
                enumerate_segment_tree_range_covering_nodes(size, l, r);
            for (auto&& i : nodes) d[i].push(x);
        } else if (type == 2) {
            l--;
            auto [ptype, pl, pr, px] = query[l];
            auto nodes =
                enumerate_segment_tree_range_covering_nodes(size, pl, pr);
            for (auto&& i : nodes) d[i].erase(px);
        } else {
            l--;
            auto nodes = enumerate_segment_tree_point_containing_nodes(size, l);
            int mx = 0;
            for (auto&& i : nodes) {
                if (d[i].size() > 0) mx = std::max(mx, d[i].top());
            }
            ans.push_back(mx);
        }
    }
    return ans;
}

void test1_sample1() {
    std::vector<int> a = {2, 7, 1, 8, 2, 8};
    std::vector<std::tuple<int, int, int, int>> query = {
        {3, 1, -1, -1}, {3, 3, -1, -1}, {3, 4, -1, -1}, {1, 1, 5, 4},
        {3, 1, -1, -1}, {3, 3, -1, -1}, {3, 4, -1, -1}, {1, 3, 6, 9},
        {3, 1, -1, -1}, {3, 3, -1, -1}, {3, 4, -1, -1}, {2, 4, -1, -1},
        {3, 1, -1, -1}, {3, 3, -1, -1}, {3, 4, -1, -1}};
    std::vector<int> sol = {2, 1, 8, 4, 4, 8, 4, 9, 9, 2, 9, 9};
    assert(solve(a, query) == sol);
}

void test2_sample2() {
    std::vector<int> a = {721, 78,  541, 256, 970, 478, 370, 467,
                          344, 542, 43,  166, 619, 17,  592, 222,
                          983, 729, 338, 747, 62,  452, 815, 838};
    std::vector<std::tuple<int, int, int, int>> query = {
        {3, 10, -1, -1}, {3, 8, -1, -1},  {3, 8, -1, -1},  {3, 13, -1, -1},
        {3, 9, -1, -1},  {1, 1, 17, 251}, {3, 3, -1, -1},  {3, 19, -1, -1},
        {3, 13, -1, -1}, {3, 22, -1, -1}, {3, 1, -1, -1},  {3, 15, -1, -1},
        {3, 18, -1, -1}, {3, 10, -1, -1}, {3, 15, -1, -1}, {1, 16, 19, 883},
        {1, 8, 23, 212}, {3, 5, -1, -1},  {3, 13, -1, -1}, {2, 6, -1, -1},
        {3, 15, -1, -1}, {1, 5, 18, 914}, {2, 17, -1, -1}, {3, 20, -1, -1},
        {1, 23, 23, 56}, {3, 13, -1, -1}, {2, 25, -1, -1}, {3, 13, -1, -1},
        {3, 13, -1, -1}, {3, 10, -1, -1}, {2, 16, -1, -1}, {1, 17, 22, 308},
        {3, 19, -1, -1}, {3, 17, -1, -1}, {3, 7, -1, -1}};
    std::vector<int> sol = {542, 467, 467, 619, 344, 541, 338, 619, 452,
                            721, 592, 729, 542, 592, 970, 619, 592, 747,
                            914, 914, 914, 914, 338, 983, 914};
    assert(solve(a, query) == sol);
}

int main() {
    // https://atcoder.jp/contests/abc342/tasks/abc342_g
    test1_sample1();
    test2_sample2();
    int a, b;
    std::cin >> a >> b;
    std::cout << a + b << '\n';
    return 0;
}
