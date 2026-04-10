#pragma once

// https://atcoder.jp/contests/abc357/tasks/abc357_f
template <class T> struct ProductSum {
    T ab, a, b;
};

template <class T> struct MonoidProductSum {
    using value_type = ProductSum<T>;
    static constexpr value_type operation(const value_type& a,
                                          const value_type& b) {
        return {a.ab + b.ab, a.a + b.a, a.b + b.b};
    }
    static constexpr value_type identity() { return {T(0), T(0), T(0)}; }
};

template <class T> struct Add2 {
    T a, b;
};

template <class T> struct MonoidAdd2 {
    using value_type = Add2<T>;
    static constexpr value_type operation(const value_type& f,
                                          const value_type& g) {
        return {f.a + g.a, f.b + g.b};
    }
    static constexpr value_type identity() { return {T(0), T(0)}; }
};

template <class T> struct ActedMonoidProductSumAdd2 {
    using MS = MonoidProductSum<T>;
    using MF = MonoidAdd2<T>;
    using S = typename MS::value_type;
    using F = typename MF::value_type;
    static constexpr S mapping(const F f, const S x, const int size) {
        return {x.ab + f.a * x.b + f.b * x.a + f.a * f.b * T(size),
                x.a + f.a * T(size), x.b + f.b * T(size)};
    }
};
