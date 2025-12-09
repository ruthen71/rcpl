#pragma once

template <class T> struct MonoidPlus {
    using value_type = T;
    static constexpr T operation(const T& a, const T& b) noexcept {
        return a + b;
    }
    static constexpr T identity() noexcept { return T(0); }
    static constexpr T inverse(const T& a) noexcept { return -a; }
    static constexpr bool commutative = true;
};
