#pragma once

template <class F> struct DualAdd {
    using value_type = F;
    static constexpr F composition(F f, F g) { return f + g; }
    static constexpr F id() { return 0; }
};
