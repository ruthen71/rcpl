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
    links: []
  bundledCode: "#line 2 \"data_structure/weighted_unionfind.hpp\"\n\ntemplate <class\
    \ T> struct weighted_unionfind {\n    std::vector<int> parents;\n    std::vector<T>\
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
    \ }  // reset\n};\n"
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
    \ 0); }  // reset\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/weighted_unionfind.hpp
  requiredBy: []
  timestamp: '2023-02-06 19:13:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_dsl/aoj_dsl_1_b.test.cpp
documentation_of: data_structure/weighted_unionfind.hpp
layout: document
title: "Weighted UnionFind (\u91CD\u307F\u3064\u304D UnionFind)"
---

- ポテンシャルつき UnionFind とも言う
- アーベル群が乗る
    - マグマ(閉じている)
    - 半群(閉じている、結合法則)
    - モノイド(閉じている、結合法則、単位元)
    - 群(閉じている、結合法則、単位元、逆元)
    - アーベル群(閉じている、結合法則、単位元、逆元、交換法則)
- データの持ち方
    - 各頂点に対し、「親の頂点番号」「親への辺の重み」「根なら部分木のサイズ」の 3 つの情報が持てれば良い
    - 「親の頂点番号」「根なら部分木のサイズ」はどの頂点もどちらかあれば OK なので `parents` でまとめている
    - 「親への辺の重み」は `diff_weight` が持つ（頂点が根ならアーベル群の単位元を入れる）
- `merge()` の説明
    - 各頂点 `x` に対し、`weight(x)` は `leader(x)` からの差分となっている
    - もともと `w` は `weight(y) - weight(x)` となっており、`w += weight(x)` によって `w` は `weight(y) - weight(leader(x))` となり、`w -= weight(y)` によって `w` は `weight(leader(y)) - weight(leader(x))` となり、最後に、`leader(x)` と `leader(y)` を Union by Size している
    - `leader(x)` の重みを 0 として、相対的に表現しているため、`diff_weight[y] = w` でOK

