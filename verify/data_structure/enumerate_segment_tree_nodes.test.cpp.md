---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/enumerate_segment_tree_nodes.hpp
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
    PROBLEM: https://atcoder.jp/contests/abc349/tasks/abc349_d
    links:
    - https://atcoder.jp/contests/abc349/tasks/abc349_d
  bundledCode: "#line 1 \"verify/data_structure/enumerate_segment_tree_nodes.test.cpp\"\
    \n#define PROBLEM \"https://atcoder.jp/contests/abc349/tasks/abc349_d\"\n\n#include\
    \ <iostream>\n#line 2 \"data_structure/enumerate_segment_tree_nodes.hpp\"\n\n\
    #include <vector>\n#include <cassert>\n#include <algorithm>\n\n// \u9577\u3055\
    \ size (2\u3079\u304D) \u306E Segment Tree \u306B\u304A\u3044\u3066\u533A\u9593\
    \ [l, r) \u3092\u30AB\u30D0\u30FC\u3059\u308B\u533A\u9593\u306E\u30CE\u30FC\u30C9\
    \u756A\u53F7\u3092\u8FD4\u3059\n// \u533A\u9593\u306E\u4F4D\u7F6E\u304C\u5C0F\u3055\
    \u3044\u9806\u306B (\u5DE6\u304B\u3089) \u8FD4\u3059\ntemplate <class T> std::vector<T>\
    \ enumerate_segment_tree_range_covering_nodes(const T size, T l, T r) {\n    std::vector<T>\
    \ ret, ret_rev;\n    l += size;\n    r += size;\n    while (l < r) {\n       \
    \ if (l & 1) ret.push_back(l++);\n        if (r & 1) ret_rev.push_back(--r);\n\
    \        l >>= 1;\n        r >>= 1;\n    }\n    std::reverse(ret_rev.begin(),\
    \ ret_rev.end());\n    ret.insert(ret.end(), ret_rev.begin(), ret_rev.end());\n\
    \    return ret;\n}\n\n// \u9577\u3055 size (2\u3079\u304D) \u306E Segment Tree\
    \ \u306B\u304A\u3044\u3066 seg[p] \u304C\u542B\u307E\u308C\u308B\u533A\u9593\u306E\
    \u30CE\u30FC\u30C9\u756A\u53F7\u3092\u8FD4\u3059\n// \u533A\u9593\u306E\u5E45\u304C\
    \u5C0F\u3055\u3044\u9806\u306B (\u4E0B\u304B\u3089) \u8FD4\u3059\ntemplate <class\
    \ T> std::vector<T> enumerate_segment_tree_point_containing_nodes(const T size,\
    \ T p) {\n    p += size;\n    std::vector<T> ret;\n    for (int i = 0; (1LL <<\
    \ i) <= size; i++) ret.push_back(p >> i);\n    return ret;\n}\n\n// \u9577\u3055\
    \ size (2\u3079\u304D) \u306E Segment Tree \u306B\u304A\u3044\u3066\u30CE\u30FC\
    \u30C9\u756A\u53F7 i \u306B\u5BFE\u5FDC\u3059\u308B\u533A\u9593 [l, r) \u3092\u8FD4\
    \u3059\n// https://atcoder.jp/contests/abc349/tasks/abc349_d\n// https://atcoder.jp/contests/abc355/tasks/abc355_e\n\
    template <class T> std::pair<T, T> segment_tree_node_to_range(const T size, const\
    \ T i) {\n    assert(size > 0 and i > 0);\n    // (1 << n) = size\n    const int\
    \ n = 63 - __builtin_clzll(size);\n    // i \u306E\u6700\u4E0A\u4F4D\u30D3\u30C3\
    \u30C8\n    const int topbiti = 63 - __builtin_clzll(i);\n    // [(2 ^ x) * y,\
    \ (2 ^ x) * (y + 1))\n    const int x = n - topbiti;\n    const T y = i - (1LL\
    \ << topbiti);\n    return {(1LL << x) * y, (1LL << x) * (y + 1)};\n}\n#line 5\
    \ \"verify/data_structure/enumerate_segment_tree_nodes.test.cpp\"\n\nint main()\
    \ {\n    long long L, R;\n    std::cin >> L >> R;\n    const long long N2 = 1LL\
    \ << 60;\n    auto res = enumerate_segment_tree_range_covering_nodes(N2, L, R);\n\
    \    std::cout << res.size() << '\\n';\n    for (auto&& i : res) {\n        auto\
    \ [l, r] = segment_tree_node_to_range(N2, i);\n        std::cout << l << ' ' <<\
    \ r << '\\n';\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc349/tasks/abc349_d\"\n\n\
    #include <iostream>\n#include \"data_structure/enumerate_segment_tree_nodes.hpp\"\
    \n\nint main() {\n    long long L, R;\n    std::cin >> L >> R;\n    const long\
    \ long N2 = 1LL << 60;\n    auto res = enumerate_segment_tree_range_covering_nodes(N2,\
    \ L, R);\n    std::cout << res.size() << '\\n';\n    for (auto&& i : res) {\n\
    \        auto [l, r] = segment_tree_node_to_range(N2, i);\n        std::cout <<\
    \ l << ' ' << r << '\\n';\n    }\n    return 0;\n}"
  dependsOn:
  - data_structure/enumerate_segment_tree_nodes.hpp
  isVerificationFile: true
  path: verify/data_structure/enumerate_segment_tree_nodes.test.cpp
  requiredBy: []
  timestamp: '2024-08-09 02:21:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/data_structure/enumerate_segment_tree_nodes.test.cpp
layout: document
redirect_from:
- /verify/verify/data_structure/enumerate_segment_tree_nodes.test.cpp
- /verify/verify/data_structure/enumerate_segment_tree_nodes.test.cpp.html
title: verify/data_structure/enumerate_segment_tree_nodes.test.cpp
---
