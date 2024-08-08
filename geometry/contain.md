---
title: Contain (多角形や円と点の位置関係)
documentation_of: ./contain.hpp
---

## 使い方

```cpp
Polygon<T> P;
Point<T> p;
// ans は Contain::IN, Contain::ON, Contain::OUT のいずれか
auto ans = contain(P, p);
```

## 参考文献
