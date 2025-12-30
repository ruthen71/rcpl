#pragma once

#include "./countr_zero.hpp"

// lowbit
// (000, 001, 010, 011, 100) -> (-1, 0, 1, 0, 2)
int lowbit(int x) { return (x == 0 ? -1 : countr_zero(x)); }
int lowbit(unsigned int x) { return (x == 0 ? -1 : countr_zero(x)); }
int lowbit(long long int x) { return (x == 0 ? -1 : countr_zero(x)); }
int lowbit(unsigned long long int x) { return (x == 0 ? -1 : countr_zero(x)); }
