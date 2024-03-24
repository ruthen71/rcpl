#pragma once
// MF
template <class T> struct MonoidAffine {
    using F = std::pair<T, T>;  // a * x + b -> {a, b}
    // f(x) = f.first * x + f.second, g(x) = g.first * x + g.second
    // f(g(x)) = f.first * (g.first * x + g.second) + f.second
    //         = f.first * g.first * x + f.first * g.second + f.second
    static constexpr F composition(F f, F g) { return {f.first * g.first, f.first * g.second + f.second}; }
    static constexpr F id() { return {T(1), T(0)}; }
};