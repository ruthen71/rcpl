---
title: Polygon Contain (多角形と点の交差判定)
documentation_of: ./polygon_contain.hpp
---

## 使い方

```cpp
Polygon<T> P;
Point<T> p;
// ans は Contain::IN, Contain::ON, Contain::OUT のいずれか
auto ans = polygon_contain(P, p);
```

## 参考文献

- [Wikipedia, Rotating calipers](https://en.wikipedia.org/wiki/Rotating_calipers)
