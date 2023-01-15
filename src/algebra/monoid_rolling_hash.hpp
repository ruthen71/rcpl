#pragma once

#include "src/math/modint261.hpp"
#include "src/string/rolling_hash.hpp"

rolling_hash<modint261> rh;

template <class Mint> struct monoid_rolling_hash {
    using S = std::pair<Mint, int>;
    using value_type = S;
    static constexpr S op(S a, S b) { return {rh.combine(a.first, b.first, b.second), a.second + b.second}; }
    static constexpr S e() { return {0, 0}; }
};

/**
 * @docs docs/algebra/monoid_rolling_hash.md
 */