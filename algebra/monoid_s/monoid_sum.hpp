#pragma once
// MS
template <class T> struct MonoidSum {
    using S = T;
    static constexpr S op(S a, S b) { return a + b; }
    static constexpr S e() { return T(0); }
};