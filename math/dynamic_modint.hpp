#pragma once

#include <utility>
#include <cassert>

template <int id> struct DynamicModint {
    using mint = DynamicModint;
    unsigned int _v;

    static int m;
    static void set_mod(const int _m) {
        assert(_m >= 1);
        m = _m;
    }

    static int mod() { return m; }
    static unsigned int umod() { return m; }

    DynamicModint() : _v(0) {}

    template <class T> DynamicModint(T v) {
        long long x = (long long)(v % (long long)(umod()));
        if (x < 0) x += umod();
        _v = (unsigned int)(x);
    }

    unsigned int val() const { return _v; }

    mint &operator++() {
        _v++;
        if (_v == umod()) _v = 0;
        return *this;
    }
    mint &operator--() {
        if (_v == 0) _v = umod();
        _v--;
        return *this;
    }
    mint operator++(int) {
        mint result = *this;
        ++*this;
        return result;
    }
    mint operator--(int) {
        mint result = *this;
        --*this;
        return result;
    }

    mint &operator+=(const mint &rhs) {
        _v += rhs._v;
        if (_v >= umod()) _v -= umod();
        return *this;
    }
    mint &operator-=(const mint &rhs) {
        _v -= rhs._v;
        if (_v >= umod()) _v += umod();
        return *this;
    }
    mint &operator*=(const mint &rhs) {
        unsigned long long z = _v;
        z *= rhs._v;
        _v = (unsigned int)(z % umod());
        return *this;
    }
    mint &operator/=(const mint &rhs) { return (*this *= rhs.inv()); }

    mint operator+() const { return *this; }
    mint operator-() const { return mint() - *this; }

    mint pow(long long n) const {
        assert(n >= 0);
        mint x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }

    mint inv() const {
        auto eg = inv_gcd(_v, mod());
        assert(eg.first == 1);
        return eg.second;
    }

    friend mint operator+(const mint &lhs, const mint &rhs) { return mint(lhs) += rhs; }
    friend mint operator-(const mint &lhs, const mint &rhs) { return mint(lhs) -= rhs; }
    friend mint operator*(const mint &lhs, const mint &rhs) { return mint(lhs) *= rhs; }
    friend mint operator/(const mint &lhs, const mint &rhs) { return mint(lhs) /= rhs; }
    friend bool operator==(const mint &lhs, const mint &rhs) { return lhs._v == rhs._v; }
    friend bool operator!=(const mint &lhs, const mint &rhs) { return lhs._v != rhs._v; }
    friend std::ostream &operator<<(std::ostream &os, const mint &v) { return os << v.val(); }

    static constexpr std::pair<int, int> inv_gcd(int a, int b) {
        if (a == 0) return {b, 0};
        int s = b, t = a, m0 = 0, m1 = 1;
        while (t) {
            const int u = s / t;
            s -= t * u;
            m0 -= m1 * u;
            std::swap(s, t);
            std::swap(m0, m1);
        }
        if (m0 < 0) m0 += b / s;
        return {s, m0};
    }
};
template <int id> int DynamicModint<id>::m = 998244353;
using mintd = DynamicModint<0>;