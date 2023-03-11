#pragma once

// https://atcoder.jp/contests/practice2/tasks/practice2_k
template <class T> struct LazySumAffine {
    using S = std::pair<T, int>;
    using F = std::pair<T, T>;  // a * x + b -> {a, b}
    using value_type_S = S;
    using value_type_F = F;
    static constexpr S op(S a, S b) { return {a.first + b.first, a.second + b.second}; }
    static constexpr S e() { return {T(0), 0}; }
    // f(x) = f.first * x + f.second, g(x) = g.first * x + g.second
    // f(g(x)) = f.first * (g.first * x + g.second) + f.second
    //         = f.first * g.first * x + f.first * g.second + f.second
    static constexpr S mapping(F f, S x) { return {f.first * x.first + f.second * x.second, x.second}; }
    static constexpr F composition(F f, F g) { return {f.first * g.first, f.first * g.second + f.second}; }
    static constexpr F id() { return {T(1), T(0)}; }
};