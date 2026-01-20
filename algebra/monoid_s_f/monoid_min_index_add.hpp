#pragma once
#include "../../algebra/monoid_f/monoid_add.hpp"
#include "../../algebra/monoid_s/monoid_min_index.hpp"
// MSF
template <class T, bool left = true> struct LazyMinIndexAdd {
    using MS = MonoidMinIndex<T, left>;
    using MF = MonoidAdd<T>;
    using S = typename MS::S;
    using F = typename MF::F;
    static constexpr S mapping(F f, S x) { return {f + x.first, x.second}; }
};
