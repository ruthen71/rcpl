---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: misc/test/top_two.test.cpp
    title: misc/test/top_two.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"misc/top_two.hpp\"\n\ntemplate <class T, T inf> struct TopTwo\
    \ {\n    T a, b;\n    TopTwo() {\n        a = -inf;\n        b = -inf;\n    }\n\
    \    TopTwo(T a, T b) : a(a), b(b) {\n        if (a < b) {\n            std::swap(this->a,\
    \ this->b);\n        }\n    }\n    bool add(T x) {\n        if (a < x) {\n   \
    \         b = a;\n            a = x;\n            return true;\n        } else\
    \ if (b < x) {\n            b = x;\n            return true;\n        }\n    \
    \    return false;\n    }\n};\n"
  code: "#pragma once\n\ntemplate <class T, T inf> struct TopTwo {\n    T a, b;\n\
    \    TopTwo() {\n        a = -inf;\n        b = -inf;\n    }\n    TopTwo(T a,\
    \ T b) : a(a), b(b) {\n        if (a < b) {\n            std::swap(this->a, this->b);\n\
    \        }\n    }\n    bool add(T x) {\n        if (a < x) {\n            b =\
    \ a;\n            a = x;\n            return true;\n        } else if (b < x)\
    \ {\n            b = x;\n            return true;\n        }\n        return false;\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/top_two.hpp
  requiredBy: []
  timestamp: '2026-02-15 05:06:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - misc/test/top_two.test.cpp
documentation_of: misc/top_two.hpp
layout: document
title: TopTwo
---

大きい 2 つの要素を管理する構造体です。

## コンストラクタ

```cpp
(1) TopTwo<T, inf> t()
(2) TopTwo<T, inf> t(T a, T b)
```

大きい 2 つの要素を `a`, `b` として作成します。

`a` と `b` は順不同です。

`a` と `b` を指定しなかった場合、それぞれ `-inf` で初期化されます。

## add

```cpp
bool t.add(T x)
```

`x` を追加します。

$(a, b)$ が更新された場合には `true` を、更新されなかった場合は `false` を返します。
