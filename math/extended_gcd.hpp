#pragma once

#include <tuple>
// find (x, y) s.t. ax + by = gcd(a, b)
// a, b >= 0
// return {x, y, gcd(a, b)}
template <class T> std::tuple<T, T, T> extended_gcd(T a, T b) {
    if (b == 0) return {1, 0, a};
    auto [y, x, g] = extended_gcd(b, a % b);
    return {x, y - (a / b) * x, g};
}