#pragma once
// MS
template <class T> struct MonoidMin {
    using S = T;
    static constexpr S op(S a, S b) { return std::min(a, b); }
    static constexpr S e() { return std::numeric_limits<T>::max(); }
};