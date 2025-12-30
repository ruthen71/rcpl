#pragma once

#if __cplusplus >= 202002L
#include <bit>
#endif

// countr_zero
// (000, 001, 010, 011, 100) -> (32, 0, 1, 0, 2)
#if __cplusplus >= 202002L
using std::countr_zero;
#else
int countr_zero(unsigned int x) {
    if (x == 0) {
        return 32;
    }
    return __builtin_ctz(x);
}
int countr_zero(unsigned long long int x) {
    if (x == 0) {
        return 64;
    }
    return __builtin_ctzll(x);
}
#endif
int countr_zero(int x) { return countr_zero((unsigned int)(x)); }
int countr_zero(long long int x) { return countr_zero((unsigned long long int)(x)); }

// lowbit
// (000, 001, 010, 011, 100) -> (-1, 0, 1, 0, 2)
int lowbit(int x) { return (x == 0 ? -1 : countr_zero(x)); }
int lowbit(unsigned int x) { return (x == 0 ? -1 : countr_zero(x)); }
int lowbit(long long int x) { return (x == 0 ? -1 : countr_zero(x)); }
int lowbit(unsigned long long int x) { return (x == 0 ? -1 : countr_zero(x)); }
