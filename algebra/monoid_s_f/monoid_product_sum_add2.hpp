#pragma once

#include <utility>

// https://atcoder.jp/contests/abc357/tasks/abc357_f
template <class T> struct MonoidProductSum {
    using S = std::tuple<T, T, T, int>;  // sum(A[i] * B[i]), sum(A[i]), sum(B[i]), size
    static constexpr S op(S a, S b) {
        auto [aab, aa, ab, as] = a;
        auto [bab, ba, bb, bs] = b;
        return {aab + bab, aa + ba, ab + bb, as + bs};
    }
    static constexpr S e() { return {T(0), T(0), T(0), 0}; }
};

template <class T> struct MonoidAdd2 {
    using F = std::pair<T, T>;
    static constexpr F composition(F f, F g) {
        auto [fa, fb] = f;
        auto [ga, gb] = g;
        return {fa + ga, fb + gb};
    }
    static constexpr F id() { return {T(0), T(0)}; }
};

template <class T> struct MonoidProductSumAdd2 {
    using MS = MonoidS<T>;
    using MF = MonoidF<T>;
    using S = typename MS::S;
    using F = typename MF::F;
    static constexpr S mapping(F f, S x) {
        auto [fa, fb] = f;
        auto [xab, xa, xb, xs] = x;
        return {xab + (fa * xb) + (fb * xa) + (fa * fb * xs), xa + (fa * xs), xb + (fb * xs), xs};
    }
};