#pragma once

template <class F> struct dual_set {
    using value_type = F;
    static constexpr F composition(F f, F g) { return f == id() ? g : f; }
    static constexpr F id() { return std::numeric_limits<F>::max(); }
};
