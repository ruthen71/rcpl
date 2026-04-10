#pragma once

#include "../monoid/monoid_xor.hpp"

// https://atcoder.jp/contests/practice2/tasks/practice2_l
template <class T> struct Inversion01 {
    // c0: 0 の個数, c1: 1 の個数, c10: 転倒数
    T c0, c1, c10;
};

template <class T> struct MonoidInversion01 {
    using value_type = Inversion01<T>;
    static constexpr value_type operation(const value_type& a,
                                          const value_type& b) {
        return {a.c0 + b.c0, a.c1 + b.c1, a.c10 + b.c10 + a.c1 * b.c0};
    }
    static constexpr value_type identity() { return {T(0), T(0), T(0)}; }
};

template <class T> struct ActedMonoidInversion01Flip {
    using MS = MonoidInversion01<T>;
    using MF = MonoidXor<int>;
    using S = typename MS::value_type;
    using F = typename MF::value_type;
    static constexpr S mapping(const F f, S x, const int size) {
        if (f == MF::identity()) {
            return x;
        }
        return {x.c1, x.c0, x.c0 * x.c1 - x.c10};
    }
};
