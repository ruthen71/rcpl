#pragma once

#if __cplusplus >= 202002L
#include <bit>
#endif

// popcount
// (000, 001, 010, 011, 100) -> (0, 1, 1, 2, 1)
#if __cplusplus >= 202002L
using std::popcount;
#else
int popcount(unsigned int x) { return __builtin_popcount(x); }
int popcount(unsigned long long int x) { return __builtin_popcountll(x); }
#endif
int popcount(int x) { return popcount((unsigned int)(x)); }
int popcount(long long int x) { return popcount((unsigned long long int)(x)); }
