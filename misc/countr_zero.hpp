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
    return x == 0 ? 32 : __builtin_ctz(x);
}
int countr_zero(unsigned long long int x) {
    return x == 0 ? 64 : __builtin_ctzll(x);
}
#endif
int countr_zero(int x) { return countr_zero((unsigned int)(x)); }
int countr_zero(long long int x) {
    return countr_zero((unsigned long long int)(x));
}
