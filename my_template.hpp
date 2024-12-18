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
using i64 = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
using f32 = float;
using f64 = double;
using f128 = long double;
template <class T> using pque = std::priority_queue<T>;
template <class T> using pqueg = std::priority_queue<T, std::vector<T>, std::greater<T>>;
// overload
#define overload4(_1, _2, _3, _4, name, ...) name
#define overload3(_1, _2, _3, name, ...) name
#define overload2(_1, _2, name, ...) name
// for loop
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
#define FORE(...) overload4(__VA_ARGS__, FORE3, FORE2, FORE1)(__VA_ARGS__)
#define FORSUB(t, s) for (long long t = (s); t >= 0; t = (t == 0 ? -1 : (t - 1) & (s)))
// function
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define SORT(a) std::sort((a).begin(), (a).end())
#define RSORT(a) std::sort((a).rbegin(), (a).rend())
#define REV(a) std::reverse((a).begin(), (a).end())
#define UNIQUE(a)                      \
    std::sort((a).begin(), (a).end()); \
    (a).erase(std::unique((a).begin(), (a).end()), (a).end())
#define LEN(a) (int)((a).size())
#define MIN(a) *std::min_element((a).begin(), (a).end())
#define MAX(a) *std::max_element((a).begin(), (a).end())
#define SUM1(a) std::accumulate((a).begin(), (a).end(), 0LL)
#define SUM2(a, x) std::accumulate((a).begin(), (a).end(), (x))
#define SUM(...) overload2(__VA_ARGS__, SUM2, SUM1)(__VA_ARGS__)
#define LB(a, x) std::distance((a).begin(), std::lower_bound((a).begin(), (a).end(), (x)))
#define UB(a, x) std::distance((a).begin(), std::upper_bound((a).begin(), (a).end(), (x)))
template <class T, class U> inline bool chmin(T& a, const U& b) { return (a > T(b) ? a = b, 1 : 0); }
template <class T, class U> inline bool chmax(T& a, const U& b) { return (a < T(b) ? a = b, 1 : 0); }
template <class T, class S> inline T floor(const T x, const S y) {
    assert(y);
    return (y < 0 ? floor(-x, -y) : (x > 0 ? x / y : x / y - (x % y == 0 ? 0 : 1)));
}
template <class T, class S> inline T ceil(const T x, const S y) {
    assert(y);
    return (y < 0 ? ceil(-x, -y) : (x > 0 ? (x + y - 1) / y : x / y));
}
template <class T, class S> std::pair<T, T> inline divmod(const T x, const S y) {
    T q = floor(x, y);
    return {q, x - q * y};
}
// 10 ^ n
constexpr long long TEN(int n) { return (n == 0) ? 1 : 10LL * TEN(n - 1); }
// 1 + 2 + ... + n
#define TRI1(n) ((n) * ((n) + 1LL) / 2)
// l + (l + 1) + ... + r
#define TRI2(l, r) (((l) + (r)) * ((r) - (l) + 1LL) / 2)
#define TRI(...) overload2(__VA_ARGS__, TRI2, TRI1)(__VA_ARGS__)
// bit operation
// bit[i] (= 0 or 1)
#define IBIT(bit, i) (((bit) >> (i)) & 1)
// (0, 1, 2, 3, 4) -> (0, 1, 3, 7, 15)
#define MASK(n) ((1LL << (n)) - 1)
#define POW2(n) (1LL << (n))
// (0, 1, 2, 3, 4) -> (0, 1, 1, 2, 1)
int popcnt(int x) { return __builtin_popcount(x); }
int popcnt(u32 x) { return __builtin_popcount(x); }
int popcnt(i64 x) { return __builtin_popcountll(x); }
int popcnt(u64 x) { return __builtin_popcountll(x); }
// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)
int topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
int topbit(u32 x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
int topbit(i64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
int topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
// (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)
int lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x)); }
int lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x)); }
int lowbit(i64 x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }
int lowbit(u64 x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }
// binary search (integer)
template <class T, class F> T bin_search(T ok, T ng, F& f) {
    assert(f(ok) and !f(ng));
    while ((ok > ng ? ok - ng : ng - ok) > 1) {
        T md = (ng + ok) >> 1;
        (f(md) ? ok : ng) = md;
    }
    return ok;
}
// binary search (real number)
template <class T, class F> T bin_search_real(T ok, T ng, F& f, const int iter = 100) {
    assert(f(ok) and !f(ng));
    for (int _ = 0; _ < iter; _++) {
        T md = (ng + ok) / 2;
        (f(md) ? ok : ng) = md;
    }
    return ok;
}
// floor(sqrt(x))
template <class T> constexpr T sqrt_floor(T x) { return T(sqrtl(x)); }
// check if [l1, r1) and [l2, r2) intersect
template <class T> constexpr bool intersect(const T l1, const T r1, const T l2, const T r2) { return std::max(l1, l2) < std::min(r1, r2); }
// check if [a.first, a.second) and [b.first, b.second) intersect
template <class T> constexpr bool intersect(const std::pair<T, T>& a, const std::pair<T, T>& b) { return intersect(a.first, a.second, b.first, b.second); }
// rotate matrix counterclockwise by pi / 2
template <class T> void rot(std::vector<std::vector<T>>& a) {
    if ((int)(a.size()) == 0) return;
    if ((int)(a[0].size()) == 0) return;
    int n = (int)(a.size()), m = (int)(a[0].size());
    std::vector res(m, std::vector<T>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[m - 1 - j][i] = a[i][j];
        }
    }
    a.swap(res);
}
// const value
constexpr int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
constexpr int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
// infinity
template <class T> constexpr T INF = 0;
template <> constexpr int INF<int> = 1'000'000'000;                 // 1e9
template <> constexpr i64 INF<i64> = i64(INF<int>) * INF<int> * 2;  // 2e18
template <> constexpr u32 INF<u32> = INF<int>;                      // 1e9
template <> constexpr u64 INF<u64> = INF<i64>;                      // 2e18
template <> constexpr f32 INF<f32> = INF<i64>;                      // 2e18
template <> constexpr f64 INF<f64> = INF<i64>;                      // 2e18
template <> constexpr f128 INF<f128> = INF<i64>;                    // 2e18
// I/O
// input
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
// input macro
#define INT(...)     \
    int __VA_ARGS__; \
    scan(__VA_ARGS__)
