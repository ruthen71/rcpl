---
title: Intersection (交差判定)
documentation_of: ./is_intersect.hpp
---

## 使い方

直線, 線分, 円, 点のすべての組合せに対して利用可能

```cpp
Object<T> obj1, obj2;     // Line, Segment, Circle, Point
if (is_intersect(obj1, obj2)) {
    ...
}
```

## 参考文献
