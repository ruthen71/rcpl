#pragma once
// MS
template <class T> struct MonoidSumSize {
    using S = std::pair<T, int>;
    static constexpr S op(S a, S b) { return {a.first + b.first, a.second + b.second}; }
    static constexpr S e() { return {T(0), 0}; }
};