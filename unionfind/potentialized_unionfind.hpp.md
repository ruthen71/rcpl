---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: unionfind/test/potentialized_unionfind.test.cpp
    title: unionfind/test/potentialized_unionfind.test.cpp
  - icon: ':heavy_check_mark:'
    path: unionfind/test/potentialized_unionfind_groups.test.cpp
    title: unionfind/test/potentialized_unionfind_groups.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"unionfind/potentialized_unionfind.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <vector>\n\n// Potentialized Unionfind\ntemplate\
    \ <class G> struct PotentializedUnionfind {\n    static_assert(G::commutative\
    \ == true);\n\n    using T = typename G::value_type;\n\n    int n;\n    std::vector<int>\
    \ parent;\n    std::vector<T> value;\n\n    PotentializedUnionfind() = default;\n\
    \n    explicit PotentializedUnionfind(int n)\n        : n(n), parent(n, -1), value(n,\
    \ G::identity()) {}\n\n    int leader(int x) {\n        assert(0 <= x and x <\
    \ n);\n        if (parent[x] < 0) {\n            return x;\n        } else {\n\
    \            int r = leader(parent[x]);\n            value[x] = G::operation(value[x],\
    \ value[parent[x]]);\n            return parent[x] = r;\n        }\n    }\n\n\
    \    T potential(int x) {\n        assert(0 <= x and x < n);\n        leader(x);\n\
    \        return value[x];\n    }\n\n    int merge(int x, int y, T d) {\n     \
    \   assert(0 <= x and x < n);\n        assert(0 <= y and y < n);\n        // d\
    \ \u306F y \u306E x \u304B\u3089\u306E\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u306E\
    \u5DEE\u5206\n        // d \u3092 leader(y) \u306E leader(x) \u304B\u3089\u306E\
    \u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u306E\u5DEE\u5206\u306B\u4FEE\u6B63\n   \
    \     d = G::operation(G::operation(d, potential(x)),\n                      \
    \   G::inverse(potential(y)));\n        x = leader(x);\n        y = leader(y);\n\
    \        if (x == y) {\n            if (d == G::identity()) {\n              \
    \  return x;\n            } else {\n                return -1;\n            }\n\
    \        }\n        if (-parent[x] < -parent[y]) {\n            std::swap(x, y);\n\
    \            d = G::inverse(d);\n        }\n        parent[x] += parent[y];\n\
    \        parent[y] = x;\n        value[y] = d;\n        return x;\n    }\n\n \
    \   T distance(int x, int y) {\n        assert(0 <= x and x < n);\n        assert(0\
    \ <= y and y < n);\n        assert(same(x, y));\n        return G::operation(potential(y),\
    \ G::inverse(potential(x)));\n    }\n\n    bool same(int x, int y) {\n       \
    \ assert(0 <= x and x < n);\n        assert(0 <= y and y < n);\n        return\
    \ leader(x) == leader(y);\n    }\n\n    int size(int x) {\n        assert(0 <=\
    \ x and x < n);\n        return -parent[leader(x)];\n    }\n\n    std::vector<std::vector<std::pair<int,\
    \ T>>> groups() {\n        std::vector<int> leader_buf(n), group_size(n);\n  \
    \      for (int i = 0; i < n; i++) {\n            leader_buf[i] = leader(i);\n\
    \            group_size[leader_buf[i]]++;\n        }\n        std::vector<std::vector<std::pair<int,\
    \ T>>> result(n);\n        for (int i = 0; i < n; i++) {\n            result[i].reserve(group_size[i]);\n\
    \        }\n        for (int i = 0; i < n; i++) {\n            result[leader_buf[i]].emplace_back(i,\
    \ potential(i));\n        }\n        result.erase(\n            std::remove_if(result.begin(),\
    \ result.end(),\n                           [&](const std::vector<std::pair<int,\
    \ T>>& v) {\n                               return v.empty();\n              \
    \             }),\n            result.end());\n        return result;\n    }\n\
    };\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\
    \n// Potentialized Unionfind\ntemplate <class G> struct PotentializedUnionfind\
    \ {\n    static_assert(G::commutative == true);\n\n    using T = typename G::value_type;\n\
    \n    int n;\n    std::vector<int> parent;\n    std::vector<T> value;\n\n    PotentializedUnionfind()\
    \ = default;\n\n    explicit PotentializedUnionfind(int n)\n        : n(n), parent(n,\
    \ -1), value(n, G::identity()) {}\n\n    int leader(int x) {\n        assert(0\
    \ <= x and x < n);\n        if (parent[x] < 0) {\n            return x;\n    \
    \    } else {\n            int r = leader(parent[x]);\n            value[x] =\
    \ G::operation(value[x], value[parent[x]]);\n            return parent[x] = r;\n\
    \        }\n    }\n\n    T potential(int x) {\n        assert(0 <= x and x < n);\n\
    \        leader(x);\n        return value[x];\n    }\n\n    int merge(int x, int\
    \ y, T d) {\n        assert(0 <= x and x < n);\n        assert(0 <= y and y <\
    \ n);\n        // d \u306F y \u306E x \u304B\u3089\u306E\u30DD\u30C6\u30F3\u30B7\
    \u30E3\u30EB\u306E\u5DEE\u5206\n        // d \u3092 leader(y) \u306E leader(x)\
    \ \u304B\u3089\u306E\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u306E\u5DEE\u5206\u306B\
    \u4FEE\u6B63\n        d = G::operation(G::operation(d, potential(x)),\n      \
    \                   G::inverse(potential(y)));\n        x = leader(x);\n     \
    \   y = leader(y);\n        if (x == y) {\n            if (d == G::identity())\
    \ {\n                return x;\n            } else {\n                return -1;\n\
    \            }\n        }\n        if (-parent[x] < -parent[y]) {\n          \
    \  std::swap(x, y);\n            d = G::inverse(d);\n        }\n        parent[x]\
    \ += parent[y];\n        parent[y] = x;\n        value[y] = d;\n        return\
    \ x;\n    }\n\n    T distance(int x, int y) {\n        assert(0 <= x and x < n);\n\
    \        assert(0 <= y and y < n);\n        assert(same(x, y));\n        return\
    \ G::operation(potential(y), G::inverse(potential(x)));\n    }\n\n    bool same(int\
    \ x, int y) {\n        assert(0 <= x and x < n);\n        assert(0 <= y and y\
    \ < n);\n        return leader(x) == leader(y);\n    }\n\n    int size(int x)\
    \ {\n        assert(0 <= x and x < n);\n        return -parent[leader(x)];\n \
    \   }\n\n    std::vector<std::vector<std::pair<int, T>>> groups() {\n        std::vector<int>\
    \ leader_buf(n), group_size(n);\n        for (int i = 0; i < n; i++) {\n     \
    \       leader_buf[i] = leader(i);\n            group_size[leader_buf[i]]++;\n\
    \        }\n        std::vector<std::vector<std::pair<int, T>>> result(n);\n \
    \       for (int i = 0; i < n; i++) {\n            result[i].reserve(group_size[i]);\n\
    \        }\n        for (int i = 0; i < n; i++) {\n            result[leader_buf[i]].emplace_back(i,\
    \ potential(i));\n        }\n        result.erase(\n            std::remove_if(result.begin(),\
    \ result.end(),\n                           [&](const std::vector<std::pair<int,\
    \ T>>& v) {\n                               return v.empty();\n              \
    \             }),\n            result.end());\n        return result;\n    }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: unionfind/potentialized_unionfind.hpp
  requiredBy: []
  timestamp: '2025-12-10 04:21:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - unionfind/test/potentialized_unionfind_groups.test.cpp
  - unionfind/test/potentialized_unionfind.test.cpp
