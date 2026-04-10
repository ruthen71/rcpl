#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include <iostream>

#include "../../enumerate/enumerate_product.hpp"

void test1_simple() {
    std::vector<int> a = {1, 2, 3};
    std::vector<std::vector<int>> ps;
    auto f = [&](std::vector<int> p) -> void {
        ps.push_back(p);
        return;
    };
    enumerate_product(a, f);
    std::vector<std::vector<int>> ps2 = {{0, 0, 0}, {0, 0, 1}, {0, 0, 2},
                                         {0, 1, 0}, {0, 1, 1}, {0, 1, 2}};
    assert(ps == ps2);
}

void test2_zero() {
    // 一度 0 以下の整数が出現した場合
    // それ以降の整数の値によらず p は列挙されない
    std::vector<int> a = {1, 0, 1000000000, 1000000000};
    std::vector<std::vector<int>> ps;
    auto f = [&](std::vector<int> p) -> void {
        ps.push_back(p);
        return;
    };
    enumerate_product(a, f);
    assert(ps.size() == 0);
}

int main() {
    test1_simple();
    test2_zero();
    int a, b;
    std::cin >> a >> b;
    std::cout << a + b << '\n';
    return 0;
}
