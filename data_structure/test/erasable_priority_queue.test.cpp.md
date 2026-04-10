---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/erasable_priority_queue.hpp
    title: "Erasable Priority Queue (\u524A\u9664\u53EF\u80FD\u512A\u5148\u5EA6\u4ED8\
      \u304D\u30AD\u30E5\u30FC)"
  - icon: ':heavy_check_mark:'
    path: misc/bit_ceil.hpp
    title: Bit Ceil
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
    - https://atcoder.jp/contests/abc342/tasks/abc342_g
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"data_structure/test/erasable_priority_queue.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include <iostream>\n\
    \n#line 2 \"data_structure/erasable_priority_queue.hpp\"\n\n#include <queue>\n\
    #include <cassert>\n\n// \u524A\u9664\u53EF\u80FD\u306A\u512A\u5148\u5EA6\u4ED8\
    \u304D\u30AD\u30E5\u30FC\n// \u30AD\u30E5\u30FC\u306B\u542B\u307E\u308C\u3066\u3044\
    \u306A\u3044\u8981\u7D20\u3092\u524A\u9664\u3057\u3088\u3046\u3068\u3057\u305F\
    \u5834\u5408\u58CA\u308C\u308B\n// std::multiset \u3088\u308A\u3082\u5B9A\u6570\
    \u500D\u304C\u826F\u3044\ntemplate <class T, class Container = std::vector<T>,\
    \ class Compare = std::less<T>> struct ErasablePriorityQueue {\n   private:\n\
    \    std::priority_queue<T, Container, Compare> que, erase_que;\n    void reduce()\
    \ {\n        while (que.size() and erase_que.size()) {\n            if (que.top()\
    \ == erase_que.top()) {\n                que.pop();\n                erase_que.pop();\n\
    \            } else {\n                // Compare = std::less<T> \u306A\u3089\
    \ que.top() < erase_que.top()\n                // Compare()(que.top(), erase_que.top())\
    \ == true\n                assert(!Compare()(que.top(), erase_que.top()));\n \
    \               break;\n            }\n        }\n    }\n\n   public:\n    size_t\
    \ size() const {\n        assert(que.size() >= erase_que.size());\n        return\
    \ que.size() - erase_que.size();\n    }\n    void push(const T t) { que.push(t);\
    \ }\n    void erase(const T t) { erase_que.push(t); }\n    const T& top() {\n\
    \        reduce();\n        return que.top();\n    }\n    void pop() {\n     \
    \   reduce();\n        que.pop();\n    }\n};\n// ErasablePriorityQueue<int, std::vector<int>,\
    \ std::greater<int>> que; // \u6700\u5C0F\u306E\u3082\u306E\u304B\u3089\u53D6\u308A\
    \u51FA\u305B\u308B\n#line 2 \"misc/bit_ceil.hpp\"\n\n#line 4 \"misc/bit_ceil.hpp\"\
    \n\n#if __cplusplus >= 202002L\n#include <bit>\n#endif\n\n// bit_ceil\n// (0,\
    \ 1, 2, 3, 4) -> (1, 1, 2, 4, 4)\n#if __cplusplus >= 202002L\nusing std::bit_ceil;\n\
    #else\nunsigned int bit_ceil(unsigned int x) {\n    unsigned int p = 1;\n    while\
    \ (p < x) p *= 2;\n    return p;\n}\nunsigned long long int bit_ceil(unsigned\
    \ long long int x) {\n    unsigned long long int p = 1;\n    while (p < x) p *=\
    \ 2;\n    return p;\n}\n#endif\nint bit_ceil(int x) {\n    assert(x >= 0);\n \
    \   return bit_ceil((unsigned int)(x));\n}\nlong long int bit_ceil(long long int\
    \ x) {\n    assert(x >= 0);\n    return bit_ceil((unsigned long long int)(x));\n\
    }\n#line 2 \"segment_tree/enumerate_segment_tree_nodes.hpp\"\n\n#include <algorithm>\n\
    #line 5 \"segment_tree/enumerate_segment_tree_nodes.hpp\"\n#include <vector>\n\
    \n#line 2 \"misc/topbit.hpp\"\n\n#line 2 \"misc/countl_zero.hpp\"\n\n#if __cplusplus\
    \ >= 202002L\n#include <bit>\n#endif\n\n// countl_zero\n// (000, 001, 010, 011,\
    \ 100) -> (32, 31, 30, 30, 29)\n#if __cplusplus >= 202002L\nusing std::countl_zero;\n\
    #else\nint countl_zero(unsigned int x) {\n    return x == 0 ? 32 : __builtin_clz(x);\n\
    }\nint countl_zero(unsigned long long int x) {\n    return x == 0 ? 64 : __builtin_clzll(x);\n\
    }\n#endif\nint countl_zero(int x) { return countl_zero((unsigned int)(x)); }\n\
    int countl_zero(long long int x) {\n    return countl_zero((unsigned long long\
    \ int)(x));\n}\n#line 4 \"misc/topbit.hpp\"\n\n// topbit\n// (000, 001, 010, 011,\
    \ 100) -> (-1, 0, 1, 1, 2)\nint topbit(int x) { return 31 - countl_zero(x); }\n\
    int topbit(unsigned int x) { return 31 - countl_zero(x); }\nint topbit(long long\
    \ int x) { return 63 - countl_zero(x); }\nint topbit(unsigned long long int x)\
    \ { return 63 - countl_zero(x); }\n#line 8 \"segment_tree/enumerate_segment_tree_nodes.hpp\"\
    \n\n// \u9577\u3055 size (2\u3079\u304D) \u306E Segment Tree \u306B\u304A\u3044\
    \u3066\u533A\u9593 [l, r)\n// \u3092\u30AB\u30D0\u30FC\u3059\u308B\u533A\u9593\
    \u306E\u30CE\u30FC\u30C9\u756A\u53F7\u3092\u8FD4\u3059 \u533A\u9593\u306E\u4F4D\
    \u7F6E\u304C\u5C0F\u3055\u3044\u9806\u306B (\u5DE6\u304B\u3089) \u8FD4\u3059\n\
    template <class T>\nstd::vector<T> enumerate_segment_tree_range_covering_nodes(const\
    \ T size,\n                                                           T l,\n \
    \                                                          T r) {\n    std::vector<T>\
    \ ret, ret_rev;\n    l += size;\n    r += size;\n    while (l < r) {\n       \
    \ if (l & 1) ret.push_back(l++);\n        if (r & 1) ret_rev.push_back(--r);\n\
    \        l >>= 1;\n        r >>= 1;\n    }\n    std::reverse(ret_rev.begin(),\
    \ ret_rev.end());\n    ret.insert(ret.end(), ret_rev.begin(), ret_rev.end());\n\
    \    return ret;\n}\n\n// \u9577\u3055 size (2\u3079\u304D) \u306E Segment Tree\
    \ \u306B\u304A\u3044\u3066 seg[p]\n// \u304C\u542B\u307E\u308C\u308B\u533A\u9593\
    \u306E\u30CE\u30FC\u30C9\u756A\u53F7\u3092\u8FD4\u3059 \u533A\u9593\u306E\u5E45\
    \u304C\u5C0F\u3055\u3044\u9806\u306B (\u4E0B\u304B\u3089) \u8FD4\u3059\ntemplate\
    \ <class T>\nstd::vector<T> enumerate_segment_tree_point_containing_nodes(const\
    \ T size,\n                                                             T p) {\n\
    \    p += size;\n    std::vector<T> ret;\n    for (int i = 0; (1LL << i) <= size;\
    \ i++) ret.push_back(p >> i);\n    return ret;\n}\n\n// \u9577\u3055 size (2\u3079\
    \u304D) \u306E Segment Tree \u306B\u304A\u3044\u3066\u30CE\u30FC\u30C9\u756A\u53F7\
    \ i \u306B\u5BFE\u5FDC\u3059\u308B\u533A\u9593 [l, r)\n// \u3092\u8FD4\u3059 https://atcoder.jp/contests/abc349/tasks/abc349_d\n\
    // https://atcoder.jp/contests/abc355/tasks/abc355_e\ntemplate <class T>\nstd::pair<T,\
    \ T> segment_tree_node_to_range(const T size, const T i) {\n    assert(size >\
    \ 0 and i > 0);\n    // (1 << n) = size\n    const int n = topbit(size);\n   \
    \ // i \u306E\u6700\u4E0A\u4F4D\u30D3\u30C3\u30C8\n    const int topbiti = topbit(i);\n\
    \    // [(2 ^ x) * y, (2 ^ x) * (y + 1))\n    const int x = n - topbiti;\n   \
    \ const T y = i - (1LL << topbiti);\n    return {(1LL << x) * y, (1LL << x) *\
    \ (y + 1)};\n}\n#line 8 \"data_structure/test/erasable_priority_queue.test.cpp\"\
    \n\nstd::vector<int> solve(std::vector<int>& a,\n                       std::vector<std::tuple<int,\
    \ int, int, int>>& query) {\n    const int n = (int)(a.size());\n\n    // \u524A\
    \u9664\u53EF\u80FD\u306A priority_queue \u3092\u4E57\u305B\u305F\u30BB\u30B0\u6728\
    \u3092\u4F5C\u6210\n    int size = bit_ceil(n);\n    std::vector<ErasablePriorityQueue<int>>\
    \ d(size << 1);\n    for (int i = 0; i < n; i++) d[i + size].push(a[i]);\n\n \
    \   std::vector<int> ans;\n    for (auto&& [type, l, r, x] : query) {\n      \
    \  if (type == 1) {\n            l--;\n            auto nodes =\n            \
    \    enumerate_segment_tree_range_covering_nodes(size, l, r);\n            for\
    \ (auto&& i : nodes) d[i].push(x);\n        } else if (type == 2) {\n        \
    \    l--;\n            auto [ptype, pl, pr, px] = query[l];\n            auto\
    \ nodes =\n                enumerate_segment_tree_range_covering_nodes(size, pl,\
    \ pr);\n            for (auto&& i : nodes) d[i].erase(px);\n        } else {\n\
    \            l--;\n            auto nodes = enumerate_segment_tree_point_containing_nodes(size,\
    \ l);\n            int mx = 0;\n            for (auto&& i : nodes) {\n       \
    \         if (d[i].size() > 0) mx = std::max(mx, d[i].top());\n            }\n\
    \            ans.push_back(mx);\n        }\n    }\n    return ans;\n}\n\nvoid\
    \ test1_sample1() {\n    std::vector<int> a = {2, 7, 1, 8, 2, 8};\n    std::vector<std::tuple<int,\
    \ int, int, int>> query = {\n        {3, 1, -1, -1}, {3, 3, -1, -1}, {3, 4, -1,\
    \ -1}, {1, 1, 5, 4},\n        {3, 1, -1, -1}, {3, 3, -1, -1}, {3, 4, -1, -1},\
    \ {1, 3, 6, 9},\n        {3, 1, -1, -1}, {3, 3, -1, -1}, {3, 4, -1, -1}, {2, 4,\
    \ -1, -1},\n        {3, 1, -1, -1}, {3, 3, -1, -1}, {3, 4, -1, -1}};\n    std::vector<int>\
    \ sol = {2, 1, 8, 4, 4, 8, 4, 9, 9, 2, 9, 9};\n    assert(solve(a, query) == sol);\n\
    }\n\nvoid test2_sample2() {\n    std::vector<int> a = {721, 78,  541, 256, 970,\
    \ 478, 370, 467,\n                          344, 542, 43,  166, 619, 17,  592,\
    \ 222,\n                          983, 729, 338, 747, 62,  452, 815, 838};\n \
    \   std::vector<std::tuple<int, int, int, int>> query = {\n        {3, 10, -1,\
    \ -1}, {3, 8, -1, -1},  {3, 8, -1, -1},  {3, 13, -1, -1},\n        {3, 9, -1,\
    \ -1},  {1, 1, 17, 251}, {3, 3, -1, -1},  {3, 19, -1, -1},\n        {3, 13, -1,\
    \ -1}, {3, 22, -1, -1}, {3, 1, -1, -1},  {3, 15, -1, -1},\n        {3, 18, -1,\
    \ -1}, {3, 10, -1, -1}, {3, 15, -1, -1}, {1, 16, 19, 883},\n        {1, 8, 23,\
    \ 212}, {3, 5, -1, -1},  {3, 13, -1, -1}, {2, 6, -1, -1},\n        {3, 15, -1,\
    \ -1}, {1, 5, 18, 914}, {2, 17, -1, -1}, {3, 20, -1, -1},\n        {1, 23, 23,\
    \ 56}, {3, 13, -1, -1}, {2, 25, -1, -1}, {3, 13, -1, -1},\n        {3, 13, -1,\
    \ -1}, {3, 10, -1, -1}, {2, 16, -1, -1}, {1, 17, 22, 308},\n        {3, 19, -1,\
    \ -1}, {3, 17, -1, -1}, {3, 7, -1, -1}};\n    std::vector<int> sol = {542, 467,\
    \ 467, 619, 344, 541, 338, 619, 452,\n                            721, 592, 729,\
    \ 542, 592, 970, 619, 592, 747,\n                            914, 914, 914, 914,\
    \ 338, 983, 914};\n    assert(solve(a, query) == sol);\n}\n\nint main() {\n  \
    \  // https://atcoder.jp/contests/abc342/tasks/abc342_g\n    test1_sample1();\n\
    \    test2_sample2();\n    int a, b;\n    std::cin >> a >> b;\n    std::cout <<\
    \ a + b << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include <iostream>\n\
    \n#include \"../../data_structure/erasable_priority_queue.hpp\"\n#include \"../../misc/bit_ceil.hpp\"\
    \n#include \"../../segment_tree/enumerate_segment_tree_nodes.hpp\"\n\nstd::vector<int>\
    \ solve(std::vector<int>& a,\n                       std::vector<std::tuple<int,\
    \ int, int, int>>& query) {\n    const int n = (int)(a.size());\n\n    // \u524A\
    \u9664\u53EF\u80FD\u306A priority_queue \u3092\u4E57\u305B\u305F\u30BB\u30B0\u6728\
    \u3092\u4F5C\u6210\n    int size = bit_ceil(n);\n    std::vector<ErasablePriorityQueue<int>>\
    \ d(size << 1);\n    for (int i = 0; i < n; i++) d[i + size].push(a[i]);\n\n \
    \   std::vector<int> ans;\n    for (auto&& [type, l, r, x] : query) {\n      \
    \  if (type == 1) {\n            l--;\n            auto nodes =\n            \
    \    enumerate_segment_tree_range_covering_nodes(size, l, r);\n            for\
    \ (auto&& i : nodes) d[i].push(x);\n        } else if (type == 2) {\n        \
    \    l--;\n            auto [ptype, pl, pr, px] = query[l];\n            auto\
    \ nodes =\n                enumerate_segment_tree_range_covering_nodes(size, pl,\
    \ pr);\n            for (auto&& i : nodes) d[i].erase(px);\n        } else {\n\
    \            l--;\n            auto nodes = enumerate_segment_tree_point_containing_nodes(size,\
    \ l);\n            int mx = 0;\n            for (auto&& i : nodes) {\n       \
    \         if (d[i].size() > 0) mx = std::max(mx, d[i].top());\n            }\n\
    \            ans.push_back(mx);\n        }\n    }\n    return ans;\n}\n\nvoid\
    \ test1_sample1() {\n    std::vector<int> a = {2, 7, 1, 8, 2, 8};\n    std::vector<std::tuple<int,\
    \ int, int, int>> query = {\n        {3, 1, -1, -1}, {3, 3, -1, -1}, {3, 4, -1,\
    \ -1}, {1, 1, 5, 4},\n        {3, 1, -1, -1}, {3, 3, -1, -1}, {3, 4, -1, -1},\
    \ {1, 3, 6, 9},\n        {3, 1, -1, -1}, {3, 3, -1, -1}, {3, 4, -1, -1}, {2, 4,\
    \ -1, -1},\n        {3, 1, -1, -1}, {3, 3, -1, -1}, {3, 4, -1, -1}};\n    std::vector<int>\
    \ sol = {2, 1, 8, 4, 4, 8, 4, 9, 9, 2, 9, 9};\n    assert(solve(a, query) == sol);\n\
    }\n\nvoid test2_sample2() {\n    std::vector<int> a = {721, 78,  541, 256, 970,\
    \ 478, 370, 467,\n                          344, 542, 43,  166, 619, 17,  592,\
    \ 222,\n                          983, 729, 338, 747, 62,  452, 815, 838};\n \
    \   std::vector<std::tuple<int, int, int, int>> query = {\n        {3, 10, -1,\
    \ -1}, {3, 8, -1, -1},  {3, 8, -1, -1},  {3, 13, -1, -1},\n        {3, 9, -1,\
    \ -1},  {1, 1, 17, 251}, {3, 3, -1, -1},  {3, 19, -1, -1},\n        {3, 13, -1,\
    \ -1}, {3, 22, -1, -1}, {3, 1, -1, -1},  {3, 15, -1, -1},\n        {3, 18, -1,\
    \ -1}, {3, 10, -1, -1}, {3, 15, -1, -1}, {1, 16, 19, 883},\n        {1, 8, 23,\
    \ 212}, {3, 5, -1, -1},  {3, 13, -1, -1}, {2, 6, -1, -1},\n        {3, 15, -1,\
    \ -1}, {1, 5, 18, 914}, {2, 17, -1, -1}, {3, 20, -1, -1},\n        {1, 23, 23,\
    \ 56}, {3, 13, -1, -1}, {2, 25, -1, -1}, {3, 13, -1, -1},\n        {3, 13, -1,\
    \ -1}, {3, 10, -1, -1}, {2, 16, -1, -1}, {1, 17, 22, 308},\n        {3, 19, -1,\
    \ -1}, {3, 17, -1, -1}, {3, 7, -1, -1}};\n    std::vector<int> sol = {542, 467,\
    \ 467, 619, 344, 541, 338, 619, 452,\n                            721, 592, 729,\
    \ 542, 592, 970, 619, 592, 747,\n                            914, 914, 914, 914,\
    \ 338, 983, 914};\n    assert(solve(a, query) == sol);\n}\n\nint main() {\n  \
    \  // https://atcoder.jp/contests/abc342/tasks/abc342_g\n    test1_sample1();\n\
    \    test2_sample2();\n    int a, b;\n    std::cin >> a >> b;\n    std::cout <<\
    \ a + b << '\\n';\n    return 0;\n}\n"
  dependsOn:
  - data_structure/erasable_priority_queue.hpp
  - misc/bit_ceil.hpp
  - segment_tree/enumerate_segment_tree_nodes.hpp
  - misc/topbit.hpp
  - misc/countl_zero.hpp
  isVerificationFile: true
  path: data_structure/test/erasable_priority_queue.test.cpp
  requiredBy: []
  timestamp: '2026-04-11 00:41:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: data_structure/test/erasable_priority_queue.test.cpp
layout: document
redirect_from:
- /verify/data_structure/test/erasable_priority_queue.test.cpp
- /verify/data_structure/test/erasable_priority_queue.test.cpp.html
title: data_structure/test/erasable_priority_queue.test.cpp
---
