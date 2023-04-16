#pragma once

template <class Mint> struct MonoidRollingHash {
    using S = std::pair<Mint, Mint>;  // {hash(s), base ^ len(s)}
    using value_type = S;

    static Mint base;

    static void constexpr set_base(Mint b = Mint(0)) {
        if (b == Mint(0)) {
            std::mt19937_64 mt(std::chrono::steady_clock::now().time_since_epoch().count());
            std::uniform_int_distribution<uint64_t> rand(1, Mint::mod() - 1);
            base = Mint(rand(mt));
        } else {
            base = b;
        }
    }

    static constexpr S make_element(Mint x) { return make_pair(x, base); }

    static constexpr S op(S a, S b) { return {a.first * b.second + b.first, a.second * b.second}; }
    static constexpr S e() { return {0, 1}; }  // {hash(""), base ^ len("")}
};