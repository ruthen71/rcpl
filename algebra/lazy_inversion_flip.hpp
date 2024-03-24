#pragma once

// https://atcoder.jp/contests/practice2/tasks/practice2_l
// MSF
template <class T> struct LazyInversionFlip {
    using S = std::tuple<T, T, T, T>;  // {0, 1, 01, 10}
    using F = bool;
    using value_type_S = S;
    using value_type_F = F;
    static constexpr S op(S a, S b) {
        auto &&[a0, a1, a01, a10] = a;
        auto &&[b0, b1, b01, b10] = b;
        return {a0 + b0, a1 + b1, a01 + b01 + a0 * b1, a10 + b10 + a1 * b0};
    }
    static constexpr S e() { return {0, 0, 0, 0}; }
    static constexpr S mapping(F f, S x) {
        auto &&[x0, x1, x01, x10] = x;
        if (f) {
            return {x1, x0, x10, x01};
        } else {
            return x;
        }
    }
    static constexpr F composition(F f, F g) { return f ^ g; }
    static constexpr F id() { return false; }
};