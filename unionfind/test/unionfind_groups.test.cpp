#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include <iostream>

#include "../../unionfind/unionfind.hpp"

void test1_zero() {
    Unionfind uf(0);
    assert(uf.groups() == std::vector<std::vector<int>>());
}

void test2_empty() {
    Unionfind uf;
    assert(uf.groups() == std::vector<std::vector<int>>());
}

void test3_assign() {
    Unionfind uf;
    uf = Unionfind(10);
}

void test4_simple() {
    Unionfind uf(2);
    assert(uf.same(0, 1) == false);
    int x = uf.merge(0, 1);
    assert(uf.leader(0) == x);
    assert(uf.leader(1) == x);
    assert(uf.same(0, 1) == true);
    assert(uf.size(0) == 2);
}

void test5_line() {
    int n = 500000;
    Unionfind uf(n);
    for (int i = 0; i < n - 1; i++) {
        uf.merge(i, i + 1);
    }
    assert(uf.size(0) == n);
    assert(uf.groups().size() == 1);
}

void test6_line_reverse() {
    int n = 500000;
    Unionfind uf(n);
    for (int i = n - 2; i >= 0; i--) {
        uf.merge(i, i + 1);
    }
    assert(uf.size(0) == n);
    assert(uf.groups().size() == 1);
}

void test7_groups() {
    int n = 5;
    Unionfind uf(n);
    uf.merge(0, 1);
    uf.merge(2, 3);
    uf.merge(2, 4);
    auto gp = uf.groups();
    for (auto&& v : gp) std::sort(v.begin(), v.end());
    std::sort(gp.begin(), gp.end());
    std::vector<std::vector<int>> gp_sorted = {{0, 1}, {2, 3, 4}};
    assert(gp == gp_sorted);
}

int main() {
    test1_zero();
    test2_empty();
    test3_assign();
    test4_simple();
    test5_line();
    test6_line_reverse();
    test7_groups();
    int a, b;
    std::cin >> a >> b;
    std::cout << a + b << '\n';
    return 0;
}
