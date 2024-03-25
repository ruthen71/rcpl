---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/monoid_s/monoid_rolling_hash.hpp\"\n// MS\ntemplate\
    \ <class Mint> struct MonoidRollingHash {\n    using S = std::pair<Mint, Mint>;\
    \  // {hash(s), base ^ len(s)}\n\n    static Mint base;\n\n    static void constexpr\
    \ set_base(Mint b = Mint(0)) {\n        if (b == Mint(0)) {\n            std::mt19937_64\
    \ mt(std::chrono::steady_clock::now().time_since_epoch().count());\n         \
    \   std::uniform_int_distribution<uint64_t> rand(1, Mint::mod() - 1);\n      \
    \      base = Mint(rand(mt));\n        } else {\n            base = b;\n     \
    \   }\n    }\n\n    static constexpr S make_element(Mint x) { return {x, base};\
    \ }\n\n    static constexpr S op(S a, S b) { return {a.first * b.second + b.first,\
    \ a.second * b.second}; }\n    static constexpr S e() { return {Mint(0), Mint(1)};\
    \ }  // {hash(\"\"), base ^ len(\"\")}\n};\n"
  code: "#pragma once\n// MS\ntemplate <class Mint> struct MonoidRollingHash {\n \
    \   using S = std::pair<Mint, Mint>;  // {hash(s), base ^ len(s)}\n\n    static\
    \ Mint base;\n\n    static void constexpr set_base(Mint b = Mint(0)) {\n     \
    \   if (b == Mint(0)) {\n            std::mt19937_64 mt(std::chrono::steady_clock::now().time_since_epoch().count());\n\
    \            std::uniform_int_distribution<uint64_t> rand(1, Mint::mod() - 1);\n\
    \            base = Mint(rand(mt));\n        } else {\n            base = b;\n\
    \        }\n    }\n\n    static constexpr S make_element(Mint x) { return {x,\
    \ base}; }\n\n    static constexpr S op(S a, S b) { return {a.first * b.second\
    \ + b.first, a.second * b.second}; }\n    static constexpr S e() { return {Mint(0),\
    \ Mint(1)}; }  // {hash(\"\"), base ^ len(\"\")}\n};"
  dependsOn: []
  isVerificationFile: false
  path: algebra/monoid_s/monoid_rolling_hash.hpp
  requiredBy: []
  timestamp: '2024-03-24 17:04:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algebra/monoid_s/monoid_rolling_hash.hpp
layout: document
title: "\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5"
---

clang でコンパイルするときには `-std=c++2b` をつける

```cpp
// mint は定義済
#include "algebra/monoid_s/monoid_rolling_hash.hpp"
using mrh = MonoidRollingHash<mint>;
template <> mint mrh::base = 0;

int main() {
    mrh::set_base();
    // code here
}
```

`mrh::set_base(b)` とすると基数に `b` にセットできる

配列を初期化するには `mrh::make_element(x)` とする

```cpp
std::vector<std::pair<mint, mint>> seginit;
seginit.push_back(mrh::make_element(x));
SegmentTree<mrh> seg(seginit);
```
## 使用例

- [ABC298 D](https://atcoder.jp/contests/abc298/submissions/51644766)
    - `set_base()` に乱数以外を用いる例
- [ABC331 F](https://atcoder.jp/contests/abc331/submissions/51644646)
    - 1点更新区間回分判定クエリ->反転した文字列も持つ