#pragma once

template <class T> struct lazy_sum_set {
    using S = std::pair<T, int>;
    using F = T;
    using value_type_S = S;
    using value_type_F = F;
    static constexpr S op(S a, S b) { return {a.first + b.first, a.second + b.second}; }
    static constexpr S e() { return {0, 0}; }
    static constexpr S mapping(F f, S x) {
        if (f != id()) x.first = f * x.second;
        return x;
    }
    static constexpr F composition(F f, F g) { return f == id() ? g : f; }
    static constexpr F id() { return std::numeric_limits<F>::max(); }
};
