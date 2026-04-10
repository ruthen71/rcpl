#pragma once

template <class T> struct MonoidTimes {
    using value_type = T;
    static constexpr T operation(const T& a, const T& b) noexcept {
        return a * b;
    }
    static constexpr T identity() noexcept { return T(1); }
    static constexpr T inverse(const T& a) noexcept { return T(1) / a; }
    static constexpr bool commutative = true;
};
