---
title: Circumscribed Circle (外接円)
documentation_of: ./circumscribed_circle.hpp
---

## 使い方

```cpp
Point<T> a, b, c;
auto cir = circumscribed_circle(a, b, c);
```

## 参考文献

- [けんちょんの競プロ精進記録, AOJ Course CGL_7_C: 外接円 (Circumscribed Circle of a Triangle)](https://drken1215.hatenablog.com/entry/2020/10/16/074400)
- [AtCoder Beginner Contest 362 B - Right Triangle](https://atcoder.jp/contests/abc362/tasks/abc362_b)
    - 直角三角形である $\Leftrightarrow$ 外接円の直径の長さが最長の辺の長さと一致