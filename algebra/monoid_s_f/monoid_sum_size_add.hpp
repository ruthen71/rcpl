#pragma once
#include "algebra/monoid_s/monoid_sum_size.hpp"
#include "algebra/monoid_f/monoid_add.hpp"
// MSF
template <class T> struct MonoidSumSizeAdd {
    using MS = MonoidSumSize<T>;
    using MF = MonoidAdd<T>;
    using S = typename MS::S;
    using F = typename MF::F;
    static constexpr S mapping(F f, S x) { return {x.first + f * x.second, x.second}; }
};