#pragma once

#include <cassert>
#include <chrono>
#include <cstdint>

#include "../misc/topbit.hpp"

template <bool auto_seed> struct Random {
    uint64_t x_seed;

    Random(uint64_t seed = 0) {
        if (auto_seed) {
            // set random seed
            assert(seed == 0);
            x_seed =
                std::chrono::steady_clock::now().time_since_epoch().count();
        } else {
            // set seed
            x_seed = seed;
        }
    }

    // http://xorshift.di.unimi.it/splitmix64.c
    // [0, 2^64 - 1]
    uint64_t rand_int() {
        uint64_t z = (x_seed += 0x9e3779b97f4a7c15);
        z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9;
        z = (z ^ (z >> 27)) * 0x94d049bb133111eb;
        return z ^ (z >> 31);
    }

    // [0, mod - 1]
    // rand_int() % mod だと mod が 2 べきでないときに偏る
    uint64_t rand_int(uint64_t mod) {
        assert(mod > 0);
        if ((mod & (mod - 1)) == 0) {
            // mod = 2^p
            // (mod - 1) = 0...01...1
            return rand_int() & (mod - 1);
        }
        // mod >= 3 (1 = 2^0, 2 = 2^1)
        int lg = topbit((uint64_t)mod);
        uint64_t mask = (lg == 63) ? ~0ULL : (1ULL << (lg + 1)) - 1;
        while (true) {
            uint64_t r = rand_int() & mask;
            if (r < mod) return r;
        }
    }

    // [l, r]
    template <class T> T rand_int(T l, T r) {
        assert(l <= r);
        return T(l + rand_int(uint64_t(r - l + 1)));
    }

    // [0.0, 1.0]
    double rand_double() {
        uint64_t v = rand_int(1ULL << 63);
        return double(v) / ((1ULL << 63) - 1);
    }

    // [l, r]
    double rand_double(double l, double r) {
        assert(l <= r);
        return l + rand_double() * (r - l);
    }
};

using RandomFixed = Random<false>;
using RandomAuto = Random<true>;

RandomAuto rng_auto;
