#pragma once

template <class T> struct lazy_sum_add {
    using S = std::pair<T, int>;
    using F = T;
    using value_type_S = S;
    using value_type_F = F;
    static constexpr S op(S a, S b) { return {a.first + b.first, a.second + b.second}; }
    static constexpr S e() { return {0, 0}; }
    static constexpr S mapping(F f, S x) { return {x.first + f * x.second, x.second}; }
    static constexpr F composition(F f, F g) { return f + g; }
    static constexpr F id() { return 0; }
};
