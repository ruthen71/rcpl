#pragma once

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <deque>
#include <forward_list>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <optional>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#ifdef RUTHEN_LOCAL
#include <debug.hpp>
#else
#define show(x) true
#endif

// type definition
using i32 = int;
using i64 = long long;
using i128 = __int128_t;
using u32 = unsigned int;
using u64 = unsigned long long;
using u128 = __uint128_t;
using f32 = float;
using f64 = double;
using f128 = long double;

#define overload4(_1, _2, _3, _4, name, ...) name
#define overload3(_1, _2, _3, name, ...) name

// loop
#define REP1(a) for (long long _ = 0; _ < (a); _++)
#define REP2(i, a) for (long long i = 0; i < (a); i++)
#define REP3(i, a, b) for (long long i = (a); i < (b); i++)
#define REP4(i, a, b, c) for (long long i = (a); i < (b); i += (c))
#define REP(...) overload4(__VA_ARGS__, REP4, REP3, REP2, REP1)(__VA_ARGS__)
#define RREP1(a) for (long long _ = (a)-1; _ >= 0; _--)
#define RREP2(i, a) for (long long i = (a)-1; i >= 0; i--)
#define RREP3(i, a, b) for (long long i = (b)-1; i >= (a); i--)
#define RREP(...) overload3(__VA_ARGS__, RREP3, RREP2, RREP1)(__VA_ARGS__)
#define FORE1(x, a) for (auto&& x : a)
#define FORE2(x, y, a) for (auto&& [x, y] : a)
#define FORE3(x, y, z, a) for (auto&& [x, y, z] : a)
#define FORE(...) overload3(__VA_ARGS__, FORE3, FORE2, FORE1)(__VA_ARGS__)

// function
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define SORT(a) std::sort((a).begin(), (a).end())
#define REV(a) std::reverse((a).begin(), (a).end())
#define UNIQUE(a)                      \
    std::sort((a).begin(), (a).end()); \
    (a).erase(std::unique((a).begin(), (a).end()), (a).end())
#define LEN(a) int((a).size())
#define MIN(a) *std::min_element((a).begin(), (a).end())
#define MAX(a) *std::max_element((a).begin(), (a).end())
template <class T> T sum(const std::vector<T>& a) {
    T res = T(0);
    for (auto&& ai : a) res += ai;
    return res;
}
#define LB(a, x) std::lower_bound((a).begin(), (a).end(), (x)) - (a).begin()
#define UB(a, x) std::upper_bound((a).begin(), (a).end(), (x)) - (a).begin()
template <class T, class U> inline bool chmin(T& a, const U& b) { return (a > T(b) ? a = b, 1 : 0); }
template <class T, class U> inline bool chmax(T& a, const U& b) { return (a < T(b) ? a = b, 1 : 0); }

// const value
constexpr int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
constexpr int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

// input
std::istream& operator>>(std::istream& is, __int128_t& x) {
    std::string s;
    is >> s;
    x = 0;
    int i = s[0] == '-' ? 1 : 0;
    while (i < (int)(s.size())) x = 10 * x + s[i++] - '0';
    if (s[0] == '-') x = -x;
    return is;
}
std::istream& operator>>(std::istream& is, __uint128_t& x) {
    std::string s;
    is >> s;
    assert(s[0] != '-');
    x = 0;
    int i = 0;
    while (i < (int)(s.size())) x = 10 * x + s[i++] - '0';
    return is;
}
template <class T> std::istream& operator>>(std::istream& is, std::vector<T>& v) {
    for (auto&& i : v) is >> i;
    return is;
}
template <class... T> void in(T&... a) { (std::cin >> ... >> a); }
void scan() {}
template <class Head, class... Tail> void scan(Head& head, Tail&... tail) {
    in(head);
    scan(tail...);
}

// definition & input
#define I32(...)     \
    i32 __VA_ARGS__; \
    scan(__VA_ARGS__)
#define I64(...)     \
    i64 __VA_ARGS__; \
    scan(__VA_ARGS__)
#define I128(...)     \
    i128 __VA_ARGS__; \
    scan(__VA_ARGS__)
#define U32(...)     \
    u32 __VA_ARGS__; \
    scan(__VA_ARGS__)
#define U64(...)     \
    u64 __VA_ARGS__; \
    scan(__VA_ARGS__)
#define U128(...)     \
    u128 __VA_ARGS__; \
    scan(__VA_ARGS__)
#define F32(...)     \
    f32 __VA_ARGS__; \
    scan(__VA_ARGS__)
#define F64(...)     \
    f64 __VA_ARGS__; \
    scan(__VA_ARGS__)
#define F128(...)     \
    f128 __VA_ARGS__; \
    scan(__VA_ARGS__)
#define STR(...)             \
    std::string __VA_ARGS__; \
    scan(__VA_ARGS__)
#define CHR(...)      \
    char __VA_ARGS__; \
    scan(__VA_ARGS__)
#define VEC(type, name, size)     \
    std::vector<type> name(size); \
    scan(name)
#define VEC2(type, name, h, w)                     \
    std::vector name((h), std::vector<type>((w))); \
    scan(name)

// output
std::ostream& operator<<(std::ostream& os, const __int128_t& x) {
    if (x == 0) {
        return os << 0;
    }
    __int128_t y = (x > 0 ? x : -x);
    std::string res;
    while (y) {
        res += y % 10 + '0';
        y /= 10;
    }
    if (x < 0) res += '-';
    std::reverse(res.begin(), res.end());
    return os << res;
}
std::ostream& operator<<(std::ostream& os, const __uint128_t& x) {
    if (x == 0) {
        return os << 0;
    }
    __uint128_t y = x;
    std::string res;
    while (y) {
        res += y % 10 + '0';
        y /= 10;
    }
    std::reverse(res.begin(), res.end());
    return os << res;
}
template <class T> std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
    auto n = v.size();
    for (size_t i = 0; i < n; i++) {
        if (i) os << ' ';
        os << v[i];
    }
    return os;
}
template <class... T> void out(const T&... a) { (std::cout << ... << a); }
void print() { out('\n'); }
template <class Head, class... Tail> void print(Head&& head, Tail&&... tail) {
    out(head);
    if (sizeof...(Tail)) out(' ');
    print(tail...);
}

// I/O speed up
struct SetUpIO {
    SetUpIO() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(0);
        std::cout << std::fixed << std::setprecision(15);
    }
} set_up_io;