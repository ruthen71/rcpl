#pragma once
// MS
template <class T> struct MonoidGcd {
    using S = T;
    static constexpr S op(S a, S b) { return std::gcd(a, b); }
    static constexpr S e() { return T(0); }
};