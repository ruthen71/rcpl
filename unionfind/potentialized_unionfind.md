---
title: Potentialized Unionfind（重み付き Unionfind）
documentation_of: ./potentialized_unionfind.hpp
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
