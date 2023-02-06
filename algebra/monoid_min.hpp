#pragma once

template <class S> struct MonoidMin {
    using value_type = S;
    static constexpr S op(S a, S b) { return std::min(a, b); }
    static constexpr S e() { return std::numeric_limits<S>::max(); }
};
