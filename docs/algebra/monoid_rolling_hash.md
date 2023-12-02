---
title: ローリングハッシュ
documentation_of: //algebra/monoid_rolling_hash.hpp
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

`mrh::set_base(b)` とすると基数に `b` にセットできる

モノイドを作成するには `mrh::make_element(x)` とする

```cpp
std::vector<pair<mint, mint>> seginit;
seginit.push_back(mrh::make_element(x));
SegmentTree<mrh> seg(seginit);
```
## 使用例

- [ABC298 D](https://atcoder.jp/contests/abc298/submissions/40706415)
    - `set_base()` に乱数以外を用いる例
- [ABC331 F](https://atcoder.jp/contests/abc331/submissions/48126645)
    - 1点更新区間回分判定クエリ→反転した文字列も持つ
- [ABC285 F](https://atcoder.jp/contests/abc285/tasks/abc285_f)
    - 非想定解
    - ソートされた文字列のハッシュは個数から計算
    - 部分列のハッシュはセグメント木で計算
