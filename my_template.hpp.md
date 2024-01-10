---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"my_template.hpp\"\n\n#include <algorithm>\n#include <array>\n\
    #include <bitset>\n#include <cassert>\n#include <chrono>\n#include <cmath>\n#include\
    \ <complex>\n#include <deque>\n#include <forward_list>\n#include <fstream>\n#include\
    \ <functional>\n#include <iomanip>\n#include <ios>\n#include <iostream>\n#include\
    \ <limits>\n#include <list>\n#include <map>\n#include <memory>\n#include <numeric>\n\
    #include <optional>\n#include <queue>\n#include <random>\n#include <set>\n#include\
    \ <sstream>\n#include <stack>\n#include <string>\n#include <tuple>\n#include <type_traits>\n\
    #include <unordered_map>\n#include <unordered_set>\n#include <utility>\n#include\
    \ <vector>\n\n#ifdef RUTHEN_LOCAL\n#include <debug.hpp>\n#else\n#define show(x)\
    \ true\n#endif\n\n// type definition\nusing i64 = long long;\nusing i128 = __int128_t;\n\
    using u32 = unsigned int;\nusing u64 = unsigned long long;\nusing u128 = __uint128_t;\n\
    using f32 = float;\nusing f64 = double;\nusing f128 = long double;\ntemplate <class\
    \ T> using pque = std::priority_queue<T>;\ntemplate <class T> using pqueg = std::priority_queue<T,\
    \ std::vector<T>, std::greater<T>>;\n\n#define overload4(_1, _2, _3, _4, name,\
    \ ...) name\n#define overload3(_1, _2, _3, name, ...) name\n#define overload2(_1,\
    \ _2, name, ...) name\n\n// loop\n#define REP1(a) for (long long _ = 0; _ < (a);\
    \ _++)\n#define REP2(i, a) for (long long i = 0; i < (a); i++)\n#define REP3(i,\
    \ a, b) for (long long i = (a); i < (b); i++)\n#define REP4(i, a, b, c) for (long\
    \ long i = (a); i < (b); i += (c))\n#define REP(...) overload4(__VA_ARGS__, REP4,\
    \ REP3, REP2, REP1)(__VA_ARGS__)\n#define RREP1(a) for (long long _ = (a)-1; _\
    \ >= 0; _--)\n#define RREP2(i, a) for (long long i = (a)-1; i >= 0; i--)\n#define\
    \ RREP3(i, a, b) for (long long i = (b)-1; i >= (a); i--)\n#define RREP(...) overload3(__VA_ARGS__,\
    \ RREP3, RREP2, RREP1)(__VA_ARGS__)\n#define FORE1(x, a) for (auto&& x : a)\n\
    #define FORE2(x, y, a) for (auto&& [x, y] : a)\n#define FORE3(x, y, z, a) for\
    \ (auto&& [x, y, z] : a)\n#define FORE(...) overload4(__VA_ARGS__, FORE3, FORE2,\
    \ FORE1)(__VA_ARGS__)\n\n// function\n#define ALL(a) (a).begin(), (a).end()\n\
    #define RALL(a) (a).rbegin(), (a).rend()\n#define SORT(a) std::sort((a).begin(),\
    \ (a).end())\n#define RSORT(a) std::sort((a).rbegin(), (a).rend())\n#define REV(a)\
    \ std::reverse((a).begin(), (a).end())\n#define UNIQUE(a)                    \
    \  \\\n    std::sort((a).begin(), (a).end()); \\\n    (a).erase(std::unique((a).begin(),\
    \ (a).end()), (a).end())\n#define LEN(a) int((a).size())\n#define MIN(a) *std::min_element((a).begin(),\
    \ (a).end())\n#define MAX(a) *std::max_element((a).begin(), (a).end())\n#define\
    \ SUM1(a) std::accumulate((a).begin(), (a).end(), 0LL)\n#define SUM2(a, x) std::accumulate((a).begin(),\
    \ (a).end(), (x))\n#define SUM(...) overload2(__VA_ARGS__, SUM2, SUM1)(__VA_ARGS__)\n\
    #define LB(a, x) std::distance((a).begin(), std::lower_bound((a).begin(), (a).end(),\
    \ (x)))\n#define UB(a, x) std::distance((a).begin(), std::upper_bound((a).begin(),\
    \ (a).end(), (x)))\ntemplate <class T, class U> inline bool chmin(T& a, const\
    \ U& b) { return (a > T(b) ? a = b, 1 : 0); }\ntemplate <class T, class U> inline\
    \ bool chmax(T& a, const U& b) { return (a < T(b) ? a = b, 1 : 0); }\ntemplate\
    \ <class T, class S> inline T floor(const T x, const S y) {\n    assert(y);\n\
    \    return (y < 0 ? floor(-x, -y) : (x > 0 ? x / y : x / y - (x % y == 0 ? 0\
    \ : 1)));\n}\ntemplate <class T, class S> inline T ceil(const T x, const S y)\
    \ {\n    assert(y);\n    return (y < 0 ? ceil(-x, -y) : (x > 0 ? (x + y - 1) /\
    \ y : x / y));\n}\ntemplate <class T, class S> std::pair<T, T> inline divmod(const\
    \ T x, const S y) {\n    T q = floor(x, y);\n    return {q, x - q * y};\n}\n\n\
    // bit operation\nint popcount(int x) { return __builtin_popcount(x); }\nint popcount(i64\
    \ x) { return __builtin_popcountll(x); }\nint popcount(u32 x) { return __builtin_popcount(x);\
    \ }\nint popcount(u64 x) { return __builtin_popcountll(x); }\n\n// binary search\n\
    template <class T, class F> T binary_search(T ok, T ng, F& f) {\n    while (abs(ok\
    \ - ng) > 1) {\n        T md = (ng + ok) >> 1;\n        (f(md) ? ok : ng) = md;\n\
    \    }\n    return ok;\n}\ntemplate <class T, class F> T binary_search_real(T\
    \ ok, T ng, F& f, const int iter = 100) {\n    for (int _ = 0; _ < iter; _++)\
    \ {\n        T md = (ng + ok) / 2;\n        (f(md) ? ok : ng) = md;\n    }\n \
    \   return ok;\n}\n\n// const value\nconstexpr int dx[8] = {1, 0, -1, 0, 1, -1,\
    \ -1, 1};\nconstexpr int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};\n\n// infinity\n\
    template <class T> constexpr T INF = 0;\ntemplate <> constexpr int INF<int> =\
    \ 1'000'000'000;                 // 1e9\ntemplate <> constexpr i64 INF<i64> =\
    \ i64(INF<int>) * INF<int> * 2;  // 2e18\ntemplate <> constexpr i128 INF<i128>\
    \ = i128(INF<i64>) * INF<i64>;   // 4e36\ntemplate <> constexpr u32 INF<u32> =\
    \ INF<int>;                      // 1e9\ntemplate <> constexpr u64 INF<u64> =\
    \ INF<i64>;                      // 2e18\ntemplate <> constexpr u128 INF<u128>\
    \ = INF<i128>;                   // 4e36\ntemplate <> constexpr f32 INF<f32> =\
    \ INF<i64>;                      // 2e18\ntemplate <> constexpr f64 INF<f64> =\
    \ INF<i64>;                      // 2e18\ntemplate <> constexpr f128 INF<f128>\
    \ = INF<i64>;                    // 2e18\n\n// input\nstd::istream& operator>>(std::istream&\
    \ is, __int128_t& x) {\n    std::string s;\n    is >> s;\n    x = 0;\n    int\
    \ i = s[0] == '-' ? 1 : 0;\n    while (i < (int)(s.size())) x = 10 * x + s[i++]\
    \ - '0';\n    if (s[0] == '-') x = -x;\n    return is;\n}\nstd::istream& operator>>(std::istream&\
    \ is, __uint128_t& x) {\n    std::string s;\n    is >> s;\n    assert(s[0] !=\
    \ '-');\n    x = 0;\n    int i = 0;\n    while (i < (int)(s.size())) x = 10 *\
    \ x + s[i++] - '0';\n    return is;\n}\ntemplate <class T> std::istream& operator>>(std::istream&\
    \ is, std::vector<T>& v) {\n    for (auto&& i : v) is >> i;\n    return is;\n\
    }\ntemplate <class... T> void in(T&... a) { (std::cin >> ... >> a); }\nvoid scan()\
    \ {}\ntemplate <class Head, class... Tail> void scan(Head& head, Tail&... tail)\
    \ {\n    in(head);\n    scan(tail...);\n}\n\n// definition & input\n#define INT(...)\
    \     \\\n    int __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define I64(...)   \
    \  \\\n    i64 __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define I128(...)     \\\
    \n    i128 __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define U32(...)     \\\n \
    \   u32 __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define U64(...)     \\\n    u64\
    \ __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define U128(...)     \\\n    u128 __VA_ARGS__;\
    \ \\\n    scan(__VA_ARGS__)\n#define F32(...)     \\\n    f32 __VA_ARGS__; \\\n\
    \    scan(__VA_ARGS__)\n#define F64(...)     \\\n    f64 __VA_ARGS__; \\\n   \
    \ scan(__VA_ARGS__)\n#define F128(...)     \\\n    f128 __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n\
    #define STR(...)             \\\n    std::string __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n\
    #define CHR(...)      \\\n    char __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define\
    \ VEC(type, name, size)     \\\n    std::vector<type> name(size); \\\n    scan(name)\n\
    #define VEC2(type, name1, name2, size)          \\\n    std::vector<type> name1(size),\
    \ name2(size); \\\n    for (int i = 0; i < size; i++) scan(name1[i], name2[i])\n\
    #define VEC3(type, name1, name2, name3, size)                \\\n    std::vector<type>\
    \ name1(size), name2(size), name3(size); \\\n    for (int i = 0; i < size; i++)\
    \ scan(name1[i], name2[i], name3[i])\n#define VEC4(type, name1, name2, name3,\
    \ name4, size)                      \\\n    std::vector<type> name1(size), name2(size),\
    \ name3(size), name4(size); \\\n    for (int i = 0; i < size; i++) scan(name1[i],\
    \ name2[i], name3[i], name4[i])\n#define VV(type, name, h, w)                \
    \       \\\n    std::vector name((h), std::vector<type>((w))); \\\n    scan(name)\n\
    \n// output\nstd::ostream& operator<<(std::ostream& os, const __int128_t& x) {\n\
    \    if (x == 0) {\n        return os << 0;\n    }\n    __int128_t y = (x > 0\
    \ ? x : -x);\n    std::string res;\n    while (y) {\n        res += y % 10 + '0';\n\
    \        y /= 10;\n    }\n    if (x < 0) res += '-';\n    std::reverse(res.begin(),\
    \ res.end());\n    return os << res;\n}\nstd::ostream& operator<<(std::ostream&\
    \ os, const __uint128_t& x) {\n    if (x == 0) {\n        return os << 0;\n  \
    \  }\n    __uint128_t y = x;\n    std::string res;\n    while (y) {\n        res\
    \ += y % 10 + '0';\n        y /= 10;\n    }\n    std::reverse(res.begin(), res.end());\n\
    \    return os << res;\n}\ntemplate <class T> std::ostream& operator<<(std::ostream&\
    \ os, const std::vector<T>& v) {\n    auto n = v.size();\n    for (size_t i =\
    \ 0; i < n; i++) {\n        if (i) os << ' ';\n        os << v[i];\n    }\n  \
    \  return os;\n}\ntemplate <class... T> void out(const T&... a) { (std::cout <<\
    \ ... << a); }\nvoid print() {\n    out('\\n');\n    // std::cout.flush();\n}\n\
    template <class Head, class... Tail> void print(Head&& head, Tail&&... tail) {\n\
    \    out(head);\n    if (sizeof...(Tail)) out(' ');\n    print(tail...);\n}\n\n\
    // bool output\nvoid YES(bool t = 1) { print(t ? \"YES\" : \"NO\"); }\nvoid NO(bool\
    \ t = 1) { YES(!t); }\nvoid Yes(bool t = 1) { print(t ? \"Yes\" : \"No\"); }\n\
    void No(bool t = 1) { Yes(!t); }\nvoid yes(bool t = 1) { print(t ? \"yes\" : \"\
    no\"); }\nvoid no(bool t = 1) { yes(!t); }\nvoid POSSIBLE(bool t = 1) { return\
    \ print(t ? \"POSSIBLE\" : \"IMPOSSIBLE\"); }\nvoid Possible(bool t = 1) { return\
    \ print(t ? \"Possible\" : \"Impossible\"); }\nvoid possible(bool t = 1) { return\
    \ print(t ? \"possible\" : \"impossible\"); }\n\n// I/O speed up\nstruct SetUpIO\
    \ {\n    SetUpIO() {\n        std::ios::sync_with_stdio(false);\n        std::cin.tie(0);\n\
    \        std::cout << std::fixed << std::setprecision(15);\n    }\n} set_up_io;\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <array>\n#include <bitset>\n\
    #include <cassert>\n#include <chrono>\n#include <cmath>\n#include <complex>\n\
    #include <deque>\n#include <forward_list>\n#include <fstream>\n#include <functional>\n\
    #include <iomanip>\n#include <ios>\n#include <iostream>\n#include <limits>\n#include\
    \ <list>\n#include <map>\n#include <memory>\n#include <numeric>\n#include <optional>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <sstream>\n#include\
    \ <stack>\n#include <string>\n#include <tuple>\n#include <type_traits>\n#include\
    \ <unordered_map>\n#include <unordered_set>\n#include <utility>\n#include <vector>\n\
    \n#ifdef RUTHEN_LOCAL\n#include <debug.hpp>\n#else\n#define show(x) true\n#endif\n\
    \n// type definition\nusing i64 = long long;\nusing i128 = __int128_t;\nusing\
    \ u32 = unsigned int;\nusing u64 = unsigned long long;\nusing u128 = __uint128_t;\n\
    using f32 = float;\nusing f64 = double;\nusing f128 = long double;\ntemplate <class\
    \ T> using pque = std::priority_queue<T>;\ntemplate <class T> using pqueg = std::priority_queue<T,\
    \ std::vector<T>, std::greater<T>>;\n\n#define overload4(_1, _2, _3, _4, name,\
    \ ...) name\n#define overload3(_1, _2, _3, name, ...) name\n#define overload2(_1,\
    \ _2, name, ...) name\n\n// loop\n#define REP1(a) for (long long _ = 0; _ < (a);\
    \ _++)\n#define REP2(i, a) for (long long i = 0; i < (a); i++)\n#define REP3(i,\
    \ a, b) for (long long i = (a); i < (b); i++)\n#define REP4(i, a, b, c) for (long\
    \ long i = (a); i < (b); i += (c))\n#define REP(...) overload4(__VA_ARGS__, REP4,\
    \ REP3, REP2, REP1)(__VA_ARGS__)\n#define RREP1(a) for (long long _ = (a)-1; _\
    \ >= 0; _--)\n#define RREP2(i, a) for (long long i = (a)-1; i >= 0; i--)\n#define\
    \ RREP3(i, a, b) for (long long i = (b)-1; i >= (a); i--)\n#define RREP(...) overload3(__VA_ARGS__,\
    \ RREP3, RREP2, RREP1)(__VA_ARGS__)\n#define FORE1(x, a) for (auto&& x : a)\n\
    #define FORE2(x, y, a) for (auto&& [x, y] : a)\n#define FORE3(x, y, z, a) for\
    \ (auto&& [x, y, z] : a)\n#define FORE(...) overload4(__VA_ARGS__, FORE3, FORE2,\
    \ FORE1)(__VA_ARGS__)\n\n// function\n#define ALL(a) (a).begin(), (a).end()\n\
    #define RALL(a) (a).rbegin(), (a).rend()\n#define SORT(a) std::sort((a).begin(),\
    \ (a).end())\n#define RSORT(a) std::sort((a).rbegin(), (a).rend())\n#define REV(a)\
    \ std::reverse((a).begin(), (a).end())\n#define UNIQUE(a)                    \
    \  \\\n    std::sort((a).begin(), (a).end()); \\\n    (a).erase(std::unique((a).begin(),\
    \ (a).end()), (a).end())\n#define LEN(a) int((a).size())\n#define MIN(a) *std::min_element((a).begin(),\
    \ (a).end())\n#define MAX(a) *std::max_element((a).begin(), (a).end())\n#define\
    \ SUM1(a) std::accumulate((a).begin(), (a).end(), 0LL)\n#define SUM2(a, x) std::accumulate((a).begin(),\
    \ (a).end(), (x))\n#define SUM(...) overload2(__VA_ARGS__, SUM2, SUM1)(__VA_ARGS__)\n\
    #define LB(a, x) std::distance((a).begin(), std::lower_bound((a).begin(), (a).end(),\
    \ (x)))\n#define UB(a, x) std::distance((a).begin(), std::upper_bound((a).begin(),\
    \ (a).end(), (x)))\ntemplate <class T, class U> inline bool chmin(T& a, const\
    \ U& b) { return (a > T(b) ? a = b, 1 : 0); }\ntemplate <class T, class U> inline\
    \ bool chmax(T& a, const U& b) { return (a < T(b) ? a = b, 1 : 0); }\ntemplate\
    \ <class T, class S> inline T floor(const T x, const S y) {\n    assert(y);\n\
    \    return (y < 0 ? floor(-x, -y) : (x > 0 ? x / y : x / y - (x % y == 0 ? 0\
    \ : 1)));\n}\ntemplate <class T, class S> inline T ceil(const T x, const S y)\
    \ {\n    assert(y);\n    return (y < 0 ? ceil(-x, -y) : (x > 0 ? (x + y - 1) /\
    \ y : x / y));\n}\ntemplate <class T, class S> std::pair<T, T> inline divmod(const\
    \ T x, const S y) {\n    T q = floor(x, y);\n    return {q, x - q * y};\n}\n\n\
    // bit operation\nint popcount(int x) { return __builtin_popcount(x); }\nint popcount(i64\
    \ x) { return __builtin_popcountll(x); }\nint popcount(u32 x) { return __builtin_popcount(x);\
    \ }\nint popcount(u64 x) { return __builtin_popcountll(x); }\n\n// binary search\n\
    template <class T, class F> T binary_search(T ok, T ng, F& f) {\n    while (abs(ok\
    \ - ng) > 1) {\n        T md = (ng + ok) >> 1;\n        (f(md) ? ok : ng) = md;\n\
    \    }\n    return ok;\n}\ntemplate <class T, class F> T binary_search_real(T\
    \ ok, T ng, F& f, const int iter = 100) {\n    for (int _ = 0; _ < iter; _++)\
    \ {\n        T md = (ng + ok) / 2;\n        (f(md) ? ok : ng) = md;\n    }\n \
    \   return ok;\n}\n\n// const value\nconstexpr int dx[8] = {1, 0, -1, 0, 1, -1,\
    \ -1, 1};\nconstexpr int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};\n\n// infinity\n\
    template <class T> constexpr T INF = 0;\ntemplate <> constexpr int INF<int> =\
    \ 1'000'000'000;                 // 1e9\ntemplate <> constexpr i64 INF<i64> =\
    \ i64(INF<int>) * INF<int> * 2;  // 2e18\ntemplate <> constexpr i128 INF<i128>\
    \ = i128(INF<i64>) * INF<i64>;   // 4e36\ntemplate <> constexpr u32 INF<u32> =\
    \ INF<int>;                      // 1e9\ntemplate <> constexpr u64 INF<u64> =\
    \ INF<i64>;                      // 2e18\ntemplate <> constexpr u128 INF<u128>\
    \ = INF<i128>;                   // 4e36\ntemplate <> constexpr f32 INF<f32> =\
    \ INF<i64>;                      // 2e18\ntemplate <> constexpr f64 INF<f64> =\
    \ INF<i64>;                      // 2e18\ntemplate <> constexpr f128 INF<f128>\
    \ = INF<i64>;                    // 2e18\n\n// input\nstd::istream& operator>>(std::istream&\
    \ is, __int128_t& x) {\n    std::string s;\n    is >> s;\n    x = 0;\n    int\
    \ i = s[0] == '-' ? 1 : 0;\n    while (i < (int)(s.size())) x = 10 * x + s[i++]\
    \ - '0';\n    if (s[0] == '-') x = -x;\n    return is;\n}\nstd::istream& operator>>(std::istream&\
    \ is, __uint128_t& x) {\n    std::string s;\n    is >> s;\n    assert(s[0] !=\
    \ '-');\n    x = 0;\n    int i = 0;\n    while (i < (int)(s.size())) x = 10 *\
    \ x + s[i++] - '0';\n    return is;\n}\ntemplate <class T> std::istream& operator>>(std::istream&\
    \ is, std::vector<T>& v) {\n    for (auto&& i : v) is >> i;\n    return is;\n\
    }\ntemplate <class... T> void in(T&... a) { (std::cin >> ... >> a); }\nvoid scan()\
    \ {}\ntemplate <class Head, class... Tail> void scan(Head& head, Tail&... tail)\
    \ {\n    in(head);\n    scan(tail...);\n}\n\n// definition & input\n#define INT(...)\
    \     \\\n    int __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define I64(...)   \
    \  \\\n    i64 __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define I128(...)     \\\
    \n    i128 __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define U32(...)     \\\n \
    \   u32 __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define U64(...)     \\\n    u64\
    \ __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define U128(...)     \\\n    u128 __VA_ARGS__;\
    \ \\\n    scan(__VA_ARGS__)\n#define F32(...)     \\\n    f32 __VA_ARGS__; \\\n\
    \    scan(__VA_ARGS__)\n#define F64(...)     \\\n    f64 __VA_ARGS__; \\\n   \
    \ scan(__VA_ARGS__)\n#define F128(...)     \\\n    f128 __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n\
    #define STR(...)             \\\n    std::string __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n\
    #define CHR(...)      \\\n    char __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define\
    \ VEC(type, name, size)     \\\n    std::vector<type> name(size); \\\n    scan(name)\n\
    #define VEC2(type, name1, name2, size)          \\\n    std::vector<type> name1(size),\
    \ name2(size); \\\n    for (int i = 0; i < size; i++) scan(name1[i], name2[i])\n\
    #define VEC3(type, name1, name2, name3, size)                \\\n    std::vector<type>\
    \ name1(size), name2(size), name3(size); \\\n    for (int i = 0; i < size; i++)\
    \ scan(name1[i], name2[i], name3[i])\n#define VEC4(type, name1, name2, name3,\
    \ name4, size)                      \\\n    std::vector<type> name1(size), name2(size),\
    \ name3(size), name4(size); \\\n    for (int i = 0; i < size; i++) scan(name1[i],\
    \ name2[i], name3[i], name4[i])\n#define VV(type, name, h, w)                \
    \       \\\n    std::vector name((h), std::vector<type>((w))); \\\n    scan(name)\n\
    \n// output\nstd::ostream& operator<<(std::ostream& os, const __int128_t& x) {\n\
    \    if (x == 0) {\n        return os << 0;\n    }\n    __int128_t y = (x > 0\
    \ ? x : -x);\n    std::string res;\n    while (y) {\n        res += y % 10 + '0';\n\
    \        y /= 10;\n    }\n    if (x < 0) res += '-';\n    std::reverse(res.begin(),\
    \ res.end());\n    return os << res;\n}\nstd::ostream& operator<<(std::ostream&\
    \ os, const __uint128_t& x) {\n    if (x == 0) {\n        return os << 0;\n  \
    \  }\n    __uint128_t y = x;\n    std::string res;\n    while (y) {\n        res\
    \ += y % 10 + '0';\n        y /= 10;\n    }\n    std::reverse(res.begin(), res.end());\n\
    \    return os << res;\n}\ntemplate <class T> std::ostream& operator<<(std::ostream&\
    \ os, const std::vector<T>& v) {\n    auto n = v.size();\n    for (size_t i =\
    \ 0; i < n; i++) {\n        if (i) os << ' ';\n        os << v[i];\n    }\n  \
    \  return os;\n}\ntemplate <class... T> void out(const T&... a) { (std::cout <<\
    \ ... << a); }\nvoid print() {\n    out('\\n');\n    // std::cout.flush();\n}\n\
    template <class Head, class... Tail> void print(Head&& head, Tail&&... tail) {\n\
    \    out(head);\n    if (sizeof...(Tail)) out(' ');\n    print(tail...);\n}\n\n\
    // bool output\nvoid YES(bool t = 1) { print(t ? \"YES\" : \"NO\"); }\nvoid NO(bool\
    \ t = 1) { YES(!t); }\nvoid Yes(bool t = 1) { print(t ? \"Yes\" : \"No\"); }\n\
    void No(bool t = 1) { Yes(!t); }\nvoid yes(bool t = 1) { print(t ? \"yes\" : \"\
    no\"); }\nvoid no(bool t = 1) { yes(!t); }\nvoid POSSIBLE(bool t = 1) { return\
    \ print(t ? \"POSSIBLE\" : \"IMPOSSIBLE\"); }\nvoid Possible(bool t = 1) { return\
    \ print(t ? \"Possible\" : \"Impossible\"); }\nvoid possible(bool t = 1) { return\
    \ print(t ? \"possible\" : \"impossible\"); }\n\n// I/O speed up\nstruct SetUpIO\
    \ {\n    SetUpIO() {\n        std::ios::sync_with_stdio(false);\n        std::cin.tie(0);\n\
    \        std::cout << std::fixed << std::setprecision(15);\n    }\n} set_up_io;"
  dependsOn: []
  isVerificationFile: false
  path: my_template.hpp
  requiredBy: []
  timestamp: '2024-01-10 12:46:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: my_template.hpp
layout: document
redirect_from:
- /library/my_template.hpp
- /library/my_template.hpp.html
title: my_template.hpp
---
