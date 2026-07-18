---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':warning:'
    path: my_template_int128.hpp
    title: my_template_int128.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"misc/io.hpp\"\n\n#include <iostream>\n\n// I/O\n// input\n\
    template <class... T> void in(T&... a) { (std::cin >> ... >> a); }\nvoid scan()\
    \ {}\ntemplate <class Head, class... Tail> void scan(Head& head, Tail&... tail)\
    \ {\n    in(head);\n    scan(tail...);\n}\n// output\ntemplate <class... T> void\
    \ out(const T&... a) { (std::cout << ... << a); }\nvoid print() { out('\\n');\
    \ }\ntemplate <class Head, class... Tail> void print(Head&& head, Tail&&... tail)\
    \ {\n    out(head);\n    if (sizeof...(Tail)) out(' ');\n    print(tail...);\n\
    }\n// output for interactive problems\nvoid printi() { std::cout << std::endl;\
    \ }\ntemplate <class Head, class... Tail> void printi(Head&& head, Tail&&... tail)\
    \ {\n    out(head);\n    if (sizeof...(Tail)) out(' ');\n    printi(tail...);\n\
    }\n"
  code: "#pragma once\n\n#include <iostream>\n\n// I/O\n// input\ntemplate <class...\
    \ T> void in(T&... a) { (std::cin >> ... >> a); }\nvoid scan() {}\ntemplate <class\
    \ Head, class... Tail> void scan(Head& head, Tail&... tail) {\n    in(head);\n\
    \    scan(tail...);\n}\n// output\ntemplate <class... T> void out(const T&...\
    \ a) { (std::cout << ... << a); }\nvoid print() { out('\\n'); }\ntemplate <class\
    \ Head, class... Tail> void print(Head&& head, Tail&&... tail) {\n    out(head);\n\
    \    if (sizeof...(Tail)) out(' ');\n    print(tail...);\n}\n// output for interactive\
    \ problems\nvoid printi() { std::cout << std::endl; }\ntemplate <class Head, class...\
    \ Tail> void printi(Head&& head, Tail&&... tail) {\n    out(head);\n    if (sizeof...(Tail))\
    \ out(' ');\n    printi(tail...);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/io.hpp
  requiredBy:
  - my_template.hpp
  - my_template_int128.hpp
  timestamp: '2026-05-10 18:24:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/io.hpp
layout: document
title: I/O
---

入出力用の関数です。

## scan

```cpp
void scan(T a, U b, ...)
```

変数 `a`, `b`, ... に対して入力を読み取り、値を格納します。

### 制約

- 型 `T`, `U`, ... に対して `std::cin` で入力できるようになっている（`std::istream` が定義されている）

## print

```cpp
void print(T a, U b, ...)
```

変数 `a`, `b`, ... の値をスペース区切りで出力し、最後に改行します。

### 制約

- 型 `T`, `U`, ... に対して `std::cout` で出力できるようになっている（`std::ostream` が定義されている）

## printi

```cpp
void printi(T a, U b, ...)
```

変数 `a`, `b`, ... の値をスペース区切りで出力し、最後に改行し、フラッシュします（`std::endl` に相当します）。

主にインタラクティブ問題のために利用します。

### 制約

- 型 `T`, `U`, ... に対して `std::cout` で出力できるようになっている（`std::ostream` が定義されている）

## 参考文献

- [【C++】可変引数関数と可変引数マクロで便利なテンプレートを作ろう【新歓ブログリレー4日目】](https://trap.jp/post/1224/)
