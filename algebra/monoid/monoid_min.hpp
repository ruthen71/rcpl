#pragma once

template <class T, T inf> struct MonoidMin {
    using value_type = T;
    static constexpr T operation(const T& a, const T& b) noexcept {
        return std::min(a, b);
    }
    static constexpr T identity() noexcept { return inf; }
    static constexpr bool commutative = true;
};
