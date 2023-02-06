# rcpl

[![Actions Status](https://github.com/ruthen71/rcpl/workflows/verify/badge.svg)](https://github.com/ruthen71/rcpl/actions)

[![GitHub Pages](https://img.shields.io/static/v1?label=GitHub+Pages&message=+&color=brightgreen&logo=github)](https://ruthen71.github.io/rcpl/)

## ドキュメントの書き方
- 使用例
- 参考文献

## 命名規則
なるべく下表に合わせる努力をする

| 対象 | 例 | 説明 |
| ---- | ---- | ---- |
| ファイル名 | `my_lib.hpp` | スネークケース |
| 関数名 | `my_func` | スネークケース |
| 型名 (typedef, using, enum) | `MyInt` | パスカルケース |
| 構造体名 | `MyStruct` | パスカルケース |
| クラス名 | `MyClass` | パスカルケース |
| 変数名 (全般) | `my_var` | スネークケース |
| 変数名 (constexpr) | `MY_VAR` | アッパースネークケース |
| メンバ変数名 (構造体) | `my_var` | スネークケース |
| メンバ変数名 (クラス) | `my_var_` | スネークケース + 末尾アンダースコア |
| 名前空間名 | `my_namespace` | スネークケース |
| 列挙型メンバ名 | `MY_ENUM_VAR` | アッパースネークケース |
| マクロ名 | `MY_MACRO` | アッパースネークケース |

- 命名はなるべく省略を避ける
- スネークケースで大文字は使わない
- パスカルケースにおいて、BFS (Breadth First Search) などはすべて大文字でも良い
    - 省略しないパスカルケースの頭文字を取っていったと考える
    - 2D (2 Dimensional) などもそう
- 一応書いたが、クラスはそもそも使う場面が思いつかない
