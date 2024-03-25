---
title: ローリングハッシュ
documentation_of: //algebra/monoid_s/monoid_rolling_hash.hpp
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