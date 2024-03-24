#pragma once
// MS
template <class T> struct MonoidMax {
    using S = T;
    static constexpr S op(S a, S b) { return std::max(a, b); }
    static constexpr S e() { return std::numeric_limits<T>::lowest(); }
};