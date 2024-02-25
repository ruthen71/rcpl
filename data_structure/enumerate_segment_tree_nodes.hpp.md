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
  bundledCode: "#line 2 \"data_structure/enumerate_segment_tree_nodes.hpp\"\n\n#include\
    \ <vector>\n\n// Segment Tree \u306B\u304A\u3044\u3066\u533A\u9593 [l, r) \u3092\
    \u30AB\u30D0\u30FC\u3059\u308B\u533A\u9593\u306E\u30CE\u30FC\u30C9\u756A\u53F7\
    \u3092\u51FA\u529B\n// \u533A\u9593\u306E\u4F4D\u7F6E\u304C\u5C0F\u3055\u3044\u9806\
    \u306B(\u5DE6\u304B\u3089)\u51FA\u529B\n// size \u306F SegmentTree \u306E size\
    \ \u3068\u540C\u3058\nstd::vector<int> enumerate_segment_tree_range_covering_nodes(const\
    \ int size, int l, int r) {\n    std::vector<int> ret, ret_rev;\n    l += size;\n\
    \    r += size;\n    while (l < r) {\n        if (l & 1) ret.push_back(l++);\n\
    \        if (r & 1) ret_rev.push_back(--r);\n        l >>= 1;\n        r >>= 1;\n\
    \    }\n    std::reverse(ret_rev.begin(), ret_rev.end());\n    ret.insert(ret.end(),\
    \ ret_rev.begin(), ret_rev.end());\n    return ret;\n}\n\n// Segment Tree \u306B\
    \u304A\u3044\u3066\u533A\u9593 [p, p + 1) \u304C\u542B\u307E\u308C\u308B\u533A\
    \u9593\u306E\u30CE\u30FC\u30C9\u756A\u53F7\u3092\u51FA\u529B\n// \u533A\u9593\u306E\
    \u5E45\u304C\u5C0F\u3055\u3044\u9806\u306B(\u4E0B\u304B\u3089)\u51FA\u529B\n//\
    \ size \u306F SegmentTree \u306E size \u3068\u540C\u3058\nstd::vector<int> enumerate_segment_tree_point_containing_nodes(const\
    \ int size, int p) {\n    p += size;\n    std::vector<int> ret;\n    for (int\
    \ i = 0; (1 << i) <= size; i++) ret.push_back(p >> i);\n    return ret;\n}\n"
  code: "#pragma once\n\n#include <vector>\n\n// Segment Tree \u306B\u304A\u3044\u3066\
    \u533A\u9593 [l, r) \u3092\u30AB\u30D0\u30FC\u3059\u308B\u533A\u9593\u306E\u30CE\
    \u30FC\u30C9\u756A\u53F7\u3092\u51FA\u529B\n// \u533A\u9593\u306E\u4F4D\u7F6E\u304C\
    \u5C0F\u3055\u3044\u9806\u306B(\u5DE6\u304B\u3089)\u51FA\u529B\n// size \u306F\
    \ SegmentTree \u306E size \u3068\u540C\u3058\nstd::vector<int> enumerate_segment_tree_range_covering_nodes(const\
    \ int size, int l, int r) {\n    std::vector<int> ret, ret_rev;\n    l += size;\n\
    \    r += size;\n    while (l < r) {\n        if (l & 1) ret.push_back(l++);\n\
    \        if (r & 1) ret_rev.push_back(--r);\n        l >>= 1;\n        r >>= 1;\n\
    \    }\n    std::reverse(ret_rev.begin(), ret_rev.end());\n    ret.insert(ret.end(),\
    \ ret_rev.begin(), ret_rev.end());\n    return ret;\n}\n\n// Segment Tree \u306B\
    \u304A\u3044\u3066\u533A\u9593 [p, p + 1) \u304C\u542B\u307E\u308C\u308B\u533A\
    \u9593\u306E\u30CE\u30FC\u30C9\u756A\u53F7\u3092\u51FA\u529B\n// \u533A\u9593\u306E\
    \u5E45\u304C\u5C0F\u3055\u3044\u9806\u306B(\u4E0B\u304B\u3089)\u51FA\u529B\n//\
    \ size \u306F SegmentTree \u306E size \u3068\u540C\u3058\nstd::vector<int> enumerate_segment_tree_point_containing_nodes(const\
    \ int size, int p) {\n    p += size;\n    std::vector<int> ret;\n    for (int\
    \ i = 0; (1 << i) <= size; i++) ret.push_back(p >> i);\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/enumerate_segment_tree_nodes.hpp
  requiredBy: []
  timestamp: '2024-02-25 18:15:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/enumerate_segment_tree_nodes.hpp
layout: document
title: "Segment Tree \u306E 1 \u70B9\u5909\u66F4\u3084\u533A\u9593\u7DCF\u7A4D\u3092\
  \u884C\u3046\u969B\u306B\u30A2\u30AF\u30BB\u30B9\u3059\u308B\u30CE\u30FC\u30C9\u756A\
  \u53F7\u306E\u5217\u6319"
---

Segment Tree の `set` や `prod` においてアクセスするノード番号を列挙する

Segment Tree の各ノードにデータ構造を乗せる際などに利用する

## 使用例

- [ABC342 G](https://atcoder.jp/contests/abc342/submissions/50636081)
    - Dual Segment Tree における作用素を `std::multiset` を用いて陽にすべて持っておくことで Undo 操作を実現している
