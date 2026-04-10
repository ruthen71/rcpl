#pragma once

template <class T> struct Affine {
    T a;
    T b;
    friend std::ostream& operator<<(std::ostream& os, const Affine& f) {
        return os << f.a << ", " << f.b;
    }
};

template <class T> struct MonoidAffine {
    using value_type = Affine<T>;
    static constexpr value_type operation(const value_type& f,
                                          const value_type& g) noexcept {
        // f(x) := ax + b, g(x) := cx + d
        // g(f(x)) = c(ax + b) + d = cax + cb + d
        return {g.a * f.a, g.a * f.b + g.b};
    }
    static constexpr value_type identity() noexcept { return {T(1), T(0)}; }
};
