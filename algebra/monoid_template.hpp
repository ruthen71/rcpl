#pragma once

template <class T> struct MonoidS {
    using value_type = ;  // todo
    static constexpr value_type operation(const value_type& a,
                                          const value_type& b) {
        // todo
    }
    static constexpr value_type identity() {
        // todo
    }
};

template <class T> struct MonoidF {
    using value_type = ;  // todo
    static constexpr value_type operation(const value_type& f,
                                          const value_type& g) {
        // todo
    }
    static constexpr value_type identity() {
        // todo
    }
};

template <class T> struct ActedMonoid {
    using MS = MonoidS<T>;
    using MF = MonoidF<T>;
    using S = typename MS::value_type;
    using F = typename MF::value_type;
    static constexpr S mapping(const F f, const S x, const int size) {
        // todo
    }
};
