---
title: グラフテンプレート
documentation_of: ./graph_template.hpp
---

隣接リストを CSR (Compressed Row Storage) 形式で管理しているため定数倍が良い

## 使い方

`add_edge()` は辺が何番目に追加されたかを返す

```cpp
Graph<T> g(n, false); // 無向グラフ
Graph<T> g(n, true);  // 有向グラフ
for (int i = 0; i < m; i++) {
    int a, b;
    T c;
    std::cin >> a >> b >> c;
    int edge_id = g.add_edge(a, b, c);
}
g.build();
```

はじめて `g[v]` などを実行した際に自動的に `build()` を実行する

注意点
- `g[v]` などとした後に辺を追加することはできない (`build()` が走ってしまうため)
- 関数の引数に与えるときに `function(const Graph<T>& g)` とはできず, `function(Graph<T>& g)` とする必要がある
    - `g[v]` の中で `build()` が走る可能性があるため `const` にできない


## 参考文献
- [【競プロ/C++】2次元ベクタを潰してグラフライブラリを軒並み高速化](https://qiita.com/Nachia/items/d420c08b333296f54526)
