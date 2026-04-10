#pragma once

#include "../algebra/value_index.hpp"

template <class T, T inf, bool left> struct MonoidMinIndex {
    using value_type = ValueIndex<T>;
    static constexpr value_type operation(const value_type& a,
                                          const value_type& b) {
        if (a.v < b.v) return a;
        if (a.v > b.v) return b;
        bool is_small = left ? (a.i < b.i) : (a.i >= b.i);
        return is_small ? a : b;
    }
    static constexpr value_type identity() noexcept {
        return value_type(inf, -1);
    }
    static constexpr bool commutative = true;
};
