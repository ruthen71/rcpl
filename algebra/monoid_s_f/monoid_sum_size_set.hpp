#pragma once
#include "../algebra/monoid_f/monoid_set.hpp"
#include "../algebra/monoid_s/monoid_sum_size.hpp"
// MSF
template <class T> struct MonoidSumSizeSet {
    using MS = MonoidSumSize<T>;
    using MF = MonoidSet<T>;
    using S = typename MS::S;
    using F = typename MF::F;
    static constexpr S mapping(F f, S x) {
        return (f == MF::id() ? x : std::make_pair(f * x.second, x.second));
    }
};
