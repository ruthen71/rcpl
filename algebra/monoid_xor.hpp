#pragma once

template <class S> struct monoid_xor {
    using value_type = S;
    static constexpr S op(S a, S b) { return a ^ b; }
    static constexpr S e() { return 0; }
};
