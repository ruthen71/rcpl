#pragma once
// MS
template <class T, bool left = true> struct MonoidMaxIndex {
    using S = std::pair<T, int>;
    static constexpr S op(S a, S b) {
        if (a.first > b.first) return a;
        if (a.first < b.first) return b;
        if (a.second > b.second) std::swap(a, b);
        return (left ? a : b);
    }
    static constexpr S e() { return {std::numeric_limits<T>::lowest(), -1}; }
};