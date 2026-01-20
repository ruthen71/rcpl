---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/kruskal.hpp
    title: "Kruskal's algorithm (\u30AF\u30E9\u30B9\u30AB\u30EB\u6CD5)"
  - icon: ':heavy_check_mark:'
    path: graph/minimum_steiner_tree.hpp
    title: "Minimum Steiner Tree (\u6700\u5C0F\u30B7\u30E5\u30BF\u30A4\u30CA\u30FC\
      \u6728)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: unionfind/test/unionfind.test.cpp
    title: unionfind/test/unionfind.test.cpp
  - icon: ':heavy_check_mark:'
    path: unionfind/test/unionfind_groups.test.cpp
    title: unionfind/test/unionfind_groups.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/kruskal.test.cpp
    title: verify/graph/kruskal.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/minimum_steiner_tree.test.cpp
    title: verify/graph/minimum_steiner_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"unionfind/unionfind.hpp\"\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <vector>\n\n// Unionfind\nstruct Unionfind {\n    int n;\n\
    \    std::vector<int> parent;\n\n    Unionfind() = default;\n\n    explicit Unionfind(int\
    \ n) : n(n), parent(n, -1) {}\n\n    int leader(int x) {\n        assert(0 <=\
    \ x and x < n);\n        if (parent[x] < 0) {\n            return x;\n       \
    \ } else {\n            return parent[x] = leader(parent[x]);\n        }\n   \
    \ }\n\n    int merge(int x, int y) {\n        assert(0 <= x and x < n);\n    \
    \    assert(0 <= y and y < n);\n        x = leader(x);\n        y = leader(y);\n\
    \        if (x == y) {\n            return x;\n        }\n        if (-parent[x]\
    \ < -parent[y]) {\n            std::swap(x, y);\n        }\n        parent[x]\
    \ += parent[y];\n        parent[y] = x;\n        return x;\n    }\n\n    bool\
    \ same(int x, int y) {\n        assert(0 <= x and x < n);\n        assert(0 <=\
    \ y and y < n);\n        return leader(x) == leader(y);\n    }\n\n    int size(int\
    \ x) {\n        assert(0 <= x and x < n);\n        return -parent[leader(x)];\n\
    \    }\n\n    std::vector<std::vector<int>> groups() {\n        std::vector<int>\
    \ leader_buf(n), group_size(n);\n        for (int i = 0; i < n; i++) {\n     \
    \       leader_buf[i] = leader(i);\n            group_size[leader_buf[i]]++;\n\
    \        }\n        std::vector<std::vector<int>> result(n);\n        for (int\
    \ i = 0; i < n; i++) {\n            result[i].reserve(group_size[i]);\n      \
    \  }\n        for (int i = 0; i < n; i++) {\n            result[leader_buf[i]].push_back(i);\n\
    \        }\n        result.erase(std::remove_if(\n                         result.begin(),\
    \ result.end(),\n                         [&](const std::vector<int>& v) { return\
    \ v.empty(); }),\n                     result.end());\n        return result;\n\
    \    }\n};\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\
    \n// Unionfind\nstruct Unionfind {\n    int n;\n    std::vector<int> parent;\n\
    \n    Unionfind() = default;\n\n    explicit Unionfind(int n) : n(n), parent(n,\
    \ -1) {}\n\n    int leader(int x) {\n        assert(0 <= x and x < n);\n     \
    \   if (parent[x] < 0) {\n            return x;\n        } else {\n          \
    \  return parent[x] = leader(parent[x]);\n        }\n    }\n\n    int merge(int\
    \ x, int y) {\n        assert(0 <= x and x < n);\n        assert(0 <= y and y\
    \ < n);\n        x = leader(x);\n        y = leader(y);\n        if (x == y) {\n\
    \            return x;\n        }\n        if (-parent[x] < -parent[y]) {\n  \
    \          std::swap(x, y);\n        }\n        parent[x] += parent[y];\n    \
    \    parent[y] = x;\n        return x;\n    }\n\n    bool same(int x, int y) {\n\
    \        assert(0 <= x and x < n);\n        assert(0 <= y and y < n);\n      \
    \  return leader(x) == leader(y);\n    }\n\n    int size(int x) {\n        assert(0\
    \ <= x and x < n);\n        return -parent[leader(x)];\n    }\n\n    std::vector<std::vector<int>>\
    \ groups() {\n        std::vector<int> leader_buf(n), group_size(n);\n       \
    \ for (int i = 0; i < n; i++) {\n            leader_buf[i] = leader(i);\n    \
    \        group_size[leader_buf[i]]++;\n        }\n        std::vector<std::vector<int>>\
    \ result(n);\n        for (int i = 0; i < n; i++) {\n            result[i].reserve(group_size[i]);\n\
    \        }\n        for (int i = 0; i < n; i++) {\n            result[leader_buf[i]].push_back(i);\n\
    \        }\n        result.erase(std::remove_if(\n                         result.begin(),\
    \ result.end(),\n                         [&](const std::vector<int>& v) { return\
    \ v.empty(); }),\n                     result.end());\n        return result;\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: unionfind/unionfind.hpp
  requiredBy:
  - graph/kruskal.hpp
  - graph/minimum_steiner_tree.hpp
  timestamp: '2025-12-10 04:21:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - unionfind/test/unionfind.test.cpp
  - unionfind/test/unionfind_groups.test.cpp
  - verify/graph/kruskal.test.cpp
  - verify/graph/minimum_steiner_tree.test.cpp
documentation_of: unionfind/unionfind.hpp
layout: document
title: Unionfind
---

無向グラフに対して

- 辺の追加
- $2$ 頂点が連結かの判定

をならし $O(\alpha(n))$ 時間で処理することが出来ます。

## コンストラクタ

```cpp
Unionfind uf(int n)
```

$n$ 頂点 $0$ 辺の無向グラフを作ります。

### 計算量

- $O(n)$

## merge

```cpp
int uf.merge(int x, int y)
```

辺 $(x, y)$ を足します。

$x, y$ が連結だった場合はその代表元を、$x, y$ が非連結だった場合は新たな代表元を返します。
すなわち、辺の追加により連結成分がマージされる時、新たな代表元は元の連結成分の代表元のうちどちらかになります。

### 制約

- $0 \leq x < n$
- $0 \leq y < n$

### 計算量

- ならし $O(\alpha(n))$

## same

```cpp
bool uf.same(int x, int y)
```

頂点 $x, y$ が連結かどうかを返します。

### 制約

- $0 \leq x < n$
- $0 \leq y < n$

### 計算量

- ならし $O(\alpha(n))$

## leader

```cpp
int uf.leader(int x)
```

頂点 $x$ の属する連結成分の代表元を返します。

### 制約

- $0 \leq x < n$

### 計算量

- ならし $O(\alpha(n))$

## size

```cpp
int uf.size(int x)
```

頂点 $x$ の属する連結成分のサイズを返します。

### 制約

- $0 \leq x < n$

### 計算量

- ならし $O(\alpha(n))$

## groups

```cpp
std::vector<std::vector<int>> uf.groups()
```

グラフを連結成分に分け、その情報を返します。

返り値は「「一つの連結成分の頂点番号のリスト」のリスト」です。
（内側外側限らず）`std::vector` 内でどの順番で格納されているかは未定義です。

### 計算量

- $O(n)$
