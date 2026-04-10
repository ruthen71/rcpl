#pragma once

#include "../monoid/monoid_affine.hpp"
#include "../monoid/monoid_plus.hpp"

template <class T> struct ActedMonoidPlusAffine {
    using MS = MonoidPlus<T>;
    using MF = MonoidAffine<T>;
    using S = typename MS::value_type;
    using F = typename MF::value_type;
    static constexpr S mapping(const F f, const S x, const int size) {
        return f.a * x + f.b * T(size);
    }
};
