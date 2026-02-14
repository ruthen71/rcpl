#pragma once

template <class T, T inf> struct TopTwo {
    T a, b;
    TopTwo() {
        a = -inf;
        b = -inf;
    }
    TopTwo(T a, T b) : a(a), b(b) {
        if (a < b) {
            std::swap(this->a, this->b);
        }
    }
    bool add(T x) {
        if (a < x) {
            b = a;
            a = x;
            return true;
        } else if (b < x) {
            b = x;
            return true;
        }
        return false;
    }
};
