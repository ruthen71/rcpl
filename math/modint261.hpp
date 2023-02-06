#pragma once

struct ModInt261 {
    static constexpr uint64_t m = (1ULL << 61) - 1;
    using uint128_t = __uint128_t;
    using mint = ModInt261;
    uint64_t _v;

    static constexpr uint64_t mod() { return m; }

    ModInt261() : _v(0ULL) {}

    template <class T> ModInt261(T v) {
        long long x = (long long)(v % (long long)mod());
        if (x < 0) x += mod();
        _v = x;
    }

    uint64_t val() const { return _v; }

    mint &operator++() {
        _v++;
        if (_v == mod()) _v = 0;
        return *this;
    }
    mint &operator--() {
        if (_v == 0) _v = mod();
        _v--;
        return *this;
    }

    mint &operator+=(const mint &rhs) {
        _v += rhs._v;
        if (_v >= mod()) _v -= mod();
        return *this;
    }
    mint &operator-=(const mint &rhs) {
        _v -= rhs._v;
        if (_v >= mod()) _v += mod();
        return *this;
    }
    mint &operator*=(const mint &rhs) {
        uint128_t z = _v;
        z *= rhs._v;
        z = (z >> 61) + (z & mod());
        if (z >= mod()) z -= mod();
        _v = (uint64_t)z;
        return *this;
    }

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

    friend mint operator+(const mint &lhs, const mint &rhs) { return mint(lhs) += rhs; }
    friend mint operator-(const mint &lhs, const mint &rhs) { return mint(lhs) -= rhs; }
    friend mint operator*(const mint &lhs, const mint &rhs) { return mint(lhs) *= rhs; }
    friend bool operator==(const mint &lhs, const mint &rhs) { return lhs._v == rhs._v; }
    friend bool operator!=(const mint &lhs, const mint &rhs) { return lhs._v != rhs._v; }
};