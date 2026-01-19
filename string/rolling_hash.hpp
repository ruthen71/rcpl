#pragma once

#include <algorithm>
#include <cassert>
#include <chrono>
#include <random>
#include <vector>

#include "../math/modint261.hpp"

// Rolling Hash
template <class Mint> struct RollingHash {
    std::vector<Mint> pwr;
    const Mint base;

    RollingHash(const int n_max = 0, Mint base = generate_base()) : base(base) {
        pwr.resize(1, Mint(1));
        if (n_max > 0) extend(n_max);
    }

    static inline Mint generate_base() {
        std::mt19937_64 mt(
            std::chrono::steady_clock::now().time_since_epoch().count());
        std::uniform_int_distribution<uint64_t> rand(1, Mint::mod() - 1);
        return Mint(rand(mt));
    }

    void extend(int m = -1) {
        const int n = (int)(pwr.size());  // n >= 1
        if (m == -1) m = n * 2;           // m >= 2
        if (m > Mint::mod()) m = Mint::mod();
        if (n >= m) return;
        pwr.resize(m);
        for (int i = n; i < m; i++) pwr[i] = pwr[i - 1] * base;
    }

    // return base ^ n
    Mint power(const int n) {
        assert(n >= 0);
        while (n >= (int)(pwr.size())) extend();
        return pwr[n];
    }

    template <class T> std::vector<Mint> build(const std::vector<T>& s) const {
        const int n = (int)(s.size());
        std::vector<Mint> res(n + 1);
        for (int i = 0; i < n; i++) {
            res[i + 1] = res[i] * base + s[i];
        }
        return res;
    }

    std::vector<Mint> build(const std::string& s) const {
        const int n = (int)(s.size());
        std::vector<int> s2(n);
        for (int i = 0; i < n; i++) s2[i] = s[i];
        return build(s2);
    }

    Mint prod(const std::vector<Mint>& hs, const int l, const int r) {
        assert(0 <= l and l <= r and r <= (int)(hs.size()));
        return hs[r] - hs[l] * power(r - l);
    }

    Mint combine(Mint h1, Mint h2, int h2len) { return h1 * power(h2len) + h2; }
};
