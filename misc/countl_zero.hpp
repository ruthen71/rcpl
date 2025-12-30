#pragma once

#if __cplusplus >= 202002L
#include <bit>
#endif

// countl_zero
// (000, 001, 010, 011, 100) -> (32, 31, 30, 30, 29)
#if __cplusplus >= 202002L
using std::countl_zero;
#else
int countl_zero(unsigned int x) {
    if (x == 0) {
        return 32;
    }
    return __builtin_clz(x);
}
int countl_zero(unsigned long long int x) {
    if (x == 0) {
        return 64;
    }
    return __builtin_clzll(x);
}
#endif
int countl_zero(int x) { return countl_zero((unsigned int)(x)); }
int countl_zero(long long int x) { return countl_zero((unsigned long long int)(x)); }

// topbit
// (000, 001, 010, 011, 100) -> (-1, 0, 1, 1, 2)
int topbit(int x) { return 31 - countl_zero(x); }
int topbit(unsigned int x) { return 31 - countl_zero(x); }
int topbit(long long int x) { return 63 - countl_zero(x); }
int topbit(unsigned long long int x) { return 63 - countl_zero(x); }
