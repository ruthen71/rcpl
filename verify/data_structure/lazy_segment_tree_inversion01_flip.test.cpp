#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include <iostream>

#include "../../algebra/acted_monoid/acted_monoid_inversion01_flip.hpp"
#include "../../data_structure/lazy_segment_tree.hpp"

std::vector<long long> solve(std::vector<int>& s,
                             std::vector<std::tuple<int, int, int>>& query) {
    const int n = (int)(s.size());
    std::vector<Inversion01<long long>> segi(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == 0) {
            segi[i] = {1, 0, 0};
        } else {
            segi[i] = {0, 1, 0};
        }
    }
    LazySegmentTree<ActedMonoidInversion01Flip<long long>> seg(segi);
    std::vector<long long> ans;
    for (auto&& [type, l, r] : query) {
        l--;
        if (type == 1) {
            seg.apply(l, r, 1);
        } else {
            ans.push_back(seg.prod(l, r).c10);
        }
    }
    return ans;
}

// https://atcoder.jp/contests/practice2/tasks/practice2_l
void test1_sample1() {
    std::vector<int> a = {0, 1, 0, 0, 1};
    std::vector<std::tuple<int, int, int>> query = {
        {2, 1, 5}, {1, 3, 4}, {2, 2, 5}, {1, 1, 3}, {2, 1, 2}};
    std::vector<long long> sol = {2, 0, 1};
    assert(solve(a, query) == sol);
}

int main() {
    test1_sample1();
    int a, b;
    std::cin >> a >> b;
    std::cout << a + b << '\n';
    return 0;
}
