---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_dsl/aoj_dsl_1_b.test.cpp
    title: verify/aoj_dsl/aoj_dsl_1_b.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data_structure/weighted_unionfind.md
    document_title: "Weighted UnionFind (\u91CD\u307F\u3064\u304D UnionFind)"
    links: []
  bundledCode: "#line 2 \"src/data_structure/weighted_unionfind.hpp\"\n\ntemplate\
    \ <class T> struct weighted_unionfind {\n    std::vector<int> parents;\n    std::vector<T>\
    \ diff_weight;\n\n    weighted_unionfind() {}\n    weighted_unionfind(int n) :\
    \ parents(n, -1), diff_weight(n) {}\n\n    int leader(int x) {\n        if (parents[x]\
    \ < 0) {\n            return x;\n        } else {\n            int r = leader(parents[x]);\n\
    \            diff_weight[x] += diff_weight[parents[x]];\n            return parents[x]\
    \ = r;\n        }\n    }\n\n    T weight(int x) {\n        leader(x);\n      \
    \  return diff_weight[x];\n    }\n\n    // weight(y) = weight(x) + w\n    bool\
    \ merge(int x, int y, T w) {\n        w += weight(x);\n        w -= weight(y);\n\
    \        x = leader(x), y = leader(y);\n        if (x == y) return false;\n  \
    \      if (parents[x] > parents[y]) std::swap(x, y), w = -w;\n        parents[x]\
    \ += parents[y];\n        parents[y] = x;\n        diff_weight[y] = w;\n     \
    \   return true;\n    }\n\n    // return weight(y) - weight(x)\n    T diff(int\
    \ x, int y) { return weight(y) - weight(x); }\n\n    bool same(int x, int y) {\
    \ return leader(x) == leader(y); }\n\n    int size(int x) { return -parents[leader(x)];\
    \ }\n\n    void init(int n) { parents.assign(n, -1), diff_weight.assign(n, 0);\
    \ }  // reset\n};\n\n/**\n * @brief Weighted UnionFind (\u91CD\u307F\u3064\u304D\
    \ UnionFind)\n * @docs docs/data_structure/weighted_unionfind.md\n */\n"
  code: "#pragma once\n\ntemplate <class T> struct weighted_unionfind {\n    std::vector<int>\
    \ parents;\n    std::vector<T> diff_weight;\n\n    weighted_unionfind() {}\n \
    \   weighted_unionfind(int n) : parents(n, -1), diff_weight(n) {}\n\n    int leader(int\
    \ x) {\n        if (parents[x] < 0) {\n            return x;\n        } else {\n\
    \            int r = leader(parents[x]);\n            diff_weight[x] += diff_weight[parents[x]];\n\
    \            return parents[x] = r;\n        }\n    }\n\n    T weight(int x) {\n\
    \        leader(x);\n        return diff_weight[x];\n    }\n\n    // weight(y)\
    \ = weight(x) + w\n    bool merge(int x, int y, T w) {\n        w += weight(x);\n\
    \        w -= weight(y);\n        x = leader(x), y = leader(y);\n        if (x\
    \ == y) return false;\n        if (parents[x] > parents[y]) std::swap(x, y), w\
    \ = -w;\n        parents[x] += parents[y];\n        parents[y] = x;\n        diff_weight[y]\
    \ = w;\n        return true;\n    }\n\n    // return weight(y) - weight(x)\n \
    \   T diff(int x, int y) { return weight(y) - weight(x); }\n\n    bool same(int\
    \ x, int y) { return leader(x) == leader(y); }\n\n    int size(int x) { return\
    \ -parents[leader(x)]; }\n\n    void init(int n) { parents.assign(n, -1), diff_weight.assign(n,\
    \ 0); }  // reset\n};\n\n/**\n * @brief Weighted UnionFind (\u91CD\u307F\u3064\
    \u304D UnionFind)\n * @docs docs/data_structure/weighted_unionfind.md\n */"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/weighted_unionfind.hpp
  requiredBy: []
  timestamp: '2022-12-04 00:46:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_dsl/aoj_dsl_1_b.test.cpp
documentation_of: src/data_structure/weighted_unionfind.hpp
layout: document
redirect_from:
- /library/src/data_structure/weighted_unionfind.hpp
- /library/src/data_structure/weighted_unionfind.hpp.html
title: "Weighted UnionFind (\u91CD\u307F\u3064\u304D UnionFind)"
---
- ポテンシャルつき UnionFind とも言う
- アーベル群が乗る
    - マグマ(閉じている)
    - 半群(閉じている、結合法則)
    - モノイド(閉じている、結合法則、単位元)
    - 群(閉じている、結合法則、単位元、逆元)
    - アーベル群(閉じている、結合法則、単位元、逆元、交換法則)
- `merge()` の説明
    - `diff_weight` は各頂点の `leader` からの重みの総和となっている(なので `weight()` は `diff_weight[x]` を返すだけで良い)
    - もともと `w` は `weight(y) - weight(x)` となっており、`w += weight(x)` によって `w` は `weight(y) - weight(leader(x))` となり、`w -= weight(y)` によって `w` は `weight(leader(y)) - weight(leader(x))` となり、最後に、`leader(x)` と `leader(y)` を Union by Size している
    - `leader(x)` の重みを 0 として、相対的に表現しているため、`diff_weight[y] = w` でOK

