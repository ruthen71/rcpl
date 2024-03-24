#pragma once

// MF
struct MonoidFlip {
    using F = int;
    static constexpr F composition(F f, F g) { return f ^ g; }
    static constexpr F id() { return 0; }
};