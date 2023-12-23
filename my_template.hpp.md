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
    \ true\n#endif\n\n// type definition\nusing i32 = int;\nusing i64 = long long;\n\
    using i128 = __int128_t;\nusing u32 = unsigned int;\nusing u64 = unsigned long\
    \ long;\nusing u128 = __uint128_t;\nusing f32 = float;\nusing f64 = double;\n\
    using f128 = long double;\n\n#define overload4(_1, _2, _3, _4, name, ...) name\n\
    #define overload3(_1, _2, _3, name, ...) name\n\n// loop\n#define REP1(a) for\
    \ (long long _ = 0; _ < (a); _++)\n#define REP2(i, a) for (long long i = 0; i\
    \ < (a); i++)\n#define REP3(i, a, b) for (long long i = (a); i < (b); i++)\n#define\
    \ REP4(i, a, b, c) for (long long i = (a); i < (b); i += (c))\n#define REP(...)\
    \ overload4(__VA_ARGS__, REP4, REP3, REP2, REP1)(__VA_ARGS__)\n#define RREP1(a)\
    \ for (long long _ = (a)-1; _ >= 0; _--)\n#define RREP2(i, a) for (long long i\
    \ = (a)-1; i >= 0; i--)\n#define RREP3(i, a, b) for (long long i = (b)-1; i >=\
    \ (a); i--)\n#define RREP(...) overload3(__VA_ARGS__, RREP3, RREP2, RREP1)(__VA_ARGS__)\n\
    #define FORE1(x, a) for (auto&& x : a)\n#define FORE2(x, y, a) for (auto&& [x,\
    \ y] : a)\n#define FORE3(x, y, z, a) for (auto&& [x, y, z] : a)\n#define FORE(...)\
    \ overload3(__VA_ARGS__, FORE3, FORE2, FORE1)(__VA_ARGS__)\n\n// function\n#define\
    \ ALL(a) (a).begin(), (a).end()\n#define RALL(a) (a).rbegin(), (a).rend()\n#define\
    \ SORT(a) std::sort((a).begin(), (a).end())\n#define REV(a) std::reverse((a).begin(),\
    \ (a).end())\n#define UNIQUE(a)                      \\\n    std::sort((a).begin(),\
    \ (a).end()); \\\n    (a).erase(std::unique((a).begin(), (a).end()), (a).end())\n\
    #define LEN(a) int((a).size())\n#define MIN(a) *std::min_element((a).begin(),\
    \ (a).end())\n#define MAX(a) *std::max_element((a).begin(), (a).end())\ntemplate\
    \ <class T> T sum(const std::vector<T>& a) {\n    T res = T(0);\n    for (auto&&\
    \ ai : a) res += ai;\n    return res;\n}\n#define LB(a, x) std::lower_bound((a).begin(),\
    \ (a).end(), (x)) - (a).begin()\n#define UB(a, x) std::upper_bound((a).begin(),\
    \ (a).end(), (x)) - (a).begin()\ntemplate <class T, class U> inline bool chmin(T&\
    \ a, const U& b) { return (a > T(b) ? a = b, 1 : 0); }\ntemplate <class T, class\
    \ U> inline bool chmax(T& a, const U& b) { return (a < T(b) ? a = b, 1 : 0); }\n\
    \n// const value\nconstexpr int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};\nconstexpr\
    \ int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};\n\n// input\nstd::istream& operator>>(std::istream&\
    \ is, __int128_t& x) {\n    std::string s;\n    is >> s;\n    x = 0;\n    int\
    \ i = s[0] == '-' ? 1 : 0;\n    while (i < (int)(s.size())) x = 10 * x + s[i++]\
    \ - '0';\n    if (s[0] == '-') x = -x;\n    return is;\n}\nstd::istream& operator>>(std::istream&\
    \ is, __uint128_t& x) {\n    std::string s;\n    is >> s;\n    assert(s[0] !=\
    \ '-');\n    x = 0;\n    int i = 0;\n    while (i < (int)(s.size())) x = 10 *\
    \ x + s[i++] - '0';\n    return is;\n}\ntemplate <class T> std::istream& operator>>(std::istream&\
    \ is, std::vector<T>& v) {\n    for (auto&& i : v) is >> i;\n    return is;\n\
    }\ntemplate <class... T> void in(T&... a) { (std::cin >> ... >> a); }\nvoid scan()\
    \ {}\ntemplate <class Head, class... Tail> void scan(Head& head, Tail&... tail)\
    \ {\n    in(head);\n    scan(tail...);\n}\n\n// definition & input\n#define I32(...)\
    \     \\\n    i32 __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define I64(...)   \
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
    #define VEC2(type, name, h, w)                     \\\n    std::vector name((h),\
    \ std::vector<type>((w))); \\\n    scan(name)\n\n// output\nstd::ostream& operator<<(std::ostream&\
    \ os, const __int128_t& x) {\n    if (x == 0) {\n        return os << 0;\n   \
    \ }\n    __int128_t y = (x > 0 ? x : -x);\n    std::string res;\n    while (y)\
    \ {\n        res += y % 10 + '0';\n        y /= 10;\n    }\n    if (x < 0) res\
    \ += '-';\n    std::reverse(res.begin(), res.end());\n    return os << res;\n\
    }\nstd::ostream& operator<<(std::ostream& os, const __uint128_t& x) {\n    if\
    \ (x == 0) {\n        return os << 0;\n    }\n    __uint128_t y = x;\n    std::string\
    \ res;\n    while (y) {\n        res += y % 10 + '0';\n        y /= 10;\n    }\n\
    \    std::reverse(res.begin(), res.end());\n    return os << res;\n}\ntemplate\
    \ <class T> std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)\
    \ {\n    auto n = v.size();\n    for (size_t i = 0; i < n; i++) {\n        if\
    \ (i) os << ' ';\n        os << v[i];\n    }\n    return os;\n}\ntemplate <class...\
    \ T> void out(const T&... a) { (std::cout << ... << a); }\nvoid print() { out('\\\
    n'); }\ntemplate <class Head, class... Tail> void print(Head&& head, Tail&&...\
    \ tail) {\n    out(head);\n    if (sizeof...(Tail)) out(' ');\n    print(tail...);\n\
    }\n\n// I/O speed up\nstruct SetUpIO {\n    SetUpIO() {\n        std::ios::sync_with_stdio(false);\n\
    \        std::cin.tie(0);\n        std::cout << std::fixed << std::setprecision(15);\n\
    \    }\n} set_up_io;\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <array>\n#include <bitset>\n\
    #include <cassert>\n#include <chrono>\n#include <cmath>\n#include <complex>\n\
    #include <deque>\n#include <forward_list>\n#include <fstream>\n#include <functional>\n\
    #include <iomanip>\n#include <ios>\n#include <iostream>\n#include <limits>\n#include\
    \ <list>\n#include <map>\n#include <memory>\n#include <numeric>\n#include <optional>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <sstream>\n#include\
    \ <stack>\n#include <string>\n#include <tuple>\n#include <type_traits>\n#include\
    \ <unordered_map>\n#include <unordered_set>\n#include <utility>\n#include <vector>\n\
    \n#ifdef RUTHEN_LOCAL\n#include <debug.hpp>\n#else\n#define show(x) true\n#endif\n\
    \n// type definition\nusing i32 = int;\nusing i64 = long long;\nusing i128 = __int128_t;\n\
    using u32 = unsigned int;\nusing u64 = unsigned long long;\nusing u128 = __uint128_t;\n\
    using f32 = float;\nusing f64 = double;\nusing f128 = long double;\n\n#define\
    \ overload4(_1, _2, _3, _4, name, ...) name\n#define overload3(_1, _2, _3, name,\
    \ ...) name\n\n// loop\n#define REP1(a) for (long long _ = 0; _ < (a); _++)\n\
    #define REP2(i, a) for (long long i = 0; i < (a); i++)\n#define REP3(i, a, b)\
    \ for (long long i = (a); i < (b); i++)\n#define REP4(i, a, b, c) for (long long\
    \ i = (a); i < (b); i += (c))\n#define REP(...) overload4(__VA_ARGS__, REP4, REP3,\
    \ REP2, REP1)(__VA_ARGS__)\n#define RREP1(a) for (long long _ = (a)-1; _ >= 0;\
    \ _--)\n#define RREP2(i, a) for (long long i = (a)-1; i >= 0; i--)\n#define RREP3(i,\
    \ a, b) for (long long i = (b)-1; i >= (a); i--)\n#define RREP(...) overload3(__VA_ARGS__,\
    \ RREP3, RREP2, RREP1)(__VA_ARGS__)\n#define FORE1(x, a) for (auto&& x : a)\n\
    #define FORE2(x, y, a) for (auto&& [x, y] : a)\n#define FORE3(x, y, z, a) for\
    \ (auto&& [x, y, z] : a)\n#define FORE(...) overload3(__VA_ARGS__, FORE3, FORE2,\
    \ FORE1)(__VA_ARGS__)\n\n// function\n#define ALL(a) (a).begin(), (a).end()\n\
    #define RALL(a) (a).rbegin(), (a).rend()\n#define SORT(a) std::sort((a).begin(),\
    \ (a).end())\n#define REV(a) std::reverse((a).begin(), (a).end())\n#define UNIQUE(a)\
    \                      \\\n    std::sort((a).begin(), (a).end()); \\\n    (a).erase(std::unique((a).begin(),\
    \ (a).end()), (a).end())\n#define LEN(a) int((a).size())\n#define MIN(a) *std::min_element((a).begin(),\
    \ (a).end())\n#define MAX(a) *std::max_element((a).begin(), (a).end())\ntemplate\
    \ <class T> T sum(const std::vector<T>& a) {\n    T res = T(0);\n    for (auto&&\
    \ ai : a) res += ai;\n    return res;\n}\n#define LB(a, x) std::lower_bound((a).begin(),\
    \ (a).end(), (x)) - (a).begin()\n#define UB(a, x) std::upper_bound((a).begin(),\
    \ (a).end(), (x)) - (a).begin()\ntemplate <class T, class U> inline bool chmin(T&\
    \ a, const U& b) { return (a > T(b) ? a = b, 1 : 0); }\ntemplate <class T, class\
    \ U> inline bool chmax(T& a, const U& b) { return (a < T(b) ? a = b, 1 : 0); }\n\
    \n// const value\nconstexpr int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};\nconstexpr\
    \ int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};\n\n// input\nstd::istream& operator>>(std::istream&\
    \ is, __int128_t& x) {\n    std::string s;\n    is >> s;\n    x = 0;\n    int\
    \ i = s[0] == '-' ? 1 : 0;\n    while (i < (int)(s.size())) x = 10 * x + s[i++]\
    \ - '0';\n    if (s[0] == '-') x = -x;\n    return is;\n}\nstd::istream& operator>>(std::istream&\
    \ is, __uint128_t& x) {\n    std::string s;\n    is >> s;\n    assert(s[0] !=\
    \ '-');\n    x = 0;\n    int i = 0;\n    while (i < (int)(s.size())) x = 10 *\
    \ x + s[i++] - '0';\n    return is;\n}\ntemplate <class T> std::istream& operator>>(std::istream&\
    \ is, std::vector<T>& v) {\n    for (auto&& i : v) is >> i;\n    return is;\n\
    }\ntemplate <class... T> void in(T&... a) { (std::cin >> ... >> a); }\nvoid scan()\
    \ {}\ntemplate <class Head, class... Tail> void scan(Head& head, Tail&... tail)\
    \ {\n    in(head);\n    scan(tail...);\n}\n\n// definition & input\n#define I32(...)\
    \     \\\n    i32 __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define I64(...)   \
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
    #define VEC2(type, name, h, w)                     \\\n    std::vector name((h),\
    \ std::vector<type>((w))); \\\n    scan(name)\n\n// output\nstd::ostream& operator<<(std::ostream&\
    \ os, const __int128_t& x) {\n    if (x == 0) {\n        return os << 0;\n   \
    \ }\n    __int128_t y = (x > 0 ? x : -x);\n    std::string res;\n    while (y)\
    \ {\n        res += y % 10 + '0';\n        y /= 10;\n    }\n    if (x < 0) res\
    \ += '-';\n    std::reverse(res.begin(), res.end());\n    return os << res;\n\
    }\nstd::ostream& operator<<(std::ostream& os, const __uint128_t& x) {\n    if\
    \ (x == 0) {\n        return os << 0;\n    }\n    __uint128_t y = x;\n    std::string\
    \ res;\n    while (y) {\n        res += y % 10 + '0';\n        y /= 10;\n    }\n\
    \    std::reverse(res.begin(), res.end());\n    return os << res;\n}\ntemplate\
    \ <class T> std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)\
    \ {\n    auto n = v.size();\n    for (size_t i = 0; i < n; i++) {\n        if\
    \ (i) os << ' ';\n        os << v[i];\n    }\n    return os;\n}\ntemplate <class...\
    \ T> void out(const T&... a) { (std::cout << ... << a); }\nvoid print() { out('\\\
    n'); }\ntemplate <class Head, class... Tail> void print(Head&& head, Tail&&...\
    \ tail) {\n    out(head);\n    if (sizeof...(Tail)) out(' ');\n    print(tail...);\n\
    }\n\n// I/O speed up\nstruct SetUpIO {\n    SetUpIO() {\n        std::ios::sync_with_stdio(false);\n\
    \        std::cin.tie(0);\n        std::cout << std::fixed << std::setprecision(15);\n\
    \    }\n} set_up_io;"
  dependsOn: []
  isVerificationFile: false
  path: my_template.hpp
  requiredBy: []
  timestamp: '2023-12-24 02:39:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: my_template.hpp
layout: document
redirect_from:
- /library/my_template.hpp
- /library/my_template.hpp.html
title: my_template.hpp
---
