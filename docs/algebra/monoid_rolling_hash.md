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
