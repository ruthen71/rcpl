#pragma once

template <class T, bool left = true> struct lazy_min_index_set {
    using S = std::pair<T, int>;
    using F = T;
    using value_type_S = S;
    using value_type_F = F;
    static constexpr S op(S a, S b) {
        if (a.first < b.first) return a;
        if (a.first > b.first) return b;
        if (a.second > b.second) std::swap(a, b);
        return (left ? a : b);
    }
    static constexpr S e() { return {std::numeric_limits<T>::max(), -1}; }
    static constexpr S mapping(F f, S x) { return f == id() ? x : ({f, x.second}); }
    static constexpr F composition(F f, F g) { return f == id() ? g : f; }
    static constexpr F id() { return std::numeric_limits<F>::max(); }
};
