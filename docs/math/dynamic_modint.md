---
title: Dynamic Modint
documentation_of: //math/dynamic_modint.hpp
---

コンパイル時に $ \bmod $ が確定しないときに使える

- すでに `using mintd = DynamicModint<0>;` が宣言されており、`mintd::set_mod(m)` などでセット可能
- 複数の $ \bmod $ に対して利用したい場合は `using mintd1 = DynamicModint<-1>` などとして増やす
