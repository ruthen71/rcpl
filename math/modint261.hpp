#pragma once

#include <cassert>

struct Modint261 {
    static constexpr unsigned long long m = (1ULL << 61) - 1;
    using mint = Modint261;
    unsigned long long _v;

    static constexpr long long mod() { return m; }
    static constexpr unsigned long long umod() { return m; }

    Modint261() : _v(0ULL) {}

    template <class T> Modint261(T v) {
        long long x = (long long)(v % (long long)(umod()));
        if (x < 0) x += umod();
        _v = (unsigned long long)(x);
    }

    unsigned long long val() const { return _v; }

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
        __uint128_t z = _v;
        z *= rhs._v;
        z = (z >> 61) + (z & umod());
        if (z >= umod()) z -= umod();
        _v = (unsigned long long)z;
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

    mint inv() const { return pow(umod() - 2); }

    friend mint operator+(const mint &lhs, const mint &rhs) { return mint(lhs) += rhs; }
    friend mint operator-(const mint &lhs, const mint &rhs) { return mint(lhs) -= rhs; }
    friend mint operator*(const mint &lhs, const mint &rhs) { return mint(lhs) *= rhs; }
    friend mint operator/(const mint &lhs, const mint &rhs) { return mint(lhs) /= rhs; }
    friend bool operator==(const mint &lhs, const mint &rhs) { return lhs._v == rhs._v; }
    friend bool operator!=(const mint &lhs, const mint &rhs) { return lhs._v != rhs._v; }
    friend std::ostream &operator<<(std::ostream &os, const mint &v) { return os << v.val(); }
};
using mint261 = Modint261;