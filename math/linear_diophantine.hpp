#pragma once

#include <tuple>
#include "math/extended_gcd.hpp"

// Reference: https://ja.wikipedia.org/wiki/ベズーの等式
// ax + by = c を解く (a, b >= 0)
// return {x, y, gcd(a, b), has_solution}
// 解が存在するとき
// (1) a = 0, b = 0, c = 0 のとき
//   x, y は任意
//   {0, 0, gcd(a, b) = 0, 1} を返す
// (2) a = 0, c が b の倍数のとき
//   x は任意, y = c / b
//   {0, c / b, gcd(a, b) = b, 1} を返す
// (3) b = 0, c が a の倍数のとき
//   y は任意, x = c / b
//   {c / a, 0, gcd(a, b) = a, 1} を返す
// (4) a > 0, b > 0, c % gcd(a, b) = 0 のとき
//   x = x' + k * (b / gcd(a, b)), y = y' - k * (a / gcd(a, b))
//   {x', y', gcd(a, b), 1} を返す
// 解が存在しないとき
// {-1, -1, -1, 0} を返す
template <class T> std::tuple<T, T, T, int> linear_diophantine(T a, T b, T c) {
    assert(a >= 0 and b >= 0);
    if (a == 0 and b == 0) {
        if (c == 0) return {0, 0, 0, 1};
        return {-1, -1, -1, 0};
    }
    if (a == 0) {
        // by = c
        if (c % b == 0) return {0, c / b, b, 1};
        return {-1, -1, -1, 0};
    }
    if (b == 0) {
        // ax = c
        if (c % a == 0) return {c / a, 0, a, 1};
        return {-1, -1, -1, 0};
    }
    // as + bt = gcd(a, b) から ax + by = c を求める
    // x = s * (c / gcd(a, b)), y = t * (c / gcd(a, b)) よりも x, y が小さくなる?
    // c = c' + a * dx + b * dy となるように c' を求める
    // (a, b は gcd(a, b) の倍数なので c' は gcd(a, b) の倍数)
    // x = dx + s * (c' / gcd(a, b)), y = dy + t * (c' / gcd(a, b)) が解となる
    // ax + by = a * dx + b * dy + (as + bt) * (c' / gcd(a, b)) = a * dx + b * dy + c' = c
    auto [s, t, g] = extended_gcd(a, b);
    if (c % g != 0) return {-1, -1, -1, 0};
    T dx = c / a;
    c -= dx * a;
    T dy = c / b;
    c -= dy * b;
    T x = dx + s * (c / g);
    T y = dy + t * (c / g);
    return {x, y, g, 1};
}

// 線形合同式 ax = b (mod m) を解く (m > 0)
// 解が存在する場合 x = x' (mod h) となるときの最小の x' と h を返す
// 解が存在しない場合 {-1, -1} を返す
template <class T> std::pair<T, T> linear_congruence(T a, T b, T m) {
    assert(m > 0);
    a = (a % m + m) % m;
    b = (b % m + m) % m;
    // ax = b (mod m) <=> ax + my = b となる (x, y) が存在
    auto [x, y, g, is_ok] = linear_diophantine(a, m, b);
    if (!is_ok) return {-1, -1};
    T h = m / g;
    x = (x % h + h) % h;
    return {x, h};
}