#pragma once

#include "../monoid/monoid_min_index.hpp"
#include "../monoid/monoid_plus.hpp"

template <class T, T inf, bool left> struct ActedMonoidMinIndexPlus {
    using MS = MonoidMinIndex<T, inf, left>;
    using MF = MonoidPlus<T>;
    using S = typename MS::value_type;
    using F = typename MF::value_type;
    static constexpr S mapping(const F f, const S x, const int size) {
        x.v += f;
        return x;
    }
};
