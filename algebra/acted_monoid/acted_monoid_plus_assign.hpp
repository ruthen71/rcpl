#pragma once

#include "../monoid/monoid_assign.hpp"
#include "../monoid/monoid_plus.hpp"

template <class T, T none> struct ActedMonoidPlusAssign {
    using MS = MonoidPlus<T>;
    using MF = MonoidAssign<T, none>;
    using S = typename MS::value_type;
    using F = typename MF::value_type;
    static constexpr S mapping(const F f, const S x, const int size) {
        if (f == MF::identity()) {
            return x;
        }
        return f * T(size);
    }
};
