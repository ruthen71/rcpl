#pragma once

#include <utility>

// constexpr ... for constexpr bool prime()
template <int m> struct StaticModint {
    using mint = StaticModint;
    unsigned int _v;

    static constexpr int mod() { return m; }
    static constexpr unsigned int umod() { return m; }

    constexpr StaticModint() : _v(0) {}

    template <class T> constexpr StaticModint(T v) {
        long long x = (long long)(v % (long long)(umod()));
        if (x < 0) x += umod();
        _v = (unsigned int)(x);
    }

    constexpr unsigned int val() const { return _v; }

    constexpr mint &operator++() {
        _v++;
        if (_v == umod()) _v = 0;
        return *this;
    }
    constexpr mint &operator--() {
        if (_v == 0) _v = umod();
        _v--;
        return *this;
    }
    constexpr mint operator++(int) {
        mint result = *this;
        ++*this;
        return result;
    }
    constexpr mint operator--(int) {
        mint result = *this;
        --*this;
        return result;
    }

    constexpr mint &operator+=(const mint &rhs) {
        _v += rhs._v;
        if (_v >= umod()) _v -= umod();
        return *this;
    }
    constexpr mint &operator-=(const mint &rhs) {
        _v -= rhs._v;
        if (_v >= umod()) _v += umod();
        return *this;
    }
    constexpr mint &operator*=(const mint &rhs) {
        unsigned long long z = _v;
        z *= rhs._v;
        _v = (unsigned int)(z % umod());
        return *this;
    }
    constexpr mint &operator/=(const mint &rhs) { return (*this *= rhs.inv()); }

    constexpr mint operator+() const { return *this; }
    constexpr mint operator-() const { return mint() - *this; }

    constexpr mint pow(long long n) const {
        assert(n >= 0);
        mint x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }

    constexpr mint inv() const {
        if (prime) {
            assert(_v);
            return pow(umod() - 2);
        } else {
            auto eg = inv_gcd(_v, m);
            assert(eg.first == 1);
            return eg.second;
        }
    }

    friend constexpr mint operator+(const mint &lhs, const mint &rhs) { return mint(lhs) += rhs; }
    friend constexpr mint operator-(const mint &lhs, const mint &rhs) { return mint(lhs) -= rhs; }
    friend constexpr mint operator*(const mint &lhs, const mint &rhs) { return mint(lhs) *= rhs; }
    friend constexpr mint operator/(const mint &lhs, const mint &rhs) { return mint(lhs) /= rhs; }
    friend constexpr bool operator==(const mint &lhs, const mint &rhs) { return lhs._v == rhs._v; }
    friend constexpr bool operator!=(const mint &lhs, const mint &rhs) { return lhs._v != rhs._v; }
    friend std::ostream &operator<<(std::ostream &os, const mint &v) { return os << v.val(); }

    static constexpr bool prime = []() -> bool {
        if (m == 1) return false;
        if (m == 2 || m == 7 || m == 61) return true;
        if (m % 2 == 0) return false;
        unsigned int d = m - 1;
        while (d % 2 == 0) d /= 2;
        for (unsigned int a : {2, 7, 61}) {
            unsigned int t = d;
            mint y = mint(a).pow(t);
            while (t != m - 1 and y != 1 and y != m - 1) {
                y *= y;
                t <<= 1;
            }
            if (y != m - 1 and t % 2 == 0) {
                return false;
            }
        }
        return true;
    }();
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
using mint107 = StaticModint<1000000007>;
using mint998 = StaticModint<998244353>;