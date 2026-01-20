#pragma once
#include "../../algebra/monoid_f/monoid_add.hpp"
#include "../../algebra/monoid_s/monoid_min.hpp"
// MSF
template <class T> struct MonoidMinAdd {
    using MS = MonoidMin<T>;
    using MF = MonoidAdd<T>;
    using S = typename MS::S;
    using F = typename MF::F;
    static constexpr S mapping(F f, S x) { return f + x; }
};
