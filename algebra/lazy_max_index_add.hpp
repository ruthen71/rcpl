#pragma once

template <class T, bool left = true> struct lazy_max_index_add {
    using S = std::pair<T, int>;
    using F = T;
    using value_type_S = S;
    using value_type_F = F;
    static constexpr S op(S a, S b) {
        if (a.first > b.first) return a;
        if (a.first < b.first) return b;
        if (a.second > b.second) std::swap(a, b);
        return (left ? a : b);
    }
    static constexpr S e() { return {std::numeric_limits<T>::lowest(), -1}; }
    static constexpr S mapping(F f, S x) { return {f + x.first, x.second}; }
    static constexpr F composition(F f, F g) { return f + g; }
    static constexpr F id() { return 0; }
};
