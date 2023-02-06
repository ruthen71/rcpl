#pragma once

#include "string/rolling_hash.hpp"

RollingHash<ModInt261> rh;

template <class Mint> struct MonoidRollingHash {
    using S = std::pair<Mint, int>;
    using value_type = S;
    static constexpr S op(S a, S b) { return {rh.combine(a.first, b.first, b.second), a.second + b.second}; }
    static constexpr S e() { return {0, 0}; }
};