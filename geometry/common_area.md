---
title: Common Area (共通部分の面積)
documentation_of: ./common_area.hpp
---

## 使い方

共通部分の面積を求める

- 円と (凸とは限らない) 多角形
- 円と円

```cpp
Circle<T> C1, C2;
Polygon<T> P;
T scp = common_area(C1, P);
T scc = common_area(C1, C2);
```

## 参考文献

- [けんちょんの競プロ精進記録, 円と多角形の共通部分の面積 (AOJ Course CGL_7_H)](https://drken1215.hatenablog.com/entry/2020/02/02/091000)
