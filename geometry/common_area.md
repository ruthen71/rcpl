---
title: Common Area (共通部分の面積)
documentation_of: ./common_area.hpp
---

## 使い方

円と多角形 (凸とは限らない) の共通部分の面積を求める

```cpp
Circle<T> C;
Polygon<T> P;
T s = common_area(C, P);
```

## 参考文献

- [けんちょんの競プロ精進記録, 円と多角形の共通部分の面積 (AOJ Course CGL_7_H)](https://drken1215.hatenablog.com/entry/2020/02/02/091000)
