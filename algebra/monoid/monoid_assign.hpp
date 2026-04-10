#pragma once

template <class T, T none> struct MonoidAssign {
    using value_type = T;
    static constexpr T operation(const T& a, const T& b) noexcept {
        if (b == identity()) {
            return a;
        }
        return b;
    }
    static constexpr T identity() noexcept { return none; }
    static constexpr bool commutative = false;
};
