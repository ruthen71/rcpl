#pragma once

#include <cassert>

#if __cplusplus >= 202002L
#include <bit>
#endif

// bit_ceil
// (0, 1, 2, 3, 4) -> (1, 1, 2, 4, 4)
#if __cplusplus >= 202002L
using std::bit_ceil;
#else
unsigned int bit_ceil(unsigned int x) {
    unsigned int p = 1;
    while (p < x) p *= 2;
    return p;
}
unsigned long long int bit_ceil(unsigned long long int x) {
    unsigned long long int p = 1;
    while (p < x) p *= 2;
    return p;
}
#endif
int bit_ceil(int x) {
    assert(x >= 0);
    return bit_ceil((unsigned int)(x));
}
long long int bit_ceil(long long int x) {
    assert(x >= 0);
    return bit_ceil((unsigned long long int)(x));
}
