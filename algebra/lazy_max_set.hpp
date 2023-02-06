#pragma once

template <class S> struct LazyMaxSet {
    using F = S;
    using value_type_S = S;
    using value_type_F = F;
    static constexpr S op(S a, S b) { return std::max(a, b); }
    static constexpr S e() { return std::numeric_limits<S>::lowest(); }
    static constexpr S mapping(F f, S x) { return f == id() ? x : f; }
    static constexpr F composition(F f, F g) { return f == id() ? g : f; }
    static constexpr F id() { return std::numeric_limits<F>::lowest(); }
};
