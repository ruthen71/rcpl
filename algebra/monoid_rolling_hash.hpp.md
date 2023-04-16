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
  bundledCode: "#line 2 \"algebra/monoid_rolling_hash.hpp\"\n\ntemplate <class Mint>\
    \ struct MonoidRollingHash {\n    using S = std::pair<Mint, Mint>;  // {hash(s),\
    \ base ^ len(s)}\n    using value_type = S;\n\n    static Mint base;\n\n    static\
    \ void constexpr set_base(Mint b = Mint(0)) {\n        if (b == Mint(0)) {\n \
    \           std::mt19937_64 mt(std::chrono::steady_clock::now().time_since_epoch().count());\n\
    \            std::uniform_int_distribution<uint64_t> rand(1, Mint::mod() - 1);\n\
    \            base = Mint(rand(mt));\n        } else {\n            base = b;\n\
    \        }\n    }\n\n    static constexpr S make_element(Mint x) { return make_pair(x,\
    \ base); }\n\n    static constexpr S op(S a, S b) { return {a.first * b.second\
    \ + b.first, a.second * b.second}; }\n    static constexpr S e() { return {0,\
    \ 1}; }  // {hash(\"\"), base ^ len(\"\")}\n};\n"
  code: "#pragma once\n\ntemplate <class Mint> struct MonoidRollingHash {\n    using\
    \ S = std::pair<Mint, Mint>;  // {hash(s), base ^ len(s)}\n    using value_type\
    \ = S;\n\n    static Mint base;\n\n    static void constexpr set_base(Mint b =\
    \ Mint(0)) {\n        if (b == Mint(0)) {\n            std::mt19937_64 mt(std::chrono::steady_clock::now().time_since_epoch().count());\n\
    \            std::uniform_int_distribution<uint64_t> rand(1, Mint::mod() - 1);\n\
    \            base = Mint(rand(mt));\n        } else {\n            base = b;\n\
    \        }\n    }\n\n    static constexpr S make_element(Mint x) { return make_pair(x,\
    \ base); }\n\n    static constexpr S op(S a, S b) { return {a.first * b.second\
    \ + b.first, a.second * b.second}; }\n    static constexpr S e() { return {0,\
    \ 1}; }  // {hash(\"\"), base ^ len(\"\")}\n};"
  dependsOn: []
  isVerificationFile: false
  path: algebra/monoid_rolling_hash.hpp
  requiredBy: []
  timestamp: '2023-04-16 23:03:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algebra/monoid_rolling_hash.hpp
layout: document
title: "\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5"
---

## 使用方法

```cpp
// 既に mint が定義されている必要がある
#include "algebra/monoid_rolling_hash.hpp"
using mrh = MonoidRollingHash<mint>;
template <> mint mrh::base = 0;

int main() {
    mrh::set_base();
    // code here
}
```

`mrh::set_base(x)` とすると基数に `x` にセットできる

モノイドを作成するには `mrh::make_element(x)` とする

```cpp
vector<pair<mint, mint>> seginit;
seginit.push_back(mrh::make_element(x));
SegmentTree<mrh> seg(seginit);
```

## 使用例

- [ABC285 F](https://atcoder.jp/contests/abc285/tasks/abc285_f)
- 2つ以上のmodを組み合わせるなら、include ではなくべた書きするしかない
    - が、基数が $ 2^{61} - 1 $ なので余程のことがなければ衝突しないと思われる
- [ABC298 D](https://atcoder.jp/contests/abc298/submissions/40706415)
