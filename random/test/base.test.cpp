#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>

#include "../base.hpp"

void test1_same_seed() {
    for (int seed = 0; seed < 10; seed++) {
        RandomFixed rng_a(seed);
        RandomFixed rng_b(seed);
        std::vector<uint64_t> a(10), b(10);
        for (int i = 0; i < 10; i++) {
            a[i] = rng_a.rand_int();
            b[i] = rng_b.rand_int();
        }
        assert(a == b);
    }
}

void test2_not_same_seed() {
    for (int seed = 0; seed < 10; seed++) {
        RandomFixed rng_a(seed);
        RandomFixed rng_b(seed + 1);
        std::vector<uint64_t> a(10), b(10);
        for (int i = 0; i < 10; i++) {
            a[i] = rng_a.rand_int();
            b[i] = rng_b.rand_int();
        }
        assert(a != b);
    }
}

void test3_auto_seed() {
    RandomAuto rng_a;
    RandomFixed rng_b(0);
    std::vector<uint64_t> a(10), b(10);
    for (int i = 0; i < 10; i++) {
        a[i] = rng_a.rand_int();
        b[i] = rng_b.rand_int();
    }
    assert(a != b);
}

void test4_negative() {
    RandomAuto rng;
    auto v = rng.rand_int(-100, -1);
    assert(-100 <= v and v <= -1);
}

void test5_big() {
    RandomAuto rng;
    const int BIG_INT = 1000000000;
    auto v = rng.rand_int(-BIG_INT, BIG_INT);
    assert(-BIG_INT <= v and v <= BIG_INT);
}

void test6_double() {
    RandomAuto rng;
    auto v = rng.rand_double();
    assert(0.0 <= v and v <= 1.0);
}

int main() {
    test1_same_seed();
    test2_not_same_seed();
    test3_auto_seed();
    test4_negative();
    test5_big();
    test6_double();
    int a, b;
    std::cin >> a >> b;
    std::cout << a + b << '\n';
    return 0;
}
