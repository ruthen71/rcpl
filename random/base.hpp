#pragma once

#include <cassert>
#include <chrono>
#include <cstdint>

template <bool set_seed> struct Random {
    uint64_t x_seed;

    Random(uint64_t seed = 0) {
        if (set_seed) {
            // set seed
            x_seed = seed;
        } else {
            // set random seed
            assert(seed == 0);
            x_seed =
                std::chrono::steady_clock::now().time_since_epoch().count();
        }
    }

    // http://xorshift.di.unimi.it/splitmix64.c
    uint64_t rand_int() {
        uint64_t z = (x_seed += 0x9e3779b97f4a7c15);
        z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9;
        z = (z ^ (z >> 27)) * 0x94d049bb133111eb;
        return z ^ (z >> 31);
    }

    // [0, mod - 1]
    uint64_t rand_int(uint64_t mod) {
        assert(mod > 0);
        return rand_int() % mod;
    }

    // [l, r]
    template <class T> T rand_int(T l, T r) {
        assert(l <= r);
        return T(l + rand_int(uint64_t(r - l + 1)));
    }
};

Random<true> rng_fixed;
Random<false> rng_test;
