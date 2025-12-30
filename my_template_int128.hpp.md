---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: misc/countl_zero.hpp
    title: Countl Zero
  - icon: ':heavy_check_mark:'
    path: misc/countr_zero.hpp
    title: Countr Zero
  - icon: ':heavy_check_mark:'
    path: misc/lowbit.hpp
    title: Lowbit
  - icon: ':heavy_check_mark:'
    path: misc/popcount.hpp
    title: Popcount
  - icon: ':question:'
    path: misc/topbit.hpp
    title: Topbit
  - icon: ':warning:'
    path: my_template.hpp
    title: my_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"my_template_int128.hpp\"\n\n#line 2 \"my_template.hpp\"\n\
    #include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <chrono>\n#include <cmath>\n#include <complex>\n#include <deque>\n#include\
    \ <forward_list>\n#include <fstream>\n#include <functional>\n#include <iomanip>\n\
    #include <ios>\n#include <iostream>\n#include <limits>\n#include <list>\n#include\
    \ <map>\n#include <memory>\n#include <numeric>\n#include <optional>\n#include\
    \ <queue>\n#include <random>\n#include <set>\n#include <sstream>\n#include <stack>\n\
    #include <string>\n#include <tuple>\n#include <type_traits>\n#include <unordered_map>\n\
    #include <unordered_set>\n#include <utility>\n#include <vector>\n\n#ifdef RUTHEN_LOCAL\n\
    #include <rcpl/debug.hpp>\n#else\n#define show(x) true\n#endif\n\n// type definition\n\
    using i64 = long long;\nusing u32 = unsigned int;\nusing u64 = unsigned long long;\n\
    using f32 = float;\nusing f64 = double;\nusing f128 = long double;\ntemplate <class\
    \ T> using pque = std::priority_queue<T>;\ntemplate <class T>\nusing pqueg = std::priority_queue<T,\
    \ std::vector<T>, std::greater<T>>;\n// overload\n#define overload4(_1, _2, _3,\
    \ _4, name, ...) name\n#define overload3(_1, _2, _3, name, ...) name\n#define\
    \ overload2(_1, _2, name, ...) name\n// for loop\n#define REP1(a) for (long long\
    \ _ = 0; _ < (a); _++)\n#define REP2(i, a) for (long long i = 0; i < (a); i++)\n\
    #define REP3(i, a, b) for (long long i = (a); i < (b); i++)\n#define REP4(i, a,\
    \ b, c) for (long long i = (a); i < (b); i += (c))\n#define REP(...) overload4(__VA_ARGS__,\
    \ REP4, REP3, REP2, REP1)(__VA_ARGS__)\n#define RREP1(a) for (long long _ = (a)\
    \ - 1; _ >= 0; _--)\n#define RREP2(i, a) for (long long i = (a) - 1; i >= 0; i--)\n\
    #define RREP3(i, a, b) for (long long i = (b) - 1; i >= (a); i--)\n#define RREP(...)\
    \ overload3(__VA_ARGS__, RREP3, RREP2, RREP1)(__VA_ARGS__)\n#define FORE1(x, a)\
    \ for (auto&& x : a)\n#define FORE2(x, y, a) for (auto&& [x, y] : a)\n#define\
    \ FORE3(x, y, z, a) for (auto&& [x, y, z] : a)\n#define FORE(...) overload4(__VA_ARGS__,\
    \ FORE3, FORE2, FORE1)(__VA_ARGS__)\n#define FORSUB(t, s) \\\n    for (long long\
    \ t = (s); t >= 0; t = (t == 0 ? -1 : (t - 1) & (s)))\n// function\n#define ALL(a)\
    \ (a).begin(), (a).end()\n#define RALL(a) (a).rbegin(), (a).rend()\n#define SORT(a)\
    \ std::sort((a).begin(), (a).end())\n#define RSORT(a) std::sort((a).rbegin(),\
    \ (a).rend())\n#define REV(a) std::reverse((a).begin(), (a).end())\n#define UNIQUE(a)\
    \                      \\\n    std::sort((a).begin(), (a).end()); \\\n    (a).erase(std::unique((a).begin(),\
    \ (a).end()), (a).end())\n#define LEN(a) (int)((a).size())\n#define MIN(a) *std::min_element((a).begin(),\
    \ (a).end())\n#define MAX(a) *std::max_element((a).begin(), (a).end())\n#define\
    \ SUM1(a) std::accumulate((a).begin(), (a).end(), 0LL)\n#define SUM2(a, x) std::accumulate((a).begin(),\
    \ (a).end(), (x))\n#define SUM(...) overload2(__VA_ARGS__, SUM2, SUM1)(__VA_ARGS__)\n\
    #define LB(a, x) \\\n    std::distance((a).begin(), std::lower_bound((a).begin(),\
    \ (a).end(), (x)))\n#define UB(a, x) \\\n    std::distance((a).begin(), std::upper_bound((a).begin(),\
    \ (a).end(), (x)))\ntemplate <class T, class U> inline bool chmin(T& a, const\
    \ U& b) {\n    return (a > T(b) ? a = b, 1 : 0);\n}\ntemplate <class T, class\
    \ U> inline bool chmax(T& a, const U& b) {\n    return (a < T(b) ? a = b, 1 :\
    \ 0);\n}\ntemplate <class T, class S> inline T floor(const T x, const S y) {\n\
    \    assert(y);\n    return (y < 0 ? floor(-x, -y)\n                  : (x > 0\
    \ ? x / y : x / y - (x % y == 0 ? 0 : 1)));\n}\ntemplate <class T, class S> inline\
    \ T ceil(const T x, const S y) {\n    assert(y);\n    return (y < 0 ? ceil(-x,\
    \ -y) : (x > 0 ? (x + y - 1) / y : x / y));\n}\ntemplate <class T, class S>\n\
    std::pair<T, T> inline divmod(const T x, const S y) {\n    T q = floor(x, y);\n\
    \    return {q, x - q * y};\n}\n// 10 ^ n\nconstexpr long long TEN(int n) { return\
    \ (n == 0) ? 1 : 10LL * TEN(n - 1); }\n// 1 + 2 + ... + n\n#define TRI1(n) ((n)\
    \ * ((n) + 1LL) / 2)\n// l + (l + 1) + ... + r\n#define TRI2(l, r) (((l) + (r))\
    \ * ((r) - (l) + 1LL) / 2)\n#define TRI(...) overload2(__VA_ARGS__, TRI2, TRI1)(__VA_ARGS__)\n\
    // bit operation\n// bit[i] (= 0 or 1)\n#define IBIT(bit, i) (((bit) >> (i)) &\
    \ 1)\n// (0, 1, 2, 3, 4) -> (0, 1, 3, 7, 15)\n#define MASK(n) ((1LL << (n)) -\
    \ 1)\n#define POW2(n) (1LL << (n))\n#line 2 \"misc/lowbit.hpp\"\n\n#line 2 \"\
    misc/countr_zero.hpp\"\n\n#if __cplusplus >= 202002L\n#include <bit>\n#endif\n\
    \n// countr_zero\n// (000, 001, 010, 011, 100) -> (32, 0, 1, 0, 2)\n#if __cplusplus\
    \ >= 202002L\nusing std::countr_zero;\n#else\nint countr_zero(unsigned int x)\
    \ {\n    return x == 0 ? 32 : __builtin_ctz(x);\n}\nint countr_zero(unsigned long\
    \ long int x) {\n    return x == 0 ? 64 : __builtin_ctzll(x);\n}\n#endif\nint\
    \ countr_zero(int x) { return countr_zero((unsigned int)(x)); }\nint countr_zero(long\
    \ long int x) {\n    return countr_zero((unsigned long long int)(x));\n}\n#line\
    \ 4 \"misc/lowbit.hpp\"\n\n// lowbit\n// (000, 001, 010, 011, 100) -> (-1, 0,\
    \ 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1 : countr_zero(x)); }\nint\
    \ lowbit(unsigned int x) { return (x == 0 ? -1 : countr_zero(x)); }\nint lowbit(long\
    \ long int x) { return (x == 0 ? -1 : countr_zero(x)); }\nint lowbit(unsigned\
    \ long long int x) { return (x == 0 ? -1 : countr_zero(x)); }\n#line 2 \"misc/popcount.hpp\"\
    \n\n#if __cplusplus >= 202002L\n#include <bit>\n#endif\n\n// popcount\n// (000,\
    \ 001, 010, 011, 100) -> (0, 1, 1, 2, 1)\n#if __cplusplus >= 202002L\nusing std::popcount;\n\
    #else\nint popcount(unsigned int x) { return __builtin_popcount(x); }\nint popcount(unsigned\
    \ long long int x) { return __builtin_popcountll(x); }\n#endif\nint popcount(int\
    \ x) { return popcount((unsigned int)(x)); }\nint popcount(long long int x) {\
    \ return popcount((unsigned long long int)(x)); }\n#line 2 \"misc/topbit.hpp\"\
    \n\n#line 2 \"misc/countl_zero.hpp\"\n\n#if __cplusplus >= 202002L\n#include <bit>\n\
    #endif\n\n// countl_zero\n// (000, 001, 010, 011, 100) -> (32, 31, 30, 30, 29)\n\
    #if __cplusplus >= 202002L\nusing std::countl_zero;\n#else\nint countl_zero(unsigned\
    \ int x) {\n    return x == 0 ? 32 : __builtin_clz(x);\n}\nint countl_zero(unsigned\
    \ long long int x) {\n    return x == 0 ? 64 : __builtin_clzll(x);\n}\n#endif\n\
    int countl_zero(int x) { return countl_zero((unsigned int)(x)); }\nint countl_zero(long\
    \ long int x) {\n    return countl_zero((unsigned long long int)(x));\n}\n#line\
    \ 4 \"misc/topbit.hpp\"\n\n// topbit\n// (000, 001, 010, 011, 100) -> (-1, 0,\
    \ 1, 1, 2)\nint topbit(int x) { return 31 - countl_zero(x); }\nint topbit(unsigned\
    \ int x) { return 31 - countl_zero(x); }\nint topbit(long long int x) { return\
    \ 63 - countl_zero(x); }\nint topbit(unsigned long long int x) { return 63 - countl_zero(x);\
    \ }\n#line 126 \"my_template.hpp\"\n// binary search (integer)\ntemplate <class\
    \ T, class F> T bin_search(T ok, T ng, F& f) {\n    // assert(f(ok) and !f(ng));\n\
    \    while ((ok > ng ? ok - ng : ng - ok) > 1) {\n        T md = (ng + ok) >>\
    \ 1;\n        (f(md) ? ok : ng) = md;\n    }\n    return ok;\n}\n// binary search\
    \ (real number)\ntemplate <class T, class F>\nT bin_search_real(T ok, T ng, F&\
    \ f, const int iter = 100) {\n    // assert(f(ok) and !f(ng));\n    for (int _\
    \ = 0; _ < iter; _++) {\n        T md = (ng + ok) / 2;\n        (f(md) ? ok :\
    \ ng) = md;\n    }\n    return ok;\n}\n// floor(sqrt(x))\ntemplate <class T> constexpr\
    \ T sqrt_floor(T x) { return T(sqrtl(x)); }\n// check if [l1, r1) and [l2, r2)\
    \ intersect\ntemplate <class T>\nconstexpr bool intersect(const T l1, const T\
    \ r1, const T l2, const T r2) {\n    return std::max(l1, l2) < std::min(r1, r2);\n\
    }\n// check if [a.first, a.second) and [b.first, b.second) intersect\ntemplate\
    \ <class T>\nconstexpr bool intersect(const std::pair<T, T>& a, const std::pair<T,\
    \ T>& b) {\n    return intersect(a.first, a.second, b.first, b.second);\n}\n//\
    \ rotate matrix counterclockwise by pi / 2\ntemplate <class T> void rot(std::vector<std::vector<T>>&\
    \ a) {\n    if ((int)(a.size()) == 0) return;\n    if ((int)(a[0].size()) == 0)\
    \ return;\n    int n = (int)(a.size()), m = (int)(a[0].size());\n    std::vector\
    \ res(m, std::vector<T>(n));\n    for (int i = 0; i < n; i++) {\n        for (int\
    \ j = 0; j < m; j++) {\n            res[m - 1 - j][i] = a[i][j];\n        }\n\
    \    }\n    a.swap(res);\n}\n// const value\nconstexpr int dx[8] = {1, 0, -1,\
    \ 0, 1, -1, -1, 1};\nconstexpr int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};\n// infinity\n\
    template <class T> constexpr T INF = 0;\ntemplate <> constexpr int INF<int> =\
    \ 1'000'000'000;                 // 1e9\ntemplate <> constexpr i64 INF<i64> =\
    \ i64(INF<int>) * INF<int> * 2;  // 2e18\ntemplate <> constexpr u32 INF<u32> =\
    \ INF<int>;                      // 1e9\ntemplate <> constexpr u64 INF<u64> =\
    \ INF<i64>;                      // 2e18\ntemplate <> constexpr f32 INF<f32> =\
    \ INF<i64>;                      // 2e18\ntemplate <> constexpr f64 INF<f64> =\
    \ INF<i64>;                      // 2e18\ntemplate <> constexpr f128 INF<f128>\
    \ = INF<i64>;                    // 2e18\n// I/O\n// input\ntemplate <class T>\n\
    std::istream& operator>>(std::istream& is, std::vector<T>& v) {\n    for (auto&&\
    \ i : v) is >> i;\n    return is;\n}\ntemplate <class... T> void in(T&... a) {\
    \ (std::cin >> ... >> a); }\nvoid scan() {}\ntemplate <class Head, class... Tail>\
    \ void scan(Head& head, Tail&... tail) {\n    in(head);\n    scan(tail...);\n\
    }\n// input macro\n#define INT(...)     \\\n    int __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n\
    #define I64(...)     \\\n    i64 __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define\
    \ U32(...)     \\\n    u32 __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define U64(...)\
    \     \\\n    u64 __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define F32(...)   \
    \  \\\n    f32 __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define F64(...)     \\\
    \n    f64 __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define F128(...)     \\\n \
    \   f128 __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define STR(...)            \
    \ \\\n    std::string __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define CHR(...)\
    \      \\\n    char __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define VEC(type,\
    \ name, size)     \\\n    std::vector<type> name(size); \\\n    scan(name)\n#define\
    \ VEC2(type, name1, name2, size)          \\\n    std::vector<type> name1(size),\
    \ name2(size); \\\n    for (int i = 0; i < size; i++) scan(name1[i], name2[i])\n\
    #define VEC3(type, name1, name2, name3, size)                \\\n    std::vector<type>\
    \ name1(size), name2(size), name3(size); \\\n    for (int i = 0; i < size; i++)\
    \ scan(name1[i], name2[i], name3[i])\n#define VEC4(type, name1, name2, name3,\
    \ name4, size)                      \\\n    std::vector<type> name1(size), name2(size),\
    \ name3(size), name4(size); \\\n    for (int i = 0; i < size; i++) scan(name1[i],\
    \ name2[i], name3[i], name4[i])\n#define VV(type, name, h, w)                \
    \       \\\n    std::vector name((h), std::vector<type>((w))); \\\n    scan(name)\n\
    // output\ntemplate <class T>\nstd::ostream& operator<<(std::ostream& os, const\
    \ std::vector<T>& v) {\n    auto n = v.size();\n    for (size_t i = 0; i < n;\
    \ i++) {\n        if (i) os << ' ';\n        os << v[i];\n    }\n    return os;\n\
    }\ntemplate <class... T> void out(const T&... a) { (std::cout << ... << a); }\n\
    void print() { out('\\n'); }\ntemplate <class Head, class... Tail> void print(Head&&\
    \ head, Tail&&... tail) {\n    out(head);\n    if (sizeof...(Tail)) out(' ');\n\
    \    print(tail...);\n}\n// for interactive problems\nvoid printi() { std::cout\
    \ << std::endl; }\ntemplate <class Head, class... Tail> void printi(Head&& head,\
    \ Tail&&... tail) {\n    out(head);\n    if (sizeof...(Tail)) out(' ');\n    printi(tail...);\n\
    }\n// bool output\nvoid YES(bool t = 1) { print(t ? \"YES\" : \"NO\"); }\nvoid\
    \ Yes(bool t = 1) { print(t ? \"Yes\" : \"No\"); }\nvoid yes(bool t = 1) { print(t\
    \ ? \"yes\" : \"no\"); }\nvoid NO(bool t = 1) { YES(!t); }\nvoid No(bool t = 1)\
    \ { Yes(!t); }\nvoid no(bool t = 1) { yes(!t); }\nvoid POSSIBLE(bool t = 1) {\
    \ print(t ? \"POSSIBLE\" : \"IMPOSSIBLE\"); }\nvoid Possible(bool t = 1) { print(t\
    \ ? \"Possible\" : \"Impossible\"); }\nvoid possible(bool t = 1) { print(t ? \"\
    possible\" : \"impossible\"); }\nvoid IMPOSSIBLE(bool t = 1) { POSSIBLE(!t); }\n\
    void Impossible(bool t = 1) { Possible(!t); }\nvoid impossible(bool t = 1) { possible(!t);\
    \ }\nvoid FIRST(bool t = 1) { print(t ? \"FIRST\" : \"SECOND\"); }\nvoid First(bool\
    \ t = 1) { print(t ? \"First\" : \"Second\"); }\nvoid first(bool t = 1) { print(t\
    \ ? \"first\" : \"second\"); }\nvoid SECOND(bool t = 1) { FIRST(!t); }\nvoid Second(bool\
    \ t = 1) { First(!t); }\nvoid second(bool t = 1) { first(!t); }\n// I/O speed\
    \ up\nstruct SetUpIO {\n    SetUpIO() {\n        std::ios::sync_with_stdio(false);\n\
    \        std::cin.tie(0);\n        std::cout << std::fixed << std::setprecision(20);\n\
    \    }\n} set_up_io;\n#line 4 \"my_template_int128.hpp\"\n// type definition\n\
    using i128 = __int128_t;\nusing u128 = __uint128_t;\n// infinity\ntemplate <>\
    \ constexpr i128 INF<i128> = i128(INF<i64>) * INF<i64>;  // 4e36\ntemplate <>\
    \ constexpr u128 INF<u128> = INF<i128>;                  // 4e36\n// input\nstd::istream&\
    \ operator>>(std::istream& is, i128& x) {\n    std::string s;\n    is >> s;\n\
    \    x = 0;\n    int i = s[0] == '-' ? 1 : 0;\n    while (i < (int)(s.size()))\
    \ x = 10 * x + s[i++] - '0';\n    if (s[0] == '-') x = -x;\n    return is;\n}\n\
    std::istream& operator>>(std::istream& is, u128& x) {\n    std::string s;\n  \
    \  is >> s;\n    assert(s[0] != '-');\n    x = 0;\n    int i = 0;\n    while (i\
    \ < (int)(s.size())) x = 10 * x + s[i++] - '0';\n    return is;\n}\n// output\n\
    std::ostream& operator<<(std::ostream& os, const i128& x) {\n    if (x == 0) {\n\
    \        return os << 0;\n    }\n    i128 y = (x > 0 ? x : -x);\n    std::string\
    \ res;\n    while (y) {\n        res += y % 10 + '0';\n        y /= 10;\n    }\n\
    \    if (x < 0) res += '-';\n    std::reverse(res.begin(), res.end());\n    return\
    \ os << res;\n}\nstd::ostream& operator<<(std::ostream& os, const u128& x) {\n\
    \    if (x == 0) {\n        return os << 0;\n    }\n    u128 y = x;\n    std::string\
    \ res;\n    while (y) {\n        res += y % 10 + '0';\n        y /= 10;\n    }\n\
    \    std::reverse(res.begin(), res.end());\n    return os << res;\n}\n// definition\
    \ & input\n#define I128(...)     \\\n    i128 __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n\
    #define U128(...)     \\\n    u128 __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n"
  code: "#pragma once\n\n#include \"my_template.hpp\"\n// type definition\nusing i128\
    \ = __int128_t;\nusing u128 = __uint128_t;\n// infinity\ntemplate <> constexpr\
    \ i128 INF<i128> = i128(INF<i64>) * INF<i64>;  // 4e36\ntemplate <> constexpr\
    \ u128 INF<u128> = INF<i128>;                  // 4e36\n// input\nstd::istream&\
    \ operator>>(std::istream& is, i128& x) {\n    std::string s;\n    is >> s;\n\
    \    x = 0;\n    int i = s[0] == '-' ? 1 : 0;\n    while (i < (int)(s.size()))\
    \ x = 10 * x + s[i++] - '0';\n    if (s[0] == '-') x = -x;\n    return is;\n}\n\
    std::istream& operator>>(std::istream& is, u128& x) {\n    std::string s;\n  \
    \  is >> s;\n    assert(s[0] != '-');\n    x = 0;\n    int i = 0;\n    while (i\
    \ < (int)(s.size())) x = 10 * x + s[i++] - '0';\n    return is;\n}\n// output\n\
    std::ostream& operator<<(std::ostream& os, const i128& x) {\n    if (x == 0) {\n\
    \        return os << 0;\n    }\n    i128 y = (x > 0 ? x : -x);\n    std::string\
    \ res;\n    while (y) {\n        res += y % 10 + '0';\n        y /= 10;\n    }\n\
    \    if (x < 0) res += '-';\n    std::reverse(res.begin(), res.end());\n    return\
    \ os << res;\n}\nstd::ostream& operator<<(std::ostream& os, const u128& x) {\n\
    \    if (x == 0) {\n        return os << 0;\n    }\n    u128 y = x;\n    std::string\
    \ res;\n    while (y) {\n        res += y % 10 + '0';\n        y /= 10;\n    }\n\
    \    std::reverse(res.begin(), res.end());\n    return os << res;\n}\n// definition\
    \ & input\n#define I128(...)     \\\n    i128 __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n\
    #define U128(...)     \\\n    u128 __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n"
  dependsOn:
  - my_template.hpp
  - misc/lowbit.hpp
  - misc/countr_zero.hpp
  - misc/popcount.hpp
  - misc/topbit.hpp
  - misc/countl_zero.hpp
  isVerificationFile: false
  path: my_template_int128.hpp
  requiredBy: []
  timestamp: '2025-12-31 07:11:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: my_template_int128.hpp
layout: document
redirect_from:
- /library/my_template_int128.hpp
- /library/my_template_int128.hpp.html
title: my_template_int128.hpp
---
