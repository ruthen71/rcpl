#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include <iostream>

#include "../../algebra/acted_monoid/acted_monoid_max01_flip.hpp"
#include "../../data_structure/lazy_segment_tree.hpp"

std::vector<int> solve(std::string& s,
                       std::vector<std::tuple<int, int, int>>& query) {
    const int n = (int)(s.size());
    std::vector<Max01<int>> segi(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            segi[i] = {1, 1, 1, 0, 0, 0, 1};
        } else {
            segi[i] = {0, 0, 0, 1, 1, 1, 1};
        }
    }
    LazySegmentTree<ActedMonoidMax01Flip<int>> seg(segi);
    std::vector<int> ans;
    for (auto&& [type, l, r] : query) {
        l--;
        if (type == 1) {
            seg.apply(l, r, 1);
        } else {
            ans.push_back(seg.prod(l, r).m1);
        }
    }
    return ans;
}

// https://atcoder.jp/contests/abc322/tasks/abc322_f
void test1_sample1() {
    std::string s = "1101110";
    std::vector<std::tuple<int, int, int>> query = {
        {2, 1, 7}, {2, 2, 4}, {1, 3, 6}, {2, 5, 6}, {1, 4, 7}, {2, 1, 7}};
    std::vector<int> sol = {3, 1, 0, 7};
    assert(solve(s, query) == sol);
}

int main() {
    test1_sample1();
    int a, b;
    std::cin >> a >> b;
    std::cout << a + b << '\n';
    return 0;
}
