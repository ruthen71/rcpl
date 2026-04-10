#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include <iostream>

#include "../../algebra/acted_monoid/acted_monoid_product_sum_add2.hpp"
#include "../../data_structure/lazy_segment_tree.hpp"
#include "../../math/static_modint.hpp"
using mint = mint998;

std::vector<int> solve(std::vector<int>& a,
                       std::vector<int>& b,
                       std::vector<std::tuple<int, int, int, int>>& query) {
    const int n = (int)(a.size());
    std::vector<ProductSum<mint>> segi(n);
    for (int i = 0; i < n; i++) {
        segi[i] = {mint(a[i]) * mint(b[i]), mint(a[i]), mint(b[i])};
    }
    LazySegmentTree<ActedMonoidProductSumAdd2<mint>> seg(segi);
    std::vector<int> ans;
    for (auto&& [type, l, r, x] : query) {
        l--;
        if (type == 1) {
            seg.apply(l, r, {x, 0});
        } else if (type == 2) {
            seg.apply(l, r, {0, x});
        } else {
            ans.push_back(seg.prod(l, r).ab.val());
        }
    }
    return ans;
}

void test1_sample1() {
    std::vector<int> a = {1, 3, 5, 6, 8};
    std::vector<int> b = {3, 1, 2, 1, 2};
    std::vector<std::tuple<int, int, int, int>> query = {
        {3, 1, 3, -1}, {1, 2, 5, 3}, {3, 1, 3, -1},
        {1, 1, 3, 1},  {2, 5, 5, 2}, {3, 1, 5, -1}};
    std::vector<int> sol = {16, 25, 84};
    assert(solve(a, b, query) == sol);
}

void test2_sample2() {
    std::vector<int> a = {1000000000, 1000000000};
    std::vector<int> b = {1000000000, 1000000000};
    std::vector<std::tuple<int, int, int, int>> query = {
        {3, 1, 1, -1}, {1, 2, 2, 1000000000}, {3, 1, 2, -1}};
    std::vector<int> sol = {716070898, 151723988};
    assert(solve(a, b, query) == sol);
}

int main() {
    // https://atcoder.jp/contests/abc357/tasks/abc357_f
    test1_sample1();
    test2_sample2();
    int a, b;
    std::cin >> a >> b;
    std::cout << a + b << '\n';
    return 0;
}
