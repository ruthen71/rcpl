---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/segment_tree_rolling_hash.test.cpp
    title: segment_tree/test/segment_tree_rolling_hash.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/monoid/monoid_rolling_hash.hpp\"\n\n#include <chrono>\n\
    #include <cstdint>\n#include <random>\n#include <utility>\n\ntemplate <class Mint>\
    \ struct Hash {\n    // {hash(s), base ^ len(s)}\n    Mint hash;\n    Mint power;\n\
    \    friend std::ostream& operator<<(std::ostream& os, const Hash& v) {\n    \
    \    return os << v.hash << \", \" << v.power;\n    }\n};\n\ntemplate <class Mint>\
    \ struct MonoidRollingHash {\n    using value_type = Hash<Mint>;\n\n    static\
    \ Mint base;\n\n    static void set_base(Mint b = Mint(0)) {\n        if (b ==\
    \ Mint(0)) {\n            std::mt19937_64 mt(\n                std::chrono::steady_clock::now().time_since_epoch().count());\n\
    \            std::uniform_int_distribution<uint64_t> rand(1, Mint::mod() - 1);\n\
    \            base = Mint(rand(mt));\n        } else {\n            base = b;\n\
    \        }\n    }\n\n    static constexpr value_type make_element(Mint x) { return\
    \ {x, base}; }\n\n    static constexpr value_type operation(const value_type&\
    \ a,\n                                          const value_type& b) {\n     \
    \   return {a.hash * b.power + b.hash, a.power * b.power};\n    }\n    static\
    \ constexpr value_type identity() {\n        // {hash(\"\"), base ^ len(\"\")}\n\
    \        return {Mint(0), Mint(1)};\n    }\n\n    static constexpr bool commutative\
    \ = false;\n};\n"
  code: "#pragma once\n\n#include <chrono>\n#include <cstdint>\n#include <random>\n\
    #include <utility>\n\ntemplate <class Mint> struct Hash {\n    // {hash(s), base\
    \ ^ len(s)}\n    Mint hash;\n    Mint power;\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const Hash& v) {\n        return os << v.hash << \", \" << v.power;\n  \
    \  }\n};\n\ntemplate <class Mint> struct MonoidRollingHash {\n    using value_type\
    \ = Hash<Mint>;\n\n    static Mint base;\n\n    static void set_base(Mint b =\
    \ Mint(0)) {\n        if (b == Mint(0)) {\n            std::mt19937_64 mt(\n \
    \               std::chrono::steady_clock::now().time_since_epoch().count());\n\
    \            std::uniform_int_distribution<uint64_t> rand(1, Mint::mod() - 1);\n\
    \            base = Mint(rand(mt));\n        } else {\n            base = b;\n\
    \        }\n    }\n\n    static constexpr value_type make_element(Mint x) { return\
    \ {x, base}; }\n\n    static constexpr value_type operation(const value_type&\
    \ a,\n                                          const value_type& b) {\n     \
    \   return {a.hash * b.power + b.hash, a.power * b.power};\n    }\n    static\
    \ constexpr value_type identity() {\n        // {hash(\"\"), base ^ len(\"\")}\n\
    \        return {Mint(0), Mint(1)};\n    }\n\n    static constexpr bool commutative\
    \ = false;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: algebra/monoid/monoid_rolling_hash.hpp
  requiredBy: []
  timestamp: '2026-04-11 00:41:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - segment_tree/test/segment_tree_rolling_hash.test.cpp
documentation_of: algebra/monoid/monoid_rolling_hash.hpp
layout: document
title: monoid_rolling_hash
---

clang でコンパイルするときには `-std=c++2b` をつける

```cpp
// mint は定義済
#include "algebra/monoid/monoid_rolling_hash.hpp"
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
