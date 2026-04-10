#pragma once

#include "../monoid/monoid_assign.hpp"
#include "../monoid/monoid_max_index.hpp"

template <class T, T inf, bool left, T none> struct ActedMonoidMaxIndexAssign {
    using MS = MonoidMaxIndex<T, inf, left>;
    using MF = MonoidAssign<T, none>;
    using S = typename MS::value_type;
    using F = typename MF::value_type;
    static constexpr S mapping(const F f, const S x, const int size) {
        if (f != MF::identity()) x.v = f;
        return x;
    }
};
