---
title: グラフ入力ライブラリ
documentation_of: ./read_graph.hpp
---

## 使い方

```cpp
auto g = read_graph<T>(n, m, true, true, 1);     // 重みあり, 有向グラフ
auto g = read_graph<T>(n, m, true, false, 1);    // 重みあり, 無向グラフ
auto g = read_graph<T>(n, m, false, true, 1);    // 重みなし, 有向グラフ
auto g = read_graph<T>(n, m, false, false, 1);   // 重みなし, 無向グラフ
```

## 参考文献
