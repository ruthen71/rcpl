#pragma once

#include "./countl_zero.hpp"

// topbit
// (000, 001, 010, 011, 100) -> (-1, 0, 1, 1, 2)
int topbit(int x) { return 31 - countl_zero(x); }
int topbit(unsigned int x) { return 31 - countl_zero(x); }
int topbit(long long int x) { return 63 - countl_zero(x); }
int topbit(unsigned long long int x) { return 63 - countl_zero(x); }
