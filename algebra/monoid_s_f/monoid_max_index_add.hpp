#pragma once
#include "algebra/monoid_s/monoid_max_index.hpp"
#include "algebra/monoid_f/monoid_add.hpp"
// MSF
template <class T, bool left = true> struct MonoidMaxIndexAdd {
    using MS = MonoidMaxIndex<T, left>;
    using MF = MonoidAdd<T>;
    using S = typename MS::S;
    using F = typename MF::F;
    static constexpr S mapping(F f, S x) { return {f + x.first, x.second}; }
};