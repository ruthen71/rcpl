#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>

#include "../base.hpp"

void test1_set_same_seed() {
    for (int seed = 0; seed < 10; seed++) {
        Random<true> rng_a(seed);
        Random<true> rng_b(seed);
        std::vector<uint64_t> a(10), b(10);
        for (int i = 0; i < 10; i++) {
            a[i] = rng_a.rand_int();
            b[i] = rng_b.rand_int();
        }
        assert(a == b);
    }
}

void test2_set_different_seed() {
    for (int seed = 0; seed < 10; seed++) {
        Random<true> rng_a(seed);
        Random<true> rng_b(seed + 1);
        std::vector<uint64_t> a(10), b(10);
        for (int i = 0; i < 10; i++) {
            a[i] = rng_a.rand_int();
            b[i] = rng_b.rand_int();
        }
        assert(a != b);
    }
}

void test3_set_auto_seed() {
    Random<false> rng;
    uint64_t s = 0;
    for (int i = 0; i < 10; i++) {
        s += rng.rand_int();
    }
}

int main() {
    test1_set_same_seed();
    test2_set_different_seed();
    test3_set_auto_seed();
    int a, b;
    std::cin >> a >> b;
    std::cout << a + b << '\n';
    return 0;
}
