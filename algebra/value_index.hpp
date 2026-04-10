#pragma once

template <class T> struct ValueIndex {
    T v;
    int i;
    friend std::ostream& operator<<(std::ostream& os, const ValueIndex& x) {
        return os << x.v;
    }
};
