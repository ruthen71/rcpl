#pragma once

template <class Mint> struct rolling_hash {
    std::vector<Mint> pwr;
    const Mint base;

    static inline Mint generate_base() {
        std::mt19937_64 mt(std::chrono::steady_clock::now().time_since_epoch().count());
        std::uniform_int_distribution<int> rand(1, Mint::mod() - 1);
        return Mint(rand(mt));
    }

    void extend() {
        int n = pwr.size();
        int m = n * 2;
        pwr.resize(m);
        for (int i = n; i < m; i++) pwr[i] = pwr[i - 1] * base;
    }

    rolling_hash(int N = 0, Mint base = generate_base()) : base(base) {
        pwr.resize(1, Mint(1));
        while (N >= (int)pwr.size()) extend();
    }

    Mint power(int i) {  // return base ^ i
        assert(i >= 0);
        while (i >= (int)pwr.size()) extend();
        return pwr[i];
    }

    std::vector<Mint> build(const std::string &s) const {
        int N = (int)s.size();
        std::vector<Mint> res(N + 1);
        for (int i = 0; i < N; i++) {
            res[i + 1] = res[i] * base + s[i];
        }
        return res;
    }

    template <class T> std::vector<Mint> build(const std::vector<T> &s) const {
        int N = (int)s.size();
        std::vector<Mint> res(N + 1);
        for (int i = 0; i < N; i++) {
            res[i + 1] = res[i] * base + s[i];
        }
        return res;
    }

    Mint prod(const std::vector<Mint> &hs, int l, int r) {
        assert(0 <= l and l <= r and r < hs.size());
        return hs[r] - hs[l] * power(r - l);
    }

    Mint combine(Mint h1, Mint h2, int h2len) { return h1 * power(h2len) + h2; }
};
