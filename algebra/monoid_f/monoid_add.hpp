#pragma once
// MF
template <class T> struct MonoidAdd {
    using F = T;
    static constexpr F composition(F f, F g) { return f + g; }
    static constexpr F id() { return T(0); }
};