#pragma once
#include "../../algebra/monoid_f/monoid_affine.hpp"
#include "../../algebra/monoid_s/monoid_sum_size.hpp"
// https://atcoder.jp/contests/practice2/tasks/practice2_k
// MSF
template <class T> struct MonoidSumSizeAffine {
    using MS = MonoidSumSize<T>;
    using MF = MonoidAffine<T>;
    using S = typename MS::S;
    using F = typename MF::F;
    static constexpr S mapping(F f, S x) {
        return {f.first * x.first + f.second * x.second, x.second};
    }
};