#define I64(...)     \
    i64 __VA_ARGS__; \
    scan(__VA_ARGS__)
#define U32(...)     \
    u32 __VA_ARGS__; \
    scan(__VA_ARGS__)
#define U64(...)     \
    u64 __VA_ARGS__; \
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
#define VEC2(type, name1, name2, size)          \
    std::vector<type> name1(size), name2(size); \
    for (int i = 0; i < size; i++) scan(name1[i], name2[i])
#define VEC3(type, name1, name2, name3, size)                \
    std::vector<type> name1(size), name2(size), name3(size); \
    for (int i = 0; i < size; i++) scan(name1[i], name2[i], name3[i])
#define VEC4(type, name1, name2, name3, name4, size)                      \
    std::vector<type> name1(size), name2(size), name3(size), name4(size); \
    for (int i = 0; i < size; i++) scan(name1[i], name2[i], name3[i], name4[i])
#define VV(type, name, h, w)                       \
    std::vector name((h), std::vector<type>((w))); \
    scan(name)
// output
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
// for interactive problems
void printi() { std::cout << std::endl; }
template <class Head, class... Tail> void printi(Head&& head, Tail&&... tail) {
    out(head);
    if (sizeof...(Tail)) out(' ');
    printi(tail...);
}
// bool output
void YES(bool t = 1) { print(t ? "YES" : "NO"); }
void Yes(bool t = 1) { print(t ? "Yes" : "No"); }
void yes(bool t = 1) { print(t ? "yes" : "no"); }
void NO(bool t = 1) { YES(!t); }
void No(bool t = 1) { Yes(!t); }
void no(bool t = 1) { yes(!t); }
void POSSIBLE(bool t = 1) { print(t ? "POSSIBLE" : "IMPOSSIBLE"); }
void Possible(bool t = 1) { print(t ? "Possible" : "Impossible"); }
void possible(bool t = 1) { print(t ? "possible" : "impossible"); }
void IMPOSSIBLE(bool t = 1) { POSSIBLE(!t); }
void Impossible(bool t = 1) { Possible(!t); }
void impossible(bool t = 1) { possible(!t); }
void FIRST(bool t = 1) { print(t ? "FIRST" : "SECOND"); }
void First(bool t = 1) { print(t ? "First" : "Second"); }
void first(bool t = 1) { print(t ? "first" : "second"); }
void SECOND(bool t = 1) { FIRST(!t); }
void Second(bool t = 1) { First(!t); }
void second(bool t = 1) { first(!t); }
// I/O speed up
struct SetUpIO {
    SetUpIO() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(0);
        std::cout << std::fixed << std::setprecision(20);
    }
} set_up_io;