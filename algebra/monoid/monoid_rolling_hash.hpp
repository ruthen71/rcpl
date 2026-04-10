#pragma once

#include <chrono>
#include <cstdint>
#include <random>
#include <utility>

template <class Mint> struct Hash {
    // {hash(s), base ^ len(s)}
    Mint hash;
    Mint power;
    friend std::ostream& operator<<(std::ostream& os, const Hash& v) {
        return os << v.hash << ", " << v.power;
    }
};

template <class Mint> struct MonoidRollingHash {
    using value_type = Hash<Mint>;

    static Mint base;

    static void set_base(Mint b = Mint(0)) {
        if (b == Mint(0)) {
            std::mt19937_64 mt(
                std::chrono::steady_clock::now().time_since_epoch().count());
            std::uniform_int_distribution<uint64_t> rand(1, Mint::mod() - 1);
            base = Mint(rand(mt));
        } else {
            base = b;
        }
    }

    static constexpr value_type make_element(Mint x) { return {x, base}; }

    static constexpr value_type operation(const value_type& a,
                                          const value_type& b) {
        return {a.hash * b.power + b.hash, a.power * b.power};
    }
    static constexpr value_type identity() {
        // {hash(""), base ^ len("")}
        return {Mint(0), Mint(1)};
    }

    static constexpr bool commutative = false;
};
