#pragma once

template <class T> struct MonoidGcd {
    using value_type = T;
    static constexpr T operation(const T& a, const T& b) noexcept {
        return std::gcd(a, b);
    }
    static constexpr T identity() noexcept { return T(0); }
    static constexpr bool commutative = true;
};
