#pragma once
#include "algebra/monoid_s/monoid_max_index.hpp"
#include "algebra/monoid_f/monoid_set.hpp"
// MSF
template <class T, bool left = true> struct MonoidMaxIndexSet {
    using MS = MonoidMaxIndex<T, left>;
    using MF = MonoidSet<T>;
    using S = typename MS::S;
    using F = typename MF::F;
    static constexpr S mapping(F f, S x) { return f == MF::id() ? x : ({f, x.second}); }
};