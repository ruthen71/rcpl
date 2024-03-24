#pragma once
// MF
template <class T> struct MonoidSet {
    using F = T;
    static constexpr F composition(F f, F g) { return f == id() ? g : f; }
    static constexpr F id() { return std::numeric_limits<F>::max(); }
};