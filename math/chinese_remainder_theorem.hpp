#pragma once

#include <cassert>
#include <vector>
#include "math/linear_diophantine.hpp"

// (rem, mod)
std::pair<long long, long long> chinese_remainder_theorem(const std::vector<long long>& r, const std::vector<long long>& m) {
    assert(r.size() == m.size());
    const int n = (int)(r.size());
    long long r0 = 0, m0 = 1;
    for (int i = 0; i < n; i++) {
        assert(m[i] >= 1);
        long long r1 = r[i] % m[i], m1 = m[i];
        if (r1 < 0) r1 += m[i];
        if (m0 < m1) {
            std::swap(r0, r1);
            std::swap(m0, m1);
        }
        // m0 > m1
        if (m0 % m1 == 0) {
            if (r0 % m1 != r1) return {0, 0};
            continue;
        }
        // (r0, m0), (r1, m1) -> (r2, m2 = lcm(m0, m1))
        // r2 % m0 = r0
        // -> r2 = r0 + x * m0
        // r2 % m1 = r1
        // -> (r0 + x * m0) % m1 = r1
        // -> x * m0 = r1 - r0 (mod m1)
        auto [x, h] = linear_congruence(m0, r1 - r0, m1);
        if (x == -1 and h == -1) return {0, 0};
        r0 += x * m0;
        m0 *= h;
        r0 %= m0;
        if (r0 < 0) r0 += m0;
    }
    return {r0, m0};
}