---
title: Strongly Connected Component (強連結成分)
documentation_of: ./strongly_connected_component.hpp
---

## 使い方

```cpp
Graph<int> g;
auto scc = strongly_connected_component(g);
```

強連結成分ごとに頂点のリストを作り, トポロジカルソートしたリストを返す

## 参考文献
