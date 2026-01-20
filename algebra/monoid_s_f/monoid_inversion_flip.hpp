#pragma once

// https://atcoder.jp/contests/practice2/tasks/practice2_l
// MS
template <class T> struct MonoidInversion {
    using S = std::tuple<T, T, T, T>;  // {0, 1, 01, 10}
    static constexpr S op(S a, S b) {
        auto&& [a0, a1, a01, a10] = a;
        auto&& [b0, b1, b01, b10] = b;
        return {a0 + b0, a1 + b1, a01 + b01 + a0 * b1, a10 + b10 + a1 * b0};
    }
    static constexpr S e() { return {T(0), T(0), T(0), T(0)}; }
};
#include "../../algebra/monoid_f/monoid_flip.hpp"
// MSF
template <class T> struct MonoidInversionFlip {
    using MS = MonoidInversion<T>;
    using MF = MonoidFlip;
    using S = typename MS::S;
    using F = typename MF::F;
    static constexpr S mapping(F f, S x) {
        if (!f) return x;
        auto&& [x0, x1, x01, x10] = x;
        return {x1, x0, x10, x01};
    }
};
