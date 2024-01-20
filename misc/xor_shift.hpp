#pragma once
#include <cassert>

struct XorShift {
    unsigned long long x = 88172645463325252ULL;
    // [0, 2 ^ 64 - 1]
    unsigned long long rand_int() {
        x = x ^ (x << 7);
        x = x ^ (x >> 9);
        return x;
    }
    // [0, mod - 1]
    long long rand_int(long long mod) {
        assert(mod > 0);
        return rand_int() % mod;
    }
    // [l, r]
    long long rand_int(long long l, long long r) {
        assert(l <= r);
        return l + rand_int(r - l + 1);
    }
    // [0, 1.0]
    double rand_double() { return rand_int() * 5.42101086242752217004e-20; }
    // [l, r]
    double rand_double(double l, double r) {
        assert(l <= r);
        return l + rand_double() * (r - l);
    }
} rnd;