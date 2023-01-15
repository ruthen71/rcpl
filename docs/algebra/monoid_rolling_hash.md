## 使用例

- [ABC285 F](https://atcoder.jp/contests/abc285/tasks/abc285_f)
- 以下の順で定義しなければならない(上手くやる方法がわからなかった)
    - `#include "src/string/rolling_hash.hpp"`
    - `rolling_hash<mint> rh;`
    - `#include "src/algebra/monoid_rolling_hash.hpp"`
- 2つ以上のmodを組み合わせるなら、include ではなくべた書きするしかない
- 正直あまり綺麗な書き方ではないので一刻も早く何とかしたい

