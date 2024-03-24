#pragma once
#include "algebra/monoid_s/monoid_min.hpp"
#include "algebra/monoid_f/monoid_set.hpp"
// MSF
template <class T> struct MonoidMinSet {
    using MS = MonoidMin<T>;
    using MF = MonoidSet<T>;
    using S = typename MS::S;
    using F = typename MF::F;
    static constexpr S mapping(F f, S x) { return f == MF::id() ? x : f; }
};