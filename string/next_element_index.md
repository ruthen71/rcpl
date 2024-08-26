---
title: Next Element Index (次の各要素の登場位置)
documentation_of: ./next_element_index.hpp
---

## 使い方

```cpp
std::string s;
auto res = next_element_index(s);
```

`res[i][c]` は $i = 0, 1, ... , n$ について, $ s[i, n) $ において次の `c` の登場位置を返す

`c` は与えられた配列の要素の最小値を基準としたときの差分である (`a - z` なら `a` が $0$, `b` が $1$, ... , `z` が $26$ となる)

## 参考文献
