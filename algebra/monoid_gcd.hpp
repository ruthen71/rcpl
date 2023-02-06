#pragma once

template <class S> struct monoid_gcd {
    using value_type = S;
    static constexpr S op(S a, S b) { return std::gcd(a, b); }
    static constexpr S e() { return 0; }
};
