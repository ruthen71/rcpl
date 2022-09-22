#pragma once

template <class T, bool left = true> struct monoid_max_index {
    using S = std::pair<T, int>;
    using value_type = S;
    static constexpr S op(S a, S b) {
        if (a.first > b.first) return a;
        if (a.first < b.first) return b;
        if (a.second > b.second) swap(a, b);
        return (left ? a : b);
    }
    static constexpr S e() { return {std::numeric_limits<T>::lowest(), -1}; }
};

/**
 * @docs docs/algebra/monoid_max_index.md
 */