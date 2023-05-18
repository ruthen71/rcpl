#pragma once

#include "icpc/template.hpp"

// https://onlinejudge.u-aizu.ac.jp/problems/3331

using uint = unsigned int;
using ull = unsigned long long;
template <uint MD> struct Modint {
    using M = Modint;
    const static M G;
    uint v;
    Modint(ll val = 0) { set_v(val % MD + MD); }
    M& set_v(uint val) {
        v = (val < MD) ? val : val - MD;
        return *this;
    }
    explicit operator bool() const { return v != 0; }
    M operator-() const { return M() - *this; }
    M operator+(const M& r) const { return M().set_v(v + r.v); }
    M operator-(const M& r) const { return M().set_v(v + MD - r.v); }
    M operator*(const M& r) const { return M().set_v(ull(v) * r.v % MD); }
    M operator/(const M& r) const { return *this * r.inv(); }
    M& operator+=(const M& r) { return *this = *this + r; }
    M& operator-=(const M& r) { return *this = *this - r; }
    M& operator*=(const M& r) { return *this = *this * r; }
    M& operator/=(const M& r) { return *this = *this / r; }
    bool operator==(const M& r) const { return v == r.v; }
    M pow(ll n) const {
        M x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    M inv() const { return pow(MD - 2); }
    friend ostream& operator<<(ostream& os, const M& r) { return os << r.v; }
};
// using mint = Modint<998244353>;
// template<> const mint mint::G = mint(3);