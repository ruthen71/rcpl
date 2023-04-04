#pragma once

// template
using Double = double;
const Double EPS = 1e-8;
// using Double = long double;
// const Double EPS = 1e-10;
// using Double = long long;
// const Double EPS = 0;
// using Double = __int128_t;
// const Double EPS = 0;
const Double PI = std::acos(Double(-1));
inline int sign(const Double &x) { return x <= -EPS ? -1 : (x >= EPS ? 1 : 0); }
inline bool equal(const Double &a, const Double &b) { return sign(a - b) == 0; }
inline Double radian_to_degree(const Double &r) { return r * 180.0 / PI; }
inline Double degree_to_radian(const Double &d) { return d * PI / 180.0; }
constexpr int IN = 2;
constexpr int ON = 1;
constexpr int OUT = 0;