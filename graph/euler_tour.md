---
title: Euler Tour (オイラーツアー)
documentation_of: ./euler_tour.hpp
---

## 使い方

```cpp
Graph<int> g;
EulerTour et(g);
// et.vertices, et.edges, et.dir, et.vsl, et.vsr, et.esl, et.esr が利用可能
```

$N = 5$ 頂点の木で辺が $E = \{ \{0, 1\}, \{0, 2\}, \{2, 3\}, \{2, 4\} \}$ である場合は以下のようになる


```txt
   0
  / \
 1   2
    / \
   3   4
vertices = [0, 1, 0, 2, 3, 2, 4, 2, 0]
edges    =  [0, 0, 1, 2, 2, 3, 3, 1]
dir      =  [0, 1, 0, 0, 1, 0, 1, 1]
vsl      = [0, 1, 3, 4, 6]
vsr      = [8, 1, 7, 4, 6]
esl      = [0, 2, 3, 5]
esr      = [1, 7, 4, 6]
```

## 参考文献
