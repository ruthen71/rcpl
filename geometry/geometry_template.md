---
title: 幾何テンプレート
documentation_of: ./geometry_template.hpp
---

## 使い方

```cpp
// EPS 取得
Constants::<T>::EPS
// PI 取得
Constants::<T>::PI
// T の誤差を 1e-8 に変更
Constants<T>::set_eps(1e-8);
```

`double`, `long double`, `long long` 以外は動かない

関数によっては整数型でのみ, あるいは浮動小数点数型でのみ動作するものもあり, 想定していない使われ方に対しては `static_assert` で CE を吐くようにしている

## 参考文献
- [cpprefjp - C++日本語レファレンス, type_traits](https://cpprefjp.github.io/reference/type_traits.html)