#pragma once

// https://atcoder.jp/contests/abc322/tasks/abc322_f
// MSF
template <class T> struct LazyMax01Flip {
    using S = std::array<T, 7>;  // {max0, left0, right0, max1, left1, right1, length}
    using F = int;
    using value_type_S = S;
    using value_type_F = F;
    static constexpr S op(S a, S b) {
        S res;
        for (int i = 0; i < 6; i += 3) {
            res[i + 0] = std::max({a[i + 0], b[i + 0], a[i + 2] + b[i + 1]});
            res[i + 1] = a[6] == a[i + 1] ? a[i + 1] + b[i + 1] : a[i + 1];
            res[i + 2] = b[6] == b[i + 2] ? a[i + 2] + b[i + 2] : b[i + 2];
        }
        res[6] = a[6] + b[6];
        return res;
    }
    static constexpr S e() { return {0, 0, 0, 0, 0, 0, 0}; }
    static constexpr S e0() { return {1, 1, 1, 0, 0, 0, 1}; }
    static constexpr S e1() { return {0, 0, 0, 1, 1, 1, 1}; }
    static constexpr S mapping(F f, S x) {
        if (f) {
            for (int i = 0; i < 3; i++) std::swap(x[i], x[i + 3]);
        }
        return x;
    }
    static constexpr F composition(F f, F g) { return f ^ g; }
    static constexpr F id() { return 0; }
};