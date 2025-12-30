#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include <array>
#include <cassert>
#include <iostream>

#include "../bit_ceil.hpp"
#include "../countl_zero.hpp"
#include "../countr_zero.hpp"
#include "../lowbit.hpp"
#include "../popcount.hpp"
#include "../topbit.hpp"

void test1_bit_ceil() {
    const std::array<int, 8> input = {0, 1, 2, 3, 4, 5, 6, 7};
    const std::array<int, 8> expected = {1, 1, 2, 4, 4, 8, 8, 8};
    for (int i = 0; i < 8; i++) {
        assert(bit_ceil(input[i]) == expected[i]);
    }
}

void test2_countl_zero() {
    using u32 = unsigned int;
    const std::array<u32, 8> input = {0, 1, 2, 3, 4, 5, 6, 7};
    const std::array<int, 8> expected = {32, 31, 30, 30, 29, 29, 29, 29};
    for (int i = 0; i < 8; i++) {
        assert(countl_zero(input[i]) == expected[i]);
    }
}

void test3_countr_zero() {
    using u32 = unsigned int;
    const std::array<u32, 8> input = {0, 1, 2, 3, 4, 5, 6, 7};
    const std::array<int, 8> expected = {32, 0, 1, 0, 2, 0, 1, 0};
    for (int i = 0; i < 8; i++) {
        assert(countr_zero(input[i]) == expected[i]);
    }
}

void test4_popcount() {
    const std::array<int, 8> input = {0, 1, 2, 3, 4, 5, 6, 7};
    const std::array<int, 8> expected = {0, 1, 1, 2, 1, 2, 2, 3};
    for (int i = 0; i < 8; i++) {
        assert(popcount(input[i]) == expected[i]);
    }
}

void test5_topbit() {
    const std::array<int, 8> input = {0, 1, 2, 3, 4, 5, 6, 7};
    const std::array<int, 8> expected = {-1, 0, 1, 1, 2, 2, 2, 2};
    for (int i = 0; i < 8; i++) {
        assert(topbit(input[i]) == expected[i]);
    }
}

void test6_lowbit() {
    const std::array<int, 8> input = {0, 1, 2, 3, 4, 5, 6, 7};
    const std::array<int, 8> expected = {-1, 0, 1, 0, 2, 0, 1, 0};
    for (int i = 0; i < 8; i++) {
        assert(lowbit(input[i]) == expected[i]);
    }
}

int main() {
    test1_bit_ceil();
    test2_countl_zero();
    test3_countr_zero();
    test4_popcount();
    test5_topbit();
    test6_lowbit();
    int a, b;
    std::cin >> a >> b;
    std::cout << a + b << '\n';
    return 0;
}
