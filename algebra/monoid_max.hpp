#pragma once

template <class S> struct MonoidMax {
    using value_type = S;
    static constexpr S op(S a, S b) { return std::max(a, b); }
    static constexpr S e() { return std::numeric_limits<S>::lowest(); }
};
