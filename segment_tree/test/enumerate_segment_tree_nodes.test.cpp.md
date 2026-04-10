---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: misc/countl_zero.hpp
    title: Countl Zero
  - icon: ':heavy_check_mark:'
    path: misc/topbit.hpp
    title: Topbit
  - icon: ':heavy_check_mark:'
    path: segment_tree/enumerate_segment_tree_nodes.hpp
    title: "Segment Tree \u306E 1 \u70B9\u5909\u66F4\u3084\u533A\u9593\u7DCF\u7A4D\
      \u3092\u884C\u3046\u969B\u306B\u30A2\u30AF\u30BB\u30B9\u3059\u308B\u30CE\u30FC\
      \u30C9\u756A\u53F7\u306E\u5217\u6319"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://atcoder.jp/contests/abc349/tasks/abc349_d
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"segment_tree/test/enumerate_segment_tree_nodes.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include <iostream>\n\
    \n#line 2 \"segment_tree/enumerate_segment_tree_nodes.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <vector>\n\n#line 2 \"misc/topbit.hpp\"\n\n#line\
    \ 2 \"misc/countl_zero.hpp\"\n\n#if __cplusplus >= 202002L\n#include <bit>\n#endif\n\
    \n// countl_zero\n// (000, 001, 010, 011, 100) -> (32, 31, 30, 30, 29)\n#if __cplusplus\
    \ >= 202002L\nusing std::countl_zero;\n#else\nint countl_zero(unsigned int x)\
    \ {\n    return x == 0 ? 32 : __builtin_clz(x);\n}\nint countl_zero(unsigned long\
    \ long int x) {\n    return x == 0 ? 64 : __builtin_clzll(x);\n}\n#endif\nint\
    \ countl_zero(int x) { return countl_zero((unsigned int)(x)); }\nint countl_zero(long\
    \ long int x) {\n    return countl_zero((unsigned long long int)(x));\n}\n#line\
    \ 4 \"misc/topbit.hpp\"\n\n// topbit\n// (000, 001, 010, 011, 100) -> (-1, 0,\
    \ 1, 1, 2)\nint topbit(int x) { return 31 - countl_zero(x); }\nint topbit(unsigned\
    \ int x) { return 31 - countl_zero(x); }\nint topbit(long long int x) { return\
    \ 63 - countl_zero(x); }\nint topbit(unsigned long long int x) { return 63 - countl_zero(x);\
    \ }\n#line 8 \"segment_tree/enumerate_segment_tree_nodes.hpp\"\n\n// \u9577\u3055\
    \ size (2\u3079\u304D) \u306E Segment Tree \u306B\u304A\u3044\u3066\u533A\u9593\
    \ [l, r)\n// \u3092\u30AB\u30D0\u30FC\u3059\u308B\u533A\u9593\u306E\u30CE\u30FC\
    \u30C9\u756A\u53F7\u3092\u8FD4\u3059 \u533A\u9593\u306E\u4F4D\u7F6E\u304C\u5C0F\
    \u3055\u3044\u9806\u306B (\u5DE6\u304B\u3089) \u8FD4\u3059\ntemplate <class T>\n\
    std::vector<T> enumerate_segment_tree_range_covering_nodes(const T size,\n   \
    \                                                        T l,\n              \
    \                                             T r) {\n    std::vector<T> ret,\
    \ ret_rev;\n    l += size;\n    r += size;\n    while (l < r) {\n        if (l\
    \ & 1) ret.push_back(l++);\n        if (r & 1) ret_rev.push_back(--r);\n     \
    \   l >>= 1;\n        r >>= 1;\n    }\n    std::reverse(ret_rev.begin(), ret_rev.end());\n\
    \    ret.insert(ret.end(), ret_rev.begin(), ret_rev.end());\n    return ret;\n\
    }\n\n// \u9577\u3055 size (2\u3079\u304D) \u306E Segment Tree \u306B\u304A\u3044\
    \u3066 seg[p]\n// \u304C\u542B\u307E\u308C\u308B\u533A\u9593\u306E\u30CE\u30FC\
    \u30C9\u756A\u53F7\u3092\u8FD4\u3059 \u533A\u9593\u306E\u5E45\u304C\u5C0F\u3055\
    \u3044\u9806\u306B (\u4E0B\u304B\u3089) \u8FD4\u3059\ntemplate <class T>\nstd::vector<T>\
    \ enumerate_segment_tree_point_containing_nodes(const T size,\n              \
    \                                               T p) {\n    p += size;\n    std::vector<T>\
    \ ret;\n    for (int i = 0; (1LL << i) <= size; i++) ret.push_back(p >> i);\n\
    \    return ret;\n}\n\n// \u9577\u3055 size (2\u3079\u304D) \u306E Segment Tree\
    \ \u306B\u304A\u3044\u3066\u30CE\u30FC\u30C9\u756A\u53F7 i \u306B\u5BFE\u5FDC\u3059\
    \u308B\u533A\u9593 [l, r)\n// \u3092\u8FD4\u3059 https://atcoder.jp/contests/abc349/tasks/abc349_d\n\
    // https://atcoder.jp/contests/abc355/tasks/abc355_e\ntemplate <class T>\nstd::pair<T,\
    \ T> segment_tree_node_to_range(const T size, const T i) {\n    assert(size >\
    \ 0 and i > 0);\n    // (1 << n) = size\n    const int n = topbit(size);\n   \
    \ // i \u306E\u6700\u4E0A\u4F4D\u30D3\u30C3\u30C8\n    const int topbiti = topbit(i);\n\
    \    // [(2 ^ x) * y, (2 ^ x) * (y + 1))\n    const int x = n - topbiti;\n   \
    \ const T y = i - (1LL << topbiti);\n    return {(1LL << x) * y, (1LL << x) *\
    \ (y + 1)};\n}\n#line 6 \"segment_tree/test/enumerate_segment_tree_nodes.test.cpp\"\
    \n\nstd::vector<std::pair<long long, long long>> solve(long long l, long long\
    \ r) {\n    const long long n2 = 1LL << 60;\n    auto res = enumerate_segment_tree_range_covering_nodes(n2,\
    \ l, r);\n    std::vector<std::pair<long long, long long>> ans;\n    for (auto&&\
    \ i : res) {\n        ans.push_back(segment_tree_node_to_range(n2, i));\n    }\n\
    \    return ans;\n}\n\nvoid test1_sample1() {\n    long long l = 3, r = 19;\n\
    \    std::vector<std::pair<long long, long long>> sol = {\n        {3, 4}, {4,\
    \ 8}, {8, 16}, {16, 18}, {18, 19}};\n    assert(solve(l, r) == sol);\n}\nvoid\
    \ test2_sample2() {\n    long long l = 0, r = 1024;\n    std::vector<std::pair<long\
    \ long, long long>> sol = {{0, 1024}};\n    assert(solve(l, r) == sol);\n}\nvoid\
    \ test3_sample3() {\n    long long l = 3940649673945088, r = 11549545024454656;\n\
    \    std::vector<std::pair<long long, long long>> sol = {\n        {3940649673945088,\
    \ 3940649673949184},\n        {3940649673949184, 4503599627370496},\n        {4503599627370496,\
    \ 9007199254740992},\n        {9007199254740992, 11258999068426240},\n       \
    \ {11258999068426240, 11540474045136896},\n        {11540474045136896, 11549270138159104},\n\
    \        {11549270138159104, 11549545016066048},\n        {11549545016066048,\
    \ 11549545024454656}};\n    assert(solve(l, r) == sol);\n}\n\nint main() {\n \
    \   // https://atcoder.jp/contests/abc349/tasks/abc349_d\n    test1_sample1();\n\
    \    test2_sample2();\n    test3_sample3();\n    int a, b;\n    std::cin >> a\
    \ >> b;\n    std::cout << a + b << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include <iostream>\n\
    \n#include \"../../segment_tree/enumerate_segment_tree_nodes.hpp\"\n\nstd::vector<std::pair<long\
    \ long, long long>> solve(long long l, long long r) {\n    const long long n2\
    \ = 1LL << 60;\n    auto res = enumerate_segment_tree_range_covering_nodes(n2,\
    \ l, r);\n    std::vector<std::pair<long long, long long>> ans;\n    for (auto&&\
    \ i : res) {\n        ans.push_back(segment_tree_node_to_range(n2, i));\n    }\n\
    \    return ans;\n}\n\nvoid test1_sample1() {\n    long long l = 3, r = 19;\n\
    \    std::vector<std::pair<long long, long long>> sol = {\n        {3, 4}, {4,\
    \ 8}, {8, 16}, {16, 18}, {18, 19}};\n    assert(solve(l, r) == sol);\n}\nvoid\
    \ test2_sample2() {\n    long long l = 0, r = 1024;\n    std::vector<std::pair<long\
    \ long, long long>> sol = {{0, 1024}};\n    assert(solve(l, r) == sol);\n}\nvoid\
    \ test3_sample3() {\n    long long l = 3940649673945088, r = 11549545024454656;\n\
    \    std::vector<std::pair<long long, long long>> sol = {\n        {3940649673945088,\
    \ 3940649673949184},\n        {3940649673949184, 4503599627370496},\n        {4503599627370496,\
    \ 9007199254740992},\n        {9007199254740992, 11258999068426240},\n       \
    \ {11258999068426240, 11540474045136896},\n        {11540474045136896, 11549270138159104},\n\
    \        {11549270138159104, 11549545016066048},\n        {11549545016066048,\
    \ 11549545024454656}};\n    assert(solve(l, r) == sol);\n}\n\nint main() {\n \
    \   // https://atcoder.jp/contests/abc349/tasks/abc349_d\n    test1_sample1();\n\
    \    test2_sample2();\n    test3_sample3();\n    int a, b;\n    std::cin >> a\
    \ >> b;\n    std::cout << a + b << '\\n';\n    return 0;\n}\n"
  dependsOn:
  - segment_tree/enumerate_segment_tree_nodes.hpp
  - misc/topbit.hpp
  - misc/countl_zero.hpp
  isVerificationFile: true
  path: segment_tree/test/enumerate_segment_tree_nodes.test.cpp
  requiredBy: []
  timestamp: '2026-04-11 00:41:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: segment_tree/test/enumerate_segment_tree_nodes.test.cpp
layout: document
redirect_from:
- /verify/segment_tree/test/enumerate_segment_tree_nodes.test.cpp
- /verify/segment_tree/test/enumerate_segment_tree_nodes.test.cpp.html
title: segment_tree/test/enumerate_segment_tree_nodes.test.cpp
---
