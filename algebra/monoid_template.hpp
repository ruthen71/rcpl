#pragma once

template <class T> struct MonoidS {
    using S = ;  // todo
    static constexpr S op(S a, S b) {
        // todo
    }
    static constexpr S e() {
        // todo
    }
};

template <class T> struct MonoidF {
    using F = ;  // todo
    static constexpr F composition(F f, F g) {
        // todo
    }
    static constexpr F id() {
        // todo
    }
};

template <class T> struct MonoidSF {
    using MS = MonoidS<T>;
    using MF = MonoidF<T>;
    using S = typename MS::S;
    using F = typename MF::F;
    static constexpr S mapping(F f, S x) {
        // todo
    }
};