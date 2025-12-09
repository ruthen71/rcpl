---
title: Unionfind
documentation_of: ./unionfind.hpp
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
