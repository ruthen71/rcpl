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
    \ T> struct WeightedUnionFind {\n    int n;\n    std::vector<int> parents;\n \
    \   std::vector<T> diff_weight;\n\n    WeightedUnionFind() {}\n    WeightedUnionFind(int\
    \ n) : n(n), parents(n, -1), diff_weight(n, T(0)) {}\n\n    int leader(int x)\
    \ {\n        if (parents[x] < 0) {\n            return x;\n        } else {\n\
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
    \ -parents[leader(x)]; }\n\n    // \u9023\u7D50\u6210\u5206\u3054\u3068\u306B\
    \ (\u9802\u70B9\u756A\u53F7 v, diff(leader(v), v)) \u306E\u914D\u5217\u3092\u8FD4\
    \u3059\n    std::vector<std::vector<std::pair<int, T>>> groups() {\n        std::vector<int>\
    \ leader_buf(n), group_size(n);\n        for (int i = 0; i < n; i++) {\n     \
    \       leader_buf[i] = leader(i);\n            group_size[leader_buf[i]]++;\n\
    \        }\n        std::vector<std::vector<std::pair<int, T>>> result(n);\n \
    \       for (int i = 0; i < n; i++) {\n            result[i].reserve(group_size[i]);\n\
    \        }\n        for (int i = 0; i < n; i++) {\n            result[leader_buf[i]].emplace_back(i,\
    \ weight(i));\n        }\n        result.erase(std::remove_if(result.begin(),\
    \ result.end(), [&](const std::vector<std::pair<int, T>>& v) { return v.empty();\
    \ }), result.end());\n        return result;\n    }\n\n    void init(int n) {\
    \ parents.assign(n, -1), diff_weight.assign(n, T(0)); }  // reset\n};\n"
  code: "#pragma once\n\ntemplate <class T> struct WeightedUnionFind {\n    int n;\n\
    \    std::vector<int> parents;\n    std::vector<T> diff_weight;\n\n    WeightedUnionFind()\
    \ {}\n    WeightedUnionFind(int n) : n(n), parents(n, -1), diff_weight(n, T(0))\
    \ {}\n\n    int leader(int x) {\n        if (parents[x] < 0) {\n            return\
    \ x;\n        } else {\n            int r = leader(parents[x]);\n            diff_weight[x]\
    \ += diff_weight[parents[x]];\n            return parents[x] = r;\n        }\n\
    \    }\n\n    T weight(int x) {\n        leader(x);\n        return diff_weight[x];\n\
    \    }\n\n    // weight(y) = weight(x) + w\n    bool merge(int x, int y, T w)\
    \ {\n        w += weight(x);\n        w -= weight(y);\n        x = leader(x),\
    \ y = leader(y);\n        if (x == y) return false;\n        if (parents[x] >\
    \ parents[y]) std::swap(x, y), w = -w;\n        parents[x] += parents[y];\n  \
    \      parents[y] = x;\n        diff_weight[y] = w;\n        return true;\n  \
    \  }\n\n    // return weight(y) - weight(x)\n    T diff(int x, int y) { return\
    \ weight(y) - weight(x); }\n\n    bool same(int x, int y) { return leader(x) ==\
    \ leader(y); }\n\n    int size(int x) { return -parents[leader(x)]; }\n\n    //\
    \ \u9023\u7D50\u6210\u5206\u3054\u3068\u306B (\u9802\u70B9\u756A\u53F7 v, diff(leader(v),\
    \ v)) \u306E\u914D\u5217\u3092\u8FD4\u3059\n    std::vector<std::vector<std::pair<int,\
    \ T>>> groups() {\n        std::vector<int> leader_buf(n), group_size(n);\n  \
    \      for (int i = 0; i < n; i++) {\n            leader_buf[i] = leader(i);\n\
    \            group_size[leader_buf[i]]++;\n        }\n        std::vector<std::vector<std::pair<int,\
    \ T>>> result(n);\n        for (int i = 0; i < n; i++) {\n            result[i].reserve(group_size[i]);\n\
    \        }\n        for (int i = 0; i < n; i++) {\n            result[leader_buf[i]].emplace_back(i,\
    \ weight(i));\n        }\n        result.erase(std::remove_if(result.begin(),\
    \ result.end(), [&](const std::vector<std::pair<int, T>>& v) { return v.empty();\
    \ }), result.end());\n        return result;\n    }\n\n    void init(int n) {\
    \ parents.assign(n, -1), diff_weight.assign(n, T(0)); }  // reset\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/weighted_unionfind.hpp
  requiredBy: []
  timestamp: '2024-05-04 23:26:46+09:00'
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
- `merge()`
    - 各頂点 `x` に対し、`weight(x)` は `leader(x)` からの差分となっている
    - もともと `w` は `weight(y) - weight(x)` となっており、`w += weight(x)` によって `w` は `weight(y) - weight(leader(x))` となり、`w -= weight(y)` によって `w` は `weight(leader(y)) - weight(leader(x))` となり、最後に、`leader(x)` と `leader(y)` を Union by Size している
    - `leader(x)` の重みを 0 として、相対的に表現しているため、`diff_weight[y] = w` でOK
- `groups()`
    - UnionFind では各連結成分ごとに頂点番号のリストを返すが、Weighted UnionFind では頂点番号とその頂点番号の根からの重みの組のリストを返す