documentation_of: unionfind/potentialized_unionfind.hpp
layout: document
title: "Potentialized Unionfind\uFF08\u91CD\u307F\u4ED8\u304D Unionfind\uFF09"
---

通常の Unionfind に加えて、各頂点に対して「代表元からの重み（ポテンシャル）の差分」を管理するデータ構造です。

- 辺の追加（重み付き）
- $2$ 頂点が連結かの判定
- $2$ 頂点のポテンシャルの差分の取得

をならし $O(\alpha(n))$ 時間で処理することが出来ます。

テンプレート引数として、可換群（アーベル群） $(T, \cdot)$ を `G` として受け取ります。
可換群とは以下の条件を満たす代数構造です。

- 結合律（ $(a \cdot b) \cdot c = a \cdot (b \cdot c)$ ）が成立する。
- 単位元（ $a \cdot e=e \cdot a=a$ となる $e$ ）が存在する。
- 逆元（ $a \cdot a^{-1}=a^{-1} \cdot a=e$ となる $a^{-1}$ ）が存在する。
- 可換（ $a \cdot b=b \cdot a$ ）である。


例えば、$\cdot$ として和を計算する可換群は [ここ](../algebra/monoid/monoid_plus.hpp) に定義されています。

計算量は $\cdot$, $e$, $a^{-1}$ が定数時間で計算できると仮定したときのものを記述します。

## コンストラクタ

```cpp
PotentializedUnionfind<G> uf(int n)
```

$n$ 頂点 $0$ 辺の無向グラフを作ります。

### 計算量

- $O(n)$

## merge

```cpp
int uf.merge(int x, int y, T d)
```

$p_x, p_y$ をそれぞれ $x, y$ のポテンシャルとし、重み $d = p_y \cdot p_x^{-1}$ の辺 $(x, y)$ を足します。

$x, y$ が連結で、かつ重み $d$ で矛盾が生じない場合はその代表元を、$x, y$ が非連結だった場合は新たな代表元を返します。
すなわち、辺の追加により連結成分がマージされる時、新たな代表元は元の連結成分の代表元のうちどちらかになります。

$x, y$ が連結で、かつ重み $d$ で矛盾が生じる場合、$-1$ を返します。


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

## potential

```cpp
T uf.potential(int x)
```

頂点 $x$ の属する連結成分の代表元からのポテンシャルの差分を返します。

### 制約

- $0 \leq x < n$

### 計算量

- ならし $O(\alpha(n))$


## distance

```cpp
T uf.distance(int x, int y)
```

$p_x, p_y$ をそれぞれ $x, y$ のポテンシャルとし、$p_y \cdot p_x^{-1}$ を返します。


### 制約

- $0 \leq x < n$
- $0 \leq y < n$
- $x$ と $y$ が同じ連結成分に属する

### 計算量

- ならし $O(\alpha(n))$

## groups

```cpp
std::vector<std::vector<std::pair<int, T>>> uf.groups()
```

グラフを連結成分に分け、その情報を返します。

返り値は「「一つの連結成分の「頂点番号と代表元からのポテンシャルの差分」のリスト」のリスト」です。
（内側外側限らず）`std::vector` 内でどの順番で格納されているかは未定義です。

### 計算量

- $O(n)$
