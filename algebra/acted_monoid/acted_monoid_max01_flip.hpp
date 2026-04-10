#pragma once

#include <algorithm>

#include "../monoid/monoid_xor.hpp"

// https://atcoder.jp/contests/abc322/tasks/abc322_f
template <class T> struct Max01 {
    // m: 最大長, l: 左端からの連続個数, r: 右端からの連続個数
    T m0, l0, r0, m1, l1, r1, size;
};

template <class T> struct MonoidMax01 {
    using value_type = Max01<T>;
    static constexpr value_type operation(const value_type& a,
                                          const value_type& b) {
        return {std::max({a.m0, b.m0, a.r0 + b.l0}),
                (a.size == a.l0 ? a.size + b.l0 : a.l0),
                (b.size == b.r0 ? a.r0 + b.size : b.r0),
                std::max({a.m1, b.m1, a.r1 + b.l1}),
                (a.size == a.l1 ? a.size + b.l1 : a.l1),
                (b.size == b.r1 ? a.r1 + b.size : b.r1),
                a.size + b.size};
    }
    static constexpr value_type identity() { return {0, 0, 0, 0, 0, 0, 0}; }
};

template <class T> struct ActedMonoidMax01Flip {
    using MS = MonoidMax01<T>;
    using MF = MonoidXor<int>;
    using S = typename MS::value_type;
    using F = typename MF::value_type;
    static constexpr S mapping(const F f, S x, const int size) {
        if (f == MF::identity()) {
            return x;
        }
        return {x.m1, x.l1, x.r1, x.m0, x.l0, x.r0, x.size};
    }
};
