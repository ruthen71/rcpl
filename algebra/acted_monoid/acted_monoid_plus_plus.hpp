#pragma once

#include "../monoid/monoid_plus.hpp"

template <class T> struct ActedMonoidPlusPlus {
    using MS = MonoidPlus<T>;
    using MF = MonoidPlus<T>;
    using S = typename MS::value_type;
    using F = typename MF::value_type;
    static constexpr S mapping(const F f, const S x, const int size) {
        return x + f * T(size);
    }
};
