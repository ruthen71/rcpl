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
    return x == 0 ? 32 : __builtin_clz(x);
}
int countl_zero(unsigned long long int x) {
    return x == 0 ? 64 : __builtin_clzll(x);
}
#endif
int countl_zero(int x) { return countl_zero((unsigned int)(x)); }
int countl_zero(long long int x) {
    return countl_zero((unsigned long long int)(x));
}
