#pragma once

#include "../monoid/monoid_assign.hpp"
#include "../monoid/monoid_min_index.hpp"

template <class T, T inf, bool smaller_index, T none>
struct ActedMonoidMinIndexAssign {
    using MS = MonoidMinIndex<T, inf, smaller_index>;
    using MF = MonoidAssign<T, none>;
    using S = typename MS::value_type;
    using F = typename MF::value_type;
    static constexpr S mapping(const F f, const S x, const int size) {
        if (f == MF::identity()) {
            return {x.v, x.i};
        }
        return {f, x.i};
    }
};